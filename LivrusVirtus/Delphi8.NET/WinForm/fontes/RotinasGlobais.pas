unit RotinasGlobais;

interface

uses System.Collections, System.Windows.Forms, System.Data, System.Data.OleDb;

type
  TRotinasGlobais = class(System.Object)
  private
    { Private Declarations }
  public
    sUsuarioLogin, sUsuarioSenha: string;
    sCodigoSelecionado, sPreco, sQtdEstoque: string;
    function ConsultaDados(Consulta: OleDbCommand; sTextoSql: string): boolean;
      overload;
    function ConsultaDados(dsConsulta: DataSet; Registros: ArrayList;
      sTextoSql: string): boolean; overload;
    function ConsultaDados(Registros: ArrayList; sTextoSql: string): boolean;
      overload;
    function ValidaCampo(sCampo, sMensagemErro: string): boolean;
    function ValidaInteger(sNum: string): boolean;
    function ValidaFloat(sNum: string): boolean;
    function VirgulaParaPonto(sNum: string; revertido: boolean): string;
    function modulo11(svalor: string; ndig: integer): integer;
    function ValidaCPF(cpf: string): boolean;
    function ValidaISBN(isbn: string): boolean;
    function ConsultaCampoDesc(Campos: ArrayList; sTextoSql,
      sMensagemErro:String): String; overload;
    function ConsultaCampoDesc(Campos: ArrayList; sCampoCodigo, sTextoSql,
      sMensagemErro: String): String; overload;
    function retDataStr(sData: DateTime; formato: string): String;
    function FormataDataStr(sData, formato: String): String;
    procedure AdicionaItemLista(lstLista: ListBox; slCodLista: ArrayList;
      sCampoCodigo: TextBox; sCampoDesc: TextBox);
    procedure RemoveItemLista(lstLista: ListBox; slCodLista: ArrayList);
    procedure AdicionaValoresLista(ConsLista: ArrayList; sTextoSql: String;
      lstLista: ListBox; slCodLista: ArrayList);

    constructor Create;
  end;

var
  Rotinas: TRotinasGlobais;

implementation

uses Principal;

constructor TRotinasGlobais.Create;
begin
  inherited Create;
  // TODO: Add any constructor code here
end;

function TRotinasGlobais.ValidaInteger(sNum: string): boolean;
begin
 if sNum<>'' then begin
    try
      Int32.Parse(sNum);
      result:=true;
    except
   	  MessageBox.Show('Número inválido!', 'Erro',
	    MessageBoxButtons.OK,MessageBoxIcon.Error);
      result:=false;
    end;
 end else
   result:=false;
end;

function TRotinasGlobais.ValidaFloat(sNum: string): boolean;
begin
 if sNum<>'' then begin
    try
      Convert.ToSingle(sNum);
      result:=true;
    except
   	  MessageBox.Show('Número inválido!', 'Erro',
	    MessageBoxButtons.OK,MessageBoxIcon.Error);
      result:=false;
    end;
 end else
   result:=false;
end;

function TRotinasGlobais.VirgulaParaPonto(sNum: string;
revertido: boolean): string;
begin
 if revertido then
   result:= sNum.Replace('.',',')
 else
   result:= sNum.Replace(',', '.');
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
   nvalor:=Int32.Parse(sres);
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
  if ( (modulo11(scpf,1)=Int32.parse(copy(cpf,13,1))) and
  (modulo11(scpf,2)=Int32.parse(copy(cpf,14,1))) ) then
    result:=true
  else
    result:=false;
end else
  result:=false;
end;

function TRotinasGlobais.ValidaISBN(isbn: string): boolean;
var snum, sdigito, sisbn: string;
 nvalor, nsoma, nstatus, ncont: integer;
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
    nvalor:=Int32.Parse(sdigito);
    nsoma := nvalor;
  end;
  for ncont:=1 to 9 do begin
    snum:=copy(sisbn, ncont, 1);
    nvalor:=Int32.Parse(snum);
    nsoma:=nsoma + (nvalor * (11 - ncont));
  end;
  If (nsoma mod 11) = 0 Then
    validaISBN:=true
  else
    validaISBN:=false;
end else
  validaISBN:=false;
end;

function TRotinasGlobais.ConsultaDados(Consulta: OleDbCommand;
sTextoSql: string): boolean;
var nTemLinhas: boolean;
  Leitor: OleDbDataReader;
begin
  Consulta := fPrincipal.db.CreateCommand;
  Consulta.CommandText := sTextoSql;

  Leitor := Consulta.ExecuteReader;
  nTemLinhas := Leitor.HasRows;
  Leitor.Close;
  ConsultaDados := nTemLinhas;
end;

function TRotinasGlobais.ConsultaDados(dsConsulta: DataSet;
Registros: ArrayList; sTextoSql: string): boolean;
var nTemLinhas: boolean;
  Consulta: OleDbCommand;
  daConsulta: OleDbDataAdapter;
  Leitor: OleDbDataReader;
  Campos: ArrayList;
  cont: integer;
