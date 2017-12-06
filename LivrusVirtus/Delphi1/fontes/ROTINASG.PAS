unit RotinasG;

interface

uses
  SysUtils, WinTypes, WinProcs, Messages, Classes, Graphics, Controls,
  Forms, Dialogs, DB, Menus, DBTables, Grids, DBGrids, StdCtrls;

type
  TRotinasGlobais = class(TObject)
  public
    { Public declarations }
    sUsuarioLogin, sUsuarioSenha: string;
    sCodigoSelecionado, sPreco, sQtdEstoque: string;
    function ConsultaDados(var Consulta: TQuery; sTextoSql: string): boolean;
    function ValidaCampo(sCampo, sMensagemErro: string): boolean;
    function ValidaInteger(sNum: string): boolean;
    function ValidaFloat(sNum: string): boolean;
    function VirgulaParaPonto(sNum: string): string;
    function modulo11(svalor: string; ndig: integer): integer;
    function ValidaCPF(cpf: string): boolean;
    function ValidaISBN(isbn: string): boolean;
    function ConsultaCampoDesc(var Consulta: TQuery; sCampoCodigo, sTextoSql,
                               sMensagemErro: string): string;
    function ConsultaCampoDesc2(var Consulta: TQuery; sTextoSql,
                               sMensagemErro: string): string;
    procedure AdicionaItemLista(var lstLista: TListBox;
              var slCodLista: TStringList; var sCampoCodigo: TEdit;
              var sCampoDesc: TEdit);
    procedure RemoveItemLista(var lstLista: TListBox;
			      var slCodLista: TStringList);
    procedure AdicionaValoresLista(var ConsLista: TQuery; sTextoSql: string;
              var lstLista: TListBox; var slCodLista: TStringList);
    procedure ChamarTela(var Tela: TForm);
  end;

var
  Rotinas: TRotinasGlobais;

implementation

function TRotinasGlobais.ConsultaDados(var Consulta: TQuery;
                       sTextoSql: string): boolean;
begin
  Consulta.Close;
  Consulta.Sql.Add(sTextoSql);
  Consulta.Open;
  result:=(Consulta.RecordCount > 0);
end;

function TRotinasGlobais.ValidaCampo(sCampo, sMensagemErro: string): boolean;
begin
result:=false;
  if sCampo='' then begin
    MessageDlg(sMensagemErro, mtInformation, [mbOk], 0);
    result:=true;
  end;
end;

function TRotinasGlobais.ValidaInteger(sNum: string): boolean;
begin
 if sNum<>'' then begin
    try
      StrToInt(sNum);
      result:=true;
    except
      MessageDlg('Número inválido!', mtError, [mbOk], 0);
      result:=false;
    end;
 end else
   result:=false;
end;

function TRotinasGlobais.ValidaFloat(sNum: string): boolean;
begin
 if sNum<>'' then begin
    try
      StrToFloat(sNum);
      result:=true;
    except
      MessageDlg('Número inválido!', mtError, [mbOk], 0);
      result:=false;
    end;
 end else
   result:=false;
end;

function TRotinasGlobais.VirgulaParaPonto(sNum: string): string;
var sPedaco, sTodo: string;
    nCont: integer;
begin
 sTodo:='';
 for ncont:=1 to length(sNum) do begin
     sPedaco:=copy(sNum, ncont, 1);
     if sPedaco=',' then 
        sTodo:=sTodo + '.'
     else
        sTodo:=sTodo + sPedaco;
 end;
 result:=sTodo;
end;

function TRotinasGlobais.modulo11(svalor: string; ndig: integer): integer;
var ncont, nsoma, nvalor, npos: integer;
    sres, slocal: string;
begin
 ncont:=1;
 while ncont <= 11 do begin
   slocal:=copy(svalor,ncont,1) + slocal;
   ncont:=ncont+1;
 end;
 nsoma:=0;
 if ndig=1 then
   ncont:=3
 else
   ncont:=2;
 npos:=2;
 while ncont <= 11 do begin
   sres:=copy(slocal,ncont,1);
   nvalor:=strtoint(sres);
   nsoma:=nsoma + (nvalor * npos);
   ncont:=ncont+1;
   npos:=npos+1;
 end;
 nsoma:=(11 - (nsoma mod 11));

