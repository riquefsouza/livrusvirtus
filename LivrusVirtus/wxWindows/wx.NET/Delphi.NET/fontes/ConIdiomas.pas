unit ConIdiomas;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConIdiomas = class(TfrmConsultas)
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
  frmConIdiomas: TfrmConIdiomas;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConIdiomas))]

implementation

uses Resource, ConsultasSQL;

constructor TfrmConIdiomas.Create(parent: wx.Window);
begin
  inherited Create(parent, 'Idioma:');

  Title := Res.STR_CONIDIOMA;
  //labDescricao.Label := 'Idioma:';
  gridConsulta.SetColLabelValue(1, 'Idioma');

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConIdiomas.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_IDIOMAS);
	e.Skip();
end;

procedure TfrmConIdiomas.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConIdiomas.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConIdiomas.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Idioma('S','', edtDescricao.Value),
    Res.STR_IDINENC, 2);
  e.Skip();
end;

procedure TfrmConIdiomas.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConIdiomas.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
