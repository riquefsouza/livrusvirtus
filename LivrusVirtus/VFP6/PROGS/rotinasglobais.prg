DEFINE CLASS RotinasGlobais AS CUSTOM
*------------------------------------------------------------------------------------
PROCEDURE DesabilitaOpDesenv(bDesabilita)

IF bDesabilita=.T. THEN

PUSH MENU _MSYSMENU  && Armazena o menu ativo.

DEACTIVATE WINDOW ;
	"project manager",;
	"properties",;
	"standard",;
	"dbibar",;
	"layout",;
	"form controls",;
	"report controls",;
	"command",;
	"document view"

RELEASE WINDOWS;
	"form designer",;
	"menu designer",;
	"report designer",;
	"database designer",;
	"view designer",;
	"query designer",;
	"color palette"

ELSE

IF WEXIST("project manager")
	ACTIVATE WINDOW "project manager"
ENDIF
IF WEXIST("properties")
	ACTIVATE WINDOW "properties"
ENDIF
IF WEXIST("standard")
	ACTIVATE WINDOW "standard"
ENDIF
IF WEXIST("dbibar")
	ACTIVATE WINDOW "dbibar"
ENDIF
IF WEXIST("layout")
	ACTIVATE WINDOW "layout"
ENDIF
IF WEXIST("form controls")
	ACTIVATE WINDOW "form controls"
ENDIF
IF WEXIST("report controls")
	ACTIVATE WINDOW "report controls"
ENDIF
IF WEXIST("command")
	ACTIVATE WINDOW "command"
ENDIF
IF WEXIST("document view")
	ACTIVATE WINDOW "document view"
ENDIF

POP MENU _MSYSMENU

ENDIF

ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE FechaTodasJanelas()

X = WONTOP()
DO WHILE NOT EMPTY(X)
	RELEASE WINDOWS &X
	X = WONTOP()
ENDDO

ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE SalvaConfiguracoes(bSalva)

IF bSalva=.T. then

pWState    = _SCREEN.WindowState
pBackColor = _Screen.BackColor
pTitulo    = _SCREEN.Caption
pTalk      = SET("Talk")
pPath      = SET("Path")
pDate      = SET("Date")
pDel       = SET("Deleted")
pCurrency  = SET("Currency",1)
pPoint     = SET("Point")
pSeparator = SET("Separator")
pExclusive = SET("Exclusive")
pReprocess = SET("Reprocess")
pRefresh   = SET("Refresh")
pError     = ON ("Error")

ELSE

_SCREEN.WindowState = pWState
_Screen.BackColor = pBackcolor
_SCREEN.Caption = pTitulo
SET TALK &pTalk
SET PATH TO &pPath
SET DELETED &pDel
SET DATE TO &pDate
SET CURRENCY TO pCurrency
SET POINT TO pPoint
SET SEPARATOR TO pSeparator
SET EXCLUSIVE &pExclusive
SET REPROCESS TO pReprocess
SET REFRESH TO pRefresh
ON  ERROR &pError
SET SYSMENU TO DEFAULT

ENDIF

ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE ConfiguraSets()

SET TALK OFF			&& Elimina a resposta dos comandos para o Vídeo
SET NOTIFY OFF
SET CONSOLE OFF
SET DATE TO DMY			&& Formato de Data para Dia/Mes/Ano
SET POINT TO ','		&& Separador Decimal
SET SEPARATOR TO '.'	&& Separador do Milhar
SET EXCLUSIVE OFF		&& Permite o compartilhamento dos arquivos de dados
SET REPROCESS TO 1 		&& Quantas tentativas para bloquear um registro
SET REFRESH TO 5		&& Tempo de atualização dos dados no Browse
SET DELETED ON			&& Não apresenta os registros marcados para exclusão
SET CENTURY ON			&& Mostra o ano com 4 dígitos
SET CENTURY TO 19 ROLLOVER 10	&& maior que 10 é entendido como 19xx. De 0 a 10 como 20xx
SET CURRENCY TO 'R$'	&& Símbolo monetário
SET SAFETY OFF			&& Não avisa para sobreescrever um arquivo
SET EXACT ON

ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE ErroSistema()
LPARAMETERS m.mensagem, m.programa, m.numero

*Comandos que podem ser usados:

* Retry	 - Retorna a execução do programa para a mesma linha
*		de onde ocorreu o erro.
* Return   - Retorna a execução do programa para a linha
*		seguinte de onde ocorreu o erro.
IF m.numero = 108 OR  m.numero = 109
	MESSAGEBOX("Registro sendo utilizado por outro usuário.",;
		64,"Gerenciador de Tarefas")
	RETURN .F.
ENDIF
= MESSAGEBOX("Erro no sistema: "+CHR(13)+CHR(13)+;
	m.mensagem+CHR(13)+;
	"Programa: "+m.programa+CHR(13)+;
	"Número: "+STR(m.numero),48,;
	"Gerenciador de Erros...")

