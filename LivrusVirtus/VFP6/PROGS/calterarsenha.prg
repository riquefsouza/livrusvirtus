DEFINE CLASS CAlterarSenha AS CUSTOM
*------------------------------------------------------------------------------------
function ValidaDados()
LParameters frm

if alltrim(frm.edtSenhaAtual.Value) <> alltrim(sUsuarioSenha)
 MESSAGEBOX("A Senha atual não confere com a senha do usuário!", 16, _Screen.Caption)
 return .F.
Endif
if Rotinas.ValidaCampo(frm.edtNovaSenha.Value, "Nova senha não informada!")
  return .F.
Endif
if alltrim(frm.edtNovaSenha.Value) <> alltrim(frm.edtConfirmarSenha.Value)
 MESSAGEBOX("A Nova senha não confere com a senha a confirmar!", 16, _Screen.Caption)
 return .F.
Endif

EndFunc
*------------------------------------------------------------------------------------
ENDDEFINE
