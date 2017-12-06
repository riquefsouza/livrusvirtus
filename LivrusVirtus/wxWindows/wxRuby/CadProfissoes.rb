require 'wxruby'
require 'Cadastros'
require 'TextValidatorCtrl'
require 'ConsultasSQL'
require 'resource'
require 'RotinasGlobais'

class FrmCadProfissoes < FrmCadastros
  def initialize(parent)
    super(parent, TextValidatorCtrl::FILTER_NUMERIC, true) 
    @labDescricao.set_label('Profissão:')

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
        @edtDescricao.get_value(), Resource::STR_PROFNINF) then
    		return false
      end
    end
    return true
  end

  def OnBtnNovoClick(event)
    self.btnNovoClick()
    self.NovoDado($ConsSQL.Profissao('N', @edtCodigo.get_value(),""))
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    self.PesquisarDados($ConsSQL.Profissao('S', 
        @edtCodigo.get_value(),""), Resource::STR_PROFNENC)
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
      $ConsSQL.Profissao('S', @edtCodigo.get_value(),""),
      $ConsSQL.Profissao('U', @edtCodigo.get_value(), @edtDescricao.get_value()),
      $ConsSQL.Profissao('I', @edtCodigo.get_value(), 
      @edtDescricao.get_value()), true)
    event.skip()
  end

  def OnBtnExcluirClick(event)
    self.ExcluirDados(self.ValidaDados(false),
      $ConsSQL.Profissao('D', @edtCodigo.get_value(),""))
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

