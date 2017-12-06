#!/usr/bin/perl -w -- 

use Wx 0.15 qw[:allclasses];
use strict;
1;

package main;

use Principal;
use RotinasGlobais;
use ConsultasSQL;
use ListaStr;
require Splash;
require resource;

unless(caller){
	local *Wx::App::OnInit = sub{1};
	my $LivrusApp = Wx::App->new();
	Wx::InitAllImageHandlers();

  $RotinasGlobais::Rotinas = RotinasGlobais->new();
  $ConsultasSQL::ConsSQL = ConsultasSQL->new();
  $Principal::fPrincipal = frmPrincipal->new();
  $LivrusApp->SetTopWindow($Principal::fPrincipal);

  if (!$RotinasGlobais::Rotinas->ConectaBanco("DBI:ODBC:ACLivrus","","")) {
    exit(0)
  }

  my $fSplash = frmSplash->new();
  $fSplash->Show($Resource::true);

  #$Principal::fPrincipal->Show($Resource::true);
	$LivrusApp->MainLoop();
}
