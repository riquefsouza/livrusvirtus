unit Principal;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, System.Resources, System.Data.OleDb;

type
  frmPrincipal = class(System.Windows.Forms.Form)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    components: System.ComponentModel.IContainer;
    MainMenu1: System.Windows.Forms.MainMenu;
    mnuCadastros: System.Windows.Forms.MenuItem;
    mnuPesquisas: System.Windows.Forms.MenuItem;
    mnuVendas: System.Windows.Forms.MenuItem;
    mnuJanelas: System.Windows.Forms.MenuItem;
    mnuOpcoes: System.Windows.Forms.MenuItem;
    MenuItem1: System.Windows.Forms.MenuItem;
    MenuItem2: System.Windows.Forms.MenuItem;
    mnuLadoALadoHorizontal: System.Windows.Forms.MenuItem;
    MenuItem4: System.Windows.Forms.MenuItem;
    mnuSobre: System.Windows.Forms.MenuItem;
    mnuSair: System.Windows.Forms.MenuItem;
    mnuLadoALadoVertical: System.Windows.Forms.MenuItem;
    mnuEmCascata: System.Windows.Forms.MenuItem;
    mnuOrganizarIcones: System.Windows.Forms.MenuItem;
    ToolBar1: System.Windows.Forms.ToolBar;
    StatusBarPanel1: System.Windows.Forms.StatusBarPanel;
    StatusBarPanel2: System.Windows.Forms.StatusBarPanel;
    ToolBarButton4: System.Windows.Forms.ToolBarButton;
    tlbSobre: System.Windows.Forms.ToolBarButton;
    tlbSair: System.Windows.Forms.ToolBarButton;
    ImageList1: System.Windows.Forms.ImageList;
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure mnuSair_Click(sender: System.Object; e: System.EventArgs);
    procedure ToolBar1_ButtonClick(sender: System.Object; e: System.Windows.Forms.ToolBarButtonClickEventArgs);
    procedure frmPrincipal_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure frmPrincipal_Load(sender: System.Object; e: System.EventArgs);
    procedure mnuLadoALadoHorizontal_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuLadoALadoVertical_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuEmCascata_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuOrganizarIcones_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuSobre_Click(sender: System.Object; e: System.EventArgs);
    procedure frmPrincipal_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
    procedure mnuCadAssuntos_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuAlterarSenha_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConAssuntos_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadAutores_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConAutores_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadEditoras_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConEditoras_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadEnderecos_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConEnderecos_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadIdiomas_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConIdiomas_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadPaises_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConPaises_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadProfissoes_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConProfissoes_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadClientes_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConClientes_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuCadLivros_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuConLivros_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuVenderLivros_Click(sender: System.Object; e: System.EventArgs);
    procedure mnuVendasRealizadas_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
  private
    { Private Declarations }
  public
    db: System.Data.OleDb.OleDbConnection;
    StatusBar1: System.Windows.Forms.StatusBar;
    tlbClientes: System.Windows.Forms.ToolBarButton;
    tlbLivros: System.Windows.Forms.ToolBarButton;
    tlbVender: System.Windows.Forms.ToolBarButton;
    mnuCadAssuntos: System.Windows.Forms.MenuItem;
    mnuConAssuntos: System.Windows.Forms.MenuItem;
    mnuCadAutores: System.Windows.Forms.MenuItem;
    mnuCadEditoras: System.Windows.Forms.MenuItem;
    mnuCadEnderecos: System.Windows.Forms.MenuItem;
    mnuCadIdiomas: System.Windows.Forms.MenuItem;
    mnuCadPaises: System.Windows.Forms.MenuItem;
    mnuCadProfissoes: System.Windows.Forms.MenuItem;
    mnuCadClientes: System.Windows.Forms.MenuItem;
    mnuCadLivros: System.Windows.Forms.MenuItem;
    mnuConAutores: System.Windows.Forms.MenuItem;
    mnuConEditoras: System.Windows.Forms.MenuItem;
    mnuConEnderecos: System.Windows.Forms.MenuItem;
    mnuConIdiomas: System.Windows.Forms.MenuItem;
    mnuConPaises: System.Windows.Forms.MenuItem;
    mnuConProfissoes: System.Windows.Forms.MenuItem;
    mnuConClientes: System.Windows.Forms.MenuItem;
    mnuConLivros: System.Windows.Forms.MenuItem;
    mnuVenderLivros: System.Windows.Forms.MenuItem;
    mnuVendasRealizadas: System.Windows.Forms.MenuItem;
    mnuAlterarSenha: System.Windows.Forms.MenuItem;
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmPrincipal))]

