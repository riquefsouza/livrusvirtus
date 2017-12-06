unit Splash;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, System.Resources;

type
  frmSplash = class(System.Windows.Forms.Form)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    components: System.ComponentModel.IContainer;
    Timer1: System.Windows.Forms.Timer;
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure Timer1_Tick(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
  private
    { Private Declarations }
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmSplash))]

var fSplash: frmSplash;

implementation

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmSplash.InitializeComponent;
var
  resources: System.Resources.ResourceManager;
begin
  Self.components := System.ComponentModel.Container.Create;
  resources := System.Resources.ResourceManager.Create(TypeOf(frmSplash));
  Self.Timer1 := System.Windows.Forms.Timer.Create(Self.components);
  // 
  // Timer1
  // 
  Self.Timer1.Enabled := True;
  Self.Timer1.Interval := 3000;
  Include(Self.Timer1.Tick, Self.Timer1_Tick);
  // 
  // frmSplash
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.BackgroundImage := (System.Drawing.Image(resources.GetObject('$this.BackgroundImage')));
  Self.ClientSize := System.Drawing.Size.Create(256, 72);
  Self.FormBorderStyle := System.Windows.Forms.FormBorderStyle.None;
  Self.Name := 'frmSplash';
  Self.StartPosition := System.Windows.Forms.FormStartPosition.CenterScreen;
  Self.Text := 'Splash';
  Self.TransparencyKey := System.Drawing.Color.White;
end;
{$ENDREGION}

procedure frmSplash.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmSplash.Create;
begin
  inherited Create;
  //
  // Required for Windows Form Designer support
  //
  InitializeComponent;
  //
  // TODO: Add any constructor code after InitializeComponent call
  //
end;

procedure frmSplash.Timer1_Tick(sender: System.Object; e: System.EventArgs);
begin
  Close;
end;

end.
