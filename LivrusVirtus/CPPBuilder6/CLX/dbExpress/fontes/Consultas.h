//---------------------------------------------------------------------------

#ifndef ConsultasH
#define ConsultasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QForms.hpp>
#include <Db.hpp>
#include <QDBGrids.hpp>
#include <DBTables.hpp>
#include <QExtCtrls.hpp>
#include <QGrids.hpp>
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
#include <DBClient.hpp>
#include <Provider.hpp>
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
        TSQLQuery *Consulta;
        TClientDataSet *CDSConsulta;
        TDataSetProvider *DSPConsulta;
        void __fastcall btnFecharClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall gridConsultaMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall CDSConsultaAfterScroll(TDataSet *DataSet);
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