var
  fPrincipal: frmPrincipal;

implementation

uses Splash, ConsultasSQL, Login, RotinasGlobais, Sobre, AlterarSenha,
  CadAssuntos, ConAssuntos, CadAutores, CadClientes, CadEditoras,
  CadEnderecos, CadIdiomas, CadLivros, CadPaises, CadProfissoes,
  ConAutores, ConClientes, ConEditoras, ConEnderecos, ConIdiomas,
  ConLivros, ConPaises, ConProfissoes, ConVendas, VenderLivros;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmPrincipal.InitializeComponent;
type
  TArrayOfSystem_Windows_Forms_MenuItem = array of System.Windows.Forms.MenuItem;
  TArrayOfSystem_Windows_Forms_StatusBarPanel = array of System.Windows.Forms.StatusBarPanel;
  TArrayOfSystem_Windows_Forms_ToolBarButton = array of System.Windows.Forms.ToolBarButton;
var
  resources: System.Resources.ResourceManager;
begin
  Self.components := System.ComponentModel.Container.Create;
  resources := System.Resources.ResourceManager.Create(TypeOf(frmPrincipal));
  Self.MainMenu1 := System.Windows.Forms.MainMenu.Create;
  Self.mnuCadastros := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadAssuntos := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadAutores := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadEditoras := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadEnderecos := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadIdiomas := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadPaises := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadProfissoes := System.Windows.Forms.MenuItem.Create;
  Self.MenuItem1 := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadClientes := System.Windows.Forms.MenuItem.Create;
  Self.mnuCadLivros := System.Windows.Forms.MenuItem.Create;
  Self.mnuPesquisas := System.Windows.Forms.MenuItem.Create;
  Self.mnuConAssuntos := System.Windows.Forms.MenuItem.Create;
  Self.mnuConAutores := System.Windows.Forms.MenuItem.Create;
  Self.mnuConEditoras := System.Windows.Forms.MenuItem.Create;
  Self.mnuConEnderecos := System.Windows.Forms.MenuItem.Create;
  Self.mnuConIdiomas := System.Windows.Forms.MenuItem.Create;
  Self.mnuConPaises := System.Windows.Forms.MenuItem.Create;
  Self.mnuConProfissoes := System.Windows.Forms.MenuItem.Create;
  Self.MenuItem2 := System.Windows.Forms.MenuItem.Create;
  Self.mnuConClientes := System.Windows.Forms.MenuItem.Create;
  Self.mnuConLivros := System.Windows.Forms.MenuItem.Create;
  Self.mnuVendas := System.Windows.Forms.MenuItem.Create;
  Self.mnuVenderLivros := System.Windows.Forms.MenuItem.Create;
  Self.mnuVendasRealizadas := System.Windows.Forms.MenuItem.Create;
  Self.mnuJanelas := System.Windows.Forms.MenuItem.Create;
  Self.mnuLadoALadoHorizontal := System.Windows.Forms.MenuItem.Create;
  Self.mnuLadoALadoVertical := System.Windows.Forms.MenuItem.Create;
  Self.mnuEmCascata := System.Windows.Forms.MenuItem.Create;
  Self.mnuOrganizarIcones := System.Windows.Forms.MenuItem.Create;
  Self.mnuOpcoes := System.Windows.Forms.MenuItem.Create;
  Self.mnuAlterarSenha := System.Windows.Forms.MenuItem.Create;
  Self.MenuItem4 := System.Windows.Forms.MenuItem.Create;
  Self.mnuSobre := System.Windows.Forms.MenuItem.Create;
  Self.mnuSair := System.Windows.Forms.MenuItem.Create;
  Self.StatusBar1 := System.Windows.Forms.StatusBar.Create;
  Self.StatusBarPanel1 := System.Windows.Forms.StatusBarPanel.Create;
  Self.StatusBarPanel2 := System.Windows.Forms.StatusBarPanel.Create;
  Self.ToolBar1 := System.Windows.Forms.ToolBar.Create;
  Self.tlbClientes := System.Windows.Forms.ToolBarButton.Create;
  Self.tlbLivros := System.Windows.Forms.ToolBarButton.Create;
  Self.tlbVender := System.Windows.Forms.ToolBarButton.Create;
  Self.ToolBarButton4 := System.Windows.Forms.ToolBarButton.Create;
  Self.tlbSobre := System.Windows.Forms.ToolBarButton.Create;
  Self.tlbSair := System.Windows.Forms.ToolBarButton.Create;
  Self.ImageList1 := System.Windows.Forms.ImageList.Create(Self.components);
  (System.ComponentModel.ISupportInitialize(Self.StatusBarPanel1)).BeginInit;
  (System.ComponentModel.ISupportInitialize(Self.StatusBarPanel2)).BeginInit;
  Self.SuspendLayout;
  // 
  // MainMenu1
  // 
  Self.MainMenu1.MenuItems.AddRange(TArrayOfSystem_Windows_Forms_MenuItem.Create(Self.mnuCadastros, 
          Self.mnuPesquisas, Self.mnuVendas, Self.mnuJanelas, Self.mnuOpcoes));
  // 
  // mnuCadastros
  // 
  Self.mnuCadastros.Index := 0;
  Self.mnuCadastros.MenuItems.AddRange(TArrayOfSystem_Windows_Forms_MenuItem.Create(Self.mnuCadAssuntos, 
          Self.mnuCadAutores, Self.mnuCadEditoras, Self.mnuCadEnderecos, Self.mnuCadIdiomas, 
          Self.mnuCadPaises, Self.mnuCadProfissoes, Self.MenuItem1, Self.mnuCadClientes, 
          Self.mnuCadLivros));
  Self.mnuCadastros.Text := '&Cadastros';
  // 
  // mnuCadAssuntos
  // 
  Self.mnuCadAssuntos.Index := 0;
  Self.mnuCadAssuntos.Text := '&Assuntos';
  Include(Self.mnuCadAssuntos.Click, Self.mnuCadAssuntos_Click);
  // 
  // mnuCadAutores
  // 
  Self.mnuCadAutores.Index := 1;
  Self.mnuCadAutores.Text := 'Au&tores';
  Include(Self.mnuCadAutores.Click, Self.mnuCadAutores_Click);
  // 
  // mnuCadEditoras
  // 
  Self.mnuCadEditoras.Index := 2;
  Self.mnuCadEditoras.Text := '&Editoras';
  Include(Self.mnuCadEditoras.Click, Self.mnuCadEditoras_Click);
  // 
  // mnuCadEnderecos
  // 
  Self.mnuCadEnderecos.Index := 3;
  Self.mnuCadEnderecos.Text := 'E&ndere�os';
  Include(Self.mnuCadEnderecos.Click, Self.mnuCadEnderecos_Click);
  // 
  // mnuCadIdiomas
  // 
  Self.mnuCadIdiomas.Index := 4;
  Self.mnuCadIdiomas.Text := '&Idiomas';
  Include(Self.mnuCadIdiomas.Click, Self.mnuCadIdiomas_Click);
  // 
  // mnuCadPaises
  // 
  Self.mnuCadPaises.Index := 5;
  Self.mnuCadPaises.Text := '&Pa�ses';
  Include(Self.mnuCadPaises.Click, Self.mnuCadPaises_Click);
  // 
  // mnuCadProfissoes
  // 
  Self.mnuCadProfissoes.Index := 6;
  Self.mnuCadProfissoes.Text := 'P&rofiss�es';
  Include(Self.mnuCadProfissoes.Click, Self.mnuCadProfissoes_Click);
  // 
  // MenuItem1
  // 
  Self.MenuItem1.Index := 7;
  Self.MenuItem1.Text := '-';
  // 
  // mnuCadClientes
  // 
  Self.mnuCadClientes.Index := 8;
  Self.mnuCadClientes.Text := '&Clientes';
  Include(Self.mnuCadClientes.Click, Self.mnuCadClientes_Click);
  // 
  // mnuCadLivros
  // 
  Self.mnuCadLivros.Index := 9;
  Self.mnuCadLivros.Text := '&Livros';
  Include(Self.mnuCadLivros.Click, Self.mnuCadLivros_Click);
  // 
  // mnuPesquisas
  // 
  Self.mnuPesquisas.Index := 1;
  Self.mnuPesquisas.MenuItems.AddRange(TArrayOfSystem_Windows_Forms_MenuItem.Create(Self.mnuConAssuntos, 
          Self.mnuConAutores, Self.mnuConEditoras, Self.mnuConEnderecos, Self.mnuConIdiomas, 
          Self.mnuConPaises, Self.mnuConProfissoes, Self.MenuItem2, Self.mnuConClientes, 
          Self.mnuConLivros));
  Self.mnuPesquisas.Text := '&Pesquisas';
  // 
  // mnuConAssuntos
  // 
  Self.mnuConAssuntos.Index := 0;
  Self.mnuConAssuntos.Text := '&Assuntos';
  Include(Self.mnuConAssuntos.Click, Self.mnuConAssuntos_Click);
  // 
  // mnuConAutores
  // 
  Self.mnuConAutores.Index := 1;
  Self.mnuConAutores.Text := 'Au&tores';
  Include(Self.mnuConAutores.Click, Self.mnuConAutores_Click);
  // 
  // mnuConEditoras
  // 
  Self.mnuConEditoras.Index := 2;
  Self.mnuConEditoras.Text := '&Editoras';
  Include(Self.mnuConEditoras.Click, Self.mnuConEditoras_Click);
  // 
  // mnuConEnderecos
  // 
  Self.mnuConEnderecos.Index := 3;
  Self.mnuConEnderecos.Text := 'E&ndere�os';
  Include(Self.mnuConEnderecos.Click, Self.mnuConEnderecos_Click);
  // 
  // mnuConIdiomas
  // 
  Self.mnuConIdiomas.Index := 4;
  Self.mnuConIdiomas.Text := 'Idiomas';
  Include(Self.mnuConIdiomas.Click, Self.mnuConIdiomas_Click);
  // 
  // mnuConPaises
  // 
  Self.mnuConPaises.Index := 5;
  Self.mnuConPaises.Text := '&Pa�ses';
  Include(Self.mnuConPaises.Click, Self.mnuConPaises_Click);
  // 
  // mnuConProfissoes
  // 
  Self.mnuConProfissoes.Index := 6;
  Self.mnuConProfissoes.Text := 'P&rofiss�es';
  Include(Self.mnuConProfissoes.Click, Self.mnuConProfissoes_Click);
  // 
  // MenuItem2
  // 
  Self.MenuItem2.Index := 7;
  Self.MenuItem2.Text := '-';
  // 
  // mnuConClientes
  // 
  Self.mnuConClientes.Index := 8;
  Self.mnuConClientes.Text := '&Clientes';
  Include(Self.mnuConClientes.Click, Self.mnuConClientes_Click);
  // 
  // mnuConLivros
  // 
  Self.mnuConLivros.Index := 9;
  Self.mnuConLivros.Text := '&Livros';
  Include(Self.mnuConLivros.Click, Self.mnuConLivros_Click);
  // 
  // mnuVendas
  // 
  Self.mnuVendas.Index := 2;
  Self.mnuVendas.MenuItems.AddRange(TArrayOfSystem_Windows_Forms_MenuItem.Create(Self.mnuVenderLivros, 
          Self.mnuVendasRealizadas));
  Self.mnuVendas.Text := '&Vendas';
  // 
  // mnuVenderLivros
  // 
  Self.mnuVenderLivros.Index := 0;
  Self.mnuVenderLivros.Text := '&Vender Livros';
  Include(Self.mnuVenderLivros.Click, Self.mnuVenderLivros_Click);
  // 
  // mnuVendasRealizadas
  // 
  Self.mnuVendasRealizadas.Index := 1;
  Self.mnuVendasRealizadas.Text := 'Vendas &Realizadas';
  Include(Self.mnuVendasRealizadas.Click, Self.mnuVendasRealizadas_Click);
  // 
  // mnuJanelas
  // 
  Self.mnuJanelas.Index := 3;
  Self.mnuJanelas.MenuItems.AddRange(TArrayOfSystem_Windows_Forms_MenuItem.Create(Self.mnuLadoALadoHorizontal, 
          Self.mnuLadoALadoVertical, Self.mnuEmCascata, Self.mnuOrganizarIcones));
  Self.mnuJanelas.Text := '&Janelas';
  // 
  // mnuLadoALadoHorizontal
  // 
  Self.mnuLadoALadoHorizontal.Index := 0;
  Self.mnuLadoALadoHorizontal.Text := 'Lado a lado &horizontal';
  Include(Self.mnuLadoALadoHorizontal.Click, Self.mnuLadoALadoHorizontal_Click);
  // 
  // mnuLadoALadoVertical
  // 
  Self.mnuLadoALadoVertical.Index := 1;
  Self.mnuLadoALadoVertical.Text := 'Lado a lado &vertical';
  Include(Self.mnuLadoALadoVertical.Click, Self.mnuLadoALadoVertical_Click);
  // 
  // mnuEmCascata
  // 
  Self.mnuEmCascata.Index := 2;
  Self.mnuEmCascata.Text := 'Em &cascata';
  Include(Self.mnuEmCascata.Click, Self.mnuEmCascata_Click);
  // 
  // mnuOrganizarIcones
  // 
  Self.mnuOrganizarIcones.Index := 3;
  Self.mnuOrganizarIcones.Text := '&Organizar �cones';
  Include(Self.mnuOrganizarIcones.Click, Self.mnuOrganizarIcones_Click);
  // 
  // mnuOpcoes
  // 
  Self.mnuOpcoes.Index := 4;
  Self.mnuOpcoes.MenuItems.AddRange(TArrayOfSystem_Windows_Forms_MenuItem.Create(Self.mnuAlterarSenha, 
          Self.MenuItem4, Self.mnuSobre, Self.mnuSair));
  Self.mnuOpcoes.Text := '&Op��es';
  // 
  // mnuAlterarSenha
  // 
  Self.mnuAlterarSenha.Index := 0;
  Self.mnuAlterarSenha.Text := '&Alterar Senha';
  Include(Self.mnuAlterarSenha.Click, Self.mnuAlterarSenha_Click);
  // 
  // MenuItem4
  // 
  Self.MenuItem4.Index := 1;
  Self.MenuItem4.Text := '-';
  // 
  // mnuSobre
  // 
  Self.mnuSobre.Index := 2;
  Self.mnuSobre.Text := '&Sobre';
  Include(Self.mnuSobre.Click, Self.mnuSobre_Click);
  // 
  // mnuSair
  // 
  Self.mnuSair.Index := 3;
  Self.mnuSair.Text := 'Sa&ir';
  Include(Self.mnuSair.Click, Self.mnuSair_Click);
  // 
  // StatusBar1
  // 
  Self.StatusBar1.Location := System.Drawing.Point.Create(0, 380);
  Self.StatusBar1.Name := 'StatusBar1';
  Self.StatusBar1.Panels.AddRange(TArrayOfSystem_Windows_Forms_StatusBarPanel.Create(Self.StatusBarPanel1, 
          Self.StatusBarPanel2));
  Self.StatusBar1.ShowPanels := True;
  Self.StatusBar1.Size := System.Drawing.Size.Create(536, 22);
  Self.StatusBar1.TabIndex := 1;
  Self.StatusBar1.Text := 'StatusBar1';
  // 
  // StatusBarPanel1
  // 
  Self.StatusBarPanel1.AutoSize := System.Windows.Forms.StatusBarPanelAutoSize.Contents;
  Self.StatusBarPanel1.Text := 'Usu�rio:';
  Self.StatusBarPanel1.Width := 56;
  // 
  // StatusBarPanel2
  // 
  Self.StatusBarPanel2.AutoSize := System.Windows.Forms.StatusBarPanelAutoSize.Spring;
  Self.StatusBarPanel2.Width := 464;
  // 
  // ToolBar1
  // 
  Self.ToolBar1.Buttons.AddRange(TArrayOfSystem_Windows_Forms_ToolBarButton.Create(Self.tlbClientes, 
          Self.tlbLivros, Self.tlbVender, Self.ToolBarButton4, Self.tlbSobre, 
          Self.tlbSair));
  Self.ToolBar1.DropDownArrows := True;
  Self.ToolBar1.ImageList := Self.ImageList1;
  Self.ToolBar1.Location := System.Drawing.Point.Create(0, 0);
  Self.ToolBar1.Name := 'ToolBar1';
  Self.ToolBar1.ShowToolTips := True;
  Self.ToolBar1.Size := System.Drawing.Size.Create(536, 28);
  Self.ToolBar1.TabIndex := 2;
  Include(Self.ToolBar1.ButtonClick, Self.ToolBar1_ButtonClick);
  // 
  // tlbClientes
  // 
  Self.tlbClientes.ImageIndex := 0;
  // 
  // tlbLivros
  // 
  Self.tlbLivros.ImageIndex := 1;
  // 
  // tlbVender
  // 
  Self.tlbVender.ImageIndex := 2;
  // 
  // ToolBarButton4
  // 
  Self.ToolBarButton4.Style := System.Windows.Forms.ToolBarButtonStyle.Separator;
  // 
  // tlbSobre
  // 
  Self.tlbSobre.ImageIndex := 3;
  // 
  // tlbSair
  // 
  Self.tlbSair.ImageIndex := 4;
  // 
  // ImageList1
  // 
  Self.ImageList1.ImageSize := System.Drawing.Size.Create(16, 16);
  Self.ImageList1.ImageStream := (System.Windows.Forms.ImageListStreamer(resources.GetObject('ImageList1.ImageStream')));
  Self.ImageList1.TransparentColor := System.Drawing.Color.Transparent;
  // 
  // frmPrincipal
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(536, 402);
  Self.Controls.Add(Self.ToolBar1);
  Self.Controls.Add(Self.StatusBar1);
  Self.Icon := (System.Drawing.Icon(resources.GetObject('$this.Icon')));
  Self.IsMdiContainer := True;
  Self.Menu := Self.MainMenu1;
  Self.Name := 'frmPrincipal';
  Self.Text := 'Livrus Virtus';
  Include(Self.Closing, Self.frmPrincipal_Closing);
  Include(Self.Load, Self.frmPrincipal_Load);
  Include(Self.MouseMove, Self.frmPrincipal_MouseMove);
  (System.ComponentModel.ISupportInitialize(Self.StatusBarPanel1)).EndInit;
  (System.ComponentModel.ISupportInitialize(Self.StatusBarPanel2)).EndInit;
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmPrincipal.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmPrincipal.Create;
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

