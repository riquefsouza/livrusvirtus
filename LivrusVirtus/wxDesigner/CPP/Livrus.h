/////////////////////////////////////////////////////////////////////////////
// Name:        Livrus.h
// Author:      XX
// Created:     XX/XX/XX
// Copyright:   
/////////////////////////////////////////////////////////////////////////////

#ifndef __Livrus_H__
#define __Livrus_H__

#if defined(__GNUG__) && !defined(__APPLE__)
    #pragma interface "Livrus.h"
#endif

// Include wxWindows' headers

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Livrus_wdr.h"

// WDR: class declarations

//----------------------------------------------------------------------------
// frmPrincipal
//----------------------------------------------------------------------------

class frmPrincipal: public wxFrame
{
public:
    // constructors and destructors
    frmPrincipal( wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE );
    
private:
    // WDR: method declarations for frmPrincipal
    void CreateMyMenuBar();
    void CreateMyToolBar();
    
private:
    // WDR: member variable declarations for frmPrincipal
    
private:
    // WDR: handler declarations for frmPrincipal
    void OnAbout( wxCommandEvent &event );
    void OnQuit( wxCommandEvent &event );
    void OnCloseWindow( wxCloseEvent &event );
    void OnSize( wxSizeEvent &event );
    void OnUpdateUI( wxUpdateUIEvent &event );
    
private:
    DECLARE_EVENT_TABLE()
};

//----------------------------------------------------------------------------
// LivrusApp
//----------------------------------------------------------------------------

class LivrusApp: public wxApp
{
public:
    LivrusApp();
    
    virtual bool OnInit();
    virtual int OnExit();
};

#endif
