require 'wxruby'
require 'Cadastros'
require 'TextValidatorCtrl'
require 'ConsultasSQL'
require 'resource'
require 'RotinasGlobais'

class FrmCadAssuntos < FrmCadastros
  def initialize(parent)
    super(parent, TextValidatorCtrl::FILTER_NUMERIC, true) 
    @labDescricao.set_label('Assunto:')

    evt_button(ID_FRMCADASTROS_BTNNOVO) {|event| OnBtnNovoClick(event)}
    evt_button(ID_FRMCADASTROS_BTNPESQUISAR) {|event| OnBtnPesquisarClick(event)}
    evt_button(ID_FRMCADASTROS_BTNANTERIOR) {|event| OnBtnAnteriorClick(event)}
    evt_button(ID_FRMCADASTROS_BTNPROXIMO) {|event| OnBtnProximoClick(event)}
    evt_button(ID_FRMCADASTROS_BTNSALVAR) {|event| OnBtnSalvarClick(event)}
    evt_button(ID_FRMCADASTROS_BTNEXCLUIR) {|event| OnBtnExcluirClick(event)}
    evt_button(ID_FRMCADASTROS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMCADASTROS_BTNFECHAR) {|event| OnBtnFecharClick(event)}
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(
      @edtCodigo.get_value(), Resource::STR_CODNINF) then
      return false
    end
    if bTodosDados then
  	  if $Rotinas.ValidaCampo(
        @edtDescricao.get_value(), Resource::STR_ASSNINF) then
    		return false
      end
    end
    return true
  end

  def OnBtnNovoClick(event)
    self.btnNovoClick()
    self.NovoDado($ConsSQL.Assunto('N', @edtCodigo.get_value(),""))
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    self.PesquisarDados($ConsSQL.Assunto('S', 
        @edtCodigo.get_value(),""), Resource::STR_ASSNENC)
    event.skip()
  end

  def OnBtnAnteriorClick(event)
    self.registroAnterior()
    event.skip()
  end

  def OnBtnProximoClick(event)
    self.registroProximo()
    event.skip()
  end

  def OnBtnSalvarClick(event)
    self.SalvarDados(self.ValidaDados(true),
      $ConsSQL.Assunto('S', @edtCodigo.get_value(),""),
      $ConsSQL.Assunto('U', @edtCodigo.get_value(), @edtDescricao.get_value()),
      $ConsSQL.Assunto('I', @edtCodigo.get_value(), 
      @edtDescricao.get_value()), true)
    event.skip()
  end

  def OnBtnExcluirClick(event)
    self.ExcluirDados(self.ValidaDados(false),
      $ConsSQL.Assunto('D', @edtCodigo.get_value(),""))
    event.skip()
  end

  def OnBtnLimparClick(event)
    self.btnLimparClick()
    event.skip()
  end

  def OnBtnFecharClick(event)
    self.get_parent().close(true)
    event.skip()
  end
end

