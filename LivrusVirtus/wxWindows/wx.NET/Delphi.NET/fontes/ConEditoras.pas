unit ConEditoras;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConEditoras = class(TfrmConsultas)
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
  frmConEditoras: TfrmConEditoras;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConEditoras))]

implementation

uses Resource, ConsultasSQL;

constructor TfrmConEditoras.Create(parent: wx.Window);
begin
  inherited Create(parent, 'Editora:');

  Title := Res.STR_CONEDITORA;
  //labDescricao.Label := 'Editora:';
  gridConsulta.SetColLabelValue(1, 'Editora');

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConEditoras.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_EDITORAS);
	e.Skip();
end;

procedure TfrmConEditoras.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConEditoras.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConEditoras.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Editora('S','', edtDescricao.Value),
    Res.STR_EDTNENC, 2);
  e.Skip();
end;

procedure TfrmConEditoras.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConEditoras.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
