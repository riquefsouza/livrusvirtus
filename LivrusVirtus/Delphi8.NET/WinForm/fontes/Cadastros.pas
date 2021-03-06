unit Cadastros;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, System.Data.OleDb;

type
  frmCadastros = class(System.Windows.Forms.Form)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure btnFechar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnNovo_Click(sender: System.Object; e: System.EventArgs);
    procedure btnAnterior_Click(sender: System.Object; e: System.EventArgs);
    procedure btnProximo_Click(sender: System.Object; e: System.EventArgs);
    procedure edtCodigo_Leave(sender: System.Object; e: System.EventArgs);
    procedure frmCadastros_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
    procedure frmCadastros_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
 		Registros: ArrayList;
		Campos: ArrayList;
		nLinhaRegistro: integer;
		labCodigo: System.Windows.Forms.Label;
		edtCodigo: System.Windows.Forms.TextBox;
		labDescricao: System.Windows.Forms.Label;
		edtDescricao: System.Windows.Forms.TextBox;
		btnNovo: System.Windows.Forms.Button;
		btnPesquisar: System.Windows.Forms.Button;
		btnAnterior: System.Windows.Forms.Button;
		btnProximo: System.Windows.Forms.Button;
		btnFechar: System.Windows.Forms.Button;
		btnLimpar: System.Windows.Forms.Button;
		btnExcluir: System.Windows.Forms.Button;
		btnSalvar: System.Windows.Forms.Button;
		Arquiva: System.Data.OleDb.OleDbCommand;
    procedure Dispose(Disposing: Boolean); override;
    procedure btnLimpar_Click(sender: System.Object; e: System.EventArgs);
    function ValidaDados(bTodosDados: boolean):boolean; virtual;
    procedure InformaLimpaDados(bInformar: boolean); virtual;
    procedure HabilitaDados(bHabilita: boolean); virtual;
    procedure NovoDado(sTextoSql: string);
    procedure ExcluirDados(sTextoSql: string);
    procedure PesquisarDados(sTextoSql, sMensagemErro: string);
    procedure SalvarDados(sTextoSql, sTextoUpdate,
                sTextoInsert: string; bLimparDados: boolean);
  private
    { Private Declarations }
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmCadastros))]

implementation

