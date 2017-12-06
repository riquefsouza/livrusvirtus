using System;
using System.Drawing;
using System.Collections;
using System.Data.OleDb;
using wx;

namespace Livrus
{
	public class frmVenderLivros: frmCadastros
	{
    private enum idx {
      ID_FRMVENDERLIVROS_BTNVENDER = 3000, ID_FRMVENDERLIVROS_BTNLIMPAR, 
      ID_FRMVENDERLIVROS_BTNFECHAR, ID_FRMVENDERLIVROS_BTNPCLIENTE,
      ID_FRMVENDERLIVROS_BTNPLIVRO, ID_FRMVENDERLIVROS_LSTLIVROS,
      ID_FRMVENDERLIVROS_EDTDTHRVENDA, ID_FRMVENDERLIVROS_EDTISBN, 
      ID_FRMVENDERLIVROS_EDTLIVRO, ID_FRMVENDERLIVROS_EDTPRECOTOTAL, 
      ID_FRMVENDERLIVROS_LABDTHRVENDA, ID_FRMVENDERLIVROS_LABISBN, 
      ID_FRMVENDERLIVROS_LABLIVRO, ID_FRMVENDERLIVROS_LABLIVROS, 
      ID_FRMVENDERLIVROS_LABPRECOTOTAL, ID_FRMVENDERLIVROS_BTNADLIVROS
    }

    private ArrayList slPrecos, slISBNs, slQtdEstoque;
    private double nPrecoTotal;
    private wx.StaticText labDtHrVenda;
    private wx.TextCtrl edtDtHrVenda;
    private wx.Button btnPCliente;
    private wx.StaticText labISBN;
    private wx.TextCtrl edtISBN;
    private wx.StaticText labLivro;
    private wx.TextCtrl edtLivro;
    private wx.Button btnAdLivros;
    private wx.Button btnPLivro;
    private wx.StaticText labLivros;
    private wx.ListBox lstLivros;
    private wx.StaticText labPrecoTotal;
    private wx.TextCtrl edtPrecoTotal;
    private wx.Button btnVender;

