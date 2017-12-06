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

class frmVenderLivros(frmCadastros):

  [ID_FRMVENDERLIVROS_BTNVENDER, ID_FRMVENDERLIVROS_BTNLIMPAR, 
  ID_FRMVENDERLIVROS_BTNFECHAR, ID_FRMVENDERLIVROS_BTNPCLIENTE,
  ID_FRMVENDERLIVROS_BTNPLIVRO, ID_FRMVENDERLIVROS_LSTLIVROS,
  ID_FRMVENDERLIVROS_EDTISBN, ID_FRMVENDERLIVROS_BTNADLIVROS] = range(700, 708)

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_VENLIVRO, 
      iconeMDI, menuMDI, TEXTFIELD_NORMAL, False)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmVenderLivros.ID_FRMVENDERLIVROS_BTNVENDER, 
      frmVenderLivros.onBtnVender)
    FXMAPFUNC(self, SEL_COMMAND, frmVenderLivros.ID_FRMVENDERLIVROS_BTNLIMPAR, 
      frmVenderLivros.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmVenderLivros.ID_FRMVENDERLIVROS_BTNFECHAR, 
      frmVenderLivros.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmVenderLivros.onClose)
    FXMAPFUNC(self, SEL_COMMAND, frmVenderLivros.ID_FRMVENDERLIVROS_BTNPCLIENTE, 
      frmVenderLivros.onBtnPCliente)
    FXMAPFUNC(self, SEL_COMMAND, frmVenderLivros.ID_FRMVENDERLIVROS_BTNPLIVRO, 
      frmVenderLivros.onBtnPLivro)
    FXMAPFUNC(self, SEL_COMMAND, frmVenderLivros.ID_FRMVENDERLIVROS_BTNADLIVROS, 
      frmVenderLivros.onBtnAdLivros)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmVenderLivros.ID_FRMCADASTROS_EDTCODIGO, 
      frmVenderLivros.onEdtCodigo_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmVenderLivros.ID_FRMVENDERLIVROS_EDTISBN, 
      frmVenderLivros.onEdtISBN_Killfocus)
    FXMAPFUNC(self, SEL_DOUBLECLICKED, frmVenderLivros.ID_FRMVENDERLIVROS_LSTLIVROS, 
      frmVenderLivros.onLstLivros_Dblclk)

    self.resize(500, 370)
    self.btnNovo.hide()
  
    frame10 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame12 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame13 = FXVerticalFrame(frame12, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame(frame12, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame15 = FXVerticalFrame(frame12, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame16 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame17 = FXVerticalFrame(frame16, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame18 = FXVerticalFrame(frame16, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXHorizontalFrame(frame16, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame20 = FXVerticalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame21 = FXHorizontalFrame(frame20, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame22 = FXHorizontalFrame(frame20, LAYOUT_LEFT|FRAME_THICK|
      FRAME_SUNKEN, 0,0,0,0,0,0,0,0)
  
    frame23 = FXHorizontalFrame(self.frame3, LAYOUT_RIGHT, 0,0,0,0,0,0,0,0)
  
    frame24 = FXHorizontalFrame(self.frame3, LAYOUT_BOTTOM|LAYOUT_RIGHT)
  
    labDtHrVenda = FXLabel(frame11, "Data/Hora Venda:", None, LAYOUT_LEFT, 
      8, 8, 91, 13)
    self.edtDtHrVenda = FXTextField(frame11, 30, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 24, 128, 21, 3, 20)
    self.edtDtHrVenda.disable()
  
    self.labCodigo.hide()
    labCodigo = FXLabel(frame13, "CPF:", None, LAYOUT_LEFT, 
      8, 48, 48, 13)
    self.edtCodigo.hide()
    self.edtCodigo = FXTextField(frame13, 14, self, 
      frmVenderLivros.ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 64, 128, 21, 3, 20)
  
    self.labDescricao.hide()
    labDescricao = FXLabel(frame14, "Cliente:", None, LAYOUT_LEFT, 
      142, 48, 56, 13)
    self.edtDescricao.hide()
    self.edtDescricao = FXTextField(frame14, 30, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      142, 64, 306, 21, 3, 20)
    self.edtDescricao.disable()
  
    self.btnPCliente = FXButton(frame15, "...", None, self, 
      frmVenderLivros.ID_FRMVENDERLIVROS_BTNPCLIENTE, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 64, 21, 21, 10, 10, 3, 3 )
  
    labISBN = FXLabel(frame17, "ISBN:", None, LAYOUT_LEFT, 
      8, 88, 48, 13)
    self.edtISBN = FXTextField(frame17, 13, self, 
      frmVenderLivros.ID_FRMVENDERLIVROS_EDTISBN, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 104, 128, 21, 3, 20)
  
    labLivro = FXLabel(frame18, "Livro:", None, LAYOUT_LEFT, 
      142, 88, 40, 13)
    self.edtLivro = FXTextField(frame18, 30, None, 0,
      TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 142, 104, 282, 21, 3, 20)
    self.edtLivro.disable()
  
    self.btnAdLivros = FXButton(frame19, "+", None, self, 
      frmVenderLivros.ID_FRMVENDERLIVROS_BTNADLIVROS, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 424, 104, 21, 21, 10, 10, 3, 3 )
    self.btnPLivro = FXButton(frame19, "...", None, self, 
      frmVenderLivros.ID_FRMVENDERLIVROS_BTNPLIVRO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 104, 21, 21, 10, 10, 3, 3 )
  
    labLivros = FXLabel(frame21, "Livros para vender:", None, 
      LAYOUT_LEFT, 8, 128, 120, 13)
    self.lstLivros = FXList(frame22, 1, self, frmVenderLivros.ID_FRMVENDERLIVROS_LSTLIVROS, 
      LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 144, 464, 96)
  
    labPrecoTotal = FXLabel(frame23, "Preço Total:", None, 
      LAYOUT_LEFT, 280, 248, 61, 13)
    self.edtPrecoTotal = FXTextField(frame23, 30, None, 0,
      TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 344, 246, 127, 21, 3, 20)
    self.edtPrecoTotal.disable()
  
    self.btnVender = FXButton(frame24, "&Vender", None, self, 
      frmVenderLivros.ID_FRMVENDERLIVROS_BTNVENDER, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 239, 275, 75, 25, 15, 15, 3, 3 )
    self.btnLimpar = FXButton(frame24, "&Limpar", None, self, 
      frmVenderLivros.ID_FRMVENDERLIVROS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 319, 275, 75, 25, 15, 15, 3, 3 )
    self.btnFechar = FXButton(frame24, "&Fechar", None, self, 
      frmVenderLivros.ID_FRMVENDERLIVROS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 399, 275, 75, 25, 15, 15, 3, 3 )
  
    self.edtDtHrVenda.setText(self.Rotinas.retDataHoraStr(True, True))   

    self.slPrecos = LISTASTR()
    self.slISBNs = LISTASTR()
    self.slQtdEstoque = LISTASTR()
    self.nPrecoTotal = 0.0
    self.LimpaDados()

  def LimpaDados(self):
    self.edtDtHrVenda.setText(self.Rotinas.retDataHoraStr(True, True))  
    self.edtCodigo.setText("")
    self.edtDescricao.setText("")
    self.edtISBN.setText("")
    self.edtLivro.setText("")
    self.lstLivros.clearItems()
    self.nPrecoTotal = 0.0
    self.edtPrecoTotal.setText("R$ 0,00")
    self.slPrecos.col = []
    self.slISBNs.col = []
    self.slQtdEstoque.col = []
    self.edtCodigo.setFocus()
  
  def ValidaDados(self):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CPFNINF):
      return False
    if self.lstLivros.getNumItems() == 0:
      showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_LIVVENNINF)
      return False
    return True
  
  def SalvaLista(self):
    nQtd = self.lstLivros.getNumItems()
    sCPF = self.edtCodigo.getText()
    sPrecoTotal = fpformat.fix(self.nPrecoTotal, 2)
    
    sDTHR = self.edtDtHrVenda.getText()
    sDataHora = self.Rotinas.ConverteDataHoraStr(sDTHR, True, 
      "%m/%d/%Y","%H:%M:%S")

    for nCont in range(0, nQtd):
      sISBN = self.slISBNs.col[nCont]   
    
      self.Rotinas.AtualizaDados(self.Rotinas.gConexao, 
        self.ConsSQL.Venda('I',sISBN, sCPF, sDataHora,
        self.Rotinas.VirgulaParaPonto(sPrecoTotal,False),""))
    
      nQtdEstoque = int(self.slQtdEstoque.col[nCont])
      if nQtdEstoque > 0:
        nQtdEstoque = nQtdEstoque - 1
     
      sQtdEstoque = str(nQtdEstoque)
      self.Rotinas.AtualizaDados(self.Rotinas.gConexao, 
        self.ConsSQL.Venda('U',sISBN, "","","", sQtdEstoque))
   
    return True

  def onBtnVender(self, sender, sel, ptr):
    if self.ValidaDados():
      if self.SalvaLista():
        showModalInformationBox(self, MBOX_OK, 
          Resource.STR_TITULO, Resource.STR_VENRESUC)
        self.LimpaDados()
    return True

  def onBtnLimpar(self, sender, sel, ptr):
    self.LimpaDados()
    return True

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True

  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaToolButton("tlbVenda")
    Principal.fPrincipal.habilitaMenu("VenderLivros")
    self.destroy()
    return True
 
  def onEdtCodigo_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtCodigo.getText()) > 0:
      if self.Rotinas.validaCPF(self.edtCodigo.getText()):
        sCliente = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Cliente('S',
        self.edtCodigo.getText(),"","","","","","","","",""),Resource.STR_CLINENC) 
        if len(sCliente)==0:
          self.edtCodigo.setText("")
          self.edtCodigo.killFocus()
          showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_CLINENC)
        else:
           self.edtDescricao.setText(sCliente)
      else:
        self.edtCodigo.setText("")
        self.edtCodigo.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_CPFINV)
    else:
       self.edtDescricao.setText("")
    return True
  
  def onEdtISBN_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtISBN.getText()) > 0:
      if self.Rotinas.validaISBN(self.edtISBN.getText()):
        sLivro = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Livro('Q',
        self.edtISBN.getText(),"","","","","","","","",""),Resource.STR_LIVNENC)
        if len(sLivro)==0:
          self.edtISBN.setText("")
          self.edtISBN.killFocus()
          showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_LIVNENC)
        else:
           self.edtLivro.setText(sLivro)
           nQtdEstoque = int(self.ConsCampo.col[0][3])
           if nQtdEstoque > 0:
             self.Rotinas.sPreco = self.ConsCampo.col[0][2]
             self.Rotinas.sQtdEstoque = self.ConsCampo.col[0][3]
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
    self.edtCodigo.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCodigo_Killfocus(None,0,None)
    return True
  
  def onBtnPLivro(self, sender, sel, ptr):
    fConLivros = ConLivros.frmConLivros(self)
    fConLivros.execute()
    self.edtISBN.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtISBN_Killfocus(None,0,None)
    return True
  
  def onBtnAdLivros(self, sender, sel, ptr): 
    sISBN = self.edtISBN.getText()
    sEdtLivro = self.edtLivro.getText()
    if len(sISBN) > 0:
      sLivros = sISBN + " - " + sEdtLivro + " - R$ " + self.Rotinas.sPreco
      if self.lstLivros.findItem(sLivros)==-1:
        self.slISBNs.col.append(sISBN)
        self.slPrecos.col.append(self.Rotinas.sPreco)
        self.slQtdEstoque.col.append(self.Rotinas.sQtdEstoque)
        self.lstLivros.appendItem(sLivros)
        nPreco = float(self.Rotinas.sPreco)
        self.nPrecoTotal = self.nPrecoTotal + nPreco
      self.edtISBN.setText("")
      self.edtLivro.setText("")
      sPrecoTotal = "R$ " + fpformat.fix(self.nPrecoTotal,2)
      self.edtPrecoTotal.setText(self.Rotinas.VirgulaParaPonto(sPrecoTotal,True))
    return True
  
  def onLstLivros_Dblclk(self, sender, sel, ptr): 
    if self.lstLivros.getNumItems() > 0:
      nSelIndice = self.lstLivros.getCurrentItem()   
      if self.lstLivros.isItemCurrent(nSelIndice):
        nPreco = float(self.slPrecos.col[nSelIndice])
        self.nPrecoTotal = self.nPrecoTotal-nPreco
        sPrecoTotal = "R$ " + fpformat.fix(self.nPrecoTotal, 2)
        self.edtPrecoTotal.setText(self.Rotinas.VirgulaParaPonto(sPrecoTotal,True))
        self.slISBNs.col.pop(nSelIndice)
        self.slPrecos.col.pop(nSelIndice)
        self.slQtdEstoque.col.pop(nSelIndice)
        self.lstLivros.removeItem(nSelIndice)
    return True
