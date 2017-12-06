use Wx 0.15 qw[:allclasses];
use strict;
package frmAlterarSenha;

use Wx qw[:everything];
use base qw(Wx::Panel);
use strict;
use Wx::Event qw(EVT_CLOSE EVT_BUTTON);
require RotinasGlobais;
require resource;

my( $ID_FRMALTERARSENHA_BTNFECHAR, 
 $ID_FRMALTERARSENHA_BTNLIMPAR, $ID_FRMALTERARSENHA_BTNSALVAR, 
 $ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, $ID_FRMALTERARSENHA_EDTLOGIN, 
 $ID_FRMALTERARSENHA_EDTNOVASENHA, $ID_FRMALTERARSENHA_EDTSENHAATUAL, 
 $ID_FRMALTERARSENHA_LABCONFIRMARSENHA, $ID_FRMALTERARSENHA_LABLOGIN, 
 $ID_FRMALTERARSENHA_LABNOVASENHA, $ID_FRMALTERARSENHA_LABSENHAATUAL ) 
  = ( 4000 .. 4011 );

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;

	$self = $self->SUPER::new( $parent, -1, wxDefaultPosition, wxSIZE(257, 161), 
    wxTAB_TRAVERSAL, "" );
  EVT_CLOSE( $self, \&OnClose );

	$self->{labLogin} = Wx::StaticText->new($self, $ID_FRMALTERARSENHA_LABLOGIN, 
    "Login: ", wxPOINT(8, 8), wxSIZE(29, 13) );
	$self->{edtLogin} = Wx::TextCtrl->new($self, $ID_FRMALTERARSENHA_EDTLOGIN, "", 
    wxPOINT(8, 24), wxSIZE(100, 21) );
	$self->{labSenhaAtual} = Wx::StaticText->new($self, $ID_FRMALTERARSENHA_LABSENHAATUAL, 
    "Senha atual:", wxPOINT(112, 8), wxSIZE(60, 13) );
	$self->{edtSenhaAtual} = Wx::TextCtrl->new($self, $ID_FRMALTERARSENHA_EDTSENHAATUAL, 
    "", wxPOINT(112, 24), wxSIZE(100, 21), wxTE_PASSWORD );
	$self->{labNovaSenha} = Wx::StaticText->new($self, $ID_FRMALTERARSENHA_LABNOVASENHA, 
    "Nova Senha:", wxPOINT(8, 48), wxSIZE(61, 13) );
	$self->{edtNovaSenha} = Wx::TextCtrl->new($self, $ID_FRMALTERARSENHA_EDTNOVASENHA,
    "", wxPOINT(8, 64), wxSIZE(100, 21), wxTE_PASSWORD );
	$self->{labConfirmarSenha} = Wx::StaticText->new($self, 
    $ID_FRMALTERARSENHA_LABCONFIRMARSENHA, "Confirmar senha:", 
    wxPOINT(112, 48), wxSIZE(79, 13) );
	$self->{edtConfirmarSenha} = Wx::TextCtrl->new($self, 
    $ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "", 
    wxPOINT(112, 64), wxSIZE(100, 21), wxTE_PASSWORD );
	$self->{btnSalvar} = Wx::Button->new($self, $ID_FRMALTERARSENHA_BTNSALVAR, 
    "&Salvar", wxPOINT(8, 104), wxSIZE(75, 25));
	$self->{btnLimpar} = Wx::Button->new($self, $ID_FRMALTERARSENHA_BTNLIMPAR, 
    "&Limpar", wxPOINT(88, 104), wxSIZE(75, 25));
	$self->{btnFechar} = Wx::Button->new($self, $ID_FRMALTERARSENHA_BTNFECHAR, 
    "&Fechar", wxPOINT(168, 104), wxSIZE(75, 25));

  $self->{edtLogin}->SetValue($RotinasGlobais::Rotinas->atrib('sUsuarioLogin'));
	$self->{edtLogin}->Enable($Resource::false);
  $self->{edtSenhaAtual}->SetMaxLength(10);
  $self->{edtNovaSenha}->SetMaxLength(10);
  $self->{edtConfirmarSenha}->SetMaxLength(10);
  $self->{edtSenhaAtual}->SetFocus();

	$self->FazLayout();

  EVT_BUTTON( $self, $ID_FRMALTERARSENHA_BTNSALVAR, 
    \&OnBtnSalvarClick );
  EVT_BUTTON( $self, $ID_FRMALTERARSENHA_BTNLIMPAR, 
    \&OnBtnLimparClick );
  EVT_BUTTON( $self, $ID_FRMALTERARSENHA_BTNFECHAR, 
    \&OnBtnFecharClick );

	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_2} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_9} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_10} = Wx::GridSizer->new(4, 1, 0, 0);
	$self->{grid_sizer_3} = Wx::GridSizer->new(4, 1, 0, 0);
	$self->{grid_sizer_3}->Add($self->{labLogin}, 0, wxLEFT|wxALIGN_BOTTOM, 8);
	$self->{grid_sizer_3}->Add($self->{edtLogin}, 0, wxLEFT, 8);
	$self->{grid_sizer_3}->Add($self->{labNovaSenha}, 0, wxLEFT|wxALIGN_BOTTOM, 8);
	$self->{grid_sizer_3}->Add($self->{edtNovaSenha}, 0, wxLEFT, 8);
	$self->{sizer_9}->Add($self->{grid_sizer_3}, 0, 0, 0);
	$self->{grid_sizer_10}->Add($self->{labSenhaAtual}, 0, wxLEFT|wxALIGN_BOTTOM, 4);
	$self->{grid_sizer_10}->Add($self->{edtSenhaAtual}, 0, wxLEFT, 4);
	$self->{grid_sizer_10}->Add($self->{labConfirmarSenha}, 0, wxLEFT|wxALIGN_BOTTOM, 4);
	$self->{grid_sizer_10}->Add($self->{edtConfirmarSenha}, 0, wxLEFT, 4);
	$self->{sizer_9}->Add($self->{grid_sizer_10}, 0, 0, 0);
	$self->{sizer_1}->Add($self->{sizer_9}, 1, 0, 0);
	$self->{sizer_2}->Add($self->{btnSalvar}, 0, wxALL, 2);
	$self->{sizer_2}->Add($self->{btnLimpar}, 0, wxALL, 2);
	$self->{sizer_2}->Add($self->{btnFechar}, 0, wxALL, 2);
	$self->{sizer_1}->Add($self->{sizer_2}, 0, wxALL, 4);
	$self->SetAutoLayout(1);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);

}

