#include "resource.h"
#include "DateCtrl.h"
#include "RotinasGlobais.h"

#include "xpms/seta.xpm"
#include "xpms/dseta.xpm"

BEGIN_EVENT_TABLE(CDateCtrl, wxPanel)
  EVT_BUTTON(ID_DATECTRL_BTNMOSTRAR, CDateCtrl::OnBtnMostrar)
  EVT_CALENDAR_DAY(ID_DATECTRL_CALCALENDARIO, CDateCtrl::OnCalendarioDia) 
  EVT_TEXT(ID_DATECTRL_EDTDATA, CDateCtrl::OnEdtData_Text)
END_EVENT_TABLE()

CDateCtrl::CDateCtrl(wxWindow* parent, wxWindowID id, 
  const wxPoint& pos, const wxSize& size, long style, const wxString& name) 
  :wxPanel(parent, id, pos, size, style, name)
{ 
  int x, y, nLargura, nAltura;  

  edtData = new wxTextCtrl(this, ID_DATECTRL_EDTDATA,
    wxT(""), wxPoint(0,0), size, style, wxDefaultValidator, name);    
  edtData->GetPosition(&x, &y);
  edtData->GetSize(&nLargura, &nAltura); 
  edtData->SetMaxLength(10);
  edtData->Connect(edtData->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) &CDateCtrl::OnEdtData_Killfocus);
  edtData->Connect(edtData->GetId(), wxEVT_SET_FOCUS, 
    (wxObjectEventFunction) &CDateCtrl::OnEdtData_Setfocus);

  btnMostrar = new wxBitmapButton(edtData, ID_DATECTRL_BTNMOSTRAR, 
  	wxBitmap( seta_xpm ), wxPoint(x+nLargura-20, y+1), wxSize(16, 16));
  btnMostrar->SetBitmapDisabled(wxBitmap( dseta_xpm ));
  btnMostrar->SetBackgroundColour(
    wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

  #ifdef __WXMSW__
    pwPopup = new wxPopupTransientWindow(this);
  #else
    pwPopup = new wxDialog(this, -1, wxT(""), wxDefaultPosition, wxDefaultSize);
  #endif

  calCalendario = new wxCalendarCtrl(pwPopup, ID_DATECTRL_CALCALENDARIO,
    wxDefaultDateTime,wxPoint(0,0), wxDefaultSize,
    wxCAL_SEQUENTIAL_MONTH_SELECTION );
}

CDateCtrl::~CDateCtrl() { 
}

void CDateCtrl::OnBtnMostrar(wxCommandEvent& event) {
wxPoint ptOrigem;
  ptOrigem = btnMostrar->ClientToScreen(wxPoint(0, 0));
  #ifdef __WXMSW__
    ptOrigem.x -= 339;
    ptOrigem.y -= 110;
    pwPopup->Position(ptOrigem, calCalendario->GetBestSize());
  #else
    ptOrigem.x -= 150;
    ptOrigem.y -= 20;
    pwPopup->Move(wxPoint());
  #endif
  pwPopup->SetSize(calCalendario->GetBestSize());
  calCalendario->SetDate(this->GetData());
  #ifdef __WXMSW__
    pwPopup->Popup();
  #else
    pwPopup->ShowModal();
  #endif
  event.Skip();
}

void CDateCtrl::OnCalendarioDia(wxCalendarEvent& event) {
  #ifdef __WXMSW__
    pwPopup->Dismiss();
  #else
    pwPopup->EndModal(true);
  #endif
  edtData->SetValue(
    Rotinas->FormataDataHoraStr(calCalendario->GetDate(), "%d/%m/%Y", ""));
  event.Skip();
}

void CDateCtrl::OnEdtData_Killfocus(wxFocusEvent& event)
{ wxTextCtrl *mData;
 
  mData = (wxTextCtrl*)event.GetEventObject();
  if (mData->GetValue().Len() > 0) {
    if (!Rotinas->validaDataHora(mData->GetValue(), true)) {
      wxMessageBox(wxT(STR_DTHRINV), wxT("Erro"), wxOK | wxICON_ERROR);
      mData->SetValue(Rotinas->retDataHoraStr(true,false));
  		mData->SetFocus();
    }
  } else
      mData->SetValue(Rotinas->retDataHoraStr(true,false));
  event.Skip();
}

void CDateCtrl::OnEdtData_Setfocus(wxFocusEvent& event)
{ wxTextCtrl *mData;
  wxButton *mMostrar;
 
  mData = (wxTextCtrl*)event.GetEventObject();
  mMostrar = (wxButton*)
    wxWindow::FindWindowById(ID_DATECTRL_BTNMOSTRAR, mData);
  mMostrar->Refresh();
  event.Skip();
}

void CDateCtrl::OnEdtData_Text(wxCommandEvent& event) {
  btnMostrar->Refresh();
  event.Skip();
}

void CDateCtrl::SetDataStr(wxString sData, bool bDMY_ou_YMD) {
  edtData->SetValue(
    Rotinas->ConverteDataHoraStr(sData, bDMY_ou_YMD, "%d/%m/%Y", ""));
}

void CDateCtrl::SetData(wxDateTime sData) {
  edtData->SetValue(
    Rotinas->FormataDataHoraStr(sData, "%d/%m/%Y", ""));
}

wxString CDateCtrl::GetDataStr(bool bDMY_ou_YMD) {
  return Rotinas->ConverteDataHoraStr(
    edtData->GetValue(), bDMY_ou_YMD, "%d/%m/%Y", "");
}

wxDateTime CDateCtrl::GetData() {  
  unsigned long ndia = 1, nmes = 1, nano = 1;
  wxDateTime mTempo;

  edtData->GetValue().Mid(0,2).ToULong(&ndia, 10);
  edtData->GetValue().Mid(3,2).ToULong(&nmes, 10);
  edtData->GetValue().Mid(6,4).ToULong(&nano, 10);

  mTempo.Set(ndia, wxDateTime::Month(nmes-1), nano);
  return mTempo;
}

void CDateCtrl::Limpar() {
  edtData->SetValue(Rotinas->retDataHoraStr(true,false));
}

void CDateCtrl::Habilitar(bool bHabilita) {
  edtData->Enable(bHabilita);
  btnMostrar->Enable(bHabilita);
}
