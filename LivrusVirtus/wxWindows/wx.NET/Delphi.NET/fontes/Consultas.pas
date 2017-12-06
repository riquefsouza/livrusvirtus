unit Consultas;

interface

uses
  System.Drawing, wx, System.Collections;

type
  TfrmConsultas = class(wx.Dialog)
  private
    sSelecionado: string;
    grid_sizer_2: wx.GridSizer;
    procedure FazLayout(bFit: boolean);
    procedure AtribuiLabRegistro(sTexto: string);
  protected
		Registros, Campos: ArrayList;
		labDescricao: wx.StaticText;
		edtDescricao: wx.TextCtrl;
	  btnPesquisar: wx.Button;
		labRegistro: wx.StaticText;
		gridConsulta: wx.Grid;
		btnFechar: wx.Button;
		btnLimpar: wx.Button;
    procedure Fecha(nIndMenu: integer);
    procedure LimparDados();
    procedure PesquisarDados(sTextoSql, sMensagemErro: string;
      nQtdCol: integer);
    procedure setLabRegistros(nLinha: integer);
  public
    constructor Create(parent: wx.Window; sLabDescricao: string);
  end;

const
  ID_FRMCONSULTAS_BTNFECHAR: integer = 500;
  ID_FRMCONSULTAS_BTNLIMPAR: integer = 501;
  ID_FRMCONSULTAS_BTNPESQUISAR: integer = 502;
  ID_FRMCONSULTAS_EDTDESCRICAO: integer = 503;
  ID_FRMCONSULTAS_GRIDCONSULTA: integer = 504;
  ID_FRMCONSULTAS_LABDESCRICAO: integer = 505;
  ID_FRMCONSULTAS_LABREGISTRO: integer = 506;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmConsultas))]

implementation

uses RotinasGlobais, Principal;

constructor TfrmConsultas.Create(parent: wx.Window; sLabDescricao: string);
begin
  inherited Create(parent, -1, 'Consulta de',
   System.Drawing.Point.Create(0, 0), System.Drawing.Size.Create(365, 263),
   wxDEFAULT_DIALOG_STYLE or wxCAPTION or
   wxRESIZE_BORDER or wxMINIMIZE_BOX or wxMAXIMIZE_BOX);

	SetIcon(wx.Icon.Create( 'xpms/livrus.xpm' ));
  ClientSize := System.Drawing.Size.Create(365, 263);
  Centre();

  labDescricao := wx.StaticText.Create(self, ID_FRMCONSULTAS_LABDESCRICAO,
    sLabDescricao, System.Drawing.Point.Create(8, 8),
    System.Drawing.Size.Create(51, 13), 0);
  edtDescricao := wx.TextCtrl.Create(self, ID_FRMCONSULTAS_EDTDESCRICAO,
    '', System.Drawing.Point.Create(8, 24),
    System.Drawing.Size.Create(257, 21), 0);
  btnPesquisar := wx.Button.Create(self, ID_FRMCONSULTAS_BTNPESQUISAR,
    '&Pesquisar', System.Drawing.Point.Create(272, 24),
    System.Drawing.Size.Create(75, 25), 0);

  gridConsulta := wx.Grid.Create(self, ID_FRMCONSULTAS_GRIDCONSULTA,
    System.Drawing.Point.Create(0, 56), System.Drawing.Size.Create(365, 125),
    wx.Window.wxBORDER_SUNKEN);
  gridConsulta.CreateGrid(1, 2, wx.GridSelectionMode.wxGridSelectRows);
  gridConsulta.SetColLabelValue(0, 'Código');
  gridConsulta.SetColSize(0, 80);
  gridConsulta.SetColLabelValue(1, 'Descrição');
  gridConsulta.SetColSize(1, 180);
  gridConsulta.Editable := false;
  gridConsulta.HideCellEditControl();
  gridConsulta.ColLabelSize := 21;

  labRegistro := wx.StaticText.Create(self, ID_FRMCONSULTAS_LABREGISTRO,
    'Registro 0 de 0', System.Drawing.Point.Create(8, 16),
    System.Drawing.Size.Create(144, 13), 0);
  btnLimpar := wx.Button.Create(self, ID_FRMCONSULTAS_BTNLIMPAR,
    '&Limpar', System.Drawing.Point.Create(16, 13),
    System.Drawing.Size.Create(75, 25), 0);
  btnFechar := wx.Button.Create(self, ID_FRMCONSULTAS_BTNFECHAR,
    '&Fechar', System.Drawing.Point.Create(75, 13),
    System.Drawing.Size.Create(75, 25), 0);

  FazLayout(true);
  Registros := ArrayList.Create();
  sSelecionado := '';
  edtDescricao.SetFocus();
