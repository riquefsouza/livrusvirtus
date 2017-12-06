using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmConEnderecos : frmConsultas
	{
		public static frmConEnderecos fConEnderecos;

		public frmConEnderecos(wx.Window parent)
      : base(parent){

      Title = Resource.STR_CONENDERECO;
      labDescricao.Label = "Endereço: ";
      gridConsulta.SetColLabelValue(1, "Logradouro");
      gridConsulta.SetColSize(1, 200);
 
      int[] nLargura = new int[4] { 150,80,100,80 };
      string[] sRotulos = new string[4] { "Bairro", 
        "CEP", "Cidade", "Estado" };
      RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 4, 
        nLargura, sRotulos);

      EVT_BUTTON((int)idt.ID_FRMCONSULTAS_BTNPESQUISAR, 
        new EventListener( OnBtnPesquisar ));
      EVT_BUTTON((int)idt.ID_FRMCONSULTAS_BTNLIMPAR, 
        new EventListener( OnBtnLimpar ));
      EVT_BUTTON((int)idt.ID_FRMCONSULTAS_BTNFECHAR, 
        new EventListener( OnBtnFechar ));
      EVT_CLOSE(new EventListener( OnClose ));
      EVT_GRID_SELECT_CELL(new EventListener( OnGridSelectCell ));
      EVT_GRID_LABEL_LEFT_CLICK(new EventListener( OnGridLabelLeftClick ));
		}

    private void OnClose( object sender, Event e ){
      Fecha(Resource.MNU_CON_ENDERECOS);
      e.Skip();
    }
    
    private void OnBtnFechar( object sender, Event e ){
      Fecha(0);
      e.Skip();
    }
    
    private void OnBtnLimpar( object sender, Event e ){
      LimparDados();
      e.Skip();
    }
    
    private void OnBtnPesquisar( object sender, Event e ){
      PesquisarDados(ConsultasSQL.ConsSQL.Endereco('S',"", edtDescricao.Value,
        "","","",""), Resource.STR_ENDNENC, 6);
      e.Skip();
    }
    
    private void OnGridSelectCell( object sender, Event e ){
      wx.GridEvent evt = (wx.GridEvent)e;
      setLabRegistros(evt.Row);
      e.Skip();
    }
    
    private void OnGridLabelLeftClick( object sender, Event e ){
      wx.GridEvent evt = (wx.GridEvent)e;
      setLabRegistros(evt.Row);
      e.Skip();
    }

	}
}
