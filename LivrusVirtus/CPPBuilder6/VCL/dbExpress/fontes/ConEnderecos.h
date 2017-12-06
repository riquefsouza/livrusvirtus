//---------------------------------------------------------------------------

#ifndef ConEnderecosH
#define ConEnderecosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Consultas.h"
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TfrmConEnderecos : public TfrmConsultas
{
__published:	// IDE-managed Components
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnLimparClick(TObject *Sender);
        void __fastcall btnPesquisarClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmConEnderecos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConEnderecos *frmConEnderecos;
//---------------------------------------------------------------------------
#endif
