//---------------------------------------------------------------------------

#ifndef VenderLivrosH
#define VenderLivrosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
//---------------------------------------------------------------------------
class TfrmVenderLivros : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edtCPF;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label9;
        TEdit *edtCliente;        
        TEdit *edtISBN;
        TButton *btnPLivro;
        TButton *btnPCliente;
        TEdit *edtDtVenda;
        TListBox *lstLivros;
        TLabel *Label5;
        TEdit *edtPrecoTotal;
        TButton *btnVender;
        TButton *btnLimpar;
        TButton *btnFechar;
        TEdit *edtLivro;
        TLabel *Label4;
        TLabel *Label6;
        TButton *btnAdLivros;
        TSQLQuery *Consulta;
        TSQLQuery *Arquiva;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnFecharClick(TObject *Sender);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall edtISBNExit(TObject *Sender);
        void __fastcall edtCPFExit(TObject *Sender);
        void __fastcall btnPClienteClick(TObject *Sender);
        void __fastcall btnPLivroClick(TObject *Sender);
        void __fastcall btnAdLivrosClick(TObject *Sender);
        void __fastcall lstLivrosDblClick(TObject *Sender);
        void __fastcall btnLimparClick(TObject *Sender);
        void __fastcall btnVenderClick(TObject *Sender);
private:	// User declarations
        float nPrecoTotal;
        TStringList *slLivros, *slPrecos, *slQtdEstoque;
        void LimpaDados();
        Boolean ValidaDados();
        Boolean SalvaLista();
public:		// User declarations
        __fastcall TfrmVenderLivros(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmVenderLivros *frmVenderLivros;
//---------------------------------------------------------------------------
#endif
