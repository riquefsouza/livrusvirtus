use Wx 0.15 qw[:allclasses];
use strict;
package frmPrincipal;

use Wx qw[:everything];
use base qw(Wx::Frame);
use strict;

use vars qw(@ISA); @ISA = qw(Wx::MDIParentFrame);
use Wx::Event qw(EVT_MENU EVT_CLOSE);
require resource;
require Filha;
require ConAssuntos;
require ConAutores;
require ConEditoras;
require ConEnderecos;
require ConIdiomas;
require ConPaises;
require ConProfissoes;
require ConClientes;
require ConLivros;
require Sobre;

our $fPrincipal = undef;

sub new {
	my( $self, $parent, $id, $title, $pos, $size, $style, $name ) = @_;
	$parent = undef              unless defined $parent;
	$id     = -1                 unless defined $id;
	$title  = ""                 unless defined $title;
	$pos    = wxDefaultPosition  unless defined $pos;
	$size   = wxDefaultSize      unless defined $size;
	$name   = ""                 unless defined $name;
	$style = wxDEFAULT_FRAME_STYLE unless defined $style;

	$self = $self->SUPER::new( $parent, $id, $title, $pos, $size, $style, $name );
        EVT_CLOSE( $self, \&OnClose );	

	# Barra de Menu

	$self->{mnuCadastros} = Wx::Menu->new();
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_ASSUNTOS, "&Assuntos", $Resource::STR_CADASSUNTO);
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_AUTORES, "A&utores", $Resource::STR_CADAUTOR);
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_EDITORAS, "&Editoras", $Resource::STR_CADEDITORA);
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_ENDERECOS, "E&ndereços", $Resource::STR_CADENDERECO);
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_IDIOMAS, "&Idiomas", $Resource::STR_CADIDIOMA);
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_PAISES, "&Países", $Resource::STR_CADPAIS);
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_PROFISSOES, "P&rofissões", $Resource::STR_CADPROFISS);
	$self->{mnuCadastros}->AppendSeparator();
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_CLIENTES, "&Clientes", $Resource::STR_CADCLIENTE);
	$self->{mnuCadastros}->Append($Resource::MNU_CAD_LIVROS, "&Livros", $Resource::STR_CADLIVRO);

	$self->{mnuPesquisas} = Wx::Menu->new();
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_ASSUNTOS, "&Assuntos", $Resource::STR_CONASSUNTO);
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_AUTORES, "A&utores", $Resource::STR_CONAUTOR);
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_EDITORAS, "&Editoras", $Resource::STR_CONEDITORA);
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_ENDERECOS, "E&ndereços", $Resource::STR_CONENDERECO);
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_IDIOMAS, "&Idiomas", $Resource::STR_CONIDIOMA);
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_PAISES, "&Países", $Resource::STR_CONPAIS);
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_PROFISSOES, "P&rofissões", $Resource::STR_CONPROFISS);
	$self->{mnuPesquisas}->AppendSeparator();
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_CLIENTES, "&Clientes", $Resource::STR_CONCLIENTE);
	$self->{mnuPesquisas}->Append($Resource::MNU_CON_LIVROS, "&Livros", $Resource::STR_CONLIVRO);

	$self->{mnuVendas} = Wx::Menu->new();
	$self->{mnuVendas}->Append($Resource::MNU_VEN_VENDERLIVROS, "&Vender Livros", $Resource::STR_VENLIVRO);
	$self->{mnuVendas}->Append($Resource::MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas", $Resource::STR_CONVENLIVRO);

	$self->{mnuOpcoes} = Wx::Menu->new();
	$self->{mnuOpcoes}->Append($Resource::MNU_OP_ALTERARSENHA, "&Alterar Senha", $Resource::STR_ALTSENHA);
	$self->{mnuOpcoes}->AppendSeparator();
	$self->{mnuOpcoes}->Append($Resource::MNU_OP_SOBRE, "&Sobre", $Resource::STR_OPSOBRE);
	$self->{mnuOpcoes}->Append($Resource::MNU_OP_SAIR, "Sa&ir\tCtrl-S", $Resource::STR_OPSAIR);

	$self->{barraMenu} = Wx::MenuBar->new();
	$self->{barraMenu}->Append($self->{mnuCadastros}, "&Cadastros");
	$self->{barraMenu}->Append($self->{mnuPesquisas}, "&Pesquisas");
	$self->{barraMenu}->Append($self->{mnuVendas}, "&Vendas");
	$self->{barraMenu}->Append($self->{mnuOpcoes}, "&Opções");

	$self->SetMenuBar($self->{barraMenu});

  EVT_MENU( $self, $Resource::MNU_CAD_ASSUNTOS, \&OnMnuCadAssuntos );
  EVT_MENU( $self, $Resource::MNU_CAD_AUTORES, \&OnMnuCadAutores );
  EVT_MENU( $self, $Resource::MNU_CAD_EDITORAS, \&OnMnuCadEditoras );
  EVT_MENU( $self, $Resource::MNU_CAD_ENDERECOS, \&OnMnuCadEnderecos );
  EVT_MENU( $self, $Resource::MNU_CAD_IDIOMAS, \&OnMnuCadIdiomas );
  EVT_MENU( $self, $Resource::MNU_CAD_PAISES, \&OnMnuCadPaises );
  EVT_MENU( $self, $Resource::MNU_CAD_PROFISSOES, \&OnMnuCadProfissoes );
  EVT_MENU( $self, $Resource::MNU_CAD_CLIENTES, \&OnMnuCadClientes );
  EVT_MENU( $self, $Resource::MNU_CAD_LIVROS, \&OnMnuCadLivros );

  EVT_MENU( $self, $Resource::MNU_CON_ASSUNTOS, \&OnMnuConAssuntos );
  EVT_MENU( $self, $Resource::MNU_CON_AUTORES, \&OnMnuConAutores );
  EVT_MENU( $self, $Resource::MNU_CON_EDITORAS, \&OnMnuConEditoras );
  EVT_MENU( $self, $Resource::MNU_CON_ENDERECOS, \&OnMnuConEnderecos );
  EVT_MENU( $self, $Resource::MNU_CON_IDIOMAS, \&OnMnuConIdiomas );
  EVT_MENU( $self, $Resource::MNU_CON_PAISES, \&OnMnuConPaises );
  EVT_MENU( $self, $Resource::MNU_CON_PROFISSOES, \&OnMnuConProfissoes );
  EVT_MENU( $self, $Resource::MNU_CON_CLIENTES, \&OnMnuConClientes );
  EVT_MENU( $self, $Resource::MNU_CON_LIVROS, \&OnMnuConLivros );

	EVT_MENU( $self, $Resource::MNU_VEN_VENDERLIVROS, \&OnMnuVenderLivros );
	EVT_MENU( $self, $Resource::MNU_VEN_VENDASREALIZADAS, \&OnMnuVendasRealizadas );

	EVT_MENU( $self, $Resource::MNU_OP_ALTERARSENHA, \&OnMnuAlterarSenha );
	EVT_MENU( $self, $Resource::MNU_OP_SOBRE, \&OnMnuSobre );
	EVT_MENU( $self, $Resource::MNU_OP_SAIR, \&OnClose );

  $self->{barraStatus} = $self->CreateStatusBar(2);
  $self->SetStatusBarPane(1);	

  # Barra de ferramentas

	$self->{barraFerra} = Wx::ToolBar->new($self, -1, wxDefaultPosition, wxDefaultSize, );
	$self->SetToolBar($self->{barraFerra});
	$self->{barraFerra}->AddTool($Resource::MNU_CAD_CLIENTES, "", 
    Wx::Bitmap->new("xpms\\cliente.xpm", wxBITMAP_TYPE_ANY), 
    Wx::Bitmap->new("xpms\\dcliente.xpm", wxBITMAP_TYPE_ANY), wxITEM_NORMAL, "", "");
	$self->{barraFerra}->AddTool($Resource::MNU_CAD_LIVROS, "", 
    Wx::Bitmap->new("xpms\\livro.xpm", wxBITMAP_TYPE_ANY), 
    Wx::Bitmap->new("xpms\\dlivro.xpm", wxBITMAP_TYPE_ANY), wxITEM_NORMAL, "", "");
	$self->{barraFerra}->AddTool($Resource::MNU_VEN_VENDERLIVROS, "", 
    Wx::Bitmap->new("xpms\\livros.xpm", wxBITMAP_TYPE_ANY), 
    Wx::Bitmap->new("xpms\\dlivros.xpm", wxBITMAP_TYPE_ANY), wxITEM_NORMAL, "", "");
	$self->{barraFerra}->AddSeparator();
	$self->{barraFerra}->AddTool($Resource::MNU_OP_SOBRE, "", 
    Wx::Bitmap->new("xpms\\sobre.xpm", wxBITMAP_TYPE_ANY), 
    Wx::Bitmap->new("xpms\\dsobre.xpm", wxBITMAP_TYPE_ANY), wxITEM_NORMAL, "", "");
	$self->{barraFerra}->AddTool($Resource::MNU_OP_SAIR, "", 
    Wx::Bitmap->new("xpms\\sair.xpm", wxBITMAP_TYPE_ANY), 
    Wx::Bitmap->new("xpms\\dsair.xpm", wxBITMAP_TYPE_ANY), wxITEM_NORMAL, "", "");

	$self->setPropriedades();
	$self->FazLayout();

	return $self;
}

