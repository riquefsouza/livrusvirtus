object frmCadastros: TfrmCadastros
  BorderStyle = bsSingle
  Caption = 'Cadastro de'
  ClientHeight = 136
  ClientWidth = 330
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  Position = poDefault
  Visible = True
  Left = 8
  Top = 8
  OnClose = FormClose
  OnMouseMove = FormMouseMove
  DesignSize = (
    330
    136)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Caption = 'C'#243'digo:'
    Left = 8
    Top = 8
    Width = 36
    Height = 13
  end
  object Label2: TLabel
    Caption = 'Descri'#231#227'o:'
    Left = 8
    Top = 48
    Width = 51
    Height = 13
  end
  object btnSalvar: TButton
    Anchors = [akRight, akBottom]
    Caption = '&Salvar'
    Enabled = False
    TabOrder = 6
    Left = 8
    Top = 104
    Width = 75
    Height = 25
  end
  object btnExcluir: TButton
    Anchors = [akRight, akBottom]
    Caption = '&Excluir'
    Enabled = False
    TabOrder = 7
    Left = 88
    Top = 104
    Width = 75
    Height = 25
  end
  object btnLimpar: TButton
    Anchors = [akRight, akBottom]
    Caption = '&Limpar'
    TabOrder = 8
    Left = 168
    Top = 104
    Width = 75
    Height = 25
    OnClick = btnLimparClick
  end
  object btnFechar: TButton
    Anchors = [akRight, akBottom]
    Caption = '&Fechar'
    TabOrder = 9
    Left = 248
    Top = 104
    Width = 75
    Height = 25
    OnClick = btnFecharClick
  end
  object btnPesquisar: TButton
    Anchors = [akTop, akRight]
    Caption = '&Pesquisar'
    TabOrder = 3
    Left = 248
    Top = 8
    Width = 75
    Height = 25
  end
  object btnAnterior: TButton
    Anchors = [akTop, akRight]
    Caption = '&Anterior'
    Enabled = False
    TabOrder = 4
    Left = 248
    Top = 40
    Width = 75
    Height = 25
    OnClick = btnAnteriorClick
  end
  object btnProximo: TButton
    Anchors = [akTop, akRight]
    Caption = 'Pr'#243'xi&mo'
    Enabled = False
    TabOrder = 5
    Left = 248
    Top = 72
    Width = 75
    Height = 25
    OnClick = btnProximoClick
  end
  object btnNovo: TButton
    Caption = '&Novo'
    TabOrder = 1
    Left = 144
    Top = 24
    Width = 75
    Height = 25
    OnClick = btnNovoClick
  end
  object edtCodigo: TEdit
    MaxLength = 10
    TabOrder = 0
    Left = 8
    Top = 24
    Width = 121
    Height = 21
    OnExit = edtCodigoExit
  end
  object edtDescricao: TEdit
    Enabled = False
    MaxLength = 50
    TabOrder = 2
    Left = 8
    Top = 64
    Width = 217
    Height = 21
  end
  object Consulta: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 168
    Top = 64
  end
  object Arquiva: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 208
    Top = 64
  end
  object CDSConsulta: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPConsulta'
    Left = 88
    Top = 64
  end
  object DSPConsulta: TDataSetProvider
    DataSet = Consulta
    Options = [poUseQuoteChar]
    Left = 128
    Top = 64
  end
end
