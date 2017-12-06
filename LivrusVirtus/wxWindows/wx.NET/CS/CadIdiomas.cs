using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmCadIdiomas: frmCadastros
	{
		public frmCadIdiomas(wx.Window parent)
      : base(parent, TextValidatorCtrl.FILTER_NUMERIC, true){

      labDescricao.Label = "Idioma: ";

      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNNOVO, new EventListener( OnBtnNovo ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNPESQUISAR, new EventListener( OnBtnPesquisar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNANTERIOR, new EventListener( OnBtnAnterior ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNPROXIMO, new EventListener( OnBtnProximo ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNSALVAR, new EventListener( OnBtnSalvar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNEXCLUIR, new EventListener( OnBtnExcluir ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNLIMPAR, new EventListener( OnBtnLimpar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNFECHAR, new EventListener( OnBtnFechar ));
			EVT_CLOSE( new EventListener( OnClose ) );
    }

		private bool ValidaDados(bool bTodosDados){
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, 
        Resource.STR_CODNINF))
        return false;
      if (bTodosDados) {
        if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Value, 
          Resource.STR_IDININF))
        	return false;
      }
			return true;
		}

    private void OnClose( object sender, Event e ){
      this.Parent.Close();
      e.Skip();
    }
    
    private void OnBtnNovo( object sender, Event e ){
      btnNovoClick();
      NovoDado(ConsultasSQL.ConsSQL.Idioma('N', edtCodigo.Value,""));	
      e.Skip();
    }
    
    private void OnBtnPesquisar( object sender, Event e ){
      PesquisarDados(ConsultasSQL.ConsSQL.Idioma('S', edtCodigo.Value,""), 
        Resource.STR_IDINENC);
      e.Skip();
    }
    
    private void OnBtnAnterior( object sender, Event e ){
      registroAnterior();	
      e.Skip();
    }
    
    private void OnBtnProximo( object sender, Event e ){
      registroProximo();		
      e.Skip();
    }
    
    private void OnBtnSalvar( object sender, Event e ){
      SalvarDados(ValidaDados(true),
        ConsultasSQL.ConsSQL.Idioma('S', edtCodigo.Value,""),
        ConsultasSQL.ConsSQL.Idioma('U', edtCodigo.Value, 
          edtDescricao.Value),
        ConsultasSQL.ConsSQL.Idioma('I', edtCodigo.Value, 
          edtDescricao.Value), true);
      e.Skip();
    }
    
    private void OnBtnExcluir( object sender, Event e ){
      ExcluirDados(ValidaDados(false),
        ConsultasSQL.ConsSQL.Idioma('D', edtCodigo.Value,""));
      e.Skip();
    }
    
    private void OnBtnFechar( object sender, Event e ){
      this.Close(true);
      e.Skip();
    }
    
    private void OnBtnLimpar( object sender, Event e ){
      btnLimparClick();
      e.Skip();
    }
	}
}
