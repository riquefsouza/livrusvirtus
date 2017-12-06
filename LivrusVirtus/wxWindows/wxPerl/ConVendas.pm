use Wx 0.15 qw[:allclasses];
use strict;
package frmConVendas;

use Wx qw[:everything];
use base qw(Wx::Panel);
use strict;
use Wx::Event qw(EVT_CLOSE EVT_BUTTON EVT_KILL_FOCUS EVT_GRID_SELECT_CELL EVT_GRID_LABEL_LEFT_CLICK);
use Wx::Grid;

require RotinasGlobais;
require ConsultasSQL;
require resource;
require ListaStr;
require ConClientes;
require ConLivros;

my ($ID_FRMCONVENDAS_BTNFECHAR, $ID_FRMCONVENDAS_BTNLIMPAR, 
 $ID_FRMCONVENDAS_BTNPCLIENTE, $ID_FRMCONVENDAS_BTNPESQUISAR, 
 $ID_FRMCONVENDAS_BTNPLIVRO, $ID_FRMCONVENDAS_EDTCLIENTE, 
 $ID_FRMCONVENDAS_EDTCPF, $ID_FRMCONVENDAS_EDTDTHRVENDA, 
 $ID_FRMCONVENDAS_EDTISBN, $ID_FRMCONVENDAS_EDTLIVRO, 
 $ID_FRMCONVENDAS_EDTPRECOTOTAL, $ID_FRMCONVENDAS_GRIDVENDAS, 
 $ID_FRMCONVENDAS_LABCLIENTE, $ID_FRMCONVENDAS_LABCPF, 
 $ID_FRMCONVENDAS_LABDTHRVENDA, $ID_FRMCONVENDAS_LABISBN, 
 $ID_FRMCONVENDAS_LABLIVRO, $ID_FRMCONVENDAS_LABPRECOTOTAL, 
 $ID_FRMCONVENDAS_LABREGISTRO) = (9100 .. 9119);

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;

	$self = $self->SUPER::new( $parent, -1, wxPOINT(379, 218), 
    wxSIZE(480, 310), wxTAB_TRAVERSAL, "" );
  $self->SetClientSize(475, 306);
  EVT_CLOSE($self, \&OnClose);

	$self->{labDtHrVenda} = Wx::StaticText->new($self, 
    $ID_FRMCONVENDAS_LABDTHRVENDA, "Data/Hora Venda: ", 
    wxPOINT(8, 8), wxSIZE(91, 13) );
	$self->{edtDtHrVenda} = Wx::TextCtrl->new($self, 
    $ID_FRMCONVENDAS_EDTDTHRVENDA, "", wxPOINT(8, 24), wxSIZE(128, 21) );
  EVT_KILL_FOCUS($self->{edtDtHrVenda}, \&OnEdtDtHrVenda_Killfocus);
	$self->{btnPesquisar} = Wx::Button->new($self, $ID_FRMCONVENDAS_BTNPESQUISAR, 
    "&Pesquisar", wxPOINT(144, 22), wxSIZE(75, 25));
	$self->{labCPF} = Wx::StaticText->new($self, 
    $ID_FRMCONVENDAS_LABCPF, "CPF: ", wxPOINT(8, 48), wxSIZE(23,13) );
	$self->{edtCPF} = Wx::TextCtrl->new($self, 
    $ID_FRMCONVENDAS_EDTCPF, "", wxPOINT(8, 64), wxSIZE(128, 21) );
  EVT_KILL_FOCUS($self->{edtCPF}, \&OnEdtCPF_Killfocus);
	$self->{labCliente} = Wx::StaticText->new($self, 
    $ID_FRMCONVENDAS_LABCLIENTE, "Cliente: ", 
    wxPOINT(142, 48), wxSIZE(35, 13) );
	$self->{edtCliente} = Wx::TextCtrl->new($self, $ID_FRMCONVENDAS_EDTCLIENTE, 
    "", wxPOINT(142, 64), wxSIZE(306, 21) );
	$self->{edtCliente}->Enable($Resource::false);
	$self->{btnPCliente} = Wx::Button->new($self, $ID_FRMCONVENDAS_BTNPCLIENTE, 
    "...", wxPOINT(448, 64), wxSIZE(21, 21));
  EVT_BUTTON($self, $ID_FRMCONVENDAS_BTNPCLIENTE, 
    \&OnBtnPClienteClick);
	$self->{labISBN} = Wx::StaticText->new($self, $ID_FRMCONVENDAS_LABISBN, 
    "ISBN: ", wxPOINT(8, 88),wxSIZE(31, 13) );
	$self->{edtISBN} = Wx::TextCtrl->new($self, $ID_FRMCONVENDAS_EDTISBN, "", 
    wxPOINT(8, 104), wxSIZE(128, 21) );
  EVT_KILL_FOCUS($self->{edtISBN}, \&OnEdtISBN_Killfocus);
	$self->{labLivro} = Wx::StaticText->new($self, $ID_FRMCONVENDAS_LABLIVRO, 
    "Livro: ", wxPOINT(142, 88), wxSIZE(29, 13) );
	$self->{edtLivro} = Wx::TextCtrl->new($self, $ID_FRMCONVENDAS_EDTLIVRO, 
    "", wxPOINT(142, 104), wxSIZE(306, 21) );
	$self->{edtLivro}->Enable($Resource::false);
	$self->{btnPLivro} = Wx::Button->new($self, $ID_FRMCONVENDAS_BTNPLIVRO, 
    "...", wxPOINT(448, 104), wxSIZE(21, 21));
  EVT_BUTTON($self, $ID_FRMCONVENDAS_BTNPLIVRO, 
    \&OnBtnPLivroClick);
	$self->{gridVendas} = Wx::Grid->new($self, $ID_FRMCONVENDAS_GRIDVENDAS, 
    wxPOINT(0, 136), wxSIZE(472, 104), wxSUNKEN_BORDER);
	$self->{gridVendas}->CreateGrid(1, 6);
	$self->{gridVendas}->SetColLabelSize(21);
	$self->{gridVendas}->EnableEditing($Resource::false);
	$self->{gridVendas}->SetSelectionMode(wxGridSelectRows);
  $self->{gridVendas}->HideCellEditControl();
  EVT_GRID_SELECT_CELL($self, \&OnGridSelectCell);
  EVT_GRID_LABEL_LEFT_CLICK($self, \&OnGridLabelLeftClick);
	$self->{labRegistro} = Wx::StaticText->new($self, 
    $ID_FRMCONVENDAS_LABREGISTRO, "Registro 0 de 0", 
    wxPOINT(8, 248), wxSIZE(144, 13));
	$self->{labPrecoTotal} = Wx::StaticText->new($self, 
    $ID_FRMCONVENDAS_LABPRECOTOTAL, "Preço Total: ", 
    wxPOINT(280, 248), wxSIZE(61, 13) );
	$self->{edtPrecoTotal} = Wx::TextCtrl->new($self, 
    $ID_FRMCONVENDAS_EDTPRECOTOTAL, "", wxPOINT(344, 246), wxSIZE(127, 21) );
	$self->{edtPrecoTotal}->Enable($Resource::false);
	$self->{btnLimpar} = Wx::Button->new($self, $ID_FRMCONVENDAS_BTNLIMPAR, 
    "&Limpar",wxPOINT(312,272), wxSIZE(75, 25));
	$self->{btnFechar} = Wx::Button->new($self, $ID_FRMCONVENDAS_BTNFECHAR, 
    "&Fechar",wxPOINT(392,272), wxSIZE(75, 25));

	$self->FazLayout();

  EVT_BUTTON( $self, $self->{btnPesquisar}->GetId(), \&OnBtnPesquisarClick );
  EVT_BUTTON( $self, $self->{btnLimpar}->GetId(), \&OnBtnLimparClick );
  EVT_BUTTON( $self, $self->{btnFechar}->GetId(), \&OnBtnFecharClick );

  my @nLarguras_sRotulos = ( 120, 100, 220, 100, 280, 80,
    "Data/Hora Venda", "CPF", "Cliente", "ISBN", "Livro", "Preço" );

  $RotinasGlobais::Rotinas->AdicionaColunasGrid(
    $self->{gridVendas}, 0, 6, @nLarguras_sRotulos);
  $self->{gridVendas}->EnableEditing($Resource::false);
  $self->{edtCPF}->SetMaxLength(14);
  $self->{edtISBN}->SetMaxLength(13);  
  $self->{edtPrecoTotal}->SetValue("R\$ 0,00");
  $self->{edtDtHrVenda}->SetValue($RotinasGlobais::Rotinas->retDataHoraStr(
    $Resource::true,$Resource::true));
  $self->{edtDtHrVenda}->SetFocus();

  $self->{lstLinhas} = ListaStr->new();

	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_6} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_22} = Wx::GridSizer->new(1, 2, 0, 0);
	$self->{sizer_23} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_8} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_7} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_24} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_4} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_8} = Wx::GridSizer->new(2, 1, 0, 0);
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
	$self->{sizer_2}->Add($self->{btnPesquisar}, 0, 
    wxLEFT|wxTOP|wxALIGN_BOTTOM, 10);
	$self->{sizer_1}->Add($self->{sizer_2}, 0, 0, 0);
	$self->{grid_sizer_2}->Add($self->{labCPF}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_2}->Add($self->{edtCPF}, 0, 0, 0);
	$self->{sizer_3}->Add($self->{grid_sizer_2}, 0, wxLEFT, 2);
	$self->{grid_sizer_3}->Add($self->{labCliente}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_3}->Add($self->{edtCliente}, 0, 0, 0);
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
	$self->{grid_sizer_8}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_8}->Add($self->{btnPLivro}, 0, 0, 0);
	$self->{sizer_4}->Add($self->{grid_sizer_8}, 0, 0, 0);
	$self->{sizer_1}->Add($self->{sizer_4}, 0, 0, 0);
	$self->{sizer_1}->Add($self->{gridVendas}, 1, wxALL|wxEXPAND, 2);
	$self->{sizer_24}->Add($self->{labRegistro}, 0, wxALL, 4);
	$self->{sizer_24}->Add(20, 20, 0, 0, 0);
	$self->{sizer_22}->Add($self->{sizer_24}, 0, 0, 0);
	$self->{sizer_7}->Add($self->{labPrecoTotal}, 0, wxALL, 2);
	$self->{sizer_7}->Add($self->{edtPrecoTotal}, 0, wxALL, 2);
	$self->{sizer_23}->Add($self->{sizer_7}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_8}->Add($self->{btnLimpar}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_8}->Add($self->{btnFechar}, 0, 
    wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
	$self->{sizer_23}->Add($self->{sizer_8}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_22}->Add($self->{sizer_23}, 1, 
    wxALIGN_RIGHT|wxALIGN_BOTTOM, 0);
	$self->{sizer_6}->Add($self->{sizer_22}, 0, wxEXPAND, 0);
	$self->{sizer_1}->Add($self->{sizer_6}, 0, wxEXPAND, 0);
	$self->SetAutoLayout(1);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);
}

