DEFINE CLASS CVenderLivros AS CUSTOM
*------------------------------------------------------------------------------------
Procedure btnFechar()
LParameters frmVen

    frmVen.release
EndProc
*------------------------------------------------------------------------------------
Procedure frmLoad()
LParameters frmVen

  frmVen.Height = 311
  frmVen.Width = 482
  nPrecoTotal = 0
  frmVen.edtDtVenda.Value = (dtoc(date()) + " " + time())
EndProc
*------------------------------------------------------------------------------------
Procedure frmMouseMove()
LParameters frmVen

	set message to frmVen.Caption
EndProc
*------------------------------------------------------------------------------------
procedure LimpaDados()
LParameters frmVen

  frmVen.edtDtVenda.Value = (dtoc(date()) + " " + time())
  frmVen.edtCPF.Value=""
  frmVen.edtCliente.Value=""
  frmVen.edtISBN.Value=""
  frmVen.edtLivro.Value=""
  frmVen.lstLivros.Clear
  frmVen.lstCodLivros.Clear
  frmVen.lstPrecos.Clear
  frmVen.lstQtdEstoque.Clear  
  nPrecoTotal = 0
  frmVen.edtPrecoTotal.Value="R$ 0,00"
  frmVen.edtCPF.SetFocus()
endproc
*------------------------------------------------------------------------------------
Function ValidaDados()
LParameters frmVen

If Rotinas.ValidaCampo(frmVen.edtCPF.Value, "CPF não informado!")
    Return .F.
EndIf
if frmVen.lstLivros.ListCount = 0
 MESSAGEBOX("Livro(s) para vender não informado(s)!", 16, _Screen.Caption)
 return .F.
Endif

Return .T.
EndFunc
*------------------------------------------------------------------------------------
function SalvaLista()
LParameters frmVen
local nCont, nQtdEstoque, sArquiva

 for nCont=1 to frmVen.lstLivros.ListCount 
    sArquiva = ConsSQL.Venda("I",alltrim(frmVen.lstLivros.ListItem[nCont]),;
    alltrim(frmVen.edtCPF.Value),(substr(frmVen.edtDtVenda.Value,4,2) + "/" +;
    substr(frmVen.edtDtVenda.Value,1,2) + substr(frmVen.edtDtVenda.Value,6,14)),;
    Rotinas.VirgulaParaPonto(alltrim(str(nPrecoTotal,7,2))),"")   
    Rotinas.AtualizaDados('curArquiva', sArquiva)

    nQtdEstoque = val(alltrim(frmVen.lstQtdEstoque.ListItem[nCont]))
    nQtdEstoque = nQtdEstoque-1
    sArquiva=ConsSQL.Venda("U",alltrim(frmVen.lstLivros.ListItem[nCont]),"","","",;
    alltrim(str(nQtdEstoque)))
    Rotinas.AtualizaDados('curArquiva', sArquiva)
 endfor

return .T.
endfunc
*------------------------------------------------------------------------------------
procedure edtISBNLostFocus()
LParameters frmVen, Consulta

if alltrim(frmVen.edtISBN.Value)<>""   
  if Rotinas.ValidaISBN(alltrim(frmVen.edtISBN.Value))
     sTextoSql = ConsSQL.Livro("Q",alltrim(frmVen.edtISBN.Value),;
                 "","","","","","","","","")  
	  if Rotinas.ConsultaDados(Consulta, sTextoSql) 
            if curCadVenLiv.QtdEstoque > 0
       	      frmVen.edtLivro.Value = alltrim(curCadVenLiv.Titulo)
              sPreco = curCadVenLiv.Preco
            else
	      MESSAGEBOX("O livro não existe no estoque!", 16, _Screen.Caption)
  	    endif	    
	  else
	    MESSAGEBOX("Livro não encontrado!", 16, _Screen.Caption)
	    frmVen.edtISBN.Value = ""
	    frmVen.edtLivro.SetFocus()
	  endif
	  Rotinas.FecharCursor(Consulta)
  else
    frmVen.edtISBN.Value = ""
    MESSAGEBOX("ISBN inválido!", 16, _Screen.Caption)    	  
  endif	  
