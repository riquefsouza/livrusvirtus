Imports System
Imports System.Drawing
Imports System.Collections
Imports System.Data.OleDb
Imports wx

Namespace Livrus

	Public Class frmVenderLivros
		Inherits frmCadastros
		
		public shared WithEvents fVenderLivros as frmVenderLivros

    private enum idx
      ID_FRMVENDERLIVROS_BTNVENDER = 3000
      ID_FRMVENDERLIVROS_BTNLIMPAR 
      ID_FRMVENDERLIVROS_BTNFECHAR 
      ID_FRMVENDERLIVROS_BTNPCLIENTE
      ID_FRMVENDERLIVROS_BTNPLIVRO
      ID_FRMVENDERLIVROS_LSTLIVROS
      ID_FRMVENDERLIVROS_EDTDTHRVENDA
      ID_FRMVENDERLIVROS_EDTISBN 
      ID_FRMVENDERLIVROS_EDTLIVRO 
      ID_FRMVENDERLIVROS_EDTPRECOTOTAL 
      ID_FRMVENDERLIVROS_LABDTHRVENDA 
      ID_FRMVENDERLIVROS_LABISBN 
      ID_FRMVENDERLIVROS_LABLIVRO
      ID_FRMVENDERLIVROS_LABLIVROS 
      ID_FRMVENDERLIVROS_LABPRECOTOTAL
      ID_FRMVENDERLIVROS_BTNADLIVROS
    end enum

    private slPrecos, slISBNs, slQtdEstoque as ArrayList
    private nPrecoTotal as double
    private labDtHrVenda as wx.StaticText
    private edtDtHrVenda as wx.TextCtrl
    private btnPCliente as wx.Button
    private labISBN as wx.StaticText
    private edtISBN as wx.TextCtrl
    private labLivro as wx.StaticText
    private edtLivro as wx.TextCtrl
    private btnAdLivros as wx.Button
    private btnPLivro as wx.Button
    private labLivros as wx.StaticText
    private lstLivros as wx.ListBox
    private labPrecoTotal as wx.StaticText
    private edtPrecoTotal as wx.TextCtrl
    private btnVender as wx.Button

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, TextValidatorCtrl.FILTER_NONE, false)

      slPrecos = new ArrayList()
      slISBNs = new ArrayList()
      slQtdEstoque = new ArrayList()
      btnNovo.Hide()
    
      labDtHrVenda = new wx.StaticText(Me, idx.ID_FRMVENDERLIVROS_LABDTHRVENDA, _
        "Data/Hora Venda: ", new Point(8, 8), new Size(91, 13), 0)  
      edtDtHrVenda = new wx.TextCtrl(Me, idx.ID_FRMVENDERLIVROS_EDTDTHRVENDA, _
        "", new Point(8, 24), new Size(128, 21), 0)
      edtDtHrVenda.Enabled = false
    
      labCodigo.Label = "CPF: "  
      labCodigo.SetSize(8, 48, 48, 13) 
      edtCodigo.SetSize(8, 64, 128, 21)
      edtCodigo.EVT_KILL_FOCUS(new EventListener( _
        AddressOf OnEdtCodigo_Killfocus ))
    
      labDescricao.Label = "Cliente: "
      labDescricao.SetSize(142, 48, 56, 13)  
      edtDescricao.SetSize(142, 64, 306, 21)
      edtDescricao.Enabled = false
     
      btnPCliente = new wx.Button(Me, idx.ID_FRMVENDERLIVROS_BTNPCLIENTE, _
        "...", new Point(448, 64), new Size(21, 21), 0)
      
      labISBN = new wx.StaticText(Me, idx.ID_FRMVENDERLIVROS_LABISBN, _
        "ISBN: ", new Point(8, 88), new Size(48, 13), 0)  
      edtISBN = new wx.TextCtrl(Me, idx.ID_FRMVENDERLIVROS_EDTISBN, _
        "", new Point(8, 104), new Size(128, 21), 0)
      edtISBN.EVT_KILL_FOCUS(new EventListener(AddressOf OnEdtISBN_Killfocus ))
      
      labLivro = new wx.StaticText(Me, idx.ID_FRMVENDERLIVROS_LABLIVRO, _
        "Livro: ", new Point(142, 88), new Size(40, 13), 0)  
      edtLivro = new wx.TextCtrl(Me, idx.ID_FRMVENDERLIVROS_EDTLIVRO, _
        "", new Point(142, 104), new Size(282, 21), 0)
      edtLivro.Enabled = false
    
      btnAdLivros = new wx.Button(Me, idx.ID_FRMVENDERLIVROS_BTNADLIVROS, _
      "+", new Point(424, 104), new Size(21, 21), 0)
      
      btnPLivro = new wx.Button(Me, idx.ID_FRMVENDERLIVROS_BTNPLIVRO, _
        "...", new Point(448, 104), new Size(21, 21), 0)
      
      labLivros = new wx.StaticText(Me, idx.ID_FRMVENDERLIVROS_LABLIVROS, _
        "Livros para vender: ", new Point(8, 128), new Size(120, 13), 0)
      
      lstLivros = new wx.ListBox(Me, idx.ID_FRMVENDERLIVROS_LSTLIVROS, _
        new Point(8, 144), new Size(464, 96))
      
      labPrecoTotal = new wx.StaticText(Me, idx.ID_FRMVENDERLIVROS_LABPRECOTOTAL, _
        "Preço Total: ", new Point(280, 248), new Size(61, 13), 0)  
      edtPrecoTotal = new wx.TextCtrl(Me, idx.ID_FRMVENDERLIVROS_EDTPRECOTOTAL, _
        "R$ 0,00", new Point(344, 246), new Size(127, 21), 0)
      edtPrecoTotal.Enabled = false
      
      btnVender = new wx.Button(Me, idx.ID_FRMVENDERLIVROS_BTNVENDER, _
        "&Vender", new Point(239, 275), new Size(75, 25), 0)  
      btnLimpar = new wx.Button(Me, idx.ID_FRMVENDERLIVROS_BTNLIMPAR, _
        "&Limpar", new Point(319, 275), new Size(75, 25), 0)  
      btnFechar = new wx.Button(Me, idx.ID_FRMVENDERLIVROS_BTNFECHAR, _
        "&Fechar", new Point(399, 275), new Size(75, 25), 0)
    
      'FazLayout()
    
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true, true)
      edtCodigo.MaxLength = 14
      edtISBN.MaxLength = 13
      nPrecoTotal = 0

      EVT_BUTTON(idx.ID_FRMVENDERLIVROS_BTNVENDER, _
        new EventListener(AddressOf OnBtnVender ))
      EVT_BUTTON(idx.ID_FRMVENDERLIVROS_BTNLIMPAR, _
        new EventListener(AddressOf OnBtnLimpar ))
      EVT_BUTTON(idx.ID_FRMVENDERLIVROS_BTNFECHAR, _
        new EventListener(AddressOf OnBtnFechar ))
			EVT_CLOSE( new EventListener(AddressOf OnClose ) )
      EVT_BUTTON(idx.ID_FRMVENDERLIVROS_BTNPCLIENTE, _ 
        new EventListener(AddressOf OnBtnPCliente ))
      EVT_BUTTON(idx.ID_FRMVENDERLIVROS_BTNPLIVRO, _
        new EventListener(AddressOf OnBtnPLivro ))
      EVT_BUTTON(idx.ID_FRMVENDERLIVROS_BTNADLIVROS, _ 
        new EventListener(AddressOf OnBtnAdLivros ))
      EVT_LISTBOX_DCLICK(idx.ID_FRMVENDERLIVROS_LSTLIVROS, _
        new EventListener(AddressOf OnLstLivros_Dblclk ))
    End Sub

    private sub FazLayout()
      dim sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_6 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_8 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_7 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_5 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_8 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_7 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_6 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_5 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_3 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_4 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_3 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_2 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_1 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      grid_sizer_1.Add(labDtHrVenda, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_1.Add(edtDtHrVenda, 0, 0, 0)
      sizer_2.Add(grid_sizer_1, 0, wx.Direction.wxLEFT, 2)
      sizer_2.Add(20, 20, 0, 0, 0)
      sizer_1.Add(sizer_2, 0, 0, 0)
      grid_sizer_2.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_2.Add(edtCodigo, 0, 0, 0)
      sizer_3.Add(grid_sizer_2, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_3.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_3.Add(edtDescricao, 0, 0, 0)
      sizer_3.Add(grid_sizer_3, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_4.Add(20, 20, 0, 0, 0)
      grid_sizer_4.Add(btnPCliente, 0, 0, 0)
      sizer_3.Add(grid_sizer_4, 0, 0, 0)
      sizer_1.Add(sizer_3, 0, 0, 0)
      grid_sizer_5.Add(labISBN, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_5.Add(edtISBN, 0, 0, 0)
      sizer_4.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_6.Add(labLivro, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_6.Add(edtLivro, 0, 0, 0)
      sizer_4.Add(grid_sizer_6, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_7.Add(20, 20, 0, 0, 0)
      grid_sizer_7.Add(btnAdLivros, 0, 0, 0)
      sizer_4.Add(grid_sizer_7, 1, wx.Stretch.wxEXPAND, 0)
      grid_sizer_8.Add(20, 20, 0, 0, 0)
      grid_sizer_8.Add(btnPLivro, 0, 0, 0)
      sizer_4.Add(grid_sizer_8, 0, 0, 0)
      sizer_1.Add(sizer_4, 0, 0, 0)
      sizer_5.Add(labLivros, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      sizer_5.Add(lstLivros, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 1)
      sizer_1.Add(sizer_5, 1, wx.Stretch.wxEXPAND, 0)
      sizer_7.Add(labPrecoTotal, 0, wx.Direction.wxALL, 2)
      sizer_7.Add(edtPrecoTotal, 0, wx.Direction.wxALL, 2)
      sizer_6.Add(sizer_7, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_8.Add(btnVender, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_8.Add(btnLimpar, 0, wx.Direction.wxALL or _ 
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_8.Add(btnFechar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_6.Add(sizer_8, 0, wx.Direction.wxALL, 2)
      sizer_1.Add(sizer_6, 0, wx.Alignment.wxALIGN_RIGHT or _
        wx.Alignment.wxALIGN_BOTTOM, 0)
      AutoLayout = true
      SetSizer(sizer_1)
      sizer_1.Fit(Me)
      sizer_1.SetSizeHints(Me)
    end sub

    private sub LimpaDados()
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true, true)
      edtCodigo.Clear()
      edtDescricao.Clear()
      edtISBN.Clear()
      edtLivro.Clear()
      lstLivros.Clear()
      nPrecoTotal = 0
      edtPrecoTotal.Value = "R$ 0,00"
      edtCodigo.SetFocus()
    end sub

		private function ValidaDados() as boolean
      if RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, _
        Resource.STR_CPFNINF) then
        return false
      end if
      if lstLivros.Count = 0 then
        wx.MessageDialog.MessageBox(Resource.STR_LIVVENNINF, "Erro", _
          wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
        return false
      end if
			return true
		end function

    private function SalvaLista() as boolean
      dim sCPF, sISBN, sPrecoTotal, sDataHora, sQtdEstoque, sDTHR as string
      dim nCont, nQtd, nQtdEstoque as integer
      dim Arquiva as OleDbCommand = new OleDbCommand()
    
      nQtd = lstLivros.Count
      sCPF = edtCodigo.Value
      sPrecoTotal = CStr(nPrecoTotal)
      
      sDTHR = edtDtHrVenda.Value
      sDataHora = RotinasGlobais.Rotinas.ConverteDataHoraStr(sDTHR, _
        "MM/dd/YYYY hh:mm:ss")
      
      for nCont=0 to nQtd-1
        sISBN = slISBNs(nCont).ToString()
      
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva, _
          ConsultasSQL.ConsSQL.Venda("I",sISBN, sCPF, sDataHora, _
          RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal,false),""))
      
        nQtdEstoque = CInt(slQtdEstoque(nCont).ToString())
        if nQtdEstoque >= 0 then
          nQtdEstoque = nQtdEstoque - 1
        end if
        sQtdEstoque = CStr(nQtdEstoque)
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva, _
          ConsultasSQL.ConsSQL.Venda("U",sISBN, "","","", sQtdEstoque))
      next nCont
      return true
    end function

 	  private sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      Me.Parent.Close()
			e.Skip()
		End Sub

    private sub OnBtnFechar(ByVal sender As Object, ByVal e As wx.Event)
      Me.Close(true)
      e.Skip()
    end sub

    private sub OnEdtCodigo_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sCliente as string
      dim ConsCampo as ArrayList = new ArrayList()    
    
      if edtCodigo.Value.Length > 0 then
        if RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.Value) then
          sCliente = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
            ConsultasSQL.ConsSQL.Cliente("S", edtCodigo.Value, _
            "","","","","","","","",""),Resource.STR_CLINENC) 
          if sCliente.Length = 0 then
            edtCodigo.Clear()
            edtCodigo.SetFocus()
          else
             edtDescricao.Value = sCliente
          end if
        else
          wx.MessageDialog.MessageBox(Resource.STR_CPFINV, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
          edtCodigo.Clear()
          edtCodigo.SetFocus()
        end if
      else
        edtDescricao.Clear()
      end if
    end sub
    
    private sub OnBtnPCliente(ByVal sender As Object, ByVal e As wx.Event)
      dim fConClientes as frmConClientes = new frmConClientes(Me)
      fConClientes.ShowModal()
      edtCodigo.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCodigo_Killfocus(nothing,nothing)
      e.Skip()
    end sub
    
    private sub OnEdtISBN_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sLivro as string
      dim nQtdEstoque as integer
      dim ConsCampo as ArrayList = new ArrayList()       
    
      if edtISBN.Value.Length > 0 then
        if RotinasGlobais.Rotinas.ValidaISBN(edtISBN.Value) then      
          sLivro = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _ 
            ConsultasSQL.ConsSQL.Livro("Q",edtISBN.Value, _
            "","","","","","","","",""),Resource.STR_LIVNENC)
          if sLivro.Length=0 then
            edtISBN.Clear()
          	edtISBN.SetFocus()
          else
             edtLivro.Value = sLivro
             nQtdEstoque = CInt(ConsCampo(3).ToString())
             if nQtdEstoque > 0 then
               RotinasGlobais.Rotinas.sPreco = ConsCampo(2).ToString()
               RotinasGlobais.Rotinas.sQtdEstoque = ConsCampo(3).ToString()
             else
               wx.MessageDialog.MessageBox(Resource.STR_LIVNEST, "Erro", _
                 wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
             end if
          end if
        else
          wx.MessageDialog.MessageBox(Resource.STR_ISBNINV, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
          edtISBN.Clear()
          edtISBN.SetFocus()
        end if
      else
        edtLivro.Clear()
      end if
    end sub
    
    private sub OnBtnPLivro(ByVal sender As Object, ByVal e As wx.Event)
      dim fConLivros as frmConLivros = new frmConLivros(Me)
      fConLivros.ShowModal()
      edtISBN.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtISBN_Killfocus(nothing,nothing)
      e.Skip()
    end sub
    
    private sub OnBtnAdLivros(ByVal sender As Object, ByVal e As wx.Event)
      dim nPreco as double
      dim sLivros, sISBN, sEdtLivro, sPrecoTotal as string
    
     sISBN = edtISBN.Value
     sEdtLivro = edtLivro.Value
     if sISBN.Length > 0 then
       sLivros = sISBN + " - " + sEdtLivro + " - R$ " + _
        RotinasGlobais.Rotinas.sPreco
       if RotinasGlobais.Rotinas.PesquisaItemLista(lstLivros, sLivros)=-1 then
         slISBNs.Add(sISBN)
         slPrecos.Add(RotinasGlobais.Rotinas.sPreco)
         slQtdEstoque.Add(RotinasGlobais.Rotinas.sQtdEstoque)
         lstLivros.Append(sLivros)
         nPreco = CDbl(RotinasGlobais.Rotinas.sPreco)
         nPrecoTotal = nPrecoTotal + nPreco
       end if
       edtISBN.Clear()
       edtLivro.Clear()
       sPrecoTotal = "R$ " + CStr(nPrecoTotal)
       edtPrecoTotal.Value = _
         RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal,true)
     end if
     e.Skip()
    end sub
    
    private sub OnLstLivros_Dblclk(ByVal sender As Object, ByVal e As wx.Event)
      dim sPrecoTotal as string
      dim nPreco as double
      dim nSelIndice as integer
    
      if lstLivros.Count > 0 then   
        nSelIndice = lstLivros.Selection
        if lstLivros.Selected(nSelIndice) then
          nPreco = CDbl(slPrecos(nSelIndice).ToString())
          nPrecoTotal = nPrecoTotal-nPreco     
          sPrecoTotal = "R$ " + Convert.ToString(nPrecoTotal)
          edtPrecoTotal.Value = _
            RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal,true)
          slISBNs.RemoveAt(nSelIndice)
          slPrecos.RemoveAt(nSelIndice)
          slQtdEstoque.RemoveAt(nSelIndice)
          lstLivros.Delete(nSelIndice)
        end if	
      end if
      e.Skip()
    end sub    
     
    private sub OnBtnVender(ByVal sender As Object, ByVal e As wx.Event)
      if ValidaDados() then
        if SalvaLista() then
          wx.MessageDialog.MessageBox(Resource.STR_VENRESUC, _
          Resource.STR_TITULO, wx.Dialog.wxOK or wx.Dialog.wxICON_INFORMATION)
          LimpaDados()
        end if
      end if	
      e.Skip()
    end sub      
    
    private sub OnBtnLimpar(ByVal sender As Object, ByVal e As wx.Event)
      LimpaDados()
      e.Skip()
    end sub

	End Class

End Namespace
