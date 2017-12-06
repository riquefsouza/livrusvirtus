
// include files for Qt
#include <qprinter.h>
#include <qpainter.h>
#include <qdir.h>
// include files for KDE

// application specific includes
#include "plivruskde.h"
#include "plivruskdeview.h"
#include "plivruskdeview.moc"
#include "plivruskdedoc.h"

PlivruskdeView::PlivruskdeView(PlivruskdeDoc* pDoc, QWidget *parent, const char* name, int wflags)
 : QWidget(parent, name, wflags)
{
    doc=pDoc;
}

PlivruskdeView::~PlivruskdeView()
{
}

PlivruskdeDoc *PlivruskdeView::getDocument() const
{
	return doc;
}

void PlivruskdeView::update(PlivruskdeView* pSender){
	if(pSender != this)
		repaint();
}

void PlivruskdeView::print(QPrinter *pPrinter)
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

void PlivruskdeView::closeEvent(QCloseEvent* e){

// DO NOT CALL QWidget::closeEvent(e) here !!
// This will accept the closing by QCloseEvent::accept() by default.
// The installed eventFilter() in PlivruskdeApp takes care for closing the widget
// or ignoring the close event

}
