#include "Principal.h"
#include "CadLivros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEditoras.h"
#include "ConAssuntos.h"
#include "ConAutores.h"

CfrmCadLivros *frmCadLivros;
LISTASTR frmCadLivros_slAssuntos, frmCadLivros_slAutores, 
  frmCadLivros_slIdiomas;

void frmCadLivros_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnFecharClick_cb(Fl_Button* b, void* v);
void frmCadLivros_edtCodigoKillFocus_cb(Fl_Input* i, void* v);
void frmCadLivros_btnPEditoraClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnAdAssuntosClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnPAssuntoClick_cb(Fl_Button* b, void* v);
void frmCadLivros_lstAssuntosDblClick_cb(Fl_Browser* b, void* v);
void frmCadLivros_btnAdAutoresClick_cb(Fl_Button* b, void* v);
void frmCadLivros_btnPAutorClick_cb(Fl_Button* b, void* v);
void frmCadLivros_lstAutoresDblClick_cb(Fl_Browser* b, void* v);

CfrmCadLivros::CfrmCadLivros()
       : CfrmCadastros(false, STR_CADLIVRO) {
	IniciaControles();
}

CfrmCadLivros::~CfrmCadLivros() { }

void CfrmCadLivros::IniciaControles() {
  this->size(557, 436);
  edtCodigo->label("ISBN:");
  edtCodigo->type(0);
  edtCodigo->maximum_size(13);
  edtCodigo->callback((Fl_Callback*)frmCadLivros_edtCodigoKillFocus_cb);

  edtDescricao->label("Título:");
  edtDescricao->size(350, 25);
  edtDescricao->maximum_size(50);

  edtEdicao = new Fl_Value_Input(365, 70, 105, 25, "Edi\347\343o:");
  edtEdicao->minimum(1);
  edtEdicao->maximum(9999);
  edtEdicao->step(1);
  edtEdicao->value(1);
  edtEdicao->align(FL_ALIGN_TOP_LEFT);
  edtEdicao->deactivate();

  edtAnoPubli = new Fl_Value_Input(10, 115, 105, 25, "Ano Publica\347\343o:");
  edtAnoPubli->minimum(1);
  edtAnoPubli->maximum(9999);
  edtAnoPubli->step(1);
  edtAnoPubli->value(1);
  edtAnoPubli->align(FL_ALIGN_TOP_LEFT);
  edtAnoPubli->deactivate();

  edtCodEditora = new Fl_Input(120, 115, 100, 25, "Editora:");
  edtCodEditora->type(2);
  edtCodEditora->callback((Fl_Callback*)frmCadLivros_edtCodEditoraKillFocus_cb);
  edtCodEditora->align(FL_ALIGN_TOP_LEFT);
  edtCodEditora->deactivate();
  edtCodEditora->maximum_size(5);
  
  edtEditora = new Fl_Input(225, 115, 220, 25);
  edtEditora->labeltype(FL_NO_LABEL);
  edtEditora->align(FL_ALIGN_TOP_LEFT);
  edtEditora->deactivate();

  btnPEditora = new Fl_Button(445, 115, 25, 25, "...");
  btnPEditora->callback((Fl_Callback*)frmCadLivros_btnPEditoraClick_cb);
  btnPEditora->deactivate();

  edtVolume = new Fl_Value_Input(10, 160, 105, 25, "Volume:");
  edtVolume->minimum(1);
  edtVolume->maximum(9999);
  edtVolume->step(1);
  edtVolume->value(1);
  edtVolume->align(FL_ALIGN_TOP_LEFT);
  edtVolume->deactivate();
  
  cmbIdioma = new Fl_Choice(120, 160, 350, 25, "Idioma:");
  cmbIdioma->down_box(FL_BORDER_BOX);
  cmbIdioma->align(FL_ALIGN_TOP_LEFT);
  cmbIdioma->deactivate();
  
  edtNPaginas = new Fl_Value_Input(10, 205, 105, 25, "N. P\341ginas:");
  edtNPaginas->minimum(1);
  edtNPaginas->maximum(9999);
  edtNPaginas->step(1);
  edtNPaginas->value(1);
  edtNPaginas->align(FL_ALIGN_TOP_LEFT);
  edtNPaginas->deactivate();
  
  edtCodAssunto = new Fl_Input(120, 205, 100, 25, "Assunto:");
  edtCodAssunto->type(2);
  edtCodAssunto->callback((Fl_Callback*)frmCadLivros_edtCodAssuntoKillFocus_cb);
  edtCodAssunto->align(FL_ALIGN_TOP_LEFT);
  edtCodAssunto->deactivate();
  
  edtAssunto = new Fl_Input(225, 205, 190, 25);
  edtAssunto->labeltype(FL_NO_LABEL);
  edtAssunto->align(FL_ALIGN_TOP_LEFT);
  edtAssunto->deactivate();
  
  btnAdAssuntos = new Fl_Button(415, 205, 25, 25, "+");
  btnAdAssuntos->callback((Fl_Callback*)frmCadLivros_btnAdAssuntosClick_cb);
  btnAdAssuntos->deactivate();
  
  btnPAssunto = new Fl_Button(445, 205, 25, 25, "...");
  btnPAssunto->callback((Fl_Callback*)frmCadLivros_btnPAssuntoClick_cb);
  btnPAssunto->deactivate();
  
  edtPreco = new Fl_Input(10, 265, 105, 25, "Pre\347o:");
  edtPreco->type(1);
  edtPreco->align(FL_ALIGN_TOP_LEFT);
  edtPreco->deactivate();
  edtPreco->maximum_size(7);
  
  lstAssuntos = new Fl_Select_Browser(120, 230, 350, 60);
  lstAssuntos->type(FL_HOLD_BROWSER);
  lstAssuntos->callback((Fl_Callback*)frmCadLivros_lstAssuntosDblClick_cb);
  lstAssuntos->deactivate();
  
  edtQtdEstoque = new Fl_Value_Input(10, 310, 105, 25, "Qtd. Estoque:");
  edtQtdEstoque->maximum(9999);
  edtQtdEstoque->step(1);
  edtQtdEstoque->align(FL_ALIGN_TOP_LEFT);
  edtQtdEstoque->deactivate();
  
  edtCodAutor = new Fl_Input(120, 310, 100, 25, "Autor:");
  edtCodAutor->type(2);
  edtCodAutor->callback((Fl_Callback*)frmCadLivros_edtCodAutorKillFocus_cb);
  edtCodAutor->align(FL_ALIGN_TOP_LEFT);
  edtCodAutor->deactivate();
  
  edtAutor = new Fl_Input(225, 310, 190, 25);
  edtAutor->labeltype(FL_NO_LABEL);
  edtAutor->align(FL_ALIGN_TOP_LEFT);
  edtAutor->deactivate();
  
  btnAdAutores = new Fl_Button(415, 310, 25, 25, "+");
  btnAdAutores->callback((Fl_Callback*)frmCadLivros_btnAdAutoresClick_cb);
  btnAdAutores->deactivate();
  
  btnPAutor = new Fl_Button(445, 310, 25, 25, "...");
  btnPAutor->callback((Fl_Callback*)frmCadLivros_btnPAutorClick_cb);
  btnPAutor->deactivate();
  
  lstAutores = new Fl_Select_Browser(120, 335, 350, 60);
  lstAutores->type(FL_HOLD_BROWSER);
  lstAutores->callback((Fl_Callback*)frmCadLivros_lstAutoresDblClick_cb);
  lstAutores->deactivate();

  IniciaBotoes(475, 20, 235, 404);

  btnNovo->callback((Fl_Callback*)frmCadLivros_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadLivros_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadLivros_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadLivros_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadLivros_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadLivros_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadLivros_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadLivros_btnFecharClick_cb);

  AdicionaCombo();
}

