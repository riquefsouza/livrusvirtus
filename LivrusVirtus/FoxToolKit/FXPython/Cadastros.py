from FXPy.fox import *
from ListaStr import LISTAMSTR
from resource import Resource
from RotinasGlobais import RotinasGlobais
import Principal

class frmCadastros(FXMDIChild):
  [ID_FRMCADASTROS_BTNNOVO, ID_FRMCADASTROS_BTNANTERIOR, 
  ID_FRMCADASTROS_BTNEXCLUIR, ID_FRMCADASTROS_BTNFECHAR, 
  ID_FRMCADASTROS_BTNLIMPAR, ID_FRMCADASTROS_BTNPESQUISAR, 
  ID_FRMCADASTROS_BTNPROXIMO, ID_FRMCADASTROS_BTNSALVAR, 
  ID_FRMCADASTROS_EDTCODIGO] = range(400,409)

  def __init__(self, clienteMDI, sTitulo, iconeMDI, menuMDI, 
    nFiltroCodigo, bIniciaBotoes, bMostra_edtCodigo=True):  
    FXMDIChild.__init__(self, clienteMDI, sTitulo, iconeMDI, 
      menuMDI, MDI_NORMAL, 0, 0, 345, 180)

    self.Rotinas = RotinasGlobais.Rotinas
    self.frame = FXVerticalFrame(self, LAYOUT_FILL_X | LAYOUT_FILL_Y)
  
    frame1 = FXVerticalFrame(self.frame, LAYOUT_FILL_X)
    self.frame2 = FXHorizontalFrame(frame1, LAYOUT_TOP)
    
    self.frame3 = FXVerticalFrame(self.frame2, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame4 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    self.frame5 = FXVerticalFrame(frame4, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame6 = FXVerticalFrame(frame4, LAYOUT_LEFT|LAYOUT_BOTTOM, 0,0,0,0,0,0,0,0)
  
    self.frame7 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame8 = FXVerticalFrame(self.frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    self.labCodigo = FXLabel(self.frame5, "Código:", None, LAYOUT_LEFT, 
      8, 8, 36, 13)
    if bMostra_edtCodigo:
      self.edtCodigo = FXTextField(self.frame5, 10, None, 
        frmCadastros.ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|
        FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
        nFiltroCodigo, 8, 24, 121, 21, 3, 20)
    self.btnNovo = FXButton(frame6, "&Novo", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNNOVO, BUTTON_DEFAULT|FRAME_RAISED|
      FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_BOTTOM, 144, 24, 75, 25, 15, 15, 3, 3 )
    self.labDescricao = FXLabel(frame8, "Descrição:", None, LAYOUT_LEFT, 
      8, 48, 51, 13)
    self.edtDescricao = FXTextField(frame8, 30, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 64, 217, 21, 3, 20)
    self.edtDescricao.disable()
  
    if bIniciaBotoes:
      self.IniciaBotoes()    

    self.lstRegistros = LISTAMSTR()
    self.nLinhaRegistro = 0 

  # Necessário por causa da tabulação dos campos
  def IniciaBotoes(self):
    frameBotoesV = FXVerticalFrame(self.frame2,
      LAYOUT_TOP|LAYOUT_RIGHT, 0,0,0,0,18,0,0,0)
    self.btnPesquisar = FXButton(frameBotoesV, "&Pesquisar", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNPESQUISAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 8, 75, 25, 10, 10, 3, 3 )
    self.btnAnterior = FXButton(frameBotoesV, "&Anterior", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNANTERIOR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 40, 75, 25, 15, 15, 3, 3 )
    self.btnProximo = FXButton(frameBotoesV, "Próxi&mo", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNPROXIMO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 72, 75, 25, 15, 15, 3, 3 )
  
    frameBotoesH = FXHorizontalFrame(self.frame, 
      LAYOUT_BOTTOM|LAYOUT_RIGHT)
    self.btnSalvar = FXButton(frameBotoesH, "&Salvar", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNSALVAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT,8, 104, 75, 25, 15, 15, 3, 3 )
    self.btnExcluir = FXButton(frameBotoesH, "&Excluir", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNEXCLUIR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 88, 104, 75, 25, 15, 15, 3, 3 )
    self.btnLimpar = FXButton(frameBotoesH, "&Limpar", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT,168, 104, 75, 25, 15, 15, 3, 3 )
    self.btnFechar = FXButton(frameBotoesH, "&Fechar", None, self, 
      frmCadastros.ID_FRMCADASTROS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 104, 75, 25, 15, 15, 3, 3 )
  
    self.btnLimparClick()
  
  def InformaLimpaDados(self, bInformar):
    if bInformar:
      self.edtCodigo.setText(self.lstRegistros.col[self.nLinhaRegistro][0])
      self.edtDescricao.setText(self.lstRegistros.col[self.nLinhaRegistro][1])
    else:
      self.edtCodigo.setText("")
      self.edtDescricao.setText("")
      self.edtCodigo.enable()
      self.edtCodigo.setFocus() 
  
  def HabilitaDados(self, bHabilita):
    if bHabilita:
      self.edtDescricao.enable()
    else:
      self.edtDescricao.disable()
  
  def btnNovoClick(self):
    self.btnSalvar.enable()
    self.btnExcluir.disable()
    self.btnPesquisar.disable()
    self.btnAnterior.disable()
    self.btnProximo.disable()
    self.btnNovo.disable()
    
    self.nLinhaRegistro = 0
    self.InformaLimpaDados(False)
    self.HabilitaDados(True)	  
  
  def NovoDado(self, sTextoSql):
    lstRegs = LISTAMSTR()
  
    if self.Rotinas.ConsultaDadosLista(self.Rotinas.gConexao, 
      lstRegs, sTextoSql):
      self.edtCodigo.setText(lstRegs.col[0][0])
      self.edtCodigo.disable()
      self.edtDescricao.setFocus() 
  
  def btnLimparClick(self):
    self.nLinhaRegistro = 0
    self.btnSalvar.disable()
    self.btnExcluir.disable()
    self.btnPesquisar.enable()
    self.btnAnterior.disable()
    self.btnProximo.disable()
    self.btnNovo.enable()
  
    self.nLinhaRegistro = 0
    self.InformaLimpaDados(False)
    self.HabilitaDados(False)	  
  
  def ExcluirDados(self, bValidaDados, sTextoSql):
    if bValidaDados:
      if showModalQuestionBox(self, MBOX_YES_NO, "Confirme",
        Resource.STR_CERTEXCL) == MBOX_CLICKED_YES:
        if self.Rotinas.AtualizaDados(self.Rotinas.gConexao, sTextoSql):
          self.btnLimparClick()
          return True     
    return False  
  
  def PesquisarDados(self, sTextoSql, sMensagemErro):
    if len(self.edtCodigo.getText()) == 0:
      self.btnAnterior.enable()
      self.btnProximo.enable()  	
  
    if self.Rotinas.ConsultaDadosLista(self.Rotinas.gConexao, 
      self.lstRegistros, sTextoSql):
       self.InformaLimpaDados(True)
       self.HabilitaDados(True)	
  
       self.btnSalvar.enable()
       self.btnExcluir.enable()
       self.btnPesquisar.disable()
       return True
    else:
      showModalErrorBox(self, MBOX_OK, "Erro", sMensagemErro)
      
    return False
  
  
  def registroAnterior(self):
    if self.nLinhaRegistro > 0:
      self.nLinhaRegistro = self.nLinhaRegistro - 1
      self.InformaLimpaDados(True)
      return True
    else:
      return False
  
  def registroProximo(self):
    if self.nLinhaRegistro < (self.lstRegistros.tam-1):
      self.nLinhaRegistro = self.nLinhaRegistro + 1
      self.InformaLimpaDados(True)
      return True
    else:
      return False
  
  def SalvarDados(self, bValidaDados, sTextoSql, 
    sTextoUpdate, sTextoInsert, bLimparDados):
    sArquiva = ''
  
    if bValidaDados:
      if self.Rotinas.ConsultaDados(self.Rotinas.gConexao,sTextoSql):
        sArquiva = sTextoUpdate
      else:
        sArquiva = sTextoInsert	  	     
      
      if self.Rotinas.AtualizaDados(self.Rotinas.gConexao, sArquiva):
        if bLimparDados:
          self.btnLimparClick()    
        return True
  	
    return False
