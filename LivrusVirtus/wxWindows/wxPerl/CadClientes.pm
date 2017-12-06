use Wx 0.15 qw[:allclasses];
use strict;
use Cadastros qw[:allclasses];
package frmCadClientes;

use Wx qw[:everything];
use base qw(frmCadastros);
use strict;
use Wx::Event qw(EVT_BUTTON EVT_KILL_FOCUS);

require resource;
require TextValidatorCtrl;
require RotinasGlobais;
require ConsultasSQL;
require ListaStr;
require ConEnderecos;
require ConPaises;
require ConProfissoes;

my ( $ID_FRMCADCLIENTES_BTNPENDERECO, 
 $ID_FRMCADCLIENTES_BTNPPAIS, $ID_FRMCADCLIENTES_BTNPPROFISSAO, 
 $ID_FRMCADCLIENTES_BTNPROXIMO, $ID_FRMCADCLIENTES_EDTBAIRRO, 
 $ID_FRMCADCLIENTES_EDTCEP, $ID_FRMCADCLIENTES_EDTCODPAIS, 
 $ID_FRMCADCLIENTES_EDTCIDADE, $ID_FRMCADCLIENTES_EDTCODENDERECO,  
 $ID_FRMCADCLIENTES_EDTCODPROFISSAO, $ID_FRMCADCLIENTES_EDTDTNASC, 
 $ID_FRMCADCLIENTES_EDTEMAIL, $ID_FRMCADCLIENTES_EDTESTADO, 
 $ID_FRMCADCLIENTES_EDTIDENTIDADE, $ID_FRMCADCLIENTES_EDTLOGRADOURO, 
 $ID_FRMCADCLIENTES_EDTPAIS, $ID_FRMCADCLIENTES_EDTPROFISSAO, 
 $ID_FRMCADCLIENTES_EDTTELEFONE, $ID_FRMCADCLIENTES_LABBAIRRO, 
 $ID_FRMCADCLIENTES_LABCEP, $ID_FRMCADCLIENTES_LABCIDADE,  
 $ID_FRMCADCLIENTES_LABDTNASC, $ID_FRMCADCLIENTES_LABEMAIL, 
 $ID_FRMCADCLIENTES_LABESTADO, $ID_FRMCADCLIENTES_LABIDENTIDADE, 
 $ID_FRMCADCLIENTES_LABLOGRADOURO, $ID_FRMCADCLIENTES_LABPAIS, 
 $ID_FRMCADCLIENTES_LABPROFISSAO, $ID_FRMCADCLIENTES_LABTELEFONE, 
 $ID_FRMCADCLIENTES_RBSEXO, $ID_FRMCADCLIENTES_SBENDERECO) = (6000..6031);

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;

	$self = $self->SUPER::new( $parent, $TextValidatorCtrl::FILTER_NONE, 
    $Resource::false );
  $self->SetClientSize(523, 441);
  $self->{labCodigo}->SetLabel("CPF: ");
  $self->{labDescricao}->SetLabel("Nome: ");
  $self->{edtDescricao}->SetSize(312, 21);
  EVT_KILL_FOCUS($self->{edtCodigo}, \&OnEdtCodigo_Killfocus);

	$self->{labEmail} = Wx::StaticText->new($self, $ID_FRMCADCLIENTES_LABEMAIL, 
    "E-mail:", wxPOINT(8, 88), wxSIZE(34, 13) );
	$self->{edtEmail} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTEMAIL, 
    "", wxPOINT(8, 104), wxSIZE(312, 21) );
  $self->{edtEmail}->Enable($Resource::false);
	$self->{labIdentidade} = Wx::StaticText->new($self, 
    $ID_FRMCADCLIENTES_LABIDENTIDADE, "Identidade: ", 
    wxPOINT(322, 88), wxSIZE(56, 13) );
	$self->{edtIdentidade} = Wx::TextCtrl->new($self, 
    $ID_FRMCADCLIENTES_EDTIDENTIDADE, "", wxPOINT(322, 104), wxSIZE(100, 21) );
	$self->{edtIdentidade}->Enable($Resource::false);
	$self->{rbSexo} = Wx::RadioBox->new($self, $ID_FRMCADCLIENTES_RBSEXO, 
    "Sexo", wxPOINT(9, 128), wxSIZE(200, 44), ["Masculino", "Feminino"], 2, 
    wxRA_SPECIFY_COLS);
	$self->{rbSexo}->Enable($Resource::false);
	$self->{labTelefone} = Wx::StaticText->new($self, 
    $ID_FRMCADCLIENTES_LABTELEFONE, "Telefone: ", 
    wxPOINT(216, 128), wxSIZE(48, 13) );
	$self->{edtTelefone} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTTELEFONE,
    "", wxPOINT(216, 144), wxSIZE(104, 21) );
	$self->{edtTelefone}->Enable($Resource::false);
	$self->{labDtNasc} = Wx::StaticText->new($self, $ID_FRMCADCLIENTES_LABDTNASC, 
    "Dt. Nascimento", wxPOINT(322, 128), wxSIZE(73, 13) );
	$self->{edtDtNasc} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTDTNASC, 
    "", wxPOINT(322, 144), wxSIZE(100, 21) );
	$self->{edtDtNasc}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtDtNasc}, \&OnEdtDtNasc_Killfocus);
	$self->{edtCodEndereco} = TextValidatorCtrl->new($self, 
    $ID_FRMCADCLIENTES_EDTCODENDERECO, "", wxPOINT(16, 200), wxSIZE(88, 21),
    0, $TextValidatorCtrl::FILTER_NUMERIC);
	$self->{edtCodEndereco}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtCodEndereco}, \&OnEdtCodEndereco_Killfocus);
	$self->{btnPEndereco} = Wx::Button->new($self, 
    $ID_FRMCADCLIENTES_BTNPENDERECO, "...", wxPOINT(104, 200), wxSIZE(21, 21));
	$self->{btnPEndereco}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnPEndereco}->GetId(), \&OnBtnPEnderecoClick);
	$self->{labLogradouro} = Wx::StaticText->new($self, 
    $ID_FRMCADCLIENTES_LABLOGRADOURO, "Logradouro: ", 
    wxPOINT(16, 224), wxSIZE(60, 13) );
	$self->{edtLogradouro} = Wx::TextCtrl->new($self, 
    $ID_FRMCADCLIENTES_EDTLOGRADOURO, "", wxPOINT(16, 240), wxSIZE(264, 21) );
	$self->{edtLogradouro}->Enable($Resource::false);
	$self->{labBairro} = Wx::StaticText->new($self, $ID_FRMCADCLIENTES_LABBAIRRO,
    "Bairro:", wxPOINT(284, 224), wxSIZE(48, 13) );
	$self->{edtBairro} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTBAIRRO, 
    "", wxPOINT(280, 240), wxSIZE(144, 21) );
	$self->{edtBairro}->Enable($Resource::false);
	$self->{labCEP} = Wx::StaticText->new($self, $ID_FRMCADCLIENTES_LABCEP, 
    "CEP:", wxPOINT(16, 264), wxSIZE(40, 13) );
	$self->{edtCEP} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTCEP, 
    "", wxPOINT(16, 280), wxSIZE(78, 21) );
	$self->{edtCEP}->Enable($Resource::false);
	$self->{labCidade} = Wx::StaticText->new($self, $ID_FRMCADCLIENTES_LABCIDADE, 
    "Cidade: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtCidade} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTCIDADE, 
    "", wxPOINT(96,280), wxSIZE(184, 21) );
	$self->{edtCidade}->Enable($Resource::false);
	$self->{labEstado} = Wx::StaticText->new($self, $ID_FRMCADCLIENTES_LABESTADO, 
    "Estado: ", wxPOINT(284, 264), wxSIZE(56, 13) );
	$self->{edtEstado} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTESTADO, 
    "", wxPOINT(284, 280), wxSIZE(144, 21) );
	$self->{edtEstado}->Enable($Resource::false);
	$self->{labPais} = Wx::StaticText->new($self, $ID_FRMCADCLIENTES_LABPAIS, 
    "País de origem: ", wxPOINT(8, 320), wxSIZE(77, 16) );
	$self->{edtCodPais} = TextValidatorCtrl->new($self, $ID_FRMCADCLIENTES_EDTCODPAIS, 
    "", wxPOINT(8, 336), wxSIZE(78, 21), 0, $TextValidatorCtrl::FILTER_ALPHA);
	$self->{edtCodPais}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtCodPais}, \&OnEdtCodPais_Killfocus);
	$self->{edtPais} = Wx::TextCtrl->new($self, $ID_FRMCADCLIENTES_EDTPAIS, 
    "", wxPOINT(88, 336), wxSIZE(240, 21) );
	$self->{edtPais}->Enable($Resource::false);
	$self->{btnPPais} = Wx::Button->new($self, $ID_FRMCADCLIENTES_BTNPPAIS, 
    "...", wxPOINT(328, 336), wxSIZE(21, 21));
	$self->{btnPPais}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnPPais}->GetId(), \&OnBtnPPaisClick);
	$self->{labProfissao} = Wx::StaticText->new($self, 
    $ID_FRMCADCLIENTES_LABPROFISSAO, "Profissão: ", 
    wxPOINT(8, 360), wxSIZE(56, 13) );
	$self->{edtCodProfissao} = TextValidatorCtrl->new($self, 
    $ID_FRMCADCLIENTES_EDTCODPROFISSAO, "", wxPOINT(8, 376), 
      wxSIZE(78, 21), 0, $TextValidatorCtrl::FILTER_NUMERIC);
	$self->{edtCodProfissao}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtCodProfissao}, \&OnEdtCodProfissao_Killfocus);
	$self->{edtProfissao} = Wx::TextCtrl->new($self, 
    $ID_FRMCADCLIENTES_EDTPROFISSAO, "", wxPOINT(88, 376), wxSIZE(240, 21) );
	$self->{edtProfissao}->Enable($Resource::false);
  $self->{btnPProfissao} = Wx::Button->new($self, $ID_FRMCADCLIENTES_BTNPPROFISSAO, 
    "...", wxPOINT(328, 376), wxSIZE(21, 21));
  $self->{btnPProfissao}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnPProfissao}->GetId(), \&OnBtnPProfissaoClick);

  $self->IniciaBotoes();
  $self->{btnPesquisar}->SetSize(440, 8, 75, 25);
  $self->{btnAnterior}->SetSize(440, 40, 75, 25);
  $self->{btnProximo}->SetSize(440, 72, 75, 25);
  $self->{btnSalvar}->SetSize(200, 408, 75, 25);
  $self->{btnExcluir}->SetSize(280, 408, 75, 25);
  $self->{btnLimpar}->SetSize(360, 408, 75, 25);
  $self->{btnFechar}->SetSize(440, 408, 75, 25);

	$self->FazLayout();

	$self->{edtCodigo}->SetMaxLength(14);
  $self->{edtDescricao}->SetMaxLength(30);
  $self->{edtEmail}->SetMaxLength(30);
  $self->{edtIdentidade}->SetMaxLength(10);
  $self->{edtCodEndereco}->SetMaxLength(10);
  $self->{edtTelefone}->SetMaxLength(17);
  $self->{edtCodPais}->SetMaxLength(3);
  $self->{edtCodProfissao}->SetMaxLength(10);

  EVT_BUTTON($self, $self->{btnNovo}->GetId(), \&OnBtnNovoClick);
  EVT_BUTTON($self, $self->{btnFechar}->GetId(), \&OnBtnFecharClick);
  EVT_BUTTON($self, $self->{btnPesquisar}->GetId(), \&OnBtnPesquisarClick);
  EVT_BUTTON($self, $self->{btnAnterior}->GetId(), \&OnBtnAnteriorClick);
  EVT_BUTTON($self, $self->{btnProximo}->GetId(), \&OnBtnProximoClick);
  EVT_BUTTON($self, $self->{btnSalvar}->GetId(), \&OnBtnSalvarClick);
  EVT_BUTTON($self, $self->{btnExcluir}->GetId(), \&OnBtnExcluirClick);
  EVT_BUTTON($self, $self->{btnLimpar}->GetId(), \&OnBtnLimparClick);

	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_2} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_3} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_4} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_5} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_16} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_23} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_22} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_19} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_15} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_21} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_20} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_18} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_11}= Wx::StaticBoxSizer->new(
    Wx::StaticBox->new($self, -1,"Endereço"), wxVERTICAL);
	$self->{sizer_14} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_17} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_16} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_15} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_13} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_14} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_13} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_12} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_10} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_12} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_11} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_6} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_5} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_4} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_8} = Wx::BoxSizer->new(wxHORIZONTAL);
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
	$self->{sizer_5}->Add($self->{sizer_8}, 1, wxEXPAND, 0);
	$self->{grid_sizer_4}->Add($self->{labEmail}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_4}->Add($self->{edtEmail}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_4}, 0, 0, 0);
	$self->{grid_sizer_5}->Add($self->{labIdentidade}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_5}->Add($self->{edtIdentidade}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_5}, 0, wxLEFT, 4);
	$self->{sizer_5}->Add($self->{sizer_6}, 0, 0, 0);
	$self->{sizer_10}->Add($self->{rbSexo}, 0, 0, 0);
	$self->{grid_sizer_11}->Add($self->{labTelefone}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_11}->Add($self->{edtTelefone}, 0, 0, 0);
	$self->{sizer_10}->Add($self->{grid_sizer_11}, 1, wxLEFT|wxEXPAND, 4);
	$self->{grid_sizer_12}->Add($self->{labDtNasc}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_12}->Add($self->{edtDtNasc}, 0, 0, 0);
	$self->{sizer_10}->Add($self->{grid_sizer_12}, 1, wxLEFT|wxEXPAND, 4);
	$self->{sizer_5}->Add($self->{sizer_10}, 1, wxEXPAND, 0);
	$self->{sizer_12}->Add($self->{edtCodEndereco}, 0, 0, 0);
	$self->{sizer_12}->Add($self->{btnPEndereco}, 0, 0, 0);
	$self->{sizer_11}->Add($self->{sizer_12}, 0, wxALL, 2);
	$self->{grid_sizer_13}->Add($self->{labLogradouro}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_13}->Add($self->{edtLogradouro}, 0, 0, 0);
	$self->{sizer_13}->Add($self->{grid_sizer_13}, 0, 0, 0);
	$self->{grid_sizer_14}->Add($self->{labBairro}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_14}->Add($self->{edtBairro}, 0, 0, 0);
	$self->{sizer_13}->Add($self->{grid_sizer_14}, 0, wxLEFT, 4);
	$self->{sizer_11}->Add($self->{sizer_13}, 0, 0, 0);
	$self->{grid_sizer_15}->Add($self->{labCEP}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_15}->Add($self->{edtCEP}, 0, 0, 0);
	$self->{sizer_14}->Add($self->{grid_sizer_15}, 0, 0, 0);
	$self->{grid_sizer_16}->Add($self->{labCidade}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_16}->Add($self->{edtCidade}, 0, 0, 0);
	$self->{sizer_14}->Add($self->{grid_sizer_16}, 0, wxLEFT, 4);
	$self->{grid_sizer_17}->Add($self->{labEstado}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_17}->Add($self->{edtEstado}, 0, 0, 0);
	$self->{sizer_14}->Add($self->{grid_sizer_17}, 0, wxLEFT, 4);
	$self->{sizer_11}->Add($self->{sizer_14}, 1, 0, 0);
	$self->{sizer_5}->Add($self->{sizer_11}, 0, 0, 0);
	$self->{grid_sizer_18}->Add($self->{labPais}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_18}->Add($self->{edtCodPais}, 0, 0, 0);
	$self->{sizer_15}->Add($self->{grid_sizer_18}, 0, 0, 0);
	$self->{grid_sizer_20}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_20}->Add($self->{edtPais}, 0, 0, 0);
	$self->{sizer_15}->Add($self->{grid_sizer_20}, 0, wxLEFT, 2);
	$self->{grid_sizer_21}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_21}->Add($self->{btnPPais}, 0, 0, 0);
	$self->{sizer_15}->Add($self->{grid_sizer_21}, 0, 0, 0);
	$self->{sizer_5}->Add($self->{sizer_15}, 0, 0, 0);
	$self->{grid_sizer_19}->Add($self->{labProfissao}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_19}->Add($self->{edtCodProfissao}, 0, 0, 0);
	$self->{sizer_16}->Add($self->{grid_sizer_19}, 0, 0, 0);
	$self->{grid_sizer_22}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_22}->Add($self->{edtProfissao}, 0, 0, 0);
	$self->{sizer_16}->Add($self->{grid_sizer_22}, 0, wxLEFT, 2);
	$self->{grid_sizer_23}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_23}->Add($self->{btnPProfissao}, 0, 0, 0);
	$self->{sizer_16}->Add($self->{grid_sizer_23}, 0, 0, 0);
	$self->{sizer_5}->Add($self->{sizer_16}, 0, 0, 0);
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
    $self->{edtCodigo}->GetValue(), $Resource::STR_CPFNINF)) {
    return $Resource::false;
  }
  if ($bTodosDados) {
	  if ($Rotinas->ValidaCampo(
      $self->{edtDescricao}->GetValue(), $Resource::STR_CLININF)) {
  		return $Resource::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtEmail}->GetValue(), $Resource::STR_EMAILNINF)) {
  		return $Resource::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtTelefone}->GetValue(), $Resource::STR_TELNINF)) {
  		return $Resource::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtCodEndereco}->GetValue(), $Resource::STR_ENDNINF)) {
  		return $Resource::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtCodPais}->GetValue(), $Resource::STR_PAISNINF)) {
  		return $Resource::false;
    }
	  if ($Rotinas->ValidaCampo(
      $self->{edtCodProfissao}->GetValue(), $Resource::STR_PROFNINF)) {
  		return $Resource::false;
    }
  }
  return $Resource::true;
}

