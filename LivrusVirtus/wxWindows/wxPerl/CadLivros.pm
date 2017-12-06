use Wx 0.15 qw[:allclasses];
use strict;
use Cadastros qw[:allclasses];
package frmCadLivros;

use Wx qw[:everything];
use base qw(frmCadastros);
use strict;
use Wx::Event qw(EVT_BUTTON EVT_KILL_FOCUS EVT_LISTBOX_DCLICK);

require resource;
require TextValidatorCtrl;
require RotinasGlobais;
require ConsultasSQL;
require ListaStr;
require ConAssuntos;
require ConAutores;
require ConEditoras;

my ($ID_FRMCADLIVROS_BTNADASSUNTOS, 
 $ID_FRMCADLIVROS_BTNADAUTORES, $ID_FRMCADLIVROS_BTNPASSUNTO, 
 $ID_FRMCADLIVROS_BTNPAUTOR, $ID_FRMCADLIVROS_BTNPEDITORA, 
 $ID_FRMCADLIVROS_CMBIDIOMA, $ID_FRMCADLIVROS_EDTANOPUBLI, 
 $ID_FRMCADLIVROS_EDTASSUNTO, $ID_FRMCADLIVROS_EDTAUTOR, 
 $ID_FRMCADLIVROS_EDTCODASSUNTO, $ID_FRMCADLIVROS_EDTCODAUTOR, 
 $ID_FRMCADLIVROS_EDTCODEDITORA, $ID_FRMCADLIVROS_EDTEDICAO, 
 $ID_FRMCADLIVROS_EDTEDITORA, $ID_FRMCADLIVROS_EDTNPAGINAS, 
 $ID_FRMCADLIVROS_EDTPRECO, $ID_FRMCADLIVROS_EDTQTDESTOQUE, 
 $ID_FRMCADLIVROS_EDTVOLUME, $ID_FRMCADLIVROS_LABANOPUBLI, 
 $ID_FRMCADLIVROS_LABASSUNTO, $ID_FRMCADLIVROS_LABAUTOR, 
 $ID_FRMCADLIVROS_LABEDICAO, $ID_FRMCADLIVROS_LABEDITORA, 
 $ID_FRMCADLIVROS_LABIDIOMA, $ID_FRMCADLIVROS_LABNPAGINAS, 
 $ID_FRMCADLIVROS_LABPRECO, $ID_FRMCADLIVROS_LABQTDESTOQUE, 
 $ID_FRMCADLIVROS_LABVOLUME, $ID_FRMCADLIVROS_LSTASSUNTOS, 
 $ID_FRMCADLIVROS_LSTAUTORES) = (7000..7029);

