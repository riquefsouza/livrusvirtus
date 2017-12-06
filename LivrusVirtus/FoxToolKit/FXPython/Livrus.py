#! /usr/bin/env python

from FXPy.fox import *
import sys
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource
import Splash
import Login
import Principal

def main(): 
  LivrusApp = FXApp("Livrus", Resource.STR_TITULO)

  RotinasGlobais.Rotinas = RotinasGlobais()
  ConsultasSQL.ConsSQL = ConsultasSQL()
  Principal.fPrincipal = Principal.create(LivrusApp)
  Login.fLogin = Login.create(Principal.fPrincipal)
  Splash.fSplash = Splash.create(Principal.fPrincipal)

  LivrusApp.init(sys.argv)
  LivrusApp.create()

  if not RotinasGlobais.Rotinas.ConectaBanco("ACLivrus","",""):
    return False
  else:
    #Splash.fSplash.iniciaTimer()
    #Splash.fSplash.show(PLACEMENT_SCREEN)
    Principal.fPrincipal.show(PLACEMENT_SCREEN)

  LivrusApp.run()

if __name__ == '__main__':
  main()

