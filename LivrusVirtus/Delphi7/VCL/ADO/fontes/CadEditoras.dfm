inherited frmCadEditoras: TfrmCadEditoras
  Caption = 'Cadastro de Editoras'
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Width = 36
    Caption = 'Editora:'
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