use Wx 0.15 qw[:allclasses];
use strict;
use Cadastros qw[:allclasses];
package frmVenderLivros;

use Wx qw[:everything];
use base qw(frmCadastros);
use strict;
use Wx::Event qw(EVT_BUTTON EVT_KILL_FOCUS EVT_LISTBOX_DCLICK);

require RotinasGlobais;
require ConsultasSQL;
require resource;
require ListaStr;
require ConClientes;
require ConLivros;

my ( $ID_FRMVENDERLIVROS_BTNADLIVROS, 
 $ID_FRMVENDERLIVROS_BTNFECHAR, $ID_FRMVENDERLIVROS_BTNLIMPAR, 
 $ID_FRMVENDERLIVROS_BTNPCLIENTE, $ID_FRMVENDERLIVROS_BTNPLIVRO, 
 $ID_FRMVENDERLIVROS_BTNVENDER, $ID_FRMVENDERLIVROS_EDTDTHRVENDA, 
 $ID_FRMVENDERLIVROS_EDTISBN, $ID_FRMVENDERLIVROS_EDTLIVRO, 
 $ID_FRMVENDERLIVROS_EDTPRECOTOTAL, $ID_FRMVENDERLIVROS_LABDTHRVENDA, 
 $ID_FRMVENDERLIVROS_LABISBN, $ID_FRMVENDERLIVROS_LABLIVRO, 
 $ID_FRMVENDERLIVROS_LABLIVROS, $ID_FRMVENDERLIVROS_LABPRECOTOTAL, 
 $ID_FRMVENDERLIVROS_LSTLIVROS ) = ( 9000 .. 9015 );

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;	

	$self = $self->SUPER::new( $parent, $TextValidatorCtrl::FILTER_NONE, 
    $Resource::false );
  $self->SetClientSize(481, 309);
  $self->{btnNovo}->Show($Resource::false);

	$self->{labDtHrVenda} = Wx::StaticText->new($self, 
    $ID_FRMVENDERLIVROS_LABDTHRVENDA, "Data/Hora Venda: ", 
    wxPOINT(8, 8), wxSIZE(91, 13) );
	$self->{edtDtHrVenda} = Wx::TextCtrl->new($self, 
    $ID_FRMVENDERLIVROS_EDTDTHRVENDA, "", 
    wxPOINT(8, 24), wxSIZE(128, 21) );
	$self->{edtDtHrVenda}->Enable($Resource::false);

  $self->{labCodigo}->SetLabel("CPF: ");  
  $self->{labCodigo}->SetSize(8, 48, 48, 13); 
  $self->{edtCodigo}->SetSize(8, 64, 128, 21);
  EVT_KILL_FOCUS($self->{edtCodigo}, \&OnEdtCodigo_Killfocus);

  $self->{labDescricao}->SetLabel("Cliente: ");  
  $self->{labDescricao}->SetSize(142, 48, 56, 13);
  $self->{edtDescricao}->SetSize(142, 64, 306, 21);
  $self->{edtDescricao}->Enable($Resource::false);

	$self->{btnPCliente} = Wx::Button->new($self, 
    $ID_FRMVENDERLIVROS_BTNPCLIENTE, "...", wxPOINT(448, 64), wxSIZE(21, 21));
  EVT_BUTTON( $self, $self->{btnPCliente}->GetId(), \&OnBtnPClienteClick );
	$self->{labISBN} = Wx::StaticText->new($self, 
    $ID_FRMVENDERLIVROS_LABISBN, "ISBN: ", wxPOINT(8, 88), wxSIZE(48, 13) );
	$self->{edtISBN} = Wx::TextCtrl->new($self, $ID_FRMVENDERLIVROS_EDTISBN, "",
    wxPOINT(8, 104), wxSIZE(128, 21) );
  EVT_KILL_FOCUS($self->{edtISBN}, \&OnEdtISBN_Killfocus);
	$self->{labLivro} = Wx::StaticText->new($self, $ID_FRMVENDERLIVROS_LABLIVRO, 
    "Livro: ", wxPOINT(142, 88), wxSIZE(40, 13) );
	$self->{edtLivro} = Wx::TextCtrl->new($self, $ID_FRMVENDERLIVROS_EDTLIVRO, 
    "", wxPOINT(142, 104), wxSIZE(282, 21) );
	$self->{edtLivro}->Enable($Resource::false);
	$self->{btnAdLivros} = Wx::Button->new($self, 
    $ID_FRMVENDERLIVROS_BTNADLIVROS, "+", wxPOINT(424, 104), wxSIZE(21, 21));
  EVT_BUTTON( $self, $self->{btnAdLivros}->GetId(), \&OnBtnAdLivrosClick );
	$self->{btnPLivro} = Wx::Button->new($self, $ID_FRMVENDERLIVROS_BTNPLIVRO, 
    "...",wxPOINT(448, 104), wxSIZE(21, 21));
  EVT_BUTTON( $self, $self->{btnPLivro}->GetId(), \&OnBtnPLivroClick );
	$self->{labLivros} = Wx::StaticText->new($self, 
    $ID_FRMVENDERLIVROS_LABLIVROS, "Livros para vender: ", 
    wxPOINT(8, 128), wxSIZE(120, 13) );
	$self->{lstLivros} = Wx::ListBox->new($self, $ID_FRMVENDERLIVROS_LSTLIVROS, 
    wxPOINT(8, 144), wxSIZE(464, 96) );
	$self->{lstLivros}->SetSelection(0);
  EVT_LISTBOX_DCLICK($self, $ID_FRMVENDERLIVROS_LSTLIVROS, 
    \&OnLstLivros_Dblclk);
	$self->{labPrecoTotal} = Wx::StaticText->new($self, 
    $ID_FRMVENDERLIVROS_LABPRECOTOTAL, "Preço Total: ", 
    wxPOINT(280, 248), wxSIZE(61, 13) );
	$self->{edtPrecoTotal} = Wx::TextCtrl->new($self, 
    $ID_FRMVENDERLIVROS_EDTPRECOTOTAL, "", wxPOINT(344, 246), wxSIZE(127, 21) );
	$self->{edtPrecoTotal}->Enable($Resource::false);
	$self->{btnVender} = Wx::Button->new($self, $ID_FRMVENDERLIVROS_BTNVENDER, 
    "&Vender", wxPOINT(239, 275), wxSIZE(75, 25));
	$self->{btnLimpar} = Wx::Button->new($self, $ID_FRMVENDERLIVROS_BTNLIMPAR, 
    "&Limpar", wxPOINT(319, 275), wxSIZE(75, 25));
	$self->{btnFechar} = Wx::Button->new($self, $ID_FRMVENDERLIVROS_BTNFECHAR, 
    "&Fechar", wxPOINT(399, 275), wxSIZE(75, 25));

	$self->FazLayout();

  EVT_BUTTON($self, $self->{btnVender}->GetId(), \&OnBtnVenderClick);
  EVT_BUTTON($self, $self->{btnLimpar}->GetId(), \&OnBtnLimparClick);
  EVT_BUTTON($self, $self->{btnFechar}->GetId(), \&OnBtnFecharClick);

  $self->{slPrecos} = ListaStr->new();
  $self->{slISBNs} = ListaStr->new();
  $self->{slQtdEstoque} = ListaStr->new();
  $self->{nPrecoTotal} = 0.0;

  $self->{edtCodigo}->SetMaxLength(14);
  $self->{edtISBN}->SetMaxLength(13);
  $self->LimpaDados();

	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_6} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_8} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_7} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_5} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_4} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_8} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_7} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_6} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_5} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_3} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_4} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_3} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_2} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_2} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_1} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_1}->Add($self->{labDtHrVenda}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_1}->Add($self->{edtDtHrVenda}, 0, 0, 0);
	$self->{sizer_2}->Add($self->{grid_sizer_1}, 0, wxLEFT, 2);
	$self->{sizer_2}->Add(20, 20, 0, 0, 0);
	$self->{sizer_1}->Add($self->{sizer_2}, 0, 0, 0);
	$self->{grid_sizer_2}->Add($self->{labCodigo}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_2}->Add($self->{edtCodigo}, 0, 0, 0);
	$self->{sizer_3}->Add($self->{grid_sizer_2}, 0, wxLEFT, 2);
	$self->{grid_sizer_3}->Add($self->{labDescricao}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_3}->Add($self->{edtDescricao}, 0, 0, 0);
	$self->{sizer_3}->Add($self->{grid_sizer_3}, 0, wxLEFT, 2);
	$self->{grid_sizer_4}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_4}->Add($self->{btnPCliente}, 0, 0, 0);
	$self->{sizer_3}->Add($self->{grid_sizer_4}, 0, 0, 0);
	$self->{sizer_1}->Add($self->{sizer_3}, 0, 0, 0);
	$self->{grid_sizer_5}->Add($self->{labISBN}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_5}->Add($self->{edtISBN}, 0, 0, 0);
	$self->{sizer_4}->Add($self->{grid_sizer_5}, 0, wxLEFT, 2);
	$self->{grid_sizer_6}->Add($self->{labLivro}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_6}->Add($self->{edtLivro}, 0, 0, 0);
	$self->{sizer_4}->Add($self->{grid_sizer_6}, 0, wxLEFT, 2);
	$self->{grid_sizer_7}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_7}->Add($self->{btnAdLivros}, 0, 0, 0);
	$self->{sizer_4}->Add($self->{grid_sizer_7}, 1, wxEXPAND, 0);
	$self->{grid_sizer_8}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_8}->Add($self->{btnPLivro}, 0, 0, 0);
	$self->{sizer_4}->Add($self->{grid_sizer_8}, 0, 0, 0);
	$self->{sizer_1}->Add($self->{sizer_4}, 0, 0, 0);
	$self->{sizer_5}->Add($self->{labLivros}, 0, wxALIGN_BOTTOM, 0);
	$self->{sizer_5}->Add($self->{lstLivros}, 1, wxALL|wxEXPAND, 1);
	$self->{sizer_1}->Add($self->{sizer_5}, 1, wxEXPAND, 0);
	$self->{sizer_7}->Add($self->{labPrecoTotal}, 0, wxALL, 2);
	$self->{sizer_7}->Add($self->{edtPrecoTotal}, 0, wxALL, 2);
	$self->{sizer_6}->Add($self->{sizer_7}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_8}->Add($self->{btnVender}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_8}->Add($self->{btnLimpar}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_8}->Add($self->{btnFechar}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_6}->Add($self->{sizer_8}, 0, wxALL, 2);
	$self->{sizer_1}->Add($self->{sizer_6}, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 0);
	$self->SetAutoLayout(1);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);
}

