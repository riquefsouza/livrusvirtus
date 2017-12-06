unit ConAutores;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConAutores = class(TfrmConsultas)
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
  frmConAutores: TfrmConAutores;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConAutores))]

implementation

uses Resource, ConsultasSQL;

constructor TfrmConAutores.Create(parent: wx.Window);
begin
  inherited Create(parent, 'Autor:');

  Title := Res.STR_CONAUTOR;
  //labDescricao.Label := 'Autor:';
  gridConsulta.SetColLabelValue(1, 'Autor');

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConAutores.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_AUTORES);
	e.Skip();
end;

procedure TfrmConAutores.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConAutores.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConAutores.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Autor('S','', edtDescricao.Value),
    Res.STR_AUTNENC, 2);
  e.Skip();
end;

procedure TfrmConAutores.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConAutores.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