		public frmVenderLivros(wx.Window parent)
      : base(parent, TextValidatorCtrl.FILTER_NONE, false){

      slPrecos = new ArrayList();
      slISBNs = new ArrayList();
      slQtdEstoque = new ArrayList();
      btnNovo.Hide();
    
      labDtHrVenda = new wx.StaticText(this, (int)idx.ID_FRMVENDERLIVROS_LABDTHRVENDA,
        "Data/Hora Venda: ", new Point(8, 8), new Size(91, 13), 0);  
      edtDtHrVenda = new wx.TextCtrl(this, (int)idx.ID_FRMVENDERLIVROS_EDTDTHRVENDA,
        "", new Point(8, 24), new Size(128, 21), 0);
      edtDtHrVenda.Enabled = false;
    
      labCodigo.Label = "CPF: ";  
      labCodigo.SetSize(8, 48, 48, 13); 
      edtCodigo.SetSize(8, 64, 128, 21);
      edtCodigo.EVT_KILL_FOCUS(new EventListener( OnEdtCodigo_Killfocus ));
    
      labDescricao.Label = "Cliente: ";
      labDescricao.SetSize(142, 48, 56, 13);  
      edtDescricao.SetSize(142, 64, 306, 21);
      edtDescricao.Enabled = false;
     
      btnPCliente = new wx.Button(this, (int)idx.ID_FRMVENDERLIVROS_BTNPCLIENTE,
        "...", new Point(448, 64), new Size(21, 21), 0);
      
      labISBN = new wx.StaticText(this, (int)idx.ID_FRMVENDERLIVROS_LABISBN,
        "ISBN: ", new Point(8, 88), new Size(48, 13), 0);  
      edtISBN = new wx.TextCtrl(this, (int)idx.ID_FRMVENDERLIVROS_EDTISBN,
        "", new Point(8, 104), new Size(128, 21), 0);
      edtISBN.EVT_KILL_FOCUS(new EventListener( OnEdtISBN_Killfocus ));
      
      labLivro = new wx.StaticText(this, (int)idx.ID_FRMVENDERLIVROS_LABLIVRO,
        "Livro: ", new Point(142, 88), new Size(40, 13), 0);  
      edtLivro = new wx.TextCtrl(this, (int)idx.ID_FRMVENDERLIVROS_EDTLIVRO,
        "", new Point(142, 104), new Size(282, 21), 0);
      edtLivro.Enabled = false;
    
      btnAdLivros = new wx.Button(this, (int)idx.ID_FRMVENDERLIVROS_BTNADLIVROS,
      "+", new Point(424, 104), new Size(21, 21), 0);
      
      btnPLivro = new wx.Button(this, (int)idx.ID_FRMVENDERLIVROS_BTNPLIVRO,
        "...", new Point(448, 104), new Size(21, 21), 0);
      
      labLivros = new wx.StaticText(this, (int)idx.ID_FRMVENDERLIVROS_LABLIVROS,
        "Livros para vender: ", new Point(8, 128), new Size(120, 13), 0);
      
      lstLivros = new wx.ListBox(this, (int)idx.ID_FRMVENDERLIVROS_LSTLIVROS,
        new Point(8, 144), new Size(464, 96));
      
      labPrecoTotal = new wx.StaticText(this, (int)idx.ID_FRMVENDERLIVROS_LABPRECOTOTAL,
        "Preço Total: ", new Point(280, 248), new Size(61, 13), 0);  
      edtPrecoTotal = new wx.TextCtrl(this, (int)idx.ID_FRMVENDERLIVROS_EDTPRECOTOTAL,
        "R$ 0,00", new Point(344, 246), new Size(127, 21), 0);
      edtPrecoTotal.Enabled = false;
      
      btnVender = new wx.Button(this, (int)idx.ID_FRMVENDERLIVROS_BTNVENDER,
        "&Vender", new Point(239, 275), new Size(75, 25), 0);  
      btnLimpar = new wx.Button(this, (int)idx.ID_FRMVENDERLIVROS_BTNLIMPAR,
        "&Limpar", new Point(319, 275), new Size(75, 25), 0);  
      btnFechar = new wx.Button(this, (int)idx.ID_FRMVENDERLIVROS_BTNFECHAR,
        "&Fechar", new Point(399, 275), new Size(75, 25), 0);
    
      //FazLayout();
    
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true, true);
      edtCodigo.MaxLength = 14;
      edtISBN.MaxLength = 13;
      nPrecoTotal = 0;

