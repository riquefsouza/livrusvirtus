Imports System
Imports System.Drawing
Imports System.Collections
Imports System.Data.OleDb
Imports wx

Namespace Livrus

	Public Class frmCadastros
		Inherits wx.Panel
		
		protected Enum idt
     ID_FRMCADASTROS_BTNANTERIOR = 400
     ID_FRMCADASTROS_BTNEXCLUIR
     ID_FRMCADASTROS_BTNFECHAR
     ID_FRMCADASTROS_BTNLIMPAR
     ID_FRMCADASTROS_BTNNOVO
     ID_FRMCADASTROS_BTNPESQUISAR
     ID_FRMCADASTROS_BTNPROXIMO
     ID_FRMCADASTROS_BTNSALVAR
     ID_FRMCADASTROS_EDTCODIGO
     ID_FRMCADASTROS_EDTDESCRICAO
     ID_FRMCADASTROS_LABCODIGO
     ID_FRMCADASTROS_LABDESCRICAO
    end Enum

		protected Registros as ArrayList
		protected Campos as ArrayList
		protected nLinhaRegistro as integer

		protected labCodigo as wx.StaticText
		protected edtCodigo as TextValidatorCtrl
		protected labDescricao as wx.StaticText
		protected edtDescricao as wx.TextCtrl
		protected btnNovo as wx.Button
		protected btnPesquisar as wx.Button
		protected btnAnterior as wx.Button
		protected btnProximo as wx.Button
		protected btnFechar as wx.Button
		protected btnLimpar as wx.Button
		protected btnExcluir as wx.Button
		protected btnSalvar as wx.Button
		protected Arquiva as OleDbCommand

    Public Sub New(ByVal parent as Window, ByVal nFiltroCodigo as integer, _
      ByVal bIniciaBotoes as boolean)
      MyBase.New(parent, -1, new Point(0, 0), new Size(330, 140))

      labCodigo = new wx.StaticText(Me, idt.ID_FRMCADASTROS_LABCODIGO, _
        "Código:", new Point(8, 8), new Size(36, 13), 0)          
      edtCodigo = new TextValidatorCtrl(Me, idt.ID_FRMCADASTROS_EDTCODIGO, _
        "", new Point(8, 24), new Size(121, 21), 0, nFiltroCodigo)  
      btnNovo = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNNOVO, _
      	"&Novo", new Point(144, 24), new Size(75, 25), 0)
      labDescricao = new wx.StaticText(Me, idt.ID_FRMCADASTROS_LABDESCRICAO, _
        "Descrição:", new Point(8, 48), new Size(51, 13), 0)  
      edtDescricao = new wx.TextCtrl(Me, idt.ID_FRMCADASTROS_EDTDESCRICAO, _
        "", new Point(8, 64), new Size(217, 21), 0)  
    
      if bIniciaBotoes then
        IniciaBotoes()
        FazLayout()
      end if
      edtCodigo.MaxLength = 10
      edtDescricao.MaxLength = 30
      Registros = new ArrayList()
      nLinhaRegistro = 0
    End Sub

    ' Necessário por causa da tabulação dos campos
    protected sub IniciaBotoes()
      btnPesquisar = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNPESQUISAR, _
        "&Pesquisar", new Point(248, 8), new Size(75, 25), 0)  
      btnAnterior = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNANTERIOR, _
        "&Anterior", new Point(248, 40), new Size(75, 25), 0)  
      btnProximo = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNPROXIMO, _
        "Próxi&mo", new Point(248, 72), new Size(75, 25), 0)  
      btnSalvar = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNSALVAR, _
        "&Salvar", new Point(8, 104), new Size(75, 25), 0)  
      btnExcluir = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNEXCLUIR, _
        "&Excluir", new Point(88, 104), new Size(75, 25), 0)  
      btnLimpar = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNLIMPAR, _
        "&Limpar", new Point(168, 104), new Size(75, 25), 0) 
      btnFechar = new wx.Button(Me, idt.ID_FRMCADASTROS_BTNFECHAR, _
        "&Fechar", new Point(248, 104), new Size(75, 25), 0)  
    
      btnLimparClick()
    end sub
    
    private sub FazLayout()
      dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_3 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_5 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim grid_sizer_2 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_1 as wx.GridSizer = new wx.GridSizer(2, 2, 0, 1)
      grid_sizer_1.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_1.Add(20, 10, 0, 0, 0)
      grid_sizer_1.Add(edtCodigo, 0, 0, 0)
      grid_sizer_1.Add(btnNovo, 0, wx.Direction.wxLEFT, 6)
      sizer_5.Add(grid_sizer_1, 0, 0, 0)
      grid_sizer_2.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_2.Add(edtDescricao, 0, 0, 2)
      sizer_5.Add(grid_sizer_2, 0, 0, 0)
      sizer_3.Add(sizer_5, 1, 0, 0)
      sizer_4.Add(btnPesquisar, 0, wx.Direction.wxALL or _ 
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_4.Add(btnAnterior, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_4.Add(btnProximo, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_3.Add(sizer_4, 0, wx.Alignment.wxALIGN_RIGHT, 0)
      sizer_1.Add(sizer_3, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 4)
      sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_2.Add(btnExcluir, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_2.Add(btnFechar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_1.Add(sizer_2, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 4)
      AutoLayout = true
      SetSizer(sizer_1)
      sizer_1.Fit(Me)
      sizer_1.SetSizeHints(Me)
    end sub

		protected Overridable sub InformaLimpaDados(bInformar as boolean)
			if bInformar then
			  Campos = CType(Registros(nLinhaRegistro),ArrayList)
			  edtCodigo.Value=Campos(0).ToString()
			  edtDescricao.Value=Campos(1).ToString()
			else
			  edtCodigo.Clear()
			  edtDescricao.Clear()
			  edtCodigo.Enabled = true
			  edtCodigo.SetFocus()
			end if
		end sub

		protected Overridable sub HabilitaDados(bHabilita as boolean)
			edtDescricao.Enabled = bHabilita
		end sub

		protected sub btnNovoClick()
			btnSalvar.Enabled = true
			btnExcluir.Enabled = false
			btnPesquisar.Enabled = false
			btnAnterior.Enabled = false
			btnProximo.Enabled = false
			btnNovo.Enabled = false

      nLinhaRegistro = 0
			InformaLimpaDados(false)
			HabilitaDados(true)
		end sub

		protected sub NovoDado(sTextoSql as string)
      if RotinasGlobais.Rotinas.ConsultaDadosLista(Registros, sTextoSql) then
        Campos = CType(Registros(0), ArrayList)
        edtCodigo.Value = Campos(0).ToString()
        edtCodigo.Enabled = false
        edtDescricao.SetFocus()
      end if
		end sub

		protected sub btnLimparClick()
			btnSalvar.Enabled = false
			btnExcluir.Enabled = false
			btnPesquisar.Enabled = true
			btnAnterior.Enabled = false
			btnProximo.Enabled = false
			btnNovo.Enabled = true

      nLinhaRegistro = 0
			InformaLimpaDados(false)
			HabilitaDados(false)
		end sub

		protected function ExcluirDados(bValidaDados as boolean, _
      sTextoSql as string) as boolean
      if bValidaDados then
        if wx.MessageDialog.MessageBox(Resource.STR_CERTEXCL, "Confirme", _
         wx.Dialog.wxICON_QUESTION or wx.Dialog.wxYES_NO) = wx.Dialog.wxYES then
          if RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sTextoSql) then
             btnLimparClick()
             return true
          end if
        end if
      end if
      return false
		end function

		protected function PesquisarDados(sTextoSql as string, _
      sMensagemErro as string) as boolean
			if edtCodigo.Value.Length = 0 then
			  btnAnterior.Enabled = true
			  btnProximo.Enabled = true
			end if

			if RotinasGlobais.Rotinas.ConsultaDadosLista(Registros,sTextoSql) then
				 InformaLimpaDados(true)
				 HabilitaDados(true)

				 btnSalvar.Enabled = true
				 btnExcluir.Enabled = true
				 btnPesquisar.Enabled = false
         return true
			else
			  wx.MessageDialog.MessageBox(sMensagemErro, "Erro", _
          wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
      end if
      return false
		end function

		protected function registroAnterior() as boolean
			if nLinhaRegistro > 0 then
				nLinhaRegistro=nLinhaRegistro - 1
				InformaLimpaDados(true)
        return true
      else
        return false
      end if
		end function

		protected function registroProximo() as boolean
			if nLinhaRegistro < (Registros.Count-1) then
				nLinhaRegistro=nLinhaRegistro + 1
				InformaLimpaDados(true)
        return true
      else
        return false
      end if
		end function

		protected function SalvarDados(bValidaDados as boolean, _
      sTextoSql as string, sTextoUpdate as string, sTextoInsert as string, _
      bLimparDados as boolean) as boolean
      dim Consulta as OleDbCommand = new OleDbCommand()
      dim sArquiva as string
    
    	if bValidaDados then 
    	   if RotinasGlobais.Rotinas.ConsultaDados(Consulta,sTextoSql) then
           sArquiva = sTextoUpdate
         else
      	   sArquiva = sTextoInsert	  	     
         end if
         if RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sArquiva) then
      	   if bLimparDados then
             btnLimparClick()
           end if
           return true
         end if
    	end if
      return false
		end function

	End Class

End Namespace