if nsoma > 9 then
  modulo11:=0
else
  modulo11:=nsoma;
end;

function TRotinasGlobais.ValidaCPF(cpf: string): boolean;
var scpf: string;
begin
if (length(cpf)=14) then begin
  scpf:=copy(cpf,1,3)+copy(cpf,5,3)+copy(cpf,9,3)+copy(cpf,13,2);
  if ( (modulo11(scpf,1)=strtoint(copy(cpf,13,1))) and
  (modulo11(scpf,2)=strtoint(copy(cpf,14,1))) ) then
    result:=true
  else
    result:=false;
end else
  result:=false;
end;

function TRotinasGlobais.ValidaISBN(isbn: string): boolean;
var snum, sdigito, sisbn: string;
 nvalor, nsoma, ncont: integer;
begin
if (length(isbn)=13) then begin
  sdigito := copy(isbn, length(isbn), 1);
  sisbn:='';
  for ncont:=1 to length(isbn)-1 do begin
    if (copy(isbn,ncont,1)<>'-') then
      sisbn:=sisbn+copy(isbn,ncont,1);
  end;
  if sdigito = 'X' then
    nsoma := 10
  else begin
    nvalor:=strtoint(sdigito);
    nsoma := nvalor;
  end;
  for ncont:=1 to 9 do begin
    snum:=copy(sisbn, ncont, 1);
    nvalor:=strtoint(snum);
    nsoma:=nsoma + (nvalor * (11 - ncont));
  end;
  If (nsoma mod 11) = 0 Then
    validaISBN:=true
  else
    validaISBN:=false;
end else
  validaISBN:=false;
end;

function TRotinasGlobais.ConsultaCampoDesc(var Consulta: TQuery;
sCampoCodigo, sTextoSql, sMensagemErro: string): string;
begin
if Rotinas.ValidaInteger(sCampoCodigo) then
  result:=ConsultaCampoDesc2(Consulta, sTextoSql, sMensagemErro)
else
  result:='';
end;

function TRotinasGlobais.ConsultaCampoDesc2(var Consulta: TQuery;
sTextoSql, sMensagemErro: string): string;
begin
  if Rotinas.ConsultaDados(Consulta, sTextoSql) then
     result:=Consulta.Fields[1].AsString
  else begin
    MessageDlg(sMensagemErro, mtError, [mbOk], 0);
    result:='';
  end;
end;

procedure TRotinasGlobais.AdicionaItemLista(var lstLista: TListBox;
var slCodLista: TStringList; var sCampoCodigo: TEdit;
var sCampoDesc: TEdit);
var sItems: string;
begin
if sCampoDesc.Text<>'' then begin
 sItems:=sCampoCodigo.Text+' - '+sCampoDesc.Text;
 if lstLista.Items.IndexOf(sItems)=-1 then
  begin
    slCodLista.Add(sCampoCodigo.Text);
    lstLista.Items.Add(sItems);
  end;
 sCampoCodigo.Clear;
 sCampoDesc.Clear;
end;
end;

procedure TRotinasGlobais.RemoveItemLista(var lstLista: TListBox;
				          var slCodLista: TStringList);
begin
 if lstLista.Items.Count > 0 then begin
   slCodLista.Delete(lstLista.ItemIndex);
   lstLista.Items.Delete(lstLista.ItemIndex);
 end;
end;

procedure TRotinasGlobais.AdicionaValoresLista(var ConsLista: TQuery;
sTextoSql: string; var lstLista: TListBox; var slCodLista: TStringList);
begin
 ConsLista.Close;
 lstLista.Clear;
 slCodLista.Clear;
 ConsLista.Sql.Add(sTextoSql);
 ConsLista.Open;
 while not ConsLista.eof do begin
  slCodLista.Add(ConsLista.Fields[0].AsString);
  lstLista.Items.Add(ConsLista.Fields[0].AsString+' - '+
  ConsLista.Fields[1].AsString);
  ConsLista.Next;
 end;
end;

procedure TRotinasGlobais.ChamarTela(var Tela: TForm);
begin
  Tela.BorderStyle:=bsSingle;
  Tela.FormStyle:=fsMDIChild;
  Tela.Position:=poDefault;
  Tela.Show;
end;

end.
