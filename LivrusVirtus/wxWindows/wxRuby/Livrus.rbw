#!/usr/bin/env ruby
module Livrus

require 'wxruby'
require 'Principal'
require 'Splash'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'ListaStr'
require 'resource'

class LivrusApp < Wx::App
    
  def on_init
    $ListaStr = LISTASTR.new
    $ListaMStr = LISTAMSTR.new
    $Rotinas = RotinasGlobais.new
    $ConsSQL = ConsultasSQL.new
    $fPrincipal = FrmPrincipal.new

    if not $Rotinas.ConectaBanco("DBI:ODBC:ACLivrus","","") then
      exit(0)
    end

    $fSplash = FrmSplash.new
    $fSplash.show(true)
  end
        
end

livrus = LivrusApp.new

livrus.main_loop

end
