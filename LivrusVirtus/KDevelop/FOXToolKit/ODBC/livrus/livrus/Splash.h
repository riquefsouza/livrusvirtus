#ifndef SPLASH_H
#define SPLASH_H

class CfrmSplash : public FXDialogBox {
  FXDECLARE(CfrmSplash)

public:
  enum { ID_FRMSPLASH_TIMER = FXDialogBox::ID_LAST };

  CfrmSplash(FXApp* owner);
  virtual void create();
  virtual ~CfrmSplash();
  long onTimer(FXObject*,FXSelector,void*);
  void iniciaTimer();

protected:
  FXIcon   *bmpLivrusVirtus;
  FXTimer  *mTimer;

private:
  CfrmSplash(){}

  void IniciaControles();
};

extern CfrmSplash *frmSplash;

#endif