CLEAR EVENTS		&& Limpa o Read Events do programa Inicio
ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE CarregaTela()
LPARAMETERS cNomeClasse, cLib

LOCAL lfrm

   IF NOT EMPTY(cNomeClasse)
      lfrm = NEWOBJECT(cNomeClasse, cLib)
      IF VARTYPE(lfrm) = "O"   
         lfrm.AutoCenter=.T.
         lfrm.Show(1)
      ENDIF
   ENDIF
   
ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE ChamaTela()
PARAMETERS oForm
*
* Verifica se o formulário já está sendo executado
*
IF TYPE(oForm) = "O" AND !ISNULL(&oForm)	&& Se estiver sendo executado... ativa
	cSHOW = oForm + ".SHOW"
	&cSHOW		
ELSE					&& Caso não tenha sido executado... executa
	RELEASE &oForm
	PUBLIC &oForm

	DO FORM &oForm
ENDIF
ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE SairSistema()
	IF MESSAGEBOX("Deseja sair do sistema?", 36,"Confirmação") = 6
		CLEAR EVENTS	
	ENDIF
ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE ConectaBanco()
	store sqlconnect('aclivrus','') to dbConexao
	
	IF dbConexao <= 0
	   MESSAGEBOX('Impossível conectar', 16, _Screen.Caption)
	EndIf	
ENDPROC
*------------------------------------------------------------------------------------
PROCEDURE DisconectaBanco()
	sqldisconnect(dbConexao)
ENDPROC
*------------------------------------------------------------------------------------
FUNCTION ConsultaDados()
LParameters sCursor, sTextoSql
  
nExec = sqlexec(dbConexao, sTextoSql, sCursor)

If reccount() > 0
	RETURN .T.
else
	RETURN .F.
endif
ENDFUNC
*------------------------------------------------------------------------------------
PROCEDURE AtualizaDados()
LPARAMETERS sCursor, sTextoSql

nExec = sqlexec(dbConexao, sTextoSql, sCursor)

ENDPROC
*------------------------------------------------------------------------------------
FUNCTION ConsultaDadosX()
LPARAMETERS sCursor, sTextoSql, gridConsulta

nExec = sqlexec(dbConexao, sTextoSql, sCursor)

gridConsulta.RecordSourceType = 1 && 1-Alias, 2-Prompt, 4-SQL
gridConsulta.RecordSource=sCursor

If reccount() > 0
	RETURN .T.
else
	RETURN .F.
endif
ENDFUNC
*------------------------------------------------------------------------------------
Function ValidaCampo()
LParameters sCampo, sMensagemErro

If sCampo = ""
   MESSAGEBOX(sMensagemErro, 16, _Screen.Caption)
   Return .T.
EndIf
Return .F.

EndFunc
*------------------------------------------------------------------------------------
Function ValidaInteger()
LParameters sNum

If sNum <> ""
      If IsDigit(sNum) 
         Return .T.
      Else
         MESSAGEBOX("Número inválido!", 16, _Screen.Caption)
         Return .F.
      EndIf
Else
   Return .F.
EndIf
EndFunc
*------------------------------------------------------------------------------------
Function ValidaFloat()
LParameters sNum

return this.ValidaInteger(sNum)
EndFunc
*------------------------------------------------------------------------------------
Procedure FecharCursor()
LPARAMETERS sCursor

	if used(sCursor)
	   use
	Endif       
EndProc
*------------------------------------------------------------------------------------
function modulo11()
LParameters svalor, ndig
local nmodulo11, ncont, nsoma, nvalor, npos, sres, slocal

 ncont=1
 slocal=""
 do while ncont <= 11
   slocal=substr(svalor,ncont,1) + slocal
   ncont=ncont+1
 enddo
 nsoma=0
 if ndig=1
   ncont=3
 else
   ncont=2
 endif
 npos=2
 do while ncont <= 11
   sres=substr(slocal,ncont,1)
   nvalor=Val(sres)
   nsoma=nsoma + (nvalor * npos)
   ncont = ncont + 1
   npos = npos + 1
 enddo
 nsoma = (11 - (nsoma % 11))

if nsoma > 9
  nmodulo11 = 0
else
  nmodulo11 = nsoma
endif
return nmodulo11
endfunc
*------------------------------------------------------------------------------
function validaCPF()
LParameters cpf
local scpf, sres, bvalidaCPF
local nstatus, nvalor1, nvalor2

if (len(cpf)=14) 
  scpf = substr(cpf,1,3)+substr(cpf,5,3)+substr(cpf,9,3)+substr(cpf,13,2)
  sres = substr(cpf,13,1)
  nvalor1 = Val(sres)
  sres = substr(cpf,14,1)
  nvalor2 = Val(sres)
  if ((this.modulo11(scpf,1)=nvalor1) .and.; 
      (this.modulo11(scpf,2)=nvalor2))
    bvalidaCPF=.T.
  else
    bvalidaCPF=.F.
  endif
