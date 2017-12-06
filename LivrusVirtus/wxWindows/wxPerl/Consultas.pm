use Wx 0.15 qw[:allclasses];
use strict;
package frmConsultas;

use Wx qw[:everything];
use base qw(Wx::Dialog);
use strict;
use Wx::Event qw(EVT_CLOSE EVT_BUTTON);
use Wx::Grid;

require resource;
require RotinasGlobais;
require ListaStr;
require Principal;

my ($ID_FRMCONSULTAS_BTNFECHAR, $ID_FRMCONSULTAS_BTNLIMPAR, 
 $ID_FRMCONSULTAS_BTNPESQUISAR, $ID_FRMCONSULTAS_EDTDESCRICAO, 
 $ID_FRMCONSULTAS_GRIDCONSULTA, $ID_FRMCONSULTAS_LABDESCRICAO, 
 $ID_FRMCONSULTAS_LABREGISTRO, $ID_FRMCONSULTAS_PANEL1, 
 $ID_FRMCONSULTAS_PANEL2, $ID_FRMCONSULTAS_SCROLLEDWINDOW1) 
 = (8000..8009);

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;

	$self = $self->SUPER::new( $parent, -1, "", wxDefaultPosition, 
    wxSIZE(355, 263), wxDEFAULT_DIALOG_STYLE | wxCAPTION | wxRESIZE_BORDER | 
    wxMINIMIZE_BOX | wxMAXIMIZE_BOX, "" );
	$self->SetClientSize(355, 263);
  $self->Centre(wxBOTH);
  EVT_CLOSE( $self, \&OnClose );

	$self->{labDescricao} = Wx::StaticText->new($self, 
    $ID_FRMCONSULTAS_LABDESCRICAO, "Descrição:", 
    wxPOINT(8, 8), wxSIZE(51, 13) );
	$self->{edtDescricao} = Wx::TextCtrl->new($self, 
    $ID_FRMCONSULTAS_EDTDESCRICAO, "", wxPOINT(8, 24), wxSIZE(257, 21) );
	$self->{btnPesquisar} = Wx::Button->new($self, $ID_FRMCONSULTAS_BTNPESQUISAR, 
    "&Pesquisar", wxPOINT(272, 24), wxSIZE(75, 25));
	$self->{gridConsulta} = Wx::Grid->new($self, $ID_FRMCONSULTAS_GRIDCONSULTA,
    wxPOINT(0, 56), wxSIZE(355, 125), wxSUNKEN_BORDER);
	$self->{gridConsulta}->CreateGrid(1, 2);
	$self->{gridConsulta}->SetColLabelSize(21);
  $self->{gridConsulta}->CreateGrid(1, 2, wxGridSelectRows);
	$self->{gridConsulta}->SetColLabelValue(0, "Código");
	$self->{gridConsulta}->SetColSize(0, 80);
	$self->{gridConsulta}->SetColLabelValue(1, "Descrição");
	$self->{gridConsulta}->SetColSize(1, 180);
  $self->{gridConsulta}->EnableEditing($Resource::false);
  $self->{gridConsulta}->HideCellEditControl();
  $self->{gridConsulta}->SetColLabelSize(21);
	$self->{labRegistro} = Wx::StaticText->new($self, 
    $ID_FRMCONSULTAS_LABREGISTRO, "Registro 0 de 0", 
    wxPOINT(8, 16), wxSIZE(144, 13) );
	$self->{btnLimpar} = Wx::Button->new($self, 
    $ID_FRMCONSULTAS_BTNLIMPAR, "&Limpar", wxPOINT(188, 13), wxSIZE(75, 25));
	$self->{btnFechar} = Wx::Button->new($self, 
    $ID_FRMCONSULTAS_BTNFECHAR, "&Fechar", wxPOINT(268, 13), wxSIZE(75, 25));

	$self->FazLayout();

  $self->{edtDescricao}->SetFocus();
  $self->{lstLinhas} = ListaStr->new();
  $self->{sSelecionado} = '';
  $self->{nRegistro} = 0;

  EVT_BUTTON( $self, $self->{btnFechar}->GetId(), \&OnBtnFecharClick );
	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{gird_sizer_2} = Wx::GridSizer->new(1, 2, 0, 0);
	$self->{sizer_2} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_3} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_4} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{grid_sizer_1} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_1}->Add($self->{labDescricao}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_1}->Add($self->{edtDescricao}, 0, 0, 0);
	$self->{sizer_3}->Add($self->{grid_sizer_1}, 0, wxALL, 2);
	$self->{sizer_4}->Add(20, 20, 0, 0, 0);
	$self->{sizer_4}->Add($self->{btnPesquisar}, 0, wxLEFT|wxTOP|wxBOTTOM, 5);
	$self->{sizer_3}->Add($self->{sizer_4}, 0, 0, 0);
	$self->{sizer_1}->Add($self->{sizer_3}, 0, wxALL, 4);
	$self->{sizer_1}->Add($self->{gridConsulta}, 1, wxEXPAND, 0);
	$self->{gird_sizer_2}->Add($self->{labRegistro}, 0, wxALL, 10);
	$self->{sizer_2}->Add($self->{btnLimpar}, 0, 
    wxALIGN_RIGHT|wxALIGN_BOTTOM, 8);
	$self->{sizer_2}->Add($self->{btnFechar}, 0, 
    wxLEFT|wxALIGN_RIGHT|wxALIGN_BOTTOM, 8);
	$self->{gird_sizer_2}->Add($self->{sizer_2}, 1, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4);
	$self->{sizer_1}->Add($self->{gird_sizer_2}, 0, 
    wxALL|wxEXPAND|wxALIGN_BOTTOM, 0);
	$self->SetAutoLayout($Resource::true);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);
	$self->Layout();
}

