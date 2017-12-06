//---------------------------------------------------------------------------

#ifndef CadEnderecosH
#define CadEnderecosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Cadastros.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include <ADODB.hpp>
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
        Boolean ValidaDados(Boolean bTodosDados);
        void InformaLimpaDados(Boolean bInformar);
        void HabilitaDados(Boolean bHabilita);
public:		// User declarations
        __fastcall TfrmCadEnderecos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadEnderecos *frmCadEnderecos;
//---------------------------------------------------------------------------
#endif
