#!/usr/bin/env ruby
module Livrus
require 'fox'
include Fox
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'ListaStr'
require 'resource'
require 'Login'
require 'Splash'

if __FILE__ == $0

  LivrusApp = FXApp.new("Livrus", Resource::STR_TITULO)

  $ListaStr = LISTASTR.new
  $ListaMStr = LISTAMSTR.new
  $Rotinas = RotinasGlobais.new
  $ConsSQL = ConsultasSQL.new
  $frmPrincipal = FRMPrincipal.new(LivrusApp)
  $frmLogin = FRMLogin.new(LivrusApp)
  $frmSplash = FRMSplash.new(LivrusApp)

  LivrusApp.create

  if not $Rotinas.ConectaBanco("DBI:ODBC:ACLivrus","","") then
    return false
  else
   $frmSplash.iniciaTimer()
   $frmSplash.show(PLACEMENT_SCREEN)
   #$frmPrincipal.show(PLACEMENT_SCREEN)
  end

  LivrusApp.run
end

end
