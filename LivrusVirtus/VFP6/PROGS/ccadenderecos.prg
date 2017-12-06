DEFINE CLASS CCadEnderecos AS Cadastros
*------------------------------------------------------------------------------------
function ValidaDados()
LParameters frmCad, bTodosDados

if Rotinas.ValidaCampo(frmCad.edtCodigo.Value, "C�digo n�o informado!")
  return .F.
Endif
if bTodosDados
  if Rotinas.ValidaCampo(frmCad.edtDescricao.Value, "Logradouro n�o informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtBairro.Value, "Bairro n�o informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtCEP.Value, "CEP n�o informado!")
	 return .F.
  Endif
  if Rotinas.ValidaCampo(frmCad.edtCidade.Value, "Cidade n�o informado!")
	 return .F.
  Endif
Endif
EndFunc
*------------------------------------------------------------------------------------
procedure RecuperaEstado()
LParameters frmCad, sEstado

local nCont

 for nCont=1 to frmCad.cmbEstado.ListCount
    if frmCad.cmbEstado.ListItem[nCont]=sEstado
       frmCad.cmbEstado.ListIndex=nCont
       exit for
    Endif 
 Endfor
 
EndProc
*------------------------------------------------------------------------------------
Procedure InformaLimpaDados()
LParameters frmCad, bInformar

If bInformar
   frmCad.edtCodigo.Value = alltrim(Str(curCadEnderecos.Codigo))
   frmCad.edtDescricao.Value = alltrim(curCadEnderecos.Logradouro)
   frmCad.edtBairro.Value = alltrim(curCadEnderecos.Bairro)
   frmCad.edtCEP.Value = alltrim(curCadEnderecos.CEP)
   frmCad.edtCidade.Value = alltrim(curCadEnderecos.Cidade)
   this.RecuperaEstado(frmCad, alltrim(curCadEnderecos.Estado))
Else
   *fCadastros.LimpaDados(frmCad)
   frmCad.edtBairro.Value = ""
   frmCad.edtCEP.Value = ""
   frmCad.edtCidade.Value = ""
   frmCad.cmbEstado.ListIndex = 1
EndIf
EndProc
*------------------------------------------------------------------------------------
Procedure HabilitaDados()
LParameters frmCad, bHabilita

    fCadastros.HabilitaDados(frmCad, bHabilita)
    frmCad.edtBairro.Enabled = bHabilita
	frmCad.edtCEP.Enabled = bHabilita
	frmCad.edtCidade.Enabled = bHabilita
	frmCad.cmbEstado.Enabled = bHabilita
EndProc
*------------------------------------------------------------------------------------
procedure AdicionaCombo()
LParameters frmCad

frmCad.cmbEstado.AddItem("Pernambuco")
frmCad.cmbEstado.AddItem("Acre")
frmCad.cmbEstado.AddItem("Alagoas")
frmCad.cmbEstado.AddItem("Amap�")
frmCad.cmbEstado.AddItem("Amazonas")
frmCad.cmbEstado.AddItem("Bahia")
frmCad.cmbEstado.AddItem("Bras�lia")
frmCad.cmbEstado.AddItem("Cear�")
frmCad.cmbEstado.AddItem("Distrito Federal")
frmCad.cmbEstado.AddItem("Esp�rito Santo")
frmCad.cmbEstado.AddItem("Goi�s")
frmCad.cmbEstado.AddItem("Mato Grosso")
frmCad.cmbEstado.AddItem("Mato Grosso do Sul")
frmCad.cmbEstado.AddItem("Minas Gerais")
frmCad.cmbEstado.AddItem("Par�")
frmCad.cmbEstado.AddItem("Para�ba")
frmCad.cmbEstado.AddItem("Paran�")
frmCad.cmbEstado.AddItem("Santa Catarina")
frmCad.cmbEstado.AddItem("Rio Grande do Norte")
frmCad.cmbEstado.AddItem("Rio Grande do Sul")
frmCad.cmbEstado.AddItem("Rio de Janeiro")
frmCad.cmbEstado.AddItem("Rond�nia")
frmCad.cmbEstado.AddItem("Roraima")
frmCad.cmbEstado.AddItem("S�o Paulo")
frmCad.cmbEstado.AddItem("Sergipe")
frmCad.cmbEstado.AddItem("Tocantins")
EndProc
*------------------------------------------------------------------------------------
Procedure frmLoad()
LParameters frmCad

    frmCad.Height = 169
    frmCad.Width = 525
    
    this.AdicionaCombo(frmCad)
    frmCad.cmbEstado.ListIndex = 1
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
ENDDEFINE