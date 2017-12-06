inherited frmCadIdiomas: TfrmCadIdiomas
  Caption = 'Cadastro de Idiomas'
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Width = 34
    Caption = 'Idioma:'
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
