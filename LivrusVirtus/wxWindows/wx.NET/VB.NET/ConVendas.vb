Imports System
Imports System.Drawing
Imports System.Collections
Imports System.Data.OleDb
Imports Microsoft.VisualBasic
Imports wx

Namespace Livrus

	Public Class frmConVendas
		Inherits wx.Panel
		
		public shared WithEvents fConVendas as frmConVendas

    private enum idx
      ID_FRMCONVENDAS_BTNPESQUISAR = 3100
      ID_FRMCONVENDAS_BTNLIMPAR
      ID_FRMCONVENDAS_BTNFECHAR
      ID_FRMCONVENDAS_BTNPCLIENTE
      ID_FRMCONVENDAS_BTNPLIVRO
      ID_FRMCONVENDAS_GRIDVENDAS
      ID_FRMCONVENDAS_EDTDTHRVENDA
      ID_FRMCONVENDAS_EDTISBN
      ID_FRMCONVENDAS_EDTLIVRO
      ID_FRMCONVENDAS_EDTPRECOTOTAL
      ID_FRMCONVENDAS_LABDTHRVENDA
      ID_FRMCONVENDAS_LABISBN
      ID_FRMCONVENDAS_LABLIVRO
      ID_FRMCONVENDAS_LABPRECOTOTAL
      ID_FRMCONVENDAS_LABCPF
      ID_FRMCONVENDAS_EDTCPF
      ID_FRMCONVENDAS_LABCLIENTE
      ID_FRMCONVENDAS_EDTCLIENTE
      ID_FRMCONVENDAS_LABREGISTRO
    end enum

    private labDtHrVenda as wx.StaticText
    private edtDtHrVenda as wx.TextCtrl
    private labCPF as wx.StaticText
    private edtCPF as wx.TextCtrl
    private labCliente as wx.StaticText
    private edtCliente as wx.TextCtrl
    private btnPCliente as wx.Button
    private labISBN as wx.StaticText
    private edtISBN as wx.TextCtrl
    private labLivro as wx.StaticText
    private edtLivro as wx.TextCtrl
    private btnPLivro as wx.Button
    private labRegistro as wx.StaticText
    private gridVendas as wx.Grid
    private labPrecoTotal as wx.StaticText
    private edtPrecoTotal as wx.TextCtrl
    private btnPesquisar as wx.Button
    private btnLimpar as wx.Button
    private btnFechar as wx.Button

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, -1, new Point(0, 0), new Size(480, 310))

      labDtHrVenda = new wx.StaticText(Me, idx.ID_FRMCONVENDAS_LABDTHRVENDA, _
        "Data/Hora Venda: ", new Point(8, 8), new Size(91, 13), 0)  
      edtDtHrVenda = new wx.TextCtrl(Me, idx.ID_FRMCONVENDAS_EDTDTHRVENDA, _
        "", new Point(8, 24), new Size(128, 21), 0)
      edtDtHrVenda.EVT_KILL_FOCUS(new EventListener( _
        AddressOf OnEdtDtHrVenda_Killfocus ))
    
      btnPesquisar = new wx.Button(Me, idx.ID_FRMCONVENDAS_BTNPESQUISAR, _
        "&Pesquisar", new Point(144, 22), new Size(75, 25), 0)
    
      labCPF = new wx.StaticText(Me, idx.ID_FRMCONVENDAS_LABCPF, _
        "CPF: ", new Point(8, 48), new Size(48, 13), 0)  
      edtCPF = new wx.TextCtrl(Me, idx.ID_FRMCONVENDAS_EDTCPF, _
        "", new Point(8, 64), new Size(128, 21), 0)
      edtCPF.EVT_KILL_FOCUS(new EventListener(AddressOf OnEdtCPF_Killfocus ))
    
      labCliente = new wx.StaticText(Me, idx.ID_FRMCONVENDAS_LABCLIENTE, _
        "Cliente: ", new Point(142, 48), new Size(56, 13), 0)  
      edtCliente = new wx.TextCtrl(Me, idx.ID_FRMCONVENDAS_EDTCLIENTE, _
        "", new Point(142, 64), new Size(306, 21), 0)
      edtCliente.Enabled = false
     
      btnPCliente = new wx.Button(Me, idx.ID_FRMCONVENDAS_BTNPCLIENTE, _
        "...", new Point(448, 64), new Size(21, 21), 0)
      
      labISBN = new wx.StaticText(Me, idx.ID_FRMCONVENDAS_LABISBN, _
        "ISBN: ", new Point(8, 88), new Size(48, 13), 0)  
      edtISBN = new wx.TextCtrl(Me, idx.ID_FRMCONVENDAS_EDTISBN, _
        "", new Point(8, 104), new Size(128, 21), 0)
      edtISBN.EVT_KILL_FOCUS(new EventListener(AddressOf OnEdtISBN_Killfocus ))
      
      labLivro = new wx.StaticText(Me, idx.ID_FRMCONVENDAS_LABLIVRO, _
        "Livro: ", new Point(142, 88), new Size(40, 13), 0)  
      edtLivro = new wx.TextCtrl(Me, idx.ID_FRMCONVENDAS_EDTLIVRO, _
        "", new Point(142, 104), new Size(306, 21), 0)
      edtLivro.Enabled = false
    
      btnPLivro = new wx.Button(Me, idx.ID_FRMCONVENDAS_BTNPLIVRO, _
        "...", new Point(448, 104), new Size(21, 21), 0)
    
      Me.gridVendas = new wx.Grid(Me, idx.ID_FRMCONVENDAS_GRIDVENDAS, _
        new Point(0, 136), new Size(355, 122), wxSUNKEN_BORDER)
      Me.gridVendas.CreateGrid(1, 6, wx.GridSelectionMode.wxGridSelectRows)
      Me.gridVendas.HideCellEditControl()
      Me.gridVendas.ColLabelSize = 21
    
      Me.labRegistro = new wx.StaticText(Me, idx.ID_FRMCONVENDAS_LABREGISTRO, _
        "Registro 0 de 0", new Point(8, 16), new Size(144, 13), 0)
    
      labPrecoTotal = new wx.StaticText(Me, idx.ID_FRMCONVENDAS_LABPRECOTOTAL, _
        "Preço Total: ", new Point(280, 248), new Size(61, 13), 0)  
      edtPrecoTotal = new wx.TextCtrl(Me, idx.ID_FRMCONVENDAS_EDTPRECOTOTAL, _
        "", new Point(344, 246), new Size(127, 21), 0)
      edtPrecoTotal.Enabled = false
    
      Me.btnLimpar = new wx.Button(Me, idx.ID_FRMCONVENDAS_BTNLIMPAR, _
        "&Limpar", new Point(16, 13), new Size(75, 25), 0)
      Me.btnFechar = new wx.Button(Me, idx.ID_FRMCONVENDAS_BTNFECHAR, _
        "&Fechar", new Point(75, 13), new Size(75, 25), 0)
    
      FazLayout()

      dim nLargura() as integer = { 120, 100, 220, 100, 280, 80 }
      dim sRotulos() as string = { "Data/Hora Venda", "CPF", "Cliente", _
       "ISBN", "Livro", "Preço" }

      RotinasGlobais.Rotinas.AdicionaColunasGrid(gridVendas, 0, 6, nLargura, sRotulos)
      gridVendas.Editable = false
      edtCPF.MaxLength = 14
      edtISBN.MaxLength = 13
      edtPrecoTotal.Value = "R$ 0,00"
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,true)

      EVT_BUTTON(idx.ID_FRMCONVENDAS_BTNPESQUISAR, _
        new EventListener(AddressOf OnBtnPesquisar ))
      EVT_BUTTON(idx.ID_FRMCONVENDAS_BTNLIMPAR,  _
        new EventListener(AddressOf OnBtnLimpar ))
      EVT_BUTTON(idx.ID_FRMCONVENDAS_BTNFECHAR,  _
        new EventListener(AddressOf OnBtnFechar ))
			EVT_CLOSE( new EventListener(AddressOf OnClose ))
      EVT_BUTTON(idx.ID_FRMCONVENDAS_BTNPCLIENTE,  _
        new EventListener(AddressOf OnBtnPCliente ))
      EVT_BUTTON(idx.ID_FRMCONVENDAS_BTNPLIVRO,  _
        new EventListener(AddressOf OnBtnPLivro ))
      EVT_GRID_SELECT_CELL( new EventListener( _
        AddressOf OnGridSelectCell ))
      EVT_GRID_LABEL_LEFT_CLICK( new EventListener( _
        AddressOf OnGridLabelLeftClick ))

    end sub

    private sub FazLayout()
      dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_6 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_22 as wx.GridSizer = new wx.GridSizer(1, 2, 0, 0)
      dim sizer_23 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_8 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_7 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_24 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_8 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
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
      sizer_2.Add(btnPesquisar, 0, wx.Direction.wxLEFT or _
        wx.Direction.wxTOP or wx.Alignment.wxALIGN_BOTTOM, 10)
      sizer_1.Add(sizer_2, 0, 0, 0)
      grid_sizer_2.Add(labCPF, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_2.Add(edtCPF, 0, 0, 0)
      sizer_3.Add(grid_sizer_2, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_3.Add(labCliente, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_3.Add(edtCliente, 0, 0, 0)
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
      grid_sizer_8.Add(20, 20, 0, 0, 0)
      grid_sizer_8.Add(btnPLivro, 0, 0, 0)
      sizer_4.Add(grid_sizer_8, 0, 0, 0)
      sizer_1.Add(sizer_4, 0, 0, 0)
      sizer_1.Add(gridVendas, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 2)
      sizer_24.Add(labRegistro, 0, wx.Direction.wxALL, 4)
      sizer_24.Add(20, 20, 0, 0, 0)
      sizer_22.Add(sizer_24, 0, 0, 0)
      sizer_7.Add(labPrecoTotal, 0, wx.Direction.wxALL, 2)
      sizer_7.Add(edtPrecoTotal, 0, wx.Direction.wxALL, 2)
      sizer_23.Add(sizer_7, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_8.Add(btnLimpar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_8.Add(btnFechar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_23.Add(sizer_8, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_22.Add(sizer_23, 1, wx.Alignment.wxALIGN_RIGHT or _
        wx.Alignment.wxALIGN_BOTTOM, 0)
      sizer_6.Add(sizer_22, 0, wx.Stretch.wxEXPAND, 0)
      sizer_1.Add(sizer_6, 0, wx.Stretch.wxEXPAND, 0)
      AutoLayout = true
      SetSizer(sizer_1)
      sizer_1.Fit(Me)
      sizer_1.SetSizeHints(Me)
    end sub

    private sub OnBtnLimpar(ByVal sender As Object, ByVal e As wx.Event)
      edtCPF.Clear()
      edtCliente.Clear()
      edtISBN.Clear()
      edtLivro.Clear()
      gridVendas.ClearGrid()
      gridVendas.DeleteRows(0, gridVendas.NumberRows-1,true)
      edtPrecoTotal.Value = "R$ 0,00"
      edtDtHrVenda.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,true)
      labRegistro.Label = "Registro 0 de 0"
      edtDtHrVenda.SetFocus()
      e.Skip()
    end sub

    private function ConsVenda(sOpcao as string) as string
      dim sISBN, sCPF, sDataHora, sret as string   

      if Len(edtDtHrVenda.Value) > 0 then
        sDataHora = RotinasGlobais.Rotinas.ConverteDataHoraStr( _
          edtDtHrVenda.Value, "MM/dd/yyyy hh:mm:ss")
      else
        sDataHora = ""
      end if

      sISBN = edtISBN.Value
      sCPF = edtCPF.Value
    
      if sOpcao = "L" then
        sret = ConsultasSQL.ConsSQL.Venda("S","ZERO","","","","")
      else
        sret = ConsultasSQL.ConsSQL.Venda(sOpcao, sISBN, sCPF, _
          sDataHora, "", "")
      end if
      return sret
    end function

		private sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      Me.Parent.Close()
			e.Skip()
		End Sub   

    private sub OnBtnFechar(ByVal sender As Object, ByVal e As wx.Event)
      Me.Close(true)
      e.Skip()
    end sub   
   
    private sub OnBtnPesquisar(ByVal sender As Object, ByVal e As wx.Event)
      dim ConsTotal as ArrayList = new ArrayList()
      dim lstLinhas as ArrayList = new ArrayList()
      dim lstTotal as ArrayList
      dim sPrecoTotal as string
      dim nTemp as double
    
      if RotinasGlobais.Rotinas.ConsultaDadosLista(lstLinhas, _
          ConsVenda("S")) then
        RotinasGlobais.Rotinas.AdicionaLinhasGrid(gridVendas, lstLinhas, 6)
    
        if RotinasGlobais.Rotinas.ConsultaDadosLista(ConsTotal, _
          ConsVenda("P")) then
          if ConsTotal.Count > 0 then
            lstTotal = CType(ConsTotal(0), ArrayList)
            nTemp = Double.Parse(lstTotal(0).ToString()) 
            sPrecoTotal = nTemp.ToString("C") 
            edtPrecoTotal.Value = sPrecoTotal
          end if
        end if    
      else
         wx.MessageDialog.MessageBox(Resource.STR_VENNENC, "Erro", _
          wx.Dialog.wxOK  or  wx.Dialog.wxICON_ERROR)
      end if
    end sub
       
    private sub OnEdtCPF_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sCliente as string
      dim ConsCampo as ArrayList = new ArrayList()    
    
      if edtCPF.Value.Length > 0 then
        if RotinasGlobais.Rotinas.ValidaCPF(edtCPF.Value) then      
          sCliente = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
            ConsultasSQL.ConsSQL.Cliente("S",edtCPF.Value, _
            "","","","","","","","",""),Resource.STR_CLINENC) 
          if sCliente.Length=0 then
            edtCPF.Clear()
            edtCPF.SetFocus()
          else
             edtCliente.Value = sCliente
          end if
        else
          wx.MessageDialog.MessageBox(Resource.STR_CPFINV, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
          edtCPF.Clear()
          edtCPF.SetFocus()
        end if
      else
        edtCliente.Clear()
      end if
    end sub
    
    private sub OnBtnPCliente(ByVal sender As Object, ByVal e As wx.Event)
      dim fConClientes as frmConClientes = new frmConClientes(Me)
      fConClientes.ShowModal()
      edtCPF.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCPF_Killfocus(nothing,nothing)	
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
          if sLivro.Length = 0 then
            edtISBN.Clear()
          	edtISBN.SetFocus()
          else
             edtLivro.Value = sLivro
             nQtdEstoque = Int32.Parse(ConsCampo(3).ToString())
             if nQtdEstoque > 0 then
               RotinasGlobais.Rotinas.sPreco = ConsCampo(2).ToString()
             else
               wx.MessageDialog.MessageBox(Resource.STR_LIVNEST, "Erro", _
                 wx.Dialog.wxOK  or  wx.Dialog.wxICON_ERROR)
             end if
          end if
        else
          wx.MessageDialog.MessageBox(Resource.STR_ISBNINV, "Erro", _
            wx.Dialog.wxOK  or  wx.Dialog.wxICON_ERROR)
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
    
    private sub setLabRegistros(nLinha as integer)
      if nLinha >= 0 then
        labRegistro.Label = "Registro " + CStr(nLinha+1) + _
          " de " + CStr(gridVendas.NumberRows)
      end if
    end sub
    
    private sub OnGridSelectCell(ByVal sender As Object, ByVal e As wx.Event)
      dim evt as wx.GridEvent = CType(e, wx.GridEvent)
      setLabRegistros(evt.Row)
      e.Skip()
    end sub
    
    private sub OnGridLabelLeftClick(ByVal sender As Object, _
      ByVal e As wx.Event)
      dim evt as wx.GridEvent = CType(e, wx.GridEvent)
      setLabRegistros(evt.Row)
      e.Skip()
    end sub
    
    private sub OnEdtDtHrVenda_Killfocus(ByVal sender As Object, _
      ByVal e As wx.Event)
      if Len(edtDtHrVenda.Value) > 0 then
        if not RotinasGlobais.Rotinas.validaDataHora(edtDtHrVenda.Value, _
           false) then
          wx.MessageDialog.MessageBox(Resource.STR_DTHRINV, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
      		edtDtHrVenda.SetFocus()
        end if
      end if 
    end sub

	End Class

End Namespace
