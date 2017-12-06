//---------------------------------------------------------------------------

#ifndef SobreH
#define SobreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmSobre : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *ProgramIcon;
        TLabel *Version;
        TLabel *Comments;
        TLabel *Copyright;
        TButton *OKButton;
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmSobre(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSobre *frmSobre;
//---------------------------------------------------------------------------
#endif
