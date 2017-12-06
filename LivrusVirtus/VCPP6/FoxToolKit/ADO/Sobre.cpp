#include "resource.h"
#include "Sobre.h"

CfrmSobre *frmSobre = (CfrmSobre *) NULL;

FXIMPLEMENT(CfrmSobre,FXDialogBox,NULL,0)

CfrmSobre::CfrmSobre(FXWindow* owner):
  FXDialogBox(owner, STR_OPSOBRE, DECOR_TITLE | DECOR_CLOSE, 
    0, 0, 0, 0, 0, 0, 0, 0, 4, 4){
  IniciaControles();
}

void CfrmSobre::IniciaControles() {
  this->setIcon(new FXBMPIcon(getApp(),Livrus));

  grupo = new FXGroupBox(this, "",
  GROUPBOX_TITLE_LEFT|FRAME_RIDGE|LAYOUT_FILL_X);

  bmpLivrusVirtus = new FXBMPIcon(getApp(), LivrusVirtus);  
  new FXLabel(grupo, "", bmpLivrusVirtus, LAYOUT_CENTER_X);
  new FXLabel(grupo, "Versão: 1.0.0", NULL, LAYOUT_RIGHT);
  new FXLabel(grupo, "Todos os direitos reservados para: Henrique F. de Souza", 
    NULL, LAYOUT_CENTER_X);
  new FXLabel(grupo, "Sistema integrante do projeto Livrus Virtus, ",
    NULL, LAYOUT_CENTER_X);
  new FXLabel(grupo, "versão programada no Visual C++ 6.0 usando a FOX GUI Toolkit", 
    NULL, LAYOUT_CENTER_X);
  
  frameok = new FXHorizontalFrame(this,
    LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH);
  new FXButton(frameok, "&Ok", NULL, this, FXDialogBox::ID_CANCEL,
    LAYOUT_CENTER_X|FRAME_RAISED|FRAME_THICK, 0, 0, 0, 0, 30, 30);
}

void CfrmSobre::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmSobre::~CfrmSobre(){
  delete grupo;
  delete bmpLivrusVirtus;
  delete frameok;
}
