object frmConsultas: TfrmConsultas
  BorderStyle = bsDialog
  Caption = 'Consulta de '
  ClientHeight = 238
  ClientWidth = 354
  Color = clBtnFace
  ParentFont = True
  Position = poMainFormCenter
  Left = 8
  Top = 8
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    Left = 0
    Top = 0
    Width = 354
    Height = 57
    object Label2: TLabel
      Caption = 'Descri'#231#227'o:'
      Left = 8
      Top = 8
      Width = 50
      Height = 13
    end
    object edtDescricao: TEdit
      TabOrder = 0
      Left = 8
      Top = 24
      Width = 257
      Height = 21
    end
    object btnPesquisar: TButton
      Caption = '&Pesquisar'
      TabOrder = 1
      Left = 272
      Top = 24
      Width = 75
      Height = 25
    end
  end
  object gridConsulta: TDBGrid
    Align = alClient
    DataSource = DSConsulta
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Left = 0
    Top = 57
    Width = 354
    Height = 148
    OnMouseMove = gridConsultaMouseMove
  end
  object Panel2: TPanel
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    Left = 0
    Top = 205
    Width = 354
    Height = 33
    DesignSize = (
      354
      33)
    object labRegistros: TLabel
      Caption = 'Registro 0 de 0'
      Left = 8
      Top = 10
      Width = 73
      Height = 13
    end
    object btnFechar: TButton
      Anchors = [akRight, akBottom]
      Caption = '&Fechar'
      TabOrder = 0
      Left = 276
      Top = 4
      Width = 75
      Height = 25
      OnClick = btnFecharClick
    end
    object btnLimpar: TButton
      Anchors = [akRight, akBottom]
      Caption = '&Limpar'
      TabOrder = 1
      Left = 196
      Top = 4
      Width = 75
      Height = 25
    end
  end
  object DSConsulta: TDataSource
    DataSet = CDSConsulta
    Left = 128
    Top = 208
  end
  object Consulta: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 160
    Top = 208
  end
  object CDSConsulta: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPConsulta'
    AfterScroll = CDSConsultaAfterScroll
    Left = 24
    Top = 160
  end
  object DSPConsulta: TDataSetProvider
    DataSet = Consulta
    Options = [poUseQuoteChar]
    Left = 64
    Top = 160
  end
end
