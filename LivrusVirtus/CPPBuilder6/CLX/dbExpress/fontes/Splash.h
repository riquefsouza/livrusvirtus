//---------------------------------------------------------------------------

#ifndef SplashH
#define SplashH
//---------------------------------------------------------------------------
#include <QControls.hpp>
#include <QExtCtrls.hpp>
#include <Classes.hpp>
#include <QStdCtrls.hpp>
#include <QGraphics.hpp>
#include <QTypes.hpp>
//---------------------------------------------------------------------------
class TfrmSplash : public Qforms::TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TPanel *Panel1;
        TImage *Image1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmSplash(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
#endif
