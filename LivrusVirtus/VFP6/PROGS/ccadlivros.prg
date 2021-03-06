DEFINE CLASS CCadLivros AS Cadastros
*------------------------------------------------------------------------------------
function ValidaDados()
LParameters frmCad, bTodosDados

if Rotinas.ValidaCampo(frmCad.edtCodigo.Value, "ISBN n�o informado!")
  return .F.
Endif
if bTodosDados
  if Rotinas.ValidaCampo(frmCad.edtDescricao.Value, "T�tulo n�o informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtEditora.Value, "Editora n�o informada!")
	 return .F.
  Endif
  if lstAssuntos.Items.Count = 0
     MESSAGEBOX("Assunto(s) n�o informado(s)!", 16, _Screen.Caption)
	 return .F.
  Endif
  if lstAutores.Items.Count = 0
     MESSAGEBOX("Autore(s) n�o informado(s)!", 16, _Screen.Caption)
	 return .F.
  Endif
Endif
EndFunc
*------------------------------------------------------------------------------------
Procedure InformaLimpaDados()
LParameters frmCad, bInformar

If bInformar
   frmCad.edtCodigo.Value = alltrim(curCadLivros.ISBN)
   frmCad.edtDescricao.Value = alltrim(curCadLivros.Titulo)
   frmCad.edtEdicao.Value = curCadLivros.Edicao
   frmCad.edtAnoPubli.Value = curCadLivros.AnoPublicacao
   frmCad.edtVolume.Value = curCadLivros.Volume
   frmCad.edtCodEditora.Value = alltrim(Str(curCadLivros.CodEditora))
   frmCad.edtEditora.Value = alltrim(curCadLivros.Editora)
   this.RecuperaIdioma(frmCad, alltrim(Str(curCadLivros.CodIdioma)))   
   frmCad.edtNPaginas.Value = curCadLivros.NumPaginas
   frmCad.edtPreco.Value = alltrim(Str(curCadLivros.Preco))
   frmCad.edtQtdEstoque.Value = curCadLivros.QtdEstoque
   this.AdicionaValoresLista("A", 'curConsLista',;
   ConsSQL.LivroAss("S", alltrim(frmCad.edtCodigo.Value),""),;
   frmCad.lstAssuntos,frmCad.lstCodAssuntos)
   this.AdicionaValoresLista("B", 'curConsLista',;
   ConsSQL.LivroAut("S", alltrim(frmCad.edtCodigo.Value),""),;
   frmCad.lstAutores,frmCad.lstCodAutores)
Else
   frmCad.edtEdicao.Value = 1
   frmCad.edtAnoPubli.Value = Year(Date())
   frmCad.edtVolume.Value = 1
   frmCad.edtCodEditora.Value = ""
   frmCad.edtEditora.Value = ""
   frmCad.edtNPaginas.Value = 1
   frmCad.edtPreco.Value = "0.00"
   frmCad.edtQtdEstoque.Value = 0
   frmCad.edtCodAssunto.Value = ""
   frmCad.lstCodAssuntos.Clear
   frmCad.lstAssuntos.Clear
   frmCad.edtCodAutor.Value = ""
   frmCad.lstCodAutores.Clear
   frmCad.lstAutores.Clear
EndIf
EndProc
*------------------------------------------------------------------------------------
Procedure HabilitaDados()
LParameters frmCad, bHabilita

    fCadastros.HabilitaDados(frmCad, bHabilita)
    frmCad.edtEdicao.Enabled = bHabilita
    frmCad.edtAnoPubli.Enabled = bHabilita
    frmCad.edtVolume.Enabled = bHabilita
    frmCad.edtCodEditora.Enabled = bHabilita
    frmCad.btnPEditora.Enabled = bHabilita
    frmCad.cmbIdioma.Enabled = bHabilita
    frmCad.edtNPaginas.Enabled = bHabilita
    frmCad.edtPreco.Enabled = bHabilita
    frmCad.edtQtdEstoque.Enabled = bHabilita
    frmCad.edtCodAssunto.Enabled = bHabilita
    frmCad.btnPAssunto.Enabled = bHabilita
    frmCad.btnAdAssuntos.Enabled = bHabilita
    frmCad.lstAssuntos.Enabled = bHabilita
    frmCad.edtCodAutor.Enabled = bHabilita
    frmCad.btnPAutor.Enabled = bHabilita
    frmCad.btnAdAutores.Enabled = bHabilita
    frmCad.lstAutores.Enabled = bHabilita
EndProc
*------------------------------------------------------------------------------------
Procedure frmLoad()
LParameters frmCad

    frmCad.Height = 375
    frmCad.Width = 506 
    
 frmCad.edtAnoPubli.Value = Year(Date())
 this.AdicionaCombo(frmCad)
 frmCad.cmbIdioma.ListIndex = 1
      
EndProc
*------------------------------------------------------------------------------------
Procedure btnLimpar()
LParameters frmCad

 fCadastros.btnLimpar(frmCad)
 this.InformaLimpaDados(frmCad, .F.)
 this.HabilitaDados(frmCad, .F.)
EndProc
*------------------------------------------------------------------------------------
Procedure btnNovo()
LParameters frmCad

    fCadastros.btnNovo(frmCad)
	this.InformaLimpaDados(frmCad, .F.)
	this.HabilitaDados(frmCad, .T.)
EndProc
*------------------------------------------------------------------------------------
procedure edtCodigoLostFocus()
LParameters frmCad

 if alltrim(frmCad.edtCodigo.Value)<>""
   if Rotinas.ValidaISBN(alltrim(frmCad.edtCodigo.Value)) = .F.
      MESSAGEBOX("ISBN inv�lido!", 16, _Screen.Caption)
      frmCad.edtCodigo.Value = ""
      frmCad.edtCodigo.SetFocus()
   endif
 endif
endproc
*------------------------------------------------------------------------------------
procedure edtPrecoLostFocus()
LParameters frmCad 

if Rotinas.ValidaFloat(alltrim(frmCad.edtPreco.Value))
  frmCad.edtPreco.Value = alltrim(frmCad.edtPreco.Value)
else
  frmCad.edtPreco.Value = "0,00"
endif
endproc
*------------------------------------------------------------------------------------
procedure edtCodEditoraLostFocus()
LParameters frmCad, Consulta

if alltrim(frmCad.edtCodEditora.Value)<>""   
  If Rotinas.ValidaInteger(alltrim(frmCad.edtCodEditora.Value)) = .T.
    sTextoSql = ConsSQL.Editora("S",alltrim(frmCad.edtCodEditora.Value),"")
    sMensagemErro = "Editora n�o encontrada!"
    
    if Rotinas.ConsultaDados(Consulta, sTextoSql) 
      frmCad.edtEditora.Value = alltrim(curCadLivCodEditora.Editora)
    else
      MESSAGEBOX(sMensagemErro, 16, _Screen.Caption)
      frmCad.edtEditora.Value = ""
      frmCad.edtCodEditora.SetFocus()
    endif
    Rotinas.FecharCursor(Consulta)
  else
    frmCad.edtEditora.Value = ""
    frmCad.edtCodEditora.SetFocus()
  endif
else
  frmCad.edtEditora.Value = ""
  frmCad.edtCodEditora.SetFocus()
endif

endproc
*------------------------------------------------------------------------------------
procedure edtCodAssuntoLostFocus()
LParameters frmCad, Consulta

if alltrim(frmCad.edtCodAssunto.Value)<>""   
  If Rotinas.ValidaInteger(alltrim(frmCad.edtCodAssunto.Value)) = .T.
    sTextoSql = ConsSQL.Assunto("S",alltrim(frmCad.edtCodAssunto.Value),"")
    sMensagemErro = "Assunto n�o encontrado!"
    
    if Rotinas.ConsultaDados(Consulta, sTextoSql) 
      frmCad.edtAssunto.Value = alltrim(curCadLivCodAssunto.Assunto)
    else
      MESSAGEBOX(sMensagemErro, 16, _Screen.Caption)
      frmCad.edtAssunto.Value = ""
      frmCad.edtCodAssunto.SetFocus()
    endif
    Rotinas.FecharCursor(Consulta)
  else
    frmCad.edtAssunto.Value = ""
    frmCad.edtCodAssunto.SetFocus()
  endif
else
  frmCad.edtAssunto.Value = ""
  frmCad.edtCodAssunto.SetFocus()
endif

endproc
*------------------------------------------------------------------------------------
procedure edtCodAutorLostFocus()
LParameters frmCad, Consulta

if alltrim(frmCad.edtCodAutor.Value)<>""   
  If Rotinas.ValidaInteger(alltrim(frmCad.edtCodAutor.Value)) = .T.
    sTextoSql = ConsSQL.Autor("S",alltrim(frmCad.edtCodAutor.Value),"")
    sMensagemErro = "Autor n�o encontrado!"
    
    if Rotinas.ConsultaDados(Consulta, sTextoSql) 
      frmCad.edtAutor.Value = alltrim(curCadLivCodAutor.Autor)
    else
      MESSAGEBOX(sMensagemErro, 16, _Screen.Caption)
      frmCad.edtAutor.Value = ""
      frmCad.edtCodAutor.SetFocus()
    endif
    Rotinas.FecharCursor(Consulta)
  else
    frmCad.edtAutor.Value = ""
    frmCad.edtCodAutor.SetFocus()
  endif
else
  frmCad.edtAutor.Value = ""
  frmCad.edtCodAutor.SetFocus()
endif

endproc
*------------------------------------------------------------------------------------
procedure RecuperaIdioma()
LParameters frmCad, sIdioma
local nCont

 for nCont=1 to frmCad.cmbIdioma.ListCount
    if alltrim(frmCad.cmbCodIdioma.ListItem[nCont])=sIdioma
       frmCad.cmbCodIdioma.ListIndex=nCont
       frmCad.cmbIdioma.ListIndex=nCont
       exit for
    Endif 
 Endfor
EndProc
*------------------------------------------------------------------------------------ 
procedure AdicionaCombo()
LParameters frmCad 
  
  frmCad.cmbCodIdioma.Clear
  frmCad.cmbIdioma.Clear
  Consulta = 'curCadLivIdioma'
  sTextoSql = ConsSQL.Idioma("S","","")
  if Rotinas.ConsultaDados(Consulta, sTextoSql)
     nTotal = RecCount()
	 for nCont=1 to nTotal
	    goto record nCont
   	    frmCad.cmbCodIdioma.AddItem(Str(curCadLivIdioma.Codigo))
	    frmCad.cmbIdioma.AddItem(curCadLivIdioma.Idioma)
	 Endfor
  endif	 
  Rotinas.FecharCursor(Consulta)
endproc
*------------------------------------------------------------------------------------ 
procedure AdicionaValoresLista()
LParameters sOpcao, ConsLista, sTextoSql, lstLista, lstCodLista
  
  lstCodLista.Clear
  lstLista.Clear
  if Rotinas.ConsultaDados(ConsLista, sTextoSql)
     nTotal = RecCount()
	 for nCont=1 to nTotal
	    goto record nCont
        if sOpcao="A" 
           lstCodLista.AddItem(alltrim(Str(curConsLista.codassunto)))
           lstLista.AddItem(alltrim(Str(curConsLista.codassunto))+" - "+;
           alltrim(curConsLista.Assunto))
        else 
           lstCodLista.AddItem(alltrim(Str(curConsLista.codautor)))
           lstLista.AddItem(alltrim(Str(curConsLista.codautor))+" - "+;
           alltrim(curConsLista.Autor))	          
        endif
	 Endfor
  endif	 
  Rotinas.FecharCursor(ConsLista)
endproc
*------------------------------------------------------------------------------
procedure SalvaLista()
LParameters frmCad, sOpcao
local nCont, nTotal, sArquiva, sItem

if sOpcao="A"
 sArquiva = ConsSQL.LivroAss("D",alltrim(frmCad.edtCodigo.Value),"")
 Rotinas.AtualizaDados('curDLivroAss', sArquiva)
 nCont = 1
 nTotal = 1
 do while .T.
   sItem = frmCad.lstCodAssuntos.ListItem[nCont]
   if alltrim(sItem)<>""
     sArquiva = ConsSQL.LivroAss("I",alltrim(frmCad.edtCodigo.Value),;
     alltrim(sItem))
     Rotinas.AtualizaDados('curILivroAss', sArquiva)
     if nTotal = frmCad.lstCodAssuntos.ListCount
       exit do
     else
       nTotal = nTotal + 1    
     endif
   endif   
   nCont = nCont + 1
 enddo
endif

if sOpcao="B"
 sArquiva = ConsSQL.LivroAut("D",alltrim(frmCad.edtCodigo.Value),"")
 Rotinas.AtualizaDados('curDLivroAut', sArquiva)
 nCont = 1 
 nTotal = 1
 do while .T.
   sItem = frmCad.lstCodAutores.ListItem[nCont]
   if alltrim(sItem)<>""
     sArquiva = ConsSQL.LivroAut("I",alltrim(frmCad.edtCodigo.Value),;
     alltrim(frmCad.lstCodAutores.ListItem[nCont]))
     Rotinas.AtualizaDados('curILivroAut', sArquiva)
     if nTotal = frmCad.lstCodAutores.ListCount
       exit do
     else
       nTotal = nTotal + 1    
     endif
   endif  
   nCont = nCont + 1        
 enddo
endif

endproc
*------------------------------------------------------------------------------
ENDDEFINE