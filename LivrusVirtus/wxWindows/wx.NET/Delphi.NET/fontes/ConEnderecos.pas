unit ConEnderecos;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConEnderecos = class(TfrmConsultas)
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
  frmConEnderecos: TfrmConEnderecos;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConEnderecos))]

implementation

uses Resource, ConsultasSQL, RotinasGlobais;

constructor TfrmConEnderecos.Create(parent: wx.Window);
const nLargura: array[0..3] of integer = ( 150,80,100,80 );
    sRotulos: array[0..3] of string = ( 'Bairro', 'CEP', 'Cidade', 'Estado' );
begin
  inherited Create(parent, 'Endereço:');

  Title := Res.STR_CONENDERECO;
  //labDescricao.Label := 'Endereço:';
  gridConsulta.SetColLabelValue(1, 'Endereço');
  gridConsulta.SetColLabelValue(1, 'Logradouro');
  gridConsulta.SetColSize(1, 200);
  
  Rotinas.AdicionaColunasGrid(gridConsulta, 2, 4, nLargura, sRotulos);

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConEnderecos.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_ENDERECOS);
	e.Skip();
end;

procedure TfrmConEnderecos.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConEnderecos.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConEnderecos.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Endereco('S','', edtDescricao.Value,'','','',''),
    Res.STR_ENDNENC, 6);
  e.Skip();
end;

procedure TfrmConEnderecos.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConEnderecos.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
