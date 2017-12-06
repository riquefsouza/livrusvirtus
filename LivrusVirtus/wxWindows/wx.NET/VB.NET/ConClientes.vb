Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class frmConClientes
		Inherits frmConsultas
		
		public shared WithEvents fConClientes as frmConClientes

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent)

      Title = Resource.STR_CONCLIENTE
      labDescricao.Label = "Cliente:  "
      gridConsulta.SetColLabelValue(1, "Cliente")

      gridConsulta.SetColLabelValue(0, "CPF")
      gridConsulta.SetColSize(0, 90)
      gridConsulta.SetColLabelValue(1, "Nome")
      gridConsulta.SetColSize(1, 220)
  
      dim nLargura() as integer = { 180,80,40,80,120,80,220,150, _
        80,100,100,80,180,80,100 }
      dim sRotulos() as string = { "Email", "Identidade", "Sexo", _
       "Telefone", "DtNascimento", "CodEndereço", "Logradouro", _
       "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", _
       "CodProfissão", "Profissão" }
      RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 15, _
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
      Fecha(Resource.MNU_CON_CLIENTES)
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
      PesquisarDados(ConsultasSQL.ConsSQL.Cliente("S","", edtDescricao.Value, _
        "","","","","","","",""), Resource.STR_CLINENC, 17)
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