bool CfrmCadLivros::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_ISBNNINF))
  	  return false;
 	if (bTodosDados) {
    if (Rotinas->ValidaCampo(edtDescricao->value(), STR_TITNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtEditora->value(), STR_EDTNINF))
		    return false;
    if (lstAssuntos->size()==0) {
      fl_alert(STR_ASSNINF);
      return false;
    }
    if (lstAutores->size()==0) {
      fl_alert(STR_AUTNINF);
      return false;
    }
	}
	return true;
}

void frmCadLivros_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadLivros->btnNovoClick();
  frmCadLivros->InformaLimpaDados(false);
  frmCadLivros->HabilitaDados(true);	
}

void frmCadLivros_btnPesquisarClick_cb(Fl_Button* b, void* v){
  if (frmCadLivros->PesquisarDados(ConsSQL->Livro('S', 
    frmCadLivros->edtCodigo->value(),
    "","","","","","","","",""), STR_LIVNENC)){
    frmCadLivros->InformaLimpaDados(true);
    frmCadLivros->HabilitaDados(true);	
  }
}

void frmCadLivros_btnAnteriorClick_cb(Fl_Button* b, void* v){
  if (frmCadLivros->registroAnterior())
    frmCadLivros->InformaLimpaDados(true);
}

void frmCadLivros_btnProximoClick_cb(Fl_Button* b, void* v){
  if (frmCadLivros->registroProximo())
    frmCadLivros->InformaLimpaDados(true);
}

