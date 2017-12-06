ID_FRMSOBRE_LABBMP = 300
ID_FRMSOBRE_LABVERSAO = 301
ID_FRMSOBRE_LABDIREITOS = 302
ID_FRMSOBRE_LABSISTEMA = 303
ID_FRMSOBRE_BTNOK = 304

local frmSobre_labBmp
local frmSobre_labVersao
local frmSobre_labDireitos
local frmSobre_labSistema
local frmSobre_btnOk

function frmSobre_Criar()
  local fSobre = wx.wxDialog(wx.wxNull, -1, STR_OPSOBRE, wx.wxPoint(498, 310),
      wx.wxSize(306, 240), wx.wxDEFAULT_DIALOG_STYLE, "") 

  fSobre:Centre(wx.wxBOTH)
  
   bmp_sobre = wx.wxBitmapFromXPMData(livrusvirtus_xpm)
	frmSobre_labBmp = wx.wxStaticBitmap(fSobre, ID_FRMSOBRE_LABBMP, bmp_sobre,
        wx.wxPoint(24, 20), wx.wxSize(254, 72) )       
	frmSobre_labVersao = wx.wxStaticText(fSobre, ID_FRMSOBRE_LABVERSAO,
    "Versão: 1.0.0", wx.wxPoint(200, 96), wx.wxSize(63, 13) )
	frmSobre_labDireitos = wx.wxStaticText(fSobre, ID_FRMSOBRE_LABDIREITOS,
    "Todos os diretos reservados para: Henrique F. de Souza",
    wx.wxPoint(16, 112), wx.wxSize(266, 13) )
	frmSobre_labSistema = wx.wxStaticText(fSobre, ID_FRMSOBRE_LABSISTEMA, 
    "Sistema integrante do projeto Livrus Virtus, " ..
    "versão programada usando a wxLua.",
    wx.wxPoint(16, 131), wx.wxSize(264, 29), wx.wxALIGN_CENTRE)
	frmSobre_btnOk = wx.wxButton(fSobre, wx.wxID_OK, "&Ok",
    wx.wxPoint(111, 180), wx.wxSize(75, 25))

	frmSobre_btnOk:SetDefault()
	frmSobre_FazLayout(fSobre)

  return fSobre
end

function frmSobre_FazLayout(parent)
	sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)	
	sizer_2 = wx.wxStaticBoxSizer(wx.wxStaticBox(parent, -1,""), wx.wxVERTICAL)
	sizer_2:AddWindow(frmSobre_labBmp, 0, wx.wxALIGN_CENTER_HORIZONTAL, 0)
	sizer_2:AddWindow(frmSobre_labVersao, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
	sizer_2:AddWindow(frmSobre_labDireitos, 0, wx.wxALL, 2)
	sizer_2:AddWindow(frmSobre_labSistema, 0, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL + 
        wx.wxALIGN_CENTER_VERTICAL, 2)
	sizer_1:AddSizer(sizer_2, 1, wx.wxALL  + wx.wxEXPAND, 6)
	sizer_1:AddWindow(frmSobre_btnOk, 0, wx.wxALL + wx.wxALIGN_CENTER_HORIZONTAL, 4)
	parent:SetSizer(sizer_1)
	sizer_1:SetSizeHints(parent)
	sizer_1:Fit(parent)
	parent:Layout()
end
