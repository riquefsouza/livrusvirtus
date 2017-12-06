//---------------------------------------------------------------------------

#ifndef ConIdiomasH
#define ConIdiomasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include "Consultas.h"
#include <Db.hpp>
#include <QDBGrids.hpp>
#include <DBTables.hpp>
#include <QExtCtrls.hpp>
#include <QGrids.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <FMTBcd.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
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
