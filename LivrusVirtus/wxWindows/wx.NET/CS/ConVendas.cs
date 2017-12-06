using System;
using System.Drawing;
using System.Collections;
using System.Data.OleDb;
using wx;

namespace Livrus
{
	public class frmConVendas: wx.Panel
	{
    private enum idx {
      ID_FRMCONVENDAS_BTNPESQUISAR = 3100, ID_FRMCONVENDAS_BTNLIMPAR, 
      ID_FRMCONVENDAS_BTNFECHAR, ID_FRMCONVENDAS_BTNPCLIENTE,
      ID_FRMCONVENDAS_BTNPLIVRO, ID_FRMCONVENDAS_GRIDVENDAS,
      ID_FRMCONVENDAS_EDTDTHRVENDA, ID_FRMCONVENDAS_EDTISBN, 
      ID_FRMCONVENDAS_EDTLIVRO, ID_FRMCONVENDAS_EDTPRECOTOTAL, 
      ID_FRMCONVENDAS_LABDTHRVENDA, ID_FRMCONVENDAS_LABISBN, 
      ID_FRMCONVENDAS_LABLIVRO, ID_FRMCONVENDAS_LABPRECOTOTAL,
      ID_FRMCONVENDAS_LABCPF, ID_FRMCONVENDAS_EDTCPF, 
      ID_FRMCONVENDAS_LABCLIENTE, ID_FRMCONVENDAS_EDTCLIENTE, 
      ID_FRMCONVENDAS_LABREGISTRO
    }
  
    private wx.StaticText labDtHrVenda;
    private wx.TextCtrl edtDtHrVenda;
    private wx.StaticText labCPF;
    private wx.TextCtrl edtCPF;
    private wx.StaticText labCliente;
    private wx.TextCtrl edtCliente;
    private wx.Button btnPCliente;
    private wx.StaticText labISBN;
    private wx.TextCtrl edtISBN;
    private wx.StaticText labLivro;
    private wx.TextCtrl edtLivro;
    private wx.Button btnPLivro;
    private wx.StaticText labRegistro;
    private wx.Grid gridVendas;
    private wx.StaticText labPrecoTotal;
    private wx.TextCtrl edtPrecoTotal;
    private wx.Button btnPesquisar;
    private wx.Button btnLimpar;
    private wx.Button btnFechar;