void frmCadLivros_btnSalvarClick_cb(Fl_Button* b, void* v){
  string sCodIdioma, sSqlInsert, sSqlUpdate;
  char sEdicao[TAM_MAX_STR], sAnoPubli[TAM_MAX_STR], 
    sVolume[TAM_MAX_STR], sNPaginas[TAM_MAX_STR], sQtdEstoque[TAM_MAX_STR];
  int nPos;
  
  nPos = frmCadLivros->cmbIdioma->value();
  sCodIdioma = ListaStr->pesquisaItemOrd(frmCadLivros_slIdiomas, nPos);

  sprintf(sEdicao, "%.0f", frmCadLivros->edtEdicao->value());
  sprintf(sAnoPubli, "%.0f", frmCadLivros->edtAnoPubli->value());
  sprintf(sVolume, "%.0f", frmCadLivros->edtVolume->value());
  sprintf(sNPaginas, "%.0f", frmCadLivros->edtNPaginas->value());
  sprintf(sQtdEstoque, "%.0f", frmCadLivros->edtQtdEstoque->value());

  sSqlUpdate = ConsSQL->Livro('U', frmCadLivros->edtCodigo->value(), 
    frmCadLivros->edtDescricao->value(), sEdicao, 
    sAnoPubli, sVolume, frmCadLivros->edtCodEditora->value(), 
    sCodIdioma, sNPaginas, 
    Rotinas->VirgulaParaPonto((char*)frmCadLivros->edtPreco->value(),false),
    sQtdEstoque);

  sSqlInsert = ConsSQL->Livro('I', frmCadLivros->edtCodigo->value(), 
    frmCadLivros->edtDescricao->value(), sEdicao, 
    sAnoPubli, sVolume, frmCadLivros->edtCodEditora->value(), 
    sCodIdioma, sNPaginas, 
    Rotinas->VirgulaParaPonto((char*)frmCadLivros->edtPreco->value(),false),
    sQtdEstoque);
  fl_alert(sSqlInsert.c_str());
  fl_alert(sSqlUpdate.c_str());
  if (frmCadLivros->SalvarDados(frmCadLivros->ValidaDados(true),
    ConsSQL->Livro('S', frmCadLivros->edtCodigo->value(),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, false)) {
    frmCadLivros->SalvaLista('A');
    frmCadLivros->SalvaLista('B');
    frmCadLivros->btnLimparClick();
    frmCadLivros->InformaLimpaDados(false);
    frmCadLivros->HabilitaDados(false);	    
  }  
}

void frmCadLivros_btnExcluirClick_cb(Fl_Button* b, void* v){
  if (frmCadLivros->ExcluirDados(frmCadLivros->ValidaDados(false),
    ConsSQL->Livro('D', frmCadLivros->edtCodigo->value(),
    "","","","","","","","",""))) {
    frmCadLivros->InformaLimpaDados(false);
    frmCadLivros->HabilitaDados(false);	
  }  
}

void frmCadLivros_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadLivros->btnLimparClick();
  frmCadLivros->InformaLimpaDados(false);
  frmCadLivros->HabilitaDados(false);	
}

void frmCadLivros_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadLivros->hide();
}

