from wxPython.wx import *
from time import localtime, strftime, strptime
from resource import Resource
from ListaStr import LISTAMSTR
import fpformat

def create():
  return RotinasGlobais()

class RotinasGlobais:
  gConexao = None
  sBarraLogin = ''
  sUsuarioLogin = ''
  sUsuarioSenha = ''
  sCodigoSelecionado = ''
  sPreco = ''
  sQtdEstoque = ''
  sepDTHR = '#' #SOMENTE ACCESS
  #sepDTHR = "'" #OUTROS BANCOS

  def __init__(self):
    self.data = []

  def ValidaFloat(self, sNum):
    nNum = 0.0
    bret = False

    if len(sNum) > 0:
      try:
        nNum = float(sNum)
        if nNum >= 0.01:
          bret = True
      except:
        wxMessageBox(Resource.STR_NUMINV, u'Erro', wxOK | wxICON_ERROR)
        bret = False
    else:
      bret = False
    
    return bret
  
  def VirgulaParaPonto(self, sNum, bRevertido):
    if bRevertido:
      sret = sNum.replace('.', ',')
    else:
      sret = sNum.replace(',', '.')
    
    return sret

  def substr(self, stexto, nini, ntam):
    return stexto[nini-1:nini+ntam-1]

  def modulo11(self, svalor, ndig):
    ncont = 1
    slocal = ''
    while (ncont <= 11):
      slocal=self.substr(svalor,ncont,1) + slocal
      ncont=ncont+1
    nsoma=0;
    if (ndig == 1):
      ncont=3;
    else:
      ncont=2;
    npos = 2
    while (ncont <= 11):
      sres = self.substr(slocal,ncont,1)
      nvalor = int(sres)
      nsoma=nsoma + (nvalor * npos)
      ncont=ncont+1
      npos=npos+1
  
    nsoma=(11 - (nsoma % 11))
    if (nsoma > 9):
      return 0
    else:
      return nsoma

  def validaCPF(self, cpf):
    if len(cpf)==14:
      try:
        scpf=self.substr(cpf,1,3)+self.substr(cpf,5,3)+self.substr(cpf,9,3)+\
          self.substr(cpf,13,2)
        sres=self.substr(cpf,13,1)
        nvalor1 = int(sres)
        sres=self.substr(cpf,14,1)
        nvalor2 = int(sres)
        if (self.modulo11(scpf,1)==nvalor1) and\
           (self.modulo11(scpf,2)==nvalor2):
          return True
        else:
          return False
      except:
        return False
    else:
      return False

  def validaISBN(self, isbn):
    if len(isbn)==13:
      sdigito = self.substr(isbn, len(isbn), 1)
      sisbn=''
      for ncont in range(1, len(isbn)):
        if self.substr(isbn,ncont,1)!='-':
          sisbn=sisbn+self.substr(isbn,ncont,1)
  
      if sdigito == 'X':
        nsoma = 10
      else:
        nvalor = int(sdigito)
        nsoma = nvalor
  
      for ncont in range(1, 10):
        snum = self.substr(sisbn, ncont, 1)
        nvalor = int(snum)
        nsoma=nsoma + (nvalor * (11 - ncont))
  
      if ((nsoma % 11) == 0):
        return True
      else:
        return False
    else:
      return False

  def validaDataHora(self, sDataHora, bSoData):
    bvalida=False
    bdatavalida=False
    bhoravalida=False
    nudiames=0
    if bSoData==True: ntam=10
    else: ntam=19

    if len(sDataHora)==ntam:
      sdia = self.substr(sDataHora,1,2)
      ndia = int(sdia)
      smes = self.substr(sDataHora,4,2)
      nmes = int(smes)
      sano = self.substr(sDataHora,7,4)
      nano = int(sano)
    
      if (nano >= 1) and (nano <= 9999):
        if (nmes >= 1) and (nmes <= 31):
            if nmes in [1, 3, 5, 7, 8, 10, 12]: 
              nudiames = 31
            elif nmes == 2: 
              # ano bissexto 
              if (nano % 4) == 0: 
                nudiames = 29
              else: nudiames = 28
            elif nmes in [4, 6, 9, 11]: 
              nudiames = 30
            if (ndia >=1) and (ndia <=nudiames):
               bdatavalida = True
    
      if bSoData:
         if bdatavalida: bvalida = True
         else: bvalida = False
      else:
        if bdatavalida:
            shora = self.substr(sDataHora,12,2)
            nhora = int(shora)
            smin = self.substr(sDataHora,15,2)
            nmin = int(smin)
            sseg = self.substr(sDataHora,18,2)
            nseg = int(sseg)
        
            if (nhora >= 0) and (nhora <= 23):
              if (nmin >= 0) and (nmin <= 59):
                if (nseg >= 0) and (nseg <= 59):
                   bhoravalida = True
        
            if bhoravalida: bvalida = True
            else: bvalida = False
        else:
          bvalida = False
    else:
      bvalida = False
  
    return bvalida

  def retDataHoraStr(self, bData, bHora):
    sDataHora = ''
    
    if bData and bHora:
      sDataHora = strftime('%d/%m/%Y %H:%M:%S', localtime())
    elif bData:
      sDataHora = strftime('%d/%m/%Y', localtime())
    elif bHora:
      sDataHora = strftime('%H:%M:%S', localtime())
    
    return sDataHora;

  def ConverteDataHoraStr(self, sDTHR, bDMY_ou_YMD, sFrmtData, sFrmtHora):
    sDataHora = ''
    sFormato = ''
    
    if len(sFrmtData) > 0:
      if bDMY_ou_YMD:
        ndia = self.substr(sDTHR, 1, 2)
        nmes = self.substr(sDTHR, 4, 2)
        nano = self.substr(sDTHR, 7, 4)
      else:
        nano = self.substr(sDTHR, 1, 4)
        nmes = self.substr(sDTHR, 6, 2)
        ndia = self.substr(sDTHR, 9, 2)
      sDataHora = ndia + '/' + nmes + '/' + nano
      sFormato = '%d/%m/%Y'

    if len(sFrmtHora) > 0:
      nhora = self.substr(sDTHR, 12, 2)
      nmin = self.substr(sDTHR, 15, 2)
      nseg = self.substr(sDTHR, 18, 2)
      sDataHora = sDataHora + nhora + ':' + nmin + ':' + nseg
      sFormato = sFormato + '%H:%M:%S'

    sDTHR = strptime(sDataHora, sFormato)
    sDataHora = strftime( sFrmtData + ' ' + sFrmtHora , sDTHR)
    return sDataHora

  def ConectaBanco(self, sBancoDeDados, sLogin, sSenha):
    import odbc
    #import MySQLdb
    try:
      #self.gConexao = MySQLdb.connect( host = 'localhost', 
      #  db = sBancoDeDados, user = sLogin, passwd = sSenha )
      self.gConexao = odbc.odbc( sBancoDeDados )
    except:
      wxMessageBox(Resource.STR_NCONBANCO, 'Erro', wxOK | wxICON_ERROR)
      return False
    else:
      return True
  
  def DisconectaBanco(self):
    pass
  
  def AtualizaDados(self, hBancoLocal, sSql):
    try:
      cursor = hBancoLocal.cursor()
      # Necessario codificacao de acordo com o banco
      cursor.execute( sSql.encode('latin-1') )   
    except:
      wxMessageBox(Resource.STR_NCEXECSQL, 'Erro', wxOK | wxICON_ERROR)
      return False
    else:
      return True
  
  def ConsultaDados(self, hBancoLocal, sSql):
    try:
      cursor = hBancoLocal.cursor()
      cursor.execute( sSql )   
    except:
      wxMessageBox(Resource.STR_NCEXECSQL, 'Erro', wxOK | wxICON_ERROR)
      return False
    else:
      LISTAMSTR.col = cursor.fetchall()
      LISTAMSTR.tam = len(LISTAMSTR.col)
      if LISTAMSTR.tam > 0:
        return True
      else:
        return False

  def arrumaColunas(self, lstLocal):
    lstLinhas = []
    nQtdCols = len(lstLocal[0])
    for nLinha in range(0,len(lstLocal)):
      lstCols = []
      for nCol in range(0,nQtdCols):
        if type(lstLocal[nLinha][nCol]) is str:
          lstCols.append(lstLocal[nLinha][nCol]) 
        elif type(lstLocal[nLinha][nCol]) is int:
          lstCols.append(str(lstLocal[nLinha][nCol])) 
        elif type(lstLocal[nLinha][nCol]) is float:
          lstCols.append(fpformat.fix(lstLocal[nLinha][nCol],2)) 
        else:
          sDTHR = strptime( str(lstLocal[nLinha][nCol]), "%a %b %d %H:%M:%S %Y")
          lstCols.append(strftime( '%d/%m/%Y %H:%M:%S' , sDTHR)) 
      
      lstLinhas.append(lstCols) 
  
    return lstLinhas

  def ConsultaDadosLista(self, hBancoLocal, lstLocal, sSql):
    try:
      cursor = hBancoLocal.cursor()
      cursor.execute( sSql )   
    except:
      wxMessageBox(Resource.STR_NCEXECSQL, 'Erro', wxOK | wxICON_ERROR)
      return False
    else:
      lstLocal.col = cursor.fetchall()
      lstLocal.tam = len(lstLocal.col)
      if lstLocal.tam > 0:
        lstLocal.col = self.arrumaColunas(lstLocal.col)
        return True
      else:
        return False

  def ValidaCampo(self, sCampo, sMensagemErro):
    bret = False
    if len(sCampo)==0:
      wxMessageBox(sMensagemErro, "Erro", wxOK | wxICON_ERROR)
      bret = True
    else:
  	  bret = False
  
    return bret

  def ConsultaCampoDesc(self, Campos, sTextoSql, sMensagemErro):
    sret = ""
    if self.ConsultaDadosLista(self.gConexao, Campos, sTextoSql):
      sret = Campos.col[0][1]
    else:
      wxMessageBox(sMensagemErro, "Erro", wxOK | wxICON_ERROR)
      sret = ""
    
    return sret

  def AdicionaItemLista(self, lstLista, slCodLista, sCampoCodigo, sCampoDesc):
    sItems = ''; sCodigo = ''; sDesc = ''
    
    if len(sCampoDesc.GetValue()) > 0:
      sCodigo = sCampoCodigo.GetValue()
      sDesc = sCampoDesc.GetValue()
      
      sItems = sCodigo + ' - ' + sDesc
      
      if lstLista.FindString(sItems) == -1:
        slCodLista.col.append(sCodigo)
        lstLista.Append(sItems)
    
      sCampoCodigo.Clear()
      sCampoDesc.Clear() 

  def RemoveItemLista(self, lstLista, slCodLista):
    nSelIndice = 0 
    if lstLista.GetCount() > 0:
      nSelIndice = lstLista.GetSelection()
      if lstLista.Selected(nSelIndice):
        slCodLista.col.pop(nSelIndice);
        lstLista.Delete(nSelIndice)

  def AdicionaValoresLista(self, sTextoSql, lstLista, slCodLista):
    Campos = LISTAMSTR()
    sItems = ''; sCodigo = ''; sDesc = ''
    nLinha = 0
  
    lstLista.Clear()
    slCodLista.col = []
    if self.ConsultaDadosLista(self.gConexao, Campos, sTextoSql): 
      for nLinha in range(0, len(Campos.col)):
        sCodigo = Campos.col[nLinha][0]
        sDesc = Campos.col[nLinha][1]
  
        slCodLista.col.append(sCodigo)
        sItems = sCodigo + ' - ' + sDesc
        lstLista.Append(sItems)

  def AdicionaColunasGrid(self, grid, nPosIni, nQtdCols, nLargura, sRotulos):
    nPos = 0; nCont = 0
    
    if nPosIni > 0:
      grid.AppendCols(nQtdCols)
    nCont = 0
    for nPos in range(nPosIni, nPosIni+nQtdCols):
      grid.SetColSize(nPos, nLargura[nCont])
      grid.SetColLabelValue(nPos, sRotulos[nCont])
      nCont = nCont + 1

  def AdicionaLinhasGrid(self, grid, lstLinhas, nQtdCol):
    nCol = 0; nLinha = 0
  
    grid.DeleteRows(0, grid.GetNumberRows(), True)
    grid.AppendRows(lstLinhas.tam, True)
    for nCol in range(0, nQtdCol):
      for nLinha in range(0, lstLinhas.tam):
        grid.SetCellValue(nLinha, nCol, str(lstLinhas.col[nLinha][nCol]))

