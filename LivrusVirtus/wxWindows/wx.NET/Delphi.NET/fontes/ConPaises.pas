unit ConPaises;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConPaises = class(TfrmConsultas)
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
  frmConPaises: TfrmConPaises;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConPaises))]

implementation

uses Resource, ConsultasSQL;

constructor TfrmConPaises.Create(parent: wx.Window);
begin
  inherited Create(parent, 'País:');

  Title := Res.STR_CONPAIS;
  //labDescricao.Label := 'País:';
  gridConsulta.SetColLabelValue(1, 'País');

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConPaises.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_PAISES);
	e.Skip();
end;

procedure TfrmConPaises.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConPaises.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConPaises.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Pais('S','', edtDescricao.Value),
    Res.STR_PAISNENC, 2);
  e.Skip();
end;

procedure TfrmConPaises.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConPaises.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
