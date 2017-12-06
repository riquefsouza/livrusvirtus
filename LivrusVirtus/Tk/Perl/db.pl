#!/usr/bin/perl
# Fig. 15.18: fig15_18.pl
# Program to query a database and display the contents in a table  

use warnings;
use strict;
use DBI;
#use DBD::ODBC;
#use DBD::mysqlPP;
use DBD::MySql;

#dbi:mysqlPP:database=$database;hostname=$option{h};port=$option{P}

my $dbh = DBI->connect( "dbi:mysql:livrus", "root", "" ) or
   die( "Could not make connection to database: $DBI::errstr" );

my $sth = $dbh->prepare( q{ SELECT * FROM assunto } ) or 
   die( "Cannot prepare statement: ", $dbh->errstr(), "\n" );
     
my $rc = $sth->execute() or
   die( "Cannot execute statement: ", $sth->errstr(), "\n" );

my @array;

while ( @array = $sth->fetchrow_array() ) {
   print($array[0]." - ".$array[1]."\n");
}

# Check to see if fetch terminated early
warn( $DBI::errstr ) if $DBI::err;

$sth->finish();
$dbh->disconnect();
