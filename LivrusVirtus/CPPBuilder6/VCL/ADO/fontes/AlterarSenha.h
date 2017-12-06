//---------------------------------------------------------------------------

#ifndef AlterarSenhaH
#define AlterarSenhaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ADODB.hpp>
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
        TADOQuery *Arquiva;
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