procedure frmPrincipal.mnuVendasRealizadas_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuVendasRealizadas.Enabled:=false;
    fConVendas := frmconVendas.Create;
    fConVendas.MdiParent:=self;
    fConVendas.Show;
end;

procedure frmPrincipal.mnuVenderLivros_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuVenderLivros.Enabled:=false;
    tlbVender.Enabled:=false;
    fVenderLivros := frmVenderLivros.Create;
    fVenderLivros.MdiParent:=self;
    fVenderLivros.Show;
end;

procedure frmPrincipal.mnuConLivros_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConLivros.Enabled:=false;
    fConLivros := frmConLivros.Create;
    fConLivros.MdiParent:=self;
    fConLivros.Show;
end;

procedure frmPrincipal.mnuCadLivros_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadLivros.Enabled:=false;
    tlbLivros.Enabled:=false;
    fCadLivros := frmCadLivros.Create;
    fCadLivros.MdiParent:=self;
    fCadLivros.Show;
end;

procedure frmPrincipal.mnuConClientes_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConClientes.Enabled:=false;
    fConClientes := frmConClientes.Create;
    fConClientes.MdiParent:=self;
    fConClientes.Show;
end;

procedure frmPrincipal.mnuCadClientes_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadClientes.Enabled:=false;
    tlbClientes.Enabled:=false;
    fCadClientes := frmCadClientes.Create;
    fCadClientes.MdiParent:=self;
    fCadClientes.Show;
