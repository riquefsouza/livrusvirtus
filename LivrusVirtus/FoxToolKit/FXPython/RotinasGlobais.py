from FXPy.fox import *
from time import localtime, strftime 
#, strptime não existe na versão 2.2 do Python
from resource import Resource
from ListaStr import LISTAMSTR
import fpformat
import os

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

  def lerFigura(self, form, nomearquivo):
    return FXBMPIcon(form, 
      open(os.path.join('bmps', nomearquivo), 'rb').read())

  def ValidaFloat(self, sNum):
    nNum = 0.0
    bret = False

    if len(sNum) > 0:
      try:
        nNum = float(sNum)
        if nNum >= 0.01:
          bret = True
      except:
        showModalErrorBox(self, MBOX_OK, 'Erro', Resource.STR_NUMINV)
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
    nano, nmes, ndia, nhora, nmin, nseg = 2005, 1, 1, 0, 0, 0

    if len(sFrmtData) > 0:
      if bDMY_ou_YMD:
        ndia = int(self.substr(sDTHR, 1, 2))
        nmes = int(self.substr(sDTHR, 4, 2))
        nano = int(self.substr(sDTHR, 7, 4))
      else:
        nano = int(self.substr(sDTHR, 1, 4))
        nmes = int(self.substr(sDTHR, 6, 2))
        ndia = int(self.substr(sDTHR, 9, 2))
      #sDataHora = ndia + '/' + nmes + '/' + nano
      #sFormato = '%d/%m/%Y'

    if len(sFrmtHora) > 0:
      nhora = int(self.substr(sDTHR, 12, 2))
      nmin = int(self.substr(sDTHR, 15, 2))
      nseg = int(self.substr(sDTHR, 18, 2))
      #sDataHora = sDataHora + nhora + ':' + nmin + ':' + nseg
      #sFormato = sFormato + '%H:%M:%S'

    #sDTHR = strptime(sDataHora, sFormato)
    sDTHR = (nano, nmes, ndia, nhora, nmin, nseg, 0, 1, 0)
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
      showModalErrorBox(self, MBOX_OK, 'Erro', Resource.STR_NCONBANCO)
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
      showModalErrorBox(self, MBOX_OK, 'Erro', Resource.STR_NCEXECSQL)
      return False
    else:
      return True
  
  def ConsultaDados(self, hBancoLocal, sSql):
    try:
      cursor = hBancoLocal.cursor()
      cursor.execute( sSql )   
    except:
      showModalErrorBox(self, MBOX_OK, 'Erro', Resource.STR_NCEXECSQL)
      return False
    else:
      LISTAMSTR.col = cursor.fetchall()
      LISTAMSTR.tam = len(LISTAMSTR.col)
      if LISTAMSTR.tam > 0:
        return True
      else:
        return False

  def strptimeFixo(self, sDataHora):
    lmes = {'Jan':1,'Feb':2, 'Mar':3 , 'Apr':4, 'May':5, 'Jun':6
    , 'Jul':7, 'Aug':8, 'Sep':9, 'Oct':10, 'Nov':11, 'Dec':12 }
    #nwdia = self.substr(sDataHora,1,3)		
    nmes = lmes[self.substr(sDataHora,5,3)]
    ndia = int(self.substr(sDataHora,9,2))
    nhora = int(self.substr(sDataHora,12,2))
    nmin = int(self.substr(sDataHora,15,2))
    nseg = int(self.substr(sDataHora,18,2))
    nano = int(self.substr(sDataHora,21,4))
  
    sDTHR = (nano, nmes, ndia, nhora, nmin, nseg, 0, 1, 0)
    return sDTHR

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
          #sDTHR = strptime( str(lstLocal[nLinha][nCol]), "%a %b %d %H:%M:%S %Y")
          sDTHR = self.strptimeFixo( str(lstLocal[nLinha][nCol]) )
          lstCols.append(strftime( '%d/%m/%Y %H:%M:%S', sDTHR)) 
      
      lstLinhas.append(lstCols) 
  
    return lstLinhas

  def ConsultaDadosLista(self, hBancoLocal, lstLocal, sSql):
    try:
      cursor = hBancoLocal.cursor()
      cursor.execute( sSql )   
    except:
      showModalErrorBox(self, MBOX_OK, 'Erro', Resource.STR_NCEXECSQL)
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
      showModalErrorBox(self, MBOX_OK, 'Erro', sMensagemErro)
      bret = True
    else:
  	  bret = False
  
    return bret

  def ConsultaCampoDesc(self, Campos, sTextoSql, sMensagemErro):
    sret = ""
    if self.ConsultaDadosLista(self.gConexao, Campos, sTextoSql):
      sret = Campos.col[0][1]
    else:
      showModalErrorBox(self, MBOX_OK, 'Erro', sMensagemErro)
      sret = ""
    
    return sret

  def AdicionaItemLista(self, lstLista, slCodLista, sCampoCodigo, sCampoDesc):
    if len(sCampoDesc.getText()) > 0:
      sCodigo = sCampoCodigo.getText()
      sDesc = sCampoDesc.getText()
      
      sItems = sCodigo + ' - ' + sDesc
      
      if lstLista.findItem(sItems) == -1:
        slCodLista.col.append(sCodigo) 
        lstLista.appendItem(sItems)
      sCampoCodigo.setText("")
      sCampoDesc.setText("")
  
  def RemoveItemLista(self, lstLista, slCodLista):
    if lstLista.getNumItems() > 0:
      nSelIndice = lstLista.getCurrentItem()
      if lstLista.isItemCurrent(nSelIndice):
        slCodLista.col.pop(nSelIndice)
        lstLista.removeItem(nSelIndice)
  
  def AdicionaValoresLista(self, sTextoSql, lstLista, slCodLista):
    lstCampos = LISTAMSTR()
    nLinha = 0
  
    lstLista.clearItems()
    slCodLista.col = []
    if self.ConsultaDadosLista(self.gConexao, lstCampos, sTextoSql):
      for nLinha in range(0,lstCampos.tam):
        sCodigo = lstCampos.col[nLinha][0]
        sDesc = lstCampos.col[nLinha][1]
  
        slCodLista.col.append(lstCampos.col[nLinha][0])
        sItems = sCodigo + ' - ' + sDesc
        lstLista.appendItem(sItems)
  
  def AdicionaColunasGrid(self, grid, nPosIni, nQtdCols, nLargura, sRotulos):
    #if (nPosIni > 1):
    #  grid.insertColumns(nPosIni, nQtdCols)
    nCont = 0
    for nPos in range(nPosIni,(nPosIni+nQtdCols)):
      grid.setColumnWidth(nPos, nLargura[nCont])
      grid.setItemText(0, nPos, sRotulos[nCont])  
      nCont = nCont + 1
  
  def AdicionaLinhasGrid(self, grid, lstLinhas, nQtdCol):
    if grid.getNumRows() > 1:
      grid.removeRows(1, grid.getNumRows()-1)  
    grid.insertRows(1, lstLinhas.tam)

    for nLinha in range(1, grid.getNumRows()):
      grid.setItemText(nLinha, 0, str(nLinha))
      grid.getItem(nLinha, 0).setButton(True)

    for nCol in range(1, nQtdCol+1):
      for nLinha in range(1, lstLinhas.tam+1):
        sLinha = lstLinhas.col[nLinha-1][nCol-1]
        grid.setItemText(nLinha, nCol, sLinha)
        if nCol > 1:
          grid.getItem(nLinha, nCol).justify = FXTableItem.LEFT

  def IniciaLayoutGrid(self, grid, nQtdLinhas, nQtdCols):
    grid.setTableSize(nQtdLinhas, nQtdCols)

    grid.leadingRows = 1
    grid.leadingCols = 1
    #grid.trailingRows = 1
    #grid.trailingCols = 1

    grid.setItemText( 0,  0, "")
    grid.setItemText( 0, nQtdCols-1, "")
    grid.setItemText(nQtdLinhas-1,  0, "")
    grid.setItemText(nQtdLinhas-1, nQtdCols-1, "")
    
    for nCol in range(1, nQtdCols):
      grid.setItemText(0, nCol, "")
      grid.getItem(0, nCol).setButton(True)
      grid.getItem(0, nCol).justify = FXTableItem.LEFT
    
    for nLinha in range(1, nQtdLinhas):
      grid.setItemText(nLinha, 0, str(nLinha))
      grid.getItem(nLinha, 0).setButton(True)

    grid.getItem(0, 0).setButton(True)

    grid.setItemText(0, 1, "Código")
    grid.setColumnWidth(1, 80)
    grid.setItemText(0, 2, "Descrição")
    grid.setColumnWidth(2, 180)
