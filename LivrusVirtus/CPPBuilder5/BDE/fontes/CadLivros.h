//---------------------------------------------------------------------------

#ifndef CadLivrosH
#define CadLivrosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Cadastros.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TfrmCadLivros : public TfrmCadastros
{
__published:	// IDE-managed Components
        TQuery *ConsLista;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TEdit *edtEditora;
        TButton *btnPEditora;
        TEdit *edtCodEditora;
        TEdit *edtPreco;
        TEdit *edtCodAssunto;
        TEdit *edtAssunto;
        TButton *btnPAssunto;
        TListBox *lstAssuntos;
        TEdit *edtCodAutor;
        TEdit *edtAutor;
        TButton *btnPAutor;
        TListBox *lstAutores;
        TButton *btnAdAssuntos;
        TButton *btnAdAutores;
        TComboBox *cmbIdioma;
        TLabel *Label5;
        TLabel *Label4;
        TLabel *Label3;
        TCSpinEdit *edtEdicao;
        TCSpinEdit *edtAnoPubli;
        TCSpinEdit *edtVolume;
        TCSpinEdit *edtNPaginas;
        TCSpinEdit *edtQtdEstoque;
        void __fastcall btnExcluirClick(TObject *Sender);
        void __fastcall btnPesquisarClick(TObject *Sender);
        void __fastcall btnSalvarClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall edtCodEditoraExit(TObject *Sender);
        void __fastcall edtCodAssuntoExit(TObject *Sender);
        void __fastcall edtCodAutorExit(TObject *Sender);
        void __fastcall btnPAssuntoClick(TObject *Sender);
        void __fastcall btnAdAssuntosClick(TObject *Sender);
        void __fastcall lstAssuntosDblClick(TObject *Sender);
        void __fastcall lstAutoresDblClick(TObject *Sender);
        void __fastcall edtPrecoExit(TObject *Sender);
        void __fastcall edtCodigoExit(TObject *Sender);
        void __fastcall btnPAutorClick(TObject *Sender);
        void __fastcall btnAdAutoresClick(TObject *Sender);
private:	// User declarations
        TStringList *slAssuntos, *slAutores, *slIdiomas;
        void AdicionaCombo();
        void SalvaLista(char sOpcao);
protected:	// User declarations
        void InformaLimpaDados(Boolean bInformar);
        void HabilitaDados(Boolean bHabilita);
        Boolean ValidaDados(Boolean bTodosDados);
public:		// User declarations
        __fastcall TfrmCadLivros(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCadLivros *frmCadLivros;
//---------------------------------------------------------------------------
#endif
