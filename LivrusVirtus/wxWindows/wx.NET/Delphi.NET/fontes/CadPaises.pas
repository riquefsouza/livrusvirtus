unit CadPaises;

interface

uses
  System.Drawing, wx, Cadastros;

type
  TfrmCadPaises = class(TfrmCadastros)
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
  frmCadPaises: TfrmCadPaises;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadPaises))]

implementation

uses Login, TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL;

constructor TfrmCadPaises.Create(parent: wx.Window);
begin
  inherited Create(parent, FILTER_ALPHA, true, 'Código:', 'País:');

  //labDescricao.Label:='País: ';
  edtCodigo.MaxLength := 3;

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

function TfrmCadPaises.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_PAISNINF) then
    	result:=false;
  end;
end;

procedure TfrmCadPaises.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadPaises.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  e.Skip();
end;

procedure TfrmCadPaises.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Pais('S', edtCodigo.Value,''), 
    Res.STR_PAISNENC);
  e.Skip();
end;

procedure TfrmCadPaises.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  registroAnterior();	
  e.Skip();
end;

procedure TfrmCadPaises.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  registroProximo();		
  e.Skip();
end;

procedure TfrmCadPaises.OnBtnSalvar(sender: System.Object; e: wx.Event);
begin
  SalvarDados(ValidaDados(true),
    ConsSQL.Pais('S', edtCodigo.Value,''),
    ConsSQL.Pais('U', edtCodigo.Value, edtDescricao.Value),
    ConsSQL.Pais('I', edtCodigo.Value, edtDescricao.Value), true);
  e.Skip();
end;

procedure TfrmCadPaises.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  ExcluirDados(ValidaDados(false),
    ConsSQL.Pais('D', edtCodigo.Value,''));
  e.Skip();
end;

procedure TfrmCadPaises.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadPaises.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  e.Skip();
end;

end.