		public frmConVendas(wx.Window parent)
      : base(parent, -1, new Point(0, 0), new Size(480, 310)){
    
      labDtHrVenda = new wx.StaticText(this, (int)idx.ID_FRMCONVENDAS_LABDTHRVENDA,
        "Data/Hora Venda: ", new Point(8, 8), new Size(91, 13), 0);  
      edtDtHrVenda = new wx.TextCtrl(this, (int)idx.ID_FRMCONVENDAS_EDTDTHRVENDA,
        "", new Point(8, 24), new Size(128, 21), 0);
      edtDtHrVenda.EVT_KILL_FOCUS(new EventListener( OnEdtDtHrVenda_Killfocus ));
    
      btnPesquisar = new wx.Button(this, (int)idx.ID_FRMCONVENDAS_BTNPESQUISAR,
        "&Pesquisar", new Point(144, 22), new Size(75, 25), 0);
    
      labCPF = new wx.StaticText(this, (int)idx.ID_FRMCONVENDAS_LABCPF,
        "CPF: ", new Point(8, 48), new Size(48, 13), 0);  
      edtCPF = new wx.TextCtrl(this, (int)idx.ID_FRMCONVENDAS_EDTCPF,
        "", new Point(8, 64), new Size(128, 21), 0);
      edtCPF.EVT_KILL_FOCUS(new EventListener( OnEdtCPF_Killfocus ));
    
      labCliente = new wx.StaticText(this, (int)idx.ID_FRMCONVENDAS_LABCLIENTE,
        "Cliente: ", new Point(142, 48), new Size(56, 13), 0);  
      edtCliente = new wx.TextCtrl(this, (int)idx.ID_FRMCONVENDAS_EDTCLIENTE,
        "", new Point(142, 64), new Size(306, 21), 0);
      edtCliente.Enabled = false;
     
      btnPCliente = new wx.Button(this, (int)idx.ID_FRMCONVENDAS_BTNPCLIENTE,
        "...", new Point(448, 64), new Size(21, 21), 0);
      
      labISBN = new wx.StaticText(this, (int)idx.ID_FRMCONVENDAS_LABISBN,
        "ISBN: ", new Point(8, 88), new Size(48, 13), 0);  
      edtISBN = new wx.TextCtrl(this, (int)idx.ID_FRMCONVENDAS_EDTISBN,
        "", new Point(8, 104), new Size(128, 21), 0);
      edtISBN.EVT_KILL_FOCUS(new EventListener( OnEdtISBN_Killfocus ));
      
      labLivro = new wx.StaticText(this, (int)idx.ID_FRMCONVENDAS_LABLIVRO,
        "Livro: ", new Point(142, 88), new Size(40, 13), 0);  
      edtLivro = new wx.TextCtrl(this, (int)idx.ID_FRMCONVENDAS_EDTLIVRO,
        "", new Point(142, 104), new Size(306, 21), 0);
      edtLivro.Enabled = false;
    
      btnPLivro = new wx.Button(this, (int)idx.ID_FRMCONVENDAS_BTNPLIVRO,
        "...", new Point(448, 104), new Size(21, 21), 0);
    
      this.gridVendas = new wx.Grid(this, (int)idx.ID_FRMCONVENDAS_GRIDVENDAS, 
        new Point(0, 136), new Size(355, 122), wxSUNKEN_BORDER);
      this.gridVendas.CreateGrid(1, 6, wx.GridSelectionMode.wxGridSelectRows);
      this.gridVendas.HideCellEditControl();
      this.gridVendas.ColLabelSize = 21;
    
      this.labRegistro = new wx.StaticText(this, (int)idx.ID_FRMCONVENDAS_LABREGISTRO,
        "Registro 0 de 0", new Point(8, 16), new Size(144, 13), 0);
    
      labPrecoTotal = new wx.StaticText(this, (int)idx.ID_FRMCONVENDAS_LABPRECOTOTAL,
        "Preço Total: ", new Point(280, 248), new Size(61, 13), 0);  
      edtPrecoTotal = new wx.TextCtrl(this, (int)idx.ID_FRMCONVENDAS_EDTPRECOTOTAL,
        "", new Point(344, 246), new Size(127, 21), 0);
      edtPrecoTotal.Enabled = false;
    
      this.btnLimpar = new wx.Button(this, (int)idx.ID_FRMCONVENDAS_BTNLIMPAR,
        "&Limpar", new Point(16, 13), new Size(75, 25), 0);
      this.btnFechar = new wx.Button(this, (int)idx.ID_FRMCONVENDAS_BTNFECHAR,
        "&Fechar", new Point(75, 13), new Size(75, 25), 0);
    
      FazLayout();
    
      int[] nLargura = new int[6] { 120, 100, 220, 100, 280, 80 };
      string[] sRotulos = new string[6] { "Data/Hora Venda", "CPF", "Cliente", 
       "ISBN", "Livro", "Preço" };
      RotinasGlobais.Rotinas.AdicionaColunasGrid(gridVendas, 0, 6, nLargura, sRotulos);
      gridVendas.Editable = false;
      edtCPF.MaxLength = 14;
      edtISBN.MaxLength = 13;
      edtPrecoTotal.Value = "R$ 0,00";
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,true);