sub setPropriedades {
	my $self = shift;

	$self->SetTitle("Livrus Virtus");
	my $icon = Wx::Icon->new();
	$icon->CopyFromBitmap(Wx::Bitmap->new("xpms\\livrus.xpm", wxBITMAP_TYPE_ANY));
	$self->SetIcon($icon);
	$self->{barraStatus}->SetStatusWidths(100,-1);
	
	my( @barraStatus_fields ) = (
		"Usuário: ",
		""
	);

	if( @barraStatus_fields ) {
			$self->{barraStatus}->SetStatusText($barraStatus_fields[$_], $_) 	
			for 0 .. $#barraStatus_fields ;
	}
	$self->{barraFerra}->Realize();
}

sub FazLayout {
	my $self = shift;

  $self->Layout();
  $self->Centre();
}

sub OnClose {
  my( $self, $event ) = @_;

  if (Wx::MessageBox($Resource::STR_SAIRSIS, "Confirma",
                         wxYES_NO | wxICON_QUESTION, $self) == wxYES) {
    $self->Destroy;
  }
}

sub OnMnuCadAssuntos {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_ASSUNTOS, 
    $Resource::false);
  my $frmCadAssuntos = frmFilha->new($self,$Resource::FRMCADASSUNTOS);
  $event->Skip();
}

