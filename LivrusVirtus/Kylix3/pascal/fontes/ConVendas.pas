unit ConVendas;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms,
  QDialogs, QStdCtrls, Consultas, FMTBcd, Provider, DBClient, DB, SqlExpr,
  QGrids, QDBGrids, QExtCtrls, QMask;

type
  TfrmConVendas = class(TfrmConsultas)
    Label5: TLabel;
    edtPrecoTotal: TEdit;
    Label9: TLabel;
    edtDtVenda: TMaskEdit;
    edtHrVenda: TMaskEdit;
    Label1: TLabel;
    edtCliente: TEdit;
    btnPCliente: TButton;
    Label3: TLabel;
    edtISBN: TEdit;
    Label6: TLabel;
    edtLivro: TEdit;
    btnPLivro: TButton;
    ConsTotal: TSQLQuery;
    ConsCampo: TSQLQuery;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btnLimparClick(Sender: TObject);
    procedure btnPesquisarClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure edtDescricaoExit(Sender: TObject);
    procedure edtISBNExit(Sender: TObject);
    procedure btnPClienteClick(Sender: TObject);
    procedure btnPLivroClick(Sender: TObject);
    procedure edtDtVendaExit(Sender: TObject);
    procedure edtHrVendaExit(Sender: TObject);
  private
    { Private declarations }
    function ConsVenda(sOpcao:char): string;
  public
    { Public declarations }
  end;

var
  frmConVendas: TfrmConVendas;

implementation

uses Principal, ConsultasSQL, RotinasGlobais, ConClientes, ConLivros;

{$R *.xfm}

procedure TfrmConVendas.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.VendasRealizadas1.Enabled:=true;
inherited;
end;

procedure TfrmConVendas.btnLimparClick(Sender: TObject);
begin
  inherited;
  edtDtVenda.Clear;
  edtHrVenda.Clear;
  edtCliente.Clear;
  edtISBN.Clear;
  edtLivro.Clear;
  edtPrecoTotal.Text:='R$ 0,00';
  edtDtVenda.SetFocus;

  LimparDados(ConsVenda('L'));

end;

function TfrmConVendas.ConsVenda(sOpcao:char): string;
var sDataVenda, sHoraVenda, sDtHrVenda: string;
begin
if edtDtVenda.Text<>'  /  /    ' then
  sDataVenda:=FormatDateTime('MM/dd/yyyy',StrToDateTime(edtDtVenda.Text))
else
  sDataVenda:='';
if edtHrVenda.Text<>'  :  :  ' then
   sHoraVenda:=edtHrVenda.Text
else
   sHoraVenda:='';
sDtHrVenda:=trim(sDataVenda+' '+sHoraVenda);
if sOpcao='L' then
 result:=ConsSQL.Venda('S','ZERO','','','','')
else
 result:=ConsSQL.Venda(sOpcao,edtISBN.Text,edtDescricao.Text,sDtHrVenda,'','');
end;

procedure TfrmConVendas.btnPesquisarClick(Sender: TObject);
begin
  inherited;
if PesquisarDados(ConsVenda('S'),'Venda não encontrada!') then begin
   Rotinas.ConsultaDados(ConsTotal,ConsVenda('P'));
   edtPrecoTotal.Text:=FormatFloat('R$ 0.00',ConsTotal.Fields[0].AsFloat);
end;
end;

procedure TfrmConVendas.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;

procedure TfrmConVendas.edtDescricaoExit(Sender: TObject);
begin
  inherited;
 if edtDescricao.Text<>'' then begin
   if Rotinas.ValidaCPF(edtDescricao.Text) then begin
      if Rotinas.ConsultaDados(ConsCampo,ConsSQL.Cliente('S',edtDescricao.Text,
         '','','','','','','','','')) then
         edtCliente.Text:=ConsCampo.Fields[1].AsString
      else
        MessageDlg('Cliente não encontrado!', mtError, [mbOk], 0);
   end else begin
     edtDescricao.Clear;
     MessageDlg('CPF inválido!', mtError, [mbOk], 0);
   end;
 end;
end;

procedure TfrmConVendas.edtISBNExit(Sender: TObject);
begin
  inherited;
 if edtISBN.Text<>'' then begin
   if Rotinas.ValidaISBN(edtISBN.Text) then begin
      if Rotinas.ConsultaDados(ConsCampo,ConsSQL.Livro('Q',edtISBN.Text,
         '','','','','','','','','')) then begin
         if ConsCampo.Fields[3].AsInteger > 0 then begin
            edtLivro.Text:=ConsCampo.Fields[1].AsString;
            Rotinas.sPreco:=ConsCampo.Fields[2].AsString;
         end else
            MessageDlg('Livro não existe no estoque!', mtError, [mbOk], 0);
      end else
        MessageDlg('Livro não encontrado!', mtError, [mbOk], 0);
   end else begin
      edtISBN.Clear;
      MessageDlg('ISBN inválido!', mtError, [mbOk], 0);
   end;
 end;
end;

procedure TfrmConVendas.btnPClienteClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConClientes, frmConClientes);
  frmConClientes.ShowModal;
  edtDescricao.Text:=Rotinas.sCodigoSelecionado;
  edtDescricaoExit(self);
end;

procedure TfrmConVendas.btnPLivroClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConLivros, frmConLivros);
  frmConLivros.ShowModal;
  edtISBN.Text:=Rotinas.sCodigoSelecionado;
  edtISBNExit(self);
end;

procedure TfrmConVendas.edtDtVendaExit(Sender: TObject);
begin
  inherited;
if edtDtVenda.Text<>'  /  /    ' then begin
  if Rotinas.ValidaDateTime(edtDtVenda.Text)=false then begin
    edtDtVenda.Clear;
    edtDtVenda.SetFocus;
  end;
end;
end;

procedure TfrmConVendas.edtHrVendaExit(Sender: TObject);
begin
  inherited;
if edtHrVenda.Text<>'  :  :  ' then begin
    if Rotinas.ValidaDateTime(edtHrVenda.Text)=false then begin
    edtHrVenda.Clear;
    edtHrVenda.SetFocus;
  end;
end;
end;

end.
