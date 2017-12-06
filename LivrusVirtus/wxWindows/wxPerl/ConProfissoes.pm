use Wx 0.15 qw[:allclasses];
use strict;
use Consultas qw[:allclasses];
package frmConProfissoes;

use Wx qw[:everything];
use base qw(frmConsultas);
use strict;
use Wx::Event qw(EVT_BUTTON EVT_CLOSE EVT_GRID_SELECT_CELL EVT_GRID_LABEL_LEFT_CLICK);

require resource;
require RotinasGlobais;
require ConsultasSQL;

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;

	$self = $self->SUPER::new( $parent );
  $self->SetTitle($Resource::STR_CONPROFISS);
  $self->{labDescricao}->SetLabel("Profissão:  ");
  $self->{gridConsulta}->SetColLabelValue(1, "Profissão");

  EVT_BUTTON( $self, $self->{btnPesquisar}->GetId(), \&OnBtnPesquisarClick );
  EVT_BUTTON( $self, $self->{btnLimpar}->GetId(), \&OnBtnLimparClick );
  EVT_BUTTON( $self, $self->{btnFechar}->GetId(), \&OnBtnFecharClick );
  EVT_CLOSE( $self, \&OnClose );
  EVT_GRID_SELECT_CELL($self, \&OnGridSelectCell );
  EVT_GRID_LABEL_LEFT_CLICK($self, \&OnGridLabelLeftClick );

	return $self;
}

sub OnClose {
  my( $self, $event ) = @_;

  $self->Fecha($Resource::MNU_CON_PROFISSOES);
  $event->Skip();
}

sub OnBtnPesquisarClick {
  my( $self, $event ) = @_;

  my $ConsSQL = $ConsultasSQL::ConsSQL;
  $self->PesquisarDados(
    $ConsSQL->Profissao('S', "", $self->{edtDescricao}->GetValue()),
    $Resource::STR_PROFNENC, 2);
  $event->Skip();
}

sub OnBtnLimparClick {
  my( $self, $event ) = @_;

  $self->LimparDados();
  $event->Skip();
}

sub OnBtnFecharClick {
  my( $self, $event ) = @_;

  $self->Fecha(0);
  $event->Skip();
}

sub OnGridSelectCell {
  my( $self, $event ) = @_;

  $self->setLabRegistros($event->GetRow());
  $event->Skip();
}

sub OnGridLabelLeftClick {
  my( $self, $event ) = @_;

  $self->setLabRegistros($event->GetRow());
  $event->Skip();
}

1;
