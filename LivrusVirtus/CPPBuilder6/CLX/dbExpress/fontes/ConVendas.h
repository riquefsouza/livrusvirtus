//---------------------------------------------------------------------------

#ifndef ConVendasH
#define ConVendasH
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
#include <QComCtrls.hpp>
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
#include <DBClient.hpp>
#include <Provider.hpp>
#include <QMask.hpp>
//---------------------------------------------------------------------------
class TfrmConVendas : public TfrmConsultas
{
__published:	// IDE-managed Components
        TLabel *Label5;
        TEdit *edtPrecoTotal;
        TLabel *Label9;
        TMaskEdit *edtDtVenda;
        TMaskEdit *edtHrVenda;
        TLabel *Label1;
        TEdit *edtCliente;
        TButton *btnPCliente;
        TButton *btnPLivro;
        TEdit *edtLivro;
        TLabel *Label6;
        TEdit *edtISBN;
        TLabel *Label3;
        TSQLQuery *ConsTotal;
        TSQLQuery *ConsCampo;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnLimparClick(TObject *Sender);
        void __fastcall btnPesquisarClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall edtDescricaoExit(TObject *Sender);
        void __fastcall edtISBNExit(TObject *Sender);
        void __fastcall btnPClienteClick(TObject *Sender);
        void __fastcall btnPLivroClick(TObject *Sender);
        void __fastcall edtDtVendaExit(TObject *Sender);
        void __fastcall edtHrVendaExit(TObject *Sender);
private:	// User declarations
        AnsiString ConsVenda(char sOpcao);
public:		// User declarations
        __fastcall TfrmConVendas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConVendas *frmConVendas;
//---------------------------------------------------------------------------
#endif
