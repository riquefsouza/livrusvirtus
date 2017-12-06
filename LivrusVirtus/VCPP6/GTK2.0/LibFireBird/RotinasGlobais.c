#include "resource.h"
#include "RotinasGlobais.h"
#include "Principal.h"

#include <ibase.h>

CONEXAO gConexao;

GString* Rotinas_sBarraLogin;
GString* Rotinas_sUsuarioLogin; 
GString* Rotinas_sUsuarioSenha;
GString* Rotinas_sCodigoSelecionado;
GString* Rotinas_sPreco;
GString* Rotinas_sQtdEstoque;
/* gchar* Rotinas_sepDTHR = "#"; SOMENTE ACCESS */
gchar* Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

void Rotinas_MsgDlg(gchar* sMensagem, GtkMessageType tipo) {
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(frmPrincipal), 
    GTK_DIALOG_DESTROY_WITH_PARENT, tipo, GTK_BUTTONS_OK, 
    "%s", Rotinas_retUTF8(sMensagem));
  gtk_window_set_position (GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);
}

gchar* Rotinas_substr(G_CONST_RETURN gchar* stexto, gint ini, gint tam)
{
GString* str1 = g_string_new("");
GString* slocal = g_string_new("");
gint i,j;
  
g_string_assign(slocal, stexto);
j=0;
ini--;
for(i=ini;i<(ini+tam);i++)
 {
   str1->str[j]=slocal->str[i];
   j++;
 }
str1->str[j]='\0';
g_string_free(slocal, TRUE);
return(str1->str);
}

gboolean Rotinas_ValidaInteger(G_CONST_RETURN gchar* sNum) {
gint nNumero;
gboolean bret = FALSE;

  if (strlen(sNum) > 0) {   
      nNumero = atoi(sNum);
      if (nNumero > 0)
        bret = TRUE;
      else {
        Rotinas_MsgDlg(STR_NUMINV, GTK_MESSAGE_ERROR);
        bret = FALSE;
      }
  } else
     bret = FALSE;

  return bret;
} 

gboolean Rotinas_ValidaFloat(G_CONST_RETURN gchar* sNum) {
gdouble nNumero;
gchar* fimptr[TAM_MAX_STR];
gboolean bret = FALSE;

  if (strlen(sNum) > 0) {   
      nNumero = g_strtod(sNum, fimptr);
      if (nNumero >= 0.01)
        bret = TRUE;
      else {
        Rotinas_MsgDlg(STR_NUMINV, GTK_MESSAGE_ERROR);
        bret = FALSE;
      }
  } else
     bret = FALSE;

  return bret;
} 

gchar* Rotinas_VirgulaParaPonto(G_CONST_RETURN gchar* sNum, 
                                gboolean revertido) {
  gint ncont;
  GString* sret = g_string_new("");
  gchar sponto[2];
  gchar svirgula[2];

  if (revertido) {
    strcpy(sponto, ",");
    strcpy(svirgula, ".");
  } else {
    strcpy(sponto, ".");
    strcpy(svirgula, ",");
  }

  for (ncont=1; ncont <= abs(strlen(sNum)); ncont++) {
    if (g_strcasecmp(Rotinas_substr(sNum, ncont, 1),svirgula)==0)
      g_string_append(sret, sponto);
    else 
      g_string_append(sret, Rotinas_substr(sNum,ncont,1));
  }
  return sret->str;
}

