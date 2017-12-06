unit Sobre;

interface

uses SysUtils, WinTypes, WinProcs, Messages, Classes, Graphics, Controls,
  Forms, Dialogs, StdCtrls, ExtCtrls;

type
  TfrmSobre = class(TForm)
    Panel1: TPanel;
    ProgramIcon: TImage;
    Version: TLabel;
    Copyright: TLabel;
    Comments: TLabel;
    OKButton: TButton;
    procedure FormActivate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmSobre: TfrmSobre;

implementation

uses Principa;

{$R *.DFM}

procedure TfrmSobre.FormActivate(Sender: TObject);
begin
{ frmPrincipal.StatusBar1.Panels.Items[1].Text:=Caption;}
end;

end.
 
