
#include <qapplication.h>
#include <qfont.h>
#include <qstring.h>
#include <qtextcodec.h>
#include <qtranslator.h>

#include "plivrusqt.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  a.setFont(QFont("helvetica", 12));
  QTranslator tor( 0 );
  // set the location where your .qm files are in load() below as the last parameter instead of "."
  // for development, use "/" to use the english original as
  // .qm files are stored in the base project directory.
  tor.load( QString("plivrusqt.") + QTextCodec::locale(), "." );
  a.installTranslator( &tor );

  PlivrusqtApp *plivrusqt=new PlivrusqtApp();
  a.setMainWidget(plivrusqt);

  plivrusqt->show();

  if(argc>1)
    plivrusqt->openDocumentFile(argv[1]);
	else
	  plivrusqt->openDocumentFile();
	
  return a.exec();
}
