#ifndef SOBRE_H
#define SOBRE_H

class CfrmSobre: public wxDialog {
protected:
  wxButton  *btnOk;
  wxStaticText *labVersao;
  wxStaticBitmap *labBmp;
  wxStaticText *labDireitos;
  wxStaticText *labSistema;

  void OnBtnOk(wxCommandEvent& event);
public:
  CfrmSobre(wxWindow *parent);
  ~CfrmSobre();
private:    
  void IniciaControles();    
  void FazLayout();

  DECLARE_EVENT_TABLE();
};

enum
{
  ID_FRMSOBRE_BTNOK = 300,
  ID_FRMSOBRE_LABVERSAO,
  ID_FRMSOBRE_LABBMP,
  ID_FRMSOBRE_LABDIREITOS,
  ID_FRMSOBRE_LABSISTEMA
};

#endif


