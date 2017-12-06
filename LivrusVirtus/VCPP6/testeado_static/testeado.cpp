// testeado.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <objbase.h>
#include <afxdisp.h>
/*
#include <tchar.h>			// Unicode
//#include <ado.h>			// ADO C++ header
#include <adoid.h>			// ADO C++ header	 
#include <adoint.h>			// ADO C++ header
*/
#include <windows.h>
#include <initguid.h>  // Include only once in your application
#include "adoid.h"     // ADO GUID's
#include "adoint.h"    // ADO Classes, enums, etc.
//... INIT OLE ...


//#ifndef __AFXWIN_H__
	//#error include 'stdafx.h' before including this file for PCH
//#endif

//#define INITGUID

//#import "C:\Arquivos de programas\Arquivos comuns\System\ado\msado15.dll" \
//no_namespace rename("EOF", "EndOfFile")
//#import <msado15.dll> rename ( "EOF", "adoEOF" )


#include <stdio.h>

//_ConnectionPtr pADOConexao;
ADOConnection *pADOConexao;

LPTSTR TipoCampo(int nTipo) 
{
  switch (nTipo) {
  case adChar:
       return "adChar";
    break;
  case adVarChar:
       return "adVarChar";
    break;
  case adSmallInt:
       return "adSmallInt";
    break;
  case adUnsignedTinyInt:
       return "adUnsignedTinyInt";
    break;
  case adDBTimeStamp:
       return "adDBTimeStamp";
    break;
  default: 
      return "nada";
    break;
  }
}

void Rotinas_TESTEHR(HRESULT x) {

  TCHAR sTemp[256];

  if FAILED(x) {
    //_com_issue_error(x);
	    wsprintf(sTemp, "Erro: %d", x);
	    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
  }
};

BOOL Rotinas_ConectaBanco(LPTSTR sStrConexao)
{
  HRESULT		hr;
  TCHAR sTemp[256];

  if(FAILED(::CoInitialize(NULL)))
    return FALSE;

//  try 
//  {
    //Rotinas_TESTEHR( pADOConexao.CreateInstance("ADODB.Connection") );

    Rotinas_TESTEHR( CoCreateInstance(CLSID_CADOConnection, NULL, 
      CLSCTX_INPROC_SERVER, IID_IADOConnection, (LPVOID *)&pADOConexao) );

    //pADOConexao->Open(sStrConexao, "", "", adConnectUnspecified);
    hr = pADOConexao->Open((BSTR) sStrConexao, (BSTR) "", (BSTR) "", adConnectUnspecified);
    if FAILED(hr) {
      wsprintf(sTemp, "Erro: %d", hr);
      AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
      return FALSE;
    }
//  }
//  catch (_com_error &e)
//  {
    //MessageBox(0, (LPTSTR) (_bstr_t) e.Description(), "Erro", MB_ICONERROR | MB_OK);
    //return FALSE;
  //} 
  return TRUE;
}

VOID Rotinas_DisconectaBanco()
{
  pADOConexao->Close();
  ::CoUninitialize();
}

BOOL Rotinas_ConsultaDados(ADOConnection *pConexao, LPTSTR sSql)
{
//  LPTSTR sTemp;
//  _RecordsetPtr pRS;
  HRESULT		hr;
  ADORecordset *pRS;
  COleVariant vtNull;
  LONG nTotal;

//  try 
//  {    
    //Rotinas_TESTEHR( pRS.CreateInstance("ADODB.Recordset") );

    Rotinas_TESTEHR( CoCreateInstance(CLSID_CADORecordset, NULL, 
      CLSCTX_INPROC_SERVER, IID_IADORecordset, (LPVOID *)&pRS) );

    hr = pRS->put_Source((BSTR) sSql);
    hr = pRS->putref_ActiveConnection(pConexao);
    hr = pRS->Open(vtNull, vtNull, adOpenStatic, adLockReadOnly, adCmdText);
    hr = pRS->get_RecordCount(&nTotal);

    if (nTotal > 0) {
      pRS->Close();
      return TRUE;
    } else {
      pRS->Close();
      return FALSE;
    }        
//  }
//  catch (_com_error &e)
//  {
    //sTemp = Rotinas_alocaString(TAM_MAX_STR);
    //wsprintf(sTemp,"%s - %s", Rotinas_lerStr(STR_NCEXECSQL), e.Description());
    //MessageBox(0, (LPTSTR) e.Description(), "Erro", MB_ICONERROR | MB_OK);
    //return FALSE;
  //}   
}

