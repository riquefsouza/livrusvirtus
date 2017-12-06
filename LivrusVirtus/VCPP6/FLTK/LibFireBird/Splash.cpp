#include "Splash.h"
#include "Login.h"

CfrmSplash *frmSplash;
//Fl_Timer *mTimer;

void frmSplash_Timer_cb(void* v);

CfrmSplash::CfrmSplash()
       : Fl_Double_Window(259, 73) {
	IniciaControles();
}

CfrmSplash::~CfrmSplash() { }

void CfrmSplash::IniciaControles() {
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
  imagem1 = new Fl_Box(0, 0, 260, 70);
  imagem1->image(image_livrusvirtus);
  this->hotspot(this, 15);
  this->set_modal();
  this->clear_border();
  /*
  mTimer = new Fl_Timer(FL_HIDDEN_TIMER, 0, 0, 50, 20, "");
  mTimer->callback((Fl_Callback*)frmSplash_Timer_cb);
  mTimer->value(3.0);
  mTimer->direction(0);
  */
  this->end();
  Fl::add_timeout(3.0, frmSplash_Timer_cb);
}
  
void frmSplash_Timer_cb(void* v) {
  Fl::repeat_timeout(1.0, frmSplash_Timer_cb);
//  mTimer->suspended(true);
  frmSplash->hide();
  //Fl::remove_timeout(frmSplash_Timer_cb);  
}
