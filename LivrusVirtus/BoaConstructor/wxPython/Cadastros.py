#Boa:FramePanel:frmCadastros

from wxPython.wx import *
from wxPython.lib.anchors import LayoutAnchors
from TextValidator import TextValidator
from ListaStr import LISTAMSTR
from RotinasGlobais import RotinasGlobais
from resource import Resource

[wxID_FRMCADASTROS, wxID_FRMCADASTROSBTNANTERIOR, wxID_FRMCADASTROSBTNEXCLUIR, 
 wxID_FRMCADASTROSBTNFECHAR, wxID_FRMCADASTROSBTNLIMPAR, 
 wxID_FRMCADASTROSBTNNOVO, wxID_FRMCADASTROSBTNPESQUISAR, 
 wxID_FRMCADASTROSBTNPROXIMO, wxID_FRMCADASTROSBTNSALVAR, 
 wxID_FRMCADASTROSEDTCODIGO, wxID_FRMCADASTROSEDTDESCRICAO, 
 wxID_FRMCADASTROSLABCODIGO, wxID_FRMCADASTROSLABDESCRICAO, 
] = map(lambda _init_ctrls: wxNewId(), range(13))

class frmCadastros(wxPanel):
    lstRegistros = LISTAMSTR()
    nLinhaRegistro = 0

    def _init_utils(self):
        pass

    def _init_ctrls(self, prnt, nFiltroCodigo, bIniciaBotoes):
        wxPanel.__init__(self, id=wxID_FRMCADASTROS, name=u'frmCadastros',
              parent=prnt, pos=wxPoint(398, 295), size=wxSize(338, 163),
              style=wxTAB_TRAVERSAL)
        self._init_utils()        
        self.SetClientSize(wxSize(330, 136))
        EVT_CLOSE(self, self.OnFrmcadastrosClose)

        self.labCodigo = wxStaticText(id=wxID_FRMCADASTROSLABCODIGO,
              label=u'C\xf3digo:', name=u'labCodigo', parent=self,
              pos=wxPoint(8, 8), size=wxSize(36, 13), style=0)

        self.edtCodigo = wxTextCtrl(id=wxID_FRMCADASTROSEDTCODIGO,
              name=u'edtCodigo', parent=self, pos=wxPoint(8, 24),
              size=wxSize(121, 21), style=0, 
              validator=TextValidator(nFiltroCodigo), value=u'')
        self.edtCodigo.SetMaxLength(10)
        self.btnNovo = wxButton(id=wxID_FRMCADASTROSBTNNOVO, label=u'&Novo',
              name=u'btnNovo', parent=self, pos=wxPoint(144, 24),
              size=wxSize(75, 25), style=0)

        self.labDescricao = wxStaticText(id=wxID_FRMCADASTROSLABDESCRICAO,
              label=u'Descri\xe7\xe3o:', name=u'labDescricao', parent=self,
              pos=wxPoint(8, 48), size=wxSize(51, 13), style=0)

        self.edtDescricao = wxTextCtrl(id=wxID_FRMCADASTROSEDTDESCRICAO,
              name=u'edtDescricao', parent=self, pos=wxPoint(8, 64),
              size=wxSize(217, 21), style=0, value=u'')
        self.edtDescricao.Enable(False)
        self.edtDescricao.SetMaxLength(30)

        if bIniciaBotoes:
          self.IniciaBotoes()
          self.FazLayout()

        self.nLinhaRegistro = 0

    def __init__(self, parent, id, pos, size, style, name):
        self._init_ctrls(parent)

    # Necessario por causa da tabulacao dos campos
    def IniciaBotoes(self):
        self.btnPesquisar = wxButton(id=wxID_FRMCADASTROSBTNPESQUISAR,
              label=u'&Pesquisar', name=u'btnPesquisar', parent=self,
              pos=wxPoint(248, 8), size=wxSize(75, 25), style=0)
        self.btnAnterior = wxButton(id=wxID_FRMCADASTROSBTNANTERIOR,
              label=u'&Anterior', name=u'btnAnterior', parent=self,
              pos=wxPoint(248, 40), size=wxSize(75, 25), style=0)
        self.btnAnterior.Enable(False)
        self.btnProximo = wxButton(id=wxID_FRMCADASTROSBTNPROXIMO,
              label=u'Pr\xf3xi&mo', name=u'btnProximo', parent=self,
              pos=wxPoint(248, 72), size=wxSize(75, 25), style=0)
        self.btnProximo.Enable(False)
        self.btnSalvar = wxButton(id=wxID_FRMCADASTROSBTNSALVAR,
              label=u'&Salvar', name=u'btnSalvar', parent=self, pos=wxPoint(8,
              104), size=wxSize(75, 25), style=0)
        self.btnSalvar.Enable(False)
        self.btnExcluir = wxButton(id=wxID_FRMCADASTROSBTNEXCLUIR,
              label=u'&Excluir', name=u'btnExcluir', parent=self,
              pos=wxPoint(88, 104), size=wxSize(75, 25), style=0)
        self.btnExcluir.Enable(False)
        self.btnLimpar = wxButton(id=wxID_FRMCADASTROSBTNLIMPAR,
              label=u'&Limpar', name=u'btnLimpar', parent=self, pos=wxPoint(168,
              104), size=wxSize(75, 25), style=0)
        self.btnFechar = wxButton(id=wxID_FRMCADASTROSBTNFECHAR,
              label=u'&Fechar', name=u'btnFechar', parent=self, pos=wxPoint(248,
              104), size=wxSize(75, 25), style=0)
        self.btnLimparClick()

    def FazLayout(self):
      self.sizer_1 = wxBoxSizer(wxVERTICAL)
      self.sizer_2 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_3 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_4 = wxBoxSizer(wxVERTICAL)
      self.sizer_5 = wxBoxSizer(wxVERTICAL)
      self.grid_sizer_2 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_1 = wxGridSizer(2, 2, 0, 1)
      self.grid_sizer_1.Add(self.labCodigo, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_1.Add(20, 10, 0, 0, 0)
      self.grid_sizer_1.Add(self.edtCodigo, 0, 0, 0)
      self.grid_sizer_1.Add(self.btnNovo, 0, wxLEFT, 6)
      self.sizer_5.Add(self.grid_sizer_1, 0, 0, 0)
      self.grid_sizer_2.Add(self.labDescricao, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_2.Add(self.edtDescricao, 0, 0, 2)
      self.sizer_5.Add(self.grid_sizer_2, 0, 0, 0)
      self.sizer_3.Add(self.sizer_5, 1, 0, 0)
      self.sizer_4.Add(self.btnPesquisar, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_4.Add(self.btnAnterior, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_4.Add(self.btnProximo, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_3.Add(self.sizer_4, 0, wxALIGN_RIGHT, 0)
      self.sizer_1.Add(self.sizer_3, 1, wxALL|wxEXPAND, 4)
      self.sizer_2.Add(self.btnSalvar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnExcluir, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnLimpar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnFechar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_1.Add(self.sizer_2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4)
      self.SetAutoLayout(True)
      self.SetSizer(self.sizer_1)
      self.sizer_1.Fit(self)
      self.sizer_1.SetSizeHints(self)
  
    def InformaLimpaDados(self, bInformar):
      if bInformar:
        self.edtCodigo.SetValue(
          self.lstRegistros.col[self.nLinhaRegistro][0])
        self.edtDescricao.SetValue(
          self.lstRegistros.col[self.nLinhaRegistro][1])
      else:
        self.edtCodigo.Clear()
        self.edtDescricao.Clear()
        self.edtCodigo.Enable(True)
        self.edtCodigo.SetFocus()

    def HabilitaDados(self, bHabilita):
      self.edtDescricao.Enable(bHabilita)

    def btnNovoClick(self):
      self.btnSalvar.Enable(True)
      self.btnExcluir.Enable(False)
      self.btnPesquisar.Enable(False)
      self.btnAnterior.Enable(False)
      self.btnProximo.Enable(False)
      self.btnNovo.Enable(False)
      
      self.nLinhaRegistro = 0
      self.InformaLimpaDados(False)
      self.HabilitaDados(True)	

    def NovoDado(self, sTextoSql):
      Rotinas = RotinasGlobais.Rotinas
      lstRegs = LISTAMSTR()
    
      if Rotinas.ConsultaDadosLista(Rotinas.gConexao, lstRegs, sTextoSql):
        self.edtCodigo.SetValue(str(lstRegs.col[0][0]))
        self.edtCodigo.Enable(False)
        self.edtDescricao.SetFocus()

    def btnLimparClick(self):
      self.nLinhaRegistro = 0
      self.btnSalvar.Enable(False)
      self.btnExcluir.Enable(False)
      self.btnPesquisar.Enable(True)
      self.btnAnterior.Enable(False)
      self.btnProximo.Enable(False)
      self.btnNovo.Enable(True)
    
      self.nLinhaRegistro = 0
      self.InformaLimpaDados(False)
      self.HabilitaDados(False)	

    def ExcluirDados(self, bValidaDados, sTextoSql):
      if bValidaDados:
        if wxMessageBox(Resource.STR_CERTEXCL, "Confirme",
                        wxICON_QUESTION | wxYES_NO) == wxYES:
          Rotinas = RotinasGlobais.Rotinas
          if Rotinas.AtualizaDados(Rotinas.gConexao, sTextoSql):
            self.btnLimparClick()
            return True
      return False

    def PesquisarDados(self, sTextoSql, sMensagemErro):
      if len(self.edtCodigo.GetValue()) == 0:
        self.btnAnterior.Enable(True)
        self.btnProximo.Enable(True)

      Rotinas = RotinasGlobais.Rotinas
      if Rotinas.ConsultaDadosLista(Rotinas.gConexao, 
          self.lstRegistros, sTextoSql):
         self.InformaLimpaDados(True)
         self.HabilitaDados(True)	
    
         self.btnSalvar.Enable(True)
         self.btnExcluir.Enable(True)
         self.btnPesquisar.Enable(False)
         return True
      else:
        wxMessageBox(sMensagemErro, "Erro", wxOK | wxICON_ERROR)
    
      return False

    def registroAnterior(self):
      if self.nLinhaRegistro > 0:
        self.nLinhaRegistro = self.nLinhaRegistro - 1
        self.InformaLimpaDados(True)
        return True
      else:
        return False

    def registroProximo(self):
      if self.nLinhaRegistro < (self.lstRegistros.tam-1):
        self.nLinhaRegistro = self.nLinhaRegistro + 1
        self.InformaLimpaDados(True)
        return True
      else:
        return False

    def SalvarDados(self, bValidaDados, sTextoSql, 
      sTextoUpdate, sTextoInsert, bLimparDados):
    
      if bValidaDados:
        Rotinas = RotinasGlobais.Rotinas
        if Rotinas.ConsultaDados(Rotinas.gConexao, sTextoSql):
          sArquiva = sTextoUpdate
        else:
          sArquiva = sTextoInsert	  	     

        if Rotinas.AtualizaDados(Rotinas.gConexao, sArquiva):
          if bLimparDados:
            self.btnLimparClick()
          return True
    
      return False

    def OnFrmcadastrosClose(self, event):
        self.Destroy()
    
