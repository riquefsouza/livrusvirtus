// Consultas.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Consultas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmConsultas

CFrmConsultas::CFrmConsultas(UINT nIDTemplate, CWnd* pParent /*=NULL*/)
  : CDialog(nIDTemplate, pParent)
{
  bModal = TRUE;
}


BEGIN_MESSAGE_MAP(CFrmConsultas, CDialog)
	//{{AFX_MSG_MAP(CFrmConsultas)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFrmConsultas message handlers

VOID CFrmConsultas::Ativar(INT idSubMenu)
{
  Rotinas->habilitaSubMenu(1, idSubMenu, FALSE);
}

VOID CFrmConsultas::Fecha(CString sSelecionado, INT idSubMenu)
{
 if (sSelecionado.GetLength() > 0)
   Rotinas_sCodigoSelecionado = sSelecionado;
 else
   Rotinas_sCodigoSelecionado = "";
  
 Rotinas->habilitaSubMenu(1, idSubMenu, TRUE);

 if (bModal)
   EndDialog(TRUE); 
 else
   DestroyWindow();

}

VOID CFrmConsultas::setLabRegistros(CStatic *idLabRegs, 
    LISTAMSTR *sLinhas, INT nReg)
{
  CString sRegs;
  UINT nTotal;
  
  if (nReg == 0) nTotal = 0;
  else nTotal = sLinhas->col[0].GetCount();
  
  sRegs.Format("Registro %d de %d", nReg, nTotal);
  idLabRegs->SetWindowText(sRegs);
}

VOID CFrmConsultas::arrumaTamanho(CListCtrl *idListaCons, 
  CStatic *idLabRegs, CButton *idBtnLimpar, CButton *idBtnFechar)
{
RECT rForm, rRegs, rLimpar, rFechar;
INT hFrm, wFrm;
        
GetClientRect(&rForm);
idLabRegs->GetClientRect(&rRegs);
idBtnLimpar->GetClientRect(&rLimpar);
idBtnFechar->GetClientRect(&rFechar);

hFrm = (rForm.bottom - rForm.top);
wFrm = (rForm.right - rForm.left);

idListaCons->MoveWindow(0, 51, wFrm, hFrm - 90, TRUE);
idLabRegs->MoveWindow(8, (hFrm - 30), 
  (rRegs.right - rRegs.left), (rRegs.bottom - rRegs.top), TRUE);
idBtnLimpar->MoveWindow((wFrm - 155), (hFrm - 30), 
  (rLimpar.right - rLimpar.left), (rLimpar.bottom - rLimpar.top), TRUE);
idBtnFechar->MoveWindow((wFrm - 80), (hFrm - 30), 
  (rFechar.right - rFechar.left), (rFechar.bottom - rFechar.top), TRUE);
}

BOOL CFrmConsultas::Notifica(LPARAM lParam, CListCtrl *idListaCons, 
    CStatic *idLabRegs, LISTAMSTR *sLinhas, CString *sSelecionado) 
{
INT nReg;      

 if (Rotinas->VisaoListaNotifica(idListaCons, sLinhas, lParam, &nReg,
    sSelecionado)) {               

   if (nReg > 0) {
     setLabRegistros(idLabRegs, sLinhas, nReg);                        
   }                  
   return TRUE;
 }
 return FALSE;
}

VOID CFrmConsultas::LimparDados(CStatic *idLabRegs, 
  CEdit *idEdtDesc, CListCtrl *idListaCons, LISTAMSTR *sLinhas)
{
  setLabRegistros(idLabRegs, sLinhas, 0);
  idListaCons->DeleteAllItems();
  idEdtDesc->SetWindowText("");
  idEdtDesc->SetFocus();
}

VOID CFrmConsultas::PesquisarDados(CListCtrl *idListaCons, 
  CStatic *idLabRegs, LISTAMSTR *sLinhas, CString sTextoSql, 
  CString sMensagemErro)
{
    if (Rotinas->ConsultaDadosLista(gConexao, sLinhas, sTextoSql)) {
       Rotinas->VisaoListaInsereLinhas(idListaCons, sLinhas);
       setLabRegistros(idLabRegs, sLinhas, 1);
    } else {
       AfxMessageBox(sMensagemErro, MB_ICONERROR | MB_OK, 0);
    }
}
