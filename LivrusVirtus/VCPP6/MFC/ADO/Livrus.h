// Livrus.h : main header file for the LIVRUS application
//

#if !defined(AFX_LIVRUS_H__2FC47DF9_C8C7_4A66_A159_12725BA3BB43__INCLUDED_)
#define AFX_LIVRUS_H__2FC47DF9_C8C7_4A66_A159_12725BA3BB43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLivrusApp:
// See Livrus.cpp for the implementation of this class
//

class CLivrusApp : public CWinApp
{
public:
	CLivrusApp();
	//HMENU m_hMDIMenu;
	//HACCEL m_hMDIAccel;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLivrusApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:

public:
	//{{AFX_MSG(CLivrusApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern HMENU g_hMDIMenu;
extern HACCEL g_hMDIAccel;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIVRUS_H__2FC47DF9_C8C7_4A66_A159_12725BA3BB43__INCLUDED_)
