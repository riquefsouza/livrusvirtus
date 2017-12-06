#Boa:FramePanel:frmCadLivros

from wxPython.wx import *
from TextValidator import TextValidator
from Cadastros import frmCadastros
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource
from ListaStr import LISTAMSTR, LISTASTR
import ConAssuntos
import ConAutores
import ConEditoras

[wxID_FRMCADLIVROS, wxID_FRMCADLIVROSBTNADASSUNTOS, 
 wxID_FRMCADLIVROSBTNADAUTORES, wxID_FRMCADLIVROSBTNPASSUNTO, 
 wxID_FRMCADLIVROSBTNPAUTOR, wxID_FRMCADLIVROSBTNPEDITORA, 
 wxID_FRMCADLIVROSCMBIDIOMA, wxID_FRMCADLIVROSEDTANOPUBLI, 
 wxID_FRMCADLIVROSEDTASSUNTO, wxID_FRMCADLIVROSEDTAUTOR, 
 wxID_FRMCADLIVROSEDTCODASSUNTO, wxID_FRMCADLIVROSEDTCODAUTOR, 
 wxID_FRMCADLIVROSEDTCODEDITORA, wxID_FRMCADLIVROSEDTEDICAO, 
 wxID_FRMCADLIVROSEDTEDITORA, wxID_FRMCADLIVROSEDTNPAGINAS, 
 wxID_FRMCADLIVROSEDTPRECO, wxID_FRMCADLIVROSEDTQTDESTOQUE, 
 wxID_FRMCADLIVROSEDTVOLUME, wxID_FRMCADLIVROSLABANOPUBLI, 
 wxID_FRMCADLIVROSLABASSUNTO, wxID_FRMCADLIVROSLABAUTOR, 
 wxID_FRMCADLIVROSLABEDICAO, wxID_FRMCADLIVROSLABEDITORA, 
 wxID_FRMCADLIVROSLABIDIOMA, wxID_FRMCADLIVROSLABNPAGINAS, 
 wxID_FRMCADLIVROSLABPRECO, wxID_FRMCADLIVROSLABQTDESTOQUE, 
 wxID_FRMCADLIVROSLABVOLUME, wxID_FRMCADLIVROSLSTASSUNTOS, 
 wxID_FRMCADLIVROSLSTAUTORES, 
] = map(lambda _init_ctrls: wxNewId(), range(31))

def create(parent):
    return frmCadLivros(parent)

