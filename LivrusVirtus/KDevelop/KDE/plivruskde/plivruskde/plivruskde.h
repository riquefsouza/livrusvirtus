
#ifndef PLIVRUSKDE_H
#define PLIVRUSKDE_H
 

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// include files for Qt
#include <qstrlist.h>
#include <qworkspace.h>

// include files for KDE
#include <kapp.h>
#include <kmainwindow.h>
#include <kaction.h>
#include <kurl.h>

// forward declaration of the Plivruskde classes
class PlivruskdeDoc;
class PlivruskdeView;

/**
  * The base class for Plivruskde application windows. It sets up the main
  * window and reads the config file as well as providing a menubar, toolbar
  * and statusbar. In initView(), your main view is created as the MDI child window manager.
  * Child windows are created in createClient(), which gets a document instance as it's document to
  * display whereby one document can have several views.The MDI child is an instance of PlivruskdeView,
  * the document an instance of PlivruskdeDoc.
  * PlivruskdeApp reimplements the methods that KTMainWindow provides for main window handling and supports
  * full session management as well as keyboard accelerator configuration by using KAccel.
  * @see KMainWindow
  * @see KApplication
  * @see KConfig
  * @see KAccel
  *
  * @author Source Framework Automatically Generated by KDevelop, (c) The KDevelop Team.
  * @version KDevelop version 1.3 code generation
  */
class PlivruskdeApp : public KMainWindow
{
  Q_OBJECT

  public:
    /** construtor of PlivruskdeApp, calls all init functions to create the application.
     * @see initMenuBar initToolBar
     */
    PlivruskdeApp();
    ~PlivruskdeApp();
    /** opens a file specified by commandline option
     */
    void openDocumentFile(const KURL& url=0);

  protected:
    /** queryClose is called by KTMainWindow on each closeEvent of a window. Against the
     * default implementation (only returns true), this overridden function retrieves all modified documents
     * from the open document list and asks the user to select which files to save before exiting the application.
     * @see KTMainWindow#queryClose
     * @see KTMainWindow#closeEvent
     */
    virtual bool queryClose();
    /** queryExit is called by KTMainWindow when the last window of the application is going to be closed during the closeEvent().
     * Against the default implementation that just returns true, this calls saveOptions() to save the settings of the last window's	
     * properties.
     * @see KTMainWindow#queryExit
     * @see KTMainWindow#closeEvent
     */
    virtual bool queryExit();
    /** saves the window properties for each open window during session end to the session config file, including saving the currently
     * opened file by a temporary filename provided by KApplication.
     * @see KTMainWindow#saveProperties
     */
    virtual void saveProperties(KConfig *_cfg);
    /** reads the session config file and restores the application's state including the last opened files and documents by reading the
     * temporary files saved by saveProperties()
     * @see KTMainWindow#readProperties
     */
    virtual void readProperties(KConfig *_cfg);
    /** event filter to catch close events for MDI child windows and is installed in createClient() on every child window.
     * Closing a window calls the eventFilter first which removes the view from the connected documents' view list. If the
     * last view is going to be closed, the eventFilter() tests if the document is modified; if yes, it asks the user to
     * save the document. If the document title contains "Untitled", slotFileSaveAs() gets called to get a save name and path.
     */
    virtual bool eventFilter(QObject* object, QEvent* event);
    /** creates a new child window. The document that will be connected to it
     * has to be created before and the instances filled, with e.g. openDocument().
     * Then call createClient() to get a new MDI child window.
     * @see PlivruskdeDoc#addView
     * @see PlivruskdeDoc#openDocument
     * @param doc pointer to the document instance that the view will
     * be connected to.
     */
		void createClient(PlivruskdeDoc* doc);

  private slots:
    /** clears the document in the actual view to reuse it as the new document */
    void slotFileNew();
    /** open a file and load it into the document*/
    void slotFileOpen();
    /** opens a file from the recent files menu */
    void slotFileOpenRecent(const KURL& url);
    /** save a document */
    void slotFileSave();
    /** save a document by a new filename*/
    void slotFileSaveAs();
    /** asks for saving if the file is modified, then closes the actual file and window*/
    void slotFileClose();
    /** print the actual file */
    void slotFilePrint();
		/** closes all documents and quits the application.*/
    void slotFileQuit();
		/** reverts the last user action for the active window */
    void slotEditUndo();
    /** put the marked text/object into the clipboard and remove
     *	it from the document
     */
    void slotEditCut();
    /** put the marked text/object into the clipboard
     */
    void slotEditCopy();
    /** paste the clipboard into the document
     */
    void slotEditPaste();
    /** toggles the toolbar
     */
    void slotViewToolBar();
    /** toggles the statusbar
     */
    void slotViewStatusBar();
    /** creates a new view for the document in the active child window and adds the new view to the
     * list of views the document maintains.
     */
    void slotWindowNewWindow();
    /** changes the statusbar contents for the standard label permanently, used to indicate current actions.
     * @param text the text that is displayed in the statusbar
     */
    void slotStatusMsg(const QString &text);
  	/** gets called when the window menu is activated; recreates the window menu with all opened window titles. */
    void windowMenuAboutToShow();
    /** activates the MDI child widget when it gets selected from the window menu. */
    void windowMenuActivated( int id );
  /**  */
  void slotWindowTile();
  /**  */
  void slotWindowCascade();

  private:
    /** save general Options like all bar positions and status as well as the geometry and the recent file list to the configuration
     * file
     */ 	
    void saveOptions();
    /** read general Options again and initialize all variables like the recent file list
     */
    void readOptions();
    /** initializes the KActions of the application */
    void initActions();

    /** sets up the statusbar for the main window by initialzing a statuslabel.
     */
    void initStatusBar();

    /** Creates the main view of the KTMainWindow instance and initializes the MDI view area including any needed
    	* connections.
     */
    void initView();

    /** the configuration object of the application */
    KConfig *config;
    /** pWorkspace is the MDI frame widget that handles MDI child widgets. Inititalized in
     * initView()
     */
    QWorkspace *pWorkspace;
    /** the printer instance */
    QPrinter *printer;
    /** a counter that gets increased each time the user creates a new document with "File"->"New" */
    int untitledCount;
    /** a list of all open documents. If the last window of a document gets closed, the installed eventFilter
     * removes this document from the list. The document list is checked for modified documents when the user
     * is about to close the application. */
    QList<PlivruskdeDoc> *pDocList;	

    // KAction pointers to enable/disable actions
    KAction* fileNew;
    KAction* fileOpen;
    KRecentFilesAction* fileOpenRecent;
    KAction* fileSave;
    KAction* fileSaveAs;
    KAction* fileClose;
    KAction* filePrint;
    KAction* fileQuit;
    KAction* editCut;
    KAction* editCopy;
    KAction* editPaste;
    KAction* windowNewWindow;
    KAction* windowTile;
    KAction* windowCascade;

    KToggleAction* viewToolBar;
    KToggleAction* viewStatusBar;
    KActionMenu* windowMenu;
};
 
#endif // PLIVRUSKDE_H
