using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmConClientes : frmConsultas
	{
		public static frmConClientes fConClientes;

		public frmConClientes(wx.Window parent)
      : base(parent){

      Title = Resource.STR_CONCLIENTE;
      labDescricao.Label = "Cliente: ";
      gridConsulta.SetColLabelValue(0, "CPF");
      gridConsulta.SetColSize(0, 90);
      gridConsulta.SetColLabelValue(1, "Nome");
      gridConsulta.SetColSize(1, 220);
  
      int[] nLargura = new int[15] { 180,80,40,80,120,80,220,150, 
        80,100,100,80,180,80,100 };
      string[] sRotulos = new string[15] { "Email", "Identidade", "Sexo", 
       "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
       "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
       "CodProfissão", "Profissão" };
      RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 15, 
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
      Fecha(Resource.MNU_CON_CLIENTES);
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
      PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S',"", edtDescricao.Value,
        "","","","","","","",""), Resource.STR_CLINENC, 17);
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
