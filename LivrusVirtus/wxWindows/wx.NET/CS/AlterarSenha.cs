using System;
using System.Drawing;
using wx;
using System.Data.OleDb;

namespace Livrus
{
	public class frmAlterarSenha : wx.Panel
	{
		private enum idt 
    { ID_FRMALTERARSENHA_BTNFECHAR = 600, ID_FRMALTERARSENHA_BTNLIMPAR, 
      ID_FRMALTERARSENHA_BTNSALVAR, ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, 
      ID_FRMALTERARSENHA_EDTLOGIN, ID_FRMALTERARSENHA_EDTNOVASENHA, 
      ID_FRMALTERARSENHA_EDTSENHAATUAL, ID_FRMALTERARSENHA_LABCONFIRMARSENHA, 
      ID_FRMALTERARSENHA_LABLOGIN, ID_FRMALTERARSENHA_LABNOVASENHA, 
      ID_FRMALTERARSENHA_LABSENHAATUAL }

    private wx.StaticText	labLogin;
    private wx.TextCtrl edtLogin;
    private wx.StaticText labSenhaAtual;
    private wx.TextCtrl edtSenhaAtual;
    private wx.StaticText labNovaSenha;
    private wx.TextCtrl edtNovaSenha;
    private wx.StaticText labConfirmarSenha;
    private wx.TextCtrl edtConfirmarSenha;
    private wx.Button btnSalvar;
    private wx.Button btnLimpar;
    private wx.Button btnFechar;

