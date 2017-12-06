//---------------------------------------------------------------------------

#ifndef CadastrosH
#define CadastrosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
#include <DBClient.hpp>
#include <Provider.hpp>
//---------------------------------------------------------------------------
class TfrmCadastros : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TButton *btnSalvar;
        TButton *btnExcluir;
        TButton *btnLimpar;
        TButton *btnFechar;
        TButton *btnPesquisar;
        TButton *btnAnterior;
        TButton *btnProximo;
        TButton *btnNovo;
        TEdit *edtCodigo;
        TEdit *edtDescricao;
        TSQLQuery *Consulta;
        TSQLQuery *Arquiva;
        TClientDataSet *CDSConsulta;
        TDataSetProvider *DSPConsulta;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnFecharClick(TObject *Sender);
        void __fastcall btnNovoClick(TObject *Sender);
        void __fastcall btnLimparClick(TObject *Sender);
        void __fastcall btnAnteriorClick(TObject *Sender);
        void __fastcall btnProximoClick(TObject *Sender);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall edtCodigoExit(TObject *Sender);
private:	// User declarations
protected:	// User declarations
        void NovoDado(AnsiString sTextoSql);
        virtual void InformaLimpaDados(Boolean bInformar); 
        virtual void HabilitaDados(Boolean bHabilita);
        virtual Boolean ValidaDados(Boolean bTodosDados);
        void ExcluirDados(AnsiString sTextoSql);
        void PesquisarDados(AnsiString sTextoSql,AnsiString sMensagemErro);
        void SalvarDados(AnsiString sTextoSql, AnsiString sTextoUpdate,
             AnsiString sTextoInsert, Boolean bLimparDados);
public:		// User declarations
        __fastcall TfrmCadastros(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadastros *frmCadastros;
//---------------------------------------------------------------------------
#endif