sub new {
	my( $self, $parent ) = @_;
	$parent = undef              unless defined $parent;

	$self = $self->SUPER::new( $parent, $TextValidatorCtrl::FILTER_NONE, 
    $Resource::false );
  $self->SetClientSize(523, 441);
  $self->{labCodigo}->SetLabel("ISBN: ");
  $self->{labDescricao}->SetLabel("Título: ");
  $self->{edtDescricao}->SetSize(312, 21);
  EVT_KILL_FOCUS($self->{edtCodigo}, \&OnEdtCodigo_Killfocus);

	$self->{labEdicao} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABEDICAO, 
    "Edição:", wxPOINT(326, 48), wxSIZE(39, 13) );
	$self->{edtEdicao} = Wx::SpinCtrl->new($self, $ID_FRMCADLIVROS_EDTEDICAO,
    "1", wxPOINT(324, 64), wxSIZE(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{edtEdicao}->Enable($Resource::false);
	$self->{labAnoPubli} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABANOPUBLI, 
    "Ano Publicação:", wxPOINT(8, 88), wxSIZE(81, 13) );
	$self->{edtAnoPubli} = Wx::SpinCtrl->new($self, $ID_FRMCADLIVROS_EDTANOPUBLI, 
    "1", wxPOINT(8, 104), wxSIZE(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{edtAnoPubli}->Enable($Resource::false);
	$self->{labEditora} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABEDITORA, 
    "Editora:", wxPOINT(104, 88), wxSIZE(39, 13) );
	$self->{edtCodEditora} = Wx::TextCtrl->new($self, $ID_FRMCADLIVROS_EDTCODEDITORA, 
    "", wxPOINT(104, 104), wxSIZE(78, 21) );
	$self->{edtCodEditora}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtCodEditora}, \&OnEdtCodEditora_Killfocus);
	$self->{edtEditora} = Wx::TextCtrl->new($self, $ID_FRMCADLIVROS_EDTEDITORA, 
    "", wxPOINT(184, 104), wxSIZE(216, 21) );
	$self->{edtEditora}->Enable($Resource::false);
	$self->{btnPEditora} = Wx::Button->new($self, $ID_FRMCADLIVROS_BTNPEDITORA, 
    "...", wxPOINT(400, 400), wxSIZE(21, 21));
	$self->{btnPEditora}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnPEditora}->GetId(), \&OnBtnPEditoraClick);
	$self->{labVolume} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABVOLUME, 
    "Volume:", wxPOINT(8, 128), wxSIZE(41, 13) );
	$self->{edtVolume} = Wx::SpinCtrl->new($self, $ID_FRMCADLIVROS_EDTVOLUME, 
    "1", wxPOINT(8, 144), wxSIZE(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{edtVolume}->Enable($Resource::false);
	$self->{labIdioma} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABIDIOMA, 
    "Idioma: ", wxPOINT(104, 128), wxSIZE(56, 13) );
	$self->{cmbIdioma} = Wx::Choice->new($self, $ID_FRMCADLIVROS_CMBIDIOMA, 
    wxPOINT(104, 144), wxSIZE(320, 21) );
	$self->{cmbIdioma}->Enable($Resource::false);
	$self->{labNPaginas} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABNPAGINAS, 
    "Nº Páginas: ", wxPOINT(8, 168), wxSIZE(59, 13) );
	$self->{edtNPaginas} = Wx::SpinCtrl->new($self, $ID_FRMCADLIVROS_EDTNPAGINAS, 
    "1", wxPOINT(8, 184), wxSIZE(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{edtNPaginas}->Enable($Resource::false);
	$self->{labAssunto} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABASSUNTO, 
    "Assunto: ", wxPOINT(104, 168), wxSIZE(44, 13) );
	$self->{edtCodAssunto} = Wx::TextCtrl->new($self, $ID_FRMCADLIVROS_EDTCODASSUNTO, 
    "", wxPOINT(104, 184), wxSIZE(78, 21) );
	$self->{edtCodAssunto}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtCodAssunto}, \&OnEdtCodAssunto_Killfocus);
	$self->{edtAssunto} = Wx::TextCtrl->new($self, $ID_FRMCADLIVROS_EDTASSUNTO, 
    "", wxPOINT(184, 184), wxSIZE(192, 21) );
	$self->{edtAssunto}->Enable($Resource::false);
	$self->{btnAdAssuntos} = Wx::Button->new($self, $ID_FRMCADLIVROS_BTNADASSUNTOS, 
    "+", wxPOINT(376, 184), wxSIZE(21, 21));
	$self->{btnAdAssuntos}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnAdAssuntos}->GetId(), \&OnBtnAdAssuntosClick);
	$self->{btnPAssunto} = Wx::Button->new($self, $ID_FRMCADLIVROS_BTNPASSUNTO, 
    "...", wxPOINT(400, 184), wxSIZE(21, 21) );
	$self->{btnPAssunto}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnPAssunto}->GetId(), \&OnBtnPAssuntoClick);
	$self->{labPreco} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABPRECO, 
    "Preço: ", wxPOINT(8, 216), wxSIZE(40, 13));
	$self->{edtPreco} = Wx::TextCtrl->new($self, $ID_FRMCADLIVROS_EDTPRECO, 
    "", wxPOINT(7, 232), wxSIZE(88, 21));
	$self->{edtPreco}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtPreco}, \&OnEdtPreco_Killfocus);
	$self->{lstAssuntos} = Wx::ListBox->new($self, $ID_FRMCADLIVROS_LSTASSUNTOS, 
    wxPOINT(104, 208), wxSIZE(320, 48));
	$self->{lstAssuntos}->Enable($Resource::false);
  EVT_LISTBOX_DCLICK($self, $ID_FRMCADLIVROS_LSTASSUNTOS,
        \&OnLstAssuntos_Dblclk);
	$self->{labQtdEstoque} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABQTDESTOQUE, 
    "Qtd. Estoque: ", wxPOINT(6, 256), wxSIZE(68, 13) );
	$self->{edtQtdEstoque} = Wx::SpinCtrl->new($self, $ID_FRMCADLIVROS_EDTQTDESTOQUE, 
    "0", wxPOINT(8, 272), wxSIZE(92, 21), wxSP_ARROW_KEYS, 0, 9999, 0);
	$self->{edtQtdEstoque}->Enable($Resource::false);
	$self->{labAutor} = Wx::StaticText->new($self, $ID_FRMCADLIVROS_LABAUTOR,
    "Autor: ", wxPOINT(104, 256), wxSIZE(31, 13) );
	$self->{edtCodAutor} = Wx::TextCtrl->new($self, $ID_FRMCADLIVROS_EDTCODAUTOR, 
    "", wxPOINT(104, 272), wxSIZE(78, 21) );
	$self->{edtCodAutor}->Enable($Resource::false);
  EVT_KILL_FOCUS($self->{edtCodAutor}, \&OnEdtCodAutor_Killfocus);
	$self->{edtAutor} = Wx::TextCtrl->new($self, $ID_FRMCADLIVROS_EDTAUTOR, 
    "",  wxPOINT(184, 272), wxSIZE(192, 21) );
	$self->{edtAutor}->Enable($Resource::false);
	$self->{btnAdAutores} = Wx::Button->new($self, $ID_FRMCADLIVROS_BTNADAUTORES, 
    "+", wxPOINT(376, 272), wxSIZE(21, 21));
	$self->{btnAdAutores}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnAdAutores}->GetId(), \&OnBtnAdAutoresClick);
	$self->{btnPAutor} = Wx::Button->new($self, $ID_FRMCADLIVROS_BTNPAUTOR, 
    "...", wxPOINT(400, 272), wxSIZE(21, 21));
	$self->{btnPAutor}->Enable($Resource::false);
  EVT_BUTTON($self, $self->{btnPAutor}->GetId(), \&OnBtnPAutorClick);
	$self->{lstAutores} = Wx::ListBox->new($self, $ID_FRMCADLIVROS_LSTAUTORES, 
    wxPOINT(104, 296), wxSIZE(320, 48) );
	$self->{lstAutores}->Enable($Resource::false);
  EVT_LISTBOX_DCLICK($self, $ID_FRMCADLIVROS_LSTAUTORES,
        \&OnLstAutores_Dblclk);

  $self->IniciaBotoes();
  $self->{btnPesquisar}->SetSize(427, 8, 75, 25);
  $self->{btnAnterior}->SetSize(427, 40, 75, 25);
  $self->{btnProximo}->SetSize(427, 72, 75, 25);
  $self->{btnSalvar}->SetSize(187, 352, 75, 25);
  $self->{btnExcluir}->SetSize(267, 352, 75, 25);
  $self->{btnLimpar}->SetSize(347, 352, 75, 25);
  $self->{btnFechar}->SetSize(427, 352, 75, 25);

	$self->FazLayout();

  $self->{edtCodigo}->SetMaxLength(13);
  $self->{edtDescricao}->SetMaxLength(50);
  $self->{edtCodEditora}->SetMaxLength(5);
  $self->{edtPreco}->SetMaxLength(7);

  $self->{slAssuntos} = ListaStr->new();
  $self->{slAutores} = ListaStr->new();
  $self->{slIdiomas} = ListaStr->new();
  $self->AdicionaCombo();

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
	$self->{sizer_21} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{sizer_20} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_37} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_36} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_35} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_34} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_33} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_19} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_32} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_18} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_31} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_30} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_29} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_28} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_27} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_17} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_26} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{grid_sizer_25} = Wx::GridSizer->new(2, 1, 0, 0);
	$self->{sizer_6} = Wx::BoxSizer->new(wxHORIZONTAL);
	$self->{grid_sizer_24} = Wx::GridSizer->new(2, 1, 0, 0);
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
	$self->{grid_sizer_9}->Add($self->{labEdicao}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_9}->Add($self->{edtEdicao}, 0, 0, 0);
	$self->{sizer_8}->Add($self->{grid_sizer_9}, 0, wxLEFT, 2);
	$self->{sizer_5}->Add($self->{sizer_8}, 1, wxEXPAND, 0);
	$self->{grid_sizer_4}->Add($self->{labAnoPubli}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_4}->Add($self->{edtAnoPubli}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_4}, 0, 0, 0);
	$self->{grid_sizer_5}->Add($self->{labEditora}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_5}->Add($self->{edtCodEditora}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_5}, 0, wxLEFT, 4);
	$self->{grid_sizer_6}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_6}->Add($self->{edtEditora}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_6}, 0, wxLEFT, 2);
	$self->{grid_sizer_24}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_24}->Add($self->{btnPEditora}, 0, 0, 0);
	$self->{sizer_6}->Add($self->{grid_sizer_24}, 0, 0, 0);
	$self->{sizer_5}->Add($self->{sizer_6}, 0, 0, 0);
	$self->{grid_sizer_25}->Add($self->{labVolume}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_25}->Add($self->{edtVolume}, 0, 0, 0);
	$self->{sizer_17}->Add($self->{grid_sizer_25}, 0, wxEXPAND, 0);
	$self->{grid_sizer_26}->Add($self->{labIdioma}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_26}->Add($self->{cmbIdioma}, 0, 0, 0);
	$self->{sizer_17}->Add($self->{grid_sizer_26}, 0, wxLEFT|wxEXPAND, 4);
	$self->{sizer_5}->Add($self->{sizer_17}, 1, 0, 0);
	$self->{grid_sizer_27}->Add($self->{labNPaginas}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_27}->Add($self->{edtNPaginas}, 0, 0, 0);
	$self->{sizer_18}->Add($self->{grid_sizer_27}, 0, 0, 0);
	$self->{grid_sizer_28}->Add($self->{labAssunto}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_28}->Add($self->{edtCodAssunto}, 0, 0, 0);
	$self->{sizer_18}->Add($self->{grid_sizer_28}, 0, wxLEFT, 4);
	$self->{grid_sizer_29}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_29}->Add($self->{edtAssunto}, 0, 0, 0);
	$self->{sizer_18}->Add($self->{grid_sizer_29}, 0, wxLEFT, 2);
	$self->{grid_sizer_30}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_30}->Add($self->{btnAdAssuntos}, 0, 0, 0);
	$self->{sizer_18}->Add($self->{grid_sizer_30}, 0, 0, 0);
	$self->{grid_sizer_31}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_31}->Add($self->{btnPAssunto}, 0, 0, 0);
	$self->{sizer_18}->Add($self->{grid_sizer_31}, 0, 0, 0);
	$self->{sizer_5}->Add($self->{sizer_18}, 1, 0, 0);
	$self->{grid_sizer_32}->Add($self->{labPreco}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_32}->Add($self->{edtPreco}, 0, 0, 0);
	$self->{sizer_19}->Add($self->{grid_sizer_32}, 0, 0, 0);
	$self->{sizer_19}->Add($self->{lstAssuntos}, 0, wxLEFT, 4);
	$self->{sizer_5}->Add($self->{sizer_19}, 1, 0, 0);
	$self->{grid_sizer_33}->Add($self->{labQtdEstoque}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_33}->Add($self->{edtQtdEstoque}, 0, 0, 0);
	$self->{sizer_20}->Add($self->{grid_sizer_33}, 0, 0, 0);
	$self->{grid_sizer_34}->Add($self->{labAutor}, 0, wxALIGN_BOTTOM, 0);
	$self->{grid_sizer_34}->Add($self->{edtCodAutor}, 0, 0, 0);
	$self->{sizer_20}->Add($self->{grid_sizer_34}, 0, 0, 0);
	$self->{grid_sizer_35}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_35}->Add($self->{edtAutor}, 0, 0, 0);
	$self->{sizer_20}->Add($self->{grid_sizer_35}, 0, wxLEFT, 2);
	$self->{grid_sizer_36}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_36}->Add($self->{btnAdAutores}, 0, 0, 0);
	$self->{sizer_20}->Add($self->{grid_sizer_36}, 0, 0, 0);
	$self->{grid_sizer_37}->Add(20, 20, 0, 0, 0);
	$self->{grid_sizer_37}->Add($self->{btnPAutor}, 0, 0, 0);
	$self->{sizer_20}->Add($self->{grid_sizer_37}, 0, 0, 0);
	$self->{sizer_5}->Add($self->{sizer_20}, 1, 0, 0);
	$self->{sizer_21}->Add(92, 20, 0, 0, 0);
	$self->{sizer_21}->Add($self->{lstAutores}, 0, 0, 0);
	$self->{sizer_5}->Add($self->{sizer_21}, 0, 0, 0);
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
}

