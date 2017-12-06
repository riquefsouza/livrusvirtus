#include "Principal.h"
#include "VenderLivros.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

CfrmVenderLivros *frmVenderLivros;
LISTASTR frmVenderLivros_slPrecos, frmVenderLivros_slISBNs, 
  frmVenderLivros_slQtdEstoque;

void frmVenderLivros_btnPClienteClick_cb(Fl_Button* b, void* v);
void frmVenderLivros_btnAdLivrosClick_cb(Fl_Button* b, void* v);
void frmVenderLivros_btnPLivroClick_cb(Fl_Button* b, void* v);
void frmVenderLivros_lstVendasSelect_cb(Fl_Browser* b, void* v);
void frmVenderLivros_btnVenderClick_cb(Fl_Button* b, void* v);
void frmVenderLivros_btnLimparClick_cb(Fl_Button* b, void* v);
void frmVenderLivros_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmVenderLivros::CfrmVenderLivros()
       : Fl_Double_Window(511, 316, "Vender Livros") {
	IniciaControles();
}

CfrmVenderLivros::~CfrmVenderLivros() { }

void CfrmVenderLivros::IniciaControles() {
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
  edtDtHrVenda = new Fl_Output(10, 20, 160, 25, "Data/Hora Venda:");
  edtDtHrVenda->align(FL_ALIGN_TOP_LEFT);
  edtDtHrVenda->deactivate();

  edtCPF = new Fl_Input(10, 65, 160, 25, "CPF:");
  edtCPF->callback((Fl_Callback*)frmVenderLivros_edtCPFKillFocus_cb);
  edtCPF->align(FL_ALIGN_TOP_LEFT);
  edtCPF->maximum_size(14);

  edtCliente = new Fl_Output(170, 65, 310, 25);
  edtCliente->deactivate();

  btnPCliente = new Fl_Button(480, 65, 25, 25, "...");
  btnPCliente->callback((Fl_Callback*)frmVenderLivros_btnPClienteClick_cb);

  edtISBN = new Fl_Input(10, 110, 160, 25, "ISBN:");
  edtISBN->callback((Fl_Callback*)frmVenderLivros_edtISBNKillFocus_cb);
  edtISBN->align(FL_ALIGN_TOP_LEFT);
  edtISBN->maximum_size(13);

  edtLivro = new Fl_Output(170, 110, 280, 25);
  edtLivro->deactivate();

  btnAdLivros = new Fl_Button(450, 110, 25, 25, "+");
  btnAdLivros->callback((Fl_Callback*)frmVenderLivros_btnAdLivrosClick_cb);

  btnPLivro = new Fl_Button(480, 110, 25, 25, "...");
  btnPLivro->callback((Fl_Callback*)frmVenderLivros_btnPLivroClick_cb);

  lstLivros = new Fl_Browser(10, 155, 495, 95, "Livros para vender:");
  lstLivros->type(1);
  lstLivros->callback((Fl_Callback*)frmVenderLivros_lstVendasSelect_cb);
  lstLivros->align(FL_ALIGN_TOP_LEFT);

  edtPrecoTotal = new Fl_Output(350, 255, 155, 25, "Pre\347o Total:");
  edtPrecoTotal->deactivate();

  btnVender = new Fl_Button(270, 285, 75, 25, "&Vender");
  btnVender->callback((Fl_Callback*)frmVenderLivros_btnVenderClick_cb);

  btnLimpar = new Fl_Button(350, 285, 75, 25, "&Limpar");
  btnLimpar->callback((Fl_Callback*)frmVenderLivros_btnLimparClick_cb);

  btnFechar = new Fl_Button(430, 285, 75, 25, "&Fechar");
  btnFechar->callback((Fl_Callback*)frmVenderLivros_btnFecharClick_cb);

  this->end();
  this->resizable(this);

  edtDtHrVenda->value(Rotinas->retDataHoraStr(true, true));
  nPrecoTotal = 0;
}