sub LimpaDados {
my $self = shift;

  $self->{edtDtHrVenda}->SetValue($RotinasGlobais::Rotinas->retDataHoraStr(
    $Resource::true, $Resource::true)); 
  $self->{edtCodigo}->Clear();
  $self->{edtDescricao}->Clear();
  $self->{edtISBN}->Clear();
  $self->{edtLivro}->Clear();
  $self->{lstLivros}->Clear();
  $self->{nPrecoTotal} = 0;
  $self->{slPrecos}->clear();
  $self->{slISBNs}->clear();
  $self->{slQtdEstoque}->clear();
  $self->{edtPrecoTotal}->SetValue("R\$ 0,00");
  $self->{edtCodigo}->SetFocus();
}

sub ValidaDados {
my $self = shift;

  if ($RotinasGlobais::Rotinas->ValidaCampo(
    $self->{edtCodigo}->GetValue(), $Resource::STR_CPFNINF)) {
    return $Resource::false;
  }
  if ($self->{lstLivros}->GetCount()==0) {
    Wx::MessageBox($Resource::STR_LIVVENNINF, "Erro", wxOK | wxICON_ERROR);
    return $Resource::false;
  }
  return $Resource::true;
}

sub SalvaLista {
my $self = shift;

  my $Rotinas = $RotinasGlobais::Rotinas;
  my $ConsSQL = $ConsultasSQL::ConsSQL;
  my $nQtd = $self->{lstLivros}->GetCount();
  my $sCPF = $self->{edtCodigo}->GetValue();
  my $sPrecoTotal = sprintf('%.2f',$self->{nPrecoTotal});
  
  my $sDTHR = $self->{edtDtHrVenda}->GetValue();
  my $sDataHora = $Rotinas->ConverteDataHoraStr($sDTHR, $Resource::true, 
    "%m/%d/%Y","%H:%M:%S");
  my ($nCont, $sISBN, $nQtdEstoque, $sQtdEstoque);
  my @lista = $self->{slISBNs}->col();
  my @lista2 = $self->{slQtdEstoque}->col();
  for ($nCont=0; $nCont < $nQtd; $nCont++) {
    $sISBN = $lista[$nCont];
    
    $Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), 
      $ConsSQL->Venda('I',$sISBN, $sCPF, $sDataHora,
      $Rotinas->VirgulaParaPonto($sPrecoTotal,$Resource::false),""));
  
    $nQtdEstoque = $lista2[$nCont];
    if ($nQtdEstoque > 0) {
      $nQtdEstoque = $nQtdEstoque - 1;
    }
    $sQtdEstoque = $nQtdEstoque;
    $Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), 
      $ConsSQL->Venda('U',$sISBN, "","","", $sQtdEstoque));
  }
  return $Resource::true;
}

