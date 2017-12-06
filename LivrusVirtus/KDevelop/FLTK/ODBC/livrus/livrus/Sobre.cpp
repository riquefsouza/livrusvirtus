#include "Principal.h"
#include "Sobre.h"

CfrmSobre *frmSobre;

void frmSobre_btnOkClick_cb(Fl_Button* b, void* v);

CfrmSobre::CfrmSobre()
       : Fl_Double_Window(302, 267, STR_OPSOBRE) {
	IniciaControles();
}

CfrmSobre::~CfrmSobre() { }

void CfrmSobre::IniciaControles() {
  this->box(FL_FLAT_BOX);
  this->color(FL_BACKGROUND_COLOR);
  this->selection_color(FL_BACKGROUND_COLOR);
  this->labelfont(0);
  this->labelsize(14);
  this->labelcolor(FL_BLACK);
  this->user_data((void*)(this));
  this->align(FL_ALIGN_TOP);
  this->when(FL_WHEN_RELEASE);
  grupo1 = new Fl_Group(5, 5, 290, 220);
    grupo1->box(FL_ENGRAVED_BOX);
    imagem1 = new Fl_Box(20, 15, 260, 80);
    imagem1->image(image_livrusvirtus);
    labVersao = new Fl_Box(195, 95, 95, 20, "Vers\343o 1.0.0");
    labDireitos = new Fl_Box(15, 120, 275, 40, 
      "Todos os diretos reservados para: Henrique F. de Souza");
    labDireitos->align(FL_ALIGN_WRAP);
    labSistema = new Fl_Box(10, 165, 285, 55, 
    "Sistema integrante do projeto Livrus Virtus, vers\343o programada " \
    "no Visual C++ 6.0 usando FLTK.");
    labSistema->align(FL_ALIGN_WRAP);
  grupo1->end();
  btnOk = new Fl_Return_Button(115, 235, 75, 25, "&Ok");
  btnOk->callback((Fl_Callback*)frmSobre_btnOkClick_cb);
  this->hotspot(this);
  this->set_modal();
  this->end();

}

void frmSobre_btnOkClick_cb(Fl_Button* b, void* v){
  frmPrincipal->BarraDeStatus2->label("");
  frmSobre->hide();
}
