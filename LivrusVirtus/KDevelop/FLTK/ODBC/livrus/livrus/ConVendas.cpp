#include "Principal.h"
#include "ConVendas.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

CfrmConVendas *frmConVendas;

void frmConVendas_edtDtHrVendaKillFocus_cb(Fl_Output* o, void* v);
void frmConVendas_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConVendas_btnPClienteClick_cb(Fl_Button* b, void* v);
void frmConVendas_btnPLivroClick_cb(Fl_Button* b, void* v);
void frmConVendas_gridVendasSelect_cb(Fl_Browser* b, void* v);
void frmConVendas_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConVendas_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConVendas::CfrmConVendas()
       : Fl_Double_Window(520, 329, "Vendas Realizadas") {
	IniciaControles();
}

CfrmConVendas::~CfrmConVendas() { }

void CfrmConVendas::IniciaControles() {
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
  grupo1 = new Fl_Group(0, 0, 520, 150);
    grupo1->box(FL_UP_BOX);
    edtDtHrVenda = new Fl_Input(10, 25, 160, 25, "Data/Hora Venda:");
    edtDtHrVenda->callback((Fl_Callback*)frmConVendas_edtDtHrVendaKillFocus_cb);
    edtDtHrVenda->align(FL_ALIGN_TOP_LEFT);

    btnPesquisar = new Fl_Button(175, 25, 75, 25, "&Pesquisar");
    btnPesquisar->callback((Fl_Callback*)frmConVendas_btnPesquisarClick_cb);

    edtCPF = new Fl_Input(10, 70, 160, 25, "CPF:");
    edtCPF->callback((Fl_Callback*)frmConVendas_edtCPFKillFocus_cb);
    edtCPF->align(FL_ALIGN_TOP_LEFT);
    edtCPF->maximum_size(14);

    edtCliente = new Fl_Output(175, 70, 310, 25);
    edtCliente->deactivate();

    btnPCliente = new Fl_Button(485, 70, 25, 25, "...");
    btnPCliente->callback((Fl_Callback*)frmConVendas_btnPClienteClick_cb);

    edtISBN = new Fl_Input(10, 115, 160, 25, "ISBN:");
    edtISBN->callback((Fl_Callback*)frmConVendas_edtISBNKillFocus_cb);
    edtISBN->align(FL_ALIGN_TOP_LEFT);
    edtISBN->maximum_size(13);

    edtLivro = new Fl_Output(175, 115, 310, 25);
    edtLivro->deactivate();

    btnPLivro = new Fl_Button(485, 115, 25, 25, "...");
    btnPLivro->callback((Fl_Callback*)frmConVendas_btnPLivroClick_cb);
  grupo1->end();

  gridVendas = new Fl_Select_Browser(0, 150, 520, 100);
  gridVendas->type(FL_HOLD_BROWSER);
  gridVendas->box(FL_UP_BOX);
  gridVendas->callback((Fl_Callback*)frmConVendas_gridVendasSelect_cb);

  grupo2 = new Fl_Group(0, 250, 520, 80);
    grupo2->box(FL_UP_BOX);
    labRegistros = new Fl_Box(10, 260, 140, 25, "Registro 0 de 0 ");
    labRegistros->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);

    edtPrecoTotal = new Fl_Output(360, 260, 155, 25, "Pre\347o Total:");
    edtPrecoTotal->value("R$ 0,00");
    edtPrecoTotal->deactivate();

    btnLimpar = new Fl_Button(360, 295, 75, 25, "&Limpar");
    btnLimpar->callback((Fl_Callback*)frmConVendas_btnLimparClick_cb);

    btnFechar = new Fl_Button(440, 295, 75, 25, "&Fechar");
    btnFechar->callback((Fl_Callback*)frmConVendas_btnFecharClick_cb);
  grupo2->end();

  this->end();
  this->resizable(this);

  edtDtHrVenda->value(Rotinas->retDataHoraStr(true,true));
}

void frmConVendas_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConVendas->edtCPF->value("");
  frmConVendas->edtCliente->value("");
  frmConVendas->edtISBN->value("");
  frmConVendas->edtLivro->value("");
  frmConVendas->gridVendas->clear();
  frmConVendas->edtPrecoTotal->value("R$ 0,00");
  frmConVendas->edtDtHrVenda->value(Rotinas->retDataHoraStr(true,true));
  frmConVendas->edtDtHrVenda->take_focus();
}

string CfrmConVendas::ConsVenda(char sOpcao)
{
  string sISBN, sCPF, sDataHora;
  string sret = "";

  if (strlen(edtDtHrVenda->value()) > 0)
    sDataHora = Rotinas->ConverteDataHoraStr(edtDtHrVenda->value(), 
      true, "%m/%d/%Y","%H:%M:%S");
  else
    sDataHora = "";

  sISBN = edtISBN->value();
  sCPF = edtCPF->value();

  if (sOpcao=='L')
    sret = ConsSQL->Venda('S',"ZERO","","","","");
  else
    sret = ConsSQL->Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");

 return sret;
}

