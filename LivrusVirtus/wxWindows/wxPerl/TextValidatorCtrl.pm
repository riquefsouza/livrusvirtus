use Wx 0.15 qw[:allclasses];
use strict;
package TextValidatorCtrl;

use Wx qw[:everything];
use base qw(Wx::TextCtrl);
use strict;
use Wx::Event qw(EVT_CHAR);
require resource;

our $FILTER_NONE = 0;
our $FILTER_ALPHA = 1;
our $FILTER_NUMERIC = 2;

sub new {
	my( $self, $parent, $id, $value, $pos, $size, $style, $nFiltro ) = @_;
	$parent = undef              unless defined $parent;
	$id     = -1                 unless defined $id;
	$value  = ""                 unless defined $value;
	$pos    = wxDefaultPosition  unless defined $pos;
	$size   = wxDefaultSize      unless defined $size;
	#$name   = ""                 unless defined $name;
	$style  = 0                  unless defined $style;
  $nFiltro = 0                 unless defined $nFiltro; 

	$self = $self->SUPER::new( $parent, $id, $value, $pos, $size, $style, 
    wxDefaultValidator, "" );
  $self->{mFiltro} = $nFiltro;
  EVT_CHAR( $self, \&OnChar );
  return $self;
}

sub OnChar {
  my( $self, $event ) = @_;

  if ($self->{mFiltro} != $FILTER_NONE) {
    my $chave = $event->GetKeyCode();
    if ($chave < WXK_SPACE || $chave == WXK_DELETE || $chave > 255) {
      $event->Skip();
    } elsif ($self->{mFiltro} == $FILTER_ALPHA) { 
      if (chr($chave) =~ /[a-zA-Z]/ ) {
        $event->Skip();
      }
    } elsif ($self->{mFiltro} == $FILTER_NUMERIC) {
      if (chr($chave) =~ /[0-9]/ ) {
        $event->Skip();
      }
    } else {
      Wx::Bell();
    }
  } else {
    $event->Skip();
  }
}

1;

