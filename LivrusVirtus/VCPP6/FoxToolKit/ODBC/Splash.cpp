#include "resource.h"
#include "Splash.h"
#include "Login.h"

CfrmSplash *frmSplash = (CfrmSplash *) NULL;

FXDEFMAP(CfrmSplash) CfrmSplashMap[]={
  FXMAPFUNC(SEL_TIMEOUT, CfrmSplash::ID_FRMSPLASH_TIMER, 
    CfrmSplash::onTimer)
};
FXIMPLEMENT(CfrmSplash,FXDialogBox,CfrmSplashMap,ARRAYNUMBER(CfrmSplashMap))

CfrmSplash::CfrmSplash(FXApp* owner):
  FXDialogBox(owner, "Splash", DECOR_NONE, 
    0, 0, 0, 0, 0, 0, 0, 0, 4, 4){
  IniciaControles();
}

void CfrmSplash::IniciaControles() {
  bmpLivrusVirtus = new FXBMPIcon(getApp(), LivrusVirtus);  
  new FXLabel(this, "", bmpLivrusVirtus, LAYOUT_CENTER_X); 
}

void CfrmSplash::create(){
  FXDialogBox::create();
}

void CfrmSplash::iniciaTimer(){
  mTimer = getApp()->addTimeout(this, ID_FRMSPLASH_TIMER, 1000);
}

CfrmSplash::~CfrmSplash(){
  delete bmpLivrusVirtus;
  getApp()->removeTimeout(mTimer);
}

long CfrmSplash::onTimer(FXObject*,FXSelector,void*) {
  mTimer = NULL;
  frmLogin->show(PLACEMENT_SCREEN);
  this->close();
  return true;
}

