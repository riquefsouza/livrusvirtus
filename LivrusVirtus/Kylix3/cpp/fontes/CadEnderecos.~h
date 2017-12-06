//---------------------------------------------------------------------------

#ifndef CadEnderecosH
#define CadEnderecosH
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
class TfrmCadEnderecos : public TfrmCadastros
{
__published:	// IDE-managed Components
        TLabel *Label11;
        TLabel *Label10;
        TLabel *Label13;
        TEdit *edtCEP;
        TEdit *edtCidade;
        TComboBox *cmbEstado;
        TEdit *edtBairro;
        TLabel *Label12;
        void __fastcall btnNovoClick(TObject *Sender);
        void __fastcall btnExcluirClick(TObject *Sender);
        void __fastcall btnPesquisarClick(TObject *Sender);
        void __fastcall btnSalvarClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        void AdicionaCombo();
        void RecuperaEstado(AnsiString sEstado);
protected:	// User declarations
        void InformaLimpaDados(Boolean bInformar);
        void HabilitaDados(Boolean bHabilita);
        Boolean ValidaDados(Boolean bTodosDados);
public:		// User declarations
        __fastcall TfrmCadEnderecos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadEnderecos *frmCadEnderecos;
//---------------------------------------------------------------------------
#endif
