unit CadProfissoes;

interface

uses
  System.Drawing, wx, Cadastros;

type
  TfrmCadProfissoes = class(TfrmCadastros)
  private
    function ValidaDados(bTodosDados: boolean): boolean;
    procedure OnClose(sender: System.Object; e: wx.Event);
    procedure OnBtnNovo(sender: System.Object; e: wx.Event);
    procedure OnBtnPesquisar(sender: System.Object; e: wx.Event);
    procedure OnBtnAnterior(sender: System.Object; e: wx.Event);
    procedure OnBtnProximo(sender: System.Object; e: wx.Event);
    procedure OnBtnSalvar(sender: System.Object; e: wx.Event);
    procedure OnBtnExcluir(sender: System.Object; e: wx.Event);
    procedure OnBtnLimpar(sender: System.Object; e: wx.Event);
    procedure OnBtnFechar(sender: System.Object; e: wx.Event);
  public
    constructor Create(parent: wx.Window);
  end;

var
  frmCadProfissoes: TfrmCadProfissoes;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadProfissoes))]

implementation

uses Login, TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL;

constructor TfrmCadProfissoes.Create(parent: wx.Window);
begin
  inherited Create(parent, FILTER_NUMERIC, true, 'Código:', 'Profissão:');

  //labDescricao.Label:='Profissão: ';

  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, OnBtnNovo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, OnBtnAnterior );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, OnBtnProximo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, OnBtnSalvar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, OnBtnExcluir );
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, OnBtnFechar );
	EVT_CLOSE( OnClose );
end;

function TfrmCadProfissoes.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_PROFNINF) then
    	result:=false;
  end;
end;

procedure TfrmCadProfissoes.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  NovoDado(ConsSQL.Profissao('N', edtCodigo.Value,''));	
  e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Profissao('S', edtCodigo.Value,''), 
    Res.STR_PROFNENC);
  e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  registroAnterior();	
  e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  registroProximo();		
  e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnSalvar(sender: System.Object; e: wx.Event);
begin
  SalvarDados(ValidaDados(true),
    ConsSQL.Profissao('S', edtCodigo.Value,''),
    ConsSQL.Profissao('U', edtCodigo.Value, edtDescricao.Value),
    ConsSQL.Profissao('I', edtCodigo.Value, edtDescricao.Value), true);
  e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  ExcluirDados(ValidaDados(false),
    ConsSQL.Profissao('D', edtCodigo.Value,''));
  e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadProfissoes.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  e.Skip();
end;

end.
