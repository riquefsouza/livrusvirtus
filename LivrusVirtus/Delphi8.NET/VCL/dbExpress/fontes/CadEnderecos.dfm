inherited frmCadEnderecos: TfrmCadEnderecos
  Caption = 'Cadastro de Endere'#231'os'
  ClientHeight = 169
  ClientWidth = 525
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Caption = 'Logradouro:'
    Width = 57
  end
  object Label12: TLabel [2]
    Caption = 'Bairro:'
    Left = 280
    Top = 48
    Width = 30
    Height = 13
  end
  object Label11: TLabel [3]
    Caption = 'CEP:'
    Left = 8
    Top = 88
    Width = 24
    Height = 13
  end
  object Label10: TLabel [4]
    Caption = 'Cidade:'
    Left = 80
    Top = 88
    Width = 36
    Height = 13
  end
  object Label13: TLabel [5]
    Caption = 'Estado:'
    Left = 280
    Top = 88
    Width = 36
    Height = 13
  end
  inherited btnSalvar: TButton
    TabOrder = 10
    Left = 203
    Top = 137
    OnClick = btnSalvarClick
  end
  inherited btnExcluir: TButton
    TabOrder = 11
    Left = 283
    Top = 137
    OnClick = btnExcluirClick
  end
  inherited btnLimpar: TButton
    TabOrder = 12
    Left = 363
    Top = 137
  end
  inherited btnFechar: TButton
    TabOrder = 13
    Left = 443
    Top = 137
  end
  inherited btnPesquisar: TButton
    Anchors = [akRight]
    TabOrder = 7
    Left = 443
    Top = 13
    OnClick = btnPesquisarClick
  end
  inherited btnAnterior: TButton
    Anchors = [akRight]
    TabOrder = 8
    Left = 443
    Top = 45
  end
  inherited btnProximo: TButton
    Anchors = [akRight]
    TabOrder = 9
    Left = 443
    Top = 76
  end
  inherited edtDescricao: TEdit
    Width = 265
  end
  object edtBairro: TEdit [16]
    Enabled = False
    MaxLength = 14
    TabOrder = 3
    Left = 280
    Top = 64
    Width = 153
    Height = 21
  end
  object edtCEP: TEdit [17]
    Enabled = False
    MaxLength = 30
    TabOrder = 4
    Left = 8
    Top = 104
    Width = 65
    Height = 21
  end
  object edtCidade: TEdit [18]
    Enabled = False
    MaxLength = 30
    TabOrder = 5
    Left = 80
    Top = 104
    Width = 193
    Height = 21
  end
  object cmbEstado: TComboBox [19]
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 6
    Left = 280
    Top = 104
    Width = 153
    Height = 21
  end
  inherited Consulta: TSQLQuery
    Left = 128
    Top = 136
  end
  inherited Arquiva: TSQLQuery
    Left = 168
    Top = 136
  end
  inherited CDSConsulta: TClientDataSet
    Left = 48
    Top = 136
  end
  inherited DSPConsulta: TDataSetProvider
    Left = 88
    Top = 136
  end
end
