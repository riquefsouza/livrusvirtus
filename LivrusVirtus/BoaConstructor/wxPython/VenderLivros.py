#Boa:FramePanel:frmVenderLivros

from wxPython.wx import *
from TextValidator import TextValidator
from Cadastros import frmCadastros
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource
from ListaStr import LISTAMSTR, LISTASTR
import fpformat
import ConClientes
import ConLivros

[wxID_FRMVENDERLIVROS, wxID_FRMVENDERLIVROSBTNADLIVROS, 
 wxID_FRMVENDERLIVROSBTNFECHAR, wxID_FRMVENDERLIVROSBTNLIMPAR, 
 wxID_FRMVENDERLIVROSBTNPCLIENTE, wxID_FRMVENDERLIVROSBTNPLIVRO, 
 wxID_FRMVENDERLIVROSBTNVENDER, wxID_FRMVENDERLIVROSEDTDTHRVENDA, 
 wxID_FRMVENDERLIVROSEDTISBN, wxID_FRMVENDERLIVROSEDTLIVRO, 
 wxID_FRMVENDERLIVROSEDTPRECOTOTAL, wxID_FRMVENDERLIVROSLABDTHRVENDA, 
 wxID_FRMVENDERLIVROSLABISBN, wxID_FRMVENDERLIVROSLABLIVRO, 
 wxID_FRMVENDERLIVROSLABLIVROS, wxID_FRMVENDERLIVROSLABPRECOTOTAL, 
 wxID_FRMVENDERLIVROSLSTLIVROS, 
] = map(lambda _init_ctrls: wxNewId(), range(17))

def create(parent):
    return frmVenderLivros(parent)

