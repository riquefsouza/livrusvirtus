Imports System
Imports System.Drawing
Imports wx
Imports System.Data.OleDb

Namespace Livrus

	Public Class frmAlterarSenha
		Inherits wx.Panel

		public shared WithEvents fAlterarSenha as frmAlterarSenha

		private enum idt
      ID_FRMALTERARSENHA_BTNFECHAR = 600
      ID_FRMALTERARSENHA_BTNLIMPAR 
      ID_FRMALTERARSENHA_BTNSALVAR
      ID_FRMALTERARSENHA_EDTCONFIRMARSENHA
      ID_FRMALTERARSENHA_EDTLOGIN
      ID_FRMALTERARSENHA_EDTNOVASENHA
      ID_FRMALTERARSENHA_EDTSENHAATUAL
      ID_FRMALTERARSENHA_LABCONFIRMARSENHA
      ID_FRMALTERARSENHA_LABLOGIN
      ID_FRMALTERARSENHA_LABNOVASENHA
      ID_FRMALTERARSENHA_LABSENHAATUAL
		End Enum
    private labLogin as wx.StaticText
    private edtLogin as wx.TextCtrl
    private labSenhaAtual as wx.StaticText
    private edtSenhaAtual as wx.TextCtrl
    private labNovaSenha as wx.StaticText
    private edtNovaSenha as wx.TextCtrl
    private labConfirmarSenha as wx.StaticText
    private edtConfirmarSenha as wx.TextCtrl
    private btnSalvar as wx.Button
    private btnLimpar as wx.Button
    private btnFechar as wx.Button

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, -1, new Point(424, 292), new Size(257, 161), _
        wxTAB_TRAVERSAL,"")

      ClientSize = new Size(249, 134)
      EVT_CLOSE(new EventListener(AddressOf OnClose ))

    	labLogin = new wx.StaticText(Me, idt.ID_FRMALTERARSENHA_LABLOGIN, _
        "Login: ", new Point(8, 8), new Size(29, 13) )
    	edtLogin = new wx.TextCtrl(Me, idt.ID_FRMALTERARSENHA_EDTLOGIN, "", _ 
        new Point(8, 24), new Size(100, 21) )
    	edtLogin.Enable(false)
    	labSenhaAtual = new wx.StaticText(Me, idt.ID_FRMALTERARSENHA_LABSENHAATUAL, _
        "Senha atual:", new Point(112, 8), new Size(60, 13) )
    	edtSenhaAtual = new wx.TextCtrl(Me, idt.ID_FRMALTERARSENHA_EDTSENHAATUAL, _
        "", new Point(112, 24), new Size(100, 21), wx.TextCtrl.wxTE_PASSWORD )
    	labNovaSenha = new wx.StaticText(Me, idt.ID_FRMALTERARSENHA_LABNOVASENHA, _
        "Nova Senha:", new Point(8, 48), new Size(61, 13) )
    	edtNovaSenha = new wx.TextCtrl(Me, idt.ID_FRMALTERARSENHA_EDTNOVASENHA, _
        "", new Point(8, 64), new Size(100, 21), wx.TextCtrl.wxTE_PASSWORD )
    	labConfirmarSenha = new wx.StaticText(Me, _
        idt.ID_FRMALTERARSENHA_LABCONFIRMARSENHA, "Confirmar senha:", _
        new Point(112, 48), new Size(79, 13) )
    	edtConfirmarSenha = new wx.TextCtrl(Me, _
        idt.ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "", _
        new Point(112, 64), new Size(100, 21), wx.TextCtrl.wxTE_PASSWORD )
    	btnSalvar = new wx.Button(Me, idt.ID_FRMALTERARSENHA_BTNSALVAR, _
        "&Salvar", new Point(8, 104), new Size(75, 25))
    	btnLimpar = new wx.Button(Me, idt.ID_FRMALTERARSENHA_BTNLIMPAR, _
        "&Limpar", new Point(88, 104), new Size(75, 25))
    	btnFechar = new wx.Button(Me, idt.ID_FRMALTERARSENHA_BTNFECHAR, _
        "&Fechar", new Point(168, 104), new Size(75, 25)) 
  
      'edtLogin.Value = RotinasGlobais.Rotinas.sUsuarioLogin
      edtSenhaAtual.MaxLength = 10
      edtNovaSenha.MaxLength = 10
      edtConfirmarSenha.MaxLength = 10
  
      EVT_BUTTON(idt.ID_FRMALTERARSENHA_BTNSALVAR, _
        new EventListener(AddressOf OnBtnSalvarClick ))
      EVT_BUTTON(idt.ID_FRMALTERARSENHA_BTNLIMPAR, _
        new EventListener(AddressOf OnBtnLimparClick ))
      EVT_BUTTON(idt.ID_FRMALTERARSENHA_BTNFECHAR, _
        new EventListener(AddressOf OnBtnFecharClick ))
  
    	FazLayout()
    	edtSenhaAtual.SetFocus()    
    End Sub

		private sub FazLayout()
      dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_9 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_10 as wx.GridSizer = new wx.GridSizer(4, 1, 0, 0)
      dim grid_sizer_3 as wx.GridSizer = new wx.GridSizer(4, 1, 0, 0)
      grid_sizer_3.Add(labLogin, 0, _
        wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 8)
      grid_sizer_3.Add(edtLogin, 0, wx.Direction.wxLEFT, 8)
      grid_sizer_3.Add(labNovaSenha, 0, _
        wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 8)
      grid_sizer_3.Add(edtNovaSenha, 0, wx.Direction.wxLEFT, 8)
      sizer_9.Add(grid_sizer_3, 0, 0, 0)
      grid_sizer_10.Add(labSenhaAtual, 0, _ 
        wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 4)
      grid_sizer_10.Add(edtSenhaAtual, 0, wx.Direction.wxLEFT, 4)
      grid_sizer_10.Add(labConfirmarSenha, 0, _
        wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 4)
      grid_sizer_10.Add(edtConfirmarSenha, 0, wx.Direction.wxLEFT, 4)
      sizer_9.Add(grid_sizer_10, 0, 0, 0)
      sizer_1.Add(sizer_9, 1, 0, 0)
      sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL, 2)
      sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL, 2)
      sizer_2.Add(btnFechar, 0, wx.Direction.wxALL, 2)
      sizer_1.Add(sizer_2, 0, wx.Direction.wxALL, 4)
      Me.AutoLayout = true
      Me.SetSizer(sizer_1)
      sizer_1.Fit(Me)
      sizer_1.SetSizeHints(Me)
		End Sub

		public sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      Destroy()
		end sub

    public sub OnBtnSalvarClick(ByVal sender As Object, ByVal e As wx.Event)
      dim Arquiva as OleDbCommand = new OleDbCommand()
      if ValidaDados() then
        if RotinasGlobais.Rotinas.AtualizaDados(Arquiva, _
          ConsultasSQL.ConsSQL.Usuario("U", edtLogin.Value, _
          edtConfirmarSenha.Value)) then
          MessageDialog.MessageBox(Resource.STR_SENALTSUC, "Erro", _
            Dialog.wxOK or Dialog.wxICON_ERROR )
        end if
      end if
      e.Skip()
    end sub
  
    public sub OnBtnLimparClick(ByVal sender As Object, ByVal e As wx.Event)
      edtSenhaAtual.Clear()
      edtNovaSenha.Clear()
      edtConfirmarSenha.Clear()
      edtSenhaAtual.SetFocus()
      e.Skip()
    end sub
  
    public sub OnBtnFecharClick(ByVal sender As Object, ByVal e As wx.Event)
      Me.Parent.Close(true)
      e.Skip()
    end sub
  
    public function ValidaDados() as boolean      
      if edtSenhaAtual.Value <> RotinasGlobais.Rotinas.sUsuarioSenha then
        MessageDialog.MessageBox(Resource.STR_SENNCSU, "Erro", _
          Dialog.wxOK or Dialog.wxICON_ERROR )
        return false
      end if
      if RotinasGlobais.Rotinas.ValidaCampo(edtNovaSenha.Value, _
         Resource.STR_NSENNINF) then
        return false
      end if
      if edtNovaSenha.Value <> edtConfirmarSenha.Value then
        MessageDialog.MessageBox(Resource.STR_NSENNCCON, "Erro", _
          Dialog.wxOK or Dialog.wxICON_ERROR )
        return false
      end if
      return true
    end function

	End Class

End Namespace
