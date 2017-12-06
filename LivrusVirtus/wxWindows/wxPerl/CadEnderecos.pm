use Wx 0.15 qw[:allclasses];
use strict;
use Cadastros qw[:allclasses];
package frmCadEnderecos;

use Wx qw[:everything];
use base qw(frmCadastros);
use strict;
use Wx::Event qw(EVT_BUTTON);
require resource;
require TextValidatorCtrl;

my( $ID_FRMCADENDERECOS_CMBESTADO, $ID_FRMCADENDERECOS_EDTBAIRRO, 
 $ID_FRMCADENDERECOS_EDTCEP, $ID_FRMCADENDERECOS_EDTCIDADE, 
 $ID_FRMCADENDERECOS_LABBAIRRO, $ID_FRMCADENDERECOS_LABCEP, 
 $ID_FRMCADENDERECOS_LABCIDADE, $ID_FRMCADENDERECOS_LABESTADO ) = (5000..5007);

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;	

  $self = $self->SUPER::new( $parent, $TextValidatorCtrl::FILTER_NUMERIC, 
    $Resource::false );
  $self->SetClientSize(523, 171);
  $self->{labDescricao}->SetLabel('Logradouro: ');
  $self->{labDescricao}->SetSize(57, 13);
  $self->{edtDescricao}->SetSize(264, 21);

	$self->{labBairro} = Wx::StaticText->new($self, $ID_FRMCADENDERECOS_LABBAIRRO, 
    "Bairro:", wxDefaultPosition, wxDefaultSize, );
	$self->{edtBairro} = Wx::TextCtrl->new($self, $ID_FRMCADENDERECOS_EDTBAIRRO,
    "", wxDefaultPosition, wxDefaultSize, );
	$self->{labCEP} = Wx::StaticText->new($self, $ID_FRMCADENDERECOS_LABCEP, 
    "CEP: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtCEP} = Wx::TextCtrl->new($self, $ID_FRMCADENDERECOS_EDTCEP, 
    "", wxDefaultPosition, wxDefaultSize, );
	$self->{labCidade} = Wx::StaticText->new($self, $ID_FRMCADENDERECOS_LABCIDADE, 
    "Cidade: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtCidade} = Wx::TextCtrl->new($self, $ID_FRMCADENDERECOS_EDTCIDADE, 
    "", wxDefaultPosition, wxDefaultSize, );
	$self->{labEstado} = Wx::StaticText->new($self, $ID_FRMCADENDERECOS_LABESTADO, 
    "Estado: ", wxDefaultPosition, wxDefaultSize, );
	$self->{cmbEstado} = Wx::Choice->new($self, $ID_FRMCADENDERECOS_CMBESTADO, 
    wxDefaultPosition, wxDefaultSize, );

	$self->{edtBairro}->SetSize(144, 21);
	$self->{edtBairro}->Enable($Resource::false);
	$self->{labCEP}->SetSize(40, 13);
	$self->{edtCEP}->SetSize(72, 21);
	$self->{edtCEP}->Enable($Resource::false);
	$self->{labCidade}->SetSize(39, 13);
	$self->{edtCidade}->SetSize(184, 21);
	$self->{edtCidade}->Enable($Resource::false);
	$self->{labEstado}->SetSize(56, 13);
	$self->{cmbEstado}->SetSize(144, 21);
	$self->{cmbEstado}->Enable($Resource::false);
	$self->{cmbEstado}->SetSelection(0);

  $self->IniciaBotoes();

  $self->{btnPesquisar}->SetSize(440, 8, 75, 25);
  $self->{btnAnterior}->SetSize(440, 40, 75, 25);
  $self->{btnProximo}->SetSize(440, 72, 75, 25);
  $self->{btnSalvar}->SetSize(200, 136, 75, 25);
  $self->{btnExcluir}->SetSize(280, 136, 75, 25);
  $self->{btnLimpar}->SetSize(360, 136, 75, 25);
  $self->{btnFechar}->SetSize(440, 136, 75, 25);

	$self->FazLayout();
      
  $self->{edtDescricao}->SetMaxLength(40);
  $self->{edtBairro}->SetMaxLength(15);
  $self->{edtCEP}->SetMaxLength(8);
  $self->{edtCidade}->SetMaxLength(30);
  $self->AdicionaCombo();

  EVT_BUTTON( $self, $self->{btnNovo}->GetId(), \&OnBtnNovoClick );
  EVT_BUTTON( $self, $self->{btnPesquisar}->GetId(), \&OnBtnPesquisarClick );
  EVT_BUTTON( $self, $self->{btnAnterior}->GetId(), \&OnBtnAnteriorClick );
  EVT_BUTTON( $self, $self->{btnProximo}->GetId(), \&OnBtnProximoClick );
  EVT_BUTTON( $self, $self->{btnSalvar}->GetId(), \&OnBtnSalvarClick );
  EVT_BUTTON( $self, $self->{btnLimpar}->GetId(), \&OnBtnLimparClick );
  EVT_BUTTON( $self, $self->{btnFechar}->GetId(), \&OnBtnFecharClick );

	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_2} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_3} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_4} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_5} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_6} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_6} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_5} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_4} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_8} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_9} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_8} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_7} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_7} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_7}->Add($self->{labCodigo}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_7}->Add($self->{edtCodigo}, 0, 0, 0);
	$self->{sizer_7}->Add($self->{grid_sizer_7}, 0, 0, 0);
	$self->{sizer_7}->Add($self->{btnNovo}, 0, wxLEFT|wxALIGN_BOTTOM, 5);
	$self->{sizer_5}->Add($self->{sizer_7}, 1, 0, 0);
	$self->{grid_sizer_8}->Add($self->{labDescricao}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_8}->Add($self->{edtDescricao}, 0, 0, 0);
	$self->{sizer_8}->Add($self->{grid_sizer_8}, 0, 0, 0);
	$self->{grid_sizer_9}->Add($self->{labBairro}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_9}->Add($self->{edtBairro}, 0, 0, 0);
	$self->{sizer_8}->Add($self->{grid_sizer_9}, 0, wxLEFT, 2);
	$self->{sizer_5}->Add($self->{sizer_8}, 1, wxEXPAND, 0);
	$self->{grid_sizer_4}->Add($self->{labCEP}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_4}->Add($self->{edtCEP}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_4}, 0, 0, 0);
	$self->{grid_sizer_5}->Add($self->{labCidade}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_5}->Add($self->{edtCidade}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_5}, 0, wxLEFT, 4);
	$self->{grid_sizer_6}->Add($self->{labEstado}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_6}->Add($self->{cmbEstado}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_6}, 0, wxLEFT, 5);
	$self->{sizer_5}->Add($self->{sizer_6}, 0, 0, 0);
	$self->{sizer_3}->Add($self->{sizer_5}, 0, 0, 0);
	$self->{sizer_4}->Add($self->{btnPesquisar}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_4}->Add($self->{btnAnterior}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_4}->Add($self->{btnProximo}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_3}->Add($self->{sizer_4}, 1, 0, 0);
	$self->{sizer_1}->Add($self->{sizer_3}, 1, wxALL|wxEXPAND, 4);
	$self->{sizer_2}->Add($self->{btnSalvar}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_2}->Add($self->{btnExcluir}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_2}->Add($self->{btnLimpar}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_2}->Add($self->{btnFechar}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_1}->Add($self->{sizer_2}, 0, 
    wxRIGHT|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4);
	$self->SetAutoLayout($Resource::true);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);
}

