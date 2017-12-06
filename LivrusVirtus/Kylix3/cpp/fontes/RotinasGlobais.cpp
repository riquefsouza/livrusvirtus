//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
TRotinasGlobais *Rotinas;
//---------------------------------------------------------------------------
__fastcall TRotinasGlobais::TRotinasGlobais()
        : TObject()
{
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ValidaInteger(AnsiString sNum)
{
 if (sNum!="") {
    try {
      StrToInt(sNum);
      return true;
    } catch (Exception &exception) {
      MessageDlg("Número inválido!", mtError, TMsgDlgButtons() << mbOk, 0);
      return false;
    }
 } else
   return false;
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ValidaFloat(AnsiString sNum)
{
 if (sNum!="") {
    try {
      StrToFloat(sNum);
      return true;
    } catch (Exception &exception) {
      MessageDlg("Número inválido!", mtError, TMsgDlgButtons() << mbOk, 0);
      return false;
    }
 } else
   return false;
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ValidaDateTime(AnsiString sNum)
{
 if (sNum!="") {
    try {
      StrToDateTime(sNum);
      return true;
    } catch (Exception &exception) {
      MessageDlg("Data/Hora inválido!", mtError, TMsgDlgButtons() << mbOk, 0);
      return false;
    }
 } else
   return false;
}
//---------------------------------------------------------------------------
AnsiString TRotinasGlobais::VirgulaParaPonto(AnsiString sNum)
{
 return StringReplace(sNum,",",".",TReplaceFlags() << rfReplaceAll);
}
//---------------------------------------------------------------------------
int TRotinasGlobais::modulo11(AnsiString svalor, int ndig)
{
int ncont, nsoma, nvalor, npos;
AnsiString slocal, sres;

 ncont=1;
 while (ncont <= 11) {
   slocal=svalor.SubString(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=3;
 else
   ncont=2;
 npos=2;
 while (ncont <= 11) {
   sres = slocal.SubString(ncont,1);
   nvalor = StrToInt(sres);
   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   return 0;
 else
   return nsoma;
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ValidaCPF(AnsiString cpf)
{
AnsiString scpf;

if (cpf.Length()==14) {
  scpf=cpf.SubString(1,3)+cpf.SubString(5,3)+cpf.SubString(9,3)+
        cpf.SubString(13,2);
  if ( (modulo11(scpf,1)==StrToInt(cpf.SubString(13,1))) &&
  (modulo11(scpf,2)==StrToInt(cpf.SubString(14,1))) )
    return true;
  else
    return false;
} else
  return false;
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ValidaISBN(AnsiString isbn)
{
AnsiString sisbn, sdigito, snum;
int nvalor, nsoma, ncont;

if (isbn.Length()==13) {
  sdigito = isbn.SubString(isbn.Length(), 1);
  sisbn="";
  for(ncont = 1; ncont <= isbn.Length()-1; ncont++)  {
    if (isbn.SubString(ncont,1)!="-")
      sisbn = sisbn + isbn.SubString(ncont,1);
  }
  if (sdigito=="X")
    nsoma = 10;
  else {
    nvalor = StrToInt(sdigito);
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.SubString(ncont, 1);
    nvalor = StrToInt(snum);
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    return true;
  else
    return false;
} else
  return false;
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ConsultaDados(TSQLQuery *Consulta, AnsiString sTextoSql)
{
  Consulta->Close();
  Consulta->SQL->Text=sTextoSql;
  Consulta->Open();
  return !(Consulta->IsEmpty());
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ConsultaDados(TSQLQuery *Consulta,
                               TClientDataSet *CDSConsulta,AnsiString sTextoSql)
{
  CDSConsulta->Close();
  Consulta->Close();
  Consulta->SQL->Text=sTextoSql;
  Consulta->Open();
  CDSConsulta->Open();
  return !(CDSConsulta->IsEmpty());
}
//---------------------------------------------------------------------------
Boolean TRotinasGlobais::ValidaCampo(AnsiString sCampo,AnsiString sMensagemErro)
{
  if (sCampo=="") {
    MessageDlg(sMensagemErro, mtInformation, TMsgDlgButtons() << mbOk, 0);
    return true;
  } else
    return false;
}
//---------------------------------------------------------------------------
AnsiString TRotinasGlobais::ConsultaCampoDesc(TSQLQuery *Consulta,
           AnsiString sTextoSql, AnsiString sMensagemErro)
{
  if (ConsultaDados(Consulta, sTextoSql)) 
     return Consulta->Fields->Fields[1]->AsString;
  else {
    MessageDlg(sMensagemErro, mtError, TMsgDlgButtons() << mbOk, 0);
    return "";
  }
}
//---------------------------------------------------------------------------
AnsiString TRotinasGlobais::ConsultaCampoDesc(TSQLQuery *Consulta,
          AnsiString sCampoCodigo,AnsiString sTextoSql,AnsiString sMensagemErro)
{
if (Rotinas->ValidaInteger(sCampoCodigo))
  return ConsultaCampoDesc(Consulta, sTextoSql, sMensagemErro);
else
  return "";
}
//---------------------------------------------------------------------------
void TRotinasGlobais::AdicionaItemLista(TListBox *lstLista,
     TStringList *slCodLista, TEdit *sCampoCodigo, TEdit *sCampoDesc)
{
AnsiString sItems;

if (sCampoDesc->Text!="") {
 sItems=sCampoCodigo->Text+" - "+sCampoDesc->Text;
 if (lstLista->Items->IndexOf(sItems)==-1) {
    slCodLista->Append(sCampoCodigo->Text.c_bstr());
    lstLista->Items->Append(sItems);
 }
 sCampoCodigo->Clear();
 sCampoDesc->Clear();
}
}
//---------------------------------------------------------------------------
void TRotinasGlobais::RemoveItemLista(TListBox *lstLista,
                                      TStringList *slCodLista)
{
 if (lstLista->Items->Count > 0) {
   slCodLista->Delete(lstLista->ItemIndex);
   lstLista->Items->Delete(lstLista->ItemIndex);
 }
}
//---------------------------------------------------------------------------
void TRotinasGlobais::AdicionaValoresLista(TSQLQuery *ConsLista,
     AnsiString sTextoSql,TListBox *lstLista, TStringList *slCodLista)
{
 ConsLista->Close();
 lstLista->Clear();
 slCodLista->Clear();
 ConsLista->SQL->Text=sTextoSql;
 ConsLista->Open();
 while (!ConsLista->Eof) {
  slCodLista->Append(ConsLista->Fields->Fields[0]->AsString);
  lstLista->Items->Append(ConsLista->Fields->Fields[0]->AsString+" - "+
  ConsLista->Fields->Fields[1]->AsString);
  ConsLista->Next();
 }
}
//---------------------------------------------------------------------------
void TRotinasGlobais::ChamarTela(TForm *Tela)
{
  Tela->BorderStyle=fbsSingle;
  Tela->FormStyle=fsMDIChild;
  Tela->Position=poDefault;
  Tela->Show();
}
//---------------------------------------------------------------------------
