unit CadAssuntos;

interface

uses
  System.Drawing, wx, Cadastros;

type
  TfrmCadAssuntos = class(TfrmCadastros)
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
  frmCadAssuntos: TfrmCadAssuntos;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadAssuntos))]

implementation

uses Login, TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL;

constructor TfrmCadAssuntos.Create(parent: wx.Window);
begin
  inherited Create(parent, FILTER_NUMERIC, true, 'Código:', 'Assunto:');

  //labDescricao.Label:='Assunto: ';

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

function TfrmCadAssuntos.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_ASSNINF) then
    	result:=false;
  end;
end;

procedure TfrmCadAssuntos.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  NovoDado(ConsSQL.Assunto('N', edtCodigo.Value,''));	
  e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Assunto('S', edtCodigo.Value,''), 
    Res.STR_ASSNENC);
  e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  registroAnterior();	
  e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  registroProximo();		
  e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnSalvar(sender: System.Object; e: wx.Event);
begin
  SalvarDados(ValidaDados(true),
    ConsSQL.Assunto('S', edtCodigo.Value,''),
    ConsSQL.Assunto('U', edtCodigo.Value, edtDescricao.Value),
    ConsSQL.Assunto('I', edtCodigo.Value, edtDescricao.Value), true);
  e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  ExcluirDados(ValidaDados(false),
    ConsSQL.Assunto('D', edtCodigo.Value,''));
  e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadAssuntos.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  e.Skip();
end;

end.
