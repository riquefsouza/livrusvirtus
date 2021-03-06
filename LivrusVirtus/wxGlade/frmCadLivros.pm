# generated by wxGlade 0.3.1 on Fri Jan 14 19:47:45 2005
# To get wxPerl visit http://wxPerl.sourceforge.net/

use Wx 0.15 qw[:allclasses];
use strict;
package frmCadLivros;

use Wx qw[:everything];
use base qw(Wx::Panel);
use strict;

# begin wxGlade: ::dependencies
# end wxGlade

sub new {
	my( $self, $parent, $id, $pos, $size, $style, $name ) = @_;
	$parent = undef              unless defined $parent;
	$id     = -1                 unless defined $id;
	$pos    = wxDefaultPosition  unless defined $pos;
	$size   = wxDefaultSize      unless defined $size;
	$name   = ""                 unless defined $name;

# begin wxGlade: frmCadLivros::new

	$style = wxTAB_TRAVERSAL 
		unless defined $style;

	$self = $self->SUPER::new( $parent, $id, $pos, $size, $style, $name );
	$self->{labCodigo} = Wx::StaticText->new($self, ID_FRMCADASTROS_LABCODIGO, "ISBN:", wxDefaultPosition, wxDefaultSize, );
	$self->{edtCodigo} = Wx::TextCtrl->new($self, ID_FRMCADASTROS_EDTCODIGO, "", wxDefaultPosition, wxDefaultSize, );
		$self->{btnNovo} = Wx::Button->new($self, ID_FRMCADASTROS_BTNNOVO, "&Novo");
	$self->{labDescricao} = Wx::StaticText->new($self, ID_FRMCADASTROS_LABDESCRICAO, "T�tulo:", wxDefaultPosition, wxDefaultSize, );
	$self->{edtDescricao} = Wx::TextCtrl->new($self, ID_FRMCADASTROS_EDTDESCRICAO, "", wxDefaultPosition, wxDefaultSize, );
	$self->{labEdicao} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABEDICAO, "Edi��o:", wxDefaultPosition, wxDefaultSize, );
	$self->{edtEdicao} = Wx::SpinCtrl->new($self, ID_FRMCADLIVROS_EDTEDICAO, "1", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{labAnoPubli} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABANOPUBLI, "Ano Publica��o:", wxDefaultPosition, wxDefaultSize, );
	$self->{edtAnoPubli} = Wx::SpinCtrl->new($self, ID_FRMCADLIVROS_EDTANOPUBLI, "1", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{labEditora} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABEDITORA, "Editora:", wxDefaultPosition, wxDefaultSize, );
	$self->{edtCodEditora} = Wx::TextCtrl->new($self, ID_FRMCADLIVROS_EDTCODEDITORA, "", wxDefaultPosition, wxDefaultSize, );
	$self->{edtEditora} = Wx::TextCtrl->new($self, ID_FRMCADLIVROS_EDTEDITORA, "", wxDefaultPosition, wxDefaultSize, );
		$self->{btnPEditora} = Wx::Button->new($self, ID_FRMCADLIVROS_BTNPEDITORA, "...");
	$self->{labVolume} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABVOLUME, "Volume:", wxDefaultPosition, wxDefaultSize, );
	$self->{edtVolume} = Wx::SpinCtrl->new($self, ID_FRMCADLIVROS_EDTVOLUME, "1", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{labIdioma} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABIDIOMA, "Idioma: ", wxDefaultPosition, wxDefaultSize, );
	$self->{cmbIdioma} = Wx::Choice->new($self, ID_FRMCADLIVROS_CMBIDIOMA, wxDefaultPosition, wxDefaultSize, ["choice 1"], );
	$self->{labNPaginas} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABNPAGINAS, "N� P�ginas: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtNPaginas} = Wx::SpinCtrl->new($self, ID_FRMCADLIVROS_EDTNPAGINAS, "1", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 9999, 1);
	$self->{labAssunto} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABASSUNTO, "Assunto: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtCodAssunto} = Wx::TextCtrl->new($self, ID_FRMCADLIVROS_EDTCODASSUNTO, "", wxDefaultPosition, wxDefaultSize, );
	$self->{edtAssunto} = Wx::TextCtrl->new($self, ID_FRMCADLIVROS_EDTASSUNTO, "", wxDefaultPosition, wxDefaultSize, );
		$self->{btnAdAssuntos} = Wx::Button->new($self, ID_FRMCADLIVROS_BTNADASSUNTOS, "+");
		$self->{btnPAssunto} = Wx::Button->new($self, ID_FRMCADLIVROS_BTNPASSUNTO, "...");
	$self->{labPreco} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABPRECO, "Pre�o: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtPreco} = Wx::TextCtrl->new($self, ID_FRMCADLIVROS_EDTPRECO, "", wxDefaultPosition, wxDefaultSize, );
	$self->{lstAssuntos} = Wx::ListBox->new($self, ID_FRMCADLIVROS_LSTASSUNTOS, wxDefaultPosition, wxDefaultSize, ["choice 1"], );
	$self->{labQtdEstoque} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABQTDESTOQUE, "Qtd. Estoque: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtQtdEstoque} = Wx::SpinCtrl->new($self, ID_FRMCADLIVROS_EDTQTDESTOQUE, "0", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999, 0);
	$self->{labAutor} = Wx::StaticText->new($self, ID_FRMCADLIVROS_LABAUTOR, "Autor: ", wxDefaultPosition, wxDefaultSize, );
	$self->{edtCodAutor} = Wx::TextCtrl->new($self, ID_FRMCADLIVROS_EDTCODAUTOR, "", wxDefaultPosition, wxDefaultSize, );
	$self->{edtAutor} = Wx::TextCtrl->new($self, ID_FRMCADLIVROS_EDTAUTOR, "", wxDefaultPosition, wxDefaultSize, );
		$self->{btnAdAutores} = Wx::Button->new($self, ID_FRMCADLIVROS_BTNADAUTORES, "+");
		$self->{btnPAutor} = Wx::Button->new($self, ID_FRMCADLIVROS_BTNPAUTOR, "...");
	$self->{lstAutores} = Wx::ListBox->new($self, ID_FRMCADLIVROS_LSTAUTORES, wxDefaultPosition, wxDefaultSize, ["choice 1"], );
		$self->{btnPesquisar} = Wx::Button->new($self, ID_FRMCADASTROS_BTNPESQUISAR, "&Pesquisar");
		$self->{btnAnterior} = Wx::Button->new($self, ID_FRMCADASTROS_BTNANTERIOR, "&Anterior");
		$self->{btnProximo} = Wx::Button->new($self, ID_FRMCADASTROS_BTNPROXIMO, "Pr�xi&mo");
		$self->{btnSalvar} = Wx::Button->new($self, ID_FRMCADASTROS_BTNSALVAR, "&Salvar");
		$self->{btnExcluir} = Wx::Button->new($self, ID_FRMCADASTROS_BTNEXCLUIR, "&Excluir");
		$self->{btnLimpar} = Wx::Button->new($self, ID_FRMCADASTROS_BTNLIMPAR, "&Limpar");
		$self->{btnFechar} = Wx::Button->new($self, ID_FRMCADASTROS_BTNFECHAR, "&Fechar");

	$self->__set_properties();
	$self->__do_layout();

	return $self;