		public frmAlterarSenha( wx.Window parent )
			: base(parent, -1, new Point(424, 292), new Size(257, 161), 
        wxTAB_TRAVERSAL,"") {
 
      ClientSize = new Size(249, 134);
      EVT_CLOSE(new EventListener( OnClose ));

    	labLogin = new wx.StaticText(this, (int)idt.ID_FRMALTERARSENHA_LABLOGIN, 
        "Login: ", new Point(8, 8), new Size(29, 13) );
    	edtLogin = new wx.TextCtrl(this, (int)idt.ID_FRMALTERARSENHA_EDTLOGIN, "", 
        new Point(8, 24), new Size(100, 21) );
    	edtLogin.Enable(false);
    	labSenhaAtual = new wx.StaticText(this, (int)idt.ID_FRMALTERARSENHA_LABSENHAATUAL, 
        "Senha atual:", new Point(112, 8), new Size(60, 13) );
    	edtSenhaAtual = new wx.TextCtrl(this, (int)idt.ID_FRMALTERARSENHA_EDTSENHAATUAL, 
        "", new Point(112, 24), new Size(100, 21), wx.TextCtrl.wxTE_PASSWORD );
    	labNovaSenha = new wx.StaticText(this, (int)idt.ID_FRMALTERARSENHA_LABNOVASENHA, 
        "Nova Senha:", new Point(8, 48), new Size(61, 13) );
    	edtNovaSenha = new wx.TextCtrl(this, (int)idt.ID_FRMALTERARSENHA_EDTNOVASENHA,
        "", new Point(8, 64), new Size(100, 21), wx.TextCtrl.wxTE_PASSWORD );
    	labConfirmarSenha = new wx.StaticText(this, 
        (int)idt.ID_FRMALTERARSENHA_LABCONFIRMARSENHA, "Confirmar senha:", 
        new Point(112, 48), new Size(79, 13) );
    	edtConfirmarSenha = new wx.TextCtrl(this, 
        (int)idt.ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "", 
        new Point(112, 64), new Size(100, 21), wx.TextCtrl.wxTE_PASSWORD );
    	btnSalvar = new wx.Button(this, (int)idt.ID_FRMALTERARSENHA_BTNSALVAR, 
        "&Salvar", new Point(8, 104), new Size(75, 25));
    	btnLimpar = new wx.Button(this, (int)idt.ID_FRMALTERARSENHA_BTNLIMPAR, 
        "&Limpar", new Point(88, 104), new Size(75, 25));
    	btnFechar = new wx.Button(this, (int)idt.ID_FRMALTERARSENHA_BTNFECHAR, 
        "&Fechar", new Point(168, 104), new Size(75, 25)); 
  
      edtLogin.Value = RotinasGlobais.Rotinas.sUsuarioLogin;
      edtSenhaAtual.MaxLength = 10;
      edtNovaSenha.MaxLength = 10;
      edtConfirmarSenha.MaxLength = 10;
  
      EVT_BUTTON((int)idt.ID_FRMALTERARSENHA_BTNSALVAR, 
        new EventListener( OnBtnSalvarClick ));
      EVT_BUTTON((int)idt.ID_FRMALTERARSENHA_BTNLIMPAR, 
        new EventListener( OnBtnLimparClick ));
      EVT_BUTTON((int)idt.ID_FRMALTERARSENHA_BTNFECHAR, 
        new EventListener( OnBtnFecharClick ));
  
    	FazLayout();
    	edtSenhaAtual.SetFocus();
		}

    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_9 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_10 = new wx.GridSizer(4, 1, 0, 0);
      wx.GridSizer grid_sizer_3 = new wx.GridSizer(4, 1, 0, 0);
      grid_sizer_3.Add(labLogin, 0, 
        wx.Direction.wxLEFT|wx.Alignment.wxALIGN_BOTTOM, 8);
      grid_sizer_3.Add(edtLogin, 0, wx.Direction.wxLEFT, 8);
      grid_sizer_3.Add(labNovaSenha, 0, 
        wx.Direction.wxLEFT|wx.Alignment.wxALIGN_BOTTOM, 8);
      grid_sizer_3.Add(edtNovaSenha, 0, wx.Direction.wxLEFT, 8);
      sizer_9.Add(grid_sizer_3, 0, 0, 0);
      grid_sizer_10.Add(labSenhaAtual, 0, 
        wx.Direction.wxLEFT|wx.Alignment.wxALIGN_BOTTOM, 4);
      grid_sizer_10.Add(edtSenhaAtual, 0, wx.Direction.wxLEFT, 4);
      grid_sizer_10.Add(labConfirmarSenha, 0, 
        wx.Direction.wxLEFT|wx.Alignment.wxALIGN_BOTTOM, 4);
      grid_sizer_10.Add(edtConfirmarSenha, 0, wx.Direction.wxLEFT, 4);
      sizer_9.Add(grid_sizer_10, 0, 0, 0);
      sizer_1.Add(sizer_9, 1, 0, 0);
      sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL, 2);
      sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL, 2);
      sizer_2.Add(btnFechar, 0, wx.Direction.wxALL, 2);
      sizer_1.Add(sizer_2, 0, wx.Direction.wxALL, 4);
      this.AutoLayout = true;
      this.SetSizer(sizer_1);
      sizer_1.Fit(this);
      sizer_1.SetSizeHints(this);
    }

		public void OnClose( object sender, Event e )	{
      Destroy();
		}

    public void OnBtnSalvarClick( object sender, Event e ){
      OleDbCommand Arquiva = new OleDbCommand();
      if (ValidaDados()) {
        if (RotinasGlobais.Rotinas.AtualizaDados(Arquiva, 
          ConsultasSQL.ConsSQL.Usuario('U', edtLogin.Value, 
          edtConfirmarSenha.Value))) {
          MessageDialog.MessageBox(Resource.STR_SENALTSUC, "Erro", 
            Dialog.wxOK|Dialog.wxICON_ERROR );
        }
      }
      e.Skip();
    }
  
    public void OnBtnLimparClick( object sender, Event e ){
      edtSenhaAtual.Clear();
      edtNovaSenha.Clear();
      edtConfirmarSenha.Clear();
      edtSenhaAtual.SetFocus();
      e.Skip();
    }
  
    public void OnBtnFecharClick( object sender, Event e ){
      this.Parent.Close(true);
      e.Skip();
    }
  
    public bool ValidaDados(){
      if (edtSenhaAtual.Value != RotinasGlobais.Rotinas.sUsuarioSenha) {
        MessageDialog.MessageBox(Resource.STR_SENNCSU, "Erro", 
          Dialog.wxOK|Dialog.wxICON_ERROR );
        return false;
      }
      if (RotinasGlobais.Rotinas.ValidaCampo(edtNovaSenha.Value,
         Resource.STR_NSENNINF)) {
        return false;
      }
      if (edtNovaSenha.Value != edtConfirmarSenha.Value) {
        MessageDialog.MessageBox(Resource.STR_NSENNCCON, "Erro", 
          Dialog.wxOK|Dialog.wxICON_ERROR );
        return false;
      }
      return true;
    }

	}
}
