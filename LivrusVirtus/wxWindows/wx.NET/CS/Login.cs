using System;
using System.Drawing;
using wx;
using System.Data.OleDb;

namespace Livrus
{
	public class frmLogin : wx.Dialog
	{
		public static frmLogin fLogin = null;

		private enum idt 
    { ID_FRMLOGIN_BMPLOGIN = 200, ID_FRMLOGIN_LABLOGIN, ID_FRMLOGIN_EDTLOGIN, 
      ID_FRMLOGIN_LABSENHA, ID_FRMLOGIN_EDTSENHA, ID_FRMLOGIN_BTNLOGIN,
      ID_FRMLOGIN_BTNCANCELAR	}
    private wx.StaticBitmap bmpLogin;
    private wx.StaticText labLogin;
    private wx.TextCtrl edtLogin;
    private wx.StaticText labSenha;
    private wx.TextCtrl edtSenha;
    private wx.Button btnLogin;
    private wx.Button btnCancelar;
    private bool bFechar;    

		public frmLogin( Window parent )
			: base(parent, -1, "Login do Sistema", new Point(546, 346), 
        new Size(211, 168), wxDEFAULT_DIALOG_STYLE,"") {

      bmpLogin = new wx.StaticBitmap(this, (int)idt.ID_FRMLOGIN_BMPLOGIN, 
        new wx.Bitmap("xpms/login.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM),
        new Point(8, 8), new Size(90, 90));
    	labLogin = new wx.StaticText(this, (int)idt.ID_FRMLOGIN_LABLOGIN, 
        "Login:", new Point(112, 8), new Size(29, 13) );
    	edtLogin = new wx.TextCtrl(this, (int)idt.ID_FRMLOGIN_EDTLOGIN, "", 
        new Point(112, 24), new Size(80, 21) );
      edtLogin.MaxLength = 10;
    	labSenha = new wx.StaticText(this, (int)idt.ID_FRMLOGIN_LABSENHA, 
        "Senha:", new Point(112, 56), new Size(34, 13) );
    	edtSenha = new wx.TextCtrl(this, (int)idt.ID_FRMLOGIN_EDTSENHA, "", 
        new Point(112, 72), new Size(80, 21), wx.TextCtrl.wxTE_PASSWORD );
      edtSenha.MaxLength = 10;
    	btnLogin = new wx.Button(this, (int)idt.ID_FRMLOGIN_BTNLOGIN, "&Login",
        new Point(24, 107), new Size(75, 25));
    	btnCancelar = new wx.Button(this, (int)idt.ID_FRMLOGIN_BTNCANCELAR, "&Cancelar",
        new Point(112, 107), new Size(75, 25));
    	btnLogin.SetDefault();
      
      bFechar = false;
      FazLayout();

			EVT_CLOSE( new EventListener( OnClose ) );
      EVT_BUTTON((int)idt.ID_FRMLOGIN_BTNLOGIN, 
        new EventListener( OnBtnLoginClick ) );
      EVT_BUTTON((int)idt.ID_FRMLOGIN_BTNCANCELAR, 
        new EventListener( OnBtnCancelarClick ) );
		}

    private void FazLayout() {
    	wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
    	wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
    	wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
    	wx.BoxSizer sizer_3 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
    	sizer_2.Add(bmpLogin, 0, wx.Direction.wxALL, 6);
    	sizer_3.Add(labLogin, 0, wx.Direction.wxALL|wx.Alignment.wxALIGN_BOTTOM, 2);
    	sizer_3.Add(edtLogin, 0, wx.Direction.wxALL, 2);
    	sizer_3.Add(labSenha, 0, wx.Direction.wxALL|wx.Alignment.wxALIGN_BOTTOM, 2);
    	sizer_3.Add(edtSenha, 0, wx.Direction.wxALL, 2);
    	sizer_2.Add(sizer_3, 0, wx.Direction.wxALL, 6);
    	sizer_1.Add(sizer_2, 0, 0, 3);
    	sizer_4.Add(btnLogin, 0, wx.Direction.wxLEFT|wx.Direction.wxTOP|
        wx.Direction.wxBOTTOM|wx.Alignment.wxALIGN_BOTTOM, 10);
    	sizer_4.Add(btnCancelar, 0, wx.Direction.wxALL|wx.Alignment.wxALIGN_BOTTOM, 10);
    	sizer_1.Add(sizer_4, 0, 
        wx.Direction.wxALL|wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 1);
    	this.SetSizer(sizer_1);
    	sizer_1.Fit(this);
    	sizer_1.SetSizeHints(this);
    	this.Layout();
    	this.Centre();
    }

		public void OnClose( object sender, Event e ){
      if (bFechar)
        Destroy();
      else {
        Destroy();
        frmPrincipal.fPrincipal.Destroy();
      }
    }

		public void OnBtnLoginClick( object sender, Event e ){
      OleDbCommand Consulta = new OleDbCommand();
      RotinasGlobais.Rotinas.sUsuarioLogin = edtLogin.Value;
      RotinasGlobais.Rotinas.sUsuarioSenha = edtSenha.Value;
  
      if (RotinasGlobais.Rotinas.ConsultaDados(Consulta, 
         ConsultasSQL.ConsSQL.Usuario('S', RotinasGlobais.Rotinas.sUsuarioLogin, 
         RotinasGlobais.Rotinas.sUsuarioSenha))) {
        RotinasGlobais.Rotinas.sBarraLogin = Resource.STR_USUARIO + 
          RotinasGlobais.Rotinas.sUsuarioLogin;
        frmPrincipal.fPrincipal.SetStatusText(RotinasGlobais.Rotinas.sBarraLogin, 0);
        bFechar = true;
        this.Close(true);
  			frmPrincipal.fPrincipal.Show( true );
      } else
        MessageDialog.MessageBox(Resource.STR_LOGSENINC, "Erro", 
          Dialog.wxOK|Dialog.wxICON_ERROR );
      e.Skip();
    }

		public void OnBtnCancelarClick( object sender, Event e ){
      bFechar = false;
      this.Close(true);
      e.Skip();
    }

	}
}
