using System;
using System.Drawing;
using System.Collections;
using System.Data.OleDb;
using wx;

namespace Livrus
{
	public class frmCadastros: wx.Panel
	{
		protected enum idt {
     ID_FRMCADASTROS_BTNANTERIOR = 400, ID_FRMCADASTROS_BTNEXCLUIR, 
     ID_FRMCADASTROS_BTNFECHAR, ID_FRMCADASTROS_BTNLIMPAR, 
     ID_FRMCADASTROS_BTNNOVO, ID_FRMCADASTROS_BTNPESQUISAR, 
     ID_FRMCADASTROS_BTNPROXIMO, ID_FRMCADASTROS_BTNSALVAR, 
     ID_FRMCADASTROS_EDTCODIGO, ID_FRMCADASTROS_EDTDESCRICAO, 
     ID_FRMCADASTROS_LABCODIGO, ID_FRMCADASTROS_LABDESCRICAO }

		protected ArrayList Registros;
		protected ArrayList Campos;
		protected int nLinhaRegistro;

		protected wx.StaticText labCodigo;
		protected TextValidatorCtrl edtCodigo;
		protected wx.StaticText labDescricao;
		protected wx.TextCtrl edtDescricao;
		protected wx.Button btnNovo;
		protected wx.Button btnPesquisar;
		protected wx.Button btnAnterior;
		protected wx.Button btnProximo;
		protected wx.Button btnFechar;
		protected wx.Button btnLimpar;
		protected wx.Button btnExcluir;
		protected wx.Button btnSalvar;
		protected OleDbCommand Arquiva;

		public frmCadastros(wx.Window parent, int nFiltroCodigo, 
      bool bIniciaBotoes) 
      : base(parent, -1, new Point(0, 0), new Size(330, 140)){

      labCodigo = new wx.StaticText(this, (int)idt.ID_FRMCADASTROS_LABCODIGO,
        "Código:", new Point(8, 8), new Size(36, 13), 0);          
      edtCodigo = new TextValidatorCtrl(this, (int)idt.ID_FRMCADASTROS_EDTCODIGO,
        "", new Point(8, 24), new Size(121, 21), 0, nFiltroCodigo);  
      btnNovo = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNNOVO, 
      	"&Novo", new Point(144, 24), new Size(75, 25), 0);
      labDescricao = new wx.StaticText(this, (int)idt.ID_FRMCADASTROS_LABDESCRICAO,
        "Descrição:", new Point(8, 48), new Size(51, 13), 0);  
      edtDescricao = new wx.TextCtrl(this, (int)idt.ID_FRMCADASTROS_EDTDESCRICAO,
        "", new Point(8, 64), new Size(217, 21), 0);  
    
      if (bIniciaBotoes) {
        IniciaBotoes();
        FazLayout();
      }
      edtCodigo.MaxLength = 10;
      edtDescricao.MaxLength = 30;
      Registros = new ArrayList();
      nLinhaRegistro = 0;
		}

