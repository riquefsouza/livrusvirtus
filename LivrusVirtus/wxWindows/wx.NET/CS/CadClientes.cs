using System;
using System.Drawing;
using System.Collections;
using wx;

namespace Livrus
{
	public class frmCadClientes: frmCadastros
	{
    private enum idx {
     ID_FRMCADCLIENTES_BTNPENDERECO = 800, ID_FRMCADCLIENTES_SBENDERECO,
     ID_FRMCADCLIENTES_BTNPPAIS, ID_FRMCADCLIENTES_BTNPPROFISSAO, 
     ID_FRMCADCLIENTES_EDTBAIRRO, ID_FRMCADCLIENTES_EDTCEP, 
     ID_FRMCADCLIENTES_EDTCIDADE, ID_FRMCADCLIENTES_EDTCODENDERECO, 
     ID_FRMCADCLIENTES_EDTCODPAIS, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
     ID_FRMCADCLIENTES_EDTDTNASC, ID_FRMCADCLIENTES_EDTEMAIL, 
     ID_FRMCADCLIENTES_EDTESTADO, ID_FRMCADCLIENTES_EDTIDENTIDADE, 
     ID_FRMCADCLIENTES_EDTLOGRADOURO, ID_FRMCADCLIENTES_EDTPAIS, 
     ID_FRMCADCLIENTES_EDTPROFISSAO, ID_FRMCADCLIENTES_EDTTELEFONE, 
     ID_FRMCADCLIENTES_LABBAIRRO, ID_FRMCADCLIENTES_LABCEP, 
     ID_FRMCADCLIENTES_LABCIDADE, ID_FRMCADCLIENTES_LABDTNASC, 
     ID_FRMCADCLIENTES_LABEMAIL, ID_FRMCADCLIENTES_LABESTADO, 
     ID_FRMCADCLIENTES_LABIDENTIDADE, ID_FRMCADCLIENTES_LABLOGRADOURO, 
     ID_FRMCADCLIENTES_LABPAIS, ID_FRMCADCLIENTES_LABPROFISSAO, 
     ID_FRMCADCLIENTES_LABTELEFONE, ID_FRMCADCLIENTES_RBSEXO }

    private wx.StaticText labEmail;
    private wx.TextCtrl edtEmail;
    private wx.StaticText labIdentidade;
    private wx.TextCtrl edtIdentidade;
    private wx.RadioBox rbSexo;
    private wx.StaticText labTelefone;
    private wx.TextCtrl edtTelefone;
    private wx.StaticText labDtNasc;
    private wx.TextCtrl edtDtNasc;
    private wx.StaticBox sbEndereco;
    private TextValidatorCtrl edtCodEndereco;
    private wx.Button btnPEndereco;
    private wx.StaticText labLogradouro;
    private wx.TextCtrl edtLogradouro;
    private wx.StaticText labBairro;
    private wx.TextCtrl edtBairro;
    private wx.StaticText labCEP;
    private wx.TextCtrl edtCEP;
    private wx.StaticText labCidade;
    private wx.TextCtrl edtCidade;
    private wx.StaticText labEstado;
    private wx.TextCtrl edtEstado;
    private wx.StaticText labPais;
    private TextValidatorCtrl edtCodPais;
    private wx.TextCtrl edtPais;
    private wx.Button btnPPais;
    private wx.StaticText labProfissao;
    private TextValidatorCtrl edtCodProfissao;
    private wx.TextCtrl edtProfissao;
    private wx.Button btnPProfissao;

		public frmCadClientes(wx.Window parent)
      : base(parent, TextValidatorCtrl.FILTER_NONE, false){

      labDescricao.Label = "Nome: ";
      edtDescricao.SetSize(new Size(312, 21));
      edtCodigo.EVT_KILL_FOCUS( new EventListener( OnEdtCodigo_Killfocus ));

      labEmail = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABEMAIL,
                 "E-mail: ", new Point(8, 88), new Size(34, 13), 0);
      edtEmail = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTEMAIL,
                 "", new Point(8, 104), new Size(312, 21), 0);
      edtEmail.Enabled = false;
    
