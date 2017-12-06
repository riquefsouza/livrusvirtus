//---------------------------------------------------------------------------

#ifndef ConsultasH
#define ConsultasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TfrmConsultas : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label2;
        TEdit *edtDescricao;
        TButton *btnPesquisar;
        TPanel *Panel2;
        TButton *btnFechar;
        TButton *btnLimpar;
        TDBGrid *gridConsulta;
        TDataSource *DSConsulta;
        TLabel *labRegistros;
        TADOQuery *Consulta;
        void __fastcall btnFecharClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ConsultaAfterScroll(TDataSet *DataSet);
        void __fastcall gridConsultaMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
private:	// User declarations
protected:	// User declarations
        void LimparDados(AnsiString sTextoSql);
        Boolean PesquisarDados(AnsiString sTextoSql,AnsiString sMensagemErro);
public:		// User declarations
        __fastcall TfrmConsultas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConsultas *frmConsultas;
//---------------------------------------------------------------------------
#endif
