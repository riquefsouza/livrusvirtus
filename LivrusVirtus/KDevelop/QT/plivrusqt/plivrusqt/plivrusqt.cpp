
// Qt includes
#include <qvbox.h>
#include <qaccel.h>

// application specific includes
#include "plivrusqtview.h"
#include "plivrusqtdoc.h"
#include "plivrusqt.h"

#include "filenew.xpm"
#include "fileopen.xpm"
#include "filesave.xpm"

PlivrusqtApp::PlivrusqtApp()
{
  setCaption(tr("Plivrusqt " VERSION ) );

  printer = new QPrinter;
  untitledCount=0;
  pDocList = new QList<PlivrusqtDoc>();
  pDocList->setAutoDelete(true);

  ///////////////////////////////////////////////////////////////////
  // call inits to invoke all other construction parts
  initView();
  initActions();
  initMenuBar();
  initToolBar();
  initStatusBar();
  resize( 450, 400 );

  viewToolBar->setOn(true);
  viewStatusBar->setOn(true);
}

PlivrusqtApp::~PlivrusqtApp()
{
  delete printer;
}

void PlivrusqtApp::initActions()
{
  QPixmap openIcon, saveIcon, newIcon;
  newIcon = QPixmap(filenew);
  openIcon = QPixmap(fileopen);
  saveIcon = QPixmap(filesave);


  fileNew = new QAction(tr("New File"), newIcon, tr("&New"), QAccel::stringToKey(tr("Ctrl+N")), this);
  fileNew->setStatusTip(tr("Creates a new document"));
  fileNew->setWhatsThis(tr("New File\n\nCreates a new document"));
  connect(fileNew, SIGNAL(activated()), this, SLOT(slotFileNew()));

  fileOpen = new QAction(tr("Open File"), openIcon, tr("&Open..."), 0, this);
  fileOpen->setStatusTip(tr("Opens an existing document"));
  fileOpen->setWhatsThis(tr("Open File\n\nOpens an existing document"));
  connect(fileOpen, SIGNAL(activated()), this, SLOT(slotFileOpen()));

  fileSave = new QAction(tr("Save File"), saveIcon, tr("&Save"), QAccel::stringToKey(tr("Ctrl+S")), this);
  fileSave->setStatusTip(tr("Saves the actual document"));
  fileSave->setWhatsThis(tr("Save File.\n\nSaves the actual document"));
  connect(fileSave, SIGNAL(activated()), this, SLOT(slotFileSave()));

  fileSaveAs = new QAction(tr("Save File As"), tr("Save &as..."), 0, this);
  fileSaveAs->setStatusTip(tr("Saves the actual document under a new filename"));
  fileSaveAs->setWhatsThis(tr("Save As\n\nSaves the actual document under a new filename"));
  connect(fileSaveAs, SIGNAL(activated()), this, SLOT(slotFileSave()));

  fileClose = new QAction(tr("Close File"), tr("&Close"), QAccel::stringToKey(tr("Ctrl+W")), this);
  fileClose->setStatusTip(tr("Closes the actual document"));
  fileClose->setWhatsThis(tr("Close File\n\nCloses the actual document"));
  connect(fileClose, SIGNAL(activated()), this, SLOT(slotFileClose()));

  filePrint = new QAction(tr("Print File"), tr("&Print"), QAccel::stringToKey(tr("Ctrl+P")), this);
  filePrint->setStatusTip(tr("Prints out the actual document"));
  filePrint->setWhatsThis(tr("Print File\n\nPrints out the actual document"));
  connect(filePrint, SIGNAL(activated()), this, SLOT(slotFilePrint()));

  fileQuit = new QAction(tr("Exit"), tr("E&xit"), QAccel::stringToKey(tr("Ctrl+Q")), this);
  fileQuit->setStatusTip(tr("Quits the application"));
  fileQuit->setWhatsThis(tr("Exit\n\nQuits the application"));
  connect(fileQuit, SIGNAL(activated()), this, SLOT(slotFileQuit()));

  editCut = new QAction(tr("Cut"), tr("Cu&t"), QAccel::stringToKey(tr("Ctrl+X")), this);
  editCut->setStatusTip(tr("Cuts the selected section and puts it to the clipboard"));
  editCut->setWhatsThis(tr("Cut\n\nCuts the selected section and puts it to the clipboard"));
  connect(editCut, SIGNAL(activated()), this, SLOT(slotEditCut()));

  editCopy = new QAction(tr("Copy"), tr("&Copy"), QAccel::stringToKey(tr("Ctrl+C")), this);
  editCopy->setStatusTip(tr("Copies the selected section to the clipboard"));
  editCopy->setWhatsThis(tr("Copy\n\nCopies the selected section to the clipboard"));
  connect(editCopy, SIGNAL(activated()), this, SLOT(slotEditCopy()));

  editUndo = new QAction(tr("Undo"), tr("&Undo"), QAccel::stringToKey(tr("Ctrl+Z")), this);
  editUndo->setStatusTip(tr("Reverts the last editing action"));
  editUndo->setWhatsThis(tr("Undo\n\nReverts the last editing action"));
  connect(editUndo, SIGNAL(activated()), this, SLOT(slotEditUndo()));

  editPaste = new QAction(tr("Paste"), tr("&Paste"), QAccel::stringToKey(tr("Ctrl+V")), this);
  editPaste->setStatusTip(tr("Pastes the clipboard contents to actual position"));
  editPaste->setWhatsThis(tr("Paste\n\nPastes the clipboard contents to actual position"));
  connect(editPaste, SIGNAL(activated()), this, SLOT(slotEditPaste()));

  viewToolBar = new QAction(tr("Toolbar"), tr("Tool&bar"), 0, this, 0, true);
  viewToolBar->setStatusTip(tr("Enables/disables the toolbar"));
  viewToolBar->setWhatsThis(tr("Toolbar\n\nEnables/disables the toolbar"));
  connect(viewToolBar, SIGNAL(toggled(bool)), this, SLOT(slotViewToolBar(bool)));

  viewStatusBar = new QAction(tr("Statusbar"), tr("&Statusbar"), 0, this, 0, true);
  viewStatusBar->setStatusTip(tr("Enables/disables the statusbar"));
  viewStatusBar->setWhatsThis(tr("Statusbar\n\nEnables/disables the statusbar"));
  connect(viewStatusBar, SIGNAL(toggled(bool)), this, SLOT(slotViewStatusBar(bool)));

  windowNewWindow = new QAction(tr("New Window"), tr("&New Window"), 0, this);
  windowNewWindow->setStatusTip(tr("Opens a new view for the current document"));
  windowNewWindow->setWhatsThis(tr("New Window\n\nOpens a new view for the current document"));
  connect(windowNewWindow, SIGNAL(activated()), this, SLOT(slotWindowNewWindow()));

  windowCascade = new QAction(tr("Cascade"), tr("&Cascade"), 0, this);
  windowCascade->setStatusTip(tr("Cascades all windows"));
  windowCascade->setWhatsThis(tr("Cascade\n\nCascades all windows"));
  connect(windowCascade, SIGNAL(activated()), pWorkspace, SLOT(cascade()));

  windowTile = new QAction(tr("Tile"), tr("&Tile"), 0, this);
  windowTile->setStatusTip(tr("Tiles all windows"));
  windowTile->setWhatsThis(tr("Tile\n\nTiles all windows"));
  connect(windowTile, SIGNAL(activated()), pWorkspace, SLOT(tile()));


  windowAction = new QActionGroup(this, 0, false);
  windowAction->insert(windowNewWindow);
  windowAction->insert(windowCascade);
  windowAction->insert(windowTile);

  helpAboutApp = new QAction(tr("About"), tr("&About..."), 0, this);
  helpAboutApp->setStatusTip(tr("About the application"));
  helpAboutApp->setWhatsThis(tr("About\n\nAbout the application"));
  connect(helpAboutApp, SIGNAL(activated()), this, SLOT(slotHelpAbout()));

}

