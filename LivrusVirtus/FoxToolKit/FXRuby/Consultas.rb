require 'fox'
require 'fox/responder'
require 'RotinasGlobais'
require 'resource'
require 'Principal'
include Fox
include Responder

class FRMConsultas < FXDialogBox

  ID_FRMCONSULTAS_BTNFECHAR, ID_FRMCONSULTAS_BTNLIMPAR, 
  ID_FRMCONSULTAS_BTNPESQUISAR, ID_FRMCONSULTAS_GRIDCONSULTA = 
    enum(FXDialogBox::ID_LAST, 4)
  
  def initialize(owner, sTitulo)  
    super(owner, sTitulo, DECOR_ALL, 0, 0, 385, 263, 0, 0, 0, 0, 4, 4)
    setIcon($Rotinas.lerFigura(getApp(), "Livrus.bmp"))

    frame = FXVerticalFrame.new(self, LAYOUT_FILL_X | LAYOUT_FILL_Y)
    frame1 = FXVerticalFrame.new(frame, LAYOUT_FILL_X)
    frame2 = FXHorizontalFrame.new(frame1, LAYOUT_TOP)
    
    frame3 = FXVerticalFrame.new(frame2, LAYOUT_LEFT)
    frame3.setPadTop(0)
    frame3.setPadBottom(0)
  
    frame4 = FXVerticalFrame.new(frame2, LAYOUT_LEFT|LAYOUT_BOTTOM)
    frame4.setPadTop(0)
    frame4.setPadBottom(0)
  
    frameBotoesH = FXHorizontalFrame.new(frame, LAYOUT_BOTTOM|LAYOUT_FILL_X)
  
    @labDescricao = FXLabel.new(frame3, "Descrição:", nil, LAYOUT_LEFT, 
      8, 8, 51, 13)
    @edtDescricao = FXTextField.new(frame3, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 24, 257, 21, 3, 20)
    btnPesquisar = FXButton.new(frame4, "&Pesquisar", nil, self, 
      ID_FRMCONSULTAS_BTNPESQUISAR, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      272, 24, 75, 25, 15, 15, 3, 3 )

    @gridConsulta = FXTable.new(frame, 2, 3, self, 
      ID_FRMCONSULTAS_GRIDCONSULTA, TABLE_COL_SIZABLE|TABLE_ROW_SIZABLE|
      LAYOUT_FILL_X|LAYOUT_FILL_Y, 0, 56, 355, 125)
    $Rotinas.IniciaLayoutGrid(@gridConsulta, 2, 3)
  
    @labRegistro = FXLabel.new(frameBotoesH, "Registro 0 de 0", nil, 
      LAYOUT_LEFT, 8, 16, 144, 13)
    btnFechar = FXButton.new(frameBotoesH, "&Fechar", nil, self, 
      FXDialogBox::ID_CANCEL, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 75, 13, 75, 25, 15, 15, 3, 3 )
    btnLimpar = FXButton.new(frameBotoesH, "&Limpar", nil, self, 
      ID_FRMCONSULTAS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 16, 13, 75, 25, 15, 15, 3, 3 )
  
    @edtDescricao.setFocus()
    @lstLinhas = LISTAMSTR.new
    @sSelecionado = ""
    @nRegistro = 0
    $Rotinas.sCodigoSelecionado = ""
  end

  def create()
    super
    show(PLACEMENT_SCREEN)
  end
  
  def LimparDados() 
    $Rotinas.sCodigoSelecionado = ""
    @labRegistro.setText("Registro 0 de 0")
    if @gridConsulta.getNumRows() > 1
      @gridConsulta.removeRows(1, @gridConsulta.getNumRows()-2)
      @gridConsulta.setItemText(1, 0, "1")
      for nCol in (1..(@gridConsulta.getNumCols()-1)) do
        @gridConsulta.setItemText(1, nCol, "")
      end
    end
    @edtDescricao.setText("")
    @edtDescricao.setFocus()
  end
  
  def PesquisarDados(sTextoSql, sMensagemErro, nQtdCol)  
    $Rotinas.sCodigoSelecionado = ""
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, @lstLinhas, sTextoSql)
      $Rotinas.AdicionaLinhasGrid(@gridConsulta, @lstLinhas, nQtdCol)
      setLabRegistros(1)
    else
      FXMessageBox.error(self, MBOX_OK, "Erro", sMensagemErro)
    end
  end
  
  def setLabRegistros(nLinha)
    if nLinha >= 1
      @labRegistro.setText("Registro " + nLinha.to_s + " de " +
        (@gridConsulta.getNumRows()-1).to_s)
      $Rotinas.sCodigoSelecionado = @gridConsulta.getItemText(nLinha, 1)
    end
  end
 
end
