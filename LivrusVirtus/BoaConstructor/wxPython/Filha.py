#Boa:MDIChild:frmFilha

from wxPython.wx import *
from resource import Resource
import CadAssuntos
import CadAutores
import CadEditoras
import CadEnderecos
import CadIdiomas
import CadPaises
import CadProfissoes
import CadClientes
import CadLivros
import VenderLivros
import ConVendas
import AlterarSenha
import Principal

def create(parent): 
    return frmFilha(parent)

[wxID_FRMFILHA] = map(lambda _init_ctrls: wxNewId(), range(1))

class frmFilha(wxMDIChildFrame):
    def _init_utils(self):
        # generated method, don't edit
        pass

    def _init_ctrls(self, prnt):
        # generated method, don't edit
        wxMDIChildFrame.__init__(self, id=wxID_FRMFILHA, name=u'frmFilha',
              parent=prnt, pos=wxPoint(0, 0), size=wxSize(342, 219),
              style=wxDEFAULT_FRAME_STYLE, title=u'Cadastro de ')
        self._init_utils()
        self.SetIcon(wxIcon(Resource.ICO_LIVRUS, wxBITMAP_TYPE_ICO))
        self.SetClientSize(wxSize(330, 136))
        EVT_CLOSE(self, self.OnFrmFilhaClose)

        if prnt.nTelaAtiva == Resource.FRMCADASSUNTOS:
          CadAssuntos.create(self)
          self.SetTitle(Resource.STR_CADASSUNTO)
        elif prnt.nTelaAtiva == Resource.FRMCADAUTORES:
          CadAutores.create(self)
          self.SetTitle(Resource.STR_CADAUTOR)
        elif prnt.nTelaAtiva == Resource.FRMCADEDITORAS:
          CadEditoras.create(self)
          self.SetTitle(Resource.STR_CADEDITORA)
        elif prnt.nTelaAtiva == Resource.FRMCADENDERECOS:
          CadEnderecos.create(self)
          self.SetTitle(Resource.STR_CADENDERECO)
          self.SetClientSize(wxSize(525, 170))
        elif prnt.nTelaAtiva == Resource.FRMCADIDIOMAS:
          CadIdiomas.create(self)
          self.SetTitle(Resource.STR_CADIDIOMA)        
        elif prnt.nTelaAtiva == Resource.FRMCADPAISES:
          CadPaises.create(self)
          self.SetTitle(Resource.STR_CADPAIS)
        elif prnt.nTelaAtiva == Resource.FRMCADPROFISSOES:
          CadProfissoes.create(self)
          self.SetTitle(Resource.STR_CADPROFISS)
        elif prnt.nTelaAtiva == Resource.FRMCADCLIENTES:
          CadClientes.create(self)
          self.SetTitle(Resource.STR_CADCLIENTE)
          self.SetClientSize(wxSize(525, 440))
        elif prnt.nTelaAtiva == Resource.FRMCADLIVROS:
          CadLivros.create(self)
          self.SetTitle(Resource.STR_CADLIVRO)
          self.SetClientSize(wxSize(510, 425))        
        elif prnt.nTelaAtiva == Resource.FRMVENDERLIVROS:
          VenderLivros.create(self)
          self.SetTitle(Resource.STR_VENLIVRO)
          self.SetClientSize(wxSize(480, 310))        
        elif prnt.nTelaAtiva == Resource.FRMCONVENDAS:
          ConVendas.create(self)
          self.SetTitle(Resource.STR_CONVENLIVRO)
          self.SetClientSize(wxSize(480, 330))
        elif prnt.nTelaAtiva == Resource.FRMALTERARSENHA:
          AlterarSenha.create(self)
          self.SetTitle(Resource.STR_ALTSENHA)
          self.SetClientSize(wxSize(255, 134))

    def __init__(self, parent):
        self._init_ctrls(parent)

    def OnFrmFilhaClose(self, event):
      frmPrincipal = Principal.fPrincipal
      if self.GetParent().nTelaAtiva == Resource.FRMCADASSUNTOS:
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_ASSUNTOS, True)
      elif self.GetParent().nTelaAtiva == Resource.FRMCADAUTORES: 
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_AUTORES, True)  
      elif self.GetParent().nTelaAtiva == Resource.FRMCADEDITORAS:
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_EDITORAS, True)    
      elif self.GetParent().nTelaAtiva == Resource.FRMCADENDERECOS:
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_ENDERECOS, True)    
      elif self.GetParent().nTelaAtiva == Resource.FRMCADIDIOMAS:
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_IDIOMAS, True)   
      elif self.GetParent().nTelaAtiva == Resource.FRMCADPAISES: 
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_PAISES, True)    
      elif self.GetParent().nTelaAtiva == Resource.FRMCADPROFISSOES: 
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_PROFISSOES, True)    
      elif self.GetParent().nTelaAtiva == Resource.FRMCADCLIENTES:
        frmPrincipal.tlbCadClientes.Enable(True)
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_CLIENTES, True)   
      elif self.GetParent().nTelaAtiva == Resource.FRMCADLIVROS:
        frmPrincipal.tlbCadLivros.Enable(True)
        frmPrincipal.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_LIVROS, True)
      elif self.GetParent().nTelaAtiva == Resource.FRMVENDERLIVROS:
        frmPrincipal.tlbVenderLivros.Enable(True)
        frmPrincipal.BarraDeMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDERLIVROS, True)  
      elif self.GetParent().nTelaAtiva == Resource.FRMCONVENDAS: 
        frmPrincipal.BarraDeMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDASREALIZADAS, True)
      elif self.GetParent().nTelaAtiva == Resource.FRMALTERARSENHA:
        frmPrincipal.BarraDeMenu.GetMenu(3).Enable(Resource.MNU_OP_ALTERARSENHA, True)
      event.Skip()
    

