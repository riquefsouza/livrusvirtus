use Wx 0.15 qw[:allclasses];
use strict;
use Consultas qw[:allclasses];
package frmConEnderecos;

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
  $self->SetTitle($Resource::STR_CONENDERECO);
  $self->{labDescricao}->SetLabel("Endere�o:  ");
  $self->{gridConsulta}->SetColLabelValue(1, "Logradouro");
  $self->{gridConsulta}->SetColSize(1, 200);

  my @nLarguras_sRotulos = ( 150, 80, 100, 80, 
    'Bairro', 'CEP', 'Cidade', 'Estado');
  $RotinasGlobais::Rotinas->AdicionaColunasGrid(
        $self->{gridConsulta}, 2, 4, @nLarguras_sRotulos);

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

  $self->Fecha($Resource::MNU_CON_ENDERECOS);
  $event->Skip();
}

sub OnBtnPesquisarClick {
  my( $self, $event ) = @_;

  my $ConsSQL = $ConsultasSQL::ConsSQL;
  $self->PesquisarDados(
    $ConsSQL->Endereco('S', "", $self->{edtDescricao}->GetValue(),
    "","","",""), $Resource::STR_ENDNENC, 6);
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
