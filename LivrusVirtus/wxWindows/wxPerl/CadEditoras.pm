use Wx 0.15 qw[:allclasses];
use strict;
use Cadastros qw[:allclasses];
package frmCadEditoras;

use Wx qw[:everything];
use base qw(frmCadastros);
use strict;
use Wx::Event qw(EVT_BUTTON);

require TextValidatorCtrl;
require RotinasGlobais;
require ConsultasSQL;
require resource;

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;	

	$self = $self->SUPER::new( $parent, $TextValidatorCtrl::FILTER_NUMERIC, 
    $Resource::true );
  $self->{labDescricao}->SetLabel('Editora:');

  EVT_BUTTON( $self, $self->{btnNovo}->GetId(), \&OnBtnNovoClick );
  EVT_BUTTON( $self, $self->{btnPesquisar}->GetId(), \&OnBtnPesquisarClick );
  EVT_BUTTON( $self, $self->{btnAnterior}->GetId(), \&OnBtnAnteriorClick );
  EVT_BUTTON( $self, $self->{btnProximo}->GetId(), \&OnBtnProximoClick );
  EVT_BUTTON( $self, $self->{btnSalvar}->GetId(), \&OnBtnSalvarClick );
  EVT_BUTTON( $self, $self->{btnExcluir}->GetId(), \&OnBtnExcluirClick );
  EVT_BUTTON( $self, $self->{btnLimpar}->GetId(), \&OnBtnLimparClick );
  EVT_BUTTON( $self, $self->{btnFechar}->GetId(), \&OnBtnFecharClick );

	return $self;
}

sub ValidaDados {
my( $self, $bTodosDados ) = @_;
my $Rotinas = $RotinasGlobais::Rotinas;

  if ($Rotinas->ValidaCampo(
    $self->{edtCodigo}->GetValue(), $Resource::STR_CODNINF)) {
    return $Resource::false;
  }
  if ($bTodosDados) {
	  if ($Rotinas->ValidaCampo(
      $self->{edtDescricao}->GetValue(), $Resource::STR_EDTNINF)) {
  		return $Resource::false;
    }
  }
  return $Resource::true;
}

sub OnBtnNovoClick {
  my( $self, $event ) = @_;
  my $ConsSQL = $ConsultasSQL::ConsSQL;

  $self->btnNovoClick();
  $self->NovoDado($ConsSQL->Editora('N', $self->{edtCodigo}->GetValue(),""));
  $event->Skip();
}

sub OnBtnPesquisarClick {
  my( $self, $event ) = @_;
  my $ConsSQL = $ConsultasSQL::ConsSQL;

  $self->PesquisarDados($ConsSQL->Editora('S', 
      $self->{edtCodigo}->GetValue(),""), $Resource::STR_EDTNENC);
  $event->Skip();
}

sub OnBtnAnteriorClick {
  my( $self, $event ) = @_;

  $self->registroAnterior();
  $event->Skip();
}

sub OnBtnProximoClick {
  my( $self, $event ) = @_;

  $self->registroProximo();
  $event->Skip();
}

sub OnBtnSalvarClick {
  my( $self, $event ) = @_;
  my $ConsSQL = $ConsultasSQL::ConsSQL;

  $self->SalvarDados($self->ValidaDados($Resource::true),
    $ConsSQL->Editora('S', $self->{edtCodigo}->GetValue(),""),
    $ConsSQL->Editora('U', $self->{edtCodigo}->GetValue(), 
    $self->{edtDescricao}->GetValue()),
    $ConsSQL->Editora('I', $self->{edtCodigo}->GetValue(), 
    $self->{edtDescricao}->GetValue()), $Resource::true);
  $event->Skip();
}

sub OnBtnExcluirClick {
  my( $self, $event ) = @_;
  my $ConsSQL = $ConsultasSQL::ConsSQL;

  $self->ExcluirDados($self->ValidaDados($Resource::false),
    $ConsSQL->Editora('D', $self->{edtCodigo}->GetValue(),""));
  $event->Skip();
}

sub OnBtnLimparClick {
  my( $self, $event ) = @_;

  $self->btnLimparClick();
  $event->Skip();
}

sub OnBtnFecharClick {
  my( $self, $event ) = @_;

  $self->GetParent()->Close();
  $event->Skip();
}

1;

