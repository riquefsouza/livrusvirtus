#Boa:MDIParent:frmPrincipal

from wxPython.wx import *
from wxPython.lib.anchors import LayoutAnchors

from resource import Resource
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
import Sobre
import Splash
import Login
import Filha
import ConAssuntos
import ConAutores
import ConEditoras
import ConEnderecos
import ConIdiomas
import ConPaises
import ConProfissoes
import ConClientes
import ConLivros

def create(parent):
    return frmPrincipal(parent)

[wxID_FRMPRINCIPAL, wxID_FRMPRINCIPALBARRADEFERRAMENTAS, 
 wxID_FRMPRINCIPALBARRADESTATUS, wxID_FRMPRINCIPALTLBSAIR, 
 wxID_FRMPRINCIPALTLBSOBRE, 
] = map(lambda _init_ctrls: wxNewId(), range(5))

class frmPrincipal(wxMDIParentFrame):
    def _init_coll_mnuPesquisas_Items(self, parent):
        parent.Append(helpString=Resource.STR_CONASSUNTO,
              id=Resource.MNU_CON_ASSUNTOS, item=u'&Assuntos',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONAUTOR,
              id=Resource.MNU_CON_AUTORES, item=u'A&utores',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONEDITORA,
              id=Resource.MNU_CON_EDITORAS, item=u'&Editoras',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONENDERECO,
              id=Resource.MNU_CON_ENDERECOS,
              item=u'E&ndere\xe7os', kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONIDIOMA,
              id=Resource.MNU_CON_IDIOMAS, item=u'&Idiomas',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONPAIS,
              id=Resource.MNU_CON_PAISES, item=u'&Pa\xedses',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONPROFISS,
              id=Resource.MNU_CON_PROFISSOES,
              item=u'P&rofiss\xf5es', kind=wxITEM_NORMAL)
        parent.AppendSeparator()
        parent.Append(helpString=Resource.STR_CONCLIENTE,
              id=Resource.MNU_CON_CLIENTES, item=u'&Clientes',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONLIVRO,
              id=Resource.MNU_CON_LIVROS, item=u'&Livros',
              kind=wxITEM_NORMAL)
        EVT_MENU(self, Resource.MNU_CON_ASSUNTOS, self.OnMnuConAssuntos)
        EVT_MENU(self, Resource.MNU_CON_AUTORES,  self.OnMnuConAutores)
        EVT_MENU(self, Resource.MNU_CON_EDITORAS, self.OnMnuConEditoras)
        EVT_MENU(self, Resource.MNU_CON_ENDERECOS, self.OnMnuConEnderecos)
        EVT_MENU(self, Resource.MNU_CON_IDIOMAS, self.OnMnuConIdiomas)
        EVT_MENU(self, Resource.MNU_CON_PAISES,
              self.OnMnuConPaises)
        EVT_MENU(self, Resource.MNU_CON_PROFISSOES,
              self.OnMnuConProfissoes)
        EVT_MENU(self, Resource.MNU_CON_CLIENTES,
              self.OnMnuConClientes)
        EVT_MENU(self, Resource.MNU_CON_LIVROS,
              self.OnMnuConLivros)

    def _init_coll_mnuCadastros_Items(self, parent):
        parent.Append(helpString=Resource.STR_CADASSUNTO,
              id=Resource.MNU_CAD_ASSUNTOS, item=u'&Assuntos',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CADAUTOR,
              id=Resource.MNU_CAD_AUTORES, item=u'A&utores',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CADEDITORA,
              id=Resource.MNU_CAD_EDITORAS, item=u'&Editoras',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CADENDERECO,
              id=Resource.MNU_CAD_ENDERECOS,
              item=u'E&ndere\xe7os', kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CADIDIOMA,
              id=Resource.MNU_CAD_IDIOMAS, item=u'&Idiomas',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CADPAIS,
              id=Resource.MNU_CAD_PAISES, item=u'&Pa\xedses',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CADPROFISS,
              id=Resource.MNU_CAD_PROFISSOES,
              item=u'P&rofiss\xf5es', kind=wxITEM_NORMAL)
        parent.AppendSeparator()
        parent.Append(helpString=Resource.STR_CADCLIENTE,
              id=Resource.MNU_CAD_CLIENTES, item=u'&Clientes',
              kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CADLIVRO,
              id=Resource.MNU_CAD_LIVROS, item=u'&Livros',
              kind=wxITEM_NORMAL)
        EVT_MENU(self, Resource.MNU_CAD_ASSUNTOS,
              self.OnMnuCadAssuntos)
        EVT_MENU(self, Resource.MNU_CAD_AUTORES,
              self.OnMnuCadAutores)
        EVT_MENU(self, Resource.MNU_CAD_EDITORAS,
              self.OnMnuCadEditoras)
        EVT_MENU(self, Resource.MNU_CAD_ENDERECOS,
              self.OnMnuCadEnderecos)
        EVT_MENU(self, Resource.MNU_CAD_IDIOMAS,
              self.OnMnuCadIdiomas)
        EVT_MENU(self, Resource.MNU_CAD_PAISES,
              self.OnMnuCadPaises)
        EVT_MENU(self, Resource.MNU_CAD_PROFISSOES,
              self.OnMnuCadProfissoes)
        EVT_MENU(self, Resource.MNU_CAD_CLIENTES,
              self.OnMnuCadClientes)
        EVT_MENU(self, Resource.MNU_CAD_LIVROS,
              self.OnMnuCadLivros)

    def _init_coll_mnuVendas_Items(self, parent):
        parent.Append(helpString=Resource.STR_VENLIVRO,
              id=Resource.MNU_VEN_VENDERLIVROS,
              item=u'&Vender Livros', kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_CONVENLIVRO,
              id=Resource.MNU_VEN_VENDASREALIZADAS,
              item=u'Vendas &Realizadas', kind=wxITEM_NORMAL)
        EVT_MENU(self, Resource.MNU_VEN_VENDERLIVROS,
              self.OnMnuVenderLivros)
        EVT_MENU(self, Resource.MNU_VEN_VENDASREALIZADAS,
              self.OnMnuVendasRealizadas)

    def _init_coll_mnuOpcoes_Items(self, parent):
        # generated method, don't edit

        parent.Append(helpString=Resource.STR_ALTSENHA,
              id=Resource.MNU_OP_ALTERARSENHA,
              item=u'&Alterar Senha', kind=wxITEM_NORMAL)
        parent.AppendSeparator()
        parent.Append(helpString=Resource.STR_OPSOBRE, 
              id=Resource.MNU_OP_SOBRE,
              item=u'&Sobre', kind=wxITEM_NORMAL)
        parent.Append(helpString=Resource.STR_OPSAIR, 
              id=Resource.MNU_OP_SAIR,
              item=u'Sa&ir\tCtrl-S', kind=wxITEM_NORMAL)
        EVT_MENU(self, Resource.MNU_OP_SAIR, self.OnMnuSair)
        EVT_MENU(self, Resource.MNU_OP_ALTERARSENHA,
              self.OnMnuAlterarSenha)
        EVT_MENU(self, Resource.MNU_OP_SOBRE, self.OnMnuSobre)

    def _init_coll_BarraDeMenu_Menus(self, parent):
        # generated method, don't edit
        parent.Append(menu=self.mnuCadastros, title=u'&Cadastros')
        parent.Append(menu=self.mnuPesquisas, title=u'&Pesquisas')
        parent.Append(menu=self.mnuVendas, title=u'&Vendas')
        parent.Append(menu=self.mnuOpcoes, title=u'&Op\xe7\xf5es')

    def _init_coll_BarraDeStatus_Fields(self, parent):
        # generated method, don't edit
        parent.SetFieldsCount(2)

        parent.SetStatusText(i=0, text=Resource.STR_USUARIO)
        parent.SetStatusText(i=1, text=u'')

        parent.SetStatusWidths([100, -1])        

    def _init_utils(self):
        # generated method, don't edit
        self.BarraDeMenu = wxMenuBar()

        self.mnuCadastros = wxMenu(title=u'')
        self._init_coll_mnuCadastros_Items(self.mnuCadastros)

        self.mnuPesquisas = wxMenu(title=u'')
        self._init_coll_mnuPesquisas_Items(self.mnuPesquisas)

        self.mnuVendas = wxMenu(title=u'')
        self._init_coll_mnuVendas_Items(self.mnuVendas)

        self.mnuOpcoes = wxMenu(title=u'')
        self._init_coll_mnuOpcoes_Items(self.mnuOpcoes)

        self._init_coll_BarraDeMenu_Menus(self.BarraDeMenu)

    def _init_ctrls(self, prnt):
        # generated method, don't edit
        wxMDIParentFrame.__init__(self, id=wxID_FRMPRINCIPAL,
              name=u'frmPrincipal', parent=prnt, pos=wxPoint(230, 92),
              size=wxSize(716, 560),
              style=wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL,
              title=u'Livrus Virtus')
        self._init_utils()
        self.SetIcon(wxIcon(Resource.ICO_LIVRUS, wxBITMAP_TYPE_ICO))
        self.SetMenuBar(self.BarraDeMenu)
        self.SetAutoLayout(true)
        self.SetClientSize(wxSize(708, 533))
        self.SetStatusBarPane(1)
        EVT_SIZE(self, self.OnWxmdiparentframe1Size)
        EVT_CLOSE(self, self.OnFrmprincipalClose)

        self.BarraDeStatus = wxStatusBar(id=wxID_FRMPRINCIPALBARRADESTATUS,
              name=u'BarraDeStatus', parent=self, style=0)
        self.BarraDeStatus.SetPosition(wxPoint(0, 466))
        self.BarraDeStatus.SetSize(wxSize(708, 20))
        self.BarraDeStatus.SetStatusText(u'')
        self.BarraDeStatus.SetAutoLayout(False)
        self._init_coll_BarraDeStatus_Fields(self.BarraDeStatus)
        self.SetStatusBar(self.BarraDeStatus)

        self.aTabela = wxAcceleratorTable([(wxACCEL_CTRL, ord('S'), 
          Resource.MNU_OP_SAIR)])
        self.SetAcceleratorTable(self.aTabela)

        self.BarraDeFerramentas = wxToolBar(id=wxID_FRMPRINCIPALBARRADEFERRAMENTAS,
              name=u'BarraDeFerramentas', parent=self, pos=wxPoint(0, 0),
              size=wxSize(708, 28), style=wxTB_HORIZONTAL | wxNO_BORDER)
        self.SetToolBar(self.BarraDeFerramentas)

        self.tlbCadClientes = wxBitmapButton(bitmap=wxBitmap(u'cliente.bmp',
              wxBITMAP_TYPE_BMP), id=Resource.TLB_CADCLIENTES,
              name=u'tlbCadClientes', parent=self.BarraDeFerramentas,
              pos=wxPoint(0, 0), size=wxSize(24, 24), style=wxBU_AUTODRAW,
              validator=wxDefaultValidator)
        self.tlbCadClientes.SetBitmapLabel(wxBitmap(u'cliente.bmp',
              wxBITMAP_TYPE_BMP))
        self.tlbCadClientes.SetBitmapDisabled(wxBitmap(u'dcliente.bmp',
              wxBITMAP_TYPE_BMP))
        EVT_BUTTON(self.tlbCadClientes, self.tlbCadClientes.GetId(),
              self.OnMnuCadClientes)

        self.tlbCadLivros = wxBitmapButton(bitmap=wxBitmap(u'Livro.bmp',
              wxBITMAP_TYPE_BMP), id=Resource.TLB_CADLIVROS,
              name=u'tlbCadLivros', parent=self.BarraDeFerramentas,
              pos=wxPoint(24, 0), size=wxSize(24, 24), style=wxBU_AUTODRAW,
              validator=wxDefaultValidator)
        self.tlbCadLivros.SetBitmapLabel(wxBitmap(u'Livro.bmp',
              wxBITMAP_TYPE_BMP))
        self.tlbCadLivros.SetBitmapDisabled(wxBitmap(u'dlivro.bmp',
              wxBITMAP_TYPE_BMP))
        EVT_BUTTON(self.tlbCadLivros, self.tlbCadLivros.GetId(),
              self.OnMnuCadLivros)

        self.tlbVenderLivros = wxBitmapButton(bitmap=wxBitmap(u'Livros.bmp',
              wxBITMAP_TYPE_BMP), id=Resource.TLB_VENDERLIVROS,
              name=u'tlbVenderLivros', parent=self.BarraDeFerramentas,
              pos=wxPoint(48, 0), size=wxSize(24, 24), style=wxBU_AUTODRAW,
              validator=wxDefaultValidator)
        self.tlbVenderLivros.SetBitmapLabel(wxBitmap(u'Livros.bmp',
              wxBITMAP_TYPE_BMP))
        self.tlbVenderLivros.SetBitmapDisabled(wxBitmap(u'dlivros.bmp',
              wxBITMAP_TYPE_BMP))
        EVT_BUTTON(self.tlbVenderLivros, self.tlbVenderLivros.GetId(),
              self.OnMnuVenderLivros)

        self.tlbSobre = wxBitmapButton(bitmap=wxBitmap(u'Sobre.bmp',
              wxBITMAP_TYPE_BMP), id=wxID_FRMPRINCIPALTLBSOBRE,
              name=u'tlbSobre', parent=self.BarraDeFerramentas, pos=wxPoint(88,
              0), size=wxSize(24, 24), style=wxBU_AUTODRAW,
              validator=wxDefaultValidator)
        self.tlbSobre.SetBitmapLabel(wxBitmap(u'Sobre.bmp',wxBITMAP_TYPE_BMP))
        self.tlbSobre.SetBitmapDisabled(wxBitmap(u'dsobre.bmp',
              wxBITMAP_TYPE_BMP))
        EVT_BUTTON(self.tlbSobre, wxID_FRMPRINCIPALTLBSOBRE,
              self.OnTlbsobreButton)

        self.tlbSair = wxBitmapButton(bitmap=wxBitmap(u'Sair.bmp',
              wxBITMAP_TYPE_BMP), id=wxID_FRMPRINCIPALTLBSAIR, name=u'tlbSair',
              parent=self.BarraDeFerramentas, pos=wxPoint(112, 0),
              size=wxSize(24, 24), style=wxBU_AUTODRAW,
              validator=wxDefaultValidator)
        self.tlbSair.SetBitmapLabel(wxBitmap(u'Sair.bmp',wxBITMAP_TYPE_BMP))
        self.tlbSair.SetBitmapDisabled(wxBitmap(u'dsair.bmp',wxBITMAP_TYPE_BMP))
        EVT_BUTTON(self.tlbSair, wxID_FRMPRINCIPALTLBSAIR, self.OnTlbsairButton)

    def __init__(self, parent):      
        self._init_ctrls(parent)

    def OnWxmdiparentframe1Size(self, event):
        wxLayoutAlgorithm().LayoutMDIFrame(self)

    def OnMnuCadAssuntos(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADASSUNTO,1)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_ASSUNTOS, False)
        self.nTelaAtiva = Resource.FRMCADASSUNTOS
        frmCadAssuntos = Filha.create(self)
        event.Skip()

    def OnMnuCadAutores(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADAUTOR,1)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_AUTORES, False)
        self.nTelaAtiva = Resource.FRMCADAUTORES
        frmCadAutores = Filha.create(self)
        event.Skip()

    def OnMnuCadEditoras(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADEDITORA,1)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_EDITORAS, False)
        self.nTelaAtiva = Resource.FRMCADEDITORAS
        frmCadEditoras = Filha.create(self)
        event.Skip()
        
    def OnMnuCadEnderecos(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADENDERECO,1)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_ENDERECOS, False)
        self.nTelaAtiva = Resource.FRMCADENDERECOS
        frmCadEnderecos = Filha.create(self)
        event.Skip()

    def OnMnuCadIdiomas(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADIDIOMA,1)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_IDIOMAS, False)
        self.nTelaAtiva = Resource.FRMCADIDIOMAS
        frmCadIdiomas = Filha.create(self)
        event.Skip()

    def OnMnuCadPaises(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADPAIS,1)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_PAISES, False)
        self.nTelaAtiva = Resource.FRMCADPAISES
        frmCadPaises = Filha.create(self)
        event.Skip()

    def OnMnuCadProfissoes(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADPROFISS,1)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_PROFISSOES, False)
        self.nTelaAtiva = Resource.FRMCADPROFISSOES
        frmCadProfissoes = Filha.create(self)
        event.Skip()

    def OnMnuCadClientes(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADCLIENTE,1)
        self.tlbCadClientes.Enable(False)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_CLIENTES, False)
        self.nTelaAtiva = Resource.FRMCADCLIENTES
        frmCadClientes = Filha.create(self)
        #event.Skip()

    def OnMnuCadLivros(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CADLIVRO,1)
        self.tlbCadLivros.Enable(False)
        self.BarraDeMenu.GetMenu(0).Enable(Resource.MNU_CAD_LIVROS, False)
        self.nTelaAtiva = Resource.FRMCADLIVROS
        frmCadLivros = Filha.create(self)
        #event.Skip()

    def OnMnuConAssuntos(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONASSUNTO,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_ASSUNTOS, False)
        frmConAssuntos = ConAssuntos.create(self)
        frmConAssuntos.Show(True)
      	event.Skip()

    def OnMnuConAutores(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONAUTOR,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_AUTORES, False)
        frmConAutores = ConAutores.create(self)
        frmConAutores.Show(True)
        event.Skip()

    def OnMnuConEditoras(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONEDITORA,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_EDITORAS, False)
        frmConEditoras = ConEditoras.create(self)
        frmConEditoras.Show(True)
        event.Skip()

    def OnMnuConEnderecos(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONENDERECO,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_ENDERECOS, False)
        frmConEnderecos = ConEnderecos.create(self)
        frmConEnderecos.Show(True)
        event.Skip()

    def OnMnuConIdiomas(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONIDIOMA,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_IDIOMAS, False)
        frmConIdiomas = ConIdiomas.create(self)
        frmConIdiomas.Show(True)
        event.Skip()

    def OnMnuConPaises(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONPAIS,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_PAISES, False)
        frmConPaises = ConPaises.create(self)
        frmConPaises.Show(True)
        event.Skip()

    def OnMnuConProfissoes(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONPROFISS,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_PROFISSOES, False)
        frmConProfissoes = ConProfissoes.create(self)
        frmConProfissoes.Show(True)
        event.Skip()

    def OnMnuConClientes(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONCLIENTE,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_CLIENTES, False)
        frmConClientes = ConClientes.create(self)
        frmConClientes.Show(True)
        event.Skip()

    def OnMnuConLivros(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONLIVRO,1)
        self.BarraDeMenu.GetMenu(1).Enable(Resource.MNU_CON_LIVROS, False)
        frmConLivros = ConLivros.create(self)
        frmConLivros.Show(True)
        event.Skip()

    def OnMnuVenderLivros(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_VENLIVRO,1)
        self.tlbVenderLivros.Enable(False)
        self.BarraDeMenu.GetMenu(2).Enable(
          Resource.MNU_VEN_VENDERLIVROS, False)
        self.nTelaAtiva = Resource.FRMVENDERLIVROS
        frmVenderLivros = Filha.create(self)
        #event.Skip()

    def OnMnuVendasRealizadas(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_CONVENLIVRO,1)
        self.BarraDeMenu.GetMenu(2).Enable(
          Resource.MNU_VEN_VENDASREALIZADAS, False)
        self.nTelaAtiva = Resource.FRMCONVENDAS
        frmConVendas = Filha.create(self)
        event.Skip()

    def OnMnuAlterarSenha(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_ALTSENHA,1)
        self.BarraDeMenu.GetMenu(3).Enable(
          Resource.MNU_OP_ALTERARSENHA, False)
        self.nTelaAtiva = Resource.FRMALTERARSENHA
        frmAlterarSenha = Filha.create(self)
        event.Skip()

    def OnMnuSobre(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_OPSOBRE,1)
        frmSobre = Sobre.create(self)
        frmSobre.ShowModal()
        frmSobre.Destroy()
        event.Skip()

    def OnMnuSair(self, event):
        self.BarraDeStatus.SetStatusText(Resource.STR_OPSAIR,1)
        self.Close(True)

    def OnTlbsobreButton(self, event):
        self.OnMnuSobre(event)

    def OnTlbsairButton(self, event):
        self.OnMnuSair(event)

    def OnFrmprincipalClose(self, event):        
        if (wxMessageBox(Resource.STR_SAIRSIS, u'Confirma',
                         wxYES_NO | wxICON_QUESTION, self) == wxYES):
            self.Destroy()

