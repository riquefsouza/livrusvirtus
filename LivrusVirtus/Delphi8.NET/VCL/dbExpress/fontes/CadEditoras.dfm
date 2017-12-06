inherited frmCadEditoras: TfrmCadEditoras
  Caption = 'Cadastro de Editoras'
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Caption = 'Editora:'
    Width = 36
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
  inherited Consulta: TSQLQuery
    Left = 168
  end
  inherited Arquiva: TSQLQuery
    Left = 208
  end
  inherited CDSConsulta: TClientDataSet
    Left = 88
  end
  inherited DSPConsulta: TDataSetProvider
    Left = 128
  end
end