sub OnBtnNovoClick {
  my( $self, $event ) = @_;

  $self->btnNovoClick();
  $self->InformaLimpaDadosLocal($Resource::false);
  $self->HabilitaDadosLocal($Resource::true);
  $event->Skip();
}

sub OnBtnPesquisarClick {
  my( $self, $event ) = @_;

  if ($self->PesquisarDados($ConsultasSQL::ConsSQL->Cliente('S', 
    $self->{edtCodigo}->GetValue(),"","","","","","","","",""), 
    $Resource::STR_CLINENC)) {
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
  my( $sSexo, $sDtNasc, $sSqlUpdate, $sSqlInsert );
  my $ConsSQL = $ConsultasSQL::ConsSQL;

  if ($self->{rbSexo}->GetSelection() == 0) {
     $sSexo = "M";
  } else {
     $sSexo = "F";
  }
  $sDtNasc = $RotinasGlobais::Rotinas->ConverteDataHoraStr(
    $self->{edtDtNasc}->GetValue(), $Resource::true, '%Y/%m/%d', '');

  $sSqlUpdate = $ConsSQL->Cliente('U', 
    $self->{edtCodigo}->GetValue(), $self->{edtDescricao}->GetValue(), 
    $self->{edtEmail}->GetValue(),  $self->{edtIdentidade}->GetValue(), $sSexo,  
    $self->{edtTelefone}->GetValue(), $sDtNasc, 
    $self->{edtCodEndereco}->GetValue(), 
    $self->{edtCodPais}->GetValue(), $self->{edtCodProfissao}->GetValue());

  $sSqlInsert = $ConsSQL->Cliente('I', 
    $self->{edtCodigo}->GetValue(), $self->{edtDescricao}->GetValue(), 
    $self->{edtEmail}->GetValue(),  $self->{edtIdentidade}->GetValue(), $sSexo,  
    $self->{edtTelefone}->GetValue(), $sDtNasc, 
    $self->{edtCodEndereco}->GetValue(), 
    $self->{edtCodPais}->GetValue(), $self->{edtCodProfissao}->GetValue());

  if ($self->SalvarDados($self->ValidaDados($Resource::true),
    $ConsSQL->Cliente('S', $self->{edtCodigo}->GetValue(),
    "","","","","","","","",""), $sSqlUpdate, $sSqlInsert, $Resource::true)) {
    $self->InformaLimpaDadosLocal($Resource::false);
    $self->HabilitaDadosLocal($Resource::false);
  }
  $event->Skip();
}

sub OnBtnExcluirClick {
  my( $self, $event ) = @_;

  if ($self->ExcluirDados($self->ValidaDados($Resource::false),
    $ConsultasSQL::ConsSQL->Cliente('D', $self->{edtCodigo}->GetValue(),
    "","","","","","","","",""))) {
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
    $self->{edtEmail}->SetValue($lista[$self->{nLinhaRegistro}][2]);
    $self->{edtIdentidade}->SetValue($lista[$self->{nLinhaRegistro}][3]);
    if ($lista[$self->{nLinhaRegistro}][4] =~ 'M') {
      $self->{rbSexo}->SetSelection(0);
    } else {
      $self->{rbSexo}->SetSelection(1);
    }
    $self->{edtTelefone}->SetValue($lista[$self->{nLinhaRegistro}][5]);
    $self->{edtDtNasc}->SetValue(substr(
      $lista[$self->{nLinhaRegistro}][6],0,10));
    $self->{edtCodEndereco}->SetValue($lista[$self->{nLinhaRegistro}][7]);
    $self->{edtLogradouro}->SetValue($lista[$self->{nLinhaRegistro}][8]);
    $self->{edtBairro}->SetValue($lista[$self->{nLinhaRegistro}][9]);
    $self->{edtCEP}->SetValue($lista[$self->{nLinhaRegistro}][10]);
    $self->{edtCidade}->SetValue($lista[$self->{nLinhaRegistro}][11]);
    $self->{edtEstado}->SetValue($lista[$self->{nLinhaRegistro}][12]);
    $self->{edtCodPais}->SetValue($lista[$self->{nLinhaRegistro}][13]);
    $self->{edtPais}->SetValue($lista[$self->{nLinhaRegistro}][14]);
    $self->{edtCodProfissao}->SetValue($lista[$self->{nLinhaRegistro}][15]);
    $self->{edtProfissao}->SetValue($lista[$self->{nLinhaRegistro}][16]);
  } else {
    $self->{edtEmail}->Clear();
    $self->{edtIdentidade}->Clear();
    $self->{rbSexo}->SetSelection(0);
    $self->{edtTelefone}->Clear();
    $self->{edtDtNasc}->Clear();
    $self->{edtCodEndereco}->Clear();
    $self->{edtLogradouro}->Clear();
    $self->{edtBairro}->Clear();
    $self->{edtCEP}->Clear();
    $self->{edtCidade}->Clear();
    $self->{edtEstado}->Clear();
    $self->{edtCodPais}->Clear();
    $self->{edtPais}->Clear();
    $self->{edtCodProfissao}->Clear();
    $self->{edtProfissao}->Clear();
    $self->{edtCodigo}->SetFocus();
  }
}

sub HabilitaDadosLocal {
  my( $self, $bHabilita ) = @_;

  $self->{edtEmail}->Enable($bHabilita);
  $self->{edtIdentidade}->Enable($bHabilita);
  $self->{rbSexo}->Enable($bHabilita);
  $self->{edtTelefone}->Enable($bHabilita);
  $self->{edtDtNasc}->Enable($bHabilita);
  $self->{edtCodEndereco}->Enable($bHabilita);
  $self->{btnPEndereco}->Enable($bHabilita);
  $self->{edtCodPais}->Enable($bHabilita);
  $self->{btnPPais}->Enable($bHabilita);
  $self->{edtCodProfissao}->Enable($bHabilita);
  $self->{btnPProfissao}->Enable($bHabilita);
}

sub OnEdtCodigo_Killfocus {
  my( $self, $event ) = @_;

  if (length($self->GetValue()) > 0) {
  	if ($RotinasGlobais::Rotinas->validaCPF($self->GetValue()) == 
      $Resource::false) {
      Wx::MessageBox($Resource::STR_CPFINV, "Erro", wxOK | wxICON_ERROR);
      $self->Clear();
      $self->SetFocus();
    }
  }  
  $event->Skip();
}

sub OnEdtDtNasc_Killfocus {
  my( $self, $event ) = @_;
  my $Rotinas = $RotinasGlobais::Rotinas;
  if (length($self->GetValue()) > 0) {
    if (!$Rotinas->validaDataHora(
        $self->GetValue(), $Resource::true)) {
      Wx::MessageBox($Resource::STR_DTHRINV, "Erro", wxOK | wxICON_ERROR);
      $self->SetValue(
        $Rotinas->retDataHoraStr($Resource::true,$Resource::false));
      $self->SetFocus();
    }
  } else {
    $self->SetValue(
      $Rotinas->retDataHoraStr($Resource::true,$Resource::false));
  }
  $event->Skip();
}

sub OnEdtCodEndereco_Killfocus {
  my( $self, $event ) = @_;
  my $ConsCampo = ListaStr->new();
  my $Rotinas = $RotinasGlobais::Rotinas;

  if (length($self->GetValue()) > 0) {
    my $sLogradouro = $Rotinas->ConsultaCampoDesc($ConsCampo, 
    $ConsultasSQL::ConsSQL->Endereco('S', $self->GetValue(),
    "","","","",""),$Resource::STR_ENDNENC);
    if (length($sLogradouro) > 0) {
      my @lista = $ConsCampo->col();
      $self->GetParent()->{edtLogradouro}->SetValue($sLogradouro);
      $self->GetParent()->{edtBairro}->SetValue($lista[0][2]);
      $self->GetParent()->{edtCEP}->SetValue($lista[0][3]);
      $self->GetParent()->{edtCidade}->SetValue($lista[0][4]);
      $self->GetParent()->{edtEstado}->SetValue($lista[0][5]);
    } else {
  	  $self->SetFocus();
      $self->GetParent()->{edtLogradouro}->Clear();
      $self->GetParent()->{edtBairro}->Clear();
      $self->GetParent()->{edtCEP}->Clear();
  	  $self->GetParent()->{edtCidade}->Clear();
  	  $self->GetParent()->{edtEstado}->Clear();
    }
  } else {
    $self->GetParent()->{edtLogradouro}->Clear();
    $self->GetParent()->{edtBairro}->Clear();
    $self->GetParent()->{edtCEP}->Clear();
	  $self->GetParent()->{edtCidade}->Clear();
	  $self->GetParent()->{edtEstado}->Clear();
  }
  $event->Skip();
}

sub OnBtnPEnderecoClick {
  my( $self, $event ) = @_;

  my $fConEnderecos = frmConEnderecos->new($self);
  $fConEnderecos->ShowModal();
  $self->{edtCodEndereco}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCodEndereco_Killfocus($self->{edtCodEndereco}, $event);
  $event->Skip();
}

sub OnEdtCodPais_Killfocus {
  my( $self, $event ) = @_;  
  my $ConsCampo = ListaStr->new();

  if (length($self->GetValue()) > 0) {
    my $sPais = $RotinasGlobais::Rotinas->ConsultaCampoDesc($ConsCampo, 
      $ConsultasSQL::ConsSQL->Pais('S',
      $self->GetValue(),""),$Resource::STR_PAISNENC);
    if (length($sPais) > 0) {
      $self->GetParent()->{edtPais}->SetValue($sPais);
    } else {
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent->{edtPais}->Clear();
  }
  $event->Skip();
}

sub OnBtnPPaisClick {
  my( $self, $event ) = @_;

  my $fConPaises = frmConPaises->new($self);
  $fConPaises->ShowModal();
  $self->{edtCodPais}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCodPais_Killfocus($self->{edtCodPais}, $event);
  $event->Skip();
}

sub OnEdtCodProfissao_Killfocus {
  my( $self, $event ) = @_;
  my $ConsCampo = ListaStr->new();

  if (length($self->GetValue()) > 0) {
    my $sProfissao = $RotinasGlobais::Rotinas->ConsultaCampoDesc(
      $ConsCampo, $ConsultasSQL::ConsSQL->Profissao('S',
      $self->GetValue(),""),$Resource::STR_PROFNENC);
    if (length($sProfissao) > 0) {
      $self->GetParent()->{edtProfissao}->SetValue($sProfissao);
    } else {
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent()->{edtProfissao}->Clear();
  }
  $event->Skip();
}

sub OnBtnPProfissaoClick {
  my( $self, $event ) = @_;

  my $fConProfissoes = frmConProfissoes->new($self);
  $fConProfissoes->ShowModal();
  $self->{edtCodProfissao}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCodProfissao_Killfocus($self->{edtCodProfissao}, $event);
  $event->Skip();
}

1;

