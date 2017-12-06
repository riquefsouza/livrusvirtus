using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmConLivros : frmConsultas
	{
		public static frmConLivros fConLivros;

		public frmConLivros(wx.Window parent)
      : base(parent){

      Title = Resource.STR_CONLIVRO;
      labDescricao.Label = "Livro: ";
      gridConsulta.SetColLabelValue(0, "ISBN");
      gridConsulta.SetColSize(0, 80);
      gridConsulta.SetColLabelValue(1, "Título");
      gridConsulta.SetColSize(1, 180);
  
      int[] nLargura = new int[10] { 80,90,80,80,100,80,100,80,80,80 };
      string[] sRotulos = new string[10] { "Edição", "AnoPublicação", 
        "Volume", "CodEditora", "Editora", "CodIdioma", "Idioma",
        "NumPáginas", "Preço", "Estoque" };
      RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 10, 
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
      Fecha(Resource.MNU_CON_LIVROS);
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
      PesquisarDados(ConsultasSQL.ConsSQL.Livro('S',"", edtDescricao.Value,
        "","","","","","","",""),Resource.STR_LIVNENC, 12);
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
