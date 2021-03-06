unit ConVendas;

interface

uses
  System.Drawing, wx, System.Collections, System.Data.OleDb;

type
  TfrmConVendas = class(wx.Panel)
  private
    labDtHrVenda: wx.StaticText;
    edtDtHrVenda: wx.TextCtrl;
    labCPF: wx.StaticText;
    edtCPF: wx.TextCtrl;
    labCliente: wx.StaticText;
    edtCliente: wx.TextCtrl;
    btnPCliente: wx.Button;
    labISBN: wx.StaticText;
    edtISBN: wx.TextCtrl;
    labLivro: wx.StaticText;
    edtLivro: wx.TextCtrl;
    btnPLivro: wx.Button;
    labRegistro: wx.StaticText;
    gridVendas: wx.Grid;
    labPrecoTotal: wx.StaticText;
    edtPrecoTotal: wx.TextCtrl;
    btnPesquisar: wx.Button;
    btnLimpar: wx.Button;
    btnFechar: wx.Button;
    procedure FazLayout(bFit: boolean);
    function ConsVenda(sOpcao: char): string;
    procedure OnClose(sender: System.Object; e: wx.Event);
    procedure OnBtnPesquisar(sender: System.Object; e: wx.Event);
    procedure OnBtnLimpar(sender: System.Object; e: wx.Event);
    procedure OnBtnFechar(sender: System.Object; e: wx.Event);
    procedure OnEdtCPF_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnBtnPCliente(sender: System.Object; e: wx.Event);
    procedure OnEdtISBN_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnBtnPLivro(sender: System.Object; e: wx.Event);
    procedure setLabRegistros(nLinha: integer);
    procedure OnGridSelectCell(sender: System.Object; e: wx.Event);
    procedure OnGridLabelLeftClick(sender: System.Object; e: wx.Event);
    procedure OnEdtDtHrVenda_Killfocus(sender: System.Object; e: wx.Event);
    procedure AtribuiLabRegistro(sTexto: string);
  public
    constructor Create(parent: wx.Window);
  end;

var
  frmConVendas: TfrmConVendas;

const
  ID_FRMCONVENDAS_BTNPESQUISAR: integer = 3100;
  ID_FRMCONVENDAS_BTNLIMPAR: integer = 3101; 
  ID_FRMCONVENDAS_BTNFECHAR: integer = 3102;
  ID_FRMCONVENDAS_BTNPCLIENTE: integer = 3103;
  ID_FRMCONVENDAS_BTNPLIVRO: integer = 3104; 
  ID_FRMCONVENDAS_GRIDVENDAS: integer = 3105;
  ID_FRMCONVENDAS_EDTDTHRVENDA: integer = 3106; 
  ID_FRMCONVENDAS_EDTISBN: integer = 3107;
  ID_FRMCONVENDAS_EDTLIVRO: integer = 3108; 
  ID_FRMCONVENDAS_EDTPRECOTOTAL: integer = 3109; 
  ID_FRMCONVENDAS_LABDTHRVENDA: integer = 3110; 
  ID_FRMCONVENDAS_LABISBN: integer = 3111; 
  ID_FRMCONVENDAS_LABLIVRO: integer = 3112; 
  ID_FRMCONVENDAS_LABPRECOTOTAL: integer = 3113;
  ID_FRMCONVENDAS_LABCPF: integer = 3114; 
  ID_FRMCONVENDAS_EDTCPF: integer = 3115; 
  ID_FRMCONVENDAS_LABCLIENTE: integer = 3116; 
  ID_FRMCONVENDAS_EDTCLIENTE: integer = 3117; 
  ID_FRMCONVENDAS_LABREGISTRO: integer = 3118;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConVendas))]

implementation

uses TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL, ConLivros,
  ConClientes;

constructor TfrmConVendas.Create(parent: wx.Window);
const nLargura: array[0..5] of integer = ( 120, 100, 220, 100, 280, 80 );
  sRotulos: array[0..5] of string = ( 'Data/Hora Venda', 'CPF', 'Cliente', 
  'ISBN', 'Livro', 'Pre�o' );