uses Principal, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmCadastros.InitializeComponent;
begin
  Self.labCodigo := System.Windows.Forms.Label.Create;
  Self.edtCodigo := System.Windows.Forms.TextBox.Create;
  Self.labDescricao := System.Windows.Forms.Label.Create;
  Self.edtDescricao := System.Windows.Forms.TextBox.Create;
  Self.btnNovo := System.Windows.Forms.Button.Create;
  Self.btnPesquisar := System.Windows.Forms.Button.Create;
  Self.btnAnterior := System.Windows.Forms.Button.Create;
  Self.btnProximo := System.Windows.Forms.Button.Create;
  Self.btnFechar := System.Windows.Forms.Button.Create;
  Self.btnLimpar := System.Windows.Forms.Button.Create;
  Self.btnExcluir := System.Windows.Forms.Button.Create;
  Self.btnSalvar := System.Windows.Forms.Button.Create;
  Self.Arquiva := System.Data.OleDb.OleDbCommand.Create;
  Self.SuspendLayout;
  // 
  // labCodigo
  // 
  Self.labCodigo.Location := System.Drawing.Point.Create(8, 8);
  Self.labCodigo.Name := 'labCodigo';
  Self.labCodigo.Size := System.Drawing.Size.Create(56, 16);
  Self.labCodigo.TabIndex := 0;
  Self.labCodigo.Text := 'C�digo:';
  // 
  // edtCodigo
  // 
  Self.edtCodigo.Location := System.Drawing.Point.Create(8, 24);
  Self.edtCodigo.MaxLength := 10;
  Self.edtCodigo.Name := 'edtCodigo';
  Self.edtCodigo.Size := System.Drawing.Size.Create(128, 20);
  Self.edtCodigo.TabIndex := 1;
  Self.edtCodigo.Text := '';
  Include(Self.edtCodigo.Leave, Self.edtCodigo_Leave);
  // 
  // labDescricao
  // 
  Self.labDescricao.Location := System.Drawing.Point.Create(8, 48);
  Self.labDescricao.Name := 'labDescricao';
  Self.labDescricao.Size := System.Drawing.Size.Create(64, 16);
  Self.labDescricao.TabIndex := 3;
  Self.labDescricao.Text := 'Descri��o:';
  // 
  // edtDescricao
  // 
  Self.edtDescricao.Enabled := False;
  Self.edtDescricao.Location := System.Drawing.Point.Create(8, 64);
  Self.edtDescricao.Name := 'edtDescricao';
  Self.edtDescricao.Size := System.Drawing.Size.Create(232, 20);
  Self.edtDescricao.TabIndex := 4;
  Self.edtDescricao.Text := '';
  // 
  // btnNovo
  // 
  Self.btnNovo.Location := System.Drawing.Point.Create(152, 24);
  Self.btnNovo.Name := 'btnNovo';
  Self.btnNovo.TabIndex := 2;
  Self.btnNovo.Text := '&Novo';
  Include(Self.btnNovo.Click, Self.btnNovo_Click);
  // 
  // btnPesquisar
  // 
  Self.btnPesquisar.Location := System.Drawing.Point.Create(256, 8);
  Self.btnPesquisar.Name := 'btnPesquisar';
  Self.btnPesquisar.TabIndex := 5;
  Self.btnPesquisar.Text := '&Pesquisar';
  // 
  // btnAnterior
  // 
  Self.btnAnterior.Enabled := False;
  Self.btnAnterior.Location := System.Drawing.Point.Create(256, 40);
  Self.btnAnterior.Name := 'btnAnterior';
  Self.btnAnterior.TabIndex := 6;
  Self.btnAnterior.Text := '&Anterior';
  Include(Self.btnAnterior.Click, Self.btnAnterior_Click);
  // 
  // btnProximo
  // 
  Self.btnProximo.Enabled := False;
  Self.btnProximo.Location := System.Drawing.Point.Create(256, 72);
  Self.btnProximo.Name := 'btnProximo';
  Self.btnProximo.TabIndex := 7;
  Self.btnProximo.Text := 'Pr�xi&mo';
  Include(Self.btnProximo.Click, Self.btnProximo_Click);
  // 
  // btnFechar
  // 
  Self.btnFechar.DialogResult := System.Windows.Forms.DialogResult.Cancel;
  Self.btnFechar.Location := System.Drawing.Point.Create(256, 104);
  Self.btnFechar.Name := 'btnFechar';
  Self.btnFechar.TabIndex := 11;
  Self.btnFechar.Text := '&Fechar';
  Include(Self.btnFechar.Click, Self.btnFechar_Click);
  // 
  // btnLimpar
  // 
  Self.btnLimpar.Location := System.Drawing.Point.Create(176, 104);
  Self.btnLimpar.Name := 'btnLimpar';
  Self.btnLimpar.TabIndex := 10;
  Self.btnLimpar.Text := '&Limpar';
  Include(Self.btnLimpar.Click, Self.btnLimpar_Click);
  // 
  // btnExcluir
  // 
  Self.btnExcluir.Enabled := False;
  Self.btnExcluir.Location := System.Drawing.Point.Create(96, 104);
  Self.btnExcluir.Name := 'btnExcluir';
  Self.btnExcluir.TabIndex := 9;
  Self.btnExcluir.Text := '&Excluir';
  // 
  // btnSalvar
  // 
  Self.btnSalvar.Enabled := False;
  Self.btnSalvar.Location := System.Drawing.Point.Create(16, 104);
  Self.btnSalvar.Name := 'btnSalvar';
  Self.btnSalvar.TabIndex := 8;
  Self.btnSalvar.Text := '&Salvar';
  // 
  // frmCadastros
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.CancelButton := Self.btnFechar;
  Self.ClientSize := System.Drawing.Size.Create(336, 133);
  Self.Controls.Add(Self.btnSalvar);
  Self.Controls.Add(Self.btnExcluir);
  Self.Controls.Add(Self.btnLimpar);
  Self.Controls.Add(Self.btnFechar);
  Self.Controls.Add(Self.btnProximo);
  Self.Controls.Add(Self.btnAnterior);
  Self.Controls.Add(Self.btnPesquisar);
  Self.Controls.Add(Self.btnNovo);
  Self.Controls.Add(Self.edtDescricao);
  Self.Controls.Add(Self.edtCodigo);
  Self.Controls.Add(Self.labDescricao);
  Self.Controls.Add(Self.labCodigo);
  Self.Name := 'frmCadastros';
  Self.Text := 'Cadastro de';
  Include(Self.Closing, Self.frmCadastros_Closing);
  Include(Self.MouseMove, Self.frmCadastros_MouseMove);
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmCadastros.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmCadastros.Create;
begin
  inherited Create;
  //
  // Required for Windows Form Designer support
  //
  InitializeComponent;
  //
  // TODO: Add any constructor code after InitializeComponent call
  //
	Registros := ArrayList.Create;
  nLinhaRegistro := 0;
end;

procedure frmCadastros.frmCadastros_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  Principal.fPrincipal.statusBar1.Panels.Item[1].Text:='';
end;

procedure frmCadastros.frmCadastros_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
begin
  Principal.fPrincipal.statusBar1.Panels.Item[1].Text:=Text;
end;

procedure frmCadastros.edtCodigo_Leave(sender: System.Object; e: System.EventArgs);
begin
  if (edtCodigo.Text<>'') then begin
    if (RotinasGlobais.Rotinas.ValidaInteger(edtCodigo.Text)=false) then begin
      edtCodigo.Text:='';
      edtCodigo.Focus;
    end;
  end;