void frmConVendas_btnPesquisarClick_cb(Fl_Button* b, void* v){
LISTAMSTR ConsTotal;  
char sPrecoTotal[TAM_MAX_STR];
double nTemp;

  if (Rotinas->ConsultaDadosLista(gConexao, 
    &frmConVendas->lstLinhas, frmConVendas->ConsVenda('S'))) {

    int nLarguras[] = { 19, 14, 50, 13, 50, 10 };

    string sRotulos[] = { "Data/Hora Venda", "CPF", "Cliente", 
     "ISBN", "Livro", "Preço" };

    Rotinas->AdicionaLinhasBrowser(frmConVendas->gridVendas, 
      frmConVendas->lstLinhas, 6, nLarguras , sRotulos);
    frmConVendas->setLabRegistros(2);
    if (Rotinas->ConsultaDadosLista(gConexao, &ConsTotal, 
      frmConVendas->ConsVenda('P'))) {
      if (ListaStr->contaM(ConsTotal) > 0) {
        nTemp = atof(ConsTotal->str[0]);
        sprintf(sPrecoTotal, "R$ %.2f", nTemp);
        frmConVendas->edtPrecoTotal->value(sPrecoTotal);
      }
    }
  } else 
     fl_alert(STR_VENNENC);
}

void frmConVendas_edtDtHrVendaKillFocus_cb(Fl_Output* o, void* v){
  if (strlen(frmConVendas->edtDtHrVenda->value()) > 0) {
    if (!Rotinas->validaDataHora(
      frmConVendas->edtDtHrVenda->value(), false)) {
      fl_alert(STR_DTHRINV);
      frmConVendas->edtDtHrVenda->take_focus();
    }
  } 
}

void frmConVendas_edtCPFKillFocus_cb(Fl_Input* i, void* v)
{ string sCliente;
  LISTAMSTR ConsCampo;

  if (strlen(frmConVendas->edtCPF->value()) > 0) {
    if (Rotinas->validaCPF(frmConVendas->edtCPF->value())) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      frmConVendas->edtCPF->value(),"","","","","","","","",""),
      STR_CLINENC); 
      if (sCliente.length()==0) {
        frmConVendas->edtCPF->value("");
        frmConVendas->edtCPF->take_focus();
      } else
         frmConVendas->edtCliente->value(sCliente.c_str());
    } else {
      fl_alert(STR_CPFINV);
      frmConVendas->edtCPF->value("");
      frmConVendas->edtCPF->take_focus();
    }
  } else
     frmConVendas->edtCliente->value("");
}

void frmConVendas_btnPClienteClick_cb(Fl_Button* b, void* v){
  frmConClientes = new CfrmConClientes(2);
  frmConClientes->show();
}

void frmConVendas_edtISBNKillFocus_cb(Fl_Input* i, void* v){
string sLivro;
int nQtdEstoque;
LISTAMSTR ConsCampo;

  if (strlen(frmConVendas->edtISBN->value()) > 0) {
    if (Rotinas->validaISBN(frmConVendas->edtISBN->value())) {      
      sLivro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Livro('Q',
      frmConVendas->edtISBN->value(),"","","","","","","","",""),
      STR_LIVNENC);
      if (sLivro.length()==0) {
        frmConVendas->edtISBN->value("");
      	frmConVendas->edtISBN->take_focus();
      } else {
         frmConVendas->edtLivro->value(sLivro.c_str());
         nQtdEstoque = atoi(ListaStr->pesquisaItemOrdM(ConsCampo,3,0));
         if (nQtdEstoque > 0) {
           Rotinas_sPreco = ListaStr->pesquisaItemOrdM(ConsCampo,2,0);
           Rotinas_sQtdEstoque = ListaStr->pesquisaItemOrdM(ConsCampo,3,0);
         } else
           fl_alert(STR_LIVNEST);
      }
    } else {
      fl_alert(STR_ISBNINV);
      frmConVendas->edtISBN->value("");
    	frmConVendas->edtISBN->take_focus();
    }
  } else
     frmConVendas->edtLivro->value("");
}

void frmConVendas_btnPLivroClick_cb(Fl_Button* b, void* v){
  frmConLivros = new CfrmConLivros(2);
  frmConLivros->show();
}

void CfrmConVendas::setLabRegistros(int nLinha) {
char *sTemp = Rotinas->alocaString(TAM_MAX_STR);

  if (gridVendas->selected(nLinha)) {
    if (nLinha >= 0) {
      sprintf(sTemp, "Registro %d de %d", nLinha-1, 
        ListaStr->contaM(lstLinhas));
      labRegistros->label(sTemp);
    }
  } else
      labRegistros->label("Registro 0 de 0");
}

void frmConVendas_gridVendasSelect_cb(Fl_Browser* b, void* v){
  frmConVendas->setLabRegistros(b->value());
}

void frmConVendas_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConVendas->hide();
}

int CfrmConVendas::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuVenVendasRealizadas->activate();
  }
  return Fl_Double_Window::handle(event);
}