class frmVenderLivros(frmCadastros):
    slPrecos = LISTASTR()
    slISBNs = LISTASTR()
    slQtdEstoque = LISTASTR()
    nPrecoTotal = 0.0

    def _init_utils(self):
        pass

    def _init_ctrls(self, prnt):
        frmCadastros._init_ctrls(self, prnt, TextValidator.FILTER_NONE, False)
        self._init_utils()
        self.SetClientSize(wxSize(481, 309))

        self.btnNovo.Hide()
        self.labDtHrVenda = wxStaticText(id=wxID_FRMVENDERLIVROSLABDTHRVENDA,
              label=u'Data/Hora Venda: ', name=u'labDtHrVenda', parent=self,
              pos=wxPoint(8, 8), size=wxSize(91, 13), style=0)

        self.edtDtHrVenda = wxTextCtrl(id=wxID_FRMVENDERLIVROSEDTDTHRVENDA,
              name=u'edtDtHrVenda', parent=self, pos=wxPoint(8, 24),
              size=wxSize(128, 21), style=0, value=u'')
        self.edtDtHrVenda.Enable(False)

        self.labCodigo.SetLabel("CPF: ")  
        self.labCodigo.SetDimensions(8, 48, 48, 13) 
        self.edtCodigo.SetDimensions(8, 64, 128, 21)
        EVT_KILL_FOCUS(self.edtCodigo, self.OnEdtCodigo_Killfocus)

        self.labDescricao.SetLabel("Cliente: ")  
        self.labDescricao.SetDimensions(142, 48, 56, 13)  
        self.edtDescricao.SetDimensions(142, 64, 306, 21)
        self.edtDescricao.Enable(false)

        self.btnPCliente = wxButton(id=wxID_FRMVENDERLIVROSBTNPCLIENTE,
              label=u'...', name=u'btnPCliente', parent=self, pos=wxPoint(448,
              64), size=wxSize(21, 21), style=0)
        EVT_BUTTON(self.btnPCliente, self.btnPCliente.GetId(),
              self.OnBtnPClienteClick)

        self.labISBN = wxStaticText(id=wxID_FRMVENDERLIVROSLABISBN,
              label=u'ISBN: ', name=u'labISBN', parent=self, pos=wxPoint(8, 88),
              size=wxSize(48, 13), style=0)

        self.edtISBN = wxTextCtrl(id=wxID_FRMVENDERLIVROSEDTISBN,
              name=u'edtISBN', parent=self, pos=wxPoint(8, 104),
              size=wxSize(128, 21), style=0, value=u'')
        EVT_KILL_FOCUS(self.edtISBN, self.OnEdtISBN_Killfocus)

        self.labLivro = wxStaticText(id=wxID_FRMVENDERLIVROSLABLIVRO,
              label=u'Livro: ', name=u'labLivro', parent=self, pos=wxPoint(142,
              88), size=wxSize(40, 13), style=0)

        self.edtLivro = wxTextCtrl(id=wxID_FRMVENDERLIVROSEDTLIVRO,
              name=u'edtLivro', parent=self, pos=wxPoint(142, 104),
              size=wxSize(282, 21), style=0, value=u'')
        self.edtLivro.Enable(False)

        self.btnAdLivros = wxButton(id=wxID_FRMVENDERLIVROSBTNADLIVROS,
              label=u'+', name=u'btnAdLivros', parent=self, pos=wxPoint(424,
              104), size=wxSize(21, 21), style=0)
        EVT_BUTTON(self.btnAdLivros, self.btnAdLivros.GetId(),
              self.OnBtnAdLivrosClick)

        self.btnPLivro = wxButton(id=wxID_FRMVENDERLIVROSBTNPLIVRO,
              label=u'...', name=u'btnPLivro', parent=self, pos=wxPoint(448,
              104), size=wxSize(21, 21), style=0)
        EVT_BUTTON(self.btnPLivro, self.btnPLivro.GetId(),
              self.OnBtnPLivroClick)

        self.labLivros = wxStaticText(id=wxID_FRMVENDERLIVROSLABLIVROS,
              label=u'Livros para vender: ', name=u'labLivros', parent=self,
              pos=wxPoint(8, 128), size=wxSize(120, 13), style=0)

        self.lstLivros = wxListBox(choices=[], id=wxID_FRMVENDERLIVROSLSTLIVROS,
              name=u'lstLivros', parent=self, pos=wxPoint(8, 144),
              size=wxSize(464, 96), style=0, validator=wxDefaultValidator)
        EVT_LISTBOX_DCLICK(self.lstLivros, wxID_FRMVENDERLIVROSLSTLIVROS,
              self.OnLstLivros_Dblclk)

        self.labPrecoTotal = wxStaticText(id=wxID_FRMVENDERLIVROSLABPRECOTOTAL,
              label=u'Pre\xe7o Total: ', name=u'labPrecoTotal', parent=self,
              pos=wxPoint(280, 248), size=wxSize(61, 13), style=0)

        self.edtPrecoTotal = wxTextCtrl(id=wxID_FRMVENDERLIVROSEDTPRECOTOTAL,
              name=u'edtPrecoTotal', parent=self, pos=wxPoint(344, 246),
              size=wxSize(127, 21), style=0, value=u'')
        self.edtPrecoTotal.Enable(False)

        self.btnVender = wxButton(id=wxID_FRMVENDERLIVROSBTNVENDER,
              label=u'&Vender', name=u'btnVender', parent=self, pos=wxPoint(239,
              275), size=wxSize(75, 25), style=0)

        self.btnLimpar = wxButton(id=wxID_FRMVENDERLIVROSBTNLIMPAR,
              label=u'&Limpar', name=u'btnLimpar', parent=self, pos=wxPoint(319,
              275), size=wxSize(75, 25), style=0)

        self.btnFechar = wxButton(id=wxID_FRMVENDERLIVROSBTNFECHAR,
              label=u'&Fechar', name=u'btnFechar', parent=self, pos=wxPoint(399,
              275), size=wxSize(75, 25), style=0)

        EVT_BUTTON(self.btnVender, self.btnVender.GetId(),
              self.OnBtnVenderClick)
        EVT_BUTTON(self.btnLimpar, self.btnLimpar.GetId(),
              self.OnBtnLimparClick)
        EVT_BUTTON(self.btnFechar, self.btnFechar.GetId(),
              self.OnBtnFecharClick)

        self.FazLayout()

        self.edtCodigo.SetMaxLength(14)
        self.edtISBN.SetMaxLength(13)  
        self.LimpaDados()

    def __init__(self, parent):
        self._init_ctrls(parent)

    def FazLayout(self):
      self.sizer_1 = wxBoxSizer(wxVERTICAL)
      self.sizer_6 = wxBoxSizer(wxVERTICAL)
      self.sizer_8 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_7 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_5 = wxBoxSizer(wxVERTICAL)
      self.sizer_4 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_8 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_7 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_6 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_5 = wxGridSizer(2, 1, 0, 0)
      self.sizer_3 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_4 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_3 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_2 = wxGridSizer(2, 1, 0, 0)
      self.sizer_2 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_1 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_1.Add(self.labDtHrVenda, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_1.Add(self.edtDtHrVenda, 0, 0, 0)
      self.sizer_2.Add(self.grid_sizer_1, 0, wxLEFT, 2)
      self.sizer_2.Add(20, 20, 0, 0, 0)
      self.sizer_1.Add(self.sizer_2, 0, 0, 0)
      self.grid_sizer_2.Add(self.labCodigo, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_2.Add(self.edtCodigo, 0, 0, 0)
      self.sizer_3.Add(self.grid_sizer_2, 0, wxLEFT, 2)
      self.grid_sizer_3.Add(self.labDescricao, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_3.Add(self.edtDescricao, 0, 0, 0)
      self.sizer_3.Add(self.grid_sizer_3, 0, wxLEFT, 2)
      self.grid_sizer_4.Add(20, 20, 0, 0, 0)
      self.grid_sizer_4.Add(self.btnPCliente, 0, 0, 0)
      self.sizer_3.Add(self.grid_sizer_4, 0, 0, 0)
      self.sizer_1.Add(self.sizer_3, 0, 0, 0)
      self.grid_sizer_5.Add(self.labISBN, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_5.Add(self.edtISBN, 0, 0, 0)
      self.sizer_4.Add(self.grid_sizer_5, 0, wxLEFT, 2)
      self.grid_sizer_6.Add(self.labLivro, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_6.Add(self.edtLivro, 0, 0, 0)
      self.sizer_4.Add(self.grid_sizer_6, 0, wxLEFT, 2)
      self.grid_sizer_7.Add(20, 20, 0, 0, 0)
      self.grid_sizer_7.Add(self.btnAdLivros, 0, 0, 0)
      self.sizer_4.Add(self.grid_sizer_7, 1, wxEXPAND, 0)
      self.grid_sizer_8.Add(20, 20, 0, 0, 0)
      self.grid_sizer_8.Add(self.btnPLivro, 0, 0, 0)
      self.sizer_4.Add(self.grid_sizer_8, 0, 0, 0)
      self.sizer_1.Add(self.sizer_4, 0, 0, 0)
      self.sizer_5.Add(self.labLivros, 0, wxALIGN_BOTTOM, 0)
      self.sizer_5.Add(self.lstLivros, 1, wxALL|wxEXPAND, 1)
      self.sizer_1.Add(self.sizer_5, 1, wxEXPAND, 0)
      self.sizer_7.Add(self.labPrecoTotal, 0, wxALL, 2)
      self.sizer_7.Add(self.edtPrecoTotal, 0, wxALL, 2)
      self.sizer_6.Add(self.sizer_7, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_8.Add(self.btnVender,0,wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_8.Add(self.btnLimpar,0,wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_8.Add(self.btnFechar,0,wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_6.Add(self.sizer_8, 0, wxALL, 2)
      self.sizer_1.Add(self.sizer_6, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 0)
      self.SetAutoLayout(True)
      self.SetSizer(self.sizer_1)
      self.sizer_1.Fit(self)
      self.sizer_1.SetSizeHints(self)

    def LimpaDados(self):
      self.edtDtHrVenda.SetValue(
        RotinasGlobais.Rotinas.retDataHoraStr(True, True))  
      self.edtCodigo.Clear()
      self.edtDescricao.Clear()
      self.edtISBN.Clear()
      self.edtLivro.Clear()
      self.lstLivros.Clear()
      self.nPrecoTotal = 0
      self.slPrecos.col = []
      self.slISBNs.col = []
      self.slQtdEstoque.col = []
      self.edtPrecoTotal.SetValue("R$ 0,00")
      self.edtCodigo.SetFocus()

    def ValidaDados(self):
      if RotinasGlobais.Rotinas.ValidaCampo(
        self.edtCodigo.GetValue(), Resource.STR_CPFNINF):
        return False
      if self.lstLivros.GetCount()==0:
        wxMessageBox(Resource.STR_LIVVENNINF, "Erro", wxOK | wxICON_ERROR)
        return False
      return True

    def SalvaLista(self):
      Rotinas = RotinasGlobais.Rotinas
      ConsSQL = ConsultasSQL.ConsSQL
      nQtd = self.lstLivros.GetCount()
      sCPF = self.edtCodigo.GetValue()
      sPrecoTotal = fpformat.fix(self.nPrecoTotal,2)
      
      sDTHR = self.edtDtHrVenda.GetValue()
      sDataHora = Rotinas.ConverteDataHoraStr(sDTHR, True, 
        "%m/%d/%Y","%H:%M:%S")
      
      for nCont in range(0, nQtd):
        sISBN = self.slISBNs.col[nCont]    
        
        Rotinas.AtualizaDados(Rotinas.gConexao, ConsSQL.Venda('I',sISBN, sCPF, 
          sDataHora,Rotinas.VirgulaParaPonto(sPrecoTotal,False),""))
      
        nQtdEstoque = int(self.slQtdEstoque.col[nCont])
        if nQtdEstoque > 0:
          nQtdEstoque = nQtdEstoque - 1
        sQtdEstoque = str(nQtdEstoque)
        Rotinas.AtualizaDados(Rotinas.gConexao, ConsSQL.Venda('U',sISBN, 
          "","","", sQtdEstoque))
    
      return True

    def OnBtnFecharClick(self, event):
      self.GetParent().Close(True)

    def OnEdtCodigo_Killfocus(self, event):
      Rotinas = RotinasGlobais.Rotinas
      ConsSQL = ConsultasSQL.ConsSQL
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCodigo.GetValue()) > 0:
        if Rotinas.validaCPF(self.edtCodigo.GetValue()):
          sCliente = Rotinas.ConsultaCampoDesc(ConsCampo, ConsSQL.Cliente('S',
          self.edtCodigo.GetValue(),"","","","","","","","",""),
          Resource.STR_CLINENC) 
          if len(sCliente)==0:
            self.edtCodigo.Clear()
            self.edtCodigo.SetFocus()
          else:
            self.edtDescricao.SetValue(sCliente)
        else:
          wxMessageBox(Resource.STR_CPFINV, "Erro", wxOK | wxICON_ERROR)
          self.edtCodigo.Clear()
          self.edtCodigo.SetFocus()
      else:
        self.edtDescricao.Clear()
      
      event.Skip()

    def OnBtnPClienteClick(self, event):
      fConClientes = ConClientes.create(self)
      fConClientes.ShowModal()
      self.edtCodigo.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCodigo_Killfocus(event)
      event.Skip()

    def OnEdtISBN_Killfocus(self, event):
      Rotinas = RotinasGlobais.Rotinas
      ConsSQL = ConsultasSQL.ConsSQL
      ConsCampo = LISTAMSTR()
    
      if len(self.edtISBN.GetValue()) > 0:
        if Rotinas.validaISBN(self.edtISBN.GetValue()):
          sLivro = Rotinas.ConsultaCampoDesc(ConsCampo, ConsSQL.Livro('Q',
          self.edtISBN.GetValue(),"","","","","","","","",""),
          Resource.STR_LIVNENC)
          if len(sLivro)==0:
            self.edtISBN.Clear()
            self.edtISBN.SetFocus()
          else:
            self.edtLivro.SetValue(sLivro)
            nQtdEstoque = int(ConsCampo.col[0][3])
            if nQtdEstoque > 0:
              Rotinas.sPreco = ConsCampo.col[0][2]
              Rotinas.sQtdEstoque = ConsCampo.col[0][3]
            else:
              wxMessageBox(Resource.STR_LIVNEST, "Erro", wxOK | wxICON_ERROR)
        else:
          wxMessageBox(Resource.STR_ISBNINV, "Erro", wxOK | wxICON_ERROR)
          self.edtISBN.Clear()
          self.edtISBN.SetFocus()
      else:
        self.edtLivro.Clear()
      event.Skip()

    def OnBtnPLivroClick(self, event):
      fConLivros = ConLivros.create(self)
      fConLivros.ShowModal()
      self.edtISBN.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtISBN_Killfocus(event)
      event.Skip()

    def OnBtnAdLivrosClick(self, event):
      Rotinas = RotinasGlobais.Rotinas
      sISBN = self.edtISBN.GetValue()
      sEdtLivro = self.edtLivro.GetValue()
      if len(sISBN) > 0:
        sLivros = sISBN + " - " + sEdtLivro + " - R$ " + Rotinas.sPreco
        if self.lstLivros.FindString(sLivros) == -1:
          self.slISBNs.col.append(sISBN)
          self.slPrecos.col.append(Rotinas.sPreco)
          self.slQtdEstoque.col.append(Rotinas.sQtdEstoque)
          self.lstLivros.Append(sLivros)
          nPreco = float(Rotinas.sPreco)
          self.nPrecoTotal = self.nPrecoTotal + nPreco
        self.edtISBN.Clear()
        self.edtLivro.Clear()
        sPrecoTotal = fpformat.fix(self.nPrecoTotal, 2)
        self.edtPrecoTotal.SetValue(
          Rotinas.VirgulaParaPonto(sPrecoTotal,True))
      event.Skip()

    def OnLstLivros_Dblclk(self, event):
      if self.lstLivros.GetCount() > 0:
        nSelIndice = self.lstLivros.GetSelection()   
        if self.lstLivros.Selected(nSelIndice):
          nPreco = float(self.slPrecos.col[nSelIndice])
          self.nPrecoTotal = self.nPrecoTotal-nPreco     
          sPrecoTotal = fpformat.fix(self.nPrecoTotal, 2)
          self.edtPrecoTotal.SetValue(
            RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal, True))
          self.slISBNs.col.pop(nSelIndice)
          self.slPrecos.col.pop(nSelIndice)
          self.slQtdEstoque.col.pop(nSelIndice)
          self.lstLivros.Delete(nSelIndice)
      event.Skip()

    def OnBtnVenderClick(self, event):
      if self.ValidaDados():
        if self.SalvaLista():
          wxMessageBox(Resource.STR_VENRESUC, 
            Resource.STR_TITULO, wxOK | wxICON_INFORMATION)
          self.LimpaDados()
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.LimpaDados()
      event.Skip()