void CfrmVenderLivros::LimpaDados() {
  edtDtHrVenda->value(Rotinas->retDataHoraStr(true, true));  
  edtCPF->value("");
  edtCliente->value("");
  edtISBN->value("");
  edtLivro->value("");
  lstLivros->clear();
  nPrecoTotal = 0;
  edtPrecoTotal->value("R$ 0,00");
  edtCPF->take_focus();
}

bool CfrmVenderLivros::ValidaDados() {
  if (Rotinas->ValidaCampo(edtCPF->value(), STR_CPFNINF))
    return false;
  if (lstLivros->size()==0) {
    fl_alert(STR_LIVVENNINF);
    return false;
  }
return true;
}

bool CfrmVenderLivros::SalvaLista()
{ string sCPF, sISBN, sDataHora, sDTHR;
  char sPrecoTotal[TAM_MAX_STR], sQtdEstoque[TAM_MAX_STR];
  int nCont, nQtd;
  int nQtdEstoque;

  nQtd = lstLivros->size();
  sCPF = edtCPF->value();
  sprintf(sPrecoTotal, "%.2f", nPrecoTotal);
  
  sDTHR = edtDtHrVenda->value();
  sDataHora = Rotinas->ConverteDataHoraStr(sDTHR, true, 
    "%m/%d/%Y","%H:%M:%S");
  
  for (nCont=0; nCont < nQtd; nCont++) {
    sISBN = ListaStr->pesquisaItemOrd(frmVenderLivros_slISBNs, nCont);
 
    Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('I',sISBN, sCPF, 
      sDataHora,Rotinas->VirgulaParaPonto(sPrecoTotal,false),""));
  
    nQtdEstoque = 
      atoi(ListaStr->pesquisaItemOrd(frmVenderLivros_slQtdEstoque, nCont));
    if (nQtdEstoque > 0) nQtdEstoque--;
    sprintf(sQtdEstoque, "%d", nQtdEstoque);
    Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('U',sISBN, 
      "","","", sQtdEstoque));
  }
return true;
}

void frmVenderLivros_edtCPFKillFocus_cb(Fl_Input* i, void* v){
string sCliente;
LISTAMSTR ConsCampo;

  if (strlen(frmVenderLivros->edtCPF->value()) > 0) {
    if (Rotinas->validaCPF(frmVenderLivros->edtCPF->value())) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      frmVenderLivros->edtCPF->value(),"","","","","","","","",""),
      STR_CLINENC); 
      if (sCliente.length()==0) {
        frmVenderLivros->edtCPF->value("");
        frmVenderLivros->edtCPF->take_focus();
      } else
         frmVenderLivros->edtCliente->value(sCliente.c_str());
    } else {
      fl_alert(STR_CPFINV);
      frmVenderLivros->edtCPF->value("");
      frmVenderLivros->edtCPF->take_focus();
    }
  } else
     frmVenderLivros->edtCliente->value("");
}

void frmVenderLivros_btnPClienteClick_cb(Fl_Button* b, void* v){
  frmConClientes = new CfrmConClientes(1);
  frmConClientes->show();
}

void frmVenderLivros_edtISBNKillFocus_cb(Fl_Input* i, void* v){
string sLivro;
int nQtdEstoque;
LISTAMSTR ConsCampo;

  if (strlen(frmVenderLivros->edtISBN->value()) > 0) {
    if (Rotinas->validaISBN(frmVenderLivros->edtISBN->value())) {      
      sLivro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Livro('Q',
      frmVenderLivros->edtISBN->value(),"","","","","","","","",""),
      STR_LIVNENC);
      if (sLivro.length()==0) {
        frmVenderLivros->edtISBN->value("");
      	frmVenderLivros->edtISBN->take_focus();
      } else {
         frmVenderLivros->edtLivro->value(sLivro.c_str());
         nQtdEstoque = atoi(ListaStr->pesquisaItemOrdM(ConsCampo,3,0));
         if (nQtdEstoque > 0) {
           Rotinas_sPreco = ListaStr->pesquisaItemOrdM(ConsCampo,2,0);
           Rotinas_sQtdEstoque = ListaStr->pesquisaItemOrdM(ConsCampo,3,0);
         } else
           fl_alert(STR_LIVNEST);
      }
    } else {
      fl_alert(STR_ISBNINV);
      frmVenderLivros->edtISBN->value("");
    	frmVenderLivros->edtISBN->take_focus();
    }
  } else
     frmVenderLivros->edtLivro->value("");
}