end;

procedure TfrmConsultas.FazLayout(bFit: boolean);
var sizer_1, sizer_2, sizer_3, sizer_4: wx.BoxSizer;
  grid_sizer_1: wx.GridSizer;
begin
  sizer_1 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  grid_sizer_2 := wx.GridSizer.Create(1, 2, 0, 0);
  sizer_2 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_3 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_4 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  grid_sizer_1 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_1.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_1.Add(edtDescricao, 0, 0, 0);
  sizer_3.Add(grid_sizer_1, 0, wx.Direction.wxALL, 2);
  sizer_4.Add(20, 20, 0, 0, 0);
  sizer_4.Add(btnPesquisar, 0, wx.Direction.wxLEFT or 
    wx.Direction.wxTOP or wx.Direction.wxBOTTOM, 5);
  sizer_3.Add(sizer_4, 0, 0, 0);
  sizer_1.Add(sizer_3, 0, wx.Direction.wxALL, 4);
  sizer_1.Add(gridConsulta, 1, wx.Stretch.wxEXPAND, 0);
  grid_sizer_2.Add(labRegistro, 0, wx.Direction.wxALL, 10);
  sizer_2.Add(btnLimpar, 0, wx.Alignment.wxALIGN_RIGHT or 
    wx.Alignment.wxALIGN_BOTTOM, 8);
  sizer_2.Add(btnFechar, 0, wx.Direction.wxLEFT or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 8);
  grid_sizer_2.Add(sizer_2, 1, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 4);
  sizer_1.Add(grid_sizer_2, 0, wx.Direction.wxALL or 
    wx.Stretch.wxEXPAND or wx.Alignment.wxALIGN_BOTTOM, 0);
  AutoLayout := true;
  SetSizer(sizer_1);
  if bFit then begin
    sizer_1.Fit(self);
    sizer_1.SetSizeHints(self);
  end;
  Layout();
end;

procedure TfrmConsultas.Fecha(nIndMenu: integer);
begin
  if Length(sSelecionado) > 0 then
    Rotinas.sCodigoSelecionado := sSelecionado
  else
    Rotinas.sCodigoSelecionado := ''; 

  if nIndMenu = 0 then begin
    if self.Modal then
      EndModal(0)
    else
      Close();
  end else
    frmPrincipal.barraMenu.GetMenu(1).Enable(nIndMenu, true);
end;

procedure TfrmConsultas.LimparDados();
begin
  //labRegistro.Label := 'Registro 0 de 0';
  AtribuiLabRegistro('Registro 0 de 0');
  gridConsulta.ClearGrid();
  gridConsulta.DeleteRows(0,gridConsulta.NumberRows-1,true);
  edtDescricao.Clear();
  edtDescricao.SetFocus();
end;

procedure TfrmConsultas.PesquisarDados(sTextoSql, sMensagemErro: string;
    nQtdCol: integer);
begin
  if Rotinas.ConsultaDadosLista(Registros, sTextoSql) then
    Rotinas.AdicionaLinhasGrid(gridConsulta, Registros, nQtdCol)
  else
    wx.MessageDialog.MessageBox(sMensagemErro, 'Erro', 
      wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR );
end;

procedure TfrmConsultas.setLabRegistros(nLinha: integer);
var sLabRegistro: string;
begin
  if nLinha >= 0 then begin
    sLabRegistro := 'Registro ' + Convert.ToString(nLinha+1) + ' de ' +
      Convert.ToString(gridConsulta.NumberRows);
    AtribuiLabRegistro(sLabRegistro);
    sSelecionado := gridConsulta.GetCellValue(nLinha, 0);
  end;
end;

//Necessário por que a propriedade Label é uma palavra chave no Delphi.
procedure TfrmConsultas.AtribuiLabRegistro(sTexto: string);
begin
  labRegistro.Destroy;
  labRegistro := wx.StaticText.Create(self, ID_FRMCONSULTAS_LABREGISTRO,
    sTexto, System.Drawing.Point.Create(8, 16),
    System.Drawing.Size.Create(144, 13), 0);
  FazLayout(false);
end;

end.