sub ValidaDados {
my( $self, $bTodosDados ) = @_;
my $Rotinas = $RotinasGlobais::Rotinas;

  if ($Rotinas->ValidaCampo(
    $self->{edtCodigo}->GetValue(), $Resource::STR_CODNINF)) {
    return $Resoure::false;
  }
  if ($bTodosDados) {
	  if ($Rotinas->ValidaCampo(
      $self->{edtDescricao}->GetValue(), $Resource::STR_ENDNINF)) {
  		return $Resoure::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtBairro}->GetValue(), $Resource::STR_BAIRRONINF)) {
  		return $Resoure::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtCEP}->GetValue(), $Resource::STR_CEPNINF)) {
  		return $Resoure::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtCidade}->GetValue(), $Resource::STR_CIDADENINF)) {
  		return $Resoure::false;
    }
  }
  return $Resource::true;
}

sub OnBtnNovoClick {
  my( $self, $event ) = @_;

  $self->btnNovoClick();
  $self->InformaLimpaDadosLocal($Resource::false);
  $self->HabilitaDadosLocal($Resource::true);
  $self->NovoDado($ConsultasSQL::ConsSQL->Endereco('N', 
    $self->{edtCodigo}->GetValue(),"","","","",""));
  $event->Skip();
}

sub OnBtnPesquisarClick {
  my( $self, $event ) = @_;

  if ($self->PesquisarDados($ConsultasSQL::ConsSQL->Endereco('S', 
    $self->{edtCodigo}->GetValue(),"","","","",""), $Resource::STR_ENDNENC)) {
    $self->InformaLimpaDadosLocal($Resource::true);
    $self->HabilitaDadosLocal($Resource::true);
  }
  $event->Skip();
}

sub OnBtnAnteriorClick {
  my( $self, $event ) = @_;

  if ($self->registroAnterior()) {
    $self->InformaLimpaDadosLocal($Resource::true);
  }
  $event->Skip();
}

sub OnBtnProximoClick {
  my( $self, $event ) = @_;

  if ($self->registroProximo()) {
    $self->InformaLimpaDadosLocal($Resource::true);
  }
  $event->Skip();
}