void CfrmCadLivros::InformaLimpaDados(bool bInformar) { 
string sTemp;

  if (bInformar) {
    edtEdicao->value(atof(
      ListaStr->pesquisaItemOrdM(lstRegistros, 2, nLinhaRegistro)));
    edtAnoPubli->value(atof(
      ListaStr->pesquisaItemOrdM(lstRegistros, 3, nLinhaRegistro)));
    edtVolume->value(atof(
      ListaStr->pesquisaItemOrdM(lstRegistros, 4, nLinhaRegistro)));
    edtCodEditora->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 5, nLinhaRegistro));
    edtEditora->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 6, nLinhaRegistro));
    cmbIdioma->value(cmbIdioma->find_item(
      ListaStr->pesquisaItemOrdM(lstRegistros, 8, nLinhaRegistro)));
    edtNPaginas->value(atof(
      ListaStr->pesquisaItemOrdM(lstRegistros, 9, nLinhaRegistro)));
    edtPreco->value(Rotinas->VirgulaParaPonto(
      ListaStr->pesquisaItemOrdM(lstRegistros, 10, nLinhaRegistro), true));
    edtQtdEstoque->value(atof(
      ListaStr->pesquisaItemOrdM(lstRegistros, 11, nLinhaRegistro)));
    
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAss('S', 
      edtCodigo->value(), ""), lstAssuntos, &frmCadLivros_slAssuntos);      
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAut('S',
      edtCodigo->value(), ""), lstAutores, &frmCadLivros_slAutores);
    
  } else {  
    edtEdicao->value(1);
    sTemp = Rotinas->retDataHoraStr(true,false);
    edtAnoPubli->value(atof(sTemp.substr(6,4).c_str()));
    edtVolume->value(1);
    edtCodEditora->value("");
    edtEditora->value("");
    cmbIdioma->value(0);    
    edtNPaginas->value(1);
    edtPreco->value("0,00");
    edtQtdEstoque->value(1);
    edtCodAssunto->value("");
    lstAssuntos->clear();
    edtCodAutor->value("");
    lstAutores->clear();
  }
} 

void CfrmCadLivros::HabilitaDados(bool bHabilita)
{
  if (bHabilita) {
    edtEdicao->activate();
    edtAnoPubli->activate();
    edtVolume->activate();
    edtCodEditora->activate();
    btnPEditora->activate();
    cmbIdioma->activate();
    edtNPaginas->activate();
    edtPreco->activate();
    edtQtdEstoque->activate();
    edtCodAssunto->activate();
    btnPAssunto->activate();
    btnAdAssuntos->activate();
    lstAssuntos->activate();
    edtCodAutor->activate();
    btnPAutor->activate();
    btnAdAutores->activate();
    lstAutores->activate();
  } else {
    edtEdicao->deactivate();
    edtAnoPubli->deactivate();
    edtVolume->deactivate();
    edtCodEditora->deactivate();
    btnPEditora->deactivate();
    cmbIdioma->deactivate();
    edtNPaginas->deactivate();
    edtPreco->deactivate();
    edtQtdEstoque->deactivate();
    edtCodAssunto->deactivate();
    btnPAssunto->deactivate();
    btnAdAssuntos->deactivate();
    lstAssuntos->deactivate();
    edtCodAutor->deactivate();
    btnPAutor->deactivate();
    btnAdAutores->deactivate();
    lstAutores->deactivate();
  }
}

void frmCadLivros_edtCodigoKillFocus_cb(Fl_Input* i, void* v){
  if (strlen(frmCadLivros->edtCodigo->value()) > 0) {
  	if (Rotinas->validaISBN(frmCadLivros->edtCodigo->value())==false) {
      fl_alert(STR_ISBNINV);
      frmCadLivros->edtCodigo->value("");
  		frmCadLivros->edtCodigo->take_focus();
  	}
  }	
}

void CfrmCadLivros::AdicionaCombo() 
{
  LISTAMSTR Campos, local = NULL;

  if (Rotinas->ConsultaDadosLista(gConexao, &Campos, 
    ConsSQL->Idioma('S',"",""))) {
	  frmCadLivros_slIdiomas = ListaStr->inicia();
	  for (local = Campos; local != NULL; local = local->proximo) {	
	    ListaStr->insereFim(&frmCadLivros_slIdiomas, local->str[0]);
      cmbIdioma->add(local->str[1]);
	  }      
  }
  ListaStr->liberaM(Campos);
  ListaStr->liberaM(local);
}

void CfrmCadLivros::SalvaLista(char sOpcao) 
{
string sISBN;
int nCont, nQtd;

  sISBN = frmCadLivros->edtCodigo->value();
  if (sOpcao=='A') {
    Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('D',sISBN,""));
   
    nQtd = ListaStr->conta(frmCadLivros_slAssuntos);
    for (nCont=0; nCont < nQtd; nCont++)  {      
      Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('I', 
        sISBN, ListaStr->pesquisaItemOrd(frmCadLivros_slAssuntos, nCont)));
    }
  } else if (sOpcao=='B') {
  	Rotinas->AtualizaDados(gConexao,ConsSQL->LivroAut('D',sISBN,""));

    nQtd = ListaStr->conta(frmCadLivros_slAutores);    
  	for (nCont=0; nCont < nQtd; nCont++)  {
  	  Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAut('I', 
        sISBN, ListaStr->pesquisaItemOrd(frmCadLivros_slAutores, nCont)));
  	}
  }
}