      EVT_BUTTON((int)idx.ID_FRMCONVENDAS_BTNPESQUISAR, new EventListener( OnBtnPesquisar ));
      EVT_BUTTON((int)idx.ID_FRMCONVENDAS_BTNLIMPAR, new EventListener( OnBtnLimpar ));
      EVT_BUTTON((int)idx.ID_FRMCONVENDAS_BTNFECHAR, new EventListener( OnBtnFechar ));
      EVT_CLOSE( new EventListener( OnClose ));
      EVT_BUTTON((int)idx.ID_FRMCONVENDAS_BTNPCLIENTE, new EventListener( OnBtnPCliente ));
      EVT_BUTTON((int)idx.ID_FRMCONVENDAS_BTNPLIVRO, new EventListener( OnBtnPLivro ));
      EVT_GRID_SELECT_CELL( new EventListener( OnGridSelectCell ));
      EVT_GRID_LABEL_LEFT_CLICK( new EventListener( OnGridLabelLeftClick ));
    }

    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_6 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.GridSizer sizer_22 = new wx.GridSizer(1, 2, 0, 0);
      wx.BoxSizer sizer_23 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_8 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_7 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_24 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_8 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_6 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_5 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_3 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_4 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_3 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_2 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_1 = new wx.GridSizer(2, 1, 0, 0);
      grid_sizer_1.Add(labDtHrVenda, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_1.Add(edtDtHrVenda, 0, 0, 0);
      sizer_2.Add(grid_sizer_1, 0, wx.Direction.wxLEFT, 2);
      sizer_2.Add(btnPesquisar, 0, wx.Direction.wxLEFT|
        wx.Direction.wxTOP|wx.Alignment.wxALIGN_BOTTOM, 10);
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
      sizer_1.Add(gridVendas, 1, wx.Direction.wxALL|wx.Stretch.wxEXPAND, 2);
      sizer_24.Add(labRegistro, 0, wx.Direction.wxALL, 4);
      sizer_24.Add(20, 20, 0, 0, 0);
      sizer_22.Add(sizer_24, 0, 0, 0);
      sizer_7.Add(labPrecoTotal, 0, wx.Direction.wxALL, 2);
      sizer_7.Add(edtPrecoTotal, 0, wx.Direction.wxALL, 2);
      sizer_23.Add(sizer_7, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_8.Add(btnLimpar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_8.Add(btnFechar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_23.Add(sizer_8, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_22.Add(sizer_23, 1, wx.Alignment.wxALIGN_RIGHT|
        wx.Alignment.wxALIGN_BOTTOM, 0);
      sizer_6.Add(sizer_22, 0, wx.Stretch.wxEXPAND, 0);
      sizer_1.Add(sizer_6, 0, wx.Stretch.wxEXPAND, 0);
      AutoLayout = true;
      SetSizer(sizer_1);
      sizer_1.Fit(this);
      sizer_1.SetSizeHints(this);
    }

    private void OnBtnLimpar( object sender, Event e ){  
      edtCPF.Clear();
      edtCliente.Clear();
      edtISBN.Clear();
      edtLivro.Clear();
      gridVendas.ClearGrid();
      gridVendas.DeleteRows(0, gridVendas.NumberRows-1,true);
      edtPrecoTotal.Value = "R$ 0,00";
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,true);
      labRegistro.Label = "Registro 0 de 0";
      edtDtHrVenda.SetFocus();
      e.Skip();
    }

    private string ConsVenda(char sOpcao){
      string sISBN, sCPF, sDataHora, sret;
    
      if (edtDtHrVenda.Value.Length > 0)
        sDataHora = RotinasGlobais.Rotinas.ConverteDataHoraStr(edtDtHrVenda.Value, 
          "MM/dd/yyyy hh:mm:ss");
      else
        sDataHora = "";
    
      sISBN = edtISBN.Value;
      sCPF = edtCPF.Value;
    
      if (sOpcao=='L')
        sret = ConsultasSQL.ConsSQL.Venda('S',"ZERO","","","","");
      else
        sret = ConsultasSQL.ConsSQL.Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");
    
     return sret;
    }

    private void OnClose( object sender, Event e ){
      this.Parent.Close();
      e.Skip();
    }

    private void OnBtnFechar( object sender, Event e ){
      this.Close(true);
      e.Skip();
    }
    
    private void OnBtnPesquisar( object sender, Event e ){
      ArrayList ConsTotal = new ArrayList();
      ArrayList lstLinhas = new ArrayList();
      ArrayList lstTotal;
      string sPrecoTotal;
      double nTemp;
    
      if (RotinasGlobais.Rotinas.ConsultaDadosLista(lstLinhas, ConsVenda('S'))) {
        RotinasGlobais.Rotinas.AdicionaLinhasGrid(gridVendas, lstLinhas, 6);
    
        if (RotinasGlobais.Rotinas.ConsultaDadosLista(ConsTotal, ConsVenda('P'))) {
          if (ConsTotal.Count > 0) {
            lstTotal = (ArrayList)ConsTotal[0];
            nTemp = Double.Parse(lstTotal[0].ToString()); 
            sPrecoTotal = nTemp.ToString("C"); 
            edtPrecoTotal.Value = sPrecoTotal;
          }
        }    
      } else {
         wx.MessageDialog.MessageBox(Resource.STR_VENNENC, "Erro", 
          wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
      }
    }
    
    private void OnEdtCPF_Killfocus( object sender, Event e ){
      string sCliente;
      ArrayList ConsCampo = new ArrayList();    
    
      if (edtCPF.Value.Length > 0) {
        if (RotinasGlobais.Rotinas.ValidaCPF(edtCPF.Value)) {      
          sCliente = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
            ConsultasSQL.ConsSQL.Cliente('S',edtCPF.Value,
            "","","","","","","","",""),Resource.STR_CLINENC); 
          if (sCliente.Length==0) {
            edtCPF.Clear();
            edtCPF.SetFocus();
          } else
             edtCliente.Value = sCliente;
        } else {
          wx.MessageDialog.MessageBox(Resource.STR_CPFINV, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          edtCPF.Clear();
          edtCPF.SetFocus();
        }
      } else
         edtCliente.Clear();
    }
    
    private void OnBtnPCliente( object sender, Event e ){
      frmConClientes fConClientes = new frmConClientes(this);
      fConClientes.ShowModal();
      edtCPF.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCPF_Killfocus(null,null);	
      e.Skip();
    }
    
    private void OnEdtISBN_Killfocus( object sender, Event e ){
      string sLivro;
      int nQtdEstoque;
      ArrayList ConsCampo = new ArrayList();
    
      if (edtISBN.Value.Length > 0) {
        if (RotinasGlobais.Rotinas.ValidaISBN(edtISBN.Value)) {      
          sLivro = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
            ConsultasSQL.ConsSQL.Livro('Q',edtISBN.Value,
            "","","","","","","","",""),Resource.STR_LIVNENC);
          if (sLivro.Length==0) {
            edtISBN.Clear();
          	edtISBN.SetFocus();
          } else {
             edtLivro.Value = sLivro;
             nQtdEstoque = Int32.Parse(ConsCampo[3].ToString());
             if (nQtdEstoque > 0) {
               RotinasGlobais.Rotinas.sPreco = ConsCampo[2].ToString();
             } else
               wx.MessageDialog.MessageBox(Resource.STR_LIVNEST, "Erro", 
                 wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          }
        } else {
          wx.MessageDialog.MessageBox(Resource.STR_ISBNINV, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          edtISBN.Clear();
          edtISBN.SetFocus();
        }
      } else
         edtLivro.Clear();
    }
    
    private void OnBtnPLivro( object sender, Event e ){
      frmConLivros fConLivros = new frmConLivros(this);
      fConLivros.ShowModal();
      edtISBN.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtISBN_Killfocus(null,null);	
      e.Skip();
    }
    
    private void setLabRegistros(int nLinha) {
      if (nLinha >= 0) {
        labRegistro.Label = "Registro " + (nLinha+1).ToString() + 
          " de " + gridVendas.NumberRows.ToString();
      }
    }
    
    private void OnGridSelectCell( object sender, Event e ){
      wx.GridEvent evt = (wx.GridEvent)e;
      setLabRegistros(evt.Row);
      e.Skip();
    }
    
    private void OnGridLabelLeftClick( object sender, Event e ){
      wx.GridEvent evt = (wx.GridEvent)e;
      setLabRegistros(evt.Row);
      e.Skip();
    }
    
    private void OnEdtDtHrVenda_Killfocus( object sender, Event e ){
      if (edtDtHrVenda.Value.Length > 0) {
        if (!RotinasGlobais.Rotinas.validaDataHora(edtDtHrVenda.Value, false)) {
          wx.MessageDialog.MessageBox(Resource.STR_DTHRINV, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
      		edtDtHrVenda.SetFocus();
        }
      } 
    }

	}
}
