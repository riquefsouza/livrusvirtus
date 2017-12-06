unit VenderLivros;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, Db, DBTables, ADODB;

type
  TfrmVenderLivros = class(TForm)
    Label1: TLabel;
    edtCPF: TEdit;
    Label9: TLabel;
    edtCliente: TEdit;
    Label2: TLabel;
    Label3: TLabel;
    edtISBN: TEdit;
    btnPLivro: TButton;
    btnPCliente: TButton;
    edtDtVenda: TEdit;
    lstLivros: TListBox;
    Label5: TLabel;
    edtPrecoTotal: TEdit;
    btnVender: TButton;
    btnLimpar: TButton;
    btnFechar: TButton;
    edtLivro: TEdit;
    Label6: TLabel;
    Label4: TLabel;
    btnAdLivros: TButton;
    Consulta: TADOQuery;
    Arquiva: TADOQuery;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btnFecharClick(Sender: TObject);
    procedure FormMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure FormShow(Sender: TObject);
    procedure edtISBNExit(Sender: TObject);
    procedure edtCPFExit(Sender: TObject);
    procedure btnPClienteClick(Sender: TObject);
    procedure btnPLivroClick(Sender: TObject);
    procedure btnAdLivrosClick(Sender: TObject);
    procedure lstLivrosDblClick(Sender: TObject);
    procedure btnLimparClick(Sender: TObject);
    procedure btnVenderClick(Sender: TObject);
  private
    { Private declarations }
    nPrecoTotal: Single;
    slLivros, slPrecos, slQtdEstoque: TStringList;
    procedure LimpaDados;
    function ValidaDados: boolean;
    function SalvaLista: boolean;
  public
    { Public declarations }
  end;

var
  frmVenderLivros: TfrmVenderLivros;

implementation

uses Principal, ConsultasSQL, ConClientes, ConLivros, RotinasGlobais;

{$R *.DFM}

procedure TfrmVenderLivros.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
slLivros.Free;
slPrecos.Free;
slQtdEstoque.Free;

frmPrincipal.ToolButton3.Enabled:=true;
frmPrincipal.VenderLivros1.Enabled:=true;
Action:=caFree;
end;

procedure TfrmVenderLivros.btnFecharClick(Sender: TObject);
begin
Close;
end;

procedure TfrmVenderLivros.FormMouseMove(Sender: TObject;
  Shift: TShiftState; X, Y: Integer);
begin
  frmPrincipal.StatusBar1.Panels.Items[1].Text:=Caption;
end;

procedure TfrmVenderLivros.FormShow(Sender: TObject);
begin
nPrecoTotal:=0;
edtDtVenda.Text:=formatdatetime('dd/mm/yyyy hh:nn:ss',now);
slLivros:=TStringList.Create;
slPrecos:=TStringList.Create;
slQtdEstoque:=TStringList.Create;
end;

procedure TfrmVenderLivros.LimpaDados;
begin
  edtDtVenda.Text:=formatdatetime('dd/mm/yyyy hh:nn:ss',now);
  edtCPF.Clear;
  edtCliente.Clear;
  edtISBN.Clear;
  edtLivro.Clear;
  lstLivros.Clear;
  slLivros.Clear;
  slPrecos.Clear;
  nPrecoTotal:=0;
  edtPrecoTotal.Text:='R$ 0,00';
  edtCPF.SetFocus;
end;

function TfrmVenderLivros.ValidaDados: boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCPF.Text,'CPF não informado!') then begin
  result:=false;
  exit;
end;
if lstLivros.Items.Count = 0 then begin
  MessageDlg('Livro(s) para vender não informado(s)!',mtInformation, [mbOk], 0);
  result:=false;
  exit;
end;
end;

function TfrmVenderLivros.SalvaLista: boolean;
var nCont, nQtdEstoque: integer;
begin
try
 result:=true;
 for nCont:=0 to slLivros.Count-1 do begin
    Arquiva.Sql.Text:=ConsSQL.Venda('I',slLivros.Strings[nCont],edtCPF.Text,
    formatdatetime('mm/dd/yyyy hh:nn:ss',StrToDateTime(edtDtVenda.Text)),
    Rotinas.VirgulaParaPonto(FormatFloat('0.00',nPrecoTotal)),'');
    Arquiva.ExecSql;

    nQtdEstoque:=StrToInt(slQtdEstoque.Strings[nCont]);
    nQtdEstoque:=nQtdEstoque-1;
    Arquiva.Sql.Text:=ConsSQL.Venda('U',slLivros.Strings[nCont],'','','',
    IntToStr(nQtdEstoque));
    Arquiva.ExecSql;
 end;
