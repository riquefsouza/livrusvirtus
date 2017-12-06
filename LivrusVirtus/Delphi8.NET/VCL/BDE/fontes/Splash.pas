unit Splash;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ExtCtrls, System.ComponentModel;

type
  TfrmSplash = class(TForm)
    Timer1: TTimer;
    Panel1: TPanel;
    Image1: TImage;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure Timer1Timer(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmSplash: TfrmSplash;

implementation

{$R *.DFM}

procedure TfrmSplash.FormClose(Sender: TObject; var Action: TCloseAction);
begin
//Action:=caFree;
end;

procedure TfrmSplash.Timer1Timer(Sender: TObject);
begin
Close;
end;

end.