sub OnMnuCadAutores {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_AUTORES, 
    $Resource::false);
  my $frmCadAutores = frmFilha->new($self,$Resource::FRMCADAUTORES);
  $event->Skip();
}

sub OnMnuCadEditoras {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_EDITORAS, 
    $Resource::false);
  my $frmCadEditoras = frmFilha->new($self,$Resource::FRMCADEDITORAS);
  $event->Skip();
}

sub OnMnuCadEnderecos {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_ENDERECOS, 
    $Resource::false);
  my $frmCadEnderecos = frmFilha->new($self,$Resource::FRMCADENDERECOS);
  $event->Skip();
}

sub OnMnuCadIdiomas {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_IDIOMAS, 
    $Resource::false);
  my $frmCadIdiomas = frmFilha->new($self,$Resource::FRMCADIDIOMAS);
  $event->Skip();
}

sub OnMnuCadPaises {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_PAISES, 
    $Resource::false);
  my $frmCadPaises = frmFilha->new($self,$Resource::FRMCADPAISES);
  $event->Skip();
}

sub OnMnuCadProfissoes {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_PROFISSOES, 
    $Resource::false);
  my $frmCadProfissoes = frmFilha->new($self,$Resource::FRMCADPROFISSOES);
  $event->Skip();
}

sub OnMnuCadClientes {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_CLIENTES, 
    $Resource::false);
  $self->{barraFerra}->EnableTool($Resource::MNU_CAD_CLIENTES, 
    $Resource::false);
  my $frmCadClientes = frmFilha->new($self,$Resource::FRMCADCLIENTES);
  $event->Skip();
}

