inherited frmCadProfissoes: TfrmCadProfissoes
  Caption = 'Cadastro de Profiss�es'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Width = 46
    Caption = 'Profiss�o:'
  end
  inherited btnSalvar: TButton
    OnClick = btnSalvarClick
  end
  inherited btnExcluir: TButton
    OnClick = btnExcluirClick
  end
  inherited btnPesquisar: TButton
    OnClick = btnPesquisarClick
  end
end