begin
  inherited Create(parent, -1, System.Drawing.Point.Create(0, 0),
    System.Drawing.Size.Create(480, 310));

  labDtHrVenda := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABDTHRVENDA,
    'Data/Hora Venda: ', System.Drawing.Point.Create(8, 8),
    System.Drawing.Size.Create(91, 13), 0);
  edtDtHrVenda := wx.TextCtrl.Create(self, ID_FRMCONVENDAS_EDTDTHRVENDA,
    '', System.Drawing.Point.Create(8, 24), System.Drawing.Size.Create(128, 21), 0);
  edtDtHrVenda.EVT_KILL_FOCUS( OnEdtDtHrVenda_Killfocus );

  btnPesquisar := wx.Button.Create(self, ID_FRMCONVENDAS_BTNPESQUISAR,
    '&Pesquisar', System.Drawing.Point.Create(144, 22),
    System.Drawing.Size.Create(75, 25), 0);

  labCPF := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABCPF,'CPF: ',
    System.Drawing.Point.Create(8, 48), System.Drawing.Size.Create(48, 13), 0);
  edtCPF := wx.TextCtrl.Create(self, ID_FRMCONVENDAS_EDTCPF,'',
    System.Drawing.Point.Create(8, 64), System.Drawing.Size.Create(128, 21), 0);
  edtCPF.EVT_KILL_FOCUS( OnEdtCPF_Killfocus );

  labCliente := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABCLIENTE,
    'Cliente: ', System.Drawing.Point.Create(142, 48),
    System.Drawing.Size.Create(56, 13), 0);
  edtCliente := wx.TextCtrl.Create(self, ID_FRMCONVENDAS_EDTCLIENTE,'',
    System.Drawing.Point.Create(142, 64),
    System.Drawing.Size.Create(306, 21), 0);
  edtCliente.Enabled := false;

  btnPCliente:= wx.Button.Create(self, ID_FRMCONVENDAS_BTNPCLIENTE,'...',
    System.Drawing.Point.Create(448, 64),
    System.Drawing.Size.Create(21, 21), 0);

  labISBN := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABISBN,'ISBN: ',
    System.Drawing.Point.Create(8, 88), System.Drawing.Size.Create(48, 13), 0);
  edtISBN := wx.TextCtrl.Create(self, ID_FRMCONVENDAS_EDTISBN,'',
    System.Drawing.Point.Create(8, 104),
    System.Drawing.Size.Create(128, 21), 0);
  edtISBN.EVT_KILL_FOCUS( OnEdtISBN_Killfocus );

  labLivro := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABLIVRO,'Livro: ',
    System.Drawing.Point.Create(142, 88),
    System.Drawing.Size.Create(40, 13), 0);
  edtLivro := wx.TextCtrl.Create(self, ID_FRMCONVENDAS_EDTLIVRO,
    '', System.Drawing.Point.Create(142, 104),
    System.Drawing.Size.Create(306, 21), 0);
  edtLivro.Enabled := false;

  btnPLivro:= wx.Button.Create(self, ID_FRMCONVENDAS_BTNPLIVRO,
    '...', System.Drawing.Point.Create(448, 104),
    System.Drawing.Size.Create(21, 21), 0);

  gridVendas := wx.Grid.Create(self, ID_FRMCONVENDAS_GRIDVENDAS,
    System.Drawing.Point.Create(0, 136), System.Drawing.Size.Create(355, 122),
    wxSUNKEN_BORDER);
  self.gridVendas.CreateGrid(1, 6, wx.GridSelectionMode.wxGridSelectRows);
  self.gridVendas.HideCellEditControl();
  self.gridVendas.ColLabelSize := 21;

  labRegistro := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABREGISTRO,
    'Registro 0 de 0', System.Drawing.Point.Create(8, 16),
    System.Drawing.Size.Create(144, 13), 0);

  labPrecoTotal := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABPRECOTOTAL,
    'Pre�o Total: ', System.Drawing.Point.Create(280, 248),
    System.Drawing.Size.Create(61, 13), 0);
  edtPrecoTotal := wx.TextCtrl.Create(self, ID_FRMCONVENDAS_EDTPRECOTOTAL,
    '', System.Drawing.Point.Create(344, 246),
    System.Drawing.Size.Create(127, 21), 0);
  edtPrecoTotal.Enabled := false;

  self.btnLimpar:= wx.Button.Create(self, ID_FRMCONVENDAS_BTNLIMPAR,
    '&Limpar', System.Drawing.Point.Create(16, 13),
    System.Drawing.Size.Create(75, 25), 0);
  self.btnFechar:= wx.Button.Create(self, ID_FRMCONVENDAS_BTNFECHAR,
    '&Fechar', System.Drawing.Point.Create(75, 13),
    System.Drawing.Size.Create(75, 25), 0);

  FazLayout(true);

  Rotinas.AdicionaColunasGrid(gridVendas, 0, 6, nLargura, sRotulos);
  gridVendas.Editable := false;
  edtCPF.MaxLength := 14;
  edtISBN.MaxLength := 13;
  edtPrecoTotal.Value := 'R$ 0,00';
  edtDtHrVenda.Value := RotinasGlobais.Rotinas.retDataHoraStr(true,true);

  EVT_BUTTON(ID_FRMCONVENDAS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCONVENDAS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCONVENDAS_BTNFECHAR, OnBtnFechar );
  EVT_CLOSE( OnClose );
  EVT_BUTTON(ID_FRMCONVENDAS_BTNPCLIENTE, OnBtnPCliente );
  EVT_BUTTON(ID_FRMCONVENDAS_BTNPLIVRO, OnBtnPLivro );
  EVT_GRID_SELECT_CELL( OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK( OnGridLabelLeftClick );
end;

procedure TfrmConVendas.FazLayout(bFit: boolean);
var sizer_1, sizer_2, sizer_3, sizer_4, sizer_6, sizer_7, sizer_8, 
    sizer_23, sizer_24: wx.BoxSizer;
    sizer_22, grid_sizer_1, grid_sizer_2, grid_sizer_3, grid_sizer_4, 
    grid_sizer_5, grid_sizer_6, grid_sizer_8: wx.GridSizer;
begin
  sizer_1 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_6 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_22 := wx.GridSizer.Create(1, 2, 0, 0);
  sizer_23 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_8 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_7 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_24 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_4 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_8 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_6 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_5 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_3 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_4 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_3 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_2 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_2 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_1 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_1.Add(labDtHrVenda, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_1.Add(edtDtHrVenda, 0, 0, 0);
  sizer_2.Add(grid_sizer_1, 0, wx.Direction.wxLEFT, 2);
  sizer_2.Add(btnPesquisar, 0, wx.Direction.wxLEFT or 
    wx.Direction.wxTOP or wx.Alignment.wxALIGN_BOTTOM, 10);
  sizer_1.Add(sizer_2, 0, 0, 0);
  grid_sizer_2.Add(labCPF, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_2.Add(edtCPF, 0, 0, 0);
  sizer_3.Add(grid_sizer_2, 0, wx.Direction.wxLEFT, 2);
  grid_sizer_3.Add(labCliente, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_3.Add(edtCliente, 0, 0, 0);
  sizer_3.Add(grid_sizer_3, 0, wx.Direction.wxLEFT, 2);
  grid_sizer_4.Add(20, 20, 0, 0, 0);
  grid_sizer_4.Add(btnPCliente, 0, 0, 0);
  sizer_3.Add(grid_sizer_4, 0, 0, 0);
  sizer_1.Add(sizer_3, 0, 0, 0);
  grid_sizer_5.Add(labISBN, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_5.Add(edtISBN, 0, 0, 0);
  sizer_4.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 2);
  grid_sizer_6.Add(labLivro, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_6.Add(edtLivro, 0, 0, 0);
  sizer_4.Add(grid_sizer_6, 0, wx.Direction.wxLEFT, 2);
  grid_sizer_8.Add(20, 20, 0, 0, 0);
  grid_sizer_8.Add(btnPLivro, 0, 0, 0);
  sizer_4.Add(grid_sizer_8, 0, 0, 0);
  sizer_1.Add(sizer_4, 0, 0, 0);
  sizer_1.Add(gridVendas, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 2);
  sizer_24.Add(labRegistro, 0, wx.Direction.wxALL, 4);
  sizer_24.Add(20, 20, 0, 0, 0);
  sizer_22.Add(sizer_24, 0, 0, 0);
  sizer_7.Add(labPrecoTotal, 0, wx.Direction.wxALL, 2);
  sizer_7.Add(edtPrecoTotal, 0, wx.Direction.wxALL, 2);
  sizer_23.Add(sizer_7, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_8.Add(btnLimpar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_8.Add(btnFechar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_23.Add(sizer_8, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_22.Add(sizer_23, 1, wx.Alignment.wxALIGN_RIGHT or 
    wx.Alignment.wxALIGN_BOTTOM, 0);
  sizer_6.Add(sizer_22, 0, wx.Stretch.wxEXPAND, 0);
  sizer_1.Add(sizer_6, 0, wx.Stretch.wxEXPAND, 0);
  AutoLayout := true;
  SetSizer(sizer_1);
  if bFit then begin
    sizer_1.Fit(self);
    sizer_1.SetSizeHints(self);
  end;
  Layout();
end;

procedure TfrmConVendas.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  edtCPF.Clear();
  edtCliente.Clear();
  edtISBN.Clear();
  edtLivro.Clear();
  gridVendas.ClearGrid();
  gridVendas.DeleteRows(0, gridVendas.NumberRows-1,true);
  edtPrecoTotal.Value := 'R$ 0,00';
  edtDtHrVenda.Value := Rotinas.retDataHoraStr(true,true);
  //labRegistro.Label := 'Registro 0 de 0';
  AtribuiLabRegistro('Registro 0 de 0');
  edtDtHrVenda.SetFocus();
  e.Skip();
end;

function TfrmConVendas.ConsVenda(sOpcao: char): string;
var sISBN, sCPF, sDataHora, sret: string;
begin
  if Length(edtDtHrVenda.Value) > 0 then
    sDataHora := Rotinas.ConverteDataHoraStr(edtDtHrVenda.Value, 
      'MM/dd/yyyy hh:mm:ss')
  else
    sDataHora := '';

  sISBN := edtISBN.Value;
  sCPF := edtCPF.Value;

  if sOpcao = 'L' then
    sret := ConsSQL.Venda('S','ZERO','','','','')
  else
    sret := ConsSQL.Venda(sOpcao, sISBN, sCPF, sDataHora, '', '');

 result:=sret;
end;

procedure TfrmConVendas.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmConVendas.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmConVendas.OnBtnPesquisar(sender: System.Object; e: wx.Event);
var ConsTotal, lstLinhas, lstTotal: ArrayList;
  sPrecoTotal: string;
  nTemp: double;
begin
  ConsTotal := ArrayList.Create;
  lstLinhas := ArrayList.Create;

  if Rotinas.ConsultaDadosLista(lstLinhas, ConsVenda('S')) then begin
    Rotinas.AdicionaLinhasGrid(gridVendas, lstLinhas, 6);

    if Rotinas.ConsultaDadosLista(ConsTotal, ConsVenda('P')) then begin
      if ConsTotal.Count > 0 then begin
        lstTotal := ArrayList(ConsTotal[0]);
        nTemp := Convert.ToDouble(lstTotal[0].ToString()); 
        sPrecoTotal := nTemp.ToString('C'); 
        edtPrecoTotal.Value := sPrecoTotal;
        setLabRegistros(0);
      end;
    end;    
  end else begin
     wx.MessageDialog.MessageBox(Res.STR_VENNENC, 'Erro', 
      wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
  end;
end;

procedure TfrmConVendas.OnEdtCPF_Killfocus(sender: System.Object; e: wx.Event);
var sCliente: string;
  ConsCampo: ArrayList;
begin
  ConsCampo := ArrayList.Create;

  if edtCPF.Value.Length > 0 then begin
    if RotinasGlobais.Rotinas.ValidaCPF(edtCPF.Value) then begin      
      sCliente := RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
        ConsultasSQL.ConsSQL.Cliente('S',edtCPF.Value,
        '','','','','','','','',''),Res.STR_CLINENC); 
      if sCliente.Length=0 then begin
        edtCPF.Clear();
        edtCPF.SetFocus();
      end else
        edtCliente.Value := sCliente;
    end else begin
      wx.MessageDialog.MessageBox(Res.STR_CPFINV, 'Erro', 
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      edtCPF.Clear();
      edtCPF.SetFocus();
    end;
  end else
    edtCliente.Clear();
end;

procedure TfrmConVendas.OnBtnPCliente(sender: System.Object; e: wx.Event);
var fConClientes: TfrmConClientes;
begin
  fConClientes := TfrmConClientes.Create(self);
  fConClientes.ShowModal();
  edtCPF.Value := Rotinas.sCodigoSelecionado;
  OnEdtCPF_Killfocus(nil,nil);	
  e.Skip();
end;

procedure TfrmConVendas.OnEdtISBN_Killfocus(sender: System.Object; e: wx.Event);
var sLivro: string;
  nQtdEstoque: integer;
  ConsCampo: ArrayList;
begin
  ConsCampo := ArrayList.Create;

  if Length(edtISBN.Value) > 0 then begin
    if Rotinas.ValidaISBN(edtISBN.Value) then begin      
      sLivro:= Rotinas.ConsultaCampoDesc(ConsCampo, 
        ConsSQL.Livro('Q',edtISBN.Value,
        '','','','','','','','',''),Res.STR_LIVNENC);
      if Length(sLivro)=0 then begin
        edtISBN.Clear();
      	edtISBN.SetFocus();
      end else begin
         edtLivro.Value := sLivro;
         nQtdEstoque := Int32.Parse(ConsCampo[3].ToString());
         if nQtdEstoque > 0 then begin
           Rotinas.sPreco := ConsCampo[2].ToString();
         end else
           wx.MessageDialog.MessageBox(Res.STR_LIVNEST, 'Erro', 
             wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      end;
    end else begin
      wx.MessageDialog.MessageBox(Res.STR_ISBNINV, 'Erro', 
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      edtISBN.Clear();
      edtISBN.SetFocus();
    end;
  end else
    edtLivro.Clear();
end;

procedure TfrmConVendas.OnBtnPLivro(sender: System.Object; e: wx.Event);
var fConLivros: TfrmConLivros;
begin
  fConLivros := TfrmConLivros.Create(self);
  fConLivros.ShowModal();
  edtISBN.Value := Rotinas.sCodigoSelecionado;
  OnEdtISBN_Killfocus(nil,nil);	
  e.Skip();
end;

procedure TfrmConVendas.setLabRegistros(nLinha: integer);
var sLabRegistro: string;
begin
  if nLinha >= 0 then begin
    slabRegistro := 'Registro ' + Convert.ToString(nLinha+1) +
      ' de ' + Convert.ToString(gridVendas.NumberRows);
    AtribuiLabRegistro(sLabRegistro);
  end;
end;

procedure TfrmConVendas.OnGridSelectCell(sender: System.Object; e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConVendas.OnGridLabelLeftClick(sender: System.Object;
  e: wx.Event);
var evt: wx.GridEvent;
begin
  evt := wx.GridEvent(e);
  setLabRegistros(evt.Row);
  e.Skip();
end;

procedure TfrmConVendas.OnEdtDtHrVenda_Killfocus(sender: System.Object;
  e: wx.Event);
begin
  if edtDtHrVenda.Value.Length > 0 then begin
    if not Rotinas.validaDataHora(edtDtHrVenda.Value, false) then begin
      wx.MessageDialog.MessageBox(Res.STR_DTHRINV, 'Erro', 
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
  		edtDtHrVenda.SetFocus();
    end;
  end; 
end;

//Necess�rio por que a propriedade Label � uma palavra chave no Delphi.
procedure TfrmConVendas.AtribuiLabRegistro(sTexto: string);
begin
  labRegistro.Destroy;
  labRegistro := wx.StaticText.Create(self, ID_FRMCONVENDAS_LABREGISTRO,
    sTexto, System.Drawing.Point.Create(8, 16),
    System.Drawing.Size.Create(144, 13), 0);
  FazLayout(false);
end;

end.