sub OnMnuCadLivros {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(0)->Enable($Resource::MNU_CAD_LIVROS, 
    $Resource::false);
  $self->{barraFerra}->EnableTool($Resource::MNU_CAD_LIVROS, 
    $Resource::false);
  my $frmCadLivros = frmFilha->new($self,$Resource::FRMCADLIVROS);
  $event->Skip();
}

sub OnMnuConAssuntos {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONASSUNTO,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_ASSUNTOS, 
    $Resource::false);
  my $fConAssuntos = frmConAssuntos->new($self);
  $fConAssuntos->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConAutores {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONAUTOR,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_AUTORES, 
    $Resource::false);
  my $fConAutores = frmConAutores->new($self);
  $fConAutores->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConEditoras {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONEDITORA,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_EDITORAS, 
    $Resource::false);
  my $fConEditoras = frmConEditoras->new($self);
  $fConEditoras->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConEnderecos {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONENDERECO,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_ENDERECOS, 
    $Resource::false);
  my $fConEnderecos = frmConEnderecos->new($self);
  $fConEnderecos->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConIdiomas {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONIDIOMA,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_IDIOMAS, 
    $Resource::false);
  my $fConIdiomas = frmConIdiomas->new($self);
  $fConIdiomas->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConPaises {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONPAIS,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_PAISES, 
    $Resource::false);
  my $fConPaises = frmConPaises->new($self);
  $fConPaises->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConProfissoes {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONPROFISS,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_PROFISSOES, 
    $Resource::false);
  my $fConProfissoes = frmConProfissoes->new($self);
  $fConProfissoes->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConClientes {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONCLIENTE,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_CLIENTES, 
    $Resource::false);
  my $fConClientes = frmConClientes->new($self);
  $fConClientes->Show($Resource::true);
  $event->Skip();
}

sub OnMnuConLivros {
  my( $self, $event ) = @_;
  $self->{barraStatus}->SetStatusText($Resource::STR_CONLIVRO,1);
  $self->{barraMenu}->GetMenu(1)->Enable($Resource::MNU_CON_LIVROS, 
    $Resource::false);
  my $fConLivros = frmConLivros->new($self);
  $fConLivros->Show($Resource::true);
  $event->Skip();
}

sub OnMnuVenderLivros {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(2)->Enable($Resource::MNU_VEN_VENDERLIVROS, 
    $Resource::false);
  $self->{barraFerra}->EnableTool($Resource::MNU_VEN_VENDERLIVROS, 
    $Resource::false);
  my $frmVenderLivros = frmFilha->new($self,$Resource::FRMVENDERLIVROS);
  $event->Skip();
}

sub OnMnuVendasRealizadas {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(2)->Enable($Resource::MNU_VEN_VENDASREALIZADAS, 
    $Resource::false);
  my $frmConVendas = frmFilha->new($self,$Resource::FRMCONVENDAS);
  $event->Skip();
}

sub OnMnuAlterarSenha {
  my( $self, $event ) = @_;
  $self->{barraMenu}->GetMenu(3)->Enable($Resource::MNU_OP_ALTERARSENHA, 
    $Resource::false);
  my $frmAlterarSenha = frmFilha->new($self,$Resource::FRMALTERARSENHA);
  $event->Skip();
}

sub OnMnuSobre {
  my( $self, $event ) = @_;
  my $frmSobre = frmSobre->new($self);
  $frmSobre->ShowModal();
	$event->Skip();
}

1;

