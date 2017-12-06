unit CadIdiomas;

interface

uses
  System.Drawing, wx, Cadastros;

type
  TfrmCadIdiomas = class(TfrmCadastros)
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
  frmCadIdiomas: TfrmCadIdiomas;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadIdiomas))]

implementation

uses Login, TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL;

constructor TfrmCadIdiomas.Create(parent: wx.Window);
begin
  inherited Create(parent, FILTER_NUMERIC, true, 'Código:', 'Idioma:');

  //labDescricao.Label:='Idioma: ';

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

function TfrmCadIdiomas.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_IDININF) then
    	result:=false;
  end;
end;

procedure TfrmCadIdiomas.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  NovoDado(ConsSQL.Idioma('N', edtCodigo.Value,''));	
  e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Idioma('S', edtCodigo.Value,''), 
    Res.STR_IDINENC);
  e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  registroAnterior();	
  e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  registroProximo();		
  e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnSalvar(sender: System.Object; e: wx.Event);
begin
  SalvarDados(ValidaDados(true),
    ConsSQL.Idioma('S', edtCodigo.Value,''),
    ConsSQL.Idioma('U', edtCodigo.Value, edtDescricao.Value),
    ConsSQL.Idioma('I', edtCodigo.Value, edtDescricao.Value), true);
  e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  ExcluirDados(ValidaDados(false),
    ConsSQL.Idioma('D', edtCodigo.Value,''));
  e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadIdiomas.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  e.Skip();
end;

end.
