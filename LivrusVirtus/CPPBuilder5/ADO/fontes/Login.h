//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ADODB.hpp>
//---------------------------------------------------------------------------
class TfrmLogin : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *edtLogin;
        TButton *BtnLogin;
        TButton *btnCancelar;
        TEdit *edtSenha;
        TImage *Image1;
        TADOQuery *Consulta;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BtnLoginClick(TObject *Sender);
        void __fastcall btnCancelarClick(TObject *Sender);
private:	// User declarations
        Boolean bFecharOuTerminar;
public:		// User declarations
        __fastcall TfrmLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
#endif