gint Rotinas_modulo11(GString* svalor, gint ndig) {
gint ncont, nsoma, npos;
gint nvalor = 0;
GString* stemp = g_string_new("");
GString* slocal = g_string_new("");
GString* sres = g_string_new("");
gint nret = 0;

 ncont=0;
 while (ncont < 11) {  
   slocal->str=strcat(Rotinas_substr(svalor->str, ncont+1, 1),slocal->str);
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont < 11) {
   sres->str = Rotinas_substr(slocal->str, ncont+1, 1);
   nvalor = atoi(sres->str);
   
   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   nret = 0;
 else
   nret = nsoma;

return nret;
}

gboolean Rotinas_ValidaCPF(G_CONST_RETURN gchar* cpf) {
GString* scpf = g_string_new("");
gint nNum1 = 0;
gint nNum2 = 0;
GString* sNum1; 
GString* sNum2;
gboolean bret = FALSE;

  if (strlen(cpf)==14) {
    g_string_sprintfa(scpf, "%s%s%s%s",
	    Rotinas_substr(cpf,1,3),Rotinas_substr(cpf,5,3),
	    Rotinas_substr(cpf,9,3),Rotinas_substr(cpf,13,2) );

    sNum1 = g_string_new(Rotinas_substr(cpf,13,1));
    nNum1 = atoi(sNum1->str);
    sNum2 = g_string_new(Rotinas_substr(cpf,14,1));
    nNum2 = atoi(sNum2->str);

    if ( (Rotinas_modulo11(scpf,1)==nNum1) 
	    && (Rotinas_modulo11(scpf,2)==nNum2) )
      bret = TRUE;
    else
      bret = FALSE;
  } else
    bret = FALSE;

return bret;
}

gboolean Rotinas_ValidaISBN(G_CONST_RETURN gchar* isbn) {
GString* sisbn = g_string_new("");
GString* sdigito = g_string_new("");
GString* snum = g_string_new("");
gint nsoma, ncont;
gint nvalor = 0;
gboolean bret = FALSE;

  if (strlen(isbn)==13) {
    sdigito->str = Rotinas_substr(isbn, strlen(isbn), 1);

    for(ncont = 0; ncont < abs(strlen(isbn)-1); ncont++)  {
      if (g_strcasecmp(Rotinas_substr(isbn, ncont+1, 1),"-")!=0)
        g_string_append(sisbn, Rotinas_substr(isbn, ncont+1, 1));
    }

    if (g_strcasecmp(sdigito->str,"X")==0)
      nsoma = 10;
    else {
      nvalor = atoi(sdigito->str);
      nsoma = nvalor;
    }
    for(ncont = 1; ncont <= 9; ncont++)  {
      snum->str = Rotinas_substr(sisbn->str, ncont, 1);
      nvalor = atoi(snum->str);
      nsoma=nsoma + (nvalor * (11 - ncont));
    }
    if ((nsoma % 11) == 0)
      bret = TRUE;
    else
      bret = FALSE;
  } else
    bret = FALSE;

 return bret;
}

gboolean Rotinas_validaDataHora(G_CONST_RETURN gchar *sDataHora, 
                                gboolean bSoData) {
  gboolean bvalida, bdatavalida, bhoravalida;
  gchar *sdia, *smes, *sano, *shora, *smin, *sseg;
  gint ndia, nmes, nano, nhora, nmin, nseg, nudiames;
  guint ntam;

bvalida = FALSE;
bdatavalida = FALSE;
bhoravalida = FALSE;
nudiames = 0;
if (bSoData==TRUE) ntam=10;
else ntam=19;

  if (strlen(sDataHora) == ntam) {
    sdia = Rotinas_substr(sDataHora, 1, 2);
    ndia = atoi(sdia);
    smes = Rotinas_substr(sDataHora, 4, 2);
    nmes = atoi(smes);
    sano = Rotinas_substr(sDataHora, 7, 4);
    nano = atoi(sano);
  
    if ((nano >= 1) && (nano <= 9999)) {
      if ((nmes >= 1) && (nmes <= 31)) {
          switch(nmes) {
           case 1: case 3: case 5: case 7: case 8: 
           case 10: case 12: nudiames = 31; break;
           case 2: {
               /* ano bissexto */
               if ((nano % 4)==0) nudiames = 29;
               else nudiames = 28;
              } break;
           case 4: case 6: case 9: case 11: nudiames = 30; break;
          }
          if ((ndia >=1) && (ndia <=nudiames))
             bdatavalida = TRUE;
      }
    }
  
    if (bSoData) {
       if (bdatavalida) 
         bvalida = TRUE;
       else 
		     bvalida = FALSE;
    } else {
      if (bdatavalida) {
          shora = Rotinas_substr(sDataHora, 12, 2);
          nhora = atoi(shora);
          smin = Rotinas_substr(sDataHora, 15, 2);
          nmin = atoi(smin);
          sseg = Rotinas_substr(sDataHora, 18, 2);
          nseg = atoi(sseg);
  
          if ((nhora >= 0) && (nhora <= 23)) {
            if ((nmin >= 0) && (nmin <= 59)) {
              if ((nseg >= 0) && (nseg <= 59))
                 bhoravalida = TRUE;
            }
          }
  
          if (bhoravalida) 
  			    bvalida = TRUE;
          else 
  			    bvalida = FALSE;
      } else
        bvalida = FALSE;
    }
  } else 
     bvalida = FALSE;

return bvalida;
}

gchar* Rotinas_FormataDataHoraStr(struct tm* sTempo, 
  gchar *sFrmtData, gchar *sFrmtHora)
{ gchar *sDataHora = (gchar*) malloc(TAM_MAX_STR);
  GString* sTemp = g_string_new("");

if (strlen(sFrmtData) > 0 && strlen(sFrmtHora) > 0)
  g_string_sprintf(sTemp, "%s %s", sFrmtData, sFrmtHora);
else if (strlen(sFrmtData) > 0)
  g_string_assign(sTemp, sFrmtData);
else if (strlen(sFrmtHora) > 0)
  g_string_assign(sTemp, sFrmtHora);

strftime(sDataHora, TAM_MAX_STR, sTemp->str, sTempo);
return sDataHora;
}

gchar* Rotinas_retDataHoraStr(gboolean bData, gboolean bHora)
{ GString* sDataHora = g_string_new("");
  time_t agora;   
  struct tm* sTempo;

  time(&agora);
  sTempo = localtime(&agora); 

if (bData && bHora)
  g_string_assign(sDataHora, 
    Rotinas_FormataDataHoraStr(sTempo, "%d/%m/%Y", "%H:%M:%S"));
else if (bData)
  g_string_assign(sDataHora, 
    Rotinas_FormataDataHoraStr(sTempo, "%d/%m/%Y", ""));
else if (bHora)
  g_string_assign(sDataHora, 
    Rotinas_FormataDataHoraStr(sTempo, "", "%H:%M:%S"));

return sDataHora->str;
}

gchar* Rotinas_ConverteDataHoraStr(G_CONST_RETURN gchar *sDTHR, 
  gboolean DMY_ou_YMD, gchar *sFrmtData, gchar *sFrmtHora)
{ GString *sDataHora = g_string_new("");
  struct tm sTempo;

if (strlen(sFrmtData) > 0) {
  if (DMY_ou_YMD) {
    sTempo.tm_mday = atoi(Rotinas_substr(sDTHR, 1, 2));
    sTempo.tm_mon = atoi(Rotinas_substr(sDTHR, 4, 2));
    sTempo.tm_year = atoi(Rotinas_substr(sDTHR, 7, 4));
  } else {
    sTempo.tm_year = atoi(Rotinas_substr(sDTHR, 1, 4));
    sTempo.tm_mon = atoi(Rotinas_substr(sDTHR, 6, 2));
    sTempo.tm_mday = atoi(Rotinas_substr(sDTHR, 9, 2));
  }
  sTempo.tm_mon -= 1;
  sTempo.tm_year -= 1900;
}

if (strlen(sFrmtHora) > 0) {
  sTempo.tm_hour = atoi(Rotinas_substr(sDTHR, 12, 2));
  sTempo.tm_min = atoi(Rotinas_substr(sDTHR, 15, 2));
  sTempo.tm_sec = atoi(Rotinas_substr(sDTHR, 18, 2));
}

g_string_assign(sDataHora, 
  Rotinas_FormataDataHoraStr(&sTempo,sFrmtData,sFrmtHora));

return sDataHora->str;
}

G_CONST_RETURN gchar* Rotinas_retTexto(GtkWidget *sEdit) {
  return gtk_entry_get_text(GTK_ENTRY(sEdit));
}

gchar* Rotinas_retLocale(const gchar *sTexto) {
GString *sTemp = g_string_new("");
gsize nBytesLidos, nBytesGravados;
GError *nErroOcorrido;

g_string_assign(sTemp, g_locale_from_utf8(sTexto, TAM_MAX_STR,
        &nBytesLidos, &nBytesGravados, &nErroOcorrido));

if (sTemp->str==NULL)
  g_string_assign(sTemp, sTexto);

return sTemp->str;
}

gchar* Rotinas_retUTF8(const gchar *sTexto) {
GString *sTemp = g_string_new("");
gsize nBytesLidos, nBytesGravados;
GError *nErroOcorrido;

g_string_assign(sTemp, g_locale_to_utf8(sTexto, TAM_MAX_STR,
        &nBytesLidos, &nBytesGravados, &nErroOcorrido));
/*
g_print("nBytesLidos = %d\n", nBytesLidos);
g_print("nBytesGravados = %d\n", nBytesGravados);
switch (nErroOcorrido->code) {
  case G_CONVERT_ERROR_NO_CONVERSION:
    g_print("nErroOcorrido = G_CONVERT_ERROR_NO_CONVERSION\n"); 
    break;
  case G_CONVERT_ERROR_ILLEGAL_SEQUENCE:
    g_print("nErroOcorrido = G_CONVERT_ERROR_ILLEGAL_SEQUENCE\n"); 
    break;
  case G_CONVERT_ERROR_FAILED:
    g_print("nErroOcorrido = G_CONVERT_ERROR_FAILED\n"); 
    break;
  case G_CONVERT_ERROR_PARTIAL_INPUT:
    g_print("nErroOcorrido = G_CONVERT_ERROR_PARTIAL_INPUT\n"); 
    break;
  case G_CONVERT_ERROR_BAD_URI:
    g_print("nErroOcorrido = G_CONVERT_ERROR_BAD_URI\n"); 
    break;
  case G_CONVERT_ERROR_NOT_ABSOLUTE_PATH:
    g_print("nErroOcorrido = G_CONVERT_ERROR_NOT_ABSOLUTE_PATH\n"); 
    break;
  default:
    g_print("nErroOcorrido = %d\n", nErroOcorrido->code); 
}
*/
if (sTemp->str==NULL)
  g_string_assign(sTemp, sTexto);

return sTemp->str;
}

gboolean Rotinas_ConectaBanco(char *sBancoDeDados, char *sLogin, char *sSenha) {
char ISC_FAR *params = NULL;
short nparams = 0;
char ISC_FAR *d, *p, *copia;
long l, sweep_interval = 16384;
long status[20];
GString *sTemp = g_string_new("");
  
  copia = params = (char *) malloc(7);
  p = params;
  *p++ = '\1';
  *p++ = isc_dpb_sweep_interval;
  *p++ = '\4';
  l = isc_vax_integer((char ISC_FAR *) &sweep_interval, 4);
  d = (char *) &l;
  *p++ = *d++;
  *p++ = *d++;
  *p++ = *d++;
  *p = *d;
  nparams = 7;
  isc_expand_dpb(&params, (short ISC_FAR *) &nparams,
                 isc_dpb_user_name, sLogin,
                 isc_dpb_password, sSenha,  NULL);

  if (isc_attach_database(status, 0, sBancoDeDados, &gConexao, nparams, params)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NCONBANCO, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    return FALSE;
  }
  return TRUE;
}

void Rotinas_DisconectaBanco() {
long status[20];
GString *sTemp = g_string_new("");

  if (isc_detach_database(status, &gConexao)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NDCOBANCO, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
  }
}

gboolean Rotinas_AtualizaDados(CONEXAO hBancoLocal, GString *sSql) {
gboolean bret = TRUE;
isc_tr_handle hTransacao = NULL;
long status[20];
GString *sTemp = g_string_new("");
gchar sLocal[TAM_MAX_STR * 4];

  strcpy(sLocal, Rotinas_retLocale(sSql->str));

  if (isc_start_transaction(status, &hTransacao, 1, &hBancoLocal, 0, NULL)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NINITRAN, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  if (isc_dsql_execute_immediate(
          status, &hBancoLocal, &hTransacao, 0, sLocal, 1, NULL)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NCEXECSQL, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  if (isc_commit_transaction(status, &hTransacao)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NFINTRAN, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  return bret;
}

gboolean Rotinas_PreConsultaDados(CONEXAO hBancoLocal, char *sSql, 
  isc_tr_handle *hTransacao, isc_stmt_handle *hstmtLocal, XSQLDA **sqlda) {
gboolean bret = TRUE;
long status[20];
GString *sTemp = g_string_new("");

  if (isc_start_transaction(status, hTransacao, 1, &hBancoLocal, 0, NULL)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NINITRAN, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  if (isc_dsql_allocate_statement(status, &hBancoLocal, hstmtLocal)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NALOCHSTM, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }

  /* Aloca SQLDA com um tamanho m�nimo. */
  (*sqlda) = (XSQLDA *) malloc(XSQLDA_LENGTH(1));
  (*sqlda)->sqln = 1;
  (*sqlda)->version = 1;

  if (isc_dsql_prepare(status, hTransacao, hstmtLocal, 0, 
    sSql, 1, (*sqlda))) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NCPREPSQL, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  return bret;
}

gboolean Rotinas_PosConsultaDados(isc_tr_handle *hTransacao, 
                              isc_stmt_handle *hstmtLocal) {
gboolean bret = TRUE;
long status[20];
GString *sTemp = g_string_new("");

  if (isc_dsql_free_statement(status, hstmtLocal, DSQL_drop)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NLIBTRAN, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  if (isc_commit_transaction(status, hTransacao)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NFINTRAN, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  return bret;
}

gboolean Rotinas_DescreveProcedimento(isc_stmt_handle hstmtLocal, 
  XSQLDA **sqlda, int *nQtdCols, char *sCampo[], float dCampo[], 
  short nsCampo[], long tsCampo[], long nlCampo[], SQLVARCHAR varCampo[]) {
gboolean bret = TRUE;
short flag = 0;
int nCol, nNulo;
long status[20];
GString *sTemp = g_string_new("");

  /* Descreve o procedimento. */
  if (isc_dsql_describe(status, &hstmtLocal, 1, *sqlda)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_DESCPROC, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  
  (*nQtdCols) = (*sqlda)->sqld;

  /* Realoca SQLDA se necess�rio. */
  if ((*sqlda)->sqln < (*sqlda)->sqld)
  {
      (*sqlda) = (XSQLDA *) malloc(XSQLDA_LENGTH((*nQtdCols)));
      (*sqlda)->sqln = (*nQtdCols);
      (*sqlda)->version = 1;
  
      /* Redescreve o procedimento. */
      if (isc_dsql_describe(status, &hstmtLocal, 1, *sqlda)) {
        g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_DESCPROC, 
          isc_sqlcode(status));
        Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
        bret = FALSE;
      }
      (*nQtdCols) = (*sqlda)->sqld;
  }
  for (nCol = 0; nCol < (*nQtdCols); nCol++) {
    /* verifica se � nulo */
    if ((*sqlda)->sqlvar[nCol].sqltype & 1)
      nNulo = 1;    
    else
      nNulo = 0;
    if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_FLOAT + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &dCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_FLOAT + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_SHORT + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &nsCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_SHORT + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_TIMESTAMP + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &tsCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_TIMESTAMP + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_LONG + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &nlCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_LONG + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_VARYING + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &varCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_VARYING + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else {
      (*sqlda)->sqlvar[nCol].sqldata = sCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_TEXT + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    }
  }

  return bret;
}

gboolean Rotinas_ConsultaDados(CONEXAO hBancoLocal, GString *sSql) {
gboolean bret = TRUE;
isc_tr_handle hTransacao = NULL;
isc_stmt_handle hstmtLocal = NULL;
long  status_fetch;
XSQLDA *sqlda;
char *sCampo[QTD_MAX_COL];
float dCampo[QTD_MAX_COL];
short nsCampo[QTD_MAX_COL];
long tsCampo[QTD_MAX_COL];
long nlCampo[QTD_MAX_COL];
SQLVARCHAR varCampo[QTD_MAX_COL];
int nCol, nQtdCols;
long status[20];
GString *sTemp = g_string_new("");

  bret = Rotinas_PreConsultaDados(hBancoLocal, sSql->str, &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = (char*)malloc(TAM_MAX_STR);

  bret = Rotinas_DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NCEXECSQL, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  if (status_fetch == 0) 
    bret = TRUE;
  else
    bret = FALSE;

  Rotinas_PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

gboolean Rotinas_ConsultaDadosLista(CONEXAO hBancoLocal, 
                                    LISTAMSTR *lstLocal, GString *sSql) {
gboolean bret = TRUE;
isc_tr_handle hTransacao = NULL;
isc_stmt_handle hstmtLocal = NULL;
XSQLDA *sqlda;
long  status_fetch;
char *sCampo[QTD_MAX_COL];
float dCampo[QTD_MAX_COL];
short nsCampo[QTD_MAX_COL];
long tsCampo[QTD_MAX_COL];
long nlCampo[QTD_MAX_COL];
SQLVARCHAR varCampo[QTD_MAX_COL];
struct tm mTempo;
int nCol, nQtdCols, nNulo;
long status[20];
GString *sTemp = g_string_new("");
gchar *sLinha[QTD_MAX_COL];
gchar sAux[TAM_MAX_STR];

  bret = Rotinas_PreConsultaDados(hBancoLocal, sSql->str, &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = (char*)malloc(TAM_MAX_STR);

  bret = Rotinas_DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    g_string_sprintf(sTemp, "%s - SQLCODE: %d", STR_NCEXECSQL, 
      isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    lstLocal->col[nCol] = g_array_new(TRUE, TRUE, TAM_MAX_STR);

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  while (status_fetch == 0) {

    for (nCol = 0; nCol < nQtdCols; nCol++) {
      /* verifica se � nulo */
      if (sqlda->sqlvar[nCol].sqltype & 1)
        nNulo = 1;    
      else
        nNulo = 0;
      if (sqlda->sqlvar[nCol].sqltype == (SQL_FLOAT + nNulo)) {
        g_string_sprintf(sTemp, "%.2f", dCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_SHORT + nNulo)) {
        g_string_sprintf(sTemp, "%d", nsCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_LONG + nNulo)) {
        g_string_sprintf(sTemp, "%d", nlCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_TIMESTAMP + nNulo)) {
        isc_decode_timestamp((ISC_TIMESTAMP *)&tsCampo[nCol], &mTempo);                  
        g_string_assign(sTemp, 
          Rotinas_FormataDataHoraStr(&mTempo, "%d/%m/%Y", "%H:%M:%S"));
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_VARYING + nNulo)) {
        varCampo[nCol].vary_string[varCampo[nCol].vary_length] = '\0';
        g_string_assign(sTemp, varCampo[nCol].vary_string);
      } else {
        sCampo[nCol][sqlda->sqlvar[nCol].sqllen] = '\0';
        g_string_assign(sTemp, sCampo[nCol]);
      }
      sLinha[nCol] = (gchar*) malloc(TAM_MAX_STR);
      strcpy(sLinha[nCol], sTemp->str);
      strcpy(sAux, Rotinas_retUTF8(sLinha[nCol]));
      g_array_append_val(lstLocal->col[nCol], sAux);
    }
    status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  }

  if (status_fetch != 100L) {
    g_string_sprintf(sTemp, "SQLCODE: %d", isc_sqlcode(status));
    Rotinas_MsgDlg(sTemp->str, GTK_MESSAGE_ERROR);
    bret = FALSE;
  }
  Rotinas_PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

gchar* Rotinas_retValorListaM(LISTAMSTR *lstLocal, gint nCol, gint nLinha) {
  return &g_array_index(lstLocal->col[nCol], gchar, nLinha * TAM_MAX_STR);
}

gchar* Rotinas_retValorLista(LISTASTR lstLocal, gint nLinha) {
  return &g_array_index(lstLocal.col, gchar, nLinha * TAM_MAX_STR);
}

gboolean Rotinas_ValidaCampo(G_CONST_RETURN gchar *sCampo, 
                             gchar *sMensagemErro)
{
  if (strlen(sCampo)==0) {
    Rotinas_MsgDlg(sMensagemErro, GTK_MESSAGE_ERROR);
	  return TRUE;
  } else
	  return FALSE;
}

gchar* Rotinas_ConsultaCampoDesc(LISTAMSTR *Campos, 
    G_CONST_RETURN gchar *sCampoCodigo, gboolean bValidaInt,
    GString *sTextoSql, gchar *sMensagemErro)
{ 
  if (bValidaInt) {
    if (!Rotinas_ValidaInteger(sCampoCodigo))
      return "";
  }
  if (Rotinas_ConsultaDadosLista(gConexao, Campos, sTextoSql)) {
    return Rotinas_retValorListaM(Campos, 1, 0);
  } else {
    Rotinas_MsgDlg(sMensagemErro, GTK_MESSAGE_ERROR);
    return "";
  }
}

void Rotinas_CriaModeloGrid(GtkTreeView *grid)
{
GtkTreeModel *modeloGrid;
GtkListStore *gListaGrid;

  gListaGrid = gtk_list_store_new((QTD_MAX_COL+1), G_TYPE_INT, G_TYPE_STRING,
	  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
    G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
    G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
  modeloGrid = GTK_TREE_MODEL(gListaGrid);

  gtk_tree_view_set_model(GTK_TREE_VIEW(grid), modeloGrid);
  g_object_unref(modeloGrid);
}

void Rotinas_LimpaModeloGrid(GtkTreeView *grid) {
  GtkListStore *gListaGrid;
  gListaGrid = GTK_LIST_STORE( gtk_tree_view_get_model(grid) );
  gtk_list_store_clear(gListaGrid);
}

void Rotinas_AdicionaLinhasGrid(GtkTreeView *grid, LISTAMSTR *lstLinhas, 
                                gint nQtdCols, gboolean bLimparGrid) {
GtkListStore *gListaGrid;
GtkTreeIter iter;
gint nCol, nLinha, nQtdLinhas;  
gchar sTemp[QTD_MAX_COL][TAM_MAX_STR];

  gListaGrid = GTK_LIST_STORE( gtk_tree_view_get_model(grid) );

  if (bLimparGrid)
    gtk_list_store_clear(gListaGrid);

  nQtdLinhas = lstLinhas->col[0]->len;
  for (nLinha = 0; nLinha < nQtdLinhas; nLinha++) {

    for (nCol = 0; nCol < nQtdCols; nCol++) {
      if (nCol > (nQtdCols-1))
        strcpy(sTemp[nCol], "");
      else
        strcpy(sTemp[nCol], Rotinas_retValorListaM(lstLinhas, nCol, nLinha));
    }

    gtk_list_store_append(gListaGrid, &iter);
    gtk_list_store_set (gListaGrid, &iter, 0, (nLinha+1),
			1, sTemp[0], 2, sTemp[1], 3, sTemp[2], 4, sTemp[3], 5, sTemp[4], 
      6, sTemp[5], 7, sTemp[6], 8, sTemp[7], 9, sTemp[8], 10, sTemp[9], 
			11, sTemp[10], 12, sTemp[11], 13, sTemp[12], 14, sTemp[13], 
			15, sTemp[14], 16, sTemp[15], 17, sTemp[16], 18, sTemp[17], 
			19, sTemp[18], 20, sTemp[19], -1);     

  }
 
}

void Rotinas_AdicionaColunasGrid(GtkTreeView *grid, gint nPosIni, gint nQtdCols, 
  gint nLargura[], GString *sRotulos[]) {
GtkCellRenderer *renderer;
GtkTreeViewColumn *gColuna;
gint nCol;

  renderer = gtk_cell_renderer_text_new ();
  gColuna = gtk_tree_view_column_new_with_attributes("",
		renderer, "Indice", 0, NULL);
  gtk_tree_view_column_set_visible(GTK_TREE_VIEW_COLUMN(gColuna), FALSE);

  for (nCol=nPosIni; nCol < QTD_MAX_COL; nCol++) {
    renderer = gtk_cell_renderer_text_new ();

    if (nCol > (nPosIni+nQtdCols-1)) {
      gColuna = gtk_tree_view_column_new_with_attributes("",
			  renderer, "text", nCol+1, NULL);
      gtk_tree_view_column_set_visible(GTK_TREE_VIEW_COLUMN(gColuna), FALSE);
    } else {
      gColuna = gtk_tree_view_column_new_with_attributes(sRotulos[nCol]->str,
			  renderer, "text", nCol+1, NULL);
      gtk_tree_view_column_set_resizable(GTK_TREE_VIEW_COLUMN(gColuna), TRUE);
      gtk_tree_view_column_set_fixed_width(
        GTK_TREE_VIEW_COLUMN(gColuna), nLargura[nCol]);
      gtk_tree_view_column_set_sort_column_id(
        GTK_TREE_VIEW_COLUMN(gColuna), nCol);      
    }

    gtk_tree_view_append_column (grid, gColuna);
  }
}

gboolean Rotinas_PesquisaContaItemGrid(GtkTreeView *grid, gchar *sItem, 
                                       gint *nQtdLinhas) {
GtkTreeModel *modeloGrid;
GtkTreeIter iter;
gboolean bProximo;
gchar *sSelecionado;
gboolean bret = FALSE;

(*nQtdLinhas) = 0;
modeloGrid = gtk_tree_view_get_model(grid);
if ( gtk_tree_model_get_iter_first(modeloGrid, &iter) ) {
  bProximo = TRUE;
  while( bProximo ) {
    gtk_tree_model_get(modeloGrid, &iter, 1, &sSelecionado, -1);
    if (strcmp(sItem, sSelecionado)==0)
      bret = TRUE;    
    bProximo = gtk_tree_model_iter_next(modeloGrid, &iter);
    (*nQtdLinhas)++;
  }
}
return bret;
}

void Rotinas_AdicionaItemLista(GtkTreeView *lstLista,
     GtkWidget *sCampoCodigo, GtkWidget *sCampoDesc)
{
LISTAMSTR lstLinhas;
gchar sTemp[TAM_MAX_STR];
GString *sItems = g_string_new("");
G_CONST_RETURN gchar *sCodigo; 
G_CONST_RETURN gchar *sDesc;
gint nQtdLinhas = 0;

sCodigo = Rotinas_retTexto(sCampoCodigo);
sDesc = Rotinas_retTexto(sCampoDesc);

if (strlen(sDesc) > 0) {
  g_string_sprintf(sItems, "%s - %s", sCodigo, sDesc);

  if (Rotinas_PesquisaContaItemGrid(lstLista, sItems->str,
      &nQtdLinhas)==FALSE) {
 
    lstLinhas.col[0] = g_array_new(TRUE, TRUE, TAM_MAX_STR);
    strcpy(sTemp, sItems->str);
    g_array_append_val(lstLinhas.col[0], sTemp);

    lstLinhas.col[1] = g_array_new(TRUE, TRUE, TAM_MAX_STR);
    strcpy(sTemp, sCodigo);
    g_array_append_val(lstLinhas.col[1], sTemp);

    Rotinas_AdicionaLinhasGrid(lstLista, &lstLinhas, 2, FALSE);
  }
  gtk_entry_set_text(GTK_ENTRY(sCampoCodigo),""); 
  gtk_entry_set_text(GTK_ENTRY(sCampoDesc),""); 
}

}

void Rotinas_RemoveItemLista(GtkTreeView *lstLista)
{
GtkTreeSelection *selection;
GtkListStore *gListaGrid;
GtkTreeModel *modeloGrid;
GtkTreeIter iter;
gint nQtdLinhas = 0;

 gListaGrid = GTK_LIST_STORE( gtk_tree_view_get_model(lstLista) );
 Rotinas_PesquisaContaItemGrid(lstLista, "", &nQtdLinhas);
 if (nQtdLinhas > 0) {   
   selection = gtk_tree_view_get_selection(lstLista);
   if (gtk_tree_selection_get_selected (selection, &modeloGrid, &iter))
      gtk_list_store_remove(gListaGrid, &iter);
 }
}

void Rotinas_AdicionaValoresLista(GString *sTextoSql, 
    GtkTreeView *lstLista)
{ 
  gchar sTemp[TAM_MAX_STR];
  LISTAMSTR Campos, lstLinhas;
  GString *sItems = g_string_new("");
  GString *sCodigo = g_string_new("");
  GString *sDesc = g_string_new("");
  gint nLinha;

  Rotinas_LimpaModeloGrid(lstLista);
  lstLinhas.col[0] = g_array_new(TRUE, TRUE, TAM_MAX_STR);
  lstLinhas.col[1] = g_array_new(TRUE, TRUE, TAM_MAX_STR);
  if (Rotinas_ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
    for (nLinha = 0; nLinha < abs(Campos.col[0]->len); nLinha++) {      
      g_string_assign(sCodigo, Rotinas_retValorListaM(&Campos, 0, nLinha));
      g_string_assign(sDesc, Rotinas_retValorListaM(&Campos, 1, nLinha));

      strcpy(sTemp, sCodigo->str);
      g_array_append_val(lstLinhas.col[1], sTemp);

      g_string_sprintf(sItems, "%s - %s", sCodigo->str, sDesc->str);
      strcpy(sTemp, sItems->str);
      g_array_append_val(lstLinhas.col[0], sTemp);
	  }      
    Rotinas_AdicionaLinhasGrid(lstLista, &lstLinhas, 2, TRUE);
  }
}

