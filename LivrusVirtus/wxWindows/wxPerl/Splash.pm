use Wx 0.15 qw[:allclasses];
use strict;
package frmSplash;

use Wx qw[:everything];
use base qw(Wx::SplashScreen);
use strict;
use Wx::Event qw(EVT_CLOSE);
require resource;
require Login;

sub new {
	my( $self ) = @_;

	my $bitmap = Wx::Bitmap->new("xpms\\livrusvirtus.xpm", wxBITMAP_TYPE_ANY);
  my $splashStyle=wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT;
  my $milliseconds = 1000;
  my $parent = undef;
	my $id     = -1;
	my $pos    = wxDefaultPosition;
	my $size   = wxDefaultSize;
	my $style  = wxSIMPLE_BORDER | wxSTAY_ON_TOP;

	$self = $self->SUPER::new( $bitmap, $splashStyle, $milliseconds, 
    $parent, $id, $pos, $size, $style );
  EVT_CLOSE( $self, \&OnClose );	

	return $self;
}

sub OnClose {
  my( $self, $event ) = @_;

  $Login::fLogin = frmLogin->new();
  $Login::fLogin->Show($Resource::true);
  $event->Skip();
}

1;

