Imports System
Imports System.Drawing
Imports System.Collections
Imports wx

Namespace Livrus

	Public Class frmConsultas
		Inherits wx.Dialog
		
    protected enum idt
     ID_FRMCONSULTAS_BTNFECHAR = 500
     ID_FRMCONSULTAS_BTNLIMPAR 
     ID_FRMCONSULTAS_BTNPESQUISAR
     ID_FRMCONSULTAS_EDTDESCRICAO 
     ID_FRMCONSULTAS_GRIDCONSULTA
     ID_FRMCONSULTAS_LABDESCRICAO 
     ID_FRMCONSULTAS_LABREGISTRO 
    end enum

		protected Registros, Campos as ArrayList
    private sSelecionado as string

		protected labDescricao as wx.StaticText
		protected edtDescricao as wx.TextCtrl
		protected btnPesquisar as wx.Button
		protected labRegistro as wx.StaticText
		protected gridConsulta as wx.Grid
		protected btnFechar as wx.Button
		protected btnLimpar as wx.Button

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, -1, "Consulta de", new Point(0, 0), _
      new Size(365, 263), wxDEFAULT_DIALOG_STYLE or wxCAPTION or _
      wxRESIZE_BORDER or wxMINIMIZE_BOX or wxMAXIMIZE_BOX )

			SetIcon(new wx.Icon( "xpms/livrus.xpm" ))
      ClientSize = new Size(365, 263)
      Centre()
    
      labDescricao = new wx.StaticText(Me, idt.ID_FRMCONSULTAS_LABDESCRICAO, _
        "Descrição:", new Point(8, 8), new Size(51, 13), 0)
      edtDescricao = new wx.TextCtrl(Me, idt.ID_FRMCONSULTAS_EDTDESCRICAO, _
        "", new Point(8, 24), new Size(257, 21), 0)
      btnPesquisar = new wx.Button(Me, idt.ID_FRMCONSULTAS_BTNPESQUISAR, _
        "&Pesquisar", new Point(272, 24), new Size(75, 25), 0)
    
      gridConsulta = new wx.Grid(Me, idt.ID_FRMCONSULTAS_GRIDCONSULTA, _ 
        new Point(0, 56), new Size(365, 125), wx.Window.wxBORDER_SUNKEN)
      gridConsulta.CreateGrid(1, 2, wx.GridSelectionMode.wxGridSelectRows)
      gridConsulta.SetColLabelValue(0, "Código")
      gridConsulta.SetColSize(0, 80)
      gridConsulta.SetColLabelValue(1, "Descrição")
      gridConsulta.SetColSize(1, 180)
      gridConsulta.Editable = false
      gridConsulta.HideCellEditControl()
      gridConsulta.ColLabelSize = 21
    
      labRegistro = new wx.StaticText(Me, idt.ID_FRMCONSULTAS_LABREGISTRO, _
        "Registro 0 de 0", new Point(8, 16), new Size(144, 13), 0)
      btnLimpar = new wx.Button(Me, idt.ID_FRMCONSULTAS_BTNLIMPAR, _
        "&Limpar", new Point(16, 13), new Size(75, 25), 0)
      btnFechar = new wx.Button(Me, idt.ID_FRMCONSULTAS_BTNFECHAR, _
        "&Fechar", new Point(75, 13), new Size(75, 25), 0)
    
      FazLayout()
      Registros = new ArrayList()
      sSelecionado = ""
      edtDescricao.SetFocus()
    End Sub

    private sub FazLayout()
      dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim grid_sizer_2 as wx.GridSizer = new wx.GridSizer(1, 2, 0, 0)
      dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_3 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim grid_sizer_1 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      grid_sizer_1.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_1.Add(edtDescricao, 0, 0, 0)
      sizer_3.Add(grid_sizer_1, 0, wx.Direction.wxALL, 2)
      sizer_4.Add(20, 20, 0, 0, 0)
      sizer_4.Add(btnPesquisar, 0, wx.Direction.wxLEFT or _
        wx.Direction.wxTOP or wx.Direction.wxBOTTOM, 5)
      sizer_3.Add(sizer_4, 0, 0, 0)
      sizer_1.Add(sizer_3, 0, wx.Direction.wxALL, 4)
      sizer_1.Add(gridConsulta, 1, wx.Stretch.wxEXPAND, 0)
      grid_sizer_2.Add(labRegistro, 0, wx.Direction.wxALL, 10)
      sizer_2.Add(btnLimpar, 0, wx.Alignment.wxALIGN_RIGHT or _
        wx.Alignment.wxALIGN_BOTTOM, 8)
      sizer_2.Add(btnFechar, 0, wx.Direction.wxLEFT or  _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 8)
      grid_sizer_2.Add(sizer_2, 1, wx.Direction.wxALL or  _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 4)
      sizer_1.Add(grid_sizer_2, 0, wx.Direction.wxALL or  _
        wx.Stretch.wxEXPAND or wx.Alignment.wxALIGN_BOTTOM, 0)
      AutoLayout = true
      SetSizer(sizer_1)
      sizer_1.Fit(Me)
      sizer_1.SetSizeHints(Me)
      Layout()
    end sub

    protected sub Fecha(nIndMenu as integer)
      if (sSelecionado.Length > 0) then
        RotinasGlobais.Rotinas.sCodigoSelecionado = sSelecionado
      else
        RotinasGlobais.Rotinas.sCodigoSelecionado = "" 
      end if
      if nIndMenu = 0 then
        if Me.Modal then
          EndModal(0)
        else
          Close()
        end if
      else
        frmPrincipal.fPrincipal.barraMenu.GetMenu(1).Enable(nIndMenu, true)
      end if
    end sub
    
    protected sub LimparDados()
      labRegistro.Label = "Registro 0 de 0"
      gridConsulta.ClearGrid()
      gridConsulta.DeleteRows(0,gridConsulta.NumberRows-1,true)
      edtDescricao.Clear()
      edtDescricao.SetFocus()
    end sub

    protected sub PesquisarDados(sTextoSql as string, _
      sMensagemErro as string, nQtdCol as integer)
      if RotinasGlobais.Rotinas.ConsultaDadosLista(Registros, sTextoSql) then
        RotinasGlobais.Rotinas.AdicionaLinhasGrid(gridConsulta, _
          Registros, nQtdCol)
      else
        MessageDialog.MessageBox(sMensagemErro, "Erro", _
          wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR )
      end if
    end sub
    
    protected sub setLabRegistros(nLinha as integer)
      if nLinha >= 0 then
        labRegistro.Label = "Registro " + CStr(nLinha+1) + " de " + _
          CStr(gridConsulta.NumberRows)
        sSelecionado = gridConsulta.GetCellValue(nLinha, 0)
      end if
    end sub

	End Class

End Namespace