sub ValidaDados {
  my( $self, $bTodosDados ) = @_;

  if ($RotinasGlobais::Rotinas->ValidaCampo(
    $self->{edtCodigo}->GetValue(), $Resource::STR_ISBNNINF)) {
    return $Resource::false;
  }
  if ($bTodosDados) {
    if ($RotinasGlobais::Rotinas->ValidaCampo(
      $self->{edtDescricao}->GetValue(), $Resource::STR_TITNINF)) {
      return $Resource::false;
    }
    if ($RotinasGlobais::Rotinas->ValidaCampo(
      $self->{edtEditora}->GetValue(), $Resource::STR_EDTNINF)) {
      return $Resource::false;
    }
    if ($self->{lstAssuntos}->GetCount()==0) {
      Wx::MessageBox($Resource::STR_ASSNINF, "Erro", wxOK | wxICON_ERROR);
      return $Resource::false;
    }
    if ($self->{lstAutores}->GetCount()==0) {
      Wx::MessageBox($Resource::STR_AUTNINF, "Erro", wxOK | wxICON_ERROR);
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

  if ($self->PesquisarDados($ConsultasSQL::ConsSQL->Livro('S', 
    $self->{edtCodigo}->GetValue(),"","","","","","","","",""),
    $Resource::STR_LIVNENC)) {
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

  my $nPos = $self->{cmbIdioma}->GetSelection();
  my @lista = $self->{slIdiomas}->col();
  my $sCodIdioma = $lista[$nPos];
  print($nPos."\n");
  print($lista[$nPos]."\n");

  my $sSqlUpdate = $ConsultasSQL::ConsSQL->Livro('U',
    $self->{edtCodigo}->GetValue(), $self->{edtDescricao}->GetValue(), 
    $self->{edtEdicao}->GetValue(), $self->{edtAnoPubli}->GetValue(), 
    $self->{edtVolume}->GetValue(), $self->{edtCodEditora}->GetValue(), 
    $sCodIdioma, $self->{edtNPaginas}->GetValue(),
    $RotinasGlobais::Rotinas->VirgulaParaPonto($self->{edtPreco}->GetValue(),
    $Resource::false), $self->{edtQtdEstoque}->GetValue());

  my $sSqlInsert = $ConsultasSQL::ConsSQL->Livro('I',
    $self->{edtCodigo}->GetValue(), $self->{edtDescricao}->GetValue(), 
    $self->{edtEdicao}->GetValue(), $self->{edtAnoPubli}->GetValue(), 
    $self->{edtVolume}->GetValue(), $self->{edtCodEditora}->GetValue(), 
    $sCodIdioma, $self->{edtNPaginas}->GetValue(),
    $RotinasGlobais::Rotinas->VirgulaParaPonto($self->{edtPreco}->GetValue(),
    $Resource::false), $self->{edtQtdEstoque}->GetValue());

  if ($self->SalvarDados($self->ValidaDados($Resource::true),
    $ConsultasSQL::ConsSQL->Livro('S', $self->{edtCodigo}->GetValue(),
    "","","","","","","","",""), $sSqlUpdate, $sSqlInsert, $Resource::false)) {
    $self->SalvaLista('A');
    $self->SalvaLista('B');
    $self->btnLimparClick();
    $self->InformaLimpaDadosLocal($Resource::false);
    $self->HabilitaDadosLocal($Resource::false);
  }
  $event->Skip();
}

sub OnBtnExcluirClick {
  my( $self, $event ) = @_;

  if ($self->ExcluirDados($self->ValidaDados($Resource::false),
    $ConsultasSQL::ConsSQL->Livro('D', $self->{edtCodigo}->GetValue(),
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
  my $Rotinas = $RotinasGlobais::Rotinas;

  if ($bInformar) {
    my @lista = $self->{lstRegistros}->col();
    $self->{edtEdicao}->SetValue($lista[$self->{nLinhaRegistro}][2]);
    $self->{edtAnoPubli}->SetValue($lista[$self->{nLinhaRegistro}][3]);
    $self->{edtVolume}->SetValue($lista[$self->{nLinhaRegistro}][4]);
    $self->{edtCodEditora}->SetValue($lista[$self->{nLinhaRegistro}][5]);
    $self->{edtEditora}->SetValue($lista[$self->{nLinhaRegistro}][6]);
    $self->{cmbIdioma}->SetStringSelection($lista[$self->{nLinhaRegistro}][8]);
    $self->{edtNPaginas}->SetValue($lista[$self->{nLinhaRegistro}][9]);
    $self->{edtPreco}->SetValue($Rotinas->VirgulaParaPonto(
      $lista[$self->{nLinhaRegistro}][10], $Resource::true));
    $self->{edtQtdEstoque}->SetValue($lista[$self->{nLinhaRegistro}][11]);
    $Rotinas->AdicionaValoresLista($ConsultasSQL::ConsSQL->LivroAss('S', 
      $self->{edtCodigo}->GetValue(), ""), 
      $self->{lstAssuntos}, $self->{slAssuntos});
    $Rotinas->AdicionaValoresLista($ConsultasSQL::ConsSQL->LivroAut('S',
      $self->{edtCodigo}->GetValue(), ""), 
      $self->{lstAutores}, $self->{slAutores});
  } else {
    $self->{edtEdicao}->SetValue(1);
    $self->{edtAnoPubli}->SetValue(substr(
      $Rotinas->retDataHoraStr($Resource::true,$Resource::false),6,4));
    $self->{edtVolume}->SetValue(1);
    $self->{edtCodEditora}->Clear();
    $self->{edtEditora}->Clear();
    $self->{cmbIdioma}->SetSelection(0);
    $self->{edtNPaginas}->SetValue(1);
    $self->{edtPreco}->SetValue("0,00");
    $self->{edtQtdEstoque}->SetValue(1);
    $self->{edtCodAssunto}->Clear();
    $self->{lstAssuntos}->Clear();
    $self->{edtCodAutor}->Clear();
    $self->{lstAutores}->Clear();
    $self->{slAssuntos}->clear();
    $self->{slAutores}->clear();
  }
}  

sub HabilitaDadosLocal {
  my( $self, $bHabilita ) = @_; 

  $self->{edtEdicao}->Enable($bHabilita);
  $self->{edtAnoPubli}->Enable($bHabilita);
  $self->{edtVolume}->Enable($bHabilita);
  $self->{edtCodEditora}->Enable($bHabilita);
  $self->{btnPEditora}->Enable($bHabilita);
  $self->{cmbIdioma}->Enable($bHabilita);
  $self->{edtNPaginas}->Enable($bHabilita);
  $self->{edtPreco}->Enable($bHabilita);
  $self->{edtQtdEstoque}->Enable($bHabilita);
  $self->{edtCodAssunto}->Enable($bHabilita);
  $self->{btnPAssunto}->Enable($bHabilita);
  $self->{btnAdAssuntos}->Enable($bHabilita);
  $self->{lstAssuntos}->Enable($bHabilita);
  $self->{edtCodAutor}->Enable($bHabilita);
  $self->{btnPAutor}->Enable($bHabilita);
  $self->{btnAdAutores}->Enable($bHabilita);
  $self->{lstAutores}->Enable($bHabilita);
}

sub OnEdtCodigo_Killfocus {
  my( $self, $event ) = @_;

  if (length($self->GetValue()) > 0) {
  	if ($RotinasGlobais::Rotinas->validaISBN(
      $self->GetValue())==$Resource::false) {
      Wx::MessageBox($Resource::STR_ISBNINV, "Erro", wxOK | wxICON_ERROR);
      $self->Clear();
      $self->SetFocus();
    }
  }
  $event->Skip();
}

sub AdicionaCombo {
  my $self = shift;
  my $nLinha = 0;
  my $Campos = ListaStr->new();
  my $Rotinas = $RotinasGlobais::Rotinas;

  if ($Rotinas->ConsultaDadosLista($Rotinas->atrib('gConexao'), $Campos,
    $ConsultasSQL::ConsSQL->Idioma('S',"",""))) {
    my @lista = $Campos->col();  
    my @lista2 = [];
    for($nLinha = 0; $nLinha < $Campos->tam(); $nLinha++) {
      $lista2[$nLinha] = $lista[$nLinha][0];
	    $self->{cmbIdioma}->Append($lista[$nLinha][1]);
    }
    $self->{slIdiomas}->set_col(@lista2);
    $self->{slIdiomas}->set_tam($Campos->tam());
  }
}

sub SalvaLista {
  my( $self, $sOpcao ) = @_;
  my $nCont = 0;
  my $Rotinas = $RotinasGlobais::Rotinas;
  my $ConsSQL = $ConsultasSQL::ConsSQL;
  my $sISBN = $self->{edtCodigo}->GetValue();

  if ($sOpcao=~'A') {
    $Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), 
    $ConsSQL->LivroAss('D',$sISBN,"")); 

    my $nQtd = $self->{slAssuntos}->tam();
    my @lista = $self->{slAssuntos}->col();
    for($nCont = 0; $nCont < $nQtd; $nCont++) {
      $Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), 
        $ConsSQL->LivroAss('I', $sISBN, $lista[$nCont]));
    }
  } elsif ($sOpcao=~'B') {
  	$Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), 
    $ConsSQL->LivroAut('D',$sISBN,""));

    my $nQtd = $self->{slAutores}->tam();
    my @lista = $self->{slAutores}->col();
    for($nCont = 0; $nCont < $nQtd; $nCont++) {
      $Rotinas->AtualizaDados($Rotinas->atrib('gConexao'), 
        $ConsSQL->LivroAut('I', $sISBN, $lista[$nCont]));
    }
  }
}

