//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <QExtCtrls.hpp>
#include <QGraphics.hpp>
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
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
        TSQLQuery *Consulta;
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
