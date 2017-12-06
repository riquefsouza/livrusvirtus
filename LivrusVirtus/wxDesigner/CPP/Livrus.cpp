/////////////////////////////////////////////////////////////////////////////
// Name:        Livrus.cpp
// Author:      XX
// Created:     XX/XX/XX
// Copyright:   
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "Livrus.h"
#endif

// For compilers that support precompilation
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// Include private headers
#include "Livrus.h"

// WDR: class implementations

//------------------------------------------------------------------------------
// frmPrincipal
//------------------------------------------------------------------------------

// WDR: event table for frmPrincipal

BEGIN_EVENT_TABLE(frmPrincipal,wxFrame)
    EVT_MENU(ID_ABOUT, frmPrincipal::OnAbout)
    EVT_MENU(ID_QUIT, frmPrincipal::OnQuit)
    EVT_CLOSE(frmPrincipal::OnCloseWindow)
    EVT_SIZE(frmPrincipal::OnSize)
    EVT_UPDATE_UI(-1,frmPrincipal::OnUpdateUI)
END_EVENT_TABLE()

frmPrincipal::frmPrincipal( wxWindow *parent, wxWindowID id, const wxString &title,
    const wxPoint &position, const wxSize& size, long style ) :
    wxFrame( parent, id, title, position, size, style )
{
    CreateMyMenuBar();
    
    CreateMyToolBar();
    
    CreateStatusBar(1);
    SetStatusText( wxT("Welcome!") );
    
     // insert main window here
}

void frmPrincipal::CreateMyMenuBar()
{
#ifdef __WXMAC__
    wxApp::s_macAboutMenuItemId = ID_ABOUT;
#endif

    SetMenuBar( MyMenuBarFunc() );
}

void frmPrincipal::CreateMyToolBar()
{
    wxToolBar *tb = CreateToolBar( wxTB_HORIZONTAL|wxNO_BORDER /* |wxTB_FLAT */ );
    
    MyToolBarFunc( tb );
}

// WDR: handler implementations for frmPrincipal

void frmPrincipal::OnAbout( wxCommandEvent &event )
{
    wxMessageDialog dialog( this, wxT("Welcome to SuperApp 1.0\n(C)opyright Joe Hacker"),
        wxT("About SuperApp"), wxOK|wxICON_INFORMATION );
    dialog.ShowModal();
}

void frmPrincipal::OnQuit( wxCommandEvent &event )
{
     Close( TRUE );
}

void frmPrincipal::OnCloseWindow( wxCloseEvent &event )
{
    // if ! saved changes -> return
    
    Destroy();
}

void frmPrincipal::OnSize( wxSizeEvent &event )
{
    event.Skip( TRUE );
}

void frmPrincipal::OnUpdateUI( wxUpdateUIEvent &event )
{
    event.Skip( TRUE );
}

//------------------------------------------------------------------------------
// LivrusApp
//------------------------------------------------------------------------------

IMPLEMENT_APP(LivrusApp)

LivrusApp::LivrusApp()
{
}

bool LivrusApp::OnInit()
{
    frmPrincipal *frame = new frmPrincipal( NULL, -1, wxT("SuperApp"), wxPoint(20,20), wxSize(500,340) );
    frame->Show( TRUE );
    
    return TRUE;
}

int LivrusApp::OnExit()
{
    return 0;
}

