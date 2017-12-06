object frmCadastros: TfrmCadastros
  Left = 288
  Top = 282
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
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnMouseMove = FormMouseMove
  DesignSize = (
    330
    136)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 36
    Height = 13
    Caption = 'C'#243'digo:'
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 51
    Height = 13
    Caption = 'Descri'#231#227'o:'
  end
  object btnSalvar: TButton
    Left = 8
    Top = 104
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = '&Salvar'
    Enabled = False
    TabOrder = 6
  end
  object btnExcluir: TButton
    Left = 88
    Top = 104
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = '&Excluir'
    Enabled = False
    TabOrder = 7
  end
  object btnLimpar: TButton
    Left = 168
    Top = 104
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = '&Limpar'
    TabOrder = 8
    OnClick = btnLimparClick
  end
  object btnFechar: TButton
    Left = 248
    Top = 104
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = '&Fechar'
    TabOrder = 9
    OnClick = btnFecharClick
  end
  object btnPesquisar: TButton
    Left = 248
    Top = 8
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = '&Pesquisar'
    TabOrder = 3
  end
  object btnAnterior: TButton
    Left = 248
    Top = 40
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = '&Anterior'
    Enabled = False
    TabOrder = 4
    OnClick = btnAnteriorClick
  end
  object btnProximo: TButton
    Left = 248
    Top = 72
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Pr'#243'xi&mo'
    Enabled = False
    TabOrder = 5
    OnClick = btnProximoClick
  end
  object btnNovo: TButton
    Left = 144
    Top = 24
    Width = 75
    Height = 25
    Caption = '&Novo'
    TabOrder = 1
    OnClick = btnNovoClick
  end
  object edtCodigo: TEdit
    Left = 8
    Top = 24
    Width = 121
    Height = 21
    MaxLength = 10
    TabOrder = 0
    OnExit = edtCodigoExit
  end
  object edtDescricao: TEdit
    Left = 8
    Top = 64
    Width = 217
    Height = 21
    Enabled = False
    MaxLength = 50
    TabOrder = 2
  end
  object Consulta: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 160
    Top = 64
  end
  object Arquiva: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 200
    Top = 64
  end
  object CDSConsulta: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DSPConsulta'
    Left = 80
    Top = 64
  end
  object DSPConsulta: TDataSetProvider
    DataSet = Consulta
    Left = 120
    Top = 64
  end
end
