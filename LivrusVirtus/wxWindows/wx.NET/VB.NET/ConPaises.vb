Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class frmConPaises
		Inherits frmConsultas
		
		public shared WithEvents fConPaises as frmConPaises

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent)

      Title = Resource.STR_CONPAIS
      labDescricao.Label = "Pa�s:  "
      gridConsulta.SetColLabelValue(1, "Pa�s")

      EVT_BUTTON(idt.ID_FRMCONSULTAS_BTNPESQUISAR, _
        new EventListener(AddressOf OnBtnPesquisar ))
      EVT_BUTTON(idt.ID_FRMCONSULTAS_BTNLIMPAR, _
        new EventListener(AddressOf OnBtnLimpar ))
      EVT_BUTTON(idt.ID_FRMCONSULTAS_BTNFECHAR, _
        new EventListener(AddressOf OnBtnFechar ))
      EVT_CLOSE(new EventListener(AddressOf OnClose ))
      EVT_GRID_SELECT_CELL(new EventListener(AddressOf OnGridSelectCell ))
      EVT_GRID_LABEL_LEFT_CLICK(new EventListener( _
        AddressOf OnGridLabelLeftClick ))
    End Sub

		private sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      Fecha(Resource.MNU_CON_PAISES)
			e.Skip()
		End Sub
    
    private sub OnBtnFechar(ByVal sender As Object, ByVal e As wx.Event)
      Fecha(0)
      e.Skip()
    end sub
    
    private sub OnBtnLimpar(ByVal sender As Object, ByVal e As wx.Event)
      LimparDados()
      e.Skip()
    end sub
    
    private sub OnBtnPesquisar(ByVal sender As Object, ByVal e As wx.Event)
      PesquisarDados(ConsultasSQL.ConsSQL.Pais("S","", edtDescricao.Value), _
        Resource.STR_PAISNENC, 2)
      e.Skip()
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

	End Class

End Namespace
