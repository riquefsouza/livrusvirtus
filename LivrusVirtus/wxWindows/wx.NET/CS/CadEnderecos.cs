using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmCadEnderecos: frmCadastros
	{
		private enum idx {
      ID_FRMCADENDERECOS_CMBESTADO = 700, ID_FRMCADENDERECOS_EDTBAIRRO, 
      ID_FRMCADENDERECOS_EDTCEP, ID_FRMCADENDERECOS_EDTCIDADE, 
      ID_FRMCADENDERECOS_LABBAIRRO, ID_FRMCADENDERECOS_LABCEP, 
      ID_FRMCADENDERECOS_LABCIDADE, ID_FRMCADENDERECOS_LABESTADO }

		private wx.StaticText labBairro;
		private wx.TextCtrl edtBairro;
		private wx.TextCtrl edtCEP;
		private wx.StaticText labCEP;
		private wx.TextCtrl edtCidade;
		private wx.StaticText labCidade;
		private wx.StaticText labEstado;
		private wx.Choice cmbEstado;
    private string[] vsEstados;

		public frmCadEnderecos(wx.Window parent)
      : base(parent, TextValidatorCtrl.FILTER_NUMERIC, false){

      ClientSize = new Size(523, 171);
      labDescricao.Label = "Logradouro:";
      labDescricao.Size = new Size(57, 13);
      edtDescricao.Size = new Size(264, 21);
    
    	labBairro = new wx.StaticText(this, (int)idx.ID_FRMCADENDERECOS_LABBAIRRO, 
        "Bairro:", new Point(280, 48), new Size(48, 13) );
    	edtBairro = new wx.TextCtrl(this, (int)idx.ID_FRMCADENDERECOS_EDTBAIRRO,
        "", new Point(280, 64), new Size(144, 21) );
      edtBairro.Enabled = false;
    	labCEP = new wx.StaticText(this, (int)idx.ID_FRMCADENDERECOS_LABCEP, 
        "CEP: ", new Point(8, 88), new Size(40, 13) );
    	edtCEP = new wx.TextCtrl(this, (int)idx.ID_FRMCADENDERECOS_EDTCEP, 
        "", new Point(8, 104), new Size(72, 21) );
      edtCEP.Enabled = false;
    	labCidade = new wx.StaticText(this, (int)idx.ID_FRMCADENDERECOS_LABCIDADE, 
        "Cidade: ", new Point(88, 88), new Size(39, 13) );
    	edtCidade = new wx.TextCtrl(this, (int)idx.ID_FRMCADENDERECOS_EDTCIDADE, 
        "", new Point(88, 104), new Size(184, 21) );
      edtCidade.Enabled = false;
    	labEstado = new wx.StaticText(this, (int)idx.ID_FRMCADENDERECOS_LABESTADO, 
        "Estado: ", new Point(280, 88), new Size(56, 13) );
      AdicionaCombo();
    	cmbEstado = new wx.Choice(this, (int)idx.ID_FRMCADENDERECOS_CMBESTADO, 
        new Point(280, 104), new Size(144, 21), vsEstados );
      cmbEstado.Enabled = false;
  
      IniciaBotoes();
    
      btnPesquisar.SetSize(440, 8, 75, 25);
      btnAnterior.SetSize(440, 40, 75, 25);
      btnProximo.SetSize(440, 72, 75, 25);
      btnSalvar.SetSize(200, 136, 75, 25);
      btnExcluir.SetSize(280, 136, 75, 25);
      btnLimpar.SetSize(360, 136, 75, 25);
      btnFechar.SetSize(440, 136, 75, 25);
    
      //FazLayout();
    
      edtDescricao.MaxLength = 40;
      edtBairro.MaxLength = 15;
      edtCEP.MaxLength = 8;
      edtCidade.MaxLength = 30;

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

    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_3 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_5 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_6 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_6 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_5 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_4 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_8 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_9 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_8 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_7 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_7 = new wx.GridSizer(2, 1, 0, 0);
      grid_sizer_7.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_7.Add(edtCodigo, 0, 0, 0);
      sizer_7.Add(grid_sizer_7, 0, 0, 0);
      sizer_7.Add(btnNovo, 0, wx.Direction.wxLEFT|wx.Alignment.wxALIGN_BOTTOM, 5);
      sizer_5.Add(sizer_7, 1, 0, 0);
      grid_sizer_8.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_8.Add(edtDescricao, 0, 0, 0);
      sizer_8.Add(grid_sizer_8, 0, 0, 0);
      grid_sizer_9.Add(labBairro, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_9.Add(edtBairro, 0, 0, 0);
      sizer_8.Add(grid_sizer_9, 0, wx.Direction.wxLEFT, 2);
      sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0);
      grid_sizer_4.Add(labCEP, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_4.Add(edtCEP, 0, 0, 0);
      sizer_6.Add(grid_sizer_4, 0, 0, 0);
      grid_sizer_5.Add(labCidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_5.Add(edtCidade, 0, 0, 0);
      sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4);
      grid_sizer_6.Add(labEstado, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_6.Add(cmbEstado, 0, 0, 0);
      sizer_6.Add(grid_sizer_6, 0, wx.Direction.wxLEFT, 5);
      sizer_5.Add(sizer_6, 0, 0, 0);
      sizer_3.Add(sizer_5, 0, 0, 0);
      sizer_4.Add(btnPesquisar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_4.Add(btnAnterior, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_4.Add(btnProximo, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_3.Add(sizer_4, 1, 0, 0);
      sizer_1.Add(sizer_3, 1, wx.Direction.wxALL|wx.Stretch.wxEXPAND, 4);
      sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnExcluir, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnFechar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_1.Add(sizer_2, 0, wx.Direction.wxRIGHT|wx.Direction.wxBOTTOM|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 4);
      AutoLayout = true;
      SetSizer(sizer_1);
      sizer_1.Fit(this);
      sizer_1.SetSizeHints(this);
    }

		private bool ValidaDados(bool bTodosDados){
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, 
        Resource.STR_CODNINF))
        return false;
      if (bTodosDados) {
        if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Value, 
          Resource.STR_ENDNINF))
        	return false;
        if (RotinasGlobais.Rotinas.ValidaCampo(edtBairro.Value, 
          Resource.STR_BAIRRONINF))
        	return false;
        if (RotinasGlobais.Rotinas.ValidaCampo(edtCEP.Value, 
          Resource.STR_CEPNINF))
        	return false;
        if (RotinasGlobais.Rotinas.ValidaCampo(edtCidade.Value, 
          Resource.STR_CIDADENINF))
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
      InformaLimpaDados(false);
      HabilitaDados(true);
      NovoDado(ConsultasSQL.ConsSQL.Endereco('N', edtCodigo.Value,
        "","","","",""));	
      e.Skip();
    }
    
    private void OnBtnPesquisar( object sender, Event e ){
      if (PesquisarDados(ConsultasSQL.ConsSQL.Endereco('S', edtCodigo.Value,
        "","","","",""), Resource.STR_ENDNENC)) {
        InformaLimpaDados(true);
        HabilitaDados(true);
      }
      e.Skip();
    }
    
    private void OnBtnAnterior( object sender, Event e ){
      if (registroAnterior())
        InformaLimpaDados(true);
      e.Skip();
    }
    
    private void OnBtnProximo( object sender, Event e ){
      if (registroProximo())
        InformaLimpaDados(true);
      e.Skip();
    }
    
    private void OnBtnSalvar( object sender, Event e ){
      if (SalvarDados(ValidaDados(true),
        ConsultasSQL.ConsSQL.Endereco('S', edtCodigo.Value,
          edtDescricao.Value,"","","",""),
        ConsultasSQL.ConsSQL.Endereco('U', edtCodigo.Value, 
          edtDescricao.Value,edtBairro.Value,edtCEP.Value,
          edtCidade.Value,cmbEstado.StringSelection),
        ConsultasSQL.ConsSQL.Endereco('I', edtCodigo.Value, 
          edtDescricao.Value,edtBairro.Value,edtCEP.Value,
          edtCidade.Value,cmbEstado.StringSelection), true)) {
        InformaLimpaDados(false);
        HabilitaDados(false);
      }
      e.Skip();
    }
    
    private void OnBtnExcluir( object sender, Event e ){
      if (ExcluirDados(ValidaDados(false),
        ConsultasSQL.ConsSQL.Endereco('D', edtCodigo.Value,
        "","","","",""))){
        InformaLimpaDados(false);
        HabilitaDados(false);
      }
      e.Skip();
    }
    
    private void OnBtnFechar( object sender, Event e ){
      this.Close(true);
      e.Skip();
    }
    
    private void OnBtnLimpar( object sender, Event e ){
      btnLimparClick();
      InformaLimpaDados(false);
      HabilitaDados(false);
      e.Skip();
    }

    protected override void InformaLimpaDados(bool bInformar){
      base.InformaLimpaDados(bInformar);

      if (bInformar) {
        edtBairro.Value = Campos[2].ToString();
        edtCEP.Value = Campos[3].ToString();
        edtCidade.Value = Campos[4].ToString();
        cmbEstado.StringSelection = Campos[5].ToString();
      } else {
        edtBairro.Clear();
        edtCEP.Clear();
        edtCidade.Clear();
        cmbEstado.Selection = 0;
      }
    }
    
    protected override void HabilitaDados(bool bHabilita){
			base.HabilitaDados(bHabilita);

      edtBairro.Enabled = bHabilita;
      edtCEP.Enabled = bHabilita;  
      edtCidade.Enabled = bHabilita;
      cmbEstado.Enabled = bHabilita;  
    }
  
    private void AdicionaCombo(){
      vsEstados = new string[26];
      vsEstados.SetValue(Resource.STR_PE, 0);
      vsEstados.SetValue(Resource.STR_AC, 1);
      vsEstados.SetValue(Resource.STR_AL, 2);
      vsEstados.SetValue(Resource.STR_AP, 3);
      vsEstados.SetValue(Resource.STR_AM, 4);
      vsEstados.SetValue(Resource.STR_BA, 5);
      vsEstados.SetValue(Resource.STR_BR, 6);
      vsEstados.SetValue(Resource.STR_CE, 7);
      vsEstados.SetValue(Resource.STR_DF, 8);
      vsEstados.SetValue(Resource.STR_ES, 9);
      vsEstados.SetValue(Resource.STR_GO, 10);
      vsEstados.SetValue(Resource.STR_MT, 11);
      vsEstados.SetValue(Resource.STR_MS, 12);
      vsEstados.SetValue(Resource.STR_MG, 13);
      vsEstados.SetValue(Resource.STR_PA, 14);
      vsEstados.SetValue(Resource.STR_PB, 15);
      vsEstados.SetValue(Resource.STR_PR, 16);
      vsEstados.SetValue(Resource.STR_SC, 17);
      vsEstados.SetValue(Resource.STR_RN, 18);
      vsEstados.SetValue(Resource.STR_RS, 19);
      vsEstados.SetValue(Resource.STR_RJ, 20);
      vsEstados.SetValue(Resource.STR_RO, 21);
      vsEstados.SetValue(Resource.STR_RR, 22);
      vsEstados.SetValue(Resource.STR_SP, 23);
      vsEstados.SetValue(Resource.STR_SE, 24);
      vsEstados.SetValue(Resource.STR_TO, 25);
    }
	}
}
