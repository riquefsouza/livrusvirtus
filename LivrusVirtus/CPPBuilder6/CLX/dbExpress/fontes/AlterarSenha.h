//---------------------------------------------------------------------------

#ifndef AlterarSenhaH
#define AlterarSenhaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TfrmAlterarSenha : public TForm
{
__published:	// IDE-managed Components
        TButton *btnSalvar;
        TButton *btnLimpar;
        TButton *btnFechar;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *edtLogin;
        TEdit *edtNovaSenha;
        TEdit *edtConfirmarSenha;
        TEdit *edtSenhaAtual;
        TSQLQuery *Arquiva;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnFecharClick(TObject *Sender);
        void __fastcall btnLimparClick(TObject *Sender);
        void __fastcall btnSalvarClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations
        Boolean ValidaDados();
public:		// User declarations
        __fastcall TfrmAlterarSenha(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAlterarSenha *frmAlterarSenha;
//---------------------------------------------------------------------------
#endif
