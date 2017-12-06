#!/usr/local/bin/ruby

require 'DBI'
# require 'DBD::ODBC'

$dbh = DBI.connect( "DBI:ODBC:ACLivrus", "", "" ) 

$sth = $dbh.prepare( "SELECT * FROM assunto" )
     
$rc = $sth.execute() 

while row=$sth.fetch do
 p row
end


$sth.finish()
$dbh.disconnect()
