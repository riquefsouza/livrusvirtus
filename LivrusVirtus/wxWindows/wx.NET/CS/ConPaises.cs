using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmConPaises : frmConsultas
	{
		public static frmConPaises fConPaises;

		public frmConPaises(wx.Window parent)
      : base(parent){

      Title = Resource.STR_CONPAIS;
      labDescricao.Label = "País: ";
      gridConsulta.SetColLabelValue(1, "País");

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
      Fecha(Resource.MNU_CON_PAISES);
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
      PesquisarDados(ConsultasSQL.ConsSQL.Pais('S',"", edtDescricao.Value),
        Resource.STR_PAISNENC, 2);
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
