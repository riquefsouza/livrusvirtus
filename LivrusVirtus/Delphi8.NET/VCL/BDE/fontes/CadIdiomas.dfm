inherited frmCadIdiomas: TfrmCadIdiomas
  Caption = 'Cadastro de Idiomas'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Caption = 'Idioma:'
    Width = 34
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
