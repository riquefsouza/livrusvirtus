inherited frmCadEnderecos: TfrmCadEnderecos
  Left = 249
  Top = 194
  Caption = 'Cadastro de Endere'#231'os'
  ClientHeight = 169
  ClientWidth = 525
  OldCreateOrder = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label2: TLabel
    Width = 57
    Caption = 'Logradouro:'
  end
  object Label12: TLabel [2]
    Left = 280
    Top = 48
    Width = 30
    Height = 13
    Caption = 'Bairro:'
  end
  object Label11: TLabel [3]
    Left = 8
    Top = 88
    Width = 24
    Height = 13
    Caption = 'CEP:'
  end
  object Label10: TLabel [4]
    Left = 80
    Top = 88
    Width = 36
    Height = 13
    Caption = 'Cidade:'
  end
  object Label13: TLabel [5]
    Left = 280
    Top = 88
    Width = 36
    Height = 13
    Caption = 'Estado:'
  end
  inherited btnSalvar: TButton
    Left = 203
    Top = 137
    TabOrder = 10
    OnClick = btnSalvarClick
  end
  inherited btnExcluir: TButton
    Left = 283
    Top = 137
    TabOrder = 11
    OnClick = btnExcluirClick
  end
  inherited btnLimpar: TButton
    Left = 363
    Top = 137
    TabOrder = 12
  end
  inherited btnFechar: TButton
    Left = 443
    Top = 137
    TabOrder = 13
  end
  inherited btnPesquisar: TButton
    Left = 443
    Top = 13
    Anchors = [akRight]
    TabOrder = 7
    OnClick = btnPesquisarClick
  end
  inherited btnAnterior: TButton
    Left = 443
    Top = 45
    Anchors = [akRight]
    TabOrder = 8
  end
  inherited btnProximo: TButton
    Left = 443
    Top = 76
    Anchors = [akRight]
    TabOrder = 9
  end
  inherited edtDescricao: TEdit
    Width = 265
  end
  object edtBairro: TEdit [16]
    Left = 280
    Top = 64
    Width = 153
    Height = 21
    Enabled = False
    MaxLength = 14
    TabOrder = 3
  end
  object edtCEP: TEdit [17]
    Left = 8
    Top = 104
    Width = 65
    Height = 21
    Enabled = False
    MaxLength = 30
    TabOrder = 4
  end
  object edtCidade: TEdit [18]
    Left = 80
    Top = 104
    Width = 193
    Height = 21
    Enabled = False
    MaxLength = 30
    TabOrder = 5
  end
  object cmbEstado: TComboBox [19]
    Left = 280
    Top = 104
    Width = 153
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 6
  end
  inherited Consulta: TSQLQuery
    Left = 240
    Top = 16
  end
  inherited Arquiva: TSQLQuery
    Left = 280
    Top = 16
  end
  inherited CDSConsulta: TClientDataSet
    AfterScroll = nil
  end
end