sub ConsVenda {
  my( $self, $sOpcao ) = @_; 
  my( $sret, $sDataHora ) = '';
  my $ConsSQL = $ConsultasSQL::ConsSQL;

  if (length($self->{edtDtHrVenda}->GetValue()) > 0) {
    $sDataHora = $RotinasGlobais::Rotinas->ConverteDataHoraStr(
      $self->{edtDtHrVenda}->GetValue(), $Resource::true, 
      "%m/%d/%Y","%H:%M:%S");
  } else {
    $sDataHora = "";
  }
  my $sISBN = $self->{edtISBN}->GetValue();
  my $sCPF = $self->{edtCPF}->GetValue();

  if ($sOpcao=~'L') {
    $sret = $ConsSQL->Venda('S',"ZERO","","","","");
  } else {
    $sret = $ConsSQL->Venda($sOpcao, $sISBN, $sCPF, $sDataHora, "", "");
  }
  print($sret."\n");
  return $sret;
}

sub OnBtnPesquisarClick {
  my( $self, $event ) = @_;
  my $Rotinas = $RotinasGlobais::Rotinas;
  my $ConsTotal = ListaStr->new();

  if ($Rotinas->ConsultaDadosLista($Rotinas->atrib('gConexao'), 
    $self->{lstLinhas}, $self->ConsVenda('S')) ) {
    $Rotinas->AdicionaLinhasGrid($self->{gridVendas}, $self->{lstLinhas}, 6);

    if ($Rotinas->ConsultaDadosLista($Rotinas->atrib('gConexao'), $ConsTotal, 
       $self->ConsVenda('P')) ){
      if ($ConsTotal->tam > 0) {
        my @lista = $ConsTotal->col();
        my $nTemp = $lista[0][0];
        my $sPrecoTotal = sprintf('R$ %.2f', $nTemp);
        $self->{edtPrecoTotal}->SetValue($sPrecoTotal);
      }
    }
  } else {
    Wx::MessageBox($Resource::STR_VENNENC, "Erro", wxOK | wxICON_ERROR);
  }
  $event->Skip();
}

