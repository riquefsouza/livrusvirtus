
// include files for Qt
#include <qdir.h>
#include <qfileinfo.h>
#include <qwidget.h>

// include files for KDE
#include <klocale.h>
#include <kmessagebox.h>
#include <kfiledialog.h>
#include <kio/job.h>
#include <kio/netaccess.h>

// application specific includes
#include "plivruskde.h"
#include "plivruskdedoc.h"
#include "plivruskdeview.h"
#include "plivruskdedoc.h"

PlivruskdeDoc::PlivruskdeDoc()
{
  pViewList = new QList<PlivruskdeView>;
  pViewList->setAutoDelete(false);
}

PlivruskdeDoc::~PlivruskdeDoc()
{
  delete pViewList;
}

void PlivruskdeDoc::addView(PlivruskdeView *view)
{
  pViewList->append(view);
	changedViewList();
}

void PlivruskdeDoc::removeView(PlivruskdeView *view)
{
	  pViewList->remove(view);
	  if(!pViewList->isEmpty())
			changedViewList();
		else
			deleteContents();
}

void PlivruskdeDoc::changedViewList(){

	PlivruskdeView *w;
	if((int)pViewList->count() == 1){
  	w=pViewList->first();
  	w->setCaption(URL().fileName());
	}
	else{
		int i;
    for( i=1,w=pViewList->first(); w!=0; i++, w=pViewList->next())
  		w->setCaption(QString(URL().fileName()+":%1").arg(i));
	}
}

bool PlivruskdeDoc::isLastView() {
  return ((int) pViewList->count() == 1);
}


void PlivruskdeDoc::updateAllViews(PlivruskdeView *sender)
{
  PlivruskdeView *w;
  for(w=pViewList->first(); w!=0; w=pViewList->next())
  {
     w->update(sender);
  }

}

void PlivruskdeDoc::setURL(const KURL &url)
{
  doc_url=url;
}

const KURL& PlivruskdeDoc::URL() const
{
  return doc_url;
}

void PlivruskdeDoc::closeDocument()
{
  PlivruskdeView *w;
  if(!isLastView())
  {
    for(w=pViewList->first(); w!=0; w=pViewList->next())
    {
   	 	if(!w->close())
 				break;
    }
	}
  if(isLastView())
  {
  	w=pViewList->first();
  	w->close();
  }
}

bool PlivruskdeDoc::newDocument()
{
  /////////////////////////////////////////////////
  // TODO: Add your document initialization code here
  /////////////////////////////////////////////////
  modified=false;
  return true;
}

bool PlivruskdeDoc::openDocument(const KURL &url, const char *format /*=0*/)
{

  QString tmpfile;
  KIO::NetAccess::download( url, tmpfile );

  /////////////////////////////////////////////////
	QFile f( tmpfile );
	if ( !f.open( IO_ReadOnly ) )
		return false;
  /////////////////////////////////////////////////
  // TODO: Add your document opening code here
  /////////////////////////////////////////////////
	f.close();

  /////////////////////////////////////////////////
  KIO::NetAccess::removeTempFile( tmpfile );
  doc_url=url;

  modified=false;
  return true;
}

bool PlivruskdeDoc::saveDocument(const KURL &url, const char *format /*=0*/)
{
//	QFile f( filename );
//	if ( !f.open( IO_WriteOnly ) )
//		return false;
//
//  /////////////////////////////////////////////////
//  // TODO: Add your document saving code here
//  /////////////////////////////////////////////////
//
//  f.close();
//
//  modified=false;
//	m_filename=filename;
//	m_title=QFileInfo(f).fileName();
  return true;
}

void PlivruskdeDoc::deleteContents()
{
  /////////////////////////////////////////////////
  // TODO: Add implementation to delete the document contents
  /////////////////////////////////////////////////

}

bool PlivruskdeDoc::canCloseFrame(PlivruskdeView* pFrame)
{
	if(!isLastView())
		return true;

	bool ret=false;
  if(isModified())
  {
		KURL saveURL;
  	switch(KMessageBox::warningYesNoCancel(pFrame, i18n("The current file has been modified.\n"
                          "Do you want to save it?"),URL().fileName()))
    {
			case KMessageBox::Yes:
				if(URL().fileName().contains(i18n("Untitled")))
				{
					saveURL=KFileDialog::getSaveURL(QDir::currentDirPath(),
                      i18n("*|All files"), pFrame, i18n("Save as..."));
          if(saveURL.isEmpty())
          	return false;
				}
				else
						saveURL=URL();

				if(!saveDocument(saveURL))
				{
 					switch(KMessageBox::warningYesNo(pFrame,i18n("Could not save the current document !\n"
																												"Close anyway ?"), i18n("I/O Error !")))
 					{
 						case KMessageBox::Yes:
 							ret=true;
 						case KMessageBox::No:
 							ret=false;
 					}
				}
				else
					ret=true;
				break;
			case KMessageBox::No:
				ret=true;
				break;
			case KMessageBox::Cancel:
			default:
				ret=false;
				break;
		}
	}
	else
		ret=true;

	return ret;
}