end;

procedure frmPrincipal.mnuConProfissoes_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConProfissoes.Enabled:=false;
    fConProfissoes := frmConProfissoes.Create;
    fConProfissoes.MdiParent:=self;
    fConProfissoes.Show;
end;

procedure frmPrincipal.mnuCadProfissoes_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadProfissoes.Enabled:=false;
    fCadProfissoes := frmCadProfissoes.Create;
    fCadProfissoes.MdiParent:=self;
    fCadProfissoes.Show;
end;

procedure frmPrincipal.mnuConPaises_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConPaises.Enabled:=false;
    fConPaises := frmConPaises.Create;
    fConPaises.MdiParent:=self;
    fConPaises.Show;
end;

procedure frmPrincipal.mnuCadPaises_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadPaises.Enabled:=false;
    fCadPaises := frmCadPaises.Create;
    fCadPaises.MdiParent:=self;
    fCadPaises.Show;
end;

procedure frmPrincipal.mnuConIdiomas_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConIdiomas.Enabled:=false;
    fConIdiomas := frmConIdiomas.Create;
    fConIdiomas.MdiParent:=self;
    fConIdiomas.Show;
end;

procedure frmPrincipal.mnuCadIdiomas_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadIdiomas.Enabled:=false;
    fCadIdiomas := frmCadIdiomas.Create;
    fCadIdiomas.MdiParent:=self;
    fCadIdiomas.Show;