void PlivrusqtApp::initMenuBar()
{
  ///////////////////////////////////////////////////////////////////
  // MENUBAR

  ///////////////////////////////////////////////////////////////////
  // menuBar entry pFileMenu
  pFileMenu=new QPopupMenu();
  fileNew->addTo(pFileMenu);
  fileOpen->addTo(pFileMenu);
  fileClose->addTo(pFileMenu);
  pFileMenu->insertSeparator();
  fileSave->addTo(pFileMenu);
  fileSaveAs->addTo(pFileMenu);
  pFileMenu->insertSeparator();
  filePrint->addTo(pFileMenu);
  pFileMenu->insertSeparator();
  fileQuit->addTo(pFileMenu);

  ///////////////////////////////////////////////////////////////////
  // menuBar entry editMenu
  pEditMenu=new QPopupMenu();
  editUndo->addTo(pEditMenu);
  pEditMenu->insertSeparator();
  editCut->addTo(pEditMenu);
  editCopy->addTo(pEditMenu);
  editPaste->addTo(pEditMenu);

  ///////////////////////////////////////////////////////////////////
  // menuBar entry viewMenu
  pViewMenu=new QPopupMenu();
  pViewMenu->setCheckable(true);
  viewToolBar->addTo(pViewMenu);
  viewStatusBar->addTo(pViewMenu);
  ///////////////////////////////////////////////////////////////////
  // EDIT YOUR APPLICATION SPECIFIC MENUENTRIES HERE

  ///////////////////////////////////////////////////////////////////
  // menuBar entry windowMenu
  pWindowMenu = new QPopupMenu(this);
  pWindowMenu->setCheckable(true);
  connect(pWindowMenu, SIGNAL(aboutToShow()), this, SLOT(windowMenuAboutToShow()));

  ///////////////////////////////////////////////////////////////////
  // menuBar entry helpMenu
  pHelpMenu=new QPopupMenu();
  helpAboutApp->addTo(pHelpMenu);
  pHelpMenu->insertSeparator();
  pHelpMenu->insertItem(tr("What's &This"), this, SLOT(whatsThis()), SHIFT+Key_F1);


  menuBar()->insertItem(tr("&File"), pFileMenu);
  menuBar()->insertItem(tr("&Edit"), pEditMenu);
  menuBar()->insertItem(tr("&View"), pViewMenu);
  menuBar()->insertItem(tr("&Window"), pWindowMenu);
  menuBar()->insertItem(tr("&Help"), pHelpMenu);

}