void frmCadLivros_edtCodEditoraKillFocus_cb(Fl_Input* i, void* v){
string sEditora;
LISTAMSTR ConsCampo;

  if (strlen(frmCadLivros->edtCodEditora->value()) > 0) {
    sEditora = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Editora('S',
      frmCadLivros->edtCodEditora->value(),""),STR_EDTNENC);    
    if (sEditora.length() > 0) {
      frmCadLivros->edtEditora->value(sEditora.c_str());
    } else {
      frmCadLivros->edtCodEditora->value("");
      frmCadLivros->edtCodEditora->take_focus();
    }
  } else {
    frmCadLivros->edtEditora->value("");
  }
}

void frmCadLivros_btnPEditoraClick_cb(Fl_Button* b, void* v){
  frmConEditoras = new CfrmConEditoras(true);
  frmConEditoras->show();
}

void frmCadLivros_edtCodAssuntoKillFocus_cb(Fl_Input* i, void* v){
string sAssunto;
LISTAMSTR ConsCampo;

  if (strlen(frmCadLivros->edtCodAssunto->value()) > 0) {
    sAssunto = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Assunto('S',
      frmCadLivros->edtCodAssunto->value(),""),STR_ASSNENC);    
    if (sAssunto.length() > 0) {
      frmCadLivros->edtAssunto->value(sAssunto.c_str());
    } else {
      frmCadLivros->edtCodAssunto->value("");
      frmCadLivros->edtCodAssunto->take_focus();
    }
  } else {
    frmCadLivros->edtAssunto->value("");
  }
}

void frmCadLivros_btnAdAssuntosClick_cb(Fl_Button* b, void* v){
  Rotinas->AdicionaItemLista(frmCadLivros->lstAssuntos, 
    &frmCadLivros_slAssuntos, frmCadLivros->edtCodAssunto, 
    frmCadLivros->edtAssunto);
}

void frmCadLivros_btnPAssuntoClick_cb(Fl_Button* b, void* v){
  frmConAssuntos = new CfrmConAssuntos(true);
  frmConAssuntos->show();
}

void frmCadLivros_lstAssuntosDblClick_cb(Fl_Browser* b, void* v){
  if (Fl::event_clicks()==1) //duplo-clique
    Rotinas->RemoveItemLista(
      frmCadLivros->lstAssuntos,&frmCadLivros_slAssuntos);
}

void frmCadLivros_edtCodAutorKillFocus_cb(Fl_Input* i, void* v){
string sAutor;
LISTAMSTR ConsCampo;

  if (strlen(frmCadLivros->edtCodAutor->value()) > 0) {
    sAutor = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Autor('S',
      frmCadLivros->edtCodAutor->value(),""),STR_AUTNENC);    
    if (sAutor.length() > 0) {
      frmCadLivros->edtAutor->value(sAutor.c_str());
    } else {
      frmCadLivros->edtCodAutor->value("");
      frmCadLivros->edtCodAutor->take_focus();
    }
  } else {
    frmCadLivros->edtAutor->value("");
  }
}

void frmCadLivros_btnAdAutoresClick_cb(Fl_Button* b, void* v){
  Rotinas->AdicionaItemLista(frmCadLivros->lstAutores, 
    &frmCadLivros_slAutores, frmCadLivros->edtCodAutor, 
    frmCadLivros->edtAutor);	
}

void frmCadLivros_btnPAutorClick_cb(Fl_Button* b, void* v){
  frmConAutores = new CfrmConAutores(true);
  frmConAutores->show();
}

void frmCadLivros_lstAutoresDblClick_cb(Fl_Browser* b, void* v){
  if (Fl::event_clicks()==1) //duplo-clique
    Rotinas->RemoveItemLista(
      frmCadLivros->lstAutores,&frmCadLivros_slAutores);
}

int CfrmCadLivros::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->tlbLivros->activate();
    frmPrincipal->mnuCadLivros->activate();
  }
  return CfrmCadastros::handle(event);
}
