#ifndef SOBRE_H
#define SOBRE_H

class CfrmSobre : public FXDialogBox {
  FXDECLARE(CfrmSobre)

public:
  CfrmSobre(FXWindow* owner);
  virtual void create();
  virtual ~CfrmSobre();

protected:
  FXGroupBox          *grupo;
  FXIcon              *bmpLivrusVirtus;
  FXHorizontalFrame   *frameok;

private:
  CfrmSobre(){}

  void IniciaControles();
};

extern CfrmSobre *frmSobre;

#endif