      EVT_BUTTON((int)idx.ID_FRMVENDERLIVROS_BTNVENDER, 
        new EventListener( OnBtnVender ));
      EVT_BUTTON((int)idx.ID_FRMVENDERLIVROS_BTNLIMPAR, 
        new EventListener( OnBtnLimpar ));
      EVT_BUTTON((int)idx.ID_FRMVENDERLIVROS_BTNFECHAR, 
        new EventListener( OnBtnFechar ));
			EVT_CLOSE( new EventListener( OnClose ) );
      EVT_BUTTON((int)idx.ID_FRMVENDERLIVROS_BTNPCLIENTE, 
        new EventListener( OnBtnPCliente ));
      EVT_BUTTON((int)idx.ID_FRMVENDERLIVROS_BTNPLIVRO, 
        new EventListener( OnBtnPLivro ));
      EVT_BUTTON((int)idx.ID_FRMVENDERLIVROS_BTNADLIVROS, 
        new EventListener( OnBtnAdLivros ));
      EVT_LISTBOX_DCLICK((int)idx.ID_FRMVENDERLIVROS_LSTLIVROS, 
        new EventListener( OnLstLivros_Dblclk ));
    }

    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_6 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_8 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_7 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_5 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_8 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_7 = new wx.GridSizer(2, 1, 0, 0);
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
      sizer_2.Add(20, 20, 0, 0, 0);
      sizer_1.Add(sizer_2, 0, 0, 0);
      grid_sizer_2.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_2.Add(edtCodigo, 0, 0, 0);
      sizer_3.Add(grid_sizer_2, 0, wx.Direction.wxLEFT, 2);
      grid_sizer_3.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_3.Add(edtDescricao, 0, 0, 0);
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
      grid_sizer_7.Add(20, 20, 0, 0, 0);
      grid_sizer_7.Add(btnAdLivros, 0, 0, 0);
      sizer_4.Add(grid_sizer_7, 1, wx.Stretch.wxEXPAND, 0);
      grid_sizer_8.Add(20, 20, 0, 0, 0);
      grid_sizer_8.Add(btnPLivro, 0, 0, 0);
      sizer_4.Add(grid_sizer_8, 0, 0, 0);
      sizer_1.Add(sizer_4, 0, 0, 0);
      sizer_5.Add(labLivros, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      sizer_5.Add(lstLivros, 1, wx.Direction.wxALL|wx.Stretch.wxEXPAND, 1);
      sizer_1.Add(sizer_5, 1, wx.Stretch.wxEXPAND, 0);
      sizer_7.Add(labPrecoTotal, 0, wx.Direction.wxALL, 2);
      sizer_7.Add(edtPrecoTotal, 0, wx.Direction.wxALL, 2);
      sizer_6.Add(sizer_7, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_8.Add(btnVender, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_8.Add(btnLimpar, 0, wx.Direction.wxALL| 
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_8.Add(btnFechar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_6.Add(sizer_8, 0, wx.Direction.wxALL, 2);
      sizer_1.Add(sizer_6, 0, wx.Alignment.wxALIGN_RIGHT|
        wx.Alignment.wxALIGN_BOTTOM, 0);
      AutoLayout = true;
      SetSizer(sizer_1);
      sizer_1.Fit(this);
      sizer_1.SetSizeHints(this);
    }

    private void LimpaDados() {
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true, true);
      edtCodigo.Clear();
      edtDescricao.Clear();
      edtISBN.Clear();
      edtLivro.Clear();
      lstLivros.Clear();
      nPrecoTotal = 0;
      edtPrecoTotal.Value = "R$ 0,00";
      edtCodigo.SetFocus();
    }

		private bool ValidaDados(){
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, 
        Resource.STR_CPFNINF))
        return false;
      if (lstLivros.Count==0) {
        wx.MessageDialog.MessageBox(Resource.STR_LIVVENNINF, "Erro", 
          wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
        return false;
      }
			return true;
		}

    private bool SalvaLista(){
      string sCPF, sISBN, sPrecoTotal, sDataHora, sQtdEstoque, sDTHR;
      int nCont, nQtd, nQtdEstoque;
      OleDbCommand Arquiva = new OleDbCommand();
    
      nQtd = lstLivros.Count;
      sCPF = edtCodigo.Value;
      sPrecoTotal = Convert.ToString(nPrecoTotal);
      
      sDTHR = edtDtHrVenda.Value;
      sDataHora = RotinasGlobais.Rotinas.ConverteDataHoraStr(sDTHR,
        "MM/dd/YYYY hh:mm:ss");
      
      for (nCont=0; nCont < nQtd; nCont++) {
        sISBN = slISBNs[nCont].ToString();
      
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva, 
          ConsultasSQL.ConsSQL.Venda('I',sISBN, sCPF, sDataHora,
          RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal,false),""));
      
        nQtdEstoque = Int32.Parse(slQtdEstoque[nCont].ToString());
        if (nQtdEstoque >= 0) 
          nQtdEstoque = nQtdEstoque - 1;
        sQtdEstoque = Convert.ToString(nQtdEstoque);
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva, 
          ConsultasSQL.ConsSQL.Venda('U',sISBN, "","","", sQtdEstoque));
      }
      return true;
    }

    private void OnClose( object sender, Event e ){
      this.Parent.Close();
      e.Skip();
    }

    private void OnBtnFechar( object sender, Event e ){
      this.Close(true);
      e.Skip();
    }

    private void OnEdtCodigo_Killfocus( object sender, Event e ){
      string sCliente;
      ArrayList ConsCampo = new ArrayList();    
    
      if (edtCodigo.Value.Length > 0) {
        if (RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.Value)) {
          sCliente = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
            ConsultasSQL.ConsSQL.Cliente('S', edtCodigo.Value,
            "","","","","","","","",""),Resource.STR_CLINENC); 
          if (sCliente.Length==0) {
            edtCodigo.Clear();
            edtCodigo.SetFocus();
          } else
             edtDescricao.Value = sCliente;
        } else {
          wx.MessageDialog.MessageBox(Resource.STR_CPFINV, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          edtCodigo.Clear();
          edtCodigo.SetFocus();
        }
      } else
         edtDescricao.Clear();
    }
    
    private void OnBtnPCliente( object sender, Event e ){
      frmConClientes fConClientes = new frmConClientes(this);
      fConClientes.ShowModal();
      edtCodigo.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCodigo_Killfocus(null,null);
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
               RotinasGlobais.Rotinas.sQtdEstoque = ConsCampo[3].ToString();
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
    
    private void OnBtnAdLivros( object sender, Event e ){
      double nPreco; 
      string sLivros, sISBN, sEdtLivro, sPrecoTotal;
    
     sISBN = edtISBN.Value;
     sEdtLivro = edtLivro.Value;
     if (sISBN.Length > 0) {
       sLivros = sISBN + " - " + sEdtLivro + " - R$ " + 
        RotinasGlobais.Rotinas.sPreco;
       if (RotinasGlobais.Rotinas.PesquisaItemLista(lstLivros, sLivros)==-1) {
         slISBNs.Add(sISBN);
         slPrecos.Add(RotinasGlobais.Rotinas.sPreco);
         slQtdEstoque.Add(RotinasGlobais.Rotinas.sQtdEstoque);
         lstLivros.Append(sLivros);
         nPreco = Double.Parse(RotinasGlobais.Rotinas.sPreco);
         nPrecoTotal = nPrecoTotal + nPreco;
       }
       edtISBN.Clear();
       edtLivro.Clear();
       sPrecoTotal = "R$ " + Convert.ToString(nPrecoTotal);
       edtPrecoTotal.Value = 
         RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal,true);
     }
     e.Skip();
    }
    
    private void OnLstLivros_Dblclk( object sender, Event e ){
      string sPrecoTotal;
      double nPreco;
      int nSelIndice;
    
      if (lstLivros.Count > 0) {   
        nSelIndice = lstLivros.Selection;
        if (lstLivros.Selected(nSelIndice)) {
          nPreco = Double.Parse(slPrecos[nSelIndice].ToString());
          nPrecoTotal = nPrecoTotal-nPreco;     
          sPrecoTotal = "R$ " + Convert.ToString(nPrecoTotal);
          edtPrecoTotal.Value = 
            RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal,true);
          slISBNs.RemoveAt(nSelIndice);
          slPrecos.RemoveAt(nSelIndice);
          slQtdEstoque.RemoveAt(nSelIndice);
          lstLivros.Delete(nSelIndice);
        }	
      }
      e.Skip();
    }    
    
    private void OnBtnVender( object sender, Event e ){
      if (ValidaDados()) {
        if (SalvaLista()) {
          wx.MessageDialog.MessageBox(Resource.STR_VENRESUC, 
          Resource.STR_TITULO, wx.Dialog.wxOK | wx.Dialog.wxICON_INFORMATION);
          LimpaDados();
        }
      }	
      e.Skip();
    }         
    
    private void OnBtnLimpar( object sender, Event e ){
      LimpaDados();
      e.Skip();
    }
	}
}
