#include "Consultas.h"
#include "RotinasGlobais.h"

CfrmConsultas *frmConsultas;

CfrmConsultas::CfrmConsultas(char* sTitulo)
       : Fl_Double_Window(416, 255, sTitulo) {
	IniciaControles();
}

CfrmConsultas::~CfrmConsultas() { }

void CfrmConsultas::IniciaControles() {
  this->box(FL_FLAT_BOX);
  this->color(FL_BACKGROUND_COLOR);
  this->selection_color(FL_BACKGROUND_COLOR);
  this->labeltype(FL_NO_LABEL);
  this->labelfont(0);
  this->labelsize(14);
  this->labelcolor(FL_BLACK);
  this->user_data((void*)(this));
  this->align(FL_ALIGN_TOP);
  this->when(FL_WHEN_RELEASE);
  grupo1 = new Fl_Group(0, 0, 415, 65);
    grupo1->box(FL_UP_BOX);
    edtDescricao = new Fl_Input(10, 25, 315, 25, "Descri\347\343o:");
    edtDescricao->align(FL_ALIGN_TOP_LEFT);
    btnPesquisar = new Fl_Button(330, 25, 75, 25, "&Pesquisar");
  grupo1->end();

  gridConsulta = new Fl_Select_Browser(0, 65, 415, 145);
  gridConsulta->type(FL_HOLD_BROWSER);
  gridConsulta->box(FL_UP_BOX);
  Fl_Group::current()->resizable(gridConsulta);

  grupo2 = new Fl_Group(0, 210, 415, 45);
    grupo2->box(FL_UP_BOX);
    labRegistro = new Fl_Box(10, 220, 140, 25, "Registro 0 de 0 ");
    labRegistro->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    btnLimpar = new Fl_Button(250, 220, 75, 25, "&Limpar");
    btnFechar = new Fl_Button(330, 220, 75, 25, "&Fechar");
  grupo2->end();

  this->set_modal();
  this->end();

}

void CfrmConsultas::Fecha() {
  if (sSelecionado.length() > 0)
    Rotinas_sCodigoSelecionado = sSelecionado;
  else
    Rotinas_sCodigoSelecionado = "";
}

void CfrmConsultas::LimparDados() {
  labRegistro->label("Registro 0 de 0");
  gridConsulta->clear();
  edtDescricao->value("");
  edtDescricao->take_focus();
}

void CfrmConsultas::PesquisarDados(string sTextoSql, string sMensagemErro, 
    int nQtdCol, int nLarguras[], string sRotulos[]) {

  if (Rotinas->ConsultaDadosLista(gConexao, &lstLinhas, sTextoSql)) {
    Rotinas->AdicionaLinhasBrowser(gridConsulta, lstLinhas, nQtdCol, 
      nLarguras, sRotulos);    
    setLabRegistros(2);
  } else
    fl_alert(sMensagemErro.c_str());
}

void CfrmConsultas::setLabRegistros(int nLinha) {
char *sTemp = Rotinas->alocaString(TAM_MAX_STR);

  if (gridConsulta->selected(nLinha)) {
    if (nLinha > 0) {
      sprintf(sTemp, "Registro %d de %d", nLinha-1, 
        ListaStr->contaM(lstLinhas));
      labRegistro->label(sTemp);
      if (nLinha > 1)
        sSelecionado = gridConsulta->text(nLinha);
      else
        sSelecionado = "";
    }
  } else {
      labRegistro->label("Registro 0 de 0");
      sSelecionado = "";
  }
}

