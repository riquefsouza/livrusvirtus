from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from ListaStr import LISTAMSTR
import Principal
import ConEnderecos
import ConPaises
import ConProfissoes

class frmCadClientes(frmCadastros):

  [ID_FRMCADCLIENTES_BTNPENDERECO, ID_FRMCADCLIENTES_BTNPPROFISSAO, 
  ID_FRMCADCLIENTES_BTNPPAIS, ID_FRMCADCLIENTES_EDTCODENDERECO, 
  ID_FRMCADCLIENTES_EDTCODPAIS, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
  ID_FRMCADCLIENTES_EDTDTNASC, ID_FRMCADCLIENTES_RBMASCULINO, 
  ID_FRMCADCLIENTES_RBFEMININO] = range(500,509)

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADCLIENTE, 
      iconeMDI, menuMDI, TEXTFIELD_NORMAL, False, False)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNNOVO, 
      frmCadClientes.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadClientes.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadClientes.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadClientes.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadClientes.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadClientes.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadClientes.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadClientes.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadClientes.onClose)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADCLIENTES_RBMASCULINO, 
      frmCadClientes.onCmdSexoMasc)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADCLIENTES_RBFEMININO, 
      frmCadClientes.onCmdSexoFem)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadClientes.ID_FRMCADASTROS_EDTCODIGO, 
      frmCadClientes.onEdtCodigo_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadClientes.ID_FRMCADCLIENTES_EDTDTNASC, 
      frmCadClientes.onEdtDtNasc_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadClientes.ID_FRMCADCLIENTES_EDTCODENDERECO, 
      frmCadClientes.onEdtCodEndereco_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadClientes.ID_FRMCADCLIENTES_EDTCODPAIS, 
      frmCadClientes.onEdtCodPais_Killfocus)
    FXMAPFUNC(self, SEL_FOCUSOUT, frmCadClientes.ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
      frmCadClientes.onEdtCodProfissao_Killfocus)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADCLIENTES_BTNPENDERECO, 
      frmCadClientes.onBtnPEndereco)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADCLIENTES_BTNPPAIS, 
      frmCadClientes.onBtnPPais)
    FXMAPFUNC(self, SEL_COMMAND, frmCadClientes.ID_FRMCADCLIENTES_BTNPPROFISSAO, 
      frmCadClientes.onBtnPProfissao)

    self.resize(558, 515)
    self.labCodigo.setText("CPF:")
    #self.edtCodigo.hide()
    self.edtCodigo = FXTextField(self.frame5, 14, self, 
      frmCadClientes.ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 24, 121, 21, 3, 20)
    self.labDescricao.setText("Nome: ")  
    self.edtDescricao.resize(312, 21)
    self.edtDescricao.setNumColumns(30)
  
    frame10 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame13 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame15 = FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame16 = FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    labEmail = FXLabel(frame11, "Bairro:", None, LAYOUT_LEFT, 
      8, 88, 34, 13)
    self.edtEmail = FXTextField(frame11, 30, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 104, 312, 21, 3, 20)
    self.edtEmail.disable()
  
    labIdentidade = FXLabel(frame12, "Identidade:", None, LAYOUT_LEFT, 
      322, 88, 56, 13)
    self.edtIdentidade = FXTextField(frame12, 10, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      322, 104, 100, 21, 3, 20)
    self.edtIdentidade.disable()

    self.gpSexo = FXGroupBox(frame14,"Sexo",LAYOUT_LEFT|FRAME_GROOVE|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 9, 128, 200, 44)
    frameSexo = FXHorizontalFrame(self.gpSexo, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    self.rbMasculino = FXRadioButton(frameSexo,"Masculino",self,
      frmCadClientes.ID_FRMCADCLIENTES_RBMASCULINO, ICON_BEFORE_TEXT|LAYOUT_LEFT)
    self.rbMasculino.disable()
    self.rbMasculino.setCheck(True)
    self.rbFeminino = FXRadioButton(frameSexo,"Feminino",self,
      frmCadClientes.ID_FRMCADCLIENTES_RBFEMININO, ICON_BEFORE_TEXT|LAYOUT_LEFT)
    self.rbFeminino.disable()
    self.gpSexo.disable()
  
    labTelefone = FXLabel(frame15, "Telefone:", None, LAYOUT_LEFT, 
      216, 128, 48, 13)
    self.edtTelefone = FXTextField(frame15, 17, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      216, 144, 104, 21, 3, 20)
    self.edtTelefone.disable()
  
    labDtNasc = FXLabel(frame16, "Dt. Nascimento:", None, LAYOUT_LEFT, 
      216, 128, 48, 13)
    self.edtDtNasc = FXTextField(frame16, 10, self, 
      frmCadClientes.ID_FRMCADCLIENTES_EDTDTNASC, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 216, 144, 104, 21, 3, 20)
    self.edtDtNasc.disable()
  
    gpEndereco = FXGroupBox(self.frame3,"Endereço",LAYOUT_SIDE_TOP|FRAME_GROOVE|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 9, 128, 430, 145)
  
    frame17 = FXHorizontalFrame(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame18 = FXHorizontalFrame(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXVerticalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame20 = FXVerticalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame21 = FXHorizontalFrame(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame22 = FXVerticalFrame(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame23 = FXVerticalFrame(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame24 = FXVerticalFrame(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    self.edtCodEndereco = FXTextField(frame17, 10, self, 
      frmCadClientes.ID_FRMCADCLIENTES_EDTCODENDERECO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      16, 200, 88, 21, 3, 20)
    self.edtCodEndereco.disable()
  
    self.btnPEndereco = FXButton(frame17, "...", None, self, 
      frmCadClientes.ID_FRMCADCLIENTES_BTNPENDERECO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 104, 200, 21, 21, 10, 10, 3, 3 )
    self.btnPEndereco.disable()
  
    labLogradouro = FXLabel(frame19, "Logradouro:", None, LAYOUT_LEFT, 
      16, 224, 60, 13)
    self.edtLogradouro = FXTextField(frame19, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      16, 240, 264, 21, 3, 20)
    self.edtLogradouro.disable()
  
    labBairro = FXLabel(frame20, "Bairro:", None, LAYOUT_LEFT, 
      284, 224, 48, 13)
    self.edtBairro = FXTextField(frame20, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      284, 240, 144, 21, 3, 20)
    self.edtBairro.disable()
  
    labCEP = FXLabel(frame22, "CEP:", None, LAYOUT_LEFT, 
      16, 264, 40, 13)
    self.edtCEP = FXTextField(frame22, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      16, 280, 78, 21, 3, 20)
    self.edtCEP.disable()
  
    labCidade = FXLabel(frame23, "Cidade:", None, LAYOUT_LEFT, 
      96, 264, 39, 13)
    self.edtCidade = FXTextField(frame23, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      96, 280, 184, 21, 3, 20)
    self.edtCidade.disable()
  
    labEstado = FXLabel(frame24, "Estado:", None, LAYOUT_LEFT, 
      284, 264, 56, 13)
    self.edtEstado = FXTextField(frame24, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      284, 280, 144, 21, 3, 20)
    self.edtEstado.disable()
  
    frame25 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame26 = FXVerticalFrame(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame27 = FXHorizontalFrame(self.frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame28 = FXVerticalFrame(frame27, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    labPais = FXLabel(frame26, "País de origem:", None, LAYOUT_LEFT, 
      8, 320, 77, 16)
    
    self.edtCodPais = FXTextField(frame26, 3, self, 
      frmCadClientes.ID_FRMCADCLIENTES_EDTCODPAIS, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 336, 78, 21, 3, 20)
    self.edtCodPais.disable()
  
    self.edtPais = FXTextField(frame25, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      88, 336, 240, 21, 3, 20)
    self.edtPais.disable()
    self.btnPPais = FXButton(frame25, "...", None, self, 
      frmCadClientes.ID_FRMCADCLIENTES_BTNPPAIS, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 328, 336, 21, 21, 10, 10, 3, 3 )
    self.btnPPais.disable()
  
    labProfissao = FXLabel(frame28, "Profissão:", None, LAYOUT_LEFT, 
      8, 360, 56, 13)
    self.edtCodProfissao = FXTextField(frame28, 10, self, 
      frmCadClientes.ID_FRMCADCLIENTES_EDTCODPROFISSAO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 376, 78, 21, 3, 20)
    self.edtCodProfissao.disable()
    self.edtProfissao = FXTextField(frame27, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      88, 376, 240, 21, 3, 20)
    self.edtProfissao.disable()
    self.btnPProfissao = FXButton(frame27, "...", None, self, 
      frmCadClientes.ID_FRMCADCLIENTES_BTNPPROFISSAO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 328, 376, 21, 21, 10, 10, 3, 3 )
    self.btnPProfissao.disable()
  
    self.IniciaBotoes()

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CPFNINF):
   	  return False    
    if bTodosDados:
      if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_CLININF):
    		return False      
      if self.Rotinas.ValidaCampo(self.edtEmail.getText(), Resource.STR_EMAILNINF):
        return False
      if self.Rotinas.ValidaCampo(self.edtTelefone.getText(), Resource.STR_TELNINF):
        return False
      if self.Rotinas.ValidaCampo(self.edtCodEndereco.getText(), Resource.STR_ENDNINF):
        return False
      if self.Rotinas.ValidaCampo(self.edtCodPais.getText(), Resource.STR_PAISNINF):
        return False
      if self.Rotinas.ValidaCampo(self.edtCodProfissao.getText(), Resource.STR_PROFNINF):
        return False  	
    return True  
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.InformaLimpaDadosLocal(False)
    self.HabilitaDadosLocal(True)
    return True
  
  def onBtnPesquisar(self, sender, sel, ptr):
    if self.PesquisarDados(self.ConsSQL.Cliente('S', self.edtCodigo.getText(),
      "","","","","","","","",""), Resource.STR_CLINENC):
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
    sSexo = ''
  
    if self.rbMasculino.getCheck():
       sSexo = "M" 
    else:   
       sSexo = "F"
     
    sDtNasc = self.Rotinas.ConverteDataHoraStr(self.edtDtNasc.getText(), 
      True, "%Y/%m/%d", "")
  
    sSqlUpdate = self.ConsSQL.Cliente('U', self.edtCodigo.getText(), 
      self.edtDescricao.getText(), self.edtEmail.getText(),  self.edtIdentidade.getText(), 
      sSexo, self.edtTelefone.getText(), sDtNasc, self.edtCodEndereco.getText(), 
      self.edtCodPais.getText(), self.edtCodProfissao.getText())
  
    sSqlInsert = self.ConsSQL.Cliente('I', self.edtCodigo.getText(), 
      self.edtDescricao.getText(), self.edtEmail.getText(),  self.edtIdentidade.getText(), 
      sSexo, self.edtTelefone.getText(), sDtNasc, self.edtCodEndereco.getText(), 
      self.edtCodPais.getText(), self.edtCodProfissao.getText())
  
    if self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Cliente('S', self.edtCodigo.getText(),"","","","","","","","",""),
      sSqlUpdate, sSqlInsert, True):
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(False)	
    return True
  
  def onBtnExcluir(self, sender, sel, ptr):
    if self.ExcluirDados(ValidaDados(False),self.ConsSQL.Cliente('D', 
      self.edtCodigo.getText(),"","","","","","","","","")):
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
    Principal.fPrincipal.habilitaToolButton("tlbCliente")
    Principal.fPrincipal.habilitaMenu("CadClientes")
    self.destroy()
    return True
 
  def InformaLimpaDadosLocal(self, bInformar):
    if (bInformar):
      self.edtCodigo.setText(self.lstRegistros.col[self.nLinhaRegistro][0])
      self.edtEmail.setText(self.lstRegistros.col[self.nLinhaRegistro][2])
      self.edtIdentidade.setText(self.lstRegistros.col[self.nLinhaRegistro][3])
      if self.lstRegistros.col[self.nLinhaRegistro][4] == "M":
        self.rbMasculino.setCheck(True)
        self.rbFeminino.setCheck(False)
      else:
        self.rbMasculino.setCheck(False)
        self.rbFeminino.setCheck(True)
      self.edtTelefone.setText(self.lstRegistros.col[self.nLinhaRegistro][5])
      sTemp = self.lstRegistros.col[self.nLinhaRegistro][6]
      self.edtDtNasc.setText(self.Rotinas.substr(sTemp,1,10))
      self.edtCodEndereco.setText(self.lstRegistros.col[self.nLinhaRegistro][7])
      self.edtLogradouro.setText(self.lstRegistros.col[self.nLinhaRegistro][8])
      self.edtBairro.setText(self.lstRegistros.col[self.nLinhaRegistro][9])
      self.edtCEP.setText(self.lstRegistros.col[self.nLinhaRegistro][10])
      self.edtCidade.setText(self.lstRegistros.col[self.nLinhaRegistro][11])
      self.edtEstado.setText(self.lstRegistros.col[self.nLinhaRegistro][12])
      self.edtCodPais.setText(self.lstRegistros.col[self.nLinhaRegistro][13])
      self.edtPais.setText(self.lstRegistros.col[self.nLinhaRegistro][14])
      self.edtCodProfissao.setText(self.lstRegistros.col[self.nLinhaRegistro][15])
      self.edtProfissao.setText(self.lstRegistros.col[self.nLinhaRegistro][16])
    else:
      self.edtEmail.setText("")
      self.edtIdentidade.setText("")
      self.rbMasculino.setCheck(True)
      self.rbFeminino.setCheck(False)
      self.edtTelefone.setText("")
      self.edtDtNasc.setText("")
      self.edtCodEndereco.setText("")
      self.edtLogradouro.setText("")
      self.edtBairro.setText("")
      self.edtCEP.setText("")
      self.edtCidade.setText("")
      self.edtEstado.setText("")
      self.edtCodPais.setText("")
      self.edtPais.setText("")
      self.edtCodProfissao.setText("")
      self.edtProfissao.setText("")
      self.edtCodigo.setFocus()
  
  def HabilitaDadosLocal(self, bHabilita):
    if (bHabilita):
      self.edtEmail.enable()
      self.edtIdentidade.enable()
      self.gpSexo.enable()
      self.rbMasculino.enable()
      self.rbFeminino.enable()
      self.edtTelefone.enable()
      self.edtDtNasc.enable()
      self.edtCodEndereco.enable()
      self.btnPEndereco.enable()
      self.edtCodPais.enable()
      self.btnPPais.enable()
      self.edtCodProfissao.enable()
      self.btnPProfissao.enable()
    else:
      self.edtEmail.disable()
      self.edtIdentidade.disable()
      self.gpSexo.disable()
      self.rbMasculino.disable()
      self.rbFeminino.disable()
      self.edtTelefone.disable()
      self.edtDtNasc.disable()
      self.edtCodEndereco.disable()
      self.btnPEndereco.disable()
      self.edtCodPais.disable()
      self.btnPPais.disable()
      self.edtCodProfissao.disable()
      self.btnPProfissao.disable()

  def onCmdSexoMasc(self, sender, sel, ptr):
    self.rbMasculino.setCheck(True)
    self.rbFeminino.setCheck(False)
    return True

  def onCmdSexoFem(self, sender, sel, ptr):
    self.rbMasculino.setCheck(False)
    self.rbFeminino.setCheck(True)
    return True
  
  def onEdtCodigo_Killfocus(self, sender, sel, ptr):
    if len(self.edtCodigo.getText()) > 0:
      if self.Rotinas.validaCPF(self.edtCodigo.getText())==False:
        self.edtCodigo.setText("")
        self.edtCodigo.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_CPFINV)
    return True
  
  def onEdtDtNasc_Killfocus(self, sender, sel, ptr):
    if len(self.edtDtNasc.getText()) > 0:
      if self.Rotinas.validaDataHora(self.edtDtNasc.getText(), True)==False:
        self.edtDtNasc.setText(self.Rotinas.retDataHoraStr(True,False))
        self.edtDtNasc.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_DTHRINV)
    else:
      self.edtDtNasc.setText(self.Rotinas.retDataHoraStr(True,False))
    return True
  
  def onEdtCodEndereco_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtCodEndereco.getText()) > 0:
      sLogradouro = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Endereco('S',
      self.edtCodEndereco.getText(),"","","","",""),Resource.STR_ENDNENC)
      if len(sLogradouro) > 0:
        self.edtLogradouro.setText(sLogradouro)
        self.edtBairro.setText(self.ConsCampo.col[0][2])
        self.edtCEP.setText(self.ConsCampo.col[0][3])
        self.edtCidade.setText(self.ConsCampo.col[0][4])
        self.edtEstado.setText(self.ConsCampo.col[0][5])
      else:	    
        self.edtCodEndereco.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_ENDNENC)
        self.edtLogradouro.setText("")
        self.edtBairro.setText("")
        self.edtCEP.setText("")
        self.edtCidade.setText("")
        self.edtEstado.setText("")      
    else:
      self.edtLogradouro.setText("")
      self.edtBairro.setText("")
      self.edtCEP.setText("")
      self.edtCidade.setText("")
      self.edtEstado.setText("")
    return True
  
  def onEdtCodPais_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtCodPais.getText()) > 0:
      sPais = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Pais('S',
        self.edtCodPais.getText(),""),Resource.STR_PAISNENC)    
      if len(sPais) > 0:
        self.edtPais.setText(sPais)
      else:      
        self.edtCodPais.killFocus()
        showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_PAISNENC)
        self.edtCodPais.setText("")
        self.edtPais.setText("")
    else:
      self.edtPais.setText("")
    return True
  
  def onEdtCodProfissao_Killfocus(self, sender, sel, ptr):
    self.ConsCampo = LISTAMSTR()
  
    if len(self.edtCodProfissao.getText()) > 0:
      sProfissao = self.Rotinas.ConsultaCampoDesc(self.ConsCampo, self.ConsSQL.Profissao('S',
        self.edtCodProfissao.getText(),""),Resource.STR_PROFNENC)    
      if len(sProfissao) > 0:
        self.edtProfissao.setText(sProfissao)
      else:
         self.edtCodProfissao.killFocus()
         showModalErrorBox(self, MBOX_OK, "Erro", Resource.STR_PROFNENC)
         self.edtCodProfissao.setText("")
         self.edtProfissao.setText("")
    else:
      self.edtProfissao.setText("")
    return True
  
  def onBtnPEndereco(self, sender, sel, ptr):
    fConEnderecos = ConEnderecos.frmConEnderecos(self)
    fConEnderecos.execute()
    self.edtCodEndereco.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCodEndereco_Killfocus(None,0,None)
    return True
  
  def onBtnPPais(self, sender, sel, ptr):
    fConPaises = ConPaises.frmConPaises(self)
    fConPaises.execute()
    self.edtCodPais.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCodPais_Killfocus(None,0,None)
    return True
  
  def onBtnPProfissao(self, sender, sel, ptr):
    fConProfissoes = ConProfissoes.frmConProfissoes(self)
    fConProfissoes.execute()
    self.edtCodProfissao.setText(self.Rotinas.sCodigoSelecionado)
    self.onEdtCodProfissao_Killfocus(None,0,None)
    return True