else
  frmVen.edtLivro.Value = ""
  frmVen.edtISBN.SetFocus()
endif
endproc
*------------------------------------------------------------------------------------
procedure edtCPFLostFocus()
LParameters frmVen, Consulta

if alltrim(frmVen.edtCPF.Value)<>""   
  if Rotinas.ValidaCPF(alltrim(frmVen.edtCPF.Value)) then
     sTextoSql = ConsSQL.Cliente("S",alltrim(frmVen.edtCPF.Value),;
                 "","","","","","","","","")  
	  if Rotinas.ConsultaDados(Consulta, sTextoSql) 
	    frmVen.edtCliente.Value = alltrim(curCadVenCli.Nome)
	  else
	    MESSAGEBOX("Cliente não encontrado!", 16, _Screen.Caption)
	    frmVen.edtCliente.Value = ""
	    frmVen.edtCPF.SetFocus()
	  endif
	  Rotinas.FecharCursor(Consulta)
  else
    frmVen.edtCPF.Value = ""
    MESSAGEBOX("CPF inválido!", 16, _Screen.Caption)    	  
  endif	  
else
  frmVen.edtCliente.Value = ""
  frmVen.edtCPF.SetFocus()
endif
endproc
*------------------------------------------------------------------------------------
procedure btnAdLivrosClick()
LParameters frmVen

local sLivros, bAchou, ncont

if alltrim(frmVen.edtISBN.Value)<>""
 bAchou = .F.
 sLivros=alltrim(frmVen.edtISBN.Value) + " - " + alltrim(frmVen.edtLivro.Value);
  + " - R$ " + str(sPreco,7,2)
 
 for ncont=1 to frmVen.lstLivros.ListCount
   if frmVen.lstLivros.ListItem[ncont]=sLivros
      bAchou = .T.      
      exit for
   endif
 endfor
 if bAchou = .F.
   frmVen.lstCodLivros.AddItem(alltrim(frmVen.edtISBN.Value))
   frmVen.lstPrecos.AddItem(alltrim(str(sPreco,7,2)))
   frmVen.lstQtdEstoque.AddItem(sQtdEstoque)
   frmVen.lstLivros.AddItem(sLivros)
   nPrecoTotal=nPrecoTotal+sPreco
 endif    
 frmVen.edtISBN.Value=""
 frmVen.edtLivro.Value=""
 frmVen.edtPrecoTotal.Value = "R$ " + alltrim(str(nPrecoTotal,7,2))
endif
endproc
*------------------------------------------------------------------------------------
procedure lstLivrosDblClick()
LParameters frmVen
local nPreco, nIndice
 if frmVen.lstLivros.ListCount > 0 
 
   nIndice = frmVen.lstLivros.IndexToItemId(frmVen.lstLivros.ListIndex)
   nPreco=val(frmVen.lstPrecos.ListItem[nIndice])
   nPrecoTotal=nPrecoTotal-nPreco
   frmVen.edtPrecoTotal.Value="R$ " + alltrim(Str(nPrecoTotal,7,2))
   frmVen.lstCodLivros.RemoveItem(frmVen.lstLivros.ListIndex)
   frmVen.lstQtdEstoque.RemoveItem(frmVen.lstLivros.ListIndex)
   frmVen.lstPrecos.RemoveItem(frmVen.lstLivros.ListIndex)      
   frmVen.lstLivros.RemoveItem(frmVen.lstLivros.ListIndex)   
 endif
endproc
*------------------------------------------------------------------------------------
procedure btnVenderClick()
LParameters frmVen

 if this.ValidaDados(frmVen) 
    if this.SalvaLista(frmVen) 
       MESSAGEBOX("Venda realizada com sucesso!", 64, _Screen.Caption)
       this.LimpaDados(frmVen)
    endif
 endif
endproc

ENDDEFINE
