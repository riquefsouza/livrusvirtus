#Boa:FramePanel:frmConVendas

from wxPython.wx import *
from wxPython.grid import *
from TextValidator import TextValidator
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource
from ListaStr import LISTAMSTR, LISTASTR
import fpformat
import ConClientes
import ConLivros

[wxID_FRMCONVENDAS, wxID_FRMCONVENDASBTNFECHAR, wxID_FRMCONVENDASBTNLIMPAR, 
 wxID_FRMCONVENDASBTNPCLIENTE, wxID_FRMCONVENDASBTNPESQUISAR, 
 wxID_FRMCONVENDASBTNPLIVRO, wxID_FRMCONVENDASEDTCLIENTE, 
 wxID_FRMCONVENDASEDTCPF, wxID_FRMCONVENDASEDTDTHRVENDA, 
 wxID_FRMCONVENDASEDTISBN, wxID_FRMCONVENDASEDTLIVRO, 
 wxID_FRMCONVENDASEDTPRECOTOTAL, wxID_FRMCONVENDASGRIDVENDAS, 
 wxID_FRMCONVENDASLABCLIENTE, wxID_FRMCONVENDASLABCPF, 
 wxID_FRMCONVENDASLABDTHRVENDA, wxID_FRMCONVENDASLABISBN, 
 wxID_FRMCONVENDASLABLIVRO, wxID_FRMCONVENDASLABPRECOTOTAL, 
 wxID_FRMCONVENDASLABREGISTRO, 
] = map(lambda _init_ctrls: wxNewId(), range(20))

def create(parent):
    return frmConVendas(parent)

