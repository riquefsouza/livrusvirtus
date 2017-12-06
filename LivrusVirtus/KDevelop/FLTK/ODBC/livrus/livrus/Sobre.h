#ifndef SOBRE_H
#define SOBRE_H

#include "resource.h"

class CfrmSobre : public Fl_Double_Window {
public:
  CfrmSobre();
  ~CfrmSobre();

protected:
  Fl_Group *grupo1;
  Fl_Box *imagem1;
  Fl_Box *labVersao;
  Fl_Box *labDireitos;
  Fl_Box *labSistema;
  Fl_Return_Button *btnOk;

private:
  void IniciaControles();
};

extern CfrmSobre *frmSobre;

#endif
