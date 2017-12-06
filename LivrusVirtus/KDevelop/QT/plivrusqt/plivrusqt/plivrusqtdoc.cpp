
// include files for Qt
#include <qdir.h>
#include <qfileinfo.h>
#include <qwidget.h>
#include <qmsgbox.h>
#include <qfiledialog.h>


// application specific includes
#include "plivrusqtdoc.h"
#include "plivrusqt.h"
#include "plivrusqtview.h"


PlivrusqtDoc::PlivrusqtDoc()
{
  pViewList = new QList<PlivrusqtView>;
  pViewList->setAutoDelete(false);
}

PlivrusqtDoc::~PlivrusqtDoc()
{
  delete pViewList;
}

void PlivrusqtDoc::addView(PlivrusqtView *view)
{
  pViewList->append(view);
	changedViewList();
}

void PlivrusqtDoc::removeView(PlivrusqtView *view)
{
	  pViewList->remove(view);
	  if(!pViewList->isEmpty())
			changedViewList();
		else
			deleteContents();
}

void PlivrusqtDoc::changedViewList(){	
	
	PlivrusqtView *w;
	if((int)pViewList->count() == 1){
  	w=pViewList->first();
  	w->setCaption(m_title);
	}
	else{
		int i;
    for( i=1,w=pViewList->first(); w!=0; i++, w=pViewList->next())
  		w->setCaption(QString(m_title+":%1").arg(i));	
	}
}

bool PlivrusqtDoc::isLastView() {
  return ((int) pViewList->count() == 1);
}


void PlivrusqtDoc::updateAllViews(PlivrusqtView *sender)
{
  PlivrusqtView *w;
  for(w=pViewList->first(); w!=0; w=pViewList->next())
  {
     w->update(sender);
  }

}

void PlivrusqtDoc::setPathName(const QString &name)
{
  m_filename=name;
	m_title=QFileInfo(name).fileName();
}

const QString& PlivrusqtDoc::pathName() const
{
  return m_filename;
}

void PlivrusqtDoc::setTitle(const QString &title)
{
  m_title=title;
}

const QString &PlivrusqtDoc::title() const
{
  return m_title;
}


void PlivrusqtDoc::closeDocument()
{
  PlivrusqtView *w;
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

bool PlivrusqtDoc::newDocument()
{
  /////////////////////////////////////////////////
  // TODO: Add your document initialization code here
  /////////////////////////////////////////////////
  modified=false;
  return true;
}

bool PlivrusqtDoc::openDocument(const QString &filename, const char *format /*=0*/)
{

	QFile f( filename );
	if ( !f.open( IO_ReadOnly ) )
		return false;
  /////////////////////////////////////////////////
  // TODO: Add your document opening code here
  /////////////////////////////////////////////////
	f.close();
	
  modified=false;
  m_filename=filename;
	m_title=QFileInfo(f).fileName();
  return true;
}

bool PlivrusqtDoc::saveDocument(const QString &filename, const char *format /*=0*/)
{
	QFile f( filename );
	if ( !f.open( IO_WriteOnly ) )
		return false;

  /////////////////////////////////////////////////
  // TODO: Add your document saving code here
  /////////////////////////////////////////////////

  f.close();

  modified=false;
  m_filename=filename;
	m_title=QFileInfo(f).fileName();
  return true;
}

void PlivrusqtDoc::deleteContents()
{
  /////////////////////////////////////////////////
  // TODO: Add implementation to delete the document contents
  /////////////////////////////////////////////////

}

bool PlivrusqtDoc::canCloseFrame(PlivrusqtView* pFrame)
{
	if(!isLastView())
		return true;
		
	bool ret=false;
  if(isModified())
  {
		QString saveName;
  	switch(QMessageBox::information(pFrame, title(), tr("The current file has been modified.\n"
                          "Do you want to save it?"),QMessageBox::Yes, QMessageBox::No, QMessageBox::Cancel ))
    {
			case QMessageBox::Yes:
				if(title().contains(tr("Untitled")))
				{
					saveName=QFileDialog::getSaveFileName(0, 0, pFrame);
                                          if(saveName.isEmpty())
          	                                return false;
				}
				else
					saveName=pathName();

				if(!saveDocument(saveName))
				{
 					switch(QMessageBox::critical(pFrame, tr("I/O Error !"), tr("Could not save the current document !\n"
																												"Close anyway ?"),QMessageBox::Yes ,QMessageBox::No))

 					{
 						case QMessageBox::Yes:
 							ret=true;
 						case QMessageBox::No:
 							ret=false;
 					}
				}
				else
					ret=true;
				break;
			case QMessageBox::No:
				ret=true;
				break;
			case QMessageBox::Cancel:
			default:
				ret=false;
				break;
		}
	}
	else
		ret=true;

	return ret;
}
