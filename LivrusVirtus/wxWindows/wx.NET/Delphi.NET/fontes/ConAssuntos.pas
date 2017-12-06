unit ConAssuntos;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConAssuntos = class(TfrmConsultas)
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
  frmConAssuntos: TfrmConAssuntos;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConAssuntos))]

implementation

uses Resource, ConsultasSQL;

constructor TfrmConAssuntos.Create(parent: wx.Window);
begin
  inherited Create(parent, 'Assunto:');

  Title := Res.STR_CONASSUNTO;
  //labDescricao.Label := 'Assunto:';
  gridConsulta.SetColLabelValue(1, 'Assunto');

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConAssuntos.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_ASSUNTOS);
	e.Skip();
end;

procedure TfrmConAssuntos.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConAssuntos.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConAssuntos.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Assunto('S','', edtDescricao.Value),
    Res.STR_ASSNENC, 2);
  e.Skip();
end;

procedure TfrmConAssuntos.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConAssuntos.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
