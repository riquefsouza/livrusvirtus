#!/bin/env python
# -*- coding: iso-8859-1 -*-
#----------------------------------------------------------------------------
# Name:         Livrus.py
# Author:       XXXX
# Created:      XX/XX/XX
# Copyright:    
#----------------------------------------------------------------------------

from wxPython.wx import *

from Livrus_wdr import *


# WDR: classes

class frmPrincipal(wxFrame):
    def __init__(self, parent, id, title,
        pos = wxPyDefaultPosition, size = wxPyDefaultSize,
        style = wxDEFAULT_FRAME_STYLE ):
        wxFrame.__init__(self, parent, id, title, pos, size, style)
        
        self.CreateMyMenuBar()
        
        self.CreateMyToolBar()
        
        self.CreateStatusBar(1)
        self.SetStatusText("Welcome!")
        
        # insert main window here
        
        # WDR: handler declarations for frmPrincipal
        EVT_MENU(self, ID_ABOUT, self.OnAbout)
        EVT_MENU(self, ID_QUIT, self.OnQuit)
        EVT_CLOSE(self, self.OnCloseWindow)
        EVT_SIZE(self, self.OnSize)
        EVT_UPDATE_UI(self, -1, self.OnUpdateUI)
        
    # WDR: methods for frmPrincipal
    
    def CreateMyMenuBar(self):
        self.SetMenuBar( MyMenuBarFunc() )
    
    def CreateMyToolBar(self):
        tb = self.CreateToolBar(wxTB_HORIZONTAL|wxNO_BORDER)
        MyToolBarFunc( tb )
    
    # WDR: handler implementations for frmPrincipal
    
    def OnAbout(self, event):
        dialog = wxMessageDialog(self, "Welcome to SuperApp 1.0\n(C)opyright Joe Hacker",
            "About SuperApp", wxOK|wxICON_INFORMATION )
        dialog.CentreOnParent()
        dialog.ShowModal()
        dialog.Destroy()
    
    def OnQuit(self, event):
        self.Close(True)
    
    def OnCloseWindow(self, event):
        self.Destroy()
    
    def OnSize(self, event):
        event.Skip(True)
    
    def OnUpdateUI(self, event):
        event.Skip(True)
    

#----------------------------------------------------------------------------

class LivrusApp(wxApp):
    
    def OnInit(self):
        wxInitAllImageHandlers()
        frame = frmPrincipal(None, -1, "SuperApp", wxPoint(20,20), wxSize(500,340) )
        frame.Show(True)
        
        return true

#----------------------------------------------------------------------------

app = LivrusApp(1)
app.MainLoop()

