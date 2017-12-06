unit ConClientes;

interface

uses
  System.Drawing, wx, Consultas;

type
  TfrmConClientes = class(TfrmConsultas)
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
  frmConClientes: TfrmConClientes;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConClientes))]

implementation

uses Resource, ConsultasSQL, RotinasGlobais;

constructor TfrmConClientes.Create(parent: wx.Window);
const nLargura: array[0..14] of integer = ( 180,80,40,80,120,80,220,150,
    80,100,100,80,180,80,100 );
    sRotulos: array[0..14] of string = ( 'Email', 'Identidade', 'Sexo',
   'Telefone', 'DtNascimento', 'CodEndereço', 'Logradouro',
   'Bairro', 'CEP', 'Cidade', 'Estado', 'CodPaís', 'País',
   'CodProfissão', 'Profissão' );
begin
  inherited Create(parent, 'Cliente:');

  Title := Res.STR_CONCLIENTE;
  //labDescricao.Label := 'Cliente:';
  gridConsulta.SetColLabelValue(0, 'CPF');
  gridConsulta.SetColSize(0, 90);
  gridConsulta.SetColLabelValue(1, 'Nome');
  gridConsulta.SetColSize(1, 220);

  Rotinas.AdicionaColunasGrid(gridConsulta, 2, 15, nLargura, sRotulos);

  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConClientes.OnClose(sender: System.Object; e: wx.Event);
begin
  Fecha(Res.MNU_CON_CLIENTES);
	e.Skip();
end;

procedure TfrmConClientes.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  Fecha(0);
  e.Skip();
end;

procedure TfrmConClientes.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  LimparDados();
  e.Skip();
end;

procedure TfrmConClientes.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  PesquisarDados(ConsSQL.Cliente('S','', edtDescricao.Value,
    '','','','','','','',''),Res.STR_CLINENC, 17);
  e.Skip();
end;

procedure TfrmConClientes.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConClientes.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

end.
