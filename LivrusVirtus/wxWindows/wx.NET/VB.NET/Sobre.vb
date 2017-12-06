Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class frmSobre
		Inherits wx.Dialog

		public shared WithEvents fSobre as frmSobre

		private enum idt
      ID_FRMSOBRE_LABBMP = 300
      ID_FRMSOBRE_LABVERSAO
      ID_FRMSOBRE_LABDIREITOS
      ID_FRMSOBRE_LABSISTEMA
      ID_FRMSOBRE_BTNOK
		End Enum
    private labBmp as wx.StaticBitmap
    private labVersao as wx.StaticText 
    private labDireitos as wx.StaticText 
    private labSistema as wx.StaticText 
    private btnOk as wx.Button 

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, -1, "Sobre o Sistema", new Point(498, 310), _
      new Size(306, 240), wxDEFAULT_DIALOG_STYLE, "")

      Me.SetIcon(new wx.Icon( "xpms/livrus.xpm" ))
      Me.Centre(wx.Orientation.wxBOTH)

    	labBmp = new wx.StaticBitmap(Me, idt.ID_FRMSOBRE_LABBMP, _
        new wx.Bitmap("xpms/livrusvirtus.xpm"), _
        new Point(24, 20), new Size(254, 72))
    	labVersao = new wx.StaticText(Me, idt.ID_FRMSOBRE_LABVERSAO, _
        "Versão: 1.0.0", new Point(200, 96), new Size(63, 13) )
    	labDireitos = new wx.StaticText(Me, idt.ID_FRMSOBRE_LABDIREITOS, _
        "Todos os diretos reservados para: Henrique F. de Souza", _
        new Point(16, 112), new Size(266, 13) )
    	labSistema = new wx.StaticText(Me, idt.ID_FRMSOBRE_LABSISTEMA, _ 
        "Sistema integrante do projeto Livrus Virtus, " + _
        "versão programada em VB.NET usando a wx.NET.", _
        new Point(16, 131), new Size(264, 29), wx.Alignment.wxALIGN_CENTRE)
    	btnOk = new wx.Button(Me, wxID_OK, "&Ok", _
        new Point(111, 180), new Size(75, 25))
    
    	btnOk.SetDefault()
    	FazLayout()
    End Sub

		private sub FazLayout()
    	dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
    	dim sizer_2 as wx.StaticBoxSizer = new wx.StaticBoxSizer( _
        new wx.StaticBox(Me, -1,""), wx.Orientation.wxVERTICAL)
    	sizer_2.Add(labBmp, 0, wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 0)
    	sizer_2.Add(labVersao, 0, wx.Direction.wxALL or  _
        wx.Alignment.wxALIGN_RIGHT, 2)
    	sizer_2.Add(labDireitos, 0, wx.Direction.wxALL, 2)
    	sizer_2.Add(labSistema, 0, wx.Direction.wxALL or  _
        wx.Alignment.wxALIGN_CENTER_HORIZONTAL or  _
        wx.Alignment.wxALIGN_CENTER_VERTICAL, 2)
    	sizer_1.Add(sizer_2, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 6)
    	sizer_1.Add(btnOk, 0, wx.Direction.wxALL or  _
        wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 4)
    	Me.SetSizer(sizer_1)
    	sizer_1.SetSizeHints(Me)
    	sizer_1.Fit(Me)
    	Me.Layout()
		End Sub

	End Class

End Namespace
