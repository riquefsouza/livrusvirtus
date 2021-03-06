unit CadEditoras;

interface

uses
  System.Drawing, wx, Cadastros;

type
  TfrmCadEditoras = class(TfrmCadastros)
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
  frmCadEditoras: TfrmCadEditoras;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadEditoras))]

implementation

uses Login, TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL;

constructor TfrmCadEditoras.Create(parent: wx.Window);
begin
  inherited Create(parent, FILTER_NUMERIC, true, 'C�digo:', 'Editora:');

  //labDescricao.Label:='Editora: ';

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

function TfrmCadEditoras.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_EDTNINF) then
    	result:=false;
  end;
end;

procedure TfrmCadEditoras.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadEditoras.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  NovoDado(ConsSQL.Editora('N', edtCodigo.Value,''));	
  e.Skip();
end;

procedure TfrmCadEditoras.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Editora('S', edtCodigo.Value,''), 
    Res.STR_EDTNENC);
  e.Skip();
end;

procedure TfrmCadEditoras.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  registroAnterior();	
  e.Skip();
end;

procedure TfrmCadEditoras.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  registroProximo();		
  e.Skip();
end;

procedure TfrmCadEditoras.OnBtnSalvar(sender: System.Object; e: wx.Event);
begin
  SalvarDados(ValidaDados(true),
    ConsSQL.Editora('S', edtCodigo.Value,''),
    ConsSQL.Editora('U', edtCodigo.Value, edtDescricao.Value),
    ConsSQL.Editora('I', edtCodigo.Value, edtDescricao.Value), true);
  e.Skip();
end;

procedure TfrmCadEditoras.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  ExcluirDados(ValidaDados(false),
    ConsSQL.Editora('D', edtCodigo.Value,''));
  e.Skip();
end;

procedure TfrmCadEditoras.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadEditoras.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  e.Skip();
end;

end.
