unit LivrusApp;

interface

uses
  System.Drawing, wx;

type
  TLivrusApp = class(wx.App)
  public
    constructor Create;
    Function OnInit(): Boolean; override;
  end;

implementation

uses Principal, Splash, Resource, RotinasGlobais, ConsultasSQL;

constructor TLivrusApp.Create;
begin
  inherited Create;
end;

Function TLivrusApp.OnInit(): Boolean;
var bret: boolean;
begin
  Res := TResource.create;
  Rotinas := TRotinasGlobais.create;
  ConsSQL := TConsultasSQL.create;
  frmPrincipal := TfrmPrincipal.Create();

  if not Rotinas.ConectaBanco(
    'File Name=C:\LivrusVirtus\bancos\access\Access2k_Livrus.udl') then
    bret := false
  else begin
    bret := true;
    frmSplash := TfrmSplash.create(nil);
    frmSplash.show(true);
  end;
  result := bret;
end;

end.
