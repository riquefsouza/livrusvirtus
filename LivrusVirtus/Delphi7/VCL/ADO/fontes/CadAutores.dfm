inherited frmCadAutores: TfrmCadAutores
  Caption = 'Cadastros de Autores'
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Width = 28
    Caption = 'Autor:'
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