# end wxGlade
}


sub __set_properties {
	my $self = shift;

# begin wxGlade: frmCadLivros::__set_properties

		$self->SetSize(513, 434);
		$self->{labCodigo}->SetSize(36, 13);
		$self->{edtCodigo}->SetSize(121, 21);
		$self->{btnNovo}->SetSize(75, 25);
		$self->{labDescricao}->SetSize(57, 13);
		$self->{edtDescricao}->SetSize(312, 21);
		$self->{edtDescricao}->Enable(0);
		$self->{labEdicao}->SetSize(48, 13);
		$self->{edtEdicao}->SetSize(92, 21);
		$self->{edtEdicao}->Enable(0);
		$self->{labAnoPubli}->SetSize(81, 13);
		$self->{edtAnoPubli}->SetSize(92, 21);
		$self->{edtAnoPubli}->Enable(0);
		$self->{labEditora}->SetSize(39, 13);
		$self->{edtCodEditora}->SetSize(78, 21);
		$self->{edtCodEditora}->Enable(0);
		$self->{edtEditora}->SetSize(216, 21);
		$self->{edtEditora}->Enable(0);
		$self->{btnPEditora}->SetSize(21, 21);
		$self->{btnPEditora}->Enable(0);
		$self->{edtVolume}->SetSize(92, 21);
		$self->{edtVolume}->Enable(0);
		$self->{cmbIdioma}->SetSize(320, 21);
		$self->{cmbIdioma}->Enable(0);
	$self->{cmbIdioma}->SetSelection(0);
		$self->{edtNPaginas}->SetSize(92, 21);
		$self->{edtNPaginas}->Enable(0);
		$self->{edtCodAssunto}->SetSize(78, 21);
		$self->{edtCodAssunto}->Enable(0);
		$self->{edtAssunto}->SetSize(192, 21);
		$self->{edtAssunto}->Enable(0);
		$self->{btnAdAssuntos}->SetSize(21, 21);
		$self->{btnAdAssuntos}->Enable(0);
		$self->{btnPAssunto}->SetSize(21, 21);
		$self->{btnPAssunto}->Enable(0);
		$self->{edtPreco}->SetSize(92, 21);
		$self->{edtPreco}->Enable(0);
		$self->{lstAssuntos}->SetSize(320, 48);
		$self->{lstAssuntos}->Enable(0);
	$self->{lstAssuntos}->SetSelection(0);
		$self->{edtQtdEstoque}->SetSize(92, 21);
		$self->{edtQtdEstoque}->Enable(0);
		$self->{edtCodAutor}->SetSize(78, 21);
		$self->{edtCodAutor}->Enable(0);
		$self->{edtAutor}->SetSize(192, 21);
		$self->{edtAutor}->Enable(0);
		$self->{btnAdAutores}->SetSize(21, 21);
		$self->{btnAdAutores}->Enable(0);
		$self->{btnPAutor}->SetSize(21, 21);
		$self->{btnPAutor}->Enable(0);
		$self->{lstAutores}->SetSize(320, 48);
		$self->{lstAutores}->Enable(0);
	$self->{lstAutores}->SetSelection(0);
		$self->{btnPesquisar}->SetSize(75, 25);
		$self->{btnAnterior}->SetSize(75, 25);
		$self->{btnAnterior}->Enable(0);
		$self->{btnProximo}->SetSize(75, 25);
		$self->{btnProximo}->Enable(0);
		$self->{btnSalvar}->SetSize(75, 25);
		$self->{btnSalvar}->Enable(0);
		$self->{btnExcluir}->SetSize(75, 25);
		$self->{btnExcluir}->Enable(0);
		$self->{btnLimpar}->SetSize(75, 25);
		$self->{btnFechar}->SetSize(75, 25);

# end wxGlade
}

sub __do_layout {
	my $self = shift;

# begin wxGlade: frmCadLivros::__do_layout

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
		$self->{sizer_2}->Add($self->{btnSalvar}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
		$self->{sizer_2}->Add($self->{btnExcluir}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
		$self->{sizer_2}->Add($self->{btnLimpar}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
		$self->{sizer_2}->Add($self->{btnFechar}, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
		$self->{sizer_1}->Add($self->{sizer_2}, 0, wxRIGHT|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4);
		$self->SetAutoLayout(1);
		$self->SetSizer($self->{sizer_1});

# end wxGlade
}

# end of class frmCadLivros

1;

