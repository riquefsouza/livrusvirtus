
#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>

#include "plivruskde.h"

static const char *description =
	I18N_NOOP("Plivruskde");
// INSERT A DESCRIPTION FOR YOUR APPLICATION HERE
	
	
static KCmdLineOptions options[] =
{
  { "+[File]", I18N_NOOP("file to open"), 0 },
  { 0, 0, 0 }
  // INSERT YOUR COMMANDLINE OPTIONS HERE
};

int main(int argc, char *argv[])
{

	KAboutData aboutData( "plivruskde", I18N_NOOP("Plivruskde"),
		VERSION, description, KAboutData::License_GPL,
		"(c) 2000, Henrique F. de Souza", 0, 0, "hfs1978@yahoo.com.br");
	aboutData.addAuthor("Henrique F. de Souza",I18N_NOOP("Maintainer"), "hfs1978@yahoo.com.br");
	
	KCmdLineArgs::init( argc, argv, &aboutData );
	KCmdLineArgs::addCmdLineOptions( options ); // Add our own options.

  KApplication app;
 
  if (app.isRestored())
  {
    RESTORE(PlivruskdeApp);
  }
  else 
  {
    PlivruskdeApp *testmdi = new PlivruskdeApp();
    testmdi->show();

    KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
		
		if (args->count())
		{
			for(int i=0;i<args->count();i++)
			{
        testmdi->openDocumentFile(args->arg(i));
		  }
		}
		else
		{
		  testmdi->openDocumentFile();
		}
		args->clear();
  }

  return app.exec();
}  