      labIdentidade = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABIDENTIDADE,
                  "Identidade: ", new Point(322, 88), new Size(56, 13), 0);
      edtIdentidade = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTIDENTIDADE,
                  "", new Point(322, 104), new Size(100, 21), 0);
      edtIdentidade.Enabled = false;  

      string[] sItems = new string[2] {"Masculino", "Feminino"};
      rbSexo = new wx.RadioBox(this, (int)idx.ID_FRMCADCLIENTES_RBSEXO, "Sexo",
                  new Point(9, 128), new Size(200, 44), sItems, 2, 
                  wx.RadioBox.wxRA_SPECIFY_COLS);
      rbSexo.Enabled = false;
    
      labTelefone = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABTELEFONE,
                  "Telefone: ", new Point(216, 128), new Size(48, 13), 0);
      edtTelefone = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTTELEFONE,
                  "", new Point(216, 144), new Size(104, 21), 0);
      edtTelefone.Enabled = false;
    
      labDtNasc = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABDTNASC,
                  "Dt. Nascimento", new Point(322, 128), new Size(73, 13), 0);
      edtDtNasc = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTDTNASC,
                "", new Point(322, 144), new Size(100, 21), 0);
      edtDtNasc.Enabled = false;
      edtDtNasc.EVT_KILL_FOCUS( new EventListener( OnEdtDtNasc_Killfocus ));

      sbEndereco = new wx.StaticBox(this, (int)idx.ID_FRMCADCLIENTES_SBENDERECO,
        "Endereço", new Point(8, 176), new Size(432, 136), 0);
    
      edtCodEndereco = new TextValidatorCtrl(this, 
        (int)idx.ID_FRMCADCLIENTES_EDTCODENDERECO,
        "", new Point(16, 200), new Size(88, 21), 0, 
        TextValidatorCtrl.FILTER_NUMERIC);
      edtCodEndereco.Enabled = false;
      edtCodEndereco.EVT_KILL_FOCUS( new EventListener( OnEdtCodEndereco_Killfocus ));
    
      btnPEndereco = new wx.Button(this, (int)idx.ID_FRMCADCLIENTES_BTNPENDERECO,
                  "...", new Point(104, 200), new Size(21, 21), 0);
      btnPEndereco.Enabled = false;
    
      labLogradouro = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABLOGRADOURO,
                  "Logradouro: ", new Point(16, 224), new Size(60, 13), 0);
      edtLogradouro = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTLOGRADOURO,
                  "", new Point(16, 240), new Size(264, 21), 0);
      edtLogradouro.Enabled = false;
    
      labBairro = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABBAIRRO,
                  "Bairro:", new Point(284, 224), new Size(48, 13), 0);
      edtBairro = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTBAIRRO,
                  "", new Point(284, 240), new Size(144, 21), 0);
      edtBairro.Enabled = false;
    
      labCEP = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABCEP, "CEP: ",
                  new Point(16, 264), new Size(40, 13), 0);
      edtCEP = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTCEP, "",
                  new Point(16, 280), new Size(78, 21), 0);
      edtCEP.Enabled = false;
    
      labCidade = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABCIDADE,
                  "Cidade: ", new Point(96, 264), new Size(39, 13), 0);
      edtCidade = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTCIDADE,
                  "", new Point(96, 280), new Size(184, 21), 0);
      edtCidade.Enabled = false;
    
      labEstado = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABESTADO,
                  "Estado: ", new Point(284, 264), new Size(56, 13), 0);
      edtEstado = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTESTADO,
                  "", new Point(284, 280), new Size(144, 21), 0);
      edtEstado.Enabled = false;
    
      labPais = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABPAIS,
        "País de origem: ", new Point(8, 320), new Size(77, 16), 0);
      edtCodPais = new TextValidatorCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTCODPAIS,
        "", new Point(8, 336), new Size(78, 21), 0, 
        TextValidatorCtrl.FILTER_ALPHA);
      edtCodPais.Enabled = false;
      edtCodPais.EVT_KILL_FOCUS( new EventListener( OnEdtCodPais_Killfocus ));
      edtPais = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTPAIS,
                  "", new Point(88, 336), new Size(240, 21), 0);
      edtPais.Enabled = false;
      btnPPais = new wx.Button(this, (int)idx.ID_FRMCADCLIENTES_BTNPPAIS, "...",
                   new Point(328, 336), new Size(21, 21), 0);
      btnPPais.Enabled = false;
    
      labProfissao = new wx.StaticText(this, (int)idx.ID_FRMCADCLIENTES_LABPROFISSAO,
                  "Profissão: ", new Point(8, 360), new Size(56, 13), 0);
      edtCodProfissao = new TextValidatorCtrl(this, 
        (int)idx.ID_FRMCADCLIENTES_EDTCODPROFISSAO,
        "", new Point(8, 376), new Size(78, 21), 0, 
        TextValidatorCtrl.FILTER_NUMERIC);
      edtCodProfissao.Enabled = false;
      edtCodProfissao.EVT_KILL_FOCUS( new EventListener( OnEdtCodProfissao_Killfocus ));
      edtProfissao = new wx.TextCtrl(this, (int)idx.ID_FRMCADCLIENTES_EDTPROFISSAO,
                  "", new Point(88, 376), new Size(240, 21), 0);
      edtProfissao.Enabled = false;
      btnPProfissao = new wx.Button(this, (int)idx.ID_FRMCADCLIENTES_BTNPPROFISSAO,
                  "...", new Point(328, 376), new Size(21, 21), 0);
      btnPProfissao.Enabled = false;
    
      IniciaBotoes();
      btnPesquisar.SetSize(440, 8, 75, 25);
      btnAnterior.SetSize(440, 40, 75, 25);
      btnProximo.SetSize(440, 72, 75, 25);
      btnSalvar.SetSize(200, 408, 75, 25);
      btnExcluir.SetSize(280, 408, 75, 25);
      btnLimpar.SetSize(360, 408, 75, 25);
      btnFechar.SetSize(440, 408, 75, 25);
    
      //FazLayout();
    
    	edtCodigo.MaxLength = 14;
      edtDescricao.MaxLength = 30;
      edtEmail.MaxLength = 30;
      edtIdentidade.MaxLength = 10;
      edtCodEndereco.MaxLength = 10;
      edtTelefone.MaxLength = 17;
      edtCodPais.MaxLength = 3;
      edtCodProfissao.MaxLength = 10;

      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNNOVO, 
        new EventListener( OnBtnNovo ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNPESQUISAR, 
        new EventListener( OnBtnPesquisar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNANTERIOR, 
        new EventListener( OnBtnAnterior ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNPROXIMO, 
        new EventListener( OnBtnProximo ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNSALVAR, 
        new EventListener( OnBtnSalvar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNEXCLUIR, 
        new EventListener( OnBtnExcluir ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNLIMPAR, 
        new EventListener( OnBtnLimpar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNFECHAR, 
        new EventListener( OnBtnFechar ));
			EVT_CLOSE( new EventListener( OnClose ) );
      EVT_BUTTON((int)idx.ID_FRMCADCLIENTES_BTNPENDERECO, 
        new EventListener( OnBtnPEndereco ));
      EVT_BUTTON((int)idx.ID_FRMCADCLIENTES_BTNPPAIS, 
        new EventListener( OnBtnPPais ));
      EVT_BUTTON((int)idx.ID_FRMCADCLIENTES_BTNPPROFISSAO, 
        new EventListener( OnBtnPProfissao ));
    }

    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_3 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_5 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_16 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_23 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_22 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_19 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_15 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_21 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_20 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_18 = new wx.GridSizer(2, 1, 0, 0);
      wx.StaticBoxSizer sizer_11 = new wx.StaticBoxSizer(
        new wx.StaticBox(this, -1, "Endereço"), wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_14 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_17 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_16 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_15 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_13 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_14 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_13 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_12 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_10 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_12 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_11 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_6 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_5 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_4 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_8 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
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
      sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0);
      grid_sizer_4.Add(labEmail, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_4.Add(edtEmail, 0, 0, 0);
      sizer_6.Add(grid_sizer_4, 0, 0, 0);
      grid_sizer_5.Add(labIdentidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_5.Add(edtIdentidade, 0, 0, 0);
      sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4);
      sizer_5.Add(sizer_6, 0, 0, 0);
      sizer_10.Add(rbSexo, 0, 0, 0);
      grid_sizer_11.Add(labTelefone, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_11.Add(edtTelefone, 0, 0, 0);
      sizer_10.Add(grid_sizer_11, 1, wx.Direction.wxLEFT|wx.Stretch.wxEXPAND, 4);
      grid_sizer_12.Add(labDtNasc, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_12.Add(edtDtNasc, 0, 0, 0);
      sizer_10.Add(grid_sizer_12, 1, wx.Direction.wxLEFT|wx.Stretch.wxEXPAND, 4);
      sizer_5.Add(sizer_10, 1, wx.Stretch.wxEXPAND, 0);
      sizer_12.Add(edtCodEndereco, 0, 0, 0);
      sizer_12.Add(btnPEndereco, 0, 0, 0);
      sizer_11.Add(sizer_12, 0, wx.Direction.wxALL, 2);
      grid_sizer_13.Add(labLogradouro, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_13.Add(edtLogradouro, 0, 0, 0);
      sizer_13.Add(grid_sizer_13, 0, 0, 0);
      grid_sizer_14.Add(labBairro, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_14.Add(edtBairro, 0, 0, 0);
      sizer_13.Add(grid_sizer_14, 0, wx.Direction.wxLEFT, 4);
      sizer_11.Add(sizer_13, 0, 0, 0);
      grid_sizer_15.Add(labCEP, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_15.Add(edtCEP, 0, 0, 0);
      sizer_14.Add(grid_sizer_15, 0, 0, 0);
      grid_sizer_16.Add(labCidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_16.Add(edtCidade, 0, 0, 0);
      sizer_14.Add(grid_sizer_16, 0, wx.Direction.wxLEFT, 4);
      grid_sizer_17.Add(labEstado, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_17.Add(edtEstado, 0, 0, 0);
      sizer_14.Add(grid_sizer_17, 0, wx.Direction.wxLEFT, 4);
      sizer_11.Add(sizer_14, 1, 0, 0);
      sizer_5.Add(sizer_11, 0, 0, 0);
      grid_sizer_18.Add(labPais, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_18.Add(edtCodPais, 0, 0, 0);
      sizer_15.Add(grid_sizer_18, 0, 0, 0);
      grid_sizer_20.Add(20, 20, 0, 0, 0);
      grid_sizer_20.Add(edtPais, 0, 0, 0);
      sizer_15.Add(grid_sizer_20, 0, wx.Direction.wxLEFT, 2);
      grid_sizer_21.Add(20, 20, 0, 0, 0);
      grid_sizer_21.Add(btnPPais, 0, 0, 0);
      sizer_15.Add(grid_sizer_21, 0, 0, 0);
      sizer_5.Add(sizer_15, 0, 0, 0);
      grid_sizer_19.Add(labProfissao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_19.Add(edtCodProfissao, 0, 0, 0);
      sizer_16.Add(grid_sizer_19, 0, 0, 0);
      grid_sizer_22.Add(20, 20, 0, 0, 0);
      grid_sizer_22.Add(edtProfissao, 0, 0, 0);
      sizer_16.Add(grid_sizer_22, 0, wx.Direction.wxLEFT, 2);
      grid_sizer_23.Add(20, 20, 0, 0, 0);
      grid_sizer_23.Add(btnPProfissao, 0, 0, 0);
      sizer_16.Add(grid_sizer_23, 0, 0, 0);
      sizer_5.Add(sizer_16, 0, 0, 0);
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
        Resource.STR_CPFNINF))
        return false;
      if (bTodosDados) {
        if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Value, 
          Resource.STR_CLININF))
        	return false;
        if (RotinasGlobais.Rotinas.ValidaCampo(edtEmail.Value, 
          Resource.STR_EMAILNINF))
          return false;
    	  if (RotinasGlobais.Rotinas.ValidaCampo(edtTelefone.Value, 
          Resource.STR_TELNINF))
    		  return false;
    	  if (RotinasGlobais.Rotinas.ValidaCampo(edtCodEndereco.Value, 
          Resource.STR_ENDNINF))
    		  return false;
    	  if (RotinasGlobais.Rotinas.ValidaCampo(edtCodPais.Value, 
          Resource.STR_PAISNINF))
    		  return false;
    	  if (RotinasGlobais.Rotinas.ValidaCampo(edtCodProfissao.Value, 
          Resource.STR_PROFNINF))
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
      e.Skip();
    }
    
    private void OnBtnPesquisar( object sender, Event e ){
      if (PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S', edtCodigo.Value,
        "","","","","","","","",""), Resource.STR_CLINENC)) {
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
      string sSexo, sDtNasc, sSqlInsert, sSqlUpdate;
    
      if (rbSexo.Selection == 0)
         sSexo = "M"; 
      else   
         sSexo = "F";
    
      sDtNasc = RotinasGlobais.Rotinas.ConverteDataHoraStr(
        edtDtNasc.Value,"MM/dd/yyyy");
    
      sSqlUpdate = ConsultasSQL.ConsSQL.Cliente('U', edtCodigo.Value, 
        edtDescricao.Value, edtEmail.Value,  edtIdentidade.Value, sSexo,  
        edtTelefone.Value, sDtNasc, edtCodEndereco.Value, 
        edtCodPais.Value, edtCodProfissao.Value);
    
      sSqlInsert = ConsultasSQL.ConsSQL.Cliente('I', edtCodigo.Value, 
        edtDescricao.Value, edtEmail.Value,  edtIdentidade.Value, sSexo,  
        edtTelefone.Value, sDtNasc, edtCodEndereco.Value, 
        edtCodPais.Value, edtCodProfissao.Value);

          wx.MessageDialog.MessageBox(sSqlUpdate, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          

      if (SalvarDados(ValidaDados(true),
        ConsultasSQL.ConsSQL.Cliente('S', edtCodigo.Value,
          "","","","","","","","",""), sSqlUpdate, sSqlInsert, true)) {
        InformaLimpaDados(false);
        HabilitaDados(false);	
      }
      e.Skip();
    }
    
    private void OnBtnExcluir( object sender, Event e ){
      if (ExcluirDados(ValidaDados(false),
        ConsultasSQL.ConsSQL.Cliente('D', edtCodigo.Value,
        "","","","","","","","",""))){
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
        edtEmail.Value = Campos[2].ToString();
        edtIdentidade.Value = Campos[3].ToString();
        if (Campos[4].ToString() == "M")
          rbSexo.Selection = 0;
        else
          rbSexo.Selection = 1;
        edtTelefone.Value = Campos[5].ToString();
        edtDtNasc.Value = Campos[6].ToString().Substring(0,10);
        edtCodEndereco.Value = Campos[7].ToString();
        edtLogradouro.Value = Campos[8].ToString();
        edtBairro.Value = Campos[9].ToString();
        edtCEP.Value = Campos[10].ToString();
        edtCidade.Value = Campos[11].ToString();
        edtEstado.Value = Campos[12].ToString();
        edtCodPais.Value = Campos[13].ToString();
        edtPais.Value = Campos[14].ToString();
        edtCodProfissao.Value = Campos[15].ToString();
        edtProfissao.Value = Campos[16].ToString();
      } else {
        edtEmail.Clear();
        edtIdentidade.Clear();
        rbSexo.Selection = 0;
        edtTelefone.Clear();
        edtDtNasc.Clear();
        edtCodEndereco.Clear();
        edtLogradouro.Clear();
        edtBairro.Clear();
        edtCEP.Clear();
        edtCidade.Clear();
        edtEstado.Clear();
        edtCodPais.Clear();
        edtPais.Clear();
        edtCodProfissao.Clear();
        edtProfissao.Clear();
        edtCodigo.SetFocus();
      }
    } 
    
    protected override void HabilitaDados(bool bHabilita){
			base.HabilitaDados(bHabilita);

      edtEmail.Enabled = bHabilita;
      edtIdentidade.Enabled = bHabilita;
      rbSexo.Enabled = bHabilita;
      edtTelefone.Enabled = bHabilita;
      edtDtNasc.Enabled = bHabilita;
      edtCodEndereco.Enabled = bHabilita;
      btnPEndereco.Enabled = bHabilita;
      edtCodPais.Enabled = bHabilita;
      btnPPais.Enabled = bHabilita;
      edtCodProfissao.Enabled = bHabilita;
      btnPProfissao.Enabled = bHabilita;
    }
    
    private void OnEdtCodigo_Killfocus( object sender, Event e ){   
      if (edtCodigo.Value.Length > 0) {
      	if (RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.Value)==false) {
          wx.MessageDialog.MessageBox(Resource.STR_CPFINV, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          edtCodigo.Clear();
      		edtCodigo.SetFocus();
      	}
      }	
    }

    private void OnEdtDtNasc_Killfocus( object sender, Event e ){   
      if (edtDtNasc.Value.Length > 0) {
        if (!RotinasGlobais.Rotinas.validaDataHora(edtDtNasc.Value, true)) {
          wx.MessageDialog.MessageBox(Resource.STR_DTHRINV, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          edtDtNasc.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,false);
      		edtDtNasc.SetFocus();
        }
      } else
          edtDtNasc.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,false);
      e.Skip();
    }
    
    private void OnEdtCodEndereco_Killfocus( object sender, Event e ){
      string sLogradouro;
      ArrayList ConsCampo = new ArrayList();
       
      if (edtCodEndereco.Value.Length > 0) {
        sLogradouro = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Endereco('S',
          edtCodEndereco.Value,"","","","",""),Resource.STR_ENDNENC);
        if (sLogradouro.Length > 0) {
          edtLogradouro.Value = sLogradouro;
          edtBairro.Value = ConsCampo[2].ToString();
          edtCEP.Value = ConsCampo[3].ToString();
          edtCidade.Value = ConsCampo[4].ToString();
          edtEstado.Value = ConsCampo[5].ToString();
        } else {
      	  edtCodEndereco.SetFocus();
          edtLogradouro.Clear();
          edtBairro.Clear();
          edtCEP.Clear();
      	  edtCidade.Clear();
      	  edtEstado.Clear();
        }
      } else {
        edtLogradouro.Clear();
        edtBairro.Clear();
        edtCEP.Clear();
    	  edtCidade.Clear();
    	  edtEstado.Clear();
      }
    }
    
    private void OnEdtCodPais_Killfocus( object sender, Event e ){
      string sPais;
      ArrayList ConsCampo = new ArrayList();  
    
      if (edtCodPais.Value.Length > 0) {
        sPais = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Pais('S',
          edtCodPais.Value,""),Resource.STR_PAISNENC);    
        if (sPais.Length > 0) {
          edtPais.Value = sPais;
        } else {
          edtCodPais.Clear();
          edtCodPais.SetFocus();
        }
      } else {
        edtPais.Clear();
      }
    }
    
    private void OnEdtCodProfissao_Killfocus( object sender, Event e ){
      string sProfissao;
      ArrayList ConsCampo = new ArrayList();   
    
      if (edtCodProfissao.Value.Length > 0) {
        sProfissao = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Profissao('S',
          edtCodProfissao.Value,""),Resource.STR_PROFNENC);    
    
        if (sProfissao.Length > 0) {
          edtProfissao.Value = sProfissao;
        } else {
          edtCodProfissao.Clear();
          edtCodProfissao.SetFocus();
        }
      } else {
        edtProfissao.Clear();
      }
    }

    private void OnBtnPEndereco( object sender, Event e ){
      frmConEnderecos fConEnderecos = new frmConEnderecos(this);
      fConEnderecos.ShowModal();
      edtCodEndereco.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCodEndereco_Killfocus(null,null);
      e.Skip();
    }
    
    private void OnBtnPPais( object sender, Event e ){
      frmConPaises fConPaises = new frmConPaises(this);
      fConPaises.ShowModal();
      edtCodPais.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCodPais_Killfocus(null,null);
      e.Skip();
    }
    
    private void OnBtnPProfissao( object sender, Event e ){
      frmConProfissoes fConProfissoes = new frmConProfissoes(this);
      fConProfissoes.ShowModal();
      edtCodProfissao.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCodProfissao_Killfocus(null,null);
      e.Skip();
    }
	}
}