sub OnClose {
  my( $self, $event ) = @_;

  $self->Destroy();
}

sub OnBtnSalvarClick {
  my( $self, $event ) = @_;

  if ($self->ValidaDados()) {
    my $Rotinas = $RotinasGlobais::Rotinas;
    my $ConsSQL = $ConsultasSQL::ConsSQL;
    if ($Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), 
      $ConsSQL->Usuario('U', 
      $self->{edtLogin}->GetValue(), $self->{edtConfirmarSenha}->GetValue()))) {
      Wx::MessageBox($Resource::STR_SENALTSUC, "Erro", wxOK | wxICON_ERROR);
    }
  }

  $event->Skip();
}

sub OnBtnLimparClick {
  my( $self, $event ) = @_;

  $self->{edtSenhaAtual}->Clear();
  $self->{edtNovaSenha}->Clear();
  $self->{edtConfirmarSenha}->Clear();
  $self->{edtSenhaAtual}->SetFocus();
  $event->Skip();
}

sub OnBtnFecharClick {
  my( $self, $event ) = @_;

  $self->GetParent()->Close($Resource::true);
  $event->Skip();
}

sub ValidaDados {
	my $self = shift;

  my $Rotinas = $RotinasGlobais::Rotinas;

  if ($self->{edtSenhaAtual}->GetValue() !~ $Rotinas->atrib('sUsuarioSenha')) {
    Wx::MessageBox($Resource::STR_SENNCSU, "Erro", wxOK | wxICON_ERROR);
    return $Resource::false;
  }
  if ($Rotinas->ValidaCampo($self->{edtNovaSenha}->GetValue(),
     $Resource::STR_NSENNINF)) {
    return $Resource::false;
  }
  if ($self->{edtNovaSenha}->GetValue() !~ 
      $self->{edtConfirmarSenha}->GetValue()) {
    Wx::MessageBox($Resource::STR_NSENNCCON, "Erro", wxOK | wxICON_ERROR);
    return $Resource::false;
  }
  return $Resource::true;
}

1;

