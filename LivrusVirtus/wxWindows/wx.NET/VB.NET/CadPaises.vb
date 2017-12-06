Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class frmCadPaises
		Inherits frmCadastros
		
		public shared WithEvents fCadPaises as frmCadPaises

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, TextValidatorCtrl.FILTER_ALPHA, true)

      labDescricao.Label = "País: "
      edtCodigo.MaxLength = 3

      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNNOVO, _
        new EventListener(AddressOf OnBtnNovo ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNPESQUISAR, _
        new EventListener(AddressOf OnBtnPesquisar ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNANTERIOR, _
        new EventListener(AddressOf OnBtnAnterior ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNPROXIMO, _
        new EventListener(AddressOf OnBtnProximo ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNSALVAR, _
        new EventListener(AddressOf OnBtnSalvar ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNEXCLUIR, _
        new EventListener(AddressOf OnBtnExcluir ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNLIMPAR, _
        new EventListener(AddressOf OnBtnLimpar ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNFECHAR, _
        new EventListener(AddressOf OnBtnFechar ))
			EVT_CLOSE( new EventListener(AddressOf OnClose ) )
    End Sub

		private function ValidaDados(bTodosDados as boolean)
      if RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, _
        Resource.STR_CODNINF) then
        return false
      end if
      if bTodosDados then
        if RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Value, _
          Resource.STR_PAISNINF) then
        	return false
        end if
      end if
			return true
		end function

		private sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      Me.Parent.Close()
			e.Skip()
		End Sub
    
    private sub OnBtnNovo(ByVal sender As Object, ByVal e As wx.Event)
      btnNovoClick()
      e.Skip()
    end sub
    
    private sub OnBtnPesquisar(ByVal sender As Object, ByVal e As wx.Event)
      PesquisarDados(ConsultasSQL.ConsSQL.Pais("S", edtCodigo.Value,""), _
        Resource.STR_PAISNENC)
      e.Skip()
    end sub
    
    private sub OnBtnAnterior(ByVal sender As Object, ByVal e As wx.Event)
      registroAnterior()	
      e.Skip()
    end sub
    
    private sub OnBtnProximo(ByVal sender As Object, ByVal e As wx.Event)
      registroProximo()		
      e.Skip()
    end sub
    
    private sub OnBtnSalvar(ByVal sender As Object, ByVal e As wx.Event)
      SalvarDados(ValidaDados(true), _
        ConsultasSQL.ConsSQL.Pais("S", edtCodigo.Value,""), _
        ConsultasSQL.ConsSQL.Pais("U", edtCodigo.Value, _
          edtDescricao.Value), _
        ConsultasSQL.ConsSQL.Pais("I", edtCodigo.Value, _
          edtDescricao.Value), true)
      e.Skip()
    end sub
    
    private sub OnBtnExcluir(ByVal sender As Object, ByVal e As wx.Event)
      ExcluirDados(ValidaDados(false), _
        ConsultasSQL.ConsSQL.Pais("D", edtCodigo.Value,""))
      e.Skip()
    end sub
    
    private sub OnBtnFechar(ByVal sender As Object, ByVal e As wx.Event)
      Me.Close(true)
      e.Skip()
    end sub
    
    private sub OnBtnLimpar(ByVal sender As Object, ByVal e As wx.Event)
      btnLimparClick()
      e.Skip()
    end sub

	End Class

End Namespace
