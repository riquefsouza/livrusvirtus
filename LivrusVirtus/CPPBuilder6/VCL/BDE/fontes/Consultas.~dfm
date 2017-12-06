object frmConsultas: TfrmConsultas
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Consulta de '
  ClientHeight = 238
  ClientWidth = 354
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 354
    Height = 57
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label2: TLabel
      Left = 8
      Top = 8
      Width = 51
      Height = 13
      Caption = 'Descrição:'
    end
    object edtDescricao: TEdit
      Left = 8
      Top = 24
      Width = 257
      Height = 21
      TabOrder = 0
    end
    object btnPesquisar: TButton
      Left = 272
      Top = 24
      Width = 75
      Height = 25
      Caption = '&Pesquisar'
      TabOrder = 1
    end
  end
  object gridConsulta: TDBGrid
    Left = 0
    Top = 57
    Width = 354
    Height = 148
    Align = alClient
    DataSource = DSConsulta
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnMouseMove = gridConsultaMouseMove
  end
  object Panel2: TPanel
    Left = 0
    Top = 205
    Width = 354
    Height = 33
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object labRegistros: TLabel
      Left = 8
      Top = 10
      Width = 72
      Height = 13
      Caption = 'Registro 0 de 0'
    end
    object btnFechar: TButton
      Left = 276
      Top = 4
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = '&Fechar'
      TabOrder = 1
      OnClick = btnFecharClick
    end
    object btnLimpar: TButton
      Left = 196
      Top = 4
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = '&Limpar'
      TabOrder = 0
    end
  end
  object DSConsulta: TDataSource
    DataSet = Consulta
    Left = 128
    Top = 208
  end
  object Consulta: TQuery
    AfterScroll = ConsultaAfterScroll
    DatabaseName = 'DBLivrus'
    Left = 160
    Top = 208
  end
end
