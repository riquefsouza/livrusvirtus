use Wx 0.15 qw[:allclasses];
use strict;
package frmSobre;

use Wx qw[:everything];
use base qw(Wx::Dialog);
use strict;

my( $ID_FRMSOBRE_LABBMP, $ID_FRMSOBRE_LABVERSAO, $ID_FRMSOBRE_LABDIREITOS, 
    $ID_FRMSOBRE_LABSISTEMA, $ID_FRMSOBRE_BTNOK ) = ( 1000 .. 1005 );

sub new {
	my( $self, $parent, $id, $title, $pos, $size, $style, $name ) = @_;
	$parent = undef              unless defined $parent;
	$id     = -1                 unless defined $id;
	$title  = ""                 unless defined $title;
	$pos    = wxDefaultPosition  unless defined $pos;
	$size   = wxDefaultSize      unless defined $size;
	$name   = ""                 unless defined $name;
	$style = wxDEFAULT_DIALOG_STYLE unless defined $style;

	$self = $self->SUPER::new( $parent, $id, $title, $pos, $size, $style, $name );
	$self->{labBmp} = Wx::StaticBitmap->new($self, $ID_FRMSOBRE_LABBMP, 
    Wx::Bitmap->new("xpms\\livrusvirtus.xpm", wxBITMAP_TYPE_ANY),);
	$self->{labVersao} = Wx::StaticText->new($self, $ID_FRMSOBRE_LABVERSAO, 
    "Versão: 1.0.0", wxDefaultPosition, wxDefaultSize, );
	$self->{labDireitos} = Wx::StaticText->new($self, $ID_FRMSOBRE_LABDIREITOS, 
    "Todos os diretos reservados para: Henrique F. de Souza", 
    wxDefaultPosition, wxDefaultSize, );
	$self->{labSistema} = Wx::StaticText->new($self, $ID_FRMSOBRE_LABSISTEMA, 
    "Sistema integrante do projeto Livrus Virtus, " . 
    "versão programada no wxGlade em wxPerl.", 
    wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	$self->{btnOk} = Wx::Button->new($self, wxID_OK, "&Ok");

	$self->SetTitle("Sobre o Sistema");
	$self->{labSistema}->SetSize(240, 29);
	$self->{btnOk}->SetSize(75, 25);
	$self->{btnOk}->SetDefault();

	$self->FazLayout();

	return $self;
}

sub FazLayout {
	my $self = shift;

	$self->{sizer_1} = Wx::BoxSizer->new(wxVERTICAL);
	$self->{sizer_2}= Wx::StaticBoxSizer->new(Wx::StaticBox->new($self, -1,""), 
    wxVERTICAL);
	$self->{sizer_2}->Add($self->{labBmp}, 0, wxALIGN_CENTER_HORIZONTAL, 0);
	$self->{sizer_2}->Add($self->{labVersao}, 0, wxALL|wxALIGN_RIGHT, 2);
	$self->{sizer_2}->Add($self->{labDireitos}, 0, wxALL, 2);
	$self->{sizer_2}->Add($self->{labSistema}, 0, 
    wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	$self->{sizer_1}->Add($self->{sizer_2}, 1, wxALL|wxEXPAND, 6);
	$self->{sizer_1}->Add($self->{btnOk}, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
	$self->SetAutoLayout(1);
	$self->SetSizer($self->{sizer_1});
	$self->{sizer_1}->Fit($self);
	$self->{sizer_1}->SetSizeHints($self);
	$self->Layout();
	$self->Centre();
}

1;