    // Necessário por causa da tabulação dos campos
    protected void IniciaBotoes() {
      btnPesquisar = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNPESQUISAR,
        "&Pesquisar", new Point(248, 8), new Size(75, 25), 0);  
      btnAnterior = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNANTERIOR,
        "&Anterior", new Point(248, 40), new Size(75, 25), 0);  
      btnProximo = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNPROXIMO,
        "Próxi&mo", new Point(248, 72), new Size(75, 25), 0);  
      btnSalvar = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNSALVAR,
        "&Salvar", new Point(8, 104), new Size(75, 25), 0);  
      btnExcluir = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNEXCLUIR,
        "&Excluir", new Point(88, 104), new Size(75, 25), 0);  
      btnLimpar = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNLIMPAR,
        "&Limpar", new Point(168, 104), new Size(75, 25), 0); 
      btnFechar = new wx.Button(this, (int)idt.ID_FRMCADASTROS_BTNFECHAR,
        "&Fechar", new Point(248, 104), new Size(75, 25), 0);  
    
      btnLimparClick();
    }
    
    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_3 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_5 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.GridSizer grid_sizer_2 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_1 = new wx.GridSizer(2, 2, 0, 1);
      grid_sizer_1.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_1.Add(20, 10, 0, 0, 0);
      grid_sizer_1.Add(edtCodigo, 0, 0, 0);
      grid_sizer_1.Add(btnNovo, 0, wx.Direction.wxLEFT, 6);
      sizer_5.Add(grid_sizer_1, 0, 0, 0);
      grid_sizer_2.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_2.Add(edtDescricao, 0, 0, 2);
      sizer_5.Add(grid_sizer_2, 0, 0, 0);
      sizer_3.Add(sizer_5, 1, 0, 0);
      sizer_4.Add(btnPesquisar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_4.Add(btnAnterior, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_4.Add(btnProximo, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_3.Add(sizer_4, 0, wx.Alignment.wxALIGN_RIGHT, 0);
      sizer_1.Add(sizer_3, 1, wx.Direction.wxALL|wx.Stretch.wxEXPAND, 4);
      sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnExcluir, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnFechar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_1.Add(sizer_2, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 4);
      AutoLayout = true;
      SetSizer(sizer_1);
      sizer_1.Fit(this);
      sizer_1.SetSizeHints(this);
    }

		protected virtual void InformaLimpaDados(bool bInformar){
			if (bInformar) {
			  Campos = (ArrayList)Registros[nLinhaRegistro];
			  edtCodigo.Value=Campos[0].ToString();
			  edtDescricao.Value=Campos[1].ToString();
			} else {
			  edtCodigo.Clear();
			  edtDescricao.Clear();
			  edtCodigo.Enabled = true;
			  edtCodigo.SetFocus();
			}
		}

		protected virtual void HabilitaDados(bool bHabilita){
			edtDescricao.Enabled = bHabilita;
		}

		protected void btnNovoClick(){
			btnSalvar.Enabled = true;
			btnExcluir.Enabled = false;
			btnPesquisar.Enabled = false;
			btnAnterior.Enabled = false;
			btnProximo.Enabled = false;
			btnNovo.Enabled = false;

      nLinhaRegistro = 0;
			InformaLimpaDados(false);
			HabilitaDados(true);
		}

		protected void NovoDado(string sTextoSql){
      if (RotinasGlobais.Rotinas.ConsultaDadosLista(Registros, sTextoSql)) {
        Campos = (ArrayList)Registros[0];
        edtCodigo.Value = Campos[0].ToString();
        edtCodigo.Enabled = false;
        edtDescricao.SetFocus();
      }
		}

		protected void btnLimparClick(){
			btnSalvar.Enabled = false;
			btnExcluir.Enabled = false;
			btnPesquisar.Enabled = true;
			btnAnterior.Enabled = false;
			btnProximo.Enabled = false;
			btnNovo.Enabled = true;

      nLinhaRegistro = 0;
			InformaLimpaDados(false);
			HabilitaDados(false);
		}

		protected bool ExcluirDados(bool bValidaDados, string sTextoSql){
      if (bValidaDados) {      
        if ( wx.MessageDialog.MessageBox(Resource.STR_CERTEXCL, "Confirme",
         wx.Dialog.wxICON_QUESTION | wx.Dialog.wxYES_NO) == wx.Dialog.wxYES ) {
          if (RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sTextoSql)) {
             btnLimparClick();
             return true;
          }      
        }
      }
      return false;
		}

		protected bool PesquisarDados(string sTextoSql, string sMensagemErro){
			if (edtCodigo.Value.Length==0) {
			  btnAnterior.Enabled = true;
			  btnProximo.Enabled = true;
			}

			if (RotinasGlobais.Rotinas.ConsultaDadosLista(Registros,sTextoSql)) {
				 InformaLimpaDados(true);
				 HabilitaDados(true);

				 btnSalvar.Enabled = true;
				 btnExcluir.Enabled = true;
				 btnPesquisar.Enabled = false;
         return true;
			} else
			  wx.MessageDialog.MessageBox(sMensagemErro, "Erro", 
          wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);

      return false;
		}

		protected bool registroAnterior(){
			if (nLinhaRegistro > 0) {
				nLinhaRegistro=nLinhaRegistro - 1;
				InformaLimpaDados(true);
        return true;
      } else
        return false;
		}

		protected bool registroProximo(){
			if (nLinhaRegistro < (Registros.Count-1)) {
				nLinhaRegistro=nLinhaRegistro + 1;
				InformaLimpaDados(true);
        return true;
      } else
        return false;
		}

		protected bool SalvarDados(bool bValidaDados, string sTextoSql,
      string sTextoUpdate, string sTextoInsert, bool bLimparDados){
      OleDbCommand Consulta = new OleDbCommand();
      string sArquiva;
    
    	if (bValidaDados) {    
    	   if (RotinasGlobais.Rotinas.ConsultaDados(Consulta,sTextoSql))
           sArquiva = sTextoUpdate;
         else
      	   sArquiva = sTextoInsert;	  	     
    
         if (RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sArquiva)) {
      	   if (bLimparDados)
             btnLimparClick();
           return true;
         }
    	}
      return false;
		}

	}
}
