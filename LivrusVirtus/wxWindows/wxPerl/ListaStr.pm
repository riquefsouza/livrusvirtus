use strict;
package ListaStr;

#our $ListaStr = undef;

sub new {
  my $self = {};

  $self->{local_col} = [];
  $self->{local_tam} = 0;

  bless($self);
  return $self;
}

sub col {
my $self = shift;

  return @{ $self->{local_col} };
}

sub set_col {
my( $self, @col ) = @_;

  @{ $self->{local_col} } = @col;
}

sub tam {
my $self = shift;

  return $self->{local_tam};
}

sub set_tam {
my( $self, $tam ) = @_;

  $self->{local_tam} = $tam;
}

sub clear {
my $self = shift;

  $self->{local_col} = [];
  $self->{local_tam} = 0;
}

1;