void PlivrusqtApp::initToolBar()
{
  ///////////////////////////////////////////////////////////////////
  // TOOLBAR
  fileToolbar = new QToolBar(this, "file operations");
  fileNew->addTo(fileToolbar);
  fileOpen->addTo(fileToolbar);
  fileSave->addTo(fileToolbar);
  fileToolbar->addSeparator();
  QWhatsThis::whatsThisButton(fileToolbar);

}

void PlivrusqtApp::initStatusBar()
{
  ///////////////////////////////////////////////////////////////////
  //STATUSBAR
  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::initView()
{ 
  ////////////////////////////////////////////////////////////////////
  // set the main widget here
  QVBox* view_back = new QVBox( this );
  view_back->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
  pWorkspace = new QWorkspace( view_back );
  setCentralWidget(view_back);
}


void PlivrusqtApp::createClient(PlivrusqtDoc* doc)
{
  PlivrusqtView* w = new PlivrusqtView(doc, pWorkspace,0,WDestructiveClose);
  w->installEventFilter(this);
  doc->addView(w);
  if ( pWorkspace->windowList().isEmpty() ) // show the very first window in maximized mode
    w->showMaximized();
  else
    w->show();
}

void PlivrusqtApp::openDocumentFile(const char* file)
{
  statusBar()->message(tr("Opening file..."));
  PlivrusqtDoc* doc;
	// check, if document already open. If yes, set the focus to the first view
  for(doc=pDocList->first(); doc > 0; doc=pDocList->next())
  {
    if(doc->pathName()==file)
    {
      PlivrusqtView* view=doc->firstView();	
      view->setFocus();
      return;
     }
  }
  doc = new PlivrusqtDoc();
  pDocList->append(doc);
  doc->newDocument();
  // Creates an untitled window if file is 0	
  if(!file)
  {
    untitledCount+=1;
    QString fileName=QString(tr("Untitled%1")).arg(untitledCount);
    doc->setPathName(fileName);
    doc->setTitle(fileName);
  }
  // Open the file
  else
  {
    if(!doc->openDocument(file))
    {
      QMessageBox::critical(this, tr("Error !"),tr("Could not open document !"));
      delete doc;
      return;
    }
  }
  // create the window
  createClient(doc);

  statusBar()->message(tr("Ready."));
}

bool PlivrusqtApp::queryExit()
{
  int exit=QMessageBox::information(this, tr("Quit..."),
                                    tr("Do your really want to quit?"),
                                    QMessageBox::Ok, QMessageBox::Cancel);

  if (exit==1)
  {

  }
  else
  {

  };

  return (exit==1);
}

bool PlivrusqtApp::eventFilter(QObject* object, QEvent* event)
{
  if((event->type() == QEvent::Close)&&((PlivrusqtApp*)object!=this))
  {
    QCloseEvent* e=(QCloseEvent*)event;
    PlivrusqtView* pView=(PlivrusqtView*)object;
    PlivrusqtDoc* pDoc=pView->getDocument();
    if(pDoc->canCloseFrame(pView))
    {
      pDoc->removeView(pView);
      if(!pDoc->firstView())
        pDocList->remove(pDoc);

      e->accept();
    }
    else
      e->ignore();
  }
  return QWidget::eventFilter( object, event );    // standard event processing
}

/////////////////////////////////////////////////////////////////////
// SLOT IMPLEMENTATION
/////////////////////////////////////////////////////////////////////


void PlivrusqtApp::slotFileNew()
{
  statusBar()->message(tr("Creating new file..."));

  openDocumentFile();		

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotFileOpen()
{
  statusBar()->message(tr("Opening file..."));

  QString fileName = QFileDialog::getOpenFileName(0,0,this);
  if (!fileName.isEmpty())
  {
     openDocumentFile(fileName);		
  }
  statusBar()->message(tr("Ready."));
}


void PlivrusqtApp::slotFileSave()
{
  statusBar()->message(tr("Saving file..."));
	
  PlivrusqtView* m = (PlivrusqtView*)pWorkspace->activeWindow();
  if( m )
  {
    PlivrusqtDoc* doc = m->getDocument();
    if(doc->title().contains(tr("Untitled")))
      slotFileSaveAs();
    else
      if(!doc->saveDocument(doc->pathName()))
        QMessageBox::critical (this, tr("I/O Error !"), tr("Could not save the current document !"));
  }

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotFileSaveAs()
{
  statusBar()->message(tr("Saving file under new filename..."));
  QString fn = QFileDialog::getSaveFileName(0, 0, this);
  if (!fn.isEmpty())
  {
    PlivrusqtView* m = (PlivrusqtView*)pWorkspace->activeWindow();
    if( m )
    {
      PlivrusqtDoc* doc = m->getDocument();
      if(!doc->saveDocument(fn))
      {
         QMessageBox::critical (this, tr("I/O Error !"), tr("Could not save the current document !"));
         return;
      }
      doc->changedViewList();
    }
  }
  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotFileClose()
{
  statusBar()->message(tr("Closing file..."));
	
  PlivrusqtView* m = (PlivrusqtView*)pWorkspace->activeWindow();
  if( m )
  {
    PlivrusqtDoc* doc=m->getDocument();
    doc->closeDocument();
  }

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotFilePrint()
{
  statusBar()->message(tr("Printing..."));
	
  PlivrusqtView* m = (PlivrusqtView*) pWorkspace->activeWindow();
  if ( m )
    m->print( printer );

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotFileQuit()
{ 
  statusBar()->message(tr("Exiting application..."));
  ///////////////////////////////////////////////////////////////////
  // exits the Application
//  if(doc->isModified())
//  {
//    if(queryExit())
//    {
//      qApp->quit();
//    }
//    else
//    {
//
//    };
//  }
//  else
//  {
    qApp->quit();
//  };

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotEditUndo()
{
  statusBar()->message(tr("Reverting last action..."));
	
  PlivrusqtView* m = (PlivrusqtView*) pWorkspace->activeWindow();
  if ( m )
//   m->undo();

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotEditCut()
{
  statusBar()->message(tr("Cutting selection..."));
	
  PlivrusqtView* m = (PlivrusqtView*) pWorkspace->activeWindow();
  if ( m )
//  m->cut();	

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotEditCopy()
{
  statusBar()->message(tr("Copying selection to clipboard..."));

  PlivrusqtView* m = (PlivrusqtView*) pWorkspace->activeWindow();
  if ( m )
//  m->copy();

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotEditPaste()
{
  statusBar()->message(tr("Inserting clipboard contents..."));
	
  PlivrusqtView* m = (PlivrusqtView*) pWorkspace->activeWindow();
  if ( m )
//   m->paste();

  statusBar()->message(tr("Ready."));
}


void PlivrusqtApp::slotViewToolBar(bool toggle)
{
  statusBar()->message(tr("Toggle toolbar..."));
  ///////////////////////////////////////////////////////////////////
  // turn Toolbar on or off
   if (toggle== false)
  {
    fileToolbar->hide();
  }
  else
  {
    fileToolbar->show();
  };

 statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotViewStatusBar(bool toggle)
{
  statusBar()->message(tr("Toggle statusbar..."));
  ///////////////////////////////////////////////////////////////////
  //turn Statusbar on or off
  
  if (toggle == false)
  {
    statusBar()->hide();
  }
  else
  {
    statusBar()->show();
  }

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotWindowNewWindow()
{
  statusBar()->message(tr("Opening new document view..."));
	
  PlivrusqtView* m = (PlivrusqtView*) pWorkspace->activeWindow();
  if ( m ){
    PlivrusqtDoc* doc = m->getDocument();
    createClient(doc);
  }

  statusBar()->message(tr("Ready."));
}

void PlivrusqtApp::slotHelpAbout()
{
  QMessageBox::about(this,tr("About..."),
                     tr("Plivrusqt\nVersion " VERSION
                     "\n(c) 2005 by Henrique F. de Souza"));
}

void PlivrusqtApp::slotStatusHelpMsg(const QString &text)
{
  ///////////////////////////////////////////////////////////////////
  // change status message of whole statusbar temporary (text, msec)
  statusBar()->message(text, 2000);
}

void PlivrusqtApp::windowMenuAboutToShow()
{
  pWindowMenu->clear();	
	windowNewWindow->addTo(pWindowMenu);
	windowCascade->addTo(pWindowMenu);
	windowTile->addTo(pWindowMenu);
	
  if ( pWorkspace->windowList().isEmpty() )
  {
    windowAction->setEnabled(false);
  }
  else
  {
    windowAction->setEnabled(true);
  }

  pWindowMenu->insertSeparator();

  QWidgetList windows = pWorkspace->windowList();
  for ( int i = 0; i < int(windows.count()); ++i )
  {
    int id = pWindowMenu->insertItem(QString("&%1 ").arg(i+1)+windows.at(i)->caption(), this, SLOT( windowMenuActivated( int ) ) );
    pWindowMenu->setItemParameter( id, i );
    pWindowMenu->setItemChecked( id, pWorkspace->activeWindow() == windows.at(i) );
  }
}

void PlivrusqtApp::windowMenuActivated( int id )
{
  QWidget* w = pWorkspace->windowList().at( id );
  if ( w )
    w->setFocus();
}

