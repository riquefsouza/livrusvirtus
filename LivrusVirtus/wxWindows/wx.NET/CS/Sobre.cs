using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmSobre : wx.Dialog
	{
		public static frmSobre fSobre = null;

		private enum idt 
    { ID_FRMSOBRE_LABBMP = 300, ID_FRMSOBRE_LABVERSAO, 
      ID_FRMSOBRE_LABDIREITOS, ID_FRMSOBRE_LABSISTEMA, ID_FRMSOBRE_BTNOK	}
    private wx.StaticBitmap labBmp;
    private wx.StaticText labVersao;
    private wx.StaticText labDireitos;
    private wx.StaticText labSistema;
    private wx.Button btnOk;

		public frmSobre( Window parent )
			: base(parent, -1, "Sobre o Sistema", new Point(498, 310), 
      new Size(306, 240), wxDEFAULT_DIALOG_STYLE,"") {

      this.SetIcon(new wx.Icon( "xpms/livrus.xpm" ));
      this.Centre(wx.Orientation.wxBOTH);

    	labBmp = new wx.StaticBitmap(this, (int)idt.ID_FRMSOBRE_LABBMP, 
        new wx.Bitmap("xpms/livrusvirtus.xpm"),
        new Point(24, 20), new Size(254, 72));
    	labVersao = new wx.StaticText(this, (int)idt.ID_FRMSOBRE_LABVERSAO, 
        "Versão: 1.0.0", new Point(200, 96), new Size(63, 13) );
    	labDireitos = new wx.StaticText(this, (int)idt.ID_FRMSOBRE_LABDIREITOS, 
        "Todos os diretos reservados para: Henrique F. de Souza", 
        new Point(16, 112), new Size(266, 13) );
    	labSistema = new wx.StaticText(this, (int)idt.ID_FRMSOBRE_LABSISTEMA, 
        "Sistema integrante do projeto Livrus Virtus, " +
        "versão programada em C# usando a wx.NET.", 
        new Point(16, 131), new Size(264, 29), wx.Alignment.wxALIGN_CENTRE);
    	btnOk = new wx.Button(this, wxID_OK, "&Ok", 
        new Point(111, 180), new Size(75, 25));
    
    	btnOk.SetDefault();
    	FazLayout();
		}

    private void FazLayout() {
    	wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
    	wx.StaticBoxSizer sizer_2= new wx.StaticBoxSizer(
        new wx.StaticBox(this, -1,""), wx.Orientation.wxVERTICAL);
    	sizer_2.Add(labBmp, 0, wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 0);
    	sizer_2.Add(labVersao, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
    	sizer_2.Add(labDireitos, 0, wx.Direction.wxALL, 2);
    	sizer_2.Add(labSistema, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_CENTER_HORIZONTAL|
        wx.Alignment.wxALIGN_CENTER_VERTICAL, 2);
    	sizer_1.Add(sizer_2, 1, wx.Direction.wxALL|wx.Stretch.wxEXPAND, 6);
    	sizer_1.Add(btnOk, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 4);
    	this.SetSizer(sizer_1);
    	sizer_1.SetSizeHints(this);
    	sizer_1.Fit(this);
    	this.Layout();
    }

	}
}