end;

procedure frmPrincipal.mnuConEnderecos_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConEnderecos.Enabled:=false;
    fConEnderecos := frmConEnderecos.Create;
    fConEnderecos.MdiParent:=self;
    fConEnderecos.Show;
end;

procedure frmPrincipal.mnuCadEnderecos_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadEnderecos.Enabled:=false;
    fCadEnderecos := frmCadEnderecos.Create;
    fCadEnderecos.MdiParent:=self;
    fCadEnderecos.Show;
end;

procedure frmPrincipal.mnuConEditoras_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConEditoras.Enabled:=false;
    fConEditoras := frmConEditoras.Create;
    fConEditoras.MdiParent:=self;
    fConEditoras.Show;
end;

procedure frmPrincipal.mnuCadEditoras_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadEditoras.Enabled:=false;
    fCadEditoras := frmCadEditoras.Create;
    fCadEditoras.MdiParent:=self;
    fCadEditoras.Show;
end;

procedure frmPrincipal.mnuConAutores_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConAutores.Enabled:=false;
    fConAutores := frmConAutores.Create;
    fConAutores.MdiParent:=self;
    fConAutores.Show;
end;

procedure frmPrincipal.mnuCadAutores_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadAutores.Enabled:=false;
    fCadAutores := frmCadAutores.Create;
    fCadAutores.MdiParent:=self;
    fCadAutores.Show;