begin
  dsConsulta.Clear;
  Consulta := OleDbCommand.Create;
  daConsulta := OleDbDataAdapter.Create;

  daConsulta.TableMappings.Add('Table','Consulta');
  Consulta := fPrincipal.db.CreateCommand;
  Consulta.CommandText:=sTextoSql;
  daConsulta.SelectCommand := Consulta;
  daConsulta.Fill(dsConsulta);

  Registros.Clear;
  Leitor := Consulta.ExecuteReader;
  while Leitor.Read do begin
   Campos := ArrayList.Create;
   for cont:=0 to (Leitor.FieldCount - 1) do begin
     Campos.Add(Leitor.GetValue(cont).ToString);
   end;
   Registros.Add(Campos);
  end;
  nTemLinhas := Leitor.HasRows;
  Leitor.Close;
  ConsultaDados := nTemLinhas;
end;

function TRotinasGlobais.ConsultaDados(Registros: ArrayList;
sTextoSql: string): boolean;
var nTemLinhas: boolean;
  Consulta: OleDbCommand;
  Leitor: OleDbDataReader;
  Campos: ArrayList;
  cont: integer;
begin
  Consulta := fPrincipal.db.CreateCommand;
  Consulta.CommandText := sTextoSql;

  Registros.Clear;
  Leitor := Consulta.ExecuteReader;
  while Leitor.Read do begin
   Campos := ArrayList.Create;
   for cont:=0 to (Leitor.FieldCount - 1) do begin
     Campos.Add(Leitor.GetValue(cont).ToString);
   end;
   Registros.Add(Campos);
  end;
  nTemLinhas := Leitor.HasRows;
  Leitor.Close;
  ConsultaDados := nTemLinhas;

end;

function TRotinasGlobais.ValidaCampo(sCampo, sMensagemErro: string): boolean;
begin
result:=false;
  if sCampo='' then begin
  	MessageBox.Show(sMensagemErro, 'Erro', MessageBoxButtons.OK,
    MessageBoxIcon.Error);
    result:=true;
  end;
end;

function TRotinasGlobais.ConsultaCampoDesc(Campos: ArrayList;
sTextoSql, sMensagemErro:String): String;
var Consulta: OleDbCommand;
  Leitor: OleDbDataReader;
  cont: integer;
  nTemLinhas: boolean;
begin
  Consulta:= fPrincipal.db.CreateCommand;
  Consulta.CommandText:= sTextoSql;

  Campos.Clear;
  Leitor:=Consulta.ExecuteReader;
  if Leitor.Read then begin
	 for cont:= 0 to Leitor.FieldCount - 1 do begin
	   Campos.Add(Leitor.GetValue(cont).ToString);
	 end;
  end;
  nTemLinhas:=Leitor.HasRows;
  Leitor.Close;

  if nTemLinhas then
	 result:=Campos.Item[1].ToString
  else begin
    MessageBox.Show(sMensagemErro, 'Erro',
    MessageBoxButtons.OK,MessageBoxIcon.Error);
	  result:='';
  end;
end;

function TRotinasGlobais.ConsultaCampoDesc(Campos: ArrayList;
sCampoCodigo, sTextoSql, sMensagemErro: String): String;
begin
  if ValidaInteger(sCampoCodigo) then
    result:=ConsultaCampoDesc(Campos, sTextoSql, sMensagemErro)
  else
    result:='';
end;

function TRotinasGlobais.retDataStr(sData: DateTime; formato: string): String;
begin
  result:=sData.ToString(formato);
end;

function TRotinasGlobais.FormataDataStr(sData, formato: String): String;
var dtNasc: DateTime;
begin
  dtNasc:=DateTime.Parse(sData);
  result:=dtNasc.ToString(formato);
end;

procedure TRotinasGlobais.AdicionaItemLista(lstLista: ListBox;
slCodLista: ArrayList; sCampoCodigo: TextBox; sCampoDesc: TextBox);
var sItems: String;
begin
  if sCampoDesc.Text<>'' then begin
     sItems:=sCampoCodigo.Text + ' - ' + sCampoDesc.Text;
     if lstLista.Items.IndexOf(sItems)=-1 then begin
    	slCodLista.Add(sCampoCodigo.Text);
    	lstLista.Items.Add(sItems);
     end;
     sCampoCodigo.Clear;
     sCampoDesc.Clear;
  end;
end;

procedure TRotinasGlobais.RemoveItemLista(lstLista: ListBox;
slCodLista: ArrayList);
begin
 if lstLista.Items.Count > 0 then begin
   slCodLista.RemoveAt(lstLista.SelectedIndex);
   lstLista.Items.RemoveAt(lstLista.SelectedIndex);
 end;
end;

procedure TRotinasGlobais.AdicionaValoresLista(ConsLista: ArrayList;
sTextoSql: String; lstLista: ListBox; slCodLista: ArrayList);
var Consulta: OleDbCommand;
Leitor: OleDbDataReader;
begin
 ConsLista.Clear;
 lstLista.Items.Clear;
 slCodLista.Clear;

  Consulta:= fPrincipal.db.CreateCommand;
  Consulta.CommandText := sTextoSql;

  Leitor:= Consulta.ExecuteReader;
  while Leitor.Read do begin
    slCodLista.Add(Leitor.GetValue(0).ToString);
    lstLista.Items.Add(Leitor.GetValue(0).ToString+' - '+
    Leitor.GetValue(1).ToString);
  end;
  Leitor.Close;

end;

end.
