use Wx 0.15 qw[:allclasses];
use strict;
package frmCadastros;

use Wx qw[:everything];
use base qw(Wx::Panel);
use Wx::Event qw(EVT_CLOSE);

require TextValidatorCtrl;
require RotinasGlobais;
require ListaStr;
require resource;

my( $ID_FRMCADASTROS_BTNANTERIOR, $ID_FRMCADASTROS_BTNEXCLUIR, 
  $ID_FRMCADASTROS_BTNFECHAR, $ID_FRMCADASTROS_BTNLIMPAR, 
  $ID_FRMCADASTROS_BTNNOVO, $ID_FRMCADASTROS_BTNPESQUISAR, 
  $ID_FRMCADASTROS_BTNPROXIMO, $ID_FRMCADASTROS_BTNSALVAR, 
  $ID_FRMCADASTROS_EDTCODIGO, $ID_FRMCADASTROS_EDTDESCRICAO, 
  $ID_FRMCADASTROS_LABCODIGO, $ID_FRMCADASTROS_LABDESCRICAO ) = 
  ( 3000 .. 3012 );

sub new {
	my( $self, $parent, $nFiltroCodigo, $bIniciaBotoes ) = @_;
	$parent = undef   unless defined $parent;

	$self = $self->SUPER::new( $parent, -1, wxDefaultPosition, wxDefaultSize, 
    wxTAB_TRAVERSAL, "" );
  EVT_CLOSE( $self, \&OnClose );

	$self->{labCodigo} = Wx::StaticText->new($self, $ID_FRMCADASTROS_LABCODIGO, 
    "Código:", wxPOINT(8, 8), wxSIZE(36, 13) );
	$self->{edtCodigo} = TextValidatorCtrl->new($self, $ID_FRMCADASTROS_EDTCODIGO, "", 
    wxPOINT(8, 24), wxSIZE(121, 21), 0, $nFiltroCodigo);
  $self->{edtCodigo}->SetMaxLength(10);
	$self->{btnNovo} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNNOVO, "&Novo",
    wxPOINT(144, 24), wxSIZE(75, 25));
	$self->{labDescricao} = Wx::StaticText->new($self, $ID_FRMCADASTROS_LABDESCRICAO, 
    "Descrição:", wxPOINT(8, 48), wxSIZE(51, 13) );
	$self->{edtDescricao} = Wx::TextCtrl->new($self, $ID_FRMCADASTROS_EDTDESCRICAO,
   "", wxPOINT(8, 64), wxSIZE(217, 21) );
	$self->{edtDescricao}->Enable($Resource::false);
  $self->{edtDescricao}->SetMaxLength(30);

  if ($bIniciaBotoes) {
    $self->IniciaBotoes();
  	$self->FazLayout();
  }

  $self->{lstRegistros} = ListaStr->new();
  $self->{nLinhaRegistro} = 0;
	return $self;
}

sub IniciaBotoes {
	my $self = shift;

	$self->{btnPesquisar} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNPESQUISAR, 
    "&Pesquisar", wxPOINT(248, 8), wxSIZE(75, 25) );
	$self->{btnAnterior} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNANTERIOR,
    "&Anterior", wxPOINT(248, 40), wxSIZE(75, 25) );
	$self->{btnAnterior}->Enable($Resource::false);
	$self->{btnProximo} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNPROXIMO,
    "Próxi&mo", wxPOINT(248, 72), wxSIZE(75, 25) );
	$self->{btnProximo}->Enable($Resource::false);
	$self->{btnSalvar} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNSALVAR, 
    "&Salvar", wxPOINT(8, 104), wxSIZE(75, 25) );
	$self->{btnSalvar}->Enable($Resource::false);
	$self->{btnExcluir} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNEXCLUIR, 
    "&Excluir", wxPOINT(88, 104), wxSIZE(75, 25) );
	$self->{btnExcluir}->Enable($Resource::false);
	$self->{btnLimpar} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNLIMPAR, 
    "&Limpar", wxPOINT(168, 104), wxSIZE(75, 25) );
	$self->{btnFechar} = Wx::Button->new($self, $ID_FRMCADASTROS_BTNFECHAR, 
    "&Fechar", wxPOINT(248, 104), wxSIZE(75, 25) );
  $self->btnLimparClick();
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_2} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_3} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_4} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_5} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{grid_sizer_2} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_1} = Wx::GridSizer->new(2, 2, 0, 1);
	$self->{grid_sizer_1}->Add($self->{labCodigo}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_1}->Add(20, 10, 0, 0, 0);
	$self->{grid_sizer_1}->Add($self->{edtCodigo}, 0, 0, 0);
	$self->{grid_sizer_1}->Add($self->{btnNovo}, 0, wxLEFT, 6);
	$self->{sizer_5}->Add($self->{grid_sizer_1}, 0, 0, 0);
	$self->{grid_sizer_2}->Add($self->{labDescricao}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_2}->Add($self->{edtDescricao}, 0, 0, 2);
	$self->{sizer_5}->Add($self->{grid_sizer_2}, 0, 0, 0);
	$self->{sizer_3}->Add($self->{sizer_5}, 1, 0, 0);
	$self->{sizer_4}->Add($self->{btnPesquisar}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_4}->Add($self->{btnAnterior}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_4}->Add($self->{btnProximo}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_3}->Add($self->{sizer_4}, 0, wxALIGN_RIGHT, 0);
	$self->{sizer_1}->Add($self->{sizer_3}, 1, wxALL|wxEXPAND, 4);
	$self->{sizer_2}->Add($self->{btnSalvar}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_2}->Add($self->{btnExcluir}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_2}->Add($self->{btnLimpar}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_2}->Add($self->{btnFechar}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_1}->Add($self->{sizer_2}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4);
	$self->SetAutoLayout(1);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);
}