sub OnEdtCodEditora_Killfocus {
  my( $self, $event ) = @_;
  my $ConsCampo = ListaStr->new();

  if (length($self->GetValue()) > 0) {
    my $sEditora = $RotinasGlobais::Rotinas->ConsultaCampoDesc($ConsCampo, 
      $ConsultasSQL::ConsSQL->Editora('S',
      $self->GetValue(),""),$Resource::STR_EDTNENC);
    if (length($sEditora) > 0) {
      $self->GetParent()->{edtEditora}->SetValue($sEditora);
    } else {
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent->{edtEditora}->Clear();
  }
  $event->Skip();
}

sub OnBtnPEditoraClick {
  my( $self, $event ) = @_;

  my $fConEditoras = frmConEditoras->new($self);
  $fConEditoras->ShowModal();
  $self->{edtCodEditora}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCodEditora_Killfocus($self->{edtCodEditora}, $event);
  $event->Skip();
}

sub OnEdtPreco_Killfocus {
  my( $self, $event ) = @_;

  my $Rotinas = $RotinasGlobais::Rotinas;
  if ($Rotinas->ValidaFloat($Rotinas->VirgulaParaPonto($self->GetValue(), 
        $Resource::false))) {
    $self->SetValue(
      $Rotinas->VirgulaParaPonto($self->GetValue(), $Resource::true));
  } else {
    $self->SetValue("0,01");
    $self->SetFocus();
  }
  $event->Skip();
}

sub OnEdtCodAssunto_Killfocus {
  my( $self, $event ) = @_;
  my $ConsCampo = ListaStr->new();

  if (length($self->GetValue()) > 0) {
    my $sAssunto = $RotinasGlobais::Rotinas->ConsultaCampoDesc($ConsCampo, 
      $ConsultasSQL::ConsSQL->Assunto('S',
      $self->GetValue(),""),$Resource::STR_EDTNENC);
    if (length($sAssunto) > 0) {
      $self->GetParent()->{edtAssunto}->SetValue($sAssunto);
    } else {
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent->{edtAssunto}->Clear();
  }
  $event->Skip();
}

sub OnBtnPAssuntoClick {
  my( $self, $event ) = @_;

  my $fConAssuntos = frmConAssuntos->new($self);
  $fConAssuntos->ShowModal();
  $self->{edtCodAssunto}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCodAssunto_Killfocus($self->{edtCodAssunto}, $event);
  $event->Skip();
}

sub OnBtnAdAssuntosClick {
  my( $self, $event ) = @_;

  $RotinasGlobais::Rotinas->AdicionaItemLista($self->{lstAssuntos}, 
    $self->{slAssuntos}, $self->{edtCodAssunto}, $self->{edtAssunto});
  $event->Skip();
}

sub OnLstAssuntos_Dblclk {
  my( $self, $event ) = @_;

  $RotinasGlobais::Rotinas->RemoveItemLista(
    $self->{lstAssuntos},$self->{slAssuntos});
  $event->Skip();
}

sub OnEdtCodAutor_Killfocus {
  my( $self, $event ) = @_;
  my $ConsCampo = ListaStr->new();

  if (length($self->GetValue()) > 0) {
    my $sAutor = $RotinasGlobais::Rotinas->ConsultaCampoDesc($ConsCampo, 
      $ConsultasSQL::ConsSQL->Autor('S',
      $self->GetValue(),""),$Resource::STR_AUTNENC);
    if (length($sAutor) > 0) {
      $self->GetParent()->{edtAutor}->SetValue($sAutor);
    } else {
      $self->Clear();
      $self->SetFocus();
    }
  } else {
    $self->GetParent->{edtAutor}->Clear();
  }
  $event->Skip();
}

sub OnBtnPAutorClick {
  my( $self, $event ) = @_;

  my $fConAutores = frmConAutores->new($self);
  $fConAutores->ShowModal();
  $self->{edtCodAutor}->SetValue(
    $RotinasGlobais::Rotinas->atrib('sCodigoSelecionado'));
  OnEdtCodAutor_Killfocus($self->{edtCodAutor}, $event);
  $event->Skip();
}

sub OnBtnAdAutoresClick {
  my( $self, $event ) = @_;

  $RotinasGlobais::Rotinas->AdicionaItemLista($self->{lstAutores}, 
    $self->{slAutores}, $self->{edtCodAutor}, $self->{edtAutor});
  $event->Skip();
}

sub OnLstAutores_Dblclk {
  my( $self, $event ) = @_;

  $RotinasGlobais::Rotinas->RemoveItemLista(
    $self->{lstAutores},$self->{slAutores});
  $event->Skip();
}

1;

