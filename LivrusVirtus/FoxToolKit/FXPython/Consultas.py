from FXPy.fox import *
from ListaStr import LISTAMSTR
from resource import Resource
from RotinasGlobais import RotinasGlobais
import Principal

class frmConsultas(FXDialogBox):
  [ID_FRMCONSULTAS_BTNFECHAR, ID_FRMCONSULTAS_BTNLIMPAR, 
  ID_FRMCONSULTAS_BTNPESQUISAR, ID_FRMCONSULTAS_GRIDCONSULTA
  ] = range(400, 404)

  def __init__(self, owner, sTitulo):
    FXDialogBox.__init__(self, owner, sTitulo, DECOR_ALL, 
      0, 0, 385, 263, 0, 0, 0, 0, 4, 4)  
    self.Rotinas = RotinasGlobais.Rotinas
    self.setIcon(self.Rotinas.lerFigura(self.getApp(), "Livrus.bmp"))

    frame = FXVerticalFrame(self, LAYOUT_FILL_X | LAYOUT_FILL_Y)
    frame1 = FXVerticalFrame(frame, LAYOUT_FILL_X)
    frame2 = FXHorizontalFrame(frame1, LAYOUT_TOP)
    
    frame3 = FXVerticalFrame(frame2, LAYOUT_LEFT)
    frame3.setPadTop(0)
    frame3.setPadBottom(0)
  
    frame4 = FXVerticalFrame(frame2, LAYOUT_LEFT|LAYOUT_BOTTOM)
    frame4.setPadTop(0)
    frame4.setPadBottom(0)
  
    frameBotoesH = FXHorizontalFrame(frame, LAYOUT_BOTTOM|LAYOUT_FILL_X)
  
    self.labDescricao = FXLabel(frame3, "Descrição:", None, LAYOUT_LEFT, 
      8, 8, 51, 13)
    self.edtDescricao = FXTextField(frame3, 50, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 24, 257, 21, 3, 20)
    btnPesquisar = FXButton(frame4, "&Pesquisar", None, self, 
      frmConsultas.ID_FRMCONSULTAS_BTNPESQUISAR, BUTTON_DEFAULT|FRAME_RAISED|
      FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      272, 24, 75, 25, 15, 15, 3, 3 )

    self.gridConsulta = FXTable(frame, 2, 3, self, 
      frmConsultas.ID_FRMCONSULTAS_GRIDCONSULTA, TABLE_COL_SIZABLE|
      TABLE_ROW_SIZABLE|LAYOUT_FILL_X|LAYOUT_FILL_Y, 0, 56, 355, 125)
    self.Rotinas.IniciaLayoutGrid(self.gridConsulta, 2, 3)
  
    self.labRegistro = FXLabel(frameBotoesH, "Registro 0 de 0", None, 
      LAYOUT_LEFT, 8, 16, 144, 13)
    btnFechar = FXButton(frameBotoesH, "&Fechar", None, self, 
      FXDialogBox.ID_CANCEL, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 75, 13, 75, 25, 15, 15, 3, 3 )
    btnLimpar = FXButton(frameBotoesH, "&Limpar", None, self, 
      frmConsultas.ID_FRMCONSULTAS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 16, 13, 75, 25, 15, 15, 3, 3 )
  
    self.edtDescricao.setFocus()
    self.lstLinhas = LISTAMSTR()
    self.sSelecionado = ""
    self.nRegistro = 0
    self.Rotinas.sCodigoSelecionado = ""  
  
  def LimparDados(self):
    self.Rotinas.sCodigoSelecionado = ""
    self.labRegistro.setText("Registro 0 de 0")
    if self.gridConsulta.getNumRows() > 1:
      self.gridConsulta.removeRows(1, self.gridConsulta.getNumRows()-2)
      self.gridConsulta.setItemText(1, 0, "1")
      for nCol in range(1,self.gridConsulta.getNumCols()):
        self.gridConsulta.setItemText(1, nCol, "")          
    self.edtDescricao.setText("")
    self.edtDescricao.setFocus()  
  
  def PesquisarDados(self, sTextoSql, sMensagemErro, nQtdCol):
    self.Rotinas.sCodigoSelecionado = ""
    if self.Rotinas.ConsultaDadosLista(self.Rotinas.gConexao, 
      self.lstLinhas, sTextoSql):
      self.Rotinas.AdicionaLinhasGrid(self.gridConsulta, 
        self.lstLinhas, nQtdCol)
      self.setLabRegistros(1)
    else:
      showModalErrorBox(self, MBOX_OK, "Erro", sMensagemErro)      
  
  def setLabRegistros(self, nLinha):
    if nLinha >= 1:
      self.labRegistro.setText("Registro " + str(nLinha) + " de " +
        str(self.gridConsulta.getNumRows()-1))
      self.Rotinas.sCodigoSelecionado = self.gridConsulta.getItemText(nLinha, 1)