else
  bvalidaCPF=.F.
endif
return bvalidaCPF
endfunc
*------------------------------------------------------------------------------
function validaISBN()
LParameters isbn
local snum, sdigito, sisbn, bvalidaISBN
local nvalor, nsoma, ncont

if (len(isbn)=13) 
  sdigito = substr(isbn, len(isbn), 1)
  sisbn=""
  for ncont=1 to len(isbn)-1
    if (substr(isbn,ncont,1)<>"-") 
      sisbn=sisbn+substr(isbn,ncont,1)
    endif 
  next
  if sdigito = "X"
    nsoma = 10
  else
    nvalor=Val(sdigito)
    nsoma=nvalor
  endif
  for ncont=1 to 9
    snum=substr(sisbn, ncont, 1)
    nvalor=Val(snum)
    nsoma=nsoma + (nvalor * (11 - ncont))
  next
  If (nsoma % 11) = 0
    bvalidaISBN=.T.
  else
    bvalidaISBN=.F.
  endif
else
  bvalidaISBN=.F.
endif
return bvalidaISBN
endfunc
*------------------------------------------------------------------------------
function validaDataHora()
LParameters sDataHora, bSoData
local bvalida, bdatavalida, bhoravalida
local sdia, smes, sano, shora, smin, sseg
local ndia, nmes, nano, nhora, nmin, nseg, nudiames
local nStatus, ntam

bvalida=.F.
bdatavalida=.F.
bhoravalida=.F.
nudiames=0

if bSoData=.T. 
  ntam=10
else 
  ntam=19
endif
if len(sDataHora)=ntam 
  sdia=substr(sDataHora,1,2)
  ndia=Val(sdia)
  smes=substr(sDataHora,4,2)
  nmes=Val(smes)
  sano=substr(sDataHora,7,4)
  nano=Val(sano)

  if (nano >= 1) .and. (nano <= 9999) 
    if (nmes >= 1) .and. (nmes <= 31) 
        do case 
         case nmes = 1 .or. nmes = 3 .or. nmes = 5 .or. nmes = 7 .or.;
              nmes = 8 .or. nmes = 10 .or. nmes = 12
             nudiames=31
         case nmes = 2
             * ano bissexto
             if (nano % 4)=0 
               nudiames=29
             else 
               nudiames=28
             endif
         case nmes = 4 .or. nmes = 6 .or. nmes = 9 .or. nmes = 11 
            nudiames=30
        endcase
        if (ndia >=1) .and. (ndia <=nudiames)
           bdatavalida=.T.
        endif
    endif
  endif

  if bSoData 
     if bdatavalida 
        bvalida=.T.
     else 
        bvalida=.F.
     endif
  else 
    if bdatavalida 
        shora=substr(sDataHora,12,2)
        nhora=Val(shora)
        smin=substr(sDataHora,15,2)
        nmin=Val(smin)
        sseg=substr(sDataHora,18,2)
        nseg=Val(sseg)

        if (nhora >= 0) .and. (nhora <= 23) 
          if (nmin >= 0) .and. (nmin <= 59) 
            if (nseg >= 0) .and. (nseg <= 59)
               bhoravalida=.T.
            endif 
          endif
        endif

        if bhoravalida 
          bvalida=.T.
        else 
          bvalida=.F.
        endif
    else
      bvalida=.F.
    endif
  endif
else 
  bvalida=.F.
endif

return bvalida
endfunc
*------------------------------------------------------------------------------
procedure AdicionaItemLista()
LParameters lstLista, lstCodLista, sCampoCodigo, sCampoDesc
local sItems, ncont, bAchou

if alltrim(sCampoDesc.Value)<>""
 bAchou = .F.
 sItems = alltrim(sCampoCodigo.Value) + " - " + alltrim(sCampoDesc.Value)
 for ncont=1 to lstLista.ListCount
   if lstLista.ListItem[ncont]=sItems
      bAchou = .T.
      exit for
   endif
 endfor
 if bAchou = .F.
   lstCodLista.AddItem(alltrim(sCampoCodigo.Value))
   lstLista.AddItem(alltrim(sItems))
 endif 
 sCampoCodigo.Value = ""
 sCampoDesc.Value = ""
endif
endproc
*------------------------------------------------------------------------------
procedure RemoveItemLista()
LParameters lstLista, slCodLista

 if lstLista.ListCount > 0
   slCodLista.RemoveItem(lstLista.ListIndex)
   lstLista.RemoveItem(lstLista.ListIndex)
 endif
endproc
*------------------------------------------------------------------------------
function VirgulaParaPonto()
LParameters sNum
local ncont, sret
sret = ""
 for ncont=1 to len(sNum)
   if substr(sNum,ncont,1)=","
      sret = sret + "."
   else 
      sret = sret + substr(sNum,ncont,1)
   endif
 endfor

 return sret
endfunc
*------------------------------------------------------------------------------
ENDDEFINE
