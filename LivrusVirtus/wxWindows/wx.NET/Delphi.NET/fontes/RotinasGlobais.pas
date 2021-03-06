unit RotinasGlobais;

interface

uses System.Collections, System.Windows.Forms, System.Data, 
  System.Data.OleDb, wx;

type
  TRotinasGlobais = class
  private
    { Private Declarations }
  public
    sUsuarioLogin, sUsuarioSenha: string;
    sCodigoSelecionado, sPreco, sQtdEstoque, sBarraLogin: string;
    gConexao: System.Data.OleDb.OleDbConnection;
    constructor Create;
    function ValidaFloat(sNum: string): boolean;
    function ValidaCampo(sCampo, sMensagemErro: string): boolean;
    function VirgulaParaPonto(sNum: string; revertido: boolean): string;
    function modulo11(svalor: string; ndig: integer): integer;
    function ValidaCPF(cpf: string): boolean;
    function ValidaISBN(isbn: string): boolean;
    function validaDataHora(sDataHora: string; bSoData: boolean): boolean;
    function retDataHoraStr(bData, bHora: boolean): string;
    function ConverteDataHoraStr(sData, formato: String): String;
    function ConectaBanco(sFonteDeDados: string): boolean;
    procedure DisconectaBanco();
    function AtualizaDados(Arquiva: OleDbCommand; sTextoSql: string): boolean;
    function ConsultaDados(Consulta: OleDbCommand; sTextoSql: string): boolean;
    function ConsultaDadosLista(Registros: ArrayList; sTextoSql: string): boolean;
    function ConsultaCampoDesc(Campos: ArrayList; sTextoSql,
      sMensagemErro:String): String;
    function PesquisaItemLista(lstLista: wx.ListBox; sItem: string): integer;
    procedure AdicionaItemLista(lstLista: wx.ListBox; slCodLista: ArrayList;
      sCampoCodigo: wx.TextCtrl; sCampoDesc: wx.TextCtrl);
    procedure RemoveItemLista(lstLista: wx.ListBox; slCodLista: ArrayList);
    procedure AdicionaValoresLista(sTextoSql: String; lstLista: wx.ListBox;
      slCodLista: ArrayList);
    procedure AdicionaColunasGrid(grid: wx.Grid; nPosIni, 
      nQtdCols: integer; nLargura: array of integer; sRotulos: array of string);   
    procedure AdicionaLinhasGrid(grid: wx.Grid; 
      lstLinhas: ArrayList; nQtdCol: integer);
  end;

var
  Rotinas: TRotinasGlobais;

const
  sepDTHR: string = '#'; //SOMENTE ACCESS 
  //sepDTHR: string = ''''; //OUTROS BANCOS 

implementation

uses Principal, Resource;

constructor TRotinasGlobais.Create;
begin
  inherited Create;
  gConexao := System.Data.OleDb.OleDbConnection.Create();
end;

function TRotinasGlobais.ValidaFloat(sNum: string): boolean;
begin
 if sNum<>'' then begin
    try
      Convert.ToSingle(sNum);
      result:=true;
    except
      MessageDialog.MessageBox(Res.STR_NUMINV, 'Erro', 
        Dialog.wxOK or Dialog.wxICON_ERROR );
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

function TRotinasGlobais.validaDataHora(sDataHora: string;
  bSoData: boolean): boolean;
var bvalida, bdatavalida, bhoravalida: boolean;
    sdia, smes, sano, shora, smin, sseg: string;
    ndia, nmes, nano, nhora, nmin, nseg, nudiames: integer;
    nStatus, ntam: integer;
begin
bdatavalida:=false;
bhoravalida:=false;
nudiames:=0;

if bSoData=true then ntam:=10
else ntam:=19;