sub InformaLimpaDados {
my( $self, $bInformar) = @_;

  if ($bInformar) {
    my @lista = $self->{lstRegistros}->col();
    $self->{edtCodigo}->SetValue($lista[$self->{nLinhaRegistro}][0]);
    $self->{edtDescricao}->SetValue($lista[$self->{nLinhaRegistro}][1]);
  } else {
    $self->{edtCodigo}->Clear();
    $self->{edtDescricao}->Clear();
    $self->{edtCodigo}->Enable($Resource::true);
    $self->{edtCodigo}->SetFocus();
  }
}

sub HabilitaDados {
my( $self, $bHabilita) = @_;

  $self->{edtDescricao}->Enable($bHabilita);
}

sub btnNovoClick {
my $self = shift;

  $self->{btnSalvar}->Enable($Resource::true);
  $self->{btnExcluir}->Enable($Resource::false);
  $self->{btnPesquisar}->Enable($Resource::false);
  $self->{btnAnterior}->Enable($Resource::false);
  $self->{btnProximo}->Enable($Resource::false);
  $self->{btnNovo}->Enable($Resource::false);
  
  $self->{nLinhaRegistro} = 0;
  $self->InformaLimpaDados($Resource::false);
  $self->HabilitaDados($Resource::true);
}

sub NovoDado {
my( $self, $sTextoSql) = @_;

  my $Rotinas = $RotinasGlobais::Rotinas;
  my $lstRegs = ListaStr->new();

  if ($Rotinas->ConsultaDadosLista($Rotinas->atrib('gConexao'), 
    $lstRegs, $sTextoSql)) {
    my @lista = $lstRegs->col();
    $self->{edtCodigo}->SetValue($lista[0][0]);
    $self->{edtCodigo}->Enable($Resource::false);
    $self->{edtDescricao}->SetFocus();
  }
}

sub btnLimparClick {
my $self = shift;

  $self->{nLinhaRegistro} = 0;
  $self->{btnSalvar}->Enable($Resource::false);
  $self->{btnExcluir}->Enable($Resource::false);
  $self->{btnPesquisar}->Enable($Resource::true);
  $self->{btnAnterior}->Enable($Resource::false);
  $self->{btnProximo}->Enable($Resource::false);
  $self->{btnNovo}->Enable($Resource::true);

  $self->InformaLimpaDados($Resource::false);
  $self->HabilitaDados($Resource::false);
}

sub ExcluirDados {
my( $self, $bValidaDados, $sTextoSql ) = @_;

  if ($bValidaDados) {
    my $Rotinas = $RotinasGlobais::Rotinas;
    if (Wx::MessageBox($Resource::STR_CERTEXCL, "Confirme",
        wxYES_NO | wxICON_QUESTION, $self) == wxYES) {
      if ($Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), $sTextoSql)) {
        $self->btnLimparClick();
        return $Resource::true;
      }
    }
  }
  return $Resource::false;
}

sub PesquisarDados {
my( $self, $sTextoSql, $sMensagemErro ) = @_;
my $Rotinas = $RotinasGlobais::Rotinas;

  if (length($self->{edtCodigo}->GetValue()) == 0) {
    $self->{btnAnterior}->Enable($Resource::true);
    $self->{btnProximo}->Enable($Resource::true);
  }
  if ($Rotinas->ConsultaDadosLista($Rotinas->atrib('gConexao'), 
      $self->{lstRegistros}, $sTextoSql)) {
     $self->InformaLimpaDados($Resource::true);
     $self->HabilitaDados($Resource::true);

     $self->{btnSalvar}->Enable($Resource::true);
     $self->{btnExcluir}->Enable($Resource::true);
     $self->{btnPesquisar}->Enable($Resource::false);
     return $Resource::true;
  } else {
    Wx::MessageBox($sMensagemErro, 'Erro', wxOK | wxICON_ERROR);
  }  
  return $Resource::false;
}

sub registroAnterior {
my $self = shift;

  if ($self->{nLinhaRegistro} > 0) {
    $self->{nLinhaRegistro} = $self->{nLinhaRegistro} - 1;
    $self->InformaLimpaDados($Resource::true);
    return $Resource::true;
  } else {
    return $Resource::false;
  }
}

sub registroProximo {
my $self = shift;

  if ($self->{nLinhaRegistro} < ($self->{lstRegistros}->tam-1)) {
    $self->{nLinhaRegistro} = $self->{nLinhaRegistro} + 1;
    $self->InformaLimpaDados($Resource::true);
    return $Resource::true;
  } else {
    return $Resource::false;
  }
}

sub SalvarDados {
my( $self, $bValidaDados, $sTextoSql, 
  $sTextoUpdate, $sTextoInsert, $bLimparDados) = @_;
my $sArquiva = '';
my $Rotinas = $RotinasGlobais::Rotinas;

  if ($bValidaDados) {
    if ($Rotinas->ConsultaDados($Rotinas->atrib('gConexao'), $sTextoSql)) {
      $sArquiva = $sTextoUpdate;
    } else {
      $sArquiva = $sTextoInsert;
    }
    if ($Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), $sArquiva)) {
      if ($bLimparDados) {
        $self->btnLimparClick();
      }
      return $Resource::true;
    }  
  }
  return $Resource::false;
}

sub OnClose {
  my( $self, $event ) = @_;

  $self->Destroy();
}

1;

