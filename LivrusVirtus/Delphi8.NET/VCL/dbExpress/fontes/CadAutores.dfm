inherited frmCadAutores: TfrmCadAutores
  Caption = 'Cadastros de Autores'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Caption = 'Autor:'
    Width = 28
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
