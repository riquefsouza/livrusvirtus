from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from ListaStr import LISTAMSTR, LISTASTR
import fpformat
import Principal
import ConClientes
import ConLivros

class frmConVendas(frmCadastros):

  [ID_FRMCONVENDAS_BTNPESQUISAR, ID_FRMCONVENDAS_BTNLIMPAR, 
  ID_FRMCONVENDAS_BTNFECHAR, ID_FRMCONVENDAS_BTNPCLIENTE,
  ID_FRMCONVENDAS_BTNPLIVRO, ID_FRMCONVENDAS_GRIDVENDAS,
  ID_FRMCONVENDAS_EDTDTHRVENDA, ID_FRMCONVENDAS_EDTISBN, 
  ID_FRMCONVENDAS_EDTCPF] = range(800,809)

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CONVENLIVRO, 
      iconeMDI, menuMDI, TEXTFIELD_NORMAL, False)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmConVendas.ID_FRMCONVENDAS_BTNPESQUISAR, 
      frmConVendas.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConVendas.ID_FRMCONVENDAS_BTNLIMPAR, 
      frmConVendas.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmConVendas.ID_FRMCONVENDAS_BTNFECHAR, 
      frmConVendas.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmConVendas.onClose)
    FXMAPFUNC(self, SEL_COMMAND, frmConVendas.ID_FRMCONVENDAS_BTNPCLIENTE, 
      frmConVendas.onBtnPCliente)
    FXMAPFUNC(self, SEL_COMMAND, frmConVendas.ID_FRMCONVENDAS_BTNPLIVRO, 
      frmConVendas.onBtnPLivro)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmConVendas.ID_FRMCONVENDAS_EDTDTHRVENDA, 
      frmConVendas.onEdtDtHrVenda_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmConVendas.ID_FRMCONVENDAS_EDTISBN, 
      frmConVendas.onEdtISBN_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmConVendas.ID_FRMCONVENDAS_EDTCPF, 
      frmConVendas.onEdtCPF_Killfocus)
    FXMAPFUNC(self, SEL_SELECTED, frmConVendas.ID_FRMCONVENDAS_GRIDVENDAS, 
      frmConVendas.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConVendas.ID_FRMCONVENDAS_GRIDVENDAS, 
      frmConVendas.onGridChanged)

    self.resize(500, 370)
    self.labCodigo.hide()
    self.edtCodigo.hide()
    self.labDescricao.hide()
    self.edtDescricao.hide()
    self.btnNovo.hide()
  
    frame10 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame(frame10, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame13 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame15 = FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame16 = FXVerticalFrame(frame13, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame17 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame18 = FXVerticalFrame(frame17, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXVerticalFrame(frame17, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame20 = FXHorizontalFrame(frame17, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame21 = FXVerticalFrame(self.frame, LAYOUT_LEFT|LAYOUT_FILL_X|
      LAYOUT_FILL_Y, 0,0,0,0,0,0,0,0)
  
    frame22 = FXHorizontalFrame(self.frame, LAYOUT_FILL_X, 0,0,0,0,0,0,0,0)
    frame23 = FXHorizontalFrame(frame22, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame24 = FXHorizontalFrame(frame22, LAYOUT_RIGHT, 0,0,0,0,0,0,0,0)
  
    frame25 = FXHorizontalFrame(self.frame, LAYOUT_BOTTOM|LAYOUT_RIGHT)
  
    labDtHrVenda = FXLabel(frame11, "Data/Hora Venda:", None, LAYOUT_LEFT, 
      8, 8, 91, 13)
    self.edtDtHrVenda = FXTextField(frame11, 19, self, 
      frmConVendas.ID_FRMCONVENDAS_EDTDTHRVENDA, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 24, 128, 21, 3, 20)
  
    self.btnPesquisar = FXButton(frame12, "&Pesquisar", None, self, 
      frmConVendas.ID_FRMCONVENDAS_BTNPESQUISAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 144, 22, 75, 25, 15, 15, 3, 3 )
  
    labCPF = FXLabel(frame14, "CPF:", None, LAYOUT_LEFT, 
      8, 48, 48, 13)
    self.edtCPF = FXTextField(frame14, 14, self, 
      frmConVendas.ID_FRMCONVENDAS_EDTCPF, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 64, 128, 21, 3, 20)
  
    labCliente = FXLabel(frame15, "Cliente:", None, LAYOUT_LEFT, 
      142, 48, 56, 13)
    self.edtDescricao.hide()
    self.edtCliente = FXTextField(frame15, 30, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      142, 64, 306, 21, 3, 20)
    self.edtCliente.disable()
    self.btnPCliente = FXButton(frame16, "...", None, self, 
      frmConVendas.ID_FRMCONVENDAS_BTNPCLIENTE, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 64, 21, 21, 10, 10, 3, 3 )
  
    labISBN = FXLabel(frame18, "ISBN:", None, LAYOUT_LEFT, 
      8, 88, 48, 13)
    self.edtISBN = FXTextField(frame18, 13, self, 
      frmConVendas.ID_FRMCONVENDAS_EDTISBN, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 104, 128, 21, 3, 20)
  
    labLivro = FXLabel(frame19, "Livro:", None, LAYOUT_LEFT, 
      142, 88, 40, 13)
    self.edtLivro = FXTextField(frame19, 30, None, 0, 
      TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 142, 104, 306, 21, 3, 20)
    self.edtLivro.disable()
    self.btnPLivro = FXButton(frame20, "...", None, self, 
      frmConVendas.ID_FRMCONVENDAS_BTNPLIVRO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 104, 21, 21, 10, 10, 3, 3 )
  
    self.gridVendas = FXTable(frame21, 2, 7, self, frmConVendas.ID_FRMCONVENDAS_GRIDVENDAS, 
      TABLE_COL_SIZABLE|LAYOUT_FILL_X|LAYOUT_FILL_Y, 0, 136, 355, 122)
    self.Rotinas.IniciaLayoutGrid(self.gridVendas, 2, 7)
  
    self.labRegistro = FXLabel(frame23, "Registro 0 de 0", None, LAYOUT_LEFT, 
      8, 16, 144, 13)
    labPrecoTotal = FXLabel(frame24, "Preço Total:", None, LAYOUT_LEFT, 
      280, 248, 61, 13)
    self.edtPrecoTotal = FXTextField(frame24, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      344, 246, 127, 21, 3, 20)
    self.edtPrecoTotal.disable()
  
    self.btnFechar = FXButton(frame25, "&Fechar", None, self, 
      frmConVendas.ID_FRMCONVENDAS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 75, 13, 75, 25, 15, 15, 3, 3 )
    self.btnLimpar = FXButton(frame25, "&Limpar", None, self, 
      frmConVendas.ID_FRMCONVENDAS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 16, 13, 75, 25, 15, 15, 3, 3 )
    
    nLargura = [ 120, 100, 220, 100, 280, 80 ]
    sRotulos = [ "Data/Hora Venda", "CPF", "Cliente", 
     "ISBN", "Livro", "Preço" ]
  
    self.Rotinas.AdicionaColunasGrid(self.gridVendas, 1, 6, nLargura, sRotulos)
    self.edtPrecoTotal.setText("R$ 0,00")
    self.edtDtHrVenda.setText(self.Rotinas.retDataHoraStr(True,True))
    self.edtDtHrVenda.setFocus()

    self.lstLinhas = LISTAMSTR()
 
  def ConsVenda(self, sOpcao):
    sret = ""
  
    if len(self.edtDtHrVenda.getText()) > 0:
      sDataHora = self.Rotinas.ConverteDataHoraStr(self.edtDtHrVenda.getText(), 
        True, "%m/%d/%Y","%H:%M:%S")
    else:
      sDataHora = ""
     
    sISBN = self.edtISBN.getText()
    sCPF = self.edtCPF.getText()
  
    if sOpcao == 'L':
      sret = self.ConsSQL.Venda('S',"ZERO","","","","")
    else:
      sret = self.ConsSQL.Venda(sOpcao, sISBN, sCPF, sDataHora, "", "")
    return sret
  
  def onBtnPesquisar(self, sender, sel, ptr):
    ConsTotal = LISTAMSTR()
 
    if self.Rotinas.ConsultaDadosLista(self.Rotinas.gConexao, 
      self.lstLinhas, self.ConsVenda('S')):
      self.Rotinas.AdicionaLinhasGrid(self.gridVendas, self.lstLinhas, 6)
  
      if self.Rotinas.ConsultaDadosLista(self.Rotinas.gConexao, 
        ConsTotal, self.ConsVenda('P')):
        if ConsTotal.tam > 0:
          nTemp = float(ConsTotal.col[0][0])
          sPrecoTotal = "R$ " + fpformat.fix(nTemp, 2)
          self.edtPrecoTotal.setText(sPrecoTotal)
        self.setLabRegistros(1)
    else:
      showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_VENNENC)
    return True
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.edtCPF.setText("")
    self.edtCliente.setText("")
    self.edtISBN.setText("")
    self.edtLivro.setText("")
    self.labRegistro.setText("Registro 0 de 0")
    if self.gridVendas.getNumRows() > 0:
      self.gridVendas.removeRows(1, self.gridVendas.getNumRows()-2)
      self.gridVendas.setItemText(1, 0, "1")
      for nCol in range(1,self.gridVendas.getNumCols()):
        self.gridVendas.setItemText(1, nCol, "")
   
    self.edtPrecoTotal.setText("R$ 0,00")
    self.edtDtHrVenda.setText(self.Rotinas.retDataHoraStr(True,True))
    self.edtDtHrVenda.setFocus()
    return True

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True

  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("VendasRealizadas")
    self.destroy()
    return True

  def onEdtCPF_Killfocus(self, sender, sel, ptr):
    ConsCampo = LISTAMSTR()
  
    if len(self.edtCPF.getText()) > 0:
      if self.Rotinas.validaCPF(self.edtCPF.getText()):
        sCliente = self.Rotinas.ConsultaCampoDesc(ConsCampo, self.ConsSQL.Cliente('S',
        self.edtCPF.getText(),"","","","","","","","",""),Resource.STR_CLINENC) 
        if len(sCliente) == 0:
          self.edtCPF.setText("")
          self.edtCPF.killFocus()
          showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_CLINENC)
        else:
          self.edtCliente.setText(sCliente)
      else:
        self.edtCPF.setText("")
        self.edtCPF.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_CPFINV)
    else:
      self.edtCliente.setText("")
    return True
  
  def onEdtISBN_Killfocus(self, sender, sel, ptr):
    ConsCampo = LISTAMSTR()
  
    if len(self.edtISBN.getText()) > 0:
      if self.Rotinas.validaISBN(self.edtISBN.getText()):
        sLivro = self.Rotinas.ConsultaCampoDesc(ConsCampo, self.ConsSQL.Livro('Q',
        self.edtISBN.getText(),"","","","","","","","",""),Resource.STR_LIVNENC)
        if len(sLivro) == 0:
          self.edtISBN.setText("")
          self.edtISBN.killFocus()
          showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_LIVNENC)
        else:
           self.edtLivro.setText(sLivro)
           nQtdEstoque = int(ConsCampo.col[0][3])
           if nQtdEstoque > 0:
             self.Rotinas.sPreco = ConsCampo.col[0][2]
             self.Rotinas.sQtdEstoque = ConsCampo.col[0][3]
           else:
             showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_LIVNEST)
      else:
        self.edtISBN.setText("")
        self.edtISBN.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_ISBNINV)
    else:
      self.edtLivro.setText("")
    return True
  
  def onBtnPCliente(self, sender, sel, ptr):
    fConClientes = ConClientes.frmConClientes(self)
    fConClientes.execute()
    self.edtCPF.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCPF_Killfocus(None,0,None)
    return True
  
  def onBtnPLivro(self, sender, sel, ptr):
    fConLivros = ConLivros.frmConLivros(self)
    fConLivros.execute()
    self.edtISBN.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtISBN_Killfocus(None,0,None)
    return True
  
  def setLabRegistros(self, nLinha):
    if nLinha >= 1:
      self.labRegistro.setText("Registro " + str(nLinha) + " de " +
        str(self.gridVendas.getNumRows()-1))
  
  def onGridSelected(self, sender, sel, ptr):
    self.setLabRegistros(sender.getCurrentRow())
    return True
  
  def onGridChanged(self, sender, sel, ptr):
    self.setLabRegistros(sender.getCurrentRow())
    return True
  
  def onEdtDtHrVenda_Killfocus(self, sender, sel, ptr):
    if len(self.edtDtHrVenda.getText()) > 0:
      if self.Rotinas.validaDataHora(self.edtDtHrVenda.getText(), False)==False:
        self.edtDtHrVenda.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_DTHRINV)
    return True
