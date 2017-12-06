#!/usr/bin/python
def getConnection( databaseType, databaseName ):
   connection = None

   if databaseType == 'MySQL':
      import MySQLdb
      connection = MySQLdb.connect( db = databaseName )
   elif databaseType == 'Access':
      import odbc
      connection = odbc.odbc( databaseName )

   return connection        

#connection = getConnection( 'MySQL', "livrus" )
connection = getConnection( 'Access', "AClivrus" )
cursor = connection.cursor()           

try:
  cursor.execute( 'select * from assunto' )   
except:
  print "An error occurred in your query statement." 
else:
  results = cursor.fetchall()     # store results in list

for entry in results: 
  print entry


cursor.close()                  # close cursor
cursor = None
connection.close()              # close connection
connection = None
