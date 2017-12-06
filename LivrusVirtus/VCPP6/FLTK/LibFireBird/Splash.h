#ifndef SPLASH_H
#define SPLASH_H

#include "resource.h"

class CfrmSplash : public Fl_Double_Window {
public:
  CfrmSplash();
  ~CfrmSplash();

protected:
  Fl_Box *imagem1;  

private:
  void IniciaControles();
};

extern CfrmSplash *frmSplash;
//extern Fl_Timer *mTimer;

#endif