sub OnEdtDtHrVenda_Killfocus {
  my( $self, $event ) = @_;

  if (length($self->GetValue()) > 0) {
    if (! $RotinasGlobais::Rotinas->validaDataHora(
      $self->GetValue(), $Resource::false)) {
      Wx::MessageBox($Resource::STR_DTHRINV, "Erro", wxOK | wxICON_ERROR);
      $self->SetFocus();
    }
  }
  $event->Skip();
}

sub OnEdtCPF_Killfocus {
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
        $self->GetParent()->{edtCliente}->SetValue($sCliente);
      }
    } else {
      Wx::MessageBox($Resource::STR_CPFINV, "Erro", wxOK | wxICON_ERROR);
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent()->{edtCliente}->Clear();
  }
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

sub OnBtnPLivroClick {
  my( $self, $event ) = @_;

  my $fConLivros = frmConLivros->new($self);
  $fConLivros->ShowModal();
  $self->{edtISBN}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtISBN_Killfocus($self->{edtISBN}, $event);
  $event->Skip();
}

sub OnBtnPClienteClick {
  my( $self, $event ) = @_;

  my $fConClientes = frmConClientes->new($self);
  $fConClientes->ShowModal();
  $self->{edtCPF}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCPF_Killfocus($self->{edtCPF}, $event);
  $event->Skip();
}

sub setLabRegistros {
  my( $self, $nLinha ) = @_; 

  if ($nLinha >= 0) {
    $self->{labRegistro}->SetLabel("Registro " . ($nLinha+1) . " de " .
      $self->{gridVendas}->GetNumberRows());
  }
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

sub OnBtnLimparClick {
  my( $self, $event ) = @_;

  $self->{edtCPF}->Clear();
  $self->{edtCliente}->Clear();
  $self->{edtISBN}->Clear();
  $self->{edtLivro}->Clear();
  $self->{gridVendas}->ClearGrid();
  $self->{gridVendas}->DeleteRows(0, $self->{gridVendas}->GetNumberRows()-1, 
    $Resource::true);
  $self->{edtPrecoTotal}->SetValue("R\$ 0,00");
  $self->{edtDtHrVenda}->SetValue($RotinasGlobais::Rotinas->retDataHoraStr(
    $Resource::true, $Resource::true));
  $self->{edtDtHrVenda}->SetFocus();
  $event->Skip();
}

sub OnBtnFecharClick {
  my( $self, $event ) = @_;

  $self->GetParent()->Close();
  $event->Skip();
}

sub OnClose {
  my( $self, $event ) = @_;

  $self->Destroy();
}

1;

