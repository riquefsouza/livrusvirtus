//---------------------------------------------------------------------------

#ifndef CadIdiomasH
#define CadIdiomasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Cadastros.h"
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TfrmCadIdiomas : public TfrmCadastros
{
__published:	// IDE-managed Components
        void __fastcall btnNovoClick(TObject *Sender);
        void __fastcall btnExcluirClick(TObject *Sender);
        void __fastcall btnPesquisarClick(TObject *Sender);
        void __fastcall btnSalvarClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
protected:	// User declarations
        Boolean ValidaDados(Boolean bTodosDados);
public:		// User declarations
        __fastcall TfrmCadIdiomas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadIdiomas *frmCadIdiomas;
//---------------------------------------------------------------------------
#endif