end;

procedure frmCadastros.btnProximo_Click(sender: System.Object; e: System.EventArgs);
begin
  if (nLinhaRegistro < (Registros.Count-1)) then begin
    nLinhaRegistro:=nLinhaRegistro + 1;
    InformaLimpaDados(true);
  end;
end;

procedure frmCadastros.btnAnterior_Click(sender: System.Object; e: System.EventArgs);
begin
  if (nLinhaRegistro > 0) then begin
    nLinhaRegistro:=nLinhaRegistro - 1;
    InformaLimpaDados(true);
  end;
end;

procedure frmCadastros.btnLimpar_Click(sender: System.Object; e: System.EventArgs);
begin
  btnSalvar.Enabled:=false;
  btnExcluir.Enabled:=false;
  btnPesquisar.Enabled:=true;
  btnAnterior.Enabled:=false;
  btnProximo.Enabled:=false;
  btnNovo.Enabled:=true;

  InformaLimpaDados(false);
  HabilitaDados(false);
end;

procedure frmCadastros.btnNovo_Click(sender: System.Object; e: System.EventArgs);
begin
  btnSalvar.Enabled:=true;
  btnExcluir.Enabled:=false;
  btnPesquisar.Enabled:=false;
  btnAnterior.Enabled:=false;
  btnProximo.Enabled:=false;
  btnNovo.Enabled:=false;

  InformaLimpaDados(false);
  HabilitaDados(true);
end;

procedure frmCadastros.btnFechar_Click(sender: System.Object; e: System.EventArgs);
begin
  Close;
end;

function frmCadastros.ValidaDados(bTodosDados: boolean):boolean;
begin
  result:=true;
end;

procedure frmCadastros.InformaLimpaDados(bInformar: boolean);
begin
  if (bInformar) then begin
    Campos := (ArrayList(Registros.Item[nLinhaRegistro]));
    edtCodigo.Text:=Campos.Item[0].ToString();
    edtDescricao.Text:=Campos.Item[1].ToString();
  end else begin
    edtCodigo.Text:='';
    edtDescricao.Text:='';
    edtCodigo.Enabled:=true;
    edtCodigo.Focus;
  end;
end;

procedure frmCadastros.HabilitaDados(bHabilita: boolean);
begin
  edtDescricao.Enabled:=bHabilita;
end;

procedure frmCadastros.NovoDado(sTextoSql: string);
begin
   if (RotinasGlobais.Rotinas.ConsultaDados(Registros, sTextoSql)) then begin
    Campos := ArrayList(Registros.Item[0]);
    edtCodigo.Text := Campos[0].ToString();
    edtCodigo.Enabled := false;
    edtDescricao.Focus;
   end;
end;

procedure frmCadastros.ExcluirDados(sTextoSql: string);
var res: System.Windows.Forms.DialogResult;
begin
  if (ValidaDados(false)) then begin

   res := MessageBox.Show(self, 'Certeza de excluir?',
   Principal.fPrincipal.Text, MessageBoxButtons.YesNo,
   MessageBoxIcon.Question, MessageBoxDefaultButton.Button2);

   if (res = System.Windows.Forms.DialogResult.Yes) then begin
      Arquiva := Principal.fPrincipal.db.CreateCommand;
      Arquiva.CommandText := sTextoSql;
      Arquiva.ExecuteNonQuery;
      Arquiva.Dispose;
      btnLimpar_Click(self,nil);
   end;
  end;
end;

procedure frmCadastros.PesquisarDados(sTextoSql, sMensagemErro: string);
begin
  if (edtCodigo.Text='') then begin
    btnAnterior.Enabled:=true;
    btnProximo.Enabled:=true;
  end;

  if (RotinasGlobais.Rotinas.ConsultaDados(Registros,sTextoSql)) then begin
       nLinhaRegistro:=0;
     InformaLimpaDados(true);
     HabilitaDados(true);

     btnSalvar.Enabled:=true;
     btnExcluir.Enabled:=true;
     btnPesquisar.Enabled:=false;
  end else
    MessageBox.Show(sMensagemErro, Principal.fPrincipal.Text,
    MessageBoxButtons.OK, MessageBoxIcon.Information);

end;

procedure frmCadastros.SalvarDados(sTextoSql, sTextoUpdate,
                sTextoInsert: string; bLimparDados: boolean);
begin
  if (ValidaDados(true)) then begin
     Arquiva := Principal.fPrincipal.db.CreateCommand;
     if (RotinasGlobais.Rotinas.ConsultaDados(Arquiva,sTextoSql)) then begin
       Arquiva.CommandText := sTextoUpdate;
     end else begin
       Arquiva.CommandText := sTextoInsert;
     end;
     Arquiva.ExecuteNonQuery;
     Arquiva.Dispose;
     if (bLimparDados) then
      btnLimpar_Click(self,nil);
  end;
end;

end.
