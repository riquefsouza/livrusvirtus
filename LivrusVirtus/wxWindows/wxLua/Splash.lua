ID_TIMER = 100
ID_FRMSPLASH = 101

frmSplash_mTimer = nil

function frmSplash_Criar()
  local fSplash = wx.wxDialog(wx.wxNull, ID_FRMSPLASH, STR_TITULO, wx.wxPoint(0, 0), 
      wx.wxSize(255, 73), wx.wxNO_BORDER, "")   

  fSplash:SetClientSize(wx.wxSize(255, 73))
  fSplash:Centre()

  bmp_splash = wx.wxBitmapFromXPMData(livrusvirtus_xpm)
  frmSplash_labBmp = wx.wxStaticBitmap(fSplash, -1, bmp_splash,
    wx.wxPoint(0, 0), wx.wxSize(254, 72))

  frmSplash_mTimer = wx.wxTimer(fSplash, ID_TIMER)
  frmSplash_mTimer:Start(1000)

  fSplash:ConnectEvent(ID_TIMER, wx.wxEVT_TIMER, 
    function (event)
      frmSplash_mTimer:Stop()
      fSplash:Close()     
    end )

  fSplash:ConnectEvent(ID_FRMSPLASH,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      frmLogin:Show(wx.TRUE)
      --fSplash:Destroy()
      event:Skip()
    end )
  
  return fSplash
end

frmSplash = frmSplash_Criar()