sub OnBtnSalvarClick {
  my( $self, $event ) = @_;

  my $ConsSQL = $ConsultasSQL::ConsSQL;
  if ($self->SalvarDados($self->ValidaDados($Resource::true),
    $ConsSQL->Endereco('S', $self->{edtCodigo}->GetValue(),
    "","","","",""),
    $ConsSQL->Endereco('U', $self->{edtCodigo}->GetValue(), 
    $self->{edtDescricao}->GetValue(),$self->{edtBairro}->GetValue(),
    $self->{edtCEP}->GetValue(),$self->{edtCidade}->GetValue(), 
    $self->{cmbEstado}->GetStringSelection()),
    $ConsSQL->Endereco('I', $self->{edtCodigo}->GetValue(), 
    $self->{edtDescricao}->GetValue(),$self->{edtBairro}->GetValue(),
    $self->{edtCEP}->GetValue(),$self->{edtCidade}->GetValue(), 
    $self->{cmbEstado}->GetStringSelection()), $Resource::true)) {
    $self->InformaLimpaDadosLocal($Resource::false);
    $self->HabilitaDadosLocal($Resource::false);
  }
  $event->Skip();
}

sub OnBtnExcluirClick {
  my( $self, $event ) = @_;

  if ($self->ExcluirDados($self->ValidaDados($Resource::false),
    $ConsultasSQL::ConsSQL->Endereco('D', $self->{edtCodigo}->GetValue(),
    "","","","",""))) {
    $self->InformaLimpaDadosLocal($Resource::false);
    $self->HabilitaDadosLocal($Resource::false);
  }
  $event->Skip();
}

sub OnBtnLimparClick {
  my( $self, $event ) = @_;

  $self->btnLimparClick();
  $self->InformaLimpaDadosLocal($Resource::false);
  $self->HabilitaDadosLocal($Resource::false);
  $event->Skip();
}

sub OnBtnFecharClick {
  my( $self, $event ) = @_;

  $self->GetParent()->Close();
  $event->Skip();
}

sub InformaLimpaDadosLocal {
  my( $self, $bInformar ) = @_;

  if ($bInformar) {
    my @lista = $self->{lstRegistros}->col();
    $self->{edtBairro}->SetValue($lista[$self->{nLinhaRegistro}][2]);
    $self->{edtCEP}->SetValue($lista[$self->{nLinhaRegistro}][3]);
    $self->{edtCidade}->SetValue($lista[$self->{nLinhaRegistro}][4]);
    $self->{cmbEstado}->SetStringSelection($lista[$self->{nLinhaRegistro}][5]);
  } else {
    $self->{edtBairro}->Clear();
    $self->{edtCEP}->Clear();
    $self->{edtCidade}->Clear();
    $self->{cmbEstado}->SetSelection(0);
  }
}

sub HabilitaDadosLocal {
  my( $self, $bHabilita ) = @_; 

  $self->{edtBairro}->Enable($bHabilita);
  $self->{edtCEP}->Enable($bHabilita);
  $self->{edtCidade}->Enable($bHabilita);
  $self->{cmbEstado}->Enable($bHabilita);  
}

sub AdicionaCombo {
  my $self = shift; 

  $self->{cmbEstado}->Append($Resource::STR_PE);
  $self->{cmbEstado}->Append($Resource::STR_AC);
  $self->{cmbEstado}->Append($Resource::STR_AL);
  $self->{cmbEstado}->Append($Resource::STR_AP);
  $self->{cmbEstado}->Append($Resource::STR_AM);
  $self->{cmbEstado}->Append($Resource::STR_BA);
  $self->{cmbEstado}->Append($Resource::STR_BR);
  $self->{cmbEstado}->Append($Resource::STR_CE);
  $self->{cmbEstado}->Append($Resource::STR_DF);
  $self->{cmbEstado}->Append($Resource::STR_ES);
  $self->{cmbEstado}->Append($Resource::STR_GO);
  $self->{cmbEstado}->Append($Resource::STR_MT);
  $self->{cmbEstado}->Append($Resource::STR_MS);
  $self->{cmbEstado}->Append($Resource::STR_MG);
  $self->{cmbEstado}->Append($Resource::STR_PA);
  $self->{cmbEstado}->Append($Resource::STR_PB);
  $self->{cmbEstado}->Append($Resource::STR_PR);
  $self->{cmbEstado}->Append($Resource::STR_SC);
  $self->{cmbEstado}->Append($Resource::STR_RN);
  $self->{cmbEstado}->Append($Resource::STR_RS);
  $self->{cmbEstado}->Append($Resource::STR_RJ);
  $self->{cmbEstado}->Append($Resource::STR_RO);
  $self->{cmbEstado}->Append($Resource::STR_RR);
  $self->{cmbEstado}->Append($Resource::STR_SP);
  $self->{cmbEstado}->Append($Resource::STR_SE);
  $self->{cmbEstado}->Append($Resource::STR_TO);
}

1;

