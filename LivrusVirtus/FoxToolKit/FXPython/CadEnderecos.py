from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
import Principal

class frmCadEnderecos(frmCadastros):

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADENDERECO, 
      iconeMDI, menuMDI, TEXTFIELD_INTEGER, False)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNNOVO, 
      frmCadEnderecos.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadEnderecos.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadEnderecos.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadEnderecos.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadEnderecos.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadEnderecos.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadEnderecos.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEnderecos.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadEnderecos.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadEnderecos.onClose)

    self.resize(540, 225)
    self.labDescricao.setText("Logradouro: ")
    self.labDescricao.resize(57, 13)
    self.edtDescricao.resize(264, 21)
    self.edtDescricao.setNumColumns(40)
  
    frame9 = FXVerticalFrame(self.frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame10 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame13 = FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    labBairro = FXLabel(frame9, "Bairro:", None, LAYOUT_LEFT, 
      280, 48, 48, 13)
    self.edtBairro = FXTextField(frame9, 15, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      280, 64, 144, 21, 3, 20)
    self.edtBairro.disable()
    labCEP = FXLabel(frame11, "CEP:", None, LAYOUT_LEFT, 
      8, 88, 40, 13)
    self.edtCEP = FXTextField(frame11, 8, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 104, 72, 21, 3, 20)
    self.edtCEP.disable()
    labCidade = FXLabel(frame12, "Cidade:", None, LAYOUT_LEFT, 
      88, 88, 40, 13)
    self.edtCidade = FXTextField(frame12, 30, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      88, 104, 184, 21, 3, 20)
    self.edtCidade.disable()
    labEstado = FXLabel(frame13, "Estado:", None, LAYOUT_LEFT, 
      280, 88, 56, 13)
    self.cmbEstado = FXComboBox(frame13, 8, 8, None, 0,
      COMBOBOX_INSERT_LAST|FRAME_SUNKEN|FRAME_THICK|LAYOUT_SIDE_TOP|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 280, 104, 144, 21, 3, 20)
    self.cmbEstado.setEditable(False)
    self.cmbEstado.setNumVisible(8)
    self.cmbEstado.disable()
  
    self.AdicionaCombo()
    self.IniciaBotoes()

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CODNINF):
   	  return False   
    if bTodosDados:
  	  if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_ENDNINF):
    		return False
  	  if self.Rotinas.ValidaCampo(self.edtBairro.getText(), Resource.STR_BAIRRONINF):
    		return False
  	  if self.Rotinas.ValidaCampo(self.edtCEP.getText(), Resource.STR_CEPNINF):
    		return False
  	  if self.Rotinas.ValidaCampo(self.edtCidade.getText(), Resource.STR_CIDADENINF):
    		return False
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.InformaLimpaDadosLocal(False)
    self.HabilitaDadosLocal(True)	
    self.NovoDado(self.ConsSQL.Endereco('N', self.edtCodigo.getText(),"","","","",""))	
    return True
    
  def onBtnPesquisar(self, sender, sel, ptr):
    if self.PesquisarDados(self.ConsSQL.Endereco('S', self.edtCodigo.getText(),
      "","","","",""), Resource.STR_ENDNENC):
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
    if self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Endereco('S', self.edtCodigo.getText(),"","","","",""),
      self.ConsSQL.Endereco('U', self.edtCodigo.getText(), self.edtDescricao.getText(),
        self.edtBairro.getText(), self.edtCEP.getText(), self.edtCidade.getText(), 
        self.cmbEstado.getText()),
      self.ConsSQL.Endereco('I', self.edtCodigo.getText(), self.edtDescricao.getText(),
        self.edtBairro.getText(), self.edtCEP.getText(), self.edtCidade.getText(), 
        self.cmbEstado.getText()), True):
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(False)    
    return True  
  
  def onBtnExcluir(self, sender, sel, ptr):
    if self.ExcluirDados(ValidaDados(False),
      self.ConsSQL.Endereco('D', self.edtCodigo.getText(),"","","","","")):
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
    Principal.fPrincipal.habilitaMenu("CadEnderecos")
    self.destroy()
    return True   
 
  def InformaLimpaDadosLocal(self, bInformar):
    if bInformar:
      self.edtBairro.setText(self.lstRegistros.col[self.nLinhaRegistro][2])
      self.edtCEP.setText(self.lstRegistros.col[self.nLinhaRegistro][3])
      self.edtCidade.setText(self.lstRegistros.col[self.nLinhaRegistro][4])
      self.cmbEstado.setText(self.lstRegistros.col[self.nLinhaRegistro][5])
    else:
      self.edtBairro.setText("")
      self.edtCEP.setText("")
      self.edtCidade.setText("")
      self.cmbEstado.setCurrentItem(0)         
  
  def HabilitaDadosLocal(self, bHabilita):
    if bHabilita:
      self.edtBairro.enable()
      self.edtCEP.enable()
      self.edtCidade.enable()
      self.cmbEstado.enable()
    else:
      self.edtBairro.disable()
      self.edtCEP.disable()
      self.edtCidade.disable()
      self.cmbEstado.disable()      
  
  def AdicionaCombo(self):
    self.cmbEstado.appendItem(Resource.STR_PE)
    self.cmbEstado.appendItem(Resource.STR_AC)
    self.cmbEstado.appendItem(Resource.STR_AL)
    self.cmbEstado.appendItem(Resource.STR_AP)
    self.cmbEstado.appendItem(Resource.STR_AM)
    self.cmbEstado.appendItem(Resource.STR_BA)
    self.cmbEstado.appendItem(Resource.STR_BR)
    self.cmbEstado.appendItem(Resource.STR_CE)
    self.cmbEstado.appendItem(Resource.STR_DF)
    self.cmbEstado.appendItem(Resource.STR_ES)
    self.cmbEstado.appendItem(Resource.STR_GO)
    self.cmbEstado.appendItem(Resource.STR_MT)
    self.cmbEstado.appendItem(Resource.STR_MS)
    self.cmbEstado.appendItem(Resource.STR_MG)
    self.cmbEstado.appendItem(Resource.STR_PA)
    self.cmbEstado.appendItem(Resource.STR_PB)
    self.cmbEstado.appendItem(Resource.STR_PR)
    self.cmbEstado.appendItem(Resource.STR_SC)
    self.cmbEstado.appendItem(Resource.STR_RN)
    self.cmbEstado.appendItem(Resource.STR_RS)
    self.cmbEstado.appendItem(Resource.STR_RJ)
    self.cmbEstado.appendItem(Resource.STR_RO)
    self.cmbEstado.appendItem(Resource.STR_RR)
    self.cmbEstado.appendItem(Resource.STR_SP)
    self.cmbEstado.appendItem(Resource.STR_SE)
    self.cmbEstado.appendItem(Resource.STR_TO)
