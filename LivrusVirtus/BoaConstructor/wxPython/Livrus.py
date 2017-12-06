#!/usr/bin/env python
#Livrus:App:LivrusApp

from wxPython.wx import *
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource
import Splash
import Principal

modules={u'Principal': [0, u'Tela Principal do Sistema', u'Principal.py'],
 u'Cadastros': [1, u'Cadastro', u'Cadastros.py'],
 u'Consultas': [2, u'Consultas', u'Consultas.py'],
 u'CadAssuntos': [3, u'Cadastro de Assuntos', u'CadAssuntos.py'],
 u'AlterarSenha': [4, u'Altera\xe7\xe3o de Senha', u'AlterarSenha.py'],
 u'Sobre': [5, u'Sobre o Sistema', u'Sobre.py'],
 u'Splash': [6, u'Tela de Splash', u'Splash.py']}

class LivrusApp(wxApp):
    def OnInit(self):
        RotinasGlobais.Rotinas = RotinasGlobais()
        ConsultasSQL.ConsSQL = ConsultasSQL()
        Principal.fPrincipal = Principal.create(None)
        self.SetTopWindow(Principal.fPrincipal)

        if not RotinasGlobais.Rotinas.ConectaBanco("ACLivrus","",""):
          wxMessageBox(Resource.STR_NCONBANCO,"Erro", wxOK | wxICON_ERROR)
          return False
               
        fSplash = Splash.create(None)
        fSplash.Show()  
        return True

def main():
    application = LivrusApp(0)
    application.MainLoop()

if __name__ == '__main__':
    main()
