use Wx 0.15 qw[:allclasses];
use strict;
package frmFilha;

use Wx qw[:everything];
use base qw(Wx::MDIChildFrame);
use strict;
use Wx::Event qw(EVT_MENU EVT_CLOSE);
require resource;
require Principal;
require CadAssuntos;
require CadAutores;
require CadEditoras;
require CadEnderecos;
require CadIdiomas;
require CadPaises;
require CadProfissoes;
require CadClientes;
require CadLivros;
require VenderLivros;
require ConVendas;
require AlterarSenha;

sub new {
	my( $self, $parent, $nTelaAtiva ) = @_;
	$parent = undef              unless defined $parent;	

	$self = $self->SUPER::new( $parent, -1, "", wxPOINT(0,0), 
    wxSIZE(342, 219), wxDEFAULT_FRAME_STYLE, "" );

	$self->SetTitle("Cadastro de");
	my $icon = Wx::Icon->new();
	$icon->CopyFromBitmap(Wx::Bitmap->new("xpms\\livrus.xpm", wxBITMAP_TYPE_ANY));
	$self->SetIcon($icon);
	$self->SetClientSize(330, 136);
	$self->SetBackgroundColour(Wx::SystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
  EVT_CLOSE( $self, \&OnClose );

  $self->{nLocalTelaAtiva} = $nTelaAtiva;

  if ($nTelaAtiva == $Resource::FRMCADASSUNTOS) {
    frmCadAssuntos->new($self);
    $self->SetTitle($Resource::STR_CADASSUNTO);
  } if ($nTelaAtiva == $Resource::FRMCADAUTORES) {
    frmCadAutores->new($self);
    $self->SetTitle($Resource::STR_CADAUTOR);
  } if ($nTelaAtiva == $Resource::FRMCADEDITORAS) {
    frmCadEditoras->new($self);
    $self->SetTitle($Resource::STR_CADEDITORA);
  } if ($nTelaAtiva == $Resource::FRMCADENDERECOS) {
    frmCadEnderecos->new($self);
    $self->SetTitle($Resource::STR_CADENDERECO);
    $self->SetClientSize(525, 170);
  } if ($nTelaAtiva == $Resource::FRMCADIDIOMAS) {
    frmCadIdiomas->new($self);
    $self->SetTitle($Resource::STR_CADIDIOMA);     
  } if ($nTelaAtiva == $Resource::FRMCADPAISES) {
    frmCadPaises->new($self);
    $self->SetTitle($Resource::STR_CADPAIS);
  } if ($nTelaAtiva == $Resource::FRMCADPROFISSOES) {
    frmCadProfissoes->new($self);
    $self->SetTitle($Resource::STR_CADPROFISS);
  } if ($nTelaAtiva == $Resource::FRMCADCLIENTES) {
    frmCadClientes->new($self);
    $self->SetTitle($Resource::STR_CADCLIENTE);
    $self->SetClientSize(525, 440);
  } if ($nTelaAtiva == $Resource::FRMCADLIVROS) {
    frmCadLivros->new($self);
    $self->SetTitle($Resource::STR_CADLIVRO);
    $self->SetClientSize(510, 425);        
  } if ($nTelaAtiva == $Resource::FRMVENDERLIVROS) {
    frmVenderLivros->new($self);
    $self->SetTitle($Resource::STR_VENLIVRO);
    $self->SetClientSize(480, 310);        
  } if ($nTelaAtiva == $Resource::FRMCONVENDAS) {
    frmConVendas->new($self);
    $self->SetTitle($Resource::STR_CONVENLIVRO);
    $self->SetClientSize(480, 330);
  } if ($nTelaAtiva == $Resource::FRMALTERARSENHA) { 
    frmAlterarSenha->new($self);
    $self->SetTitle($Resource::STR_ALTSENHA);
    $self->SetClientSize(255, 134);
  }
	return $self;
}

sub OnClose {
  my( $self, $event ) = @_;

  my $frmPrincipal = $Principal::fPrincipal;
  if ($self->{nLocalTelaAtiva} == $Resource::FRMCADASSUNTOS) {
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_ASSUNTOS, $Resource::true);
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADAUTORES) { 
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_AUTORES, $Resource::true);  
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADEDITORAS) {
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_EDITORAS, $Resource::true);    
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADENDERECOS) {
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_ENDERECOS, $Resource::true);    
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADIDIOMAS) {
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_IDIOMAS, $Resource::true);   
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADPAISES) { 
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_PAISES, $Resource::true);    
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADPROFISSOES) { 
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_PROFISSOES, $Resource::true);    
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADCLIENTES) {
    $frmPrincipal->{barraFerra}->EnableTool($Resource::MNU_CAD_CLIENTES, 
      $Resource::true);
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_CLIENTES, $Resource::true);   
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCADLIVROS) {
    $frmPrincipal->{barraFerra}->EnableTool($Resource::MNU_CAD_LIVROS, 
      $Resource::true);
    $frmPrincipal->{barraMenu}->GetMenu(0)->Enable(
      $Resource::MNU_CAD_LIVROS, $Resource::true);
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMVENDERLIVROS) {
    $frmPrincipal->{barraFerra}->EnableTool($Resource::MNU_VEN_VENDERLIVROS, 
      $Resource::true);
    $frmPrincipal->{barraMenu}->GetMenu(2)->Enable(
      $Resource::MNU_VEN_VENDERLIVROS, $Resource::true);  
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMCONVENDAS) { 
    $frmPrincipal->{barraMenu}->GetMenu(2)->Enable(
      $Resource::MNU_VEN_VENDASREALIZADAS, $Resource::true);
  } if ($self->{nLocalTelaAtiva} == $Resource::FRMALTERARSENHA) {
    $frmPrincipal->{barraMenu}->GetMenu(3)->Enable(
      $Resource::MNU_OP_ALTERARSENHA, $Resource::true);
  }
  $event->Skip();
}

1;

