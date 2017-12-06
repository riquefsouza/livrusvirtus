//---------------------------------------------------------------------------

#ifndef CadClientesH
#define CadClientesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Cadastros.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TfrmCadClientes : public TfrmCadastros
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TLabel *Label7;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *edtCodPais;
        TEdit *edtPais;
        TButton *btnPPais;
        TEdit *edtCodProfissao;
        TEdit *edtProfissao;
        TButton *btnPProfissao;
        TEdit *edtEmail;
        TEdit *edtTelefone;
        TRadioGroup *rdgSexo;
        TDateTimePicker *edtDtNascimento;
        TGroupBox *grpEndereco;
        TLabel *Label5;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TEdit *edtCodEndereco;
        TEdit *edtLogradouro;
        TButton *btnPEndereco;
        TEdit *edtCidade;
        TEdit *edtCEP;
        TEdit *edtBairro;
        TEdit *edtEstado;
        TEdit *edtIdentidade;
        void __fastcall btnExcluirClick(TObject *Sender);
        void __fastcall btnPesquisarClick(TObject *Sender);
        void __fastcall btnSalvarClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall edtCodPaisExit(TObject *Sender);
        void __fastcall edtCodProfissaoExit(TObject *Sender);
        void __fastcall edtCodEnderecoExit(TObject *Sender);
        void __fastcall edtCodigoExit(TObject *Sender);
        void __fastcall btnPEnderecoClick(TObject *Sender);
        void __fastcall btnPPaisClick(TObject *Sender);
        void __fastcall btnPProfissaoClick(TObject *Sender);
private:	// User declarations
        void InformaLimpaDados(Boolean bInformar);
        void HabilitaDados(Boolean bHabilita);
protected:	// User declarations
        Boolean ValidaDados(Boolean bTodosDados);
public:		// User declarations
        __fastcall TfrmCadClientes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadClientes *frmCadClientes;
//---------------------------------------------------------------------------
#endif
