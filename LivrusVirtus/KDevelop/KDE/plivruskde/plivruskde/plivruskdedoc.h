
#ifndef PLIVRUSKDEDOC_H
#define PLIVRUSKDEDOC_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// include files for QT
#include <qobject.h>
#include <qstring.h>
#include <qlist.h>

// include files for KDE
#include <kurl.h>

// forward declaration of the Plivruskde classes
class PlivruskdeView;

/**	PlivruskdeDoc provides a document object for a document-view model.
  *
  * The PlivruskdeDoc class provides a document object that can be used in conjunction with the classes
  * PlivruskdeApp and PlivruskdeView to create a document-view model for MDI (Multiple Document Interface)
  * KDE 2 applications based on KApplication and KTMainWindow as main classes and QWorkspace as MDI manager widget.
  * Thereby, the document object is created by the PlivruskdeApp instance (and kept in a document list) and contains
  * the document structure with the according methods for manipulating the document
  * data by PlivruskdeView objects. Also, PlivruskdeDoc contains the methods for serialization of the document data
  * from and to files.
  * @author Source Framework Automatically Generated by KDevelop, (c) The KDevelop Team.
  * @version KDevelop version 1.3 code generation
  */
class PlivruskdeDoc : public QObject
{
  Q_OBJECT

  friend struct PlivruskdeView;

  public:
    /** Constructor for the fileclass of the application */
    PlivruskdeDoc();
    /** Destructor for the fileclass of the application */
    ~PlivruskdeDoc();

    /** adds a view to the document which represents the document contents. Usually this is your main view. */
    void addView(PlivruskdeView *view);
    /** removes a view from the list of currently connected views */
    void removeView(PlivruskdeView *view);
		/** gets called if a view is removed or added */
		void changedViewList();
    /** returns the first view instance */
		PlivruskdeView* firstView(){ return pViewList->first(); };
		/** returns true, if the requested view is the last view of the document */
    bool isLastView();
    /** This method gets called when the user is about to close a frame window. It checks, if more than one view
    	* is connected to the document (then the frame can be closed), if pFrame is the last view and the document is
    	* modified, the user gets asked if he wants to save the document.
    	*/
		bool canCloseFrame(PlivruskdeView* pFrame);
    /** sets the modified flag for the document after a modifying action on the view connected to the document.*/
    void setModified(bool _m=true){ modified=_m; };
    /** returns if the document is modified or not. Use this to determine if your document needs saving by the user on closing.*/
    bool isModified(){ return modified; };
    /** deletes the document's contents */
    void deleteContents();
    /** initializes the document generally */
    bool newDocument();
    /** closes the acutal document */
    void closeDocument();
    /** loads the document by filename and format and emits the updateViews() signal */
    bool openDocument(const KURL &url, const char *format=0);
    /** saves the document under filename and format.*/
    bool saveDocument(const KURL &url, const char *format=0);
    /** returns the KURL of the document */
    const KURL& URL() const;
    /** sets the URL of the document */
	  void setURL(const KURL& url);

  public slots:
    /** calls repaint() on all views connected to the document object and is called by the view by which the document has been changed.
     * As this view normally repaints itself, it is excluded from the paintEvent.
     */
    void updateAllViews(PlivruskdeView *sender);

  private:
    /** the modified flag of the current document */
    bool modified;
    KURL doc_url;
    /** the list of the views currently connected to the document */
    QList<PlivruskdeView> *pViewList;

};

#endif // PLIVRUSKDEDOC_H