sub OnEdtCodigo_Killfocus {
  my( $self, $event ) = @_;

  my $Rotinas = $RotinasGlobais::Rotinas;
  my $ConsSQL = $ConsultasSQL::ConsSQL;
  my $ConsCampo = ListaStr->new();

  if (length($self->GetValue()) > 0) {
    if ($Rotinas->validaCPF($self->GetValue())) {
      my $sCliente = $Rotinas->ConsultaCampoDesc($ConsCampo, 
      $ConsSQL->Cliente('S', $self->GetValue(),
      "","","","","","","","",""), $Resource::STR_CLINENC);
      if (length($sCliente)==0) {
        $self->Clear();
        $self->SetFocus();
      } else {
        $self->GetParent()->{edtDescricao}->SetValue($sCliente);
      }
    } else {
      Wx::MessageBox($Resource::STR_CPFINV, "Erro", wxOK | wxICON_ERROR);
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent()->{edtDescricao}->Clear();
  }
  $event->Skip();
}

sub OnBtnPClienteClick {
  my( $self, $event ) = @_;

  my $fConClientes = frmConClientes->new($self);
  $fConClientes->ShowModal();
  $self->{edtCodigo}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCodigo_Killfocus($self->{edtCodigo}, $event);
  $event->Skip();
}

sub OnEdtISBN_Killfocus {
  my( $self, $event ) = @_;

  my $Rotinas = $RotinasGlobais::Rotinas;
  my $ConsSQL = $ConsultasSQL::ConsSQL;
  my $ConsCampo = ListaStr->new();

  if (length($self->GetValue()) > 0) {
    if ($Rotinas->validaISBN($self->GetValue())) {
      my $sLivro = $Rotinas->ConsultaCampoDesc($ConsCampo, $ConsSQL->Livro('Q',
      $self->GetValue(),"","","","","","","","",""), $Resource::STR_LIVNENC);
      if (length($sLivro)==0) {
        $self->Clear();
        $self->SetFocus();
      } else {
        $self->GetParent()->{edtLivro}->SetValue($sLivro);
        my @lista = $ConsCampo->col();
        my $nQtdEstoque = $lista[0][3];
        if ($nQtdEstoque > 0) {
          $Rotinas->set_atrib('sPreco', $lista[0][2]);
          $Rotinas->set_atrib('sQtdEstoque', $lista[0][3]);
        } else {
          Wx::MessageBox($Resource::STR_LIVNEST, "Erro", wxOK | wxICON_ERROR);
        }
      }
    } else {
      Wx::MessageBox($Resource::STR_ISBNINV, "Erro", wxOK | wxICON_ERROR);
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent()->{edtLivro}->Clear();
  }
  $event->Skip();
}

sub OnBtnAdLivrosClick {
  my( $self, $event ) = @_;

  my $Rotinas = $RotinasGlobais::Rotinas;
  my $sISBN = $self->{edtISBN}->GetValue();
  my $sEdtLivro = $self->{edtLivro}->GetValue();
  if (length($sISBN) > 0) {
    my $sLivros = $sISBN . " - " . $sEdtLivro . " - R\$ " . 
      $Rotinas->atrib('sPreco');
    my @lista1 = $self->{slISBNs}->col();
    my @lista2 = $self->{slPrecos}->col();
    my @lista3 = $self->{slQtdEstoque}->col();
    if ($self->{lstLivros}->FindString($sLivros) == -1) {
      push @lista1, $sISBN;
      $self->{slISBNs}->set_col(@lista1);
      push @lista2, $Rotinas->atrib('sPreco');
      $self->{slPrecos}->set_col(@lista2);
      push @lista3, $Rotinas->atrib('sQtdEstoque');
      $self->{slQtdEstoque}->set_col(@lista3);
      $self->{lstLivros}->Append($sLivros);
      my $nPreco = $Rotinas->atrib('sPreco');
      $self->{nPrecoTotal} = $self->{nPrecoTotal} + $nPreco;
    }
    $self->{edtISBN}->Clear();
    $self->{edtLivro}->Clear();
    my $sPrecoTotal = sprintf('R$ %.2f',$self->{nPrecoTotal});
    $self->{edtPrecoTotal}->SetValue(
      $Rotinas->VirgulaParaPonto($sPrecoTotal,$Resource::true));
  }
  $event->Skip();
}

sub OnBtnPLivroClick {
  my( $self, $event ) = @_;

  my $fConLivros = frmConLivros->new($self);
  $fConLivros->ShowModal();
  $self->{edtISBN}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtISBN_Killfocus($self->{edtISBN}, $event);
  $event->Skip();
}

sub OnLstLivros_Dblclk {
  my( $self, $event ) = @_;

  if ($self->{lstLivros}->GetCount() > 0) {
    my $nSelIndice = $self->{lstLivros}->GetSelection();
    if ($self->{lstLivros}->Selected($nSelIndice) ) {
      my @lista = $self->{slPrecos}->col();
      my $nPreco = $lista[$nSelIndice];
      $self->{nPrecoTotal} = $self->{nPrecoTotal}-$nPreco;
      my $sPrecoTotal = sprintf('R$ %.2f',$self->{nPrecoTotal});
      $self->{edtPrecoTotal}->SetValue(
        $RotinasGlobais::Rotinas->VirgulaParaPonto($sPrecoTotal, 
        $Resource::true));

      my @lista1 = $self->{slISBNs}->col();
      my @lista2 = $self->{slPrecos}->col();
      my @lista3 = $self->{slQtdEstoque}->col();

      splice @lista1, $nSelIndice, 1;
      $self->{slISBNs}->set_col(@lista1);
      splice @lista2, $nSelIndice, 1;
      $self->{slPrecos}->set_col(@lista2);
      splice @lista3, $nSelIndice, 1;
      $self->{slQtdEstoque}->set_col(@lista3);
      $self->{lstLivros}->Delete($nSelIndice);
    }
  }
  $event->Skip();
}

sub OnBtnVenderClick {
  my( $self, $event ) = @_;

  if ($self->ValidaDados()) {
    if ($self->SalvaLista()) {
      Wx::MessageBox($Resource::STR_VENRESUC, 
        $Resource::STR_TITULO, wxOK | wxICON_INFORMATION);
      $self->LimpaDados();
    }
  }
  $event->Skip();
}

sub OnBtnLimparClick {
  my( $self, $event ) = @_;

  $self->LimpaDados();
  $event->Skip();
}

sub OnBtnFecharClick {
  my( $self, $event ) = @_;

  $self->GetParent()->Close();
  $event->Skip();
}

1;

