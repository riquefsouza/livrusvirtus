#include "resource.h"
#include "Cadastros.h"
#include "Principal.h"

FXIMPLEMENT(CfrmCadastros,FXMDIChild,NULL,0)

CfrmCadastros::CfrmCadastros(FXMDIClient *clienteMDI, FXString sTitulo, 
  FXIcon *iconeMDI, FXMDIMenu *menuMDI, FXint nFiltroCodigo, 
  FXbool bIniciaBotoes): FXMDIChild(clienteMDI, sTitulo, 
  iconeMDI, menuMDI, MDI_NORMAL|MDI_TRACKING, 0, 0, 345, 180) {
  IniciaControles(nFiltroCodigo, bIniciaBotoes);
}

void CfrmCadastros::IniciaControles(FXint nFiltroCodigo, 
                                    FXbool bIniciaBotoes) {
  this->setIcon(new FXBMPIcon(getApp(),Livrus));

  frame = new FXVerticalFrame(this, LAYOUT_FILL_X | LAYOUT_FILL_Y);

  frame1 = new FXVerticalFrame(frame, LAYOUT_FILL_X);
  frame2 = new FXHorizontalFrame(frame1, LAYOUT_TOP);
  
  frame3 = new FXVerticalFrame(frame2, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame4 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame5 = new FXVerticalFrame(frame4, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame6 = new FXVerticalFrame(frame4, LAYOUT_LEFT|LAYOUT_BOTTOM, 0,0,0,0,0,0,0,0);

  frame7 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame8 = new FXVerticalFrame(frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  this->labCodigo = new FXLabel(frame5, "Código:", NULL, LAYOUT_LEFT, 
    8, 8, 36, 13);
  this->edtCodigo = new FXTextField(frame5, 10, NULL, ID_FRMCADASTROS_EDTCODIGO, 
    TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    nFiltroCodigo, 8, 24, 121, 21, 3, 20);
  this->btnNovo = new FXButton(frame6, "&Novo", NULL, this, 
    ID_FRMCADASTROS_BTNNOVO, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_BOTTOM, 144, 24, 75, 25, 15, 15, 3, 3 );
  this->labDescricao = new FXLabel(frame8, "Descrição:", NULL, LAYOUT_LEFT, 
    8, 48, 51, 13);
  this->edtDescricao = new FXTextField(frame8, 30, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 64, 217, 21, 3, 20);
  this->edtDescricao->disable();

  if (bIniciaBotoes) 
    IniciaBotoes();

  nLinhaRegistro = 0;
}

// Necessário por causa da tabulação dos campos
void CfrmCadastros::IniciaBotoes() {
  frameBotoesV = new FXVerticalFrame(frame2,
    LAYOUT_TOP|LAYOUT_RIGHT, 0,0,0,0,18,0,0,0);
  this->btnPesquisar = new FXButton(frameBotoesV, "&Pesquisar", NULL, this, 
    ID_FRMCADASTROS_BTNPESQUISAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 248, 8, 75, 25, 10, 10, 3, 3 );
  this->btnAnterior = new FXButton(frameBotoesV, "&Anterior", NULL, this, 
    ID_FRMCADASTROS_BTNANTERIOR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 248, 40, 75, 25, 15, 15, 3, 3 );
  this->btnProximo = new FXButton(frameBotoesV, "Próxi&mo", NULL, this, 
    ID_FRMCADASTROS_BTNPROXIMO, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 248, 72, 75, 25, 15, 15, 3, 3 );

  frameBotoesH = new FXHorizontalFrame(frame, 
    LAYOUT_BOTTOM|LAYOUT_RIGHT);
  this->btnSalvar = new FXButton(frameBotoesH, "&Salvar", NULL, this, 
    ID_FRMCADASTROS_BTNSALVAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT,8, 104, 75, 25, 15, 15, 3, 3 );
  this->btnExcluir = new FXButton(frameBotoesH, "&Excluir", NULL, this, 
    ID_FRMCADASTROS_BTNEXCLUIR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 88, 104, 75, 25, 15, 15, 3, 3 );
  this->btnLimpar = new FXButton(frameBotoesH, "&Limpar", NULL, this, 
    ID_FRMCADASTROS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT,168, 104, 75, 25, 15, 15, 3, 3 );
  this->btnFechar = new FXButton(frameBotoesH, "&Fechar", NULL, this, 
    ID_FRMCADASTROS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 248, 104, 75, 25, 15, 15, 3, 3 );

  btnLimparClick();
}

CfrmCadastros::~CfrmCadastros(){

}

void CfrmCadastros::InformaLimpaDados(FXbool bInformar)
{ 
  if (bInformar) {
    edtCodigo->setText(lstRegistros.col[0][nLinhaRegistro]);
    edtDescricao->setText(lstRegistros.col[1][nLinhaRegistro]);
  } else {
    edtCodigo->setText("");
    edtDescricao->setText("");
    edtCodigo->enable();
    edtCodigo->setFocus();
  }
} 

void CfrmCadastros::HabilitaDados(FXbool bHabilita)
{
  if (bHabilita)
    edtDescricao->enable();
  else
    edtDescricao->disable();
}

void CfrmCadastros::btnNovoClick()
{ 
  btnSalvar->enable();
  btnExcluir->disable();
  btnPesquisar->disable();
  btnAnterior->disable();
  btnProximo->disable();
  btnNovo->disable();
  
  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(true);	
}

void CfrmCadastros::NovoDado(FXString sTextoSql)
{ 
  LISTAMSTR lstRegs;

  if (Rotinas->ConsultaDadosLista(gConexao, &lstRegs, sTextoSql)) {
    edtCodigo->setText(lstRegs.col[0][0]);

    edtCodigo->disable();
    edtDescricao->setFocus();
  }
}

void CfrmCadastros::btnLimparClick() 
{
  nLinhaRegistro = 0;
  btnSalvar->disable();
  btnExcluir->disable();
  btnPesquisar->enable();
  btnAnterior->disable();
  btnProximo->disable();
  btnNovo->enable();

  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(false);	
}

FXbool CfrmCadastros::ExcluirDados(FXbool bValidaDados, FXString sTextoSql)
{
   if (bValidaDados) {
     if (FXMessageBox::question(this, MBOX_YES_NO, "Confirme",
        STR_CERTEXCL) == MBOX_CLICKED_YES) {
        if (Rotinas->AtualizaDados(gConexao, sTextoSql)) {
           btnLimparClick();
           return true;
        }
  	 }
   }
  return false;
}

FXbool CfrmCadastros::PesquisarDados(FXString sTextoSql, FXString sMensagemErro)
{  
	if (edtCodigo->getText().length() == 0) {
    btnAnterior->enable();
    btnProximo->enable();
	}

  if (Rotinas->ConsultaDadosLista(gConexao, &lstRegistros, sTextoSql)) {
     InformaLimpaDados(true);
     HabilitaDados(true);	

     btnSalvar->enable();
     btnExcluir->enable();
     btnPesquisar->disable();
     return true;
	} else
    FXMessageBox::error(this, MBOX_OK, "Erro", sMensagemErro.text());

  return false;
}

FXbool CfrmCadastros::registroAnterior()
{
	if (nLinhaRegistro > 0) {
    nLinhaRegistro--;
    InformaLimpaDados(true);
    return true;
	} else
    return false;
}

FXbool CfrmCadastros::registroProximo()
{
	if (nLinhaRegistro < abs(lstRegistros.col[0].no()-1)) {
    nLinhaRegistro++;
    InformaLimpaDados(true);
    return true;
	} else
    return false;
}

FXbool CfrmCadastros::SalvarDados(FXbool bValidaDados, FXString sTextoSql, 
  FXString sTextoUpdate, FXString sTextoInsert, FXbool bLimparDados)
{
FXString sArquiva;

	if (bValidaDados) {    
	   if (Rotinas->ConsultaDados(gConexao,sTextoSql))
         sArquiva = sTextoUpdate;
     else
  	     sArquiva = sTextoInsert;	  	     

     if (Rotinas->AtualizaDados(gConexao, sArquiva)) {
  	   if (bLimparDados)
         btnLimparClick();
       return true;
     }
	}
  return false;
}