if length(sDataHora)=ntam then begin
  sdia:=copy(sDataHora,1,2);
  Val(sdia,ndia,nStatus);
  smes:=copy(sDataHora,4,2);
  Val(smes,nmes,nStatus);
  sano:=copy(sDataHora,7,4);
  Val(sano,nano,nStatus);

  if (nano >= 1) and (nano <= 9999) then begin
    if (nmes >= 1) and (nmes <= 31) then begin
        case nmes of
         1, 3, 5, 7, 8, 10, 12: nudiames:=31;
         2: begin
             { ano bissexto }
             if (nano mod 4)=0 then nudiames:=29
             else nudiames:=28;
            end;
         4, 6, 9, 11: nudiames:=30;
        end;
        if (ndia >=1) and (ndia <=nudiames) then
           bdatavalida:=true;
    end;
  end;

  if bSoData then begin
     if bdatavalida then bvalida:=true
     else bvalida:=false;
  end else begin
    if bdatavalida then begin
        shora:=copy(sDataHora,12,2);
        Val(shora,nhora,nStatus);
        smin:=copy(sDataHora,15,2);
        Val(smin,nmin,nStatus);
        sseg:=copy(sDataHora,18,2);
        Val(sseg,nseg,nStatus);

        if (nhora >= 0) and (nhora <= 23) then begin
          if (nmin >= 0) and (nmin <= 59) then begin
            if (nseg >= 0) and (nseg <= 59) then
               bhoravalida:=true;
          end;
        end;

        if bhoravalida then bvalida:=true
        else bvalida:=false;
    end else
      bvalida:=false;
  end;
end else 
  bvalida:=false;

result:=bvalida;
end;

function TRotinasGlobais.retDataHoraStr(bData, bHora: boolean): string;
var sDataHora: string;
  sTempo: DateTime;
begin
  sDataHora:='';
  sTempo := DateTime.Now;
  
  if (bData) and (bHora) then
    sDataHora := sTempo.ToString('dd/MM/yyyy hh:mm:ss')
  else if bData then
    sDataHora := sTempo.ToString('dd/MM/yyyy')
  else if bHora then
    sDataHora := sTempo.ToString('hh:mm:ss');
  
  result:=sDataHora;
end;

function TRotinasGlobais.ConverteDataHoraStr(sData, formato: String): String;
var dtNasc: DateTime;
begin
  dtNasc:=DateTime.Parse(sData);
  result:=dtNasc.ToString(formato);
end;

function TRotinasGlobais.ConectaBanco(sFonteDeDados: string): boolean;
begin
	gConexao.ConnectionString := sFonteDeDados;
  gConexao.Open();

  if gConexao.State = ConnectionState.Open then
    result:=true
  else begin
    MessageDialog.MessageBox(Res.STR_NCONBANCO, 'Erro', 
      Dialog.wxOK or Dialog.wxICON_ERROR );
    result:=false;
  end;
end;

procedure TRotinasGlobais.DisconectaBanco();
begin
  gConexao.Close();
end;

function TRotinasGlobais.AtualizaDados(Arquiva: OleDbCommand; 
  sTextoSql: string): boolean;
begin
  Arquiva := gConexao.CreateCommand();
  Arquiva.CommandText := sTextoSql;
	if Arquiva.ExecuteNonQuery() > 0 then begin
	  Arquiva.Dispose();
    result:=true;
  end else begin
    //MessageDialog.MessageBox(Res.STR_NCEXECSQL, 'Erro', 
    //  Dialog.wxOK or Dialog.wxICON_ERROR );
    result:=false;
  end;
end;

function TRotinasGlobais.ConsultaDados(Consulta: OleDbCommand;
sTextoSql: string): boolean;
var nTemLinhas: boolean;
  Leitor: OleDbDataReader;
begin
  Consulta := gConexao.CreateCommand;
  Consulta.CommandText := sTextoSql;

  Leitor := Consulta.ExecuteReader;
  nTemLinhas := Leitor.HasRows;
  Leitor.Close;
  ConsultaDados := nTemLinhas;
end;

function TRotinasGlobais.ConsultaDadosLista(Registros: ArrayList;
  sTextoSql: string): boolean;
var nTemLinhas: boolean;
  Consulta: OleDbCommand;
  Leitor: OleDbDataReader;
  Campos: ArrayList;
  cont: integer;
