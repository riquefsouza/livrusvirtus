unit ConProfissoes;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConProfissoes = class(TfrmConsultas)
  private
    procedure OnClose(sender: System.Object; e: wx.Event);
    procedure OnBtnFechar(sender: System.Object; e: wx.Event);
    procedure OnBtnLimpar(sender: System.Object; e: wx.Event);
    procedure OnBtnPesquisar(sender: System.Object; e: wx.Event);
    procedure OnGridSelectCell(sender: System.Object; e: wx.Event);
    procedure OnGridLabelLeftClick(sender: System.Object; e: wx.Event);
  public
    constructor Create(parent: wx.Window);
  end;

var
  frmConProfissoes: TfrmConProfissoes;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConProfissoes))]

implementation

uses Resource, ConsultasSQL;

constructor TfrmConProfissoes.Create(parent: wx.Window);
begin
  inherited Create(parent, 'Profissão:');

  Title := Res.STR_CONPROFISS;
  //labDescricao.Label := 'Profissão:';
  gridConsulta.SetColLabelValue(1, 'Profissão');

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConProfissoes.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_PROFISSOES);
	e.Skip();
end;

procedure TfrmConProfissoes.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConProfissoes.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConProfissoes.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Profissao('S','', edtDescricao.Value),
    Res.STR_PROFNENC, 2);
  e.Skip();
end;

procedure TfrmConProfissoes.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConProfissoes.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