end;

procedure frmPrincipal.mnuConAssuntos_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuConAssuntos.Enabled:=false;
		fConAssuntos := frmConAssuntos.Create;
		fConAssuntos.MdiParent:=self;
		fConAssuntos.Show;
end;

procedure frmPrincipal.mnuAlterarSenha_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuAlterarSenha.Enabled:=false;
    fAlterarSenha := frmAlterarSenha.Create;
    fAlterarSenha.MdiParent:=Self;
    fAlterarSenha.Show;
end;

procedure frmPrincipal.mnuCadAssuntos_Click(sender: System.Object; e: System.EventArgs);
begin
    mnuCadAssuntos.Enabled:=false;
    fCadAssuntos := frmCadAssuntos.Create;
    fCadAssuntos.MdiParent:=self;
    fCadAssuntos.Show;
end;

procedure frmPrincipal.frmPrincipal_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
begin
  self.statusBar1.Panels.Item[1].Text:=' ';
end;

procedure frmPrincipal.mnuSobre_Click(sender: System.Object; e: System.EventArgs);
begin
  	Sobre.fSobre := frmSobre.Create;
		Sobre.fSobre.ShowDialog;
end;

procedure frmPrincipal.mnuOrganizarIcones_Click(sender: System.Object; e: System.EventArgs);
begin
  self.LayoutMdi(MdiLayout.ArrangeIcons);
