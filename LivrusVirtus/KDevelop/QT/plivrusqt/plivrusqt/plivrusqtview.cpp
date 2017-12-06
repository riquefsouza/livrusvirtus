
// include files for Qt
#include <qprinter.h>
#include <qpainter.h>

// application specific includes
#include "plivrusqtview.h"
#include "plivrusqtdoc.h"


PlivrusqtView::PlivrusqtView(PlivrusqtDoc* pDoc, QWidget *parent, const char* name, int wflags)
 : QWidget(parent, name, wflags)
{
    doc=pDoc;
}

PlivrusqtView::~PlivrusqtView()
{
}

PlivrusqtDoc *PlivrusqtView::getDocument() const
{
	return doc;
}

void PlivrusqtView::update(PlivrusqtView* pSender){
	if(pSender != this)
		repaint();
}

void PlivrusqtView::print(QPrinter *pPrinter)
{
  if (pPrinter->setup(this))
  {
		QPainter p;
		p.begin(pPrinter);
		
		///////////////////////////////
		// TODO: add your printing code here
		///////////////////////////////
		
		p.end();
  }
}

void PlivrusqtView::closeEvent(QCloseEvent*)
{
  // LEAVE THIS EMPTY: THE EVENT FILTER IN THE PlivrusqtApp CLASS TAKES CARE FOR CLOSING
  // QWidget closeEvent must be prevented.
}