sub OnClose {
  my( $self, $event ) = @_;

  $self->Destroy();
}

sub OnBtnFecharClick {
  my( $self, $event ) = @_;

  $self->Close();
  $event->Skip();
}

sub Fecha {
my( $self, $nIndMenu ) = @_;
my $Rotinas = $RotinasGlobais::Rotinas;

  if (length($self->{sSelecionado}) > 0) {
    $Rotinas->set_atrib('sCodigoSelecionado', $self->{sSelecionado});
  } else {
    $Rotinas->set_atrib('sCodigoSelecionado', "");
  }

  if ($nIndMenu == 0) {
    if ($self->IsModal()) {
      $self->EndModal($Resource::true);
    } else {
      $self->Close();
    }
  } else {
    my $frmPrincipal = $Principal::fPrincipal;
    $frmPrincipal->{barraMenu}->GetMenu(1)->Enable($nIndMenu, $Resource::true);
  }
}

sub LimparDados {
my( $self ) = @_;

  $self->{labRegistro}->SetLabel("Registro 0 de 0");
  $self->{gridConsulta}->ClearGrid();
  $self->{gridConsulta}->DeleteRows(0, 
    $self->{gridConsulta}->GetNumberRows()-1, $Resource::true);
  $self->{edtDescricao}->Clear();
  $self->{edtDescricao}->SetFocus();
}

sub PesquisarDados {
my( $self, $sTextoSql, $sMensagemErro, $nQtdCol ) = @_;

  my $Rotinas = $RotinasGlobais::Rotinas;
  if ($Rotinas->ConsultaDadosLista(
    $Rotinas->atrib('gConexao'), $self->{lstLinhas}, $sTextoSql)) {
    $Rotinas->AdicionaLinhasGrid($self->{gridConsulta}, 
      $self->{lstLinhas}, $nQtdCol );
  } else {
    Wx::MessageBox($sMensagemErro, "Erro", wxOK | wxICON_ERROR );
  }  
}

sub setLabRegistros {
my( $self, $nLinha ) = @_;

  if ($nLinha >= 0) {
    $self->{labRegistro}->SetLabel("Registro " . ($nLinha+1) . " de " .
      $self->{gridConsulta}->GetNumberRows());
    $self->{sSelecionado} = $self->{gridConsulta}->GetCellValue($nLinha, 0);
  }
}

1;