BOOL Rotinas_AtualizaDados(ADOConnection *pConexao, LPTSTR sSql)
{
  //_CommandPtr  pCmnd;
  ADOCommand *pCmnd;

  //_variant_t   pRegsAfetados;
  COleVariant  pRegsAfetados;

//  try 
//  {    
    //Rotinas_TESTEHR( pCmnd.CreateInstance("ADODB.Command") );

    Rotinas_TESTEHR( CoCreateInstance(CLSID_CADOCommand, NULL, 
      CLSCTX_INPROC_SERVER, IID_IADOCommand, (LPVOID *)&pCmnd) );

    //pCmnd->ActiveConnection = pConexao;
    pCmnd->putref_ActiveConnection(pConexao);
    //pCmnd->CommandText = (_bstr_t) sSql;
    pCmnd->put_CommandText((BSTR) sSql);
    pRegsAfetados.vt = VT_I4;
    pCmnd->Execute(&pRegsAfetados,NULL,adCmdText, NULL);
    //pConexao->Execute((BSTR) sSql, NULL, adExecuteNoRecords, NULL);  

    if ( V_I4(&pRegsAfetados) > 0)
      return TRUE;
    else
      return FALSE;
//  }
//  catch (_com_error &e)
//  {
    //sTemp = Rotinas_alocaString(TAM_MAX_STR);
    //wsprintf(sTemp,"%s - %s", Rotinas_lerStr(STR_NCEXECSQL), e.Description());
    //MessageBox(0, (LPTSTR) (_bstr_t) e.Description(), "Erro", MB_ICONERROR | MB_OK);
    //return FALSE;
  //}   
}

BOOL Rotinas_ConsultaDadosLista(ADOConnection *pConexao, LPTSTR sSql)
                                //LISTAMSTR *lstLocal, 
{
//  LPTSTR sTemp;
//  _RecordsetPtr pRS;
  ADORecordset *pRS;
  ADOFields *pCampos;
  ADOField *pCampo;
  LONG nCol, nQtdCol;
  HRESULT		hr;
  COleVariant vtNull;
  LONG nTotal;
  VARIANT_BOOL	vbEOF;

  COleVariant vtItem, vtCol;
//  LPTSTR sValor;

  //try 
  //{    
//    Rotinas_TESTEHR( pRS.CreateInstance("ADODB.Recordset") );
    Rotinas_TESTEHR( CoCreateInstance(CLSID_CADORecordset, NULL, 
      CLSCTX_INPROC_SERVER, IID_IADORecordset, (LPVOID *)&pRS) );

//    pRS->Open(sSql, _variant_t((IDispatch *) pConexao, true), 
//      adOpenStatic, adLockReadOnly, adCmdText);
    hr = pRS->put_Source((BSTR) sSql);
    hr = pRS->putref_ActiveConnection(pConexao);
    hr = pRS->Open(vtNull, vtNull, adOpenStatic, adLockReadOnly, adCmdText);
    hr = pRS->get_RecordCount(&nTotal);

    if (nTotal > 0) {
//    if (pRS->GetRecordCount() > 0) {
      //nQtdCol = pRS->GetFields()->Count;
      hr = pRS->get_Fields(&pCampos);
      pCampos->get_Count(&nQtdCol);

      pRS->get_EOF(&vbEOF);
      //while (!pRS->EndOfFile) {
      while (vbEOF) {
        for (nCol = 0; nCol < nQtdCol; nCol++) {
         // printf("%d: %s\n", nCol+1, 
          //   ((char*) TipoCampo(pRS->GetFields()->Item[nCol]->Type)));

//          printf("%s\n", 
//                (LPTSTR) ((_bstr_t) pRS->GetFields()->GetItem((LONG)nCol)->GetValue())  );          
          vtCol.vt = VT_I4;
          vtCol.operator =(nCol);

          pCampos->get_Item(vtCol, &pCampo);
          pCampo->get_Value(vtItem);
          
          printf("%s\n", (LPTSTR) V_BSTR(&vtItem) );

        }  
        pRS->MoveNext();
      }

      pRS->Close();
      return TRUE;
    } else {
      pRS->Close();
      return FALSE;
    }        
//  }
//  catch (_com_error &e)
//  {
    //sTemp = Rotinas_alocaString(TAM_MAX_STR);
    //wsprintf(sTemp,"%s - %s", Rotinas_lerStr(STR_NCEXECSQL), e.Description());
    //MessageBox(0, (LPTSTR) e.Description(), "Erro", MB_ICONERROR | MB_OK);
   //return FALSE;
  //}   
}

void main(void)
{
  //temp();
  Rotinas_ConectaBanco("FILE NAME=C:\\LivrusVirtus\\Bancos\\access\\Access2k_Livrus.udl");
  //if ( Rotinas_AtualizaDados(pADOConexao, "insert into assunto values(41,'alfa2')") )
    //Rotinas_ConsultaDadosLista(pADOConexao, "select * from assunto");
  Rotinas_DisconectaBanco();
}