void frmVenderLivros_btnAdLivrosClick_cb(Fl_Button* b, void* v){
double nPreco; 
string sLivros, sISBN, sEdtLivro;
char sPrecoTotal[TAM_MAX_STR];

 sISBN = frmVenderLivros->edtISBN->value();
 sEdtLivro = frmVenderLivros->edtLivro->value();
 if (sISBN.length() > 0) {
   sLivros = sISBN + " - " + sEdtLivro + " - R$ " + Rotinas_sPreco;
   if (Rotinas->VerificaItemLista(frmVenderLivros->lstLivros, sLivros)==false) {
   	 ListaStr->insereFim(&frmVenderLivros_slISBNs, (char*)sISBN.c_str()); 
   	 ListaStr->insereFim(
       &frmVenderLivros_slPrecos, (char*)Rotinas_sPreco.c_str()); 
   	 ListaStr->insereFim(
       &frmVenderLivros_slQtdEstoque, (char*)Rotinas_sQtdEstoque.c_str()); 
     sLivros = "@f" + sLivros;
     frmVenderLivros->lstLivros->add(sLivros.c_str());
     nPreco = atof(Rotinas_sPreco.c_str());
     frmVenderLivros->nPrecoTotal = frmVenderLivros->nPrecoTotal + nPreco;
   }
   frmVenderLivros->edtISBN->value("");
   frmVenderLivros->edtLivro->value("");
   sprintf(sPrecoTotal, "R$ %.2f", frmVenderLivros->nPrecoTotal);
   frmVenderLivros->edtPrecoTotal->value(
     Rotinas->VirgulaParaPonto(sPrecoTotal,true));
 }
}

void frmVenderLivros_btnPLivroClick_cb(Fl_Button* b, void* v){
  frmConLivros = new CfrmConLivros(1);
  frmConLivros->show();
}

void frmVenderLivros_lstVendasSelect_cb(Fl_Browser* b, void* v){
char sPrecoTotal[TAM_MAX_STR];
double nPreco;
int nSelIndice;

  if (Fl::event_clicks()==1) { //duplo-clique
    if (frmVenderLivros->lstLivros->size() > 0) {   
      nSelIndice = frmVenderLivros->lstLivros->value();   
      if (frmVenderLivros->lstLivros->selected(nSelIndice)) {
        nPreco = atof(ListaStr->pesquisaItemOrd(
          frmVenderLivros_slPrecos,nSelIndice));
        frmVenderLivros->nPrecoTotal=frmVenderLivros->nPrecoTotal-nPreco;
        sprintf(sPrecoTotal, "R$ %.2f", frmVenderLivros->nPrecoTotal);
        frmVenderLivros->edtPrecoTotal->value(
          Rotinas->VirgulaParaPonto(sPrecoTotal,true));
   	    ListaStr->removeItemOrd(&frmVenderLivros_slISBNs, nSelIndice, true);
        ListaStr->removeItemOrd(&frmVenderLivros_slPrecos, nSelIndice, true);         
        ListaStr->removeItemOrd(
          &frmVenderLivros_slQtdEstoque, nSelIndice, true);
        frmVenderLivros->lstLivros->remove(nSelIndice);
      }	
    }
  }
}

void frmVenderLivros_btnVenderClick_cb(Fl_Button* b, void* v){
  if (frmVenderLivros->ValidaDados()) {
    if (frmVenderLivros->SalvaLista()) {
      fl_alert(STR_VENRESUC);
      frmVenderLivros->LimpaDados();
    }
  }	
}

void frmVenderLivros_btnLimparClick_cb(Fl_Button* b, void* v){
  frmVenderLivros->LimpaDados();
}

void frmVenderLivros_btnFecharClick_cb(Fl_Button* b, void* v){
  frmVenderLivros->hide();
}

int CfrmVenderLivros::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->tlbVenda->activate();
    frmPrincipal->mnuVenVenderLivros->activate();
  }
  return Fl_Double_Window::handle(event);
}
