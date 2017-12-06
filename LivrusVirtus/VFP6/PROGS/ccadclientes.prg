DEFINE CLASS CCadClientes AS Cadastros
*------------------------------------------------------------------------------------
function ValidaDados()
LParameters frmCad, bTodosDados

if Rotinas.ValidaCampo(frmCad.edtCodigo.Value, "CPF não informado!")
  return .F.
Endif
if bTodosDados
  if Rotinas.ValidaCampo(frmCad.edtDescricao.Value, "Nome não informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtEmail.Value, "E-mail não informado!")
	 return .F.
  Endif
  if (frmCad.rdgSexo.Option1.Value = 0 and frmCad.rdgSexo.Option2.Value = 0)
     MESSAGEBOX("Sexo não informado!", 16, _Screen.Caption)
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtTelefone.Value, "Telefone não informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtCodEndereco.Value, "Endereço não informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtCodPais.Value, "País não informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtCodProfissao.Value, "Profissão não informado!")
	 return .F.
  Endif 
Endif
EndFunc
*------------------------------------------------------------------------------------
Procedure InformaLimpaDados()
LParameters frmCad, bInformar

local dDataNasc

If bInformar
   frmCad.edtCodigo.Value = alltrim(curCadClientes.CPF)
   frmCad.edtDescricao.Value = alltrim(curCadClientes.Nome)
   frmCad.edtEmail.Value = alltrim(curCadClientes.Email)
   frmCad.edtIdentidade.Value = alltrim(curCadClientes.Identidade)   
   if alltrim(curCadClientes.Sexo)= 'M'
      frmCad.rdgSexo.Option1.Value = 1
      frmCad.rdgSexo.Option2.Value = 0
   else
      frmCad.rdgSexo.Option1.Value = 0
      frmCad.rdgSexo.Option2.Value = 1
   Endif  	
   frmCad.edtTelefone.Value = alltrim(curCadClientes.Telefone)
   
   dDataNasc = curCadClientes.DtNascimento
   frmCad.edtDtNascimento.Value = alltrim(dtoc(dDataNasc))
   
   frmCad.edtCodEndereco.Value = alltrim(str(curCadClientes.CodEndereco))
   frmCad.edtLogradouro.Value = alltrim(curCadClientes.Logradouro)
   frmCad.edtBairro.Value = alltrim(curCadClientes.Bairro)
   frmCad.edtCEP.Value = alltrim(curCadClientes.CEP)
   frmCad.edtCidade.Value = alltrim(curCadClientes.Cidade)
   frmCad.edtEstado.Value = alltrim(curCadClientes.Estado)
   frmCad.edtCodPais.Value = alltrim(curCadClientes.CodPais)
   frmCad.edtPais.Value = alltrim(curCadClientes.Pais)
   frmCad.edtCodProfissao.Value = alltrim(str(curCadClientes.CodProfissao))
   frmCad.edtProfissao.Value = alltrim(curCadClientes.Profissao)
Else
   frmCad.edtEmail.Value = ""
   frmCad.edtIdentidade.Value = ""
   frmCad.rdgSexo.Option1.Value = 1
   frmCad.rdgSexo.Option2.Value = 0
   frmCad.edtTelefone.Value = ""
   frmCad.edtDtNascimento.Value = dtoc(date())
   frmCad.edtCodEndereco.Value = ""
   frmCad.edtLogradouro.Value = ""
   frmCad.edtBairro.Value = ""
   frmCad.edtCEP.Value = ""
   frmCad.edtCidade.Value = ""
   frmCad.edtEstado.Value = ""
   frmCad.edtCodPais.Value = ""
   frmCad.edtPais.Value = ""
   frmCad.edtCodProfissao.Value = ""
   frmCad.edtProfissao.Value = ""   
EndIf
EndProc
*------------------------------------------------------------------------------------
Procedure HabilitaDados()
LParameters frmCad, bHabilita

   fCadastros.HabilitaDados(frmCad, bHabilita)
   frmCad.edtEmail.Enabled = bHabilita
   frmCad.edtIdentidade.Enabled = bHabilita
   frmCad.rdgSexo.Option1.Enabled = bHabilita
   frmCad.rdgSexo.Option2.Enabled = bHabilita
   frmCad.edtTelefone.Enabled = bHabilita
   frmCad.edtDtNascimento.Enabled = bHabilita
   frmCad.edtCodEndereco.Enabled = bHabilita
   frmCad.btnPEndereco.Enabled = bHabilita
   frmCad.edtCodPais.Enabled = bHabilita
   frmCad.btnPPais.Enabled = bHabilita
   frmCad.edtCodProfissao.Enabled = bHabilita
   frmCad.btnPProfissao.Enabled = bHabilita
EndProc
*------------------------------------------------------------------------------------
Procedure frmLoad()
LParameters frmCad

    frmCad.Height = 442
    frmCad.Width = 522   
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
procedure edtCodPaisLostFocus()
LParameters frmCad, Consulta

if alltrim(frmCad.edtCodPais.Value)<>""   
  sTextoSql = ConsSQL.Pais("S",alltrim(frmCad.edtCodPais.Value),"")
  sMensagemErro = "País não encontrado!"
  
  if Rotinas.ConsultaDados(Consulta, sTextoSql) 
    frmCad.edtPais.Value = alltrim(curCadCliCodPais.Pais)
  else
    MESSAGEBOX(sMensagemErro, 16, _Screen.Caption)
    frmCad.edtPais.Value = ""
    frmCad.edtCodPais.SetFocus()
  endif
  Rotinas.FecharCursor(Consulta)
else
  frmCad.edtPais.Value = ""
  frmCad.edtCodPais.SetFocus()
endif

endproc
*------------------------------------------------------------------------------------
procedure edtDtNascLostFocus()
LParameters frmCad

 if alltrim(frmCad.edtDtNascimento.Value)<>""
   if Rotinas.validaDataHora(alltrim(frmCad.edtDtNascimento.Value),.T.) = .F.
      MESSAGEBOX("Data inválida!", 16, _Screen.Caption)
      frmCad.edtDtNascimento.Value = dtoc(date())
      frmCad.edtDtNascimento.SetFocus()
   endif
 endif
endproc
*------------------------------------------------------------------------------------
procedure edtCodigoLostFocus()
LParameters frmCad

 if alltrim(frmCad.edtCodigo.Value)<>""
   if Rotinas.ValidaCPF(alltrim(frmCad.edtCodigo.Value)) = .F.
      MESSAGEBOX("CPF inválido!", 16, _Screen.Caption)
      frmCad.edtCodigo.Value = ""
      frmCad.edtCodigo.SetFocus()
   endif
 endif
endproc
*------------------------------------------------------------------------------------
procedure edtCodProfissaoLostFocus()
LParameters frmCad, Consulta

if alltrim(frmCad.edtCodProfissao.Value)<>""   
  If Rotinas.ValidaInteger(alltrim(frmCad.edtCodProfissao.Value)) = .T.
    sTextoSql = ConsSQL.Profissao("S",alltrim(frmCad.edtCodProfissao.Value),"")
    sMensagemErro = "Profissão não encontrada!"
    
    if Rotinas.ConsultaDados(Consulta, sTextoSql) 
      frmCad.edtProfissao.Value = alltrim(curCadCliCodProfissao.Profissao)
    else
      MESSAGEBOX(sMensagemErro, 16, _Screen.Caption)
      frmCad.edtProfissao.Value = ""
      frmCad.edtCodProfissao.SetFocus()
    endif
    Rotinas.FecharCursor(Consulta)
  else
    frmCad.edtProfissao.Value = ""
    frmCad.edtCodProfissao.SetFocus()
  endif
else
  frmCad.edtProfissao.Value = ""
  frmCad.edtCodProfissao.SetFocus()
endif

endproc
*------------------------------------------------------------------------------------
procedure edtCodEnderecoLostFocus()
LParameters frmCad, Consulta

if alltrim(frmCad.edtCodEndereco.Value)<>""   
  If Rotinas.ValidaInteger(alltrim(frmCad.edtCodEndereco.Value)) = .T.
    sTextoSql = ConsSQL.Endereco("S",alltrim(frmCad.edtCodEndereco.Value),;
                "","","","","")
    sMensagemErro = "Endereço não encontrado!"
    
    if Rotinas.ConsultaDados(Consulta, sTextoSql) 
      frmCad.edtLogradouro.Value = alltrim(curCadCliCodEndereco.Logradouro)
      frmCad.edtBairro.Value = alltrim(curCadCliCodEndereco.Bairro)
      frmCad.edtCEP.Value = alltrim(curCadCliCodEndereco.CEP)
      frmCad.edtCidade.Value = alltrim(curCadCliCodEndereco.Cidade)
      frmCad.edtEstado.Value = alltrim(curCadCliCodEndereco.Estado)
    else
      MESSAGEBOX(sMensagemErro, 16, _Screen.Caption)
      frmCad.edtLogradouro.Value = ""
      frmCad.edtBairro.Value = ""
      frmCad.edtCEP.Value = ""
      frmCad.edtCidade.Value = ""
      frmCad.edtEstado.Value = ""
      frmCad.edtCodEndereco.SetFocus()
    endif
    Rotinas.FecharCursor(Consulta)
  else
      frmCad.edtLogradouro.Value = ""
      frmCad.edtBairro.Value = ""
      frmCad.edtCEP.Value = ""
      frmCad.edtCidade.Value = ""
      frmCad.edtEstado.Value = ""
      frmCad.edtCodEndereco.SetFocus()
  endif
else
    frmCad.edtLogradouro.Value = ""
    frmCad.edtBairro.Value = ""
    frmCad.edtCEP.Value = ""
    frmCad.edtCidade.Value = ""
    frmCad.edtEstado.Value = ""
    frmCad.edtCodEndereco.SetFocus()
endif

endproc
*------------------------------------------------------------------------------------
ENDDEFINE