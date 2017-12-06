//---------------------------------------------------------------------------

#ifndef ConIdiomasH
#define ConIdiomasH
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
//---------------------------------------------------------------------------
class TfrmConIdiomas : public TfrmConsultas
{
__published:	// IDE-managed Components
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btnPesquisarClick(TObject *Sender);
        void __fastcall btnLimparClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmConIdiomas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConIdiomas *frmConIdiomas;
//---------------------------------------------------------------------------
#endif
