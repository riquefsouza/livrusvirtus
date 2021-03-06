
#ifndef PLIVRUSQTVIEW_H
#define PLIVRUSQTVIEW_H

// include files for Qt
#include <qwidget.h>

class PlivrusqtDoc;

/**
 * This class provides an incomplete base for your application view.
 *
 * @author Source Framework Automatically Generated by KDevelop, (c) The KDevelop Team.
 * @version KDevelop version 1.1 code generation
 */
class PlivrusqtView : public QWidget
{
  Q_OBJECT

  friend struct PlivrusqtDoc;

  public:
    /** Constructor for the view
    	* @param pDoc  your document instance that the view represents. Create a document before calling the constructor
    	* or connect an already existing document to a new MDI child widget.*/
    PlivrusqtView(PlivrusqtDoc* pDoc, QWidget* parent, const char *name, int wflags);
    /** Destructor for the main view */
    ~PlivrusqtView();
		/** returns a pointer to the document connected to the view*/
    PlivrusqtDoc *getDocument() const;
    /** gets called to redraw the document contents if it has been modified */
		void update(PlivrusqtView* pSender);
    /** contains the implementation for printing functionality and gets called by PlivrusqtApp::slotFilePrint() */
    void print(QPrinter *pPrinter);

  protected:
	  virtual void closeEvent(QCloseEvent*);

	  PlivrusqtDoc *doc;

  private:

};

#endif