class frmConVendas(wxPanel):
    lstLinhas = LISTAMSTR()

    def _init_ctrls(self, prnt):
        # generated method, don't edit
        wxPanel.__init__(self, id=wxID_FRMCONVENDAS, name=u'frmConVendas',
              parent=prnt, pos=wxPoint(379, 218), size=wxSize(480, 310),
              style=wxTAB_TRAVERSAL)
        self.SetClientSize(wxSize(475, 306))
        EVT_CLOSE(self, self.OnFrmConVendasClose)

        self.labDtHrVenda = wxStaticText(id=wxID_FRMCONVENDASLABDTHRVENDA,
              label=u'Data/Hora Venda: ', name=u'labDtHrVenda', parent=self,
              pos=wxPoint(8, 8), size=wxSize(91, 13), style=0)

        self.edtDtHrVenda = wxTextCtrl(id=wxID_FRMCONVENDASEDTDTHRVENDA,
              name=u'edtDtHrVenda', parent=self, pos=wxPoint(8, 24),
              size=wxSize(128, 21), style=0, value=u'')
        EVT_KILL_FOCUS(self.edtDtHrVenda, self.OnEdtDtHrVendaKillFocus)

        self.btnPesquisar = wxButton(id=wxID_FRMCONVENDASBTNPESQUISAR,
              label=u'&Pesquisar', name=u'btnPesquisar', parent=self,
              pos=wxPoint(144, 22), size=wxSize(75, 25), style=0)
        EVT_BUTTON(self.btnPesquisar, wxID_FRMCONVENDASBTNPESQUISAR,
              self.OnBtnPesquisarButton)

        self.labISBN = wxStaticText(id=wxID_FRMCONVENDASLABISBN,
              label=u'ISBN: ', name=u'labISBN', parent=self, pos=wxPoint(8, 88),
              size=wxSize(31, 13), style=0)

        self.edtISBN = wxTextCtrl(id=wxID_FRMCONVENDASEDTISBN, name=u'edtISBN',
              parent=self, pos=wxPoint(8, 104), size=wxSize(128, 21), style=0,
              value=u'')
        EVT_KILL_FOCUS(self.edtISBN, self.OnEdtISBNKillFocus)

        self.labLivro = wxStaticText(id=wxID_FRMCONVENDASLABLIVRO,
              label=u'Livro: ', name=u'labLivro', parent=self, pos=wxPoint(142,
              88), size=wxSize(29, 13), style=0)

        self.edtLivro = wxTextCtrl(id=wxID_FRMCONVENDASEDTLIVRO,
              name=u'edtLivro', parent=self, pos=wxPoint(142, 104),
              size=wxSize(306, 21), style=0, value=u'')
        self.edtLivro.Enable(False)

        self.btnPLivro = wxButton(id=wxID_FRMCONVENDASBTNPLIVRO, label=u'...',
              name=u'btnPLivro', parent=self, pos=wxPoint(448, 104),
              size=wxSize(21, 21), style=0)
        EVT_BUTTON(self.btnPLivro, wxID_FRMCONVENDASBTNPLIVRO,
              self.OnBtnPLivroButton)

        self.labCPF = wxStaticText(id=wxID_FRMCONVENDASLABCPF, label=u'CPF:',
              name=u'labCPF', parent=self, pos=wxPoint(8, 48), size=wxSize(23,
              13), style=0)

        self.edtCPF = wxTextCtrl(id=wxID_FRMCONVENDASEDTCPF, name=u'edtCPF',
              parent=self, pos=wxPoint(8, 64), size=wxSize(128, 21), style=0,
              value=u'')
        EVT_KILL_FOCUS(self.edtCPF, self.OnEdtCPFKillFocus)

        self.labCliente = wxStaticText(id=wxID_FRMCONVENDASLABCLIENTE,
              label=u'Cliente:', name=u'labCliente', parent=self,
              pos=wxPoint(142, 48), size=wxSize(35, 13), style=0)

        self.edtCliente = wxTextCtrl(id=wxID_FRMCONVENDASEDTCLIENTE,
              name=u'edtCliente', parent=self, pos=wxPoint(142, 64),
              size=wxSize(306, 21), style=0, value=u'')
        self.edtCliente.Enable(False)

        self.btnPCliente = wxButton(id=wxID_FRMCONVENDASBTNPCLIENTE,
              label=u'...', name=u'btnPCliente', parent=self, pos=wxPoint(448,
              64), size=wxSize(21, 21), style=0)
        EVT_BUTTON(self.btnPCliente, wxID_FRMCONVENDASBTNPCLIENTE,
              self.OnBtnPClienteButton)

        self.gridVendas = wxGrid(id=wxID_FRMCONVENDASGRIDVENDAS,
              name=u'gridVendas', parent=self, pos=wxPoint(0, 136),
              size=wxSize(472, 104), style=wxSUNKEN_BORDER)
        self.gridVendas.CreateGrid(1, 6, wxGrid.wxGridSelectRows)
        self.gridVendas.HideCellEditControl()
        self.gridVendas.SetColLabelSize(21)
        EVT_GRID_SELECT_CELL(self.gridVendas, self.OnGridVendasGridSelectCell)
        EVT_GRID_LABEL_LEFT_CLICK(self.gridVendas,
              self.OnGridVendasGridLabelLeftClick)

        self.labRegistro = wxStaticText(id=wxID_FRMCONVENDASLABREGISTRO,
              label=u'Registro 0 de 0 ', name=u'labRegistro', parent=self,
              pos=wxPoint(8, 248), size=wxSize(144, 13), style=0)

        self.labPrecoTotal = wxStaticText(id=wxID_FRMCONVENDASLABPRECOTOTAL,
              label=u'Pre\xe7o Total: ', name=u'labPrecoTotal', parent=self,
              pos=wxPoint(280, 248), size=wxSize(61, 13), style=0)

        self.edtPrecoTotal = wxTextCtrl(id=wxID_FRMCONVENDASEDTPRECOTOTAL,
              name=u'edtPrecoTotal', parent=self, pos=wxPoint(344, 246),
              size=wxSize(127, 21), style=0, value=u'')
        self.edtPrecoTotal.Enable(False)

        self.btnLimpar = wxButton(id=wxID_FRMCONVENDASBTNLIMPAR,
              label=u'&Limpar', name=u'btnLimpar', parent=self, pos=wxPoint(312,
              272), size=wxSize(75, 25), style=0)
        EVT_BUTTON(self.btnLimpar, wxID_FRMCONVENDASBTNLIMPAR,
              self.OnBtnLimparButton)

        self.btnFechar = wxButton(id=wxID_FRMCONVENDASBTNFECHAR,
              label=u'&Fechar', name=u'btnFechar', parent=self, pos=wxPoint(392,
              272), size=wxSize(75, 25), style=0)
        EVT_BUTTON(self.btnFechar, wxID_FRMCONVENDASBTNFECHAR,
              self.OnBtnFecharButton)

        self.FazLayout()
      
        nLargura = ( 120, 100, 220, 100, 280, 80 )      
        sRotulos = ( "Data/Hora Venda", "CPF", "Cliente", 
         "ISBN", "Livro", "Pre\xe7o" )
      
        RotinasGlobais.Rotinas.AdicionaColunasGrid(
          self.gridVendas, 0, 6, nLargura, sRotulos)
        self.gridVendas.EnableEditing(False)
        self.edtCPF.SetMaxLength(14)
        self.edtISBN.SetMaxLength(13)  
        self.edtPrecoTotal.SetValue("R$ 0,00")
        self.edtDtHrVenda.SetValue(
          RotinasGlobais.Rotinas.retDataHoraStr(true,true))
        self.edtDtHrVenda.SetFocus()

    def FazLayout(self):
      self.sizer_1 = wxBoxSizer(wxVERTICAL)
      self.sizer_6 = wxBoxSizer(wxVERTICAL)
      self.sizer_22 = wxGridSizer(1, 2, 0, 0)
      self.sizer_23 = wxBoxSizer(wxVERTICAL)
      self.sizer_8 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_7 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_24 = wxBoxSizer(wxVERTICAL)
      self.sizer_4 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_8 = wxGridSizer(2, 1, 0, 0)
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
      self.sizer_2.Add(self.btnPesquisar, 0, wxLEFT|wxTOP|wxALIGN_BOTTOM, 10)
      self.sizer_1.Add(self.sizer_2, 0, 0, 0)
      self.grid_sizer_2.Add(self.labCPF, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_2.Add(self.edtCPF, 0, 0, 0)
      self.sizer_3.Add(self.grid_sizer_2, 0, wxLEFT, 2)
      self.grid_sizer_3.Add(self.labCliente, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_3.Add(self.edtCliente, 0, 0, 0)
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
      self.grid_sizer_8.Add(20, 20, 0, 0, 0)
      self.grid_sizer_8.Add(self.btnPLivro, 0, 0, 0)
      self.sizer_4.Add(self.grid_sizer_8, 0, 0, 0)
      self.sizer_1.Add(self.sizer_4, 0, 0, 0)
      self.sizer_1.Add(self.gridVendas, 1, wxALL|wxEXPAND, 2)
      self.sizer_24.Add(self.labRegistro, 0, wxALL, 4)
      self.sizer_24.Add(20, 20, 0, 0, 0)
      self.sizer_22.Add(self.sizer_24, 0, 0, 0)
      self.sizer_7.Add(self.labPrecoTotal, 0, wxALL, 2)
      self.sizer_7.Add(self.edtPrecoTotal, 0, wxALL, 2)
      self.sizer_23.Add(self.sizer_7, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_8.Add(self.btnLimpar,0,wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_8.Add(self.btnFechar,0,wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_23.Add(self.sizer_8, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_22.Add(self.sizer_23, 1, wxALIGN_RIGHT|wxALIGN_BOTTOM, 0)
      self.sizer_6.Add(self.sizer_22, 0, wxEXPAND, 0)
      self.sizer_1.Add(self.sizer_6, 0, wxEXPAND, 0)
      self.SetAutoLayout(True)
      self.SetSizer(self.sizer_1)
      self.sizer_1.Fit(self)
      self.sizer_1.SetSizeHints(self)

    def __init__(self, parent):
        self._init_ctrls(parent)

    def ConsVenda(self, sOpcao):
      sret = ''
      ConsSQL = ConsultasSQL.ConsSQL
      if len(self.edtDtHrVenda.GetValue()) > 0:
        sDataHora = RotinasGlobais.Rotinas.ConverteDataHoraStr(
          self.edtDtHrVenda.GetValue(), True, "%m/%d/%Y","%H:%M:%S")
      else:
        sDataHora = ""
    
      sISBN = self.edtISBN.GetValue()
      sCPF = self.edtCPF.GetValue()
    
      if sOpcao=='L':
        sret = ConsSQL.Venda('S',"ZERO","","","","")
      else:
        sret = ConsSQL.Venda(sOpcao, sISBN, sCPF, sDataHora, "", "")
      
      return sret

    def OnEdtDtHrVendaKillFocus(self, event):
      if len(self.edtDtHrVenda.GetValue()) > 0:
        if not RotinasGlobais.Rotinas.validaDataHora(
          self.edtDtHrVenda.GetValue(), False):
          wxMessageBox(Resource.STR_DTHRINV, "Erro", wxOK | wxICON_ERROR)
          self.edtDtHrVenda.SetFocus()
      event.Skip()

    def OnBtnPesquisarButton(self, event):
      Rotinas = RotinasGlobais.Rotinas
      ConsTotal = LISTAMSTR() 
    
      if Rotinas.ConsultaDadosLista(Rotinas.gConexao, 
        self.lstLinhas, self.ConsVenda('S')):
        Rotinas.AdicionaLinhasGrid(self.gridVendas, self.lstLinhas, 6)
    
        if Rotinas.ConsultaDadosLista(Rotinas.gConexao, ConsTotal, 
           self.ConsVenda('P')):
          if len(ConsTotal.col) > 0:
            nTemp = float(ConsTotal.col[0][0])
            sPrecoTotal = fpformat.fix(nTemp, 2)
            self.edtPrecoTotal.SetValue(sPrecoTotal)    
      else:
        wxMessageBox(Resource.STR_VENNENC, "Erro", wxOK | wxICON_ERROR)
      event.Skip()

    def OnEdtISBNKillFocus(self, event):
      Rotinas = RotinasGlobais.Rotinas
      ConsCampo = LISTAMSTR()
      if len(self.edtISBN.GetValue()) > 0:
        if Rotinas.validaISBN(self.edtISBN.GetValue()):
          sLivro = Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Livro('Q', self.edtISBN.GetValue(),
          "","","","","","","","",""),Resource.STR_LIVNENC)
          if len(sLivro)==0:
            self.edtISBN.Clear()
            self.edtISBN.SetFocus()
          else:
            self.edtLivro.SetValue(sLivro)
            nQtdEstoque= int(ConsCampo.col[0][3])
            if nQtdEstoque > 0:
             Rotinas.sPreco = ConsCampo.col[0][2]
            else:
             wxMessageBox(Resource.STR_LIVNEST, "Erro", wxOK | wxICON_ERROR)
        else:
          wxMessageBox(Resource.STR_ISBNINV, "Erro", wxOK | wxICON_ERROR)
          self.edtISBN.Clear()
          self.edtISBN.SetFocus()
      else:
         self.edtLivro.Clear()
      event.Skip()

    def OnBtnPLivroButton(self, event):
      fConLivros = ConLivros.create(self)
      fConLivros.ShowModal()
      self.edtISBN.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtISBNKillFocus(event)
      event.Skip()

    def OnEdtCPFKillFocus(self, event):
      Rotinas = RotinasGlobais.Rotinas
      ConsSQL = ConsultasSQL.ConsSQL
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCPF.GetValue()) > 0:
        if Rotinas.validaCPF(self.edtCPF.GetValue()):
          sCliente = Rotinas.ConsultaCampoDesc(ConsCampo, ConsSQL.Cliente('S',
          self.edtCPF.GetValue(),"","","","","","","","",""),
          Resource.STR_CLINENC) 
          if len(sCliente)==0:
            self.edtCPF.Clear()
            self.edtCPF.SetFocus()
          else:
            self.edtCliente.SetValue(sCliente)
        else:
          wxMessageBox(Resource.STR_CPFINV, "Erro", wxOK | wxICON_ERROR)
          self.edtCPF.Clear()
          self.edtCPF.SetFocus()
      else:
        self.edtCliente.Clear()
      
      event.Skip()

    def OnBtnPClienteButton(self, event):
      fConClientes = ConClientes.create(self)
      fConClientes.ShowModal()
      self.edtCPF.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCPFKillFocus(event)
      event.Skip()

    def setLabRegistros(self, nLinha):
      if nLinha >= 0:
        self.labRegistro.SetLabel("Registro " + str(nLinha+1) + " de " +\
          str(self.gridVendas.GetNumberRows()))

    def OnGridVendasGridSelectCell(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()

    def OnGridVendasGridLabelLeftClick(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()

    def OnBtnLimparButton(self, event):
      self.edtCPF.Clear()
      self.edtCliente.Clear()
      self.edtISBN.Clear()
      self.edtLivro.Clear()
      self.gridVendas.ClearGrid()
      self.gridVendas.DeleteRows(0, self.gridVendas.GetNumberRows()-1,True)
      self.edtPrecoTotal.SetValue("R$ 0,00")
      self.edtDtHrVenda.SetValue(
        RotinasGlobais.Rotinas.retDataHoraStr(True,True))
      self.labRegistro.SetLabel("Registro 0 de 0")
      self.edtDtHrVenda.SetFocus()
      event.Skip()

    def OnBtnFecharButton(self, event):
      self.GetParent().Close(True)

    def OnFrmConVendasClose(self, event):
      self.Destroy()