except
 on E: Exception do begin
  MessageDlg(E.Message, mtError, [mbOk], 0);
  result:=false;
 end;
end;
end;

procedure TfrmVenderLivros.edtISBNExit(Sender: TObject);
begin
 if edtISBN.Text<>'' then begin
   if Rotinas.ValidaISBN(edtISBN.Text) then begin
      if Rotinas.ConsultaDados(Consulta, ConsSQL.Livro('Q',edtISBN.Text,
         '','','','','','','','','')) then begin
         if Consulta.Fields[3].AsInteger > 0 then begin
            edtLivro.Text:=Consulta.Fields[1].AsString;
            Rotinas.sPreco:=Consulta.Fields[2].AsString;
         end else begin
            edtISBN.Clear;
            MessageDlg('O livro não existe no estoque!', mtError, [mbOk], 0);
         end;
      end else
        MessageDlg('Livro não encontrado!', mtError, [mbOk], 0);
   end else begin
      edtISBN.Clear;
      MessageDlg('ISBN inválido!', mtError, [mbOk], 0);
   end;
 end;
end;

procedure TfrmVenderLivros.edtCPFExit(Sender: TObject);
begin
 if edtCPF.Text<>'' then begin
   if Rotinas.ValidaCPF(edtCPF.Text) then begin
      if Rotinas.ConsultaDados(Consulta, ConsSQL.Cliente('S',edtCPF.Text,
         '','','','','','','','','')) then
         edtCliente.Text:=Consulta.Fields[1].AsString
      else
        MessageDlg('Cliente não encontrado!', mtError, [mbOk], 0);
   end else begin
     edtCPF.Clear;
     MessageDlg('CPF inválido!', mtError, [mbOk], 0);
   end;
 end;
end;

procedure TfrmVenderLivros.btnPClienteClick(Sender: TObject);
begin
  Application.CreateForm(TfrmConClientes, frmConClientes);
  frmConClientes.ShowModal;
  edtCPF.Text:=Rotinas.sCodigoSelecionado;
  edtCPFExit(self);
end;

procedure TfrmVenderLivros.btnPLivroClick(Sender: TObject);
begin
  Application.CreateForm(TfrmConLivros, frmConLivros);
  frmConLivros.ShowModal;
  edtISBN.Text:=Rotinas.sCodigoSelecionado;
  edtISBNExit(self);
end;

procedure TfrmVenderLivros.btnAdLivrosClick(Sender: TObject);
var sLivros: string;
begin
if edtISBN.Text<>'' then begin
 sLivros:=edtISBN.Text+' - '+edtLivro.Text+' - R$ '+Rotinas.sPreco;
 if lstLivros.Items.IndexOf(sLivros)=-1 then
  begin
    slLivros.Append(edtISBN.Text);
    slPrecos.Append(Rotinas.sPreco);
    slQtdEstoque.Append(Rotinas.sQtdEstoque);
    lstLivros.Items.Append(sLivros);
    nPrecoTotal:=nPrecoTotal+StrToFloat(Rotinas.sPreco);
  end;
 edtISBN.Clear;
 edtLivro.Clear;
 edtPrecoTotal.Text:=FormatFloat('R$ 0.00',nPrecoTotal);
end;
end;

procedure TfrmVenderLivros.lstLivrosDblClick(Sender: TObject);
var nPreco: single;
begin
 if lstLivros.Items.Count > 0 then begin
   nPreco:=StrToFloat(slPrecos.Strings[lstLivros.ItemIndex]);
   nPrecoTotal:=nPrecoTotal-nPreco;
   edtPrecoTotal.Text:='R$ '+FloatToStr(nPrecoTotal);
   slLivros.Delete(lstLivros.ItemIndex);
   slPrecos.Delete(lstLivros.ItemIndex);  
   slQtdEstoque.Delete(lstLivros.ItemIndex);
   lstLivros.Items.Delete(lstLivros.ItemIndex);   
 end;
end;

procedure TfrmVenderLivros.btnLimparClick(Sender: TObject);
begin
LimpaDados;
end;

procedure TfrmVenderLivros.btnVenderClick(Sender: TObject);
begin
 if ValidaDados then begin
    if SalvaLista then begin
       MessageDlg('Venda realizada com sucesso!', mtInformation, [mbOk], 0);
       LimpaDados;
    end;
 end;
end;

end.