class frmCadLivros(frmCadastros):
    slAssuntos = LISTASTR()
    slAutores = LISTASTR()
    slIdiomas = LISTASTR()

    def _init_utils(self):
        pass

    def _init_ctrls(self, prnt):
        frmCadastros._init_ctrls(self, prnt, TextValidator.FILTER_NONE, False)
        self._init_utils()
        self.SetClientSize(wxSize(511, 384))
        self.labCodigo.SetLabel(u'ISBN: ')
        self.labDescricao.SetLabel(u'T\xedtulo: ')
        self.edtDescricao.SetSize(wxSize(312, 21))
        self.edtDescricao.Enable(False)
        EVT_KILL_FOCUS(self.edtCodigo, self.OnEdtCodigo_Killfocus)

        self.labEdicao = wxStaticText(id=wxID_FRMCADLIVROSLABEDICAO,
              label=u'Edi\xe7\xe3o: ', name=u'labEdicao', parent=self,
              pos=wxPoint(326, 48), size=wxSize(39, 13), style=0)

        self.edtEdicao = wxSpinCtrl(id=wxID_FRMCADLIVROSEDTEDICAO, initial=0,
              max=100, min=0, name=u'edtEdicao', parent=self, pos=wxPoint(324,
              64), size=wxSize(92, 21), style=wxSP_ARROW_KEYS)
        self.edtEdicao.Enable(False)
        self.edtEdicao.SetRange(0, 9999)
        self.edtEdicao.SetValue(0)

        self.labAnoPubli = wxStaticText(id=wxID_FRMCADLIVROSLABANOPUBLI,
              label=u'Ano Publica\xe7\xe3o: ', name=u'labAnoPubli', parent=self,
              pos=wxPoint(8, 88), size=wxSize(81, 13), style=0)

        self.edtAnoPubli = wxSpinCtrl(id=wxID_FRMCADLIVROSEDTANOPUBLI,
              initial=0, max=100, min=0, name=u'edtAnoPubli', parent=self,
              pos=wxPoint(8, 104), size=wxSize(92, 21), style=wxSP_ARROW_KEYS)
        self.edtAnoPubli.Enable(False)
        self.edtAnoPubli.SetRange(0, 9999)
        self.edtAnoPubli.SetValue(0)

        self.labEditora = wxStaticText(id=wxID_FRMCADLIVROSLABEDITORA,
              label=u'Editora: ', name=u'labEditora', parent=self,
              pos=wxPoint(104, 88), size=wxSize(39, 13), style=0)

        self.edtCodEditora = wxTextCtrl(id=wxID_FRMCADLIVROSEDTCODEDITORA,
              name=u'edtCodEditora', parent=self, pos=wxPoint(104, 104),
              size=wxSize(78, 21), style=0,
              validator=TextValidator(TextValidator.FILTER_NUMERIC), value=u'')
        self.edtCodEditora.Enable(False)
        EVT_KILL_FOCUS(self.edtCodEditora, self.OnEdtCodEditora_Killfocus)

        self.edtEditora = wxTextCtrl(id=wxID_FRMCADLIVROSEDTEDITORA,
              name=u'edtEditora', parent=self, pos=wxPoint(184, 104),
              size=wxSize(216, 21), style=0, value=u'')
        self.edtEditora.Enable(False)

        self.btnPEditora = wxButton(id=wxID_FRMCADLIVROSBTNPEDITORA,
              label=u'...', name=u'btnPEditora', parent=self, pos=wxPoint(400,
              104), size=wxSize(21, 21), style=0)
        self.btnPEditora.Enable(False)
        EVT_BUTTON(self.btnPEditora, self.btnPEditora.GetId(), 
          self.OnBtnPEditoraClick)

        self.labVolume = wxStaticText(id=wxID_FRMCADLIVROSLABVOLUME,
              label=u'Volume: ', name=u'labVolume', parent=self, pos=wxPoint(8,
              128), size=wxSize(41, 13), style=0)

        self.edtVolume = wxSpinCtrl(id=wxID_FRMCADLIVROSEDTVOLUME, initial=0,
              max=100, min=0, name=u'edtVolume', parent=self, pos=wxPoint(8,
              144), size=wxSize(92, 21), style=wxSP_ARROW_KEYS)
        self.edtVolume.Enable(False)
        self.edtVolume.SetRange(0, 9999)
        self.edtVolume.SetValue(0)

        self.labIdioma = wxStaticText(id=wxID_FRMCADLIVROSLABIDIOMA,
              label=u'Idioma: ', name=u'labIdioma', parent=self,
              pos=wxPoint(104, 128), size=wxSize(56, 13), style=0)

        self.cmbIdioma = wxChoice(choices=[], id=wxID_FRMCADLIVROSCMBIDIOMA,
              name=u'cmbIdioma', parent=self, pos=wxPoint(104, 144),
              size=wxSize(320, 21), style=0, validator=wxDefaultValidator)
        self.cmbIdioma.Enable(False)

        self.labNPaginas = wxStaticText(id=wxID_FRMCADLIVROSLABNPAGINAS,
              label=u'N\xba P\xe1ginas: ', name=u'labNPaginas', parent=self,
              pos=wxPoint(8, 168), size=wxSize(59, 13), style=0)

        self.edtNPaginas = wxSpinCtrl(id=wxID_FRMCADLIVROSEDTNPAGINAS,
              initial=0, max=100, min=0, name=u'edtNPaginas', parent=self,
              pos=wxPoint(8, 184), size=wxSize(92, 21), style=wxSP_ARROW_KEYS)
        self.edtNPaginas.Enable(False)
        self.edtNPaginas.SetRange(0, 9999)
        self.edtNPaginas.SetValue(0)

        self.labAssunto = wxStaticText(id=wxID_FRMCADLIVROSLABASSUNTO,
              label=u'Assunto: ', name=u'labAssunto', parent=self,
              pos=wxPoint(104, 168), size=wxSize(44, 13), style=0)

        self.edtCodAssunto = wxTextCtrl(id=wxID_FRMCADLIVROSEDTCODASSUNTO,
              name=u'edtCodAssunto', parent=self, pos=wxPoint(104, 184),
              size=wxSize(78, 21), style=0,
              validator=TextValidator(TextValidator.FILTER_NUMERIC), value=u'')
        self.edtCodAssunto.Enable(False)
        EVT_KILL_FOCUS(self.edtCodAssunto, self.OnEdtCodAssunto_Killfocus)

        self.edtAssunto = wxTextCtrl(id=wxID_FRMCADLIVROSEDTASSUNTO,
              name=u'edtAssunto', parent=self, pos=wxPoint(184, 184),
              size=wxSize(192, 21), style=0, value=u'')
        self.edtAssunto.Enable(False)

        self.btnAdAssuntos = wxButton(id=wxID_FRMCADLIVROSBTNADASSUNTOS,
              label=u'+', name=u'btnAdAssuntos', parent=self, pos=wxPoint(376,
              184), size=wxSize(21, 21), style=0)
        self.btnAdAssuntos.Enable(False)
        EVT_BUTTON(self.btnAdAssuntos, self.btnAdAssuntos.GetId(), 
          self.OnBtnAdAssuntosClick)

        self.btnPAssunto = wxButton(id=wxID_FRMCADLIVROSBTNPASSUNTO,
              label=u'...', name=u'btnPAssunto', parent=self, pos=wxPoint(400,
              184), size=wxSize(21, 21), style=0)
        self.btnPAssunto.Enable(False)
        EVT_BUTTON(self.btnPAssunto, self.btnPAssunto.GetId(), 
          self.OnBtnPAssuntoClick)

        self.lstAssuntos = wxListBox(choices=[],
              id=wxID_FRMCADLIVROSLSTASSUNTOS, name=u'lstAssuntos', parent=self,
              pos=wxPoint(104, 208), size=wxSize(320, 48), style=0,
              validator=wxDefaultValidator)
        self.lstAssuntos.Enable(False)
        EVT_LISTBOX_DCLICK(self.lstAssuntos, wxID_FRMCADLIVROSLSTASSUNTOS,
              self.OnLstAssuntos_Dblclk)

        self.labPreco = wxStaticText(id=wxID_FRMCADLIVROSLABPRECO,
              label=u'Pre\xe7o', name=u'labPreco', parent=self, pos=wxPoint(8,
              216), size=wxSize(40, 13), style=0)

        self.edtPreco = wxTextCtrl(id=wxID_FRMCADLIVROSEDTPRECO,
              name=u'edtPreco', parent=self, pos=wxPoint(7, 232),
              size=wxSize(88, 21), style=0, value=u'')
        self.edtPreco.Enable(False)
        EVT_KILL_FOCUS(self.edtPreco, self.OnEdtPreco_Killfocus)

        self.labQtdEstoque = wxStaticText(id=wxID_FRMCADLIVROSLABQTDESTOQUE,
              label=u'Qtd. Estoque: ', name=u'labQtdEstoque', parent=self,
              pos=wxPoint(6, 256), size=wxSize(68, 13), style=0)

        self.edtQtdEstoque = wxSpinCtrl(id=wxID_FRMCADLIVROSEDTQTDESTOQUE,
              initial=0, max=100, min=0, name=u'edtQtdEstoque', parent=self,
              pos=wxPoint(8, 272), size=wxSize(92, 21), style=wxSP_ARROW_KEYS)
        self.edtQtdEstoque.Enable(False)
        self.edtQtdEstoque.SetRange(1, 9999)
        self.edtQtdEstoque.SetValue(1)
        self.edtQtdEstoque.Show(True)

        self.labAutor = wxStaticText(id=wxID_FRMCADLIVROSLABAUTOR,
              label=u'Autor: ', name=u'labAutor', parent=self, pos=wxPoint(104,
              256), size=wxSize(31, 13), style=0)

        self.edtCodAutor = wxTextCtrl(id=wxID_FRMCADLIVROSEDTCODAUTOR,
              name=u'edtCodAutor', parent=self, pos=wxPoint(104, 272),
              size=wxSize(78, 21), style=0,
              validator=TextValidator(TextValidator.FILTER_NUMERIC), value=u'')
        self.edtCodAutor.Enable(False)
        EVT_KILL_FOCUS(self.edtCodAutor, self.OnEdtCodAutor_Killfocus)

        self.edtAutor = wxTextCtrl(id=wxID_FRMCADLIVROSEDTAUTOR,
              name=u'edtAutor', parent=self, pos=wxPoint(184, 272),
              size=wxSize(192, 21), style=0, value=u'')
        self.edtAutor.Enable(False)

        self.btnAdAutores = wxButton(id=wxID_FRMCADLIVROSBTNADAUTORES,
              label=u'+', name=u'btnAdAutores', parent=self, pos=wxPoint(376,
              272), size=wxSize(21, 21), style=0)
        self.btnAdAutores.Enable(False)
        EVT_BUTTON(self.btnAdAutores, self.btnAdAutores.GetId(), 
          self.OnBtnAdAutoresClick)

        self.btnPAutor = wxButton(id=wxID_FRMCADLIVROSBTNPAUTOR, label=u'...',
              name=u'btnPAutor', parent=self, pos=wxPoint(400, 272),
              size=wxSize(21, 21), style=0)
        self.btnPAutor.Enable(False)
        EVT_BUTTON(self.btnPAutor, self.btnPAutor.GetId(), 
          self.OnBtnPAutorClick)

        self.lstAutores = wxListBox(choices=[], id=wxID_FRMCADLIVROSLSTAUTORES,
              name=u'lstAutores', parent=self, pos=wxPoint(104, 296),
              size=wxSize(320, 48), style=0, validator=wxDefaultValidator)
        self.lstAutores.Enable(False)
        EVT_LISTBOX_DCLICK(self.lstAutores, wxID_FRMCADLIVROSLSTAUTORES,
              self.OnLstAutores_Dblclk)

        self.IniciaBotoes()
        self.btnPesquisar.SetDimensions(427, 8, 75, 25)
        self.btnAnterior.SetDimensions(427, 40, 75, 25)
        self.btnProximo.SetDimensions(427, 72, 75, 25)
        self.btnSalvar.SetDimensions(187, 352, 75, 25)
        self.btnExcluir.SetDimensions(267, 352, 75, 25)
        self.btnLimpar.SetDimensions(347, 352, 75, 25)
        self.btnFechar.SetDimensions(427, 352, 75, 25)
      
        self.FazLayout()
      
        self.edtCodigo.SetMaxLength(13)
        self.edtDescricao.SetMaxLength(50)
        self.edtCodEditora.SetMaxLength(5)
        self.edtPreco.SetMaxLength(7)
      
        self.AdicionaCombo()

        EVT_BUTTON(self.btnNovo, self.btnNovo.GetId(), self.OnBtnNovoClick)
        EVT_BUTTON(self.btnFechar, self.btnFechar.GetId(), 
          self.OnBtnFecharClick)
        EVT_BUTTON(self.btnPesquisar, self.btnPesquisar.GetId(),
              self.OnBtnPesquisarClick)
        EVT_BUTTON(self.btnAnterior, self.btnAnterior.GetId(),
              self.OnBtnAnteriorClick)
        EVT_BUTTON(self.btnProximo, self.btnProximo.GetId(),
              self.OnBtnProximoClick)
        EVT_BUTTON(self.btnSalvar, self.btnSalvar.GetId(),
              self.OnBtnSalvarClick)
        EVT_BUTTON(self.btnExcluir, self.btnExcluir.GetId(),
              self.OnBtnExcluirClick)
        EVT_BUTTON(self.btnLimpar, self.btnLimpar.GetId(),
              self.OnBtnLimparClick)

    def FazLayout(self):
      self.sizer_1 = wxBoxSizer(wxVERTICAL)
      self.sizer_2 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_3 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_4 = wxBoxSizer(wxVERTICAL)
      self.sizer_5 = wxBoxSizer(wxVERTICAL)
      self.sizer_21 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_20 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_37 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_36 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_35 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_34 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_33 = wxGridSizer(2, 1, 0, 0)
      self.sizer_19 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_32 = wxGridSizer(2, 1, 0, 0)
      self.sizer_18 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_31 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_30 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_29 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_28 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_27 = wxGridSizer(2, 1, 0, 0)
      self.sizer_17 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_26 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_25 = wxGridSizer(2, 1, 0, 0)
      self.sizer_6 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_24 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_6 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_5 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_4 = wxGridSizer(2, 1, 0, 0)
      self.sizer_8 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_9 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_8 = wxGridSizer(2, 1, 0, 0)
      self.sizer_7 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_7 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_7.Add(self.labCodigo, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_7.Add(self.edtCodigo, 0, 0, 0)
      self.sizer_7.Add(self.grid_sizer_7, 0, 0, 0)
      self.sizer_7.Add(self.btnNovo, 0, wxLEFT|wxALIGN_BOTTOM, 5)
      self.sizer_5.Add(self.sizer_7, 1, 0, 0)
      self.grid_sizer_8.Add(self.labDescricao, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_8.Add(self.edtDescricao, 0, 0, 0)
      self.sizer_8.Add(self.grid_sizer_8, 0, 0, 0)
      self.grid_sizer_9.Add(self.labEdicao, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_9.Add(self.edtEdicao, 0, 0, 0)
      self.sizer_8.Add(self.grid_sizer_9, 0, wxLEFT, 2)
      self.sizer_5.Add(self.sizer_8, 1, wxEXPAND, 0)
      self.grid_sizer_4.Add(self.labAnoPubli, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_4.Add(self.edtAnoPubli, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_4, 0, 0, 0)
      self.grid_sizer_5.Add(self.labEditora, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_5.Add(self.edtCodEditora, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_5, 0, wxLEFT, 4)
      self.grid_sizer_6.Add(20, 20, 0, 0, 0)
      self.grid_sizer_6.Add(self.edtEditora, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_6, 0, wxLEFT, 2)
      self.grid_sizer_24.Add(20, 20, 0, 0, 0)
      self.grid_sizer_24.Add(self.btnPEditora, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_24, 0, 0, 0)
      self.sizer_5.Add(self.sizer_6, 0, 0, 0)
      self.grid_sizer_25.Add(self.labVolume, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_25.Add(self.edtVolume, 0, 0, 0)
      self.sizer_17.Add(self.grid_sizer_25, 0, wxEXPAND, 0)
      self.grid_sizer_26.Add(self.labIdioma, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_26.Add(self.cmbIdioma, 0, 0, 0)
      self.sizer_17.Add(self.grid_sizer_26, 0, wxLEFT|wxEXPAND, 4)
      self.sizer_5.Add(self.sizer_17, 1, 0, 0)
      self.grid_sizer_27.Add(self.labNPaginas, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_27.Add(self.edtNPaginas, 0, 0, 0)
      self.sizer_18.Add(self.grid_sizer_27, 0, 0, 0)
      self.grid_sizer_28.Add(self.labAssunto, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_28.Add(self.edtCodAssunto, 0, 0, 0)
      self.sizer_18.Add(self.grid_sizer_28, 0, wxLEFT, 4)
      self.grid_sizer_29.Add(20, 20, 0, 0, 0)
      self.grid_sizer_29.Add(self.edtAssunto, 0, 0, 0)
      self.sizer_18.Add(self.grid_sizer_29, 0, wxLEFT, 2)
      self.grid_sizer_30.Add(20, 20, 0, 0, 0)
      self.grid_sizer_30.Add(self.btnAdAssuntos, 0, 0, 0)
      self.sizer_18.Add(self.grid_sizer_30, 0, 0, 0)
      self.grid_sizer_31.Add(20, 20, 0, 0, 0)
      self.grid_sizer_31.Add(self.btnPAssunto, 0, 0, 0)
      self.sizer_18.Add(self.grid_sizer_31, 0, 0, 0)
      self.sizer_5.Add(self.sizer_18, 1, 0, 0)
      self.grid_sizer_32.Add(self.labPreco, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_32.Add(self.edtPreco, 0, 0, 0)
      self.sizer_19.Add(self.grid_sizer_32, 0, 0, 0)
      self.sizer_19.Add(self.lstAssuntos, 0, wxLEFT, 4)
      self.sizer_5.Add(self.sizer_19, 1, 0, 0)
      self.grid_sizer_33.Add(self.labQtdEstoque, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_33.Add(self.edtQtdEstoque, 0, 0, 0)
      self.sizer_20.Add(self.grid_sizer_33, 0, 0, 0)
      self.grid_sizer_34.Add(self.labAutor, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_34.Add(self.edtCodAutor, 0, 0, 0)
      self.sizer_20.Add(self.grid_sizer_34, 0, 0, 0)
      self.grid_sizer_35.Add(20, 20, 0, 0, 0)
      self.grid_sizer_35.Add(self.edtAutor, 0, 0, 0)
      self.sizer_20.Add(self.grid_sizer_35, 0, wxLEFT, 2)
      self.grid_sizer_36.Add(20, 20, 0, 0, 0)
      self.grid_sizer_36.Add(self.btnAdAutores, 0, 0, 0)
      self.sizer_20.Add(self.grid_sizer_36, 0, 0, 0)
      self.grid_sizer_37.Add(20, 20, 0, 0, 0)
      self.grid_sizer_37.Add(self.btnPAutor, 0, 0, 0)
      self.sizer_20.Add(self.grid_sizer_37, 0, 0, 0)
      self.sizer_5.Add(self.sizer_20, 1, 0, 0)
      self.sizer_21.Add(92, 20, 0, 0, 0)
      self.sizer_21.Add(self.lstAutores, 0, 0, 0)
      self.sizer_5.Add(self.sizer_21, 0, 0, 0)
      self.sizer_3.Add(self.sizer_5, 0, 0, 0)
      self.sizer_4.Add(self.btnPesquisar, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_4.Add(self.btnAnterior, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_4.Add(self.btnProximo, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_3.Add(self.sizer_4, 1, 0, 0)
      self.sizer_1.Add(self.sizer_3, 1, wxALL|wxEXPAND, 4)
      self.sizer_2.Add(self.btnSalvar, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnExcluir, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnLimpar, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnFechar, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_1.Add(self.sizer_2, 0, 
        wxRIGHT|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4)
      self.SetAutoLayout(True)
      self.SetSizer(self.sizer_1)

    def __init__(self, parent):
        self._init_ctrls(parent)

    def ValidaDados(self, bTodosDados):
      if RotinasGlobais.Rotinas.ValidaCampo(
        self.edtCodigo.GetValue(), Resource.STR_ISBNNINF):
        return False
      if bTodosDados:
        if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtDescricao.GetValue(), Resource.STR_TITNINF):
          return False
        if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtEditora.GetValue(), Resource.STR_EDTNINF):
          return False
        if self.lstAssuntos.GetCount()==0:
          wxMessageBox(Resource.STR_ASSNINF, "Erro", wxOK | wxICON_ERROR)
          return False
        if self.lstAutores.GetCount()==0:
          wxMessageBox(Resource.STR_AUTNINF, "Erro", wxOK | wxICON_ERROR)
          return False
      return True

    def OnBtnFecharClick(self, event):
      self.GetParent().Close(True)
    
    def OnBtnNovoClick(self, event):
      self.btnNovoClick()
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(True)
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      if self.PesquisarDados(ConsultasSQL.ConsSQL.Livro('S', 
        self.edtCodigo.GetValue(),"","","","","","","","",""),                                  
        Resource.STR_LIVNENC):
        self.InformaLimpaDadosLocal(True)
        self.HabilitaDadosLocal(True)
      event.Skip()

    def OnBtnAnteriorClick(self, event):
      if self.registroAnterior():
        self.InformaLimpaDadosLocal(True)
      event.Skip()

    def OnBtnProximoClick(self, event):
      if self.registroProximo():
        self.InformaLimpaDadosLocal(True)
      event.Skip()

    def OnBtnSalvarClick(self, event):        
      self.nPos = self.cmbIdioma.GetSelection()
      self.sCodIdioma = self.slIdiomas.col[self.nPos]
    
      self.sSqlUpdate = ConsultasSQL.ConsSQL.Livro('U',
        self.edtCodigo.GetValue(), self.edtDescricao.GetValue(), 
        str(self.edtEdicao.GetValue()), str(self.edtAnoPubli.GetValue()), 
        str(self.edtVolume.GetValue()), self.edtCodEditora.GetValue(), 
        self.sCodIdioma, str(self.edtNPaginas.GetValue()),
        RotinasGlobais.Rotinas.VirgulaParaPonto(
        self.edtPreco.GetValue(),False), str(self.edtQtdEstoque.GetValue()))
    
      self.sSqlInsert = ConsultasSQL.ConsSQL.Livro('I', 
        self.edtCodigo.GetValue(), self.edtDescricao.GetValue(), 
        str(self.edtEdicao.GetValue()), str(self.edtAnoPubli.GetValue()), 
        str(self.edtVolume.GetValue()), self.edtCodEditora.GetValue(), 
        self.sCodIdioma, str(self.edtNPaginas.GetValue()),
        RotinasGlobais.Rotinas.VirgulaParaPonto(
        self.edtPreco.GetValue(),False), str(self.edtQtdEstoque.GetValue()))

      if self.SalvarDados(self.ValidaDados(True),
        ConsultasSQL.ConsSQL.Livro('S', self.edtCodigo.GetValue(),
        "","","","","","","","",""), self.sSqlUpdate, self.sSqlInsert, False):
        self.SalvaLista('A')
        self.SalvaLista('B')
        self.btnLimparClick()
        self.InformaLimpaDadosLocal(False)
        self.HabilitaDadosLocal(False)
      event.Skip()

    def OnBtnExcluirClick(self, event):
      if self.ExcluirDados(self.ValidaDados(False),
        ConsultasSQL.ConsSQL.Livro('D', self.edtCodigo.GetValue(),
        "","","","","","","","","")):
        self.InformaLimpaDadosLocal(False)
        self.HabilitaDadosLocal(False)
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.btnLimparClick()
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(False)
      event.Skip()

    def InformaLimpaDadosLocal(self, bInformar):
      Rotinas = RotinasGlobais.Rotinas
      if bInformar:
        self.edtEdicao.SetValue(
          int(self.lstRegistros.col[self.nLinhaRegistro][2]))
        self.edtAnoPubli.SetValue(
          int(self.lstRegistros.col[self.nLinhaRegistro][3]))
        self.edtVolume.SetValue(
          int(self.lstRegistros.col[self.nLinhaRegistro][4]))
        self.edtCodEditora.SetValue(
          self.lstRegistros.col[self.nLinhaRegistro][5])
        self.edtEditora.SetValue(self.lstRegistros.col[self.nLinhaRegistro][6])
        self.cmbIdioma.SetStringSelection(
          self.lstRegistros.col[self.nLinhaRegistro][8])
        self.edtNPaginas.SetValue(int(self.lstRegistros.col[self.nLinhaRegistro][9]))
        self.edtPreco.SetValue(Rotinas.VirgulaParaPonto(
          self.lstRegistros.col[self.nLinhaRegistro][10], True))
        self.edtQtdEstoque.SetValue(
          int(self.lstRegistros.col[self.nLinhaRegistro][11]))
        Rotinas.AdicionaValoresLista(ConsultasSQL.ConsSQL.LivroAss('S', 
          self.edtCodigo.GetValue(), ""), self.lstAssuntos, self.slAssuntos)
        Rotinas.AdicionaValoresLista(ConsultasSQL.ConsSQL.LivroAut('S',
          self.edtCodigo.GetValue(), ""), self.lstAutores, self.slAutores)
      else:
        self.edtEdicao.SetValue(1)
        self.edtAnoPubli.SetValue(int(Rotinas.substr(
          Rotinas.retDataHoraStr(True,False),7,4)))
        self.edtVolume.SetValue(1)
        self.edtCodEditora.Clear()
        self.edtEditora.Clear()
        self.cmbIdioma.SetSelection(0)    
        self.edtNPaginas.SetValue(1)
        self.edtPreco.SetValue("0,00")
        self.edtQtdEstoque.SetValue(1)
        self.edtCodAssunto.Clear()
        self.lstAssuntos.Clear()
        self.edtCodAutor.Clear()
        self.lstAutores.Clear()
        self.slAssuntos.col = []
        self.slAutores.col = []

    def HabilitaDadosLocal(self, bHabilita):
      self.edtEdicao.Enable(bHabilita)
      self.edtAnoPubli.Enable(bHabilita)
      self.edtVolume.Enable(bHabilita)
      self.edtCodEditora.Enable(bHabilita)
      self.btnPEditora.Enable(bHabilita)
      self.cmbIdioma.Enable(bHabilita)
      self.edtNPaginas.Enable(bHabilita)
      self.edtPreco.Enable(bHabilita)
      self.edtQtdEstoque.Enable(bHabilita)
      self.edtCodAssunto.Enable(bHabilita)
      self.btnPAssunto.Enable(bHabilita)
      self.btnAdAssuntos.Enable(bHabilita)
      self.lstAssuntos.Enable(bHabilita)
      self.edtCodAutor.Enable(bHabilita)
      self.btnPAutor.Enable(bHabilita)
      self.btnAdAutores.Enable(bHabilita)
      self.lstAutores.Enable(bHabilita)

    def OnEdtCodigo_Killfocus(self, event):
      if len(self.edtCodigo.GetValue()) > 0:
      	if RotinasGlobais.Rotinas.validaISBN(self.edtCodigo.GetValue())==False:
          wxMessageBox(Resource.STR_ISBNINV, "Erro", wxOK | wxICON_ERROR)
          self.edtCodigo.Clear()
          self.edtCodigo.SetFocus()
      event.Skip()

    def AdicionaCombo(self):
      Campos = LISTAMSTR()
      Rotinas = RotinasGlobais.Rotinas
      if Rotinas.ConsultaDadosLista(Rotinas.gConexao, Campos,
        ConsultasSQL.ConsSQL.Idioma('S',"","")):
        for nLinha in range(0, len(Campos.col)):
    	    self.slIdiomas.col.append(Campos.col[nLinha][0])
    	    self.cmbIdioma.Append(Campos.col[nLinha][1])

    def SalvaLista(self, sOpcao):
      Rotinas = RotinasGlobais.Rotinas
      ConsSQL = ConsultasSQL.ConsSQL
      self.sISBN = self.edtCodigo.GetValue()
      if sOpcao=='A':
        Rotinas.AtualizaDados(Rotinas.gConexao, 
        ConsSQL.LivroAss('D',self.sISBN,"")) 
    
        self.nQtd = len(self.slAssuntos.col)
        for nCont in range(0, self.nQtd):
          Rotinas.AtualizaDados(Rotinas.gConexao, 
            ConsSQL.LivroAss('I', self.sISBN, self.slAssuntos.col[nCont]))
      
      elif sOpcao=='B':
      	Rotinas.AtualizaDados(Rotinas.gConexao,
        ConsSQL.LivroAut('D',self.sISBN,""))
    
        self.nQtd = len(self.slAutores.col)
        for nCont in range(0, self.nQtd):
          Rotinas.AtualizaDados(Rotinas.gConexao, 
            ConsSQL.LivroAut('I', self.sISBN, self.slAutores.col[nCont]))

    def OnEdtCodEditora_Killfocus(self, event):
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCodEditora.GetValue()) > 0:
        sEditora = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
        ConsultasSQL.ConsSQL.Editora('S', self.edtCodEditora.GetValue(),""),
        Resource.STR_EDTNENC)
        if len(self.sEditora) > 0:
          self.edtEditora.SetValue(sEditora)
        else:
          self.edtCodEditora.Clear()
          self.edtCodEditora.SetFocus()
      else:
        self.edtEditora.Clear()

    def OnBtnPEditoraClick(self, event):
      fConEditoras = ConEditoras.create(self)
      fConEditoras.ShowModal()
      self.edtCodEditora.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCodEditora_Killfocus(event)
      event.Skip()

    def OnEdtPreco_Killfocus(self, event):
      Rotinas = RotinasGlobais.Rotinas
      if Rotinas.ValidaFloat(
            Rotinas.VirgulaParaPonto(self.edtPreco.GetValue(), False)):
        self.edtPreco.SetValue(
          Rotinas.VirgulaParaPonto(self.edtPreco.GetValue(), True))
      else:
        self.edtPreco.SetValue("0,01")
        self.edtPreco.SetFocus()

    def OnEdtCodAssunto_Killfocus(self, event):
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCodAssunto.GetValue()) > 0:
        sAssunto = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Assunto('S', self.edtCodAssunto.GetValue(),""),
          Resource.STR_ASSNENC)
        if len(sAssunto) > 0:
          self.edtAssunto.SetValue(sAssunto)
        else:
          self.edtCodAssunto.Clear()
          self.edtCodAssunto.SetFocus()
      else:
        self.edtAssunto.Clear()

    def OnBtnPAssuntoClick(self, event):
      fConAssuntos = ConAssuntos.create(self)
      fConAssuntos.ShowModal()
      self.edtCodAssunto.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCodAssunto_Killfocus(event)
      event.Skip()

    def OnEdtCodAutor_Killfocus(self, event):
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCodAutor.GetValue()) > 0:
        sAutor = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Autor('S',
          self.edtCodAutor.GetValue(),""),Resource.STR_AUTNENC)    
        if len(sAutor) > 0:
          self.edtAutor.SetValue(sAutor)
        else:
          self.edtCodAutor.Clear()
          self.edtCodAutor.SetFocus()
      else:
        self.edtAutor.Clear()

    def OnBtnPAutorClick(self, event):
      fConAutores = ConAutores.create(self)
      fConAutores.ShowModal()
      self.edtCodAutor.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCodAutor_Killfocus(event)
      event.Skip()

    def OnBtnAdAssuntosClick(self, event):
      RotinasGlobais.Rotinas.AdicionaItemLista(self.lstAssuntos, 
        self.slAssuntos, self.edtCodAssunto, self.edtAssunto)

    def OnLstAssuntos_Dblclk(self, event):
      RotinasGlobais.Rotinas.RemoveItemLista(self.lstAssuntos,self.slAssuntos)

    def OnBtnAdAutoresClick(self, event):
      RotinasGlobais.Rotinas.AdicionaItemLista(self.lstAutores, 
        self.slAutores, self.edtCodAutor, self.edtAutor)	

    def OnLstAutores_Dblclk(self, event):
      RotinasGlobais.Rotinas.RemoveItemLista(self.lstAutores,self.slAutores)

