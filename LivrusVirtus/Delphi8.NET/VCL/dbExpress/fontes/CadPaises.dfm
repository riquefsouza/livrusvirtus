inherited frmCadPaises: TfrmCadPaises
  Caption = 'Cadastro de Pa'#237'ses'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Caption = 'Pa'#237's:'
    Width = 25
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
  inherited edtCodigo: TEdit
    MaxLength = 3
  end
end