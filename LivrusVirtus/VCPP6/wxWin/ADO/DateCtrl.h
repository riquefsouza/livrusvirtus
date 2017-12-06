#ifndef DATECTRL_H
#define DATECTRL_H

class CDateCtrl : public wxPanel
{
public:
  CDateCtrl(wxWindow* parent, wxWindowID id, 
    const wxPoint& pos = wxDefaultPosition, 
    const wxSize& size = wxDefaultSize, long style = 0, 
    const wxString& name = wxPanelNameStr);
  ~CDateCtrl();
  void SetDataStr(wxString sData, bool bDMY_ou_YMD);
  void SetData(wxDateTime sData);
  wxString GetDataStr(bool bDMY_ou_YMD);
  wxDateTime GetData();
  void Limpar();
  void Habilitar(bool bHabilita);

protected:
  wxTextCtrl *edtData;
  wxBitmapButton *btnMostrar;  
  #ifdef __WXMSW__
    wxPopupTransientWindow *pwPopup;
  #else
    wxDialog *pwPopup;
  #endif
  wxCalendarCtrl *calCalendario;
  
  void OnBtnMostrar(wxCommandEvent& event);
  void OnCalendarioDia(wxCalendarEvent& event);
  void OnEdtData_Killfocus(wxFocusEvent& event);
  void OnEdtData_Setfocus(wxFocusEvent& event);
  void OnEdtData_Text(wxCommandEvent& event);

private:
  DECLARE_EVENT_TABLE();
};

enum {
   ID_DATECTRL_BTNMOSTRAR = 700, 
   ID_DATECTRL_CALCALENDARIO, 
   ID_DATECTRL_EDTDATA
  };

#endif

