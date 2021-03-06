unit ConLivros;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConLivros = class(TfrmConsultas)
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
  frmConLivros: TfrmConLivros;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConLivros))]

implementation

uses Resource, ConsultasSQL, RotinasGlobais;

constructor TfrmConLivros.Create(parent: wx.Window);
const nLargura: array[0..9] of integer = ( 80,90,80,80,100,80,100,80,80,80 );
    sRotulos: array[0..9] of string = ( 'Edi��o', 'AnoPublica��o',
    'Volume', 'CodEditora', 'Editora', 'CodIdioma', 'Idioma',
    'NumP�ginas', 'Pre�o', 'Estoque' );
begin
  inherited Create(parent, 'Livro:');

  Title := Res.STR_CONLIVRO;
  //labDescricao.Label := 'Livro:';
  gridConsulta.SetColLabelValue(0, 'ISBN');
  gridConsulta.SetColSize(0, 80);
  gridConsulta.SetColLabelValue(1, 'T�tulo');
  gridConsulta.SetColSize(1, 180);

  Rotinas.AdicionaColunasGrid(gridConsulta, 2, 10, nLargura, sRotulos);

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConLivros.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_LIVROS);
	e.Skip();
end;

procedure TfrmConLivros.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConLivros.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConLivros.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Livro('S','', edtDescricao.Value,
    '','','','','','','',''), Res.STR_LIVNENC, 12);
  e.Skip();
end;

procedure TfrmConLivros.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConLivros.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