end;

procedure frmPrincipal.mnuEmCascata_Click(sender: System.Object; e: System.EventArgs);
begin
  self.LayoutMdi(MdiLayout.Cascade);
end;

procedure frmPrincipal.mnuLadoALadoVertical_Click(sender: System.Object; e: System.EventArgs);
begin
	self.LayoutMdi(MdiLayout.TileVertical);
end;

procedure frmPrincipal.mnuLadoALadoHorizontal_Click(sender: System.Object; e: System.EventArgs);
begin
	 self.LayoutMdi(MdiLayout.TileHorizontal);
end;

procedure frmPrincipal.frmPrincipal_Load(sender: System.Object; e: System.EventArgs);
begin
    db.Open;

    ConsultasSQL.ConsSQL := TConsultasSQL.Create;
    RotinasGlobais.Rotinas := TRotinasGlobais.Create;

    Splash.fSplash := frmSplash.Create;
    Splash.fSplash.ShowDialog;

    Login.fLogin := frmLogin.Create;
    Login.fLogin.ShowDialog;
end;

procedure frmPrincipal.ToolBar1_ButtonClick(sender: System.Object; e: System.Windows.Forms.ToolBarButtonClickEventArgs);
begin
  case (toolBar1.Buttons.IndexOf(e.Button)) of
    0: mnuCadClientes_Click(self,nil);
    1: mnuCadLivros_Click(self,nil);
    2: mnuVenderLivros_Click(self,nil);
	  4: mnuSobre_Click(self,nil);
	  5: mnuSair_Click(self,nil);
	end;
end;

procedure frmPrincipal.frmPrincipal_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
var res: System.Windows.Forms.DialogResult;
begin

res := MessageBox.Show('Deseja sair do sistema?',fPrincipal.Text,
       MessageBoxButtons.YesNo, MessageBoxIcon.Question,
       MessageBoxDefaultButton.Button1);

 if res = System.Windows.Forms.DialogResult.Yes then begin
    db.Close;
    e.Cancel:=false;
  end else
    e.Cancel:=true;
end;

procedure frmPrincipal.mnuSair_Click(sender: System.Object; e: System.EventArgs);
begin
Close;
end;

end.
