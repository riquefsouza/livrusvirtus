unit Sobre;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, System.Resources;

type
  frmSobre = class(System.Windows.Forms.Form)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
	  groupBox1: System.Windows.Forms.GroupBox;
		btnOk: System.Windows.Forms.Button;
		pictureBox1: System.Windows.Forms.PictureBox;
		label1: System.Windows.Forms.Label;
		label2: System.Windows.Forms.Label;
		label3: System.Windows.Forms.Label;

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure frmSobre_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
    procedure frmSobre_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
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

  [assembly: RuntimeRequiredAttribute(TypeOf(frmSobre))]

var fSobre: frmSobre;

implementation

uses Principal;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmSobre.InitializeComponent;
var
  resources: System.Resources.ResourceManager;
begin
  resources := System.Resources.ResourceManager.Create(TypeOf(frmSobre));
  Self.groupBox1 := System.Windows.Forms.GroupBox.Create;
  Self.label3 := System.Windows.Forms.Label.Create;
  Self.label2 := System.Windows.Forms.Label.Create;
  Self.label1 := System.Windows.Forms.Label.Create;
  Self.pictureBox1 := System.Windows.Forms.PictureBox.Create;
  Self.btnOk := System.Windows.Forms.Button.Create;
  Self.groupBox1.SuspendLayout;
  Self.SuspendLayout;
  // 
  // groupBox1
  // 
  Self.groupBox1.BackColor := System.Drawing.Color.Transparent;
  Self.groupBox1.Controls.Add(Self.label3);
  Self.groupBox1.Controls.Add(Self.label2);
  Self.groupBox1.Controls.Add(Self.label1);
  Self.groupBox1.Controls.Add(Self.pictureBox1);
  Self.groupBox1.Location := System.Drawing.Point.Create(8, 8);
  Self.groupBox1.Name := 'groupBox1';
  Self.groupBox1.Size := System.Drawing.Size.Create(312, 176);
  Self.groupBox1.TabIndex := 0;
  Self.groupBox1.TabStop := False;
  // 
  // label3
  // 
  Self.label3.Location := System.Drawing.Point.Create(24, 128);
  Self.label3.Name := 'label3';
  Self.label3.Size := System.Drawing.Size.Create(256, 40);
  Self.label3.TabIndex := 3;
  Self.label3.Text := 'Sistema integrante do projeto Livrus Virtus, versão programada no Borland Delph'+ 
  'i 8.0 for the Microsoft .NET Framework.';
  Self.label3.TextAlign := System.Drawing.ContentAlignment.MiddleCenter;
  // 
  // label2
  // 
  Self.label2.Location := System.Drawing.Point.Create(8, 112);
  Self.label2.Name := 'label2';
  Self.label2.Size := System.Drawing.Size.Create(296, 16);
  Self.label2.TabIndex := 2;
  Self.label2.Text := 'Todos os direitos reservados para: Henrique F. de Souza';
  Self.label2.TextAlign := System.Drawing.ContentAlignment.MiddleLeft;
  // 
  // label1
  // 
  Self.label1.Location := System.Drawing.Point.Create(16, 96);
  Self.label1.Name := 'label1';
  Self.label1.Size := System.Drawing.Size.Create(280, 16);
  Self.label1.TabIndex := 1;
  Self.label1.Text := 'Versão: 1.0.0';
  Self.label1.TextAlign := System.Drawing.ContentAlignment.MiddleRight;
  // 
  // pictureBox1
  // 
  Self.pictureBox1.BackColor := System.Drawing.Color.Transparent;
  Self.pictureBox1.Image := (System.Drawing.Image(resources.GetObject('pictureBox1.Image')));
  Self.pictureBox1.Location := System.Drawing.Point.Create(24, 16);
  Self.pictureBox1.Name := 'pictureBox1';
  Self.pictureBox1.Size := System.Drawing.Size.Create(264, 72);
  Self.pictureBox1.SizeMode := System.Windows.Forms.PictureBoxSizeMode.StretchImage;
  Self.pictureBox1.TabIndex := 0;
  Self.pictureBox1.TabStop := False;
  // 
  // btnOk
  // 
  Self.btnOk.DialogResult := System.Windows.Forms.DialogResult.OK;
  Self.btnOk.Location := System.Drawing.Point.Create(128, 192);
  Self.btnOk.Name := 'btnOk';
  Self.btnOk.TabIndex := 1;
  Self.btnOk.Text := 'OK';
  // 
  // frmSobre
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(328, 221);
  Self.Controls.Add(Self.btnOk);
  Self.Controls.Add(Self.groupBox1);
  Self.FormBorderStyle := System.Windows.Forms.FormBorderStyle.FixedDialog;
  Self.MaximizeBox := False;
  Self.MinimizeBox := False;
  Self.Name := 'frmSobre';
  Self.StartPosition := System.Windows.Forms.FormStartPosition.CenterParent;
  Self.Text := 'Sobre o Sistema';
  Include(Self.Closing, Self.frmSobre_Closing);
  Include(Self.MouseMove, Self.frmSobre_MouseMove);
  Self.groupBox1.ResumeLayout(False);
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmSobre.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmSobre.Create;
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

procedure frmSobre.frmSobre_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
      Principal.fPrincipal.StatusBar1.Panels.Item[1].Text:=Text;
end;

procedure frmSobre.frmSobre_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
begin
    Principal.fPrincipal.StatusBar1.Panels.Item[1].Text:='';
end;

end.
