using System;
using System.Drawing;
using System.Collections;
using wx;

namespace Livrus
{
	public class frmConsultas: wx.Dialog
	{
    protected enum idt {
     ID_FRMCONSULTAS_BTNFECHAR = 500, ID_FRMCONSULTAS_BTNLIMPAR, 
     ID_FRMCONSULTAS_BTNPESQUISAR, ID_FRMCONSULTAS_EDTDESCRICAO, 
     ID_FRMCONSULTAS_GRIDCONSULTA, ID_FRMCONSULTAS_LABDESCRICAO, 
     ID_FRMCONSULTAS_LABREGISTRO }

		protected ArrayList Registros, Campos;
    private string sSelecionado;

		protected wx.StaticText labDescricao;
		protected wx.TextCtrl edtDescricao;
		protected wx.Button btnPesquisar;
		protected wx.StaticText labRegistro;
		protected wx.Grid gridConsulta;
		protected wx.Button btnFechar;
		protected wx.Button btnLimpar;

		public frmConsultas(wx.Window parent)
      : base(parent, -1, "Consulta de", new Point(0, 0), new Size(365, 263),
     	wxDEFAULT_DIALOG_STYLE | wxCAPTION | wxRESIZE_BORDER | 
      wxMINIMIZE_BOX | wxMAXIMIZE_BOX) {

			SetIcon(new wx.Icon( "xpms/livrus.xpm" ));
      ClientSize = new Size(365, 263);
      Centre();
    
      labDescricao = new wx.StaticText(this, (int)idt.ID_FRMCONSULTAS_LABDESCRICAO,
        "Descri��o:", new Point(8, 8), new Size(51, 13), 0);
      edtDescricao = new wx.TextCtrl(this, (int)idt.ID_FRMCONSULTAS_EDTDESCRICAO,
        "", new Point(8, 24), new Size(257, 21), 0);
      btnPesquisar = new wx.Button(this, (int)idt.ID_FRMCONSULTAS_BTNPESQUISAR,
        "&Pesquisar", new Point(272, 24), new Size(75, 25), 0);
    
      gridConsulta = new wx.Grid(this, (int)idt.ID_FRMCONSULTAS_GRIDCONSULTA, 
        new Point(0, 56), new Size(365, 125), wx.Window.wxBORDER_SUNKEN);
      gridConsulta.CreateGrid(1, 2, wx.GridSelectionMode.wxGridSelectRows);
      gridConsulta.SetColLabelValue(0, "C�digo");
      gridConsulta.SetColSize(0, 80);
      gridConsulta.SetColLabelValue(1, "Descri��o");
      gridConsulta.SetColSize(1, 180);
      gridConsulta.Editable = false;
      gridConsulta.HideCellEditControl();
      gridConsulta.ColLabelSize = 21;
    
      labRegistro = new wx.StaticText(this, (int)idt.ID_FRMCONSULTAS_LABREGISTRO,
        "Registro 0 de 0", new Point(8, 16), new Size(144, 13), 0);
      btnLimpar = new wx.Button(this, (int)idt.ID_FRMCONSULTAS_BTNLIMPAR,
        "&Limpar", new Point(16, 13), new Size(75, 25), 0);
      btnFechar = new wx.Button(this, (int)idt.ID_FRMCONSULTAS_BTNFECHAR,
        "&Fechar", new Point(75, 13), new Size(75, 25), 0);
    
      FazLayout();
      Registros = new ArrayList();
      sSelecionado = "";
      edtDescricao.SetFocus();
		}

    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.GridSizer grid_sizer_2 = new wx.GridSizer(1, 2, 0, 0);
      wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_3 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.GridSizer grid_sizer_1 = new wx.GridSizer(2, 1, 0, 0);
      grid_sizer_1.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_1.Add(edtDescricao, 0, 0, 0);
      sizer_3.Add(grid_sizer_1, 0, wx.Direction.wxALL, 2);
      sizer_4.Add(20, 20, 0, 0, 0);
      sizer_4.Add(btnPesquisar, 0, wx.Direction.wxLEFT|
        wx.Direction.wxTOP|wx.Direction.wxBOTTOM, 5);
      sizer_3.Add(sizer_4, 0, 0, 0);
      sizer_1.Add(sizer_3, 0, wx.Direction.wxALL, 4);
      sizer_1.Add(gridConsulta, 1, wx.Stretch.wxEXPAND, 0);
      grid_sizer_2.Add(labRegistro, 0, wx.Direction.wxALL, 10);
      sizer_2.Add(btnLimpar, 0, wx.Alignment.wxALIGN_RIGHT|
        wx.Alignment.wxALIGN_BOTTOM, 8);
      sizer_2.Add(btnFechar, 0, wx.Direction.wxLEFT|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 8);
      grid_sizer_2.Add(sizer_2, 1, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 4);
      sizer_1.Add(grid_sizer_2, 0, wx.Direction.wxALL|
        wx.Stretch.wxEXPAND|wx.Alignment.wxALIGN_BOTTOM, 0);
      AutoLayout = true;
      SetSizer(sizer_1);
      sizer_1.Fit(this);
      sizer_1.SetSizeHints(this);
      Layout();
    }

    protected void Fecha(int nIndMenu) {
      if (sSelecionado.Length > 0)
        RotinasGlobais.Rotinas.sCodigoSelecionado = sSelecionado;
      else
        RotinasGlobais.Rotinas.sCodigoSelecionado = ""; 
    
      if (nIndMenu == 0) {
        if (this.Modal)
          EndModal(0);
        else
          Close();
      } else
        frmPrincipal.fPrincipal.barraMenu.GetMenu(1).Enable(nIndMenu, true);
    }
    
    protected void LimparDados() {
      labRegistro.Label = "Registro 0 de 0";
      gridConsulta.ClearGrid();
      gridConsulta.DeleteRows(0,gridConsulta.NumberRows-1,true);
      edtDescricao.Clear();
      edtDescricao.SetFocus();
    }

    protected void PesquisarDados(string sTextoSql, string sMensagemErro, 
        int nQtdCol) {   
      if (RotinasGlobais.Rotinas.ConsultaDadosLista(Registros, sTextoSql))
        RotinasGlobais.Rotinas.AdicionaLinhasGrid(gridConsulta, Registros, nQtdCol);
      else
        MessageDialog.MessageBox(sMensagemErro, "Erro", 
          wx.Dialog.wxOK|wx.Dialog.wxICON_ERROR );
    }
    
    protected void setLabRegistros(int nLinha) {
      if (nLinha >= 0) {
        labRegistro.Label = "Registro " + (nLinha+1).ToString() + " de " + 
          gridConsulta.NumberRows.ToString();
        sSelecionado = gridConsulta.GetCellValue(nLinha, 0);
      }
    }

	}
}