begin
  Consulta := gConexao.CreateCommand;
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
  ConsultaDadosLista := nTemLinhas;
end;

function TRotinasGlobais.ValidaCampo(sCampo, sMensagemErro: string): boolean;
begin
result:=false;
  if sCampo='' then begin
    MessageDialog.MessageBox(sMensagemErro, 'Erro', 
      Dialog.wxOK or Dialog.wxICON_ERROR );
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
  Consulta:= gConexao.CreateCommand;
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
    MessageDialog.MessageBox(sMensagemErro, 'Erro', 
      Dialog.wxOK or Dialog.wxICON_ERROR );
	  result:='';
  end;
end;

function TRotinasGlobais.PesquisaItemLista(lstLista: wx.ListBox; 
  sItem: string): integer;
var bret, nLinha: integer;
begin
  bret := -1;
  for nLinha := 0 to lstLista.Count do begin
    if lstLista.GetString(nLinha) = sItem then begin
      bret := 0;
    end;        
  end;
  result:=bret;
end;

procedure TRotinasGlobais.AdicionaItemLista(lstLista: wx.ListBox;
slCodLista: ArrayList; sCampoCodigo: wx.TextCtrl; sCampoDesc: wx.TextCtrl);
var sItems: String;
begin
  if sCampoDesc.Value<>'' then begin
     sItems:=sCampoCodigo.Value + ' - ' + sCampoDesc.Value;
     if PesquisaItemLista(lstLista, sItems)=-1 then begin
    	slCodLista.Add(sCampoCodigo.Value);
    	lstLista.Append(sItems);
     end;
     sCampoCodigo.Clear;
     sCampoDesc.Clear;
  end;
end;

procedure TRotinasGlobais.RemoveItemLista(lstLista: wx.ListBox;
  slCodLista: ArrayList);
var nSelIndice: integer;
begin
  if lstLista.Count > 0 then begin
    nSelIndice := lstLista.Selection;
    if lstLista.Selected(nSelIndice) then begin
      slCodLista.RemoveAt(nSelIndice);
      lstLista.Delete(nSelIndice);
    end;
  end;
end;

procedure TRotinasGlobais.AdicionaValoresLista(sTextoSql: String;
  lstLista: wx.ListBox; slCodLista: ArrayList);
var Consulta: OleDbCommand;
Leitor: OleDbDataReader;
begin
 lstLista.Clear;
 slCodLista.Clear;

  Consulta:= gConexao.CreateCommand;
  Consulta.CommandText := sTextoSql;

  Leitor:= Consulta.ExecuteReader;
  while Leitor.Read do begin
    slCodLista.Add(Leitor.GetValue(0).ToString);
    lstLista.Append(Leitor.GetValue(0).ToString+' - '+
    Leitor.GetValue(1).ToString);
  end;
  Leitor.Close;
end;

procedure TRotinasGlobais.AdicionaColunasGrid(grid: wx.Grid; nPosIni, 
  nQtdCols: integer; nLargura: array of integer; sRotulos: array of string);
var nPos, nCont: integer;
begin    
  if nPosIni > 0 then begin
    grid.AppendCols(nQtdCols);
  end;
  nCont := 0;
  for nPos := nPosIni to (nPosIni+nQtdCols-1) do begin
    grid.SetColSize(nPos, nLargura[nCont]);
    grid.SetColLabelValue(nPos, sRotulos[nCont]);
    nCont := nCont + 1;
  end;
end;

procedure TRotinasGlobais.AdicionaLinhasGrid(grid: wx.Grid; 
  lstLinhas: ArrayList; nQtdCol: integer);
var nCol, nLinha: integer;
   lstCampos: ArrayList;
begin
  grid.DeleteRows(0, grid.NumberRows, true);
  grid.AppendRows(lstLinhas.Count, true);
  for nLinha := 0 to lstLinhas.Count-1 do begin
	  lstCampos := ArrayList(lstLinhas[nLinha]);
    for nCol:= 0 to nQtdCol-1 do begin
      grid.SetCellValue(nLinha, nCol, lstCampos[nCol].ToString());
    end;
  end;
end;

end.
