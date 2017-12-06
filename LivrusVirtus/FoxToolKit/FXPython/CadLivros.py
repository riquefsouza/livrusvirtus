from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from ListaStr import LISTAMSTR, LISTASTR
import Principal
import ConEditoras
import ConAssuntos
import ConAutores

class frmCadLivros(frmCadastros):

  [ID_FRMCADLIVROS_BTNADASSUNTOS, ID_FRMCADLIVROS_BTNADAUTORES, 
  ID_FRMCADLIVROS_BTNPASSUNTO, ID_FRMCADLIVROS_BTNPAUTOR, 
  ID_FRMCADLIVROS_BTNPEDITORA, ID_FRMCADLIVROS_LSTASSUNTOS, 
  ID_FRMCADLIVROS_LSTAUTORES, ID_FRMCADLIVROS_EDTCODASSUNTO, 
  ID_FRMCADLIVROS_EDTCODAUTOR, ID_FRMCADLIVROS_EDTCODEDITORA] = range(600,610)

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADLIVRO, 
      iconeMDI, menuMDI, TEXTFIELD_NORMAL, False, False)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNNOVO, 
      frmCadLivros.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadLivros.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadLivros.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadLivros.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadLivros.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadLivros.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadLivros.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadLivros.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadLivros.onClose)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadLivros.ID_FRMCADASTROS_EDTCODIGO, 
      frmCadLivros.onEdtCodigo_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadLivros.ID_FRMCADLIVROS_EDTCODEDITORA, 
      frmCadLivros.onEdtCodEditora_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadLivros.ID_FRMCADLIVROS_EDTCODASSUNTO, 
      frmCadLivros.onEdtCodAssunto_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadLivros.ID_FRMCADLIVROS_EDTCODAUTOR, 
      frmCadLivros.onEdtCodAutor_Killfocus)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADLIVROS_BTNPEDITORA, 
      frmCadLivros.onBtnPEditora)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADLIVROS_BTNPASSUNTO, 
      frmCadLivros.onBtnPAssunto)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADLIVROS_BTNADASSUNTOS, 
      frmCadLivros.onBtnAdAssuntos)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADLIVROS_BTNPAUTOR, 
      frmCadLivros.onBtnPAutor)
    FXMAPFUNC(self, SEL_COMMAND, frmCadLivros.ID_FRMCADLIVROS_BTNADAUTORES, 
      frmCadLivros.onBtnAdAutores)
    FXMAPFUNC(self, SEL_DOUBLECLICKED, frmCadLivros.ID_FRMCADLIVROS_LSTASSUNTOS, 
      frmCadLivros.onLstAssuntos_Dblclk)
    FXMAPFUNC(self, SEL_DOUBLECLICKED, frmCadLivros.ID_FRMCADLIVROS_LSTAUTORES, 
      frmCadLivros.onLstAutores_Dblclk)

    self.resize(548, 475)
    self.labCodigo.setText("ISBN:")
    #self.edtCodigo.hide()
    self.edtCodigo = FXTextField(self.frame5, 13, self, 
      frmCadLivros.ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|
      FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 24, 121, 21, 3, 20)
    self.labDescricao.setText("T\xedtulo:")
    self.edtDescricao.resize(312, 21)
    self.edtDescricao.setNumColumns(50)
  
    frame10 = FXVerticalFrame(self.frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame11 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame(frame11, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame13 = FXHorizontalFrame(frame11, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame15 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame16 = FXVerticalFrame(frame15, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame17 = FXVerticalFrame(frame15, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame18 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXVerticalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame20 = FXHorizontalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame21 = FXVerticalFrame(frame20, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame22 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame23 = FXVerticalFrame(frame22, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
    frame24 = FXHorizontalFrame(frame22, LAYOUT_LEFT|FRAME_THICK|
      FRAME_SUNKEN, 0,0,0,0,0,0,0,0)
  
    frame25 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame26 = FXVerticalFrame(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame27 = FXHorizontalFrame(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame28 = FXVerticalFrame(frame27, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame29 = FXHorizontalFrame(self.frame3, LAYOUT_RIGHT|FRAME_THICK|
      FRAME_SUNKEN, 0,0,0,0,0,0,0,0)
  
    labEdicao = FXLabel(frame10, "Edição:", None, LAYOUT_LEFT, 
      326, 48, 39, 13)
    self.edtEdicao = FXSpinner(frame10, 10, None, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      324, 64, 92, 21)
    self.edtEdicao.setRange(1, 9999)
    self.edtEdicao.disable()
  
    labAnoPubli = FXLabel(frame12, "Ano Publicação:", None, LAYOUT_LEFT, 
      8, 88, 81, 13)
    self.edtAnoPubli = FXSpinner(frame12, 10, None, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 104, 92, 21)
    self.edtAnoPubli.setRange(1, 9999)
    self.edtAnoPubli.disable()
  
    labEditora = FXLabel(frame14, "Editora:", None, LAYOUT_LEFT, 
      104, 88, 39, 13)
    self.edtCodEditora = FXTextField(frame14, 5, self, 
      frmCadLivros.ID_FRMCADLIVROS_EDTCODEDITORA, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      104, 104, 78, 21, 3, 20)
    self.edtCodEditora.disable()
    self.edtEditora = FXTextField(frame13, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      184, 104, 216, 21, 3, 20)
    self.edtEditora.disable()
    self.btnPEditora = FXButton(frame13, "...", None, self, 
      frmCadLivros.ID_FRMCADLIVROS_BTNPEDITORA, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 400, 104, 21, 21, 10, 10, 3, 3 )
    self.btnPEditora.disable()
  
    labVolume = FXLabel(frame16, "Volume:", None, LAYOUT_LEFT, 
      8, 128, 41, 13)
    self.edtVolume = FXSpinner(frame16, 10, None, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 144, 92, 21)
    self.edtVolume.setRange(1, 9999)
    self.edtVolume.disable()
  
    labIdioma = FXLabel(frame17, "Volume:", None, LAYOUT_LEFT, 
      104, 128, 56, 13)
    self.cmbIdioma = FXComboBox(frame17,8,8,None,0,
      COMBOBOX_INSERT_LAST|FRAME_SUNKEN|FRAME_THICK|LAYOUT_SIDE_TOP|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 144, 320, 21, 3, 20)
    self.cmbIdioma.setEditable(False)
    self.cmbIdioma.setNumVisible(8)
    self.cmbIdioma.disable()
    
    labNPaginas = FXLabel(frame19, "Nº Páginas:", None, LAYOUT_LEFT, 
      8, 168, 59, 13)
    self.edtNPaginas = FXSpinner(frame19, 10, None, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 184, 92, 21)
    self.edtNPaginas.setRange(1, 9999)
    self.edtNPaginas.disable()
  
    labAssunto = FXLabel(frame21, "Assunto:", None, LAYOUT_LEFT, 
      104, 168, 44, 13)
    self.edtCodAssunto = FXTextField(frame21, 10, self, 
      frmCadLivros.ID_FRMCADLIVROS_EDTCODASSUNTO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      104, 184, 78, 21, 3, 20)
    self.edtCodAssunto.disable()
    self.edtAssunto = FXTextField(frame20, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      184, 184, 192, 21, 3, 20)
    self.edtAssunto.disable()
    self.btnAdAssuntos = FXButton(frame20, "+", None, self, 
      frmCadLivros.ID_FRMCADLIVROS_BTNADASSUNTOS, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 376, 184, 21, 21, 10, 10, 3, 3 )
    self.btnAdAssuntos.disable()
    self.btnPAssunto = FXButton(frame20, "...", None, self, 
      frmCadLivros.ID_FRMCADLIVROS_BTNPASSUNTO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 400, 184, 21, 21, 10, 10, 3, 3 )
    self.btnPAssunto.disable()
  
    labPreco = FXLabel(frame23, "Preço:", None, LAYOUT_LEFT, 
      8, 216, 40, 13)
    self.edtPreco = FXTextField(frame23, 7, None, 
      frmCadLivros.ID_FRMCADLIVROS_EDTCODEDITORA, TEXTFIELD_LIMITED|TEXTFIELD_REAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      7, 232, 92, 21, 3, 20)
    self.edtPreco.disable()

    self.lstAssuntos = FXList(frame24, 1, self, frmCadLivros.ID_FRMCADLIVROS_LSTASSUNTOS, 
      LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 208, 320, 48)
    self.lstAssuntos.disable()
  
    labQtdEstoque = FXLabel(frame26, "Qtd. Estoque:", None, LAYOUT_LEFT, 
      6, 256, 68, 13)
    self.edtQtdEstoque = FXSpinner(frame26, 10, None, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 272, 92, 21)
    self.edtQtdEstoque.setRange(0, 9999)
    self.edtQtdEstoque.disable()
  
    labAutor = FXLabel(frame28, "Autor:", None, LAYOUT_LEFT, 
      104, 256, 31, 13)
    self.edtCodAutor = FXTextField(frame28, 10, self, 
      frmCadLivros.ID_FRMCADLIVROS_EDTCODAUTOR, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      104, 272, 78, 21, 3, 20)
    self.edtCodAutor.disable()
    self.edtAutor = FXTextField(frame27, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      184, 272, 192, 21, 3, 20)
    self.edtAutor.disable()
    self.btnAdAutores = FXButton(frame27, "+", None, self, 
      frmCadLivros.ID_FRMCADLIVROS_BTNADAUTORES, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 376, 272, 21, 21, 10, 10, 3, 3 )
    self.btnAdAutores.disable()
    self.btnPAutor = FXButton(frame27, "...", None, self, 
      frmCadLivros.ID_FRMCADLIVROS_BTNPAUTOR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 400, 272, 21, 21, 10, 10, 3, 3 )
    self.btnPAutor.disable()
  
    self.lstAutores = FXList(frame29, 1, self, frmCadLivros.ID_FRMCADLIVROS_LSTAUTORES, 
      LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 296, 320, 48)
    self.lstAutores.disable()

    self.slAssuntos = LISTASTR()
    self.slAutores = LISTASTR()
    self.slIdiomas = LISTASTR()
   
    self.AdicionaCombo()
    self.IniciaBotoes()

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_ISBNNINF):
      return False
    if bTodosDados:
      if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_TITNINF):
        return False
      if self.Rotinas.ValidaCampo(self.edtEditora.getText(), Resource.STR_EDTNINF):
        return False
      if self.lstAssuntos.getNumItems() == 0:
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_ASSNINF)
        return False
      if self.lstAutores.getNumItems()==0:
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_AUTNINF)
        return False
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.InformaLimpaDadosLocal(False)
    HabilitaDadosLocal(True)
    return True
  
  def onBtnPesquisar(self, sender, sel, ptr):
    if self.PesquisarDados(self.ConsSQL.Livro('S', self.edtCodigo.getText(),
      "","","","","","","","",""), Resource.STR_LIVNENC):
      self.InformaLimpaDadosLocal(True)
      self.HabilitaDadosLocal(True)
    return True
  
  def onBtnAnterior(self, sender, sel, ptr):
    if self.registroAnterior():
      self.InformaLimpaDadosLocal(True)
    return True
  
  def onBtnProximo(self, sender, sel, ptr):
    if self.registroProximo():
      self.InformaLimpaDadosLocal(True)
    return True
  
  def onBtnSalvar(self, sender, sel, ptr):
    nPos = self.cmbIdioma.getCurrentItem()
    sCodIdioma = self.slIdiomas.col[nPos]
  
    sSqlUpdate = self.ConsSQL.Livro('U', self.edtCodigo.getText(), 
      self.edtDescricao.getText(), str(self.edtEdicao.getValue()), 
      str(self.edtAnoPubli.getValue()), str(self.edtVolume.getValue()),
      self.edtCodEditora.getText(), sCodIdioma, str(self.edtNPaginas.getValue()),
      self.Rotinas.VirgulaParaPonto(self.edtPreco.getText(),False),
      str(self.edtQtdEstoque.getValue()))
  
    sSqlInsert = self.ConsSQL.Livro('I', self.edtCodigo.getText(), 
      self.edtDescricao.getText(), str(self.edtEdicao.getValue()), 
      str(self.edtAnoPubli.getValue()), str(self.edtVolume.getValue()),
      self.edtCodEditora.getText(), sCodIdioma, str(self.edtNPaginas.getValue()),
      self.Rotinas.VirgulaParaPonto(self.edtPreco.getText(),False),
      str(self.edtQtdEstoque.getValue()))
  
    if self.SalvarDados(self.ValidaDados(True), self.ConsSQL.Livro('S', 
      self.edtCodigo.getText(),"","","","","","","","",""),
      sSqlUpdate, sSqlInsert, False):
      self.SalvaLista('A')
      self.SalvaLista('B')
      self.btnLimparClick()
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(False)	    
    return True
  
  def onBtnExcluir(self, sender, sel, ptr):
    if self.ExcluirDados(ValidaDados(False), self.ConsSQL.Livro('D', 
      self.edtCodigo.getText(), "","","","","","","","","")):
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(False)
    return True
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.btnLimparClick()
    self.InformaLimpaDadosLocal(False)
    self.HabilitaDadosLocal(False)
    return True

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True

  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaToolButton("tlbLivro")
    Principal.fPrincipal.habilitaMenu("CadLivros")
    self.destroy()
    return True
 
  def InformaLimpaDadosLocal(self, bInformar):
    if (bInformar):
      self.edtEdicao.setValue(int(self.lstRegistros.col[self.nLinhaRegistro][2]))
      self.edtAnoPubli.setValue(int(self.lstRegistros.col[self.nLinhaRegistro][3]))
      self.edtVolume.setValue(int(self.lstRegistros.col[self.nLinhaRegistro][4]))
      self.edtCodEditora.setText(self.lstRegistros.col[self.nLinhaRegistro][5])
      self.edtEditora.setText(self.lstRegistros.col[self.nLinhaRegistro][6])
      self.cmbIdioma.setText(self.lstRegistros.col[self.nLinhaRegistro][8])
      self.edtNPaginas.setValue(int(self.lstRegistros.col[self.nLinhaRegistro][9]))
      self.edtPreco.setText(
        self.Rotinas.VirgulaParaPonto(self.lstRegistros.col[self.nLinhaRegistro][10], True))
      self.edtQtdEstoque.setValue(int(self.lstRegistros.col[self.nLinhaRegistro][11]))
      self.Rotinas.AdicionaValoresLista(self.ConsSQL.LivroAss('S', 
        self.edtCodigo.getText(), ""), self.lstAssuntos, self.slAssuntos)      
      self.Rotinas.AdicionaValoresLista(self.ConsSQL.LivroAut('S',
        self.edtCodigo.getText(), ""), self.lstAutores, self.slAutores)
    else:  
      self.edtEdicao.setValue(1)
      self.edtAnoPubli.setValue(
        int(self.Rotinas.substr(self.Rotinas.retDataHoraStr(True,False),7,4)))
      self.edtVolume.setValue(1)
      self.edtCodEditora.setText("")
      self.edtEditora.setText("")
      self.cmbIdioma.setCurrentItem(0)    
      self.edtNPaginas.setValue(1)
      self.edtPreco.setText("0,00")
      self.edtQtdEstoque.setValue(1)
      self.edtCodAssunto.setText("")
      self.lstAssuntos.clearItems()
      self.edtCodAutor.setText("")
      self.lstAutores.clearItems()
      self.slAssuntos.col = []
      self.slAutores.col = []
  
  def HabilitaDadosLocal(self, bHabilita):
    if bHabilita:
      self.edtEdicao.enable()
      self.edtAnoPubli.enable()
      self.edtVolume.enable()
      self.edtCodEditora.enable()
      self.btnPEditora.enable()
      self.cmbIdioma.enable()
      self.edtNPaginas.enable()
      self.edtPreco.enable()
      self.edtQtdEstoque.enable()
      self.edtCodAssunto.enable()
      self.btnPAssunto.enable()
      self.btnAdAssuntos.enable()
      self.lstAssuntos.enable()
      self.edtCodAutor.enable()
      self.btnPAutor.enable()
      self.btnAdAutores.enable()
      self.lstAutores.enable()
    else:
      self.edtEdicao.disable()  
      self.edtAnoPubli.disable()
      self.edtVolume.disable()
      self.edtCodEditora.disable()
      self.btnPEditora.disable()
      self.cmbIdioma.disable()
      self.edtNPaginas.disable()
      self.edtPreco.disable()
      self.edtQtdEstoque.disable()
      self.edtCodAssunto.disable()
      self.btnPAssunto.disable()
      self.btnAdAssuntos.disable()
      self.lstAssuntos.disable()
      self.edtCodAutor.disable()
      self.btnPAutor.disable()
      self.btnAdAutores.disable()
      self.lstAutores.disable()

  def AdicionaCombo(self):
    self.ConsCampos = LISTAMSTR()
  
    if self.Rotinas.ConsultaDadosLista(self.Rotinas.gConexao, self.ConsCampos, 
      self.ConsSQL.Idioma('S',"","")):
      self.slIdiomas.col = []
      for nLinha in range(0,self.ConsCampos.tam):
  	    self.slIdiomas.col.append(self.ConsCampos.col[nLinha][0])
  	    self.cmbIdioma.appendItem(self.ConsCampos.col[nLinha][1])   
    if self.ConsCampos.tam < 8:
      self.cmbIdioma.setNumVisible(self.ConsCampos.tam)
  
  def SalvaLista(self, sOpcao):
    self.sISBN = self.edtCodigo.getText()
    if sOpcao=='A':
      self.Rotinas.AtualizaDados(self.Rotinas.gConexao, 
        self.ConsSQL.LivroAss('D',self.sISBN,"")) 
  
      self.nQtd = len(self.slAssuntos.col)
      for nCont in range(0, self.nQtd):
        self.Rotinas.AtualizaDados(self.Rotinas.gConexao, 
          self.ConsSQL.LivroAss('I', self.sISBN, self.slAssuntos.col[nCont]))
     
    elif sOpcao=='B':
      self.Rotinas.AtualizaDados(self.Rotinas.gConexao,
        self.ConsSQL.LivroAut('D',self.sISBN,""))
  
      self.nQtd = len(self.slAutores.col)
      for nCont in range(0, self.nQtd):
        self.Rotinas.AtualizaDados(self.Rotinas.gConexao, 
          self.ConsSQL.LivroAut('I', self.sISBN, self.slAutores.col[nCont]))
  
  def onEdtCodigo_Killfocus(self, sender, sel, ptr):
    if len(self.edtCodigo.getText()) > 0:
      if self.Rotinas.validaISBN(self.edtCodigo.getText())==False:
        self.edtCodigo.setText("")
        self.edtCodigo.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_ISBNINV)
    return True
  
  def onEdtCodEditora_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtCodEditora.getText()) > 0:
      sEditora = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Editora('S',
        self.edtCodEditora.getText(),""),Resource.STR_EDTNENC)    
      if len(sEditora) > 0:
        self.edtEditora.setText(sEditora)
      else:
        self.edtCodEditora.setText("")
        self.edtEditora.setText("")
        self.edtCodEditora.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_EDTNENC)
    else:
      self.edtEditora.setText("")
    return True
  
  def onEdtCodAssunto_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtCodAssunto.getText()) > 0:
      sAssunto = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Assunto('S',
        self.edtCodAssunto.getText(),""),Resource.STR_ASSNENC)    
  
      if len(sAssunto) > 0:
        self.edtAssunto.setText(sAssunto)
      else:
        self.edtCodAssunto.setText("")
        self.edtAssunto.setText("")
        self.edtCodAssunto.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_ASSNENC)
    else:
      self.edtAssunto.setText("")
    return True
  
  def onEdtCodAutor_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtCodAutor.getText()) > 0:
      sAutor = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Autor('S',
        self.edtCodAutor.getText(),""),Resource.STR_AUTNENC)    
  
      if len(sAutor) > 0:
        self.edtAutor.setText(sAutor)
      else:
        self.edtCodAutor.setText("")
        self.edtAutor.setText("")
        self.edtCodAutor.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_AUTNENC)
    else:
      self.edtAutor.setText("")
    return True
  
  def onBtnPEditora(self, sender, sel, ptr):
    fConEditoras = ConEditoras.frmConEditoras(self)
    fConEditoras.execute()
    self.edtCodEditora.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCodEditora_Killfocus(None,0,None)
    return True
  
  def onBtnPAssunto(self, sender, sel, ptr):
    fConAssuntos = ConAssuntos.frmConAssuntos(self)
    fConAssuntos.execute()
    self.edtCodAssunto.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCodAssunto_Killfocus(self.edtCodAssunto,0,None)
    return True
  
  def onBtnAdAssuntos(self, sender, sel, ptr):
    self.Rotinas.AdicionaItemLista(self.lstAssuntos, 
      self.slAssuntos, self.edtCodAssunto, self.edtAssunto)
    return True
  
  def onBtnPAutor(self, sender, sel, ptr):
    fConAutores = ConAutores.frmConAutores(self)
    fConAutores.execute()
    self.edtCodAutor.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCodAutor_Killfocus(self.edtCodAutor,0,None)
    return True
  
  def onBtnAdAutores(self, sender, sel, ptr):
    self.Rotinas.AdicionaItemLista(self.lstAutores, 
      self.slAutores, self.edtCodAutor, self.edtAutor)	
    return True
  
  def onLstAssuntos_Dblclk(self, sender, sel, ptr):
    self.Rotinas.RemoveItemLista(self.lstAssuntos,self.slAssuntos)
    return True
  
  def onLstAutores_Dblclk(self, sender, sel, ptr):
    self.Rotinas.RemoveItemLista(self.lstAutores,self.slAutores)
    return True
