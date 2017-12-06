Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class frmConEnderecos
		Inherits frmConsultas
		
		public shared WithEvents fConEnderecos as frmConEnderecos

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent)

      Title = Resource.STR_CONENDERECO
      labDescricao.Label = "Endereço: "
      gridConsulta.SetColLabelValue(1, "Logradouro")
      gridConsulta.SetColSize(1, 200)
 
      dim nLargura() as integer = { 150,80,100,80 }
      dim sRotulos() as string = { "Bairro", _
        "CEP", "Cidade", "Estado" }
      RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 4, _
        nLargura, sRotulos)

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
      Fecha(Resource.MNU_CON_ENDERECOS)
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
      PesquisarDados(ConsultasSQL.ConsSQL.Endereco("S","", edtDescricao.Value, _
        "","","",""), Resource.STR_ENDNENC, 6)
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
