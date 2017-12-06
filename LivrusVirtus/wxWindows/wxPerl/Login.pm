use Wx 0.15 qw[:allclasses];
use strict;
package frmLogin;

use Wx qw[:everything];
use base qw(Wx::Dialog);
use strict;
use Wx::Event qw(EVT_CLOSE EVT_BUTTON);
require Principal;
require resource;
require RotinasGlobais;
require ConsultasSQL;

our $fLogin = undef;
my $bFechar = $Resource::false;

my( $ID_FRMLOGIN_BMPLOGIN, $ID_FRMLOGIN_LABLOGIN, $ID_FRMLOGIN_EDTLOGIN, 
    $ID_FRMLOGIN_LABSENHA, $ID_FRMLOGIN_EDTSENHA, $ID_FRMLOGIN_BTNLOGIN,
    $ID_FRMLOGIN_BTNCANCELAR ) = ( 2000 .. 2007 );

sub new {
	my( $self, $parent, $id, $title, $pos, $size, $style, $name ) = @_;
	$parent = undef              unless defined $parent;
	$id     = -1                 unless defined $id;
	$title  = "Login do Sistema" unless defined $title;
	$pos    = wxPOINT(546, 346)  unless defined $pos;
	$size   = wxSIZE(211, 168)   unless defined $size;
	$name   = ""                 unless defined $name;
	$style = wxDEFAULT_DIALOG_STYLE unless defined $style;

	$self = $self->SUPER::new( $parent, $id, $title, $pos, $size, $style, $name );
  $self->SetClientSize(wxSIZE(203, 141));
  $self->Centre(wxBOTH);

	$self->{bmpLogin} = Wx::StaticBitmap->new($self, $ID_FRMLOGIN_BMPLOGIN, 
    Wx::Bitmap->new("xpms\\login.xpm", wxBITMAP_TYPE_ANY),
    wxPOINT(8, 8), wxSIZE(88, 90) );
	$self->{labLogin} = Wx::StaticText->new($self, $ID_FRMLOGIN_LABLOGIN, 
    "Login:", wxPOINT(112, 8), wxSIZE(29, 13) );
	$self->{edtLogin} = Wx::TextCtrl->new($self, $ID_FRMLOGIN_EDTLOGIN, "", 
    wxPOINT(112, 24), wxSIZE(80, 21) );
  $self->{edtLogin}->SetMaxLength(10);
	$self->{labSenha} = Wx::StaticText->new($self, $ID_FRMLOGIN_LABSENHA, 
    "Senha:", wxPOINT(112, 56), wxSIZE(34, 13) );
	$self->{edtSenha} = Wx::TextCtrl->new($self, $ID_FRMLOGIN_EDTSENHA, "", 
    wxPOINT(112, 72), wxSIZE(80, 21), wxTE_PASSWORD );
  $self->{edtSenha}->SetMaxLength(10);
	$self->{btnLogin} = Wx::Button->new($self, $ID_FRMLOGIN_BTNLOGIN, "&Login",
    wxPOINT(24, 107), wxSIZE(75, 25));
  $self->{btnLogin}->SetDefault();
	$self->{btnCancelar} = Wx::Button->new($self, $ID_FRMLOGIN_BTNCANCELAR, 
    "&Cancelar", wxPOINT(112, 107), wxSIZE(75, 25));
	
	$self->FazLayout();

  EVT_CLOSE( $self, \&OnClose );	
  EVT_BUTTON( $self, $ID_FRMLOGIN_BTNLOGIN, \&OnBtnLoginClick );
  EVT_BUTTON( $self, $ID_FRMLOGIN_BTNCANCELAR, 
    \&OnBtnCancelarClick ); 

	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_4} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_2} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_3} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_2}->Add($self->{bmpLogin}, 0, wxALL, 6);
	$self->{sizer_3}->Add($self->{labLogin}, 0, wxALL|wxALIGN_BOTTOM, 2);
	$self->{sizer_3}->Add($self->{edtLogin}, 0, wxALL, 2);
	$self->{sizer_3}->Add($self->{labSenha}, 0, wxALL|wxALIGN_BOTTOM, 2);
	$self->{sizer_3}->Add($self->{edtSenha}, 0, wxALL, 2);
	$self->{sizer_2}->Add($self->{sizer_3}, 0, wxALL, 6);
	$self->{sizer_1}->Add($self->{sizer_2}, 0, 0, 3);
	$self->{sizer_4}->Add($self->{btnLogin}, 0, 
    wxLEFT|wxTOP|wxBOTTOM|wxALIGN_BOTTOM, 10);
	$self->{sizer_4}->Add($self->{btnCancelar}, 0, wxALL|wxALIGN_BOTTOM, 10);
	$self->{sizer_1}->Add($self->{sizer_4}, 0, 
    wxALL|wxALIGN_CENTER_HORIZONTAL, 1);
	$self->SetAutoLayout(1);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);
	$self->Layout();
	$self->Centre();
}

sub OnClose {
  my( $self, $event ) = @_;

  if ($bFechar) {
    $self->Destroy();
  } else {
    $Principal::fPrincipal->Destroy();
    exit(0);
  }
}

sub OnBtnLoginClick {
  my( $self, $event ) = @_;

  my $Rotinas = $RotinasGlobais::Rotinas;
  my $ConsSQL = $ConsultasSQL::ConsSQL;

  $Rotinas->set_atrib('sUsuarioLogin', $self->{edtLogin}->GetValue());
  $Rotinas->set_atrib('sUsuarioSenha', $self->{edtSenha}->GetValue());

  if ($Rotinas->ConsultaDados($Rotinas->atrib('gConexao'), $ConsSQL->Usuario('S',
     $Rotinas->atrib('sUsuarioLogin'), $Rotinas->atrib('sUsuarioSenha') ))) {
    $Rotinas->set_atrib('sBarraLogin', $Resource::STR_USUARIO . $Rotinas->atrib('sUsuarioLogin') );
    $Principal::fPrincipal->SetStatusText($Rotinas->atrib('sBarraLogin'), 0);

    $bFechar = $Resource::true;
    $self->Close($Resource::true);
    $Principal::fPrincipal->Show($Resource::true);
  } else {
    Wx::MessageBox($Resource::STR_LOGSENINC, "Erro", wxOK | wxICON_ERROR);
  }
  $event->Skip();
}

sub OnBtnCancelarClick {
  my( $self, $event ) = @_;

  $bFechar = $Resource::false;
  $self->Close($Resource::true);
  $event->Skip();
}

1;

