//---------------------------------------------------------------------------

#ifndef CadIdiomasH
#define CadIdiomasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include "Cadastros.h"
//#include <Db.hpp>
//#include <DBTables.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
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
