require 'fox'
require 'fox/responder'
require 'RotinasGlobais'
require 'resource'
require 'Principal'
include Fox
include Responder

class FRMCadastros < FXMDIChild

  ID_FRMCADASTROS_BTNNOVO, ID_FRMCADASTROS_BTNANTERIOR, 
  ID_FRMCADASTROS_BTNEXCLUIR, ID_FRMCADASTROS_BTNFECHAR, 
  ID_FRMCADASTROS_BTNLIMPAR, ID_FRMCADASTROS_BTNPESQUISAR, 
  ID_FRMCADASTROS_BTNPROXIMO, ID_FRMCADASTROS_BTNSALVAR, 
  ID_FRMCADASTROS_EDTCODIGO = enum(FXMDIChild::ID_LAST, 9)
  
  def initialize(clienteMDI, sTitulo, iconeMDI, menuMDI, nFiltroCodigo, 
    bIniciaBotoes)  
    super(clienteMDI, sTitulo, iconeMDI, menuMDI, MDI_NORMAL, 0, 0, 345, 180)

    @frame = FXVerticalFrame.new(self, LAYOUT_FILL_X | LAYOUT_FILL_Y)
  
    frame1 = FXVerticalFrame.new(@frame, LAYOUT_FILL_X)
    @frame2 = FXHorizontalFrame.new(frame1, LAYOUT_TOP)
    
    @frame3 = FXVerticalFrame.new(@frame2, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame4 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    @frame5 = FXVerticalFrame.new(frame4, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame6 = FXVerticalFrame.new(frame4, LAYOUT_LEFT|LAYOUT_BOTTOM, 0,0,0,0,0,0,0,0)
  
    @frame7 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame8 = FXVerticalFrame.new(@frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    @labCodigo = FXLabel.new(@frame5, "Código:", nil, LAYOUT_LEFT, 
      8, 8, 36, 13)
    @edtCodigo = FXTextField.new(@frame5, 10, nil, ID_FRMCADASTROS_EDTCODIGO, 
      TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      nFiltroCodigo, 8, 24, 121, 21, 3, 20)
    @btnNovo = FXButton.new(frame6, "&Novo", nil, self, 
      ID_FRMCADASTROS_BTNNOVO, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_BOTTOM, 144, 24, 75, 25, 15, 15, 3, 3 )
    @labDescricao = FXLabel.new(frame8, "Descrição:", nil, LAYOUT_LEFT, 
      8, 48, 51, 13)
    @edtDescricao = FXTextField.new(frame8, 30, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 64, 217, 21, 3, 20)
    @edtDescricao.disable()
  
    if bIniciaBotoes
      IniciaBotoes()
    end

    @lstRegistros = LISTAMSTR.new
    @nLinhaRegistro = 0
  end

  # Necessário por causa da tabulação dos campos
  def IniciaBotoes()
    frameBotoesV = FXVerticalFrame.new(@frame2,
      LAYOUT_TOP|LAYOUT_RIGHT, 0,0,0,0,18,0,0,0)
    @btnPesquisar = FXButton.new(frameBotoesV, "&Pesquisar", nil, self, 
      ID_FRMCADASTROS_BTNPESQUISAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 8, 75, 25, 10, 10, 3, 3 )
    @btnAnterior = FXButton.new(frameBotoesV, "&Anterior", nil, self, 
      ID_FRMCADASTROS_BTNANTERIOR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 40, 75, 25, 15, 15, 3, 3 )
    @btnProximo = FXButton.new(frameBotoesV, "Próxi&mo", nil, self, 
      ID_FRMCADASTROS_BTNPROXIMO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 72, 75, 25, 15, 15, 3, 3 )
  
    frameBotoesH = FXHorizontalFrame.new(@frame, 
      LAYOUT_BOTTOM|LAYOUT_RIGHT)
    @btnSalvar = FXButton.new(frameBotoesH, "&Salvar", nil, self, 
      ID_FRMCADASTROS_BTNSALVAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT,8, 104, 75, 25, 15, 15, 3, 3 )
    @btnExcluir = FXButton.new(frameBotoesH, "&Excluir", nil, self, 
      ID_FRMCADASTROS_BTNEXCLUIR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 88, 104, 75, 25, 15, 15, 3, 3 )
    @btnLimpar = FXButton.new(frameBotoesH, "&Limpar", nil, self, 
      ID_FRMCADASTROS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT,168, 104, 75, 25, 15, 15, 3, 3 )
    @btnFechar = FXButton.new(frameBotoesH, "&Fechar", nil, self, 
      ID_FRMCADASTROS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 248, 104, 75, 25, 15, 15, 3, 3 )
  
    btnLimparClick()
  end

  def InformaLimpaDados(bInformar)
    if bInformar
      @edtCodigo.setText(@lstRegistros.col[@nLinhaRegistro][0])
      @edtDescricao.setText(@lstRegistros.col[@nLinhaRegistro][1])
    else
      @edtCodigo.setText("")
      @edtDescricao.setText("")
      @edtCodigo.enable()
      @edtCodigo.setFocus()
    end
  end 
  
  def HabilitaDados(bHabilita)
    if bHabilita
      @edtDescricao.enable()
    else
      @edtDescricao.disable()
    end
  end
  
  def btnNovoClick()
    @btnSalvar.enable()
    @btnExcluir.disable()
    @btnPesquisar.disable()
    @btnAnterior.disable()
    @btnProximo.disable()
    @btnNovo.disable()
    
    @nLinhaRegistro = 0
    InformaLimpaDados(false)
    HabilitaDados(true)	
  end
  
  def NovoDado(sTextoSql)
    lstRegs = LISTAMSTR.new
  
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, lstRegs, sTextoSql)
      @edtCodigo.setText(lstRegs.col[0][0])
  
      @edtCodigo.disable()
      @edtDescricao.setFocus()
    end
  end
  
  def btnLimparClick() 
    @nLinhaRegistro = 0
    @btnSalvar.disable()
    @btnExcluir.disable()
    @btnPesquisar.enable()
    @btnAnterior.disable()
    @btnProximo.disable()
    @btnNovo.enable()
  
    @nLinhaRegistro = 0
    InformaLimpaDados(false)
    HabilitaDados(false)	
  end
  
  def ExcluirDados(bValidaDados, sTextoSql)
     if bValidaDados
       if FXMessageBox.question(self, MBOX_YES_NO, "Confirme",
          Resource::STR_CERTEXCL) == MBOX_CLICKED_YES 
          if $Rotinas.AtualizaDados($Rotinas.gConexao, sTextoSql)
             btnLimparClick()
             return true
          end
    	 end
     end
    return false
  end
  
  def PesquisarDados(sTextoSql, sMensagemErro)
  	if @edtCodigo.getText().length() == 0
      @btnAnterior.enable()
      @btnProximo.enable()
  	end
  
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, @lstRegistros, sTextoSql)
       InformaLimpaDados(true)
       HabilitaDados(true)	
  
       @btnSalvar.enable()
       @btnExcluir.enable()
       @btnPesquisar.disable()
       return true
  	else
      FXMessageBox.error(self, MBOX_OK, "Erro", sMensagemErro)
    end  
    return false
  end
  
  def registroAnterior()
  	if @nLinhaRegistro > 0
      @nLinhaRegistro = @nLinhaRegistro - 1
      InformaLimpaDados(true)
      return true
  	else
      return false
    end
  end
  
  def registroProximo()
  	if @nLinhaRegistro < @lstRegistros.tam-1
      @nLinhaRegistro = @nLinhaRegistro + 1
      InformaLimpaDados(true)
      return true
  	else
      return false
    end
  end
  
  def SalvarDados(bValidaDados, sTextoSql, 
    sTextoUpdate, sTextoInsert, bLimparDados)
    sArquiva = ''
  
  	if bValidaDados
  	   if $Rotinas.ConsultaDados($Rotinas.gConexao,sTextoSql)
           sArquiva = sTextoUpdate
       else
    	     sArquiva = sTextoInsert	  	     
       end
       if $Rotinas.AtualizaDados($Rotinas.gConexao, sArquiva)
    	   if bLimparDados
           btnLimparClick()
         end
         return true
       end
  	end
    return false
  end  
 
end
