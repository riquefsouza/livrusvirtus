inherited frmConVendas: TfrmConVendas
  Caption = 'Consulta de Vendas Realizadas'
  ClientHeight = 305
  ClientWidth = 457
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    Width = 457
    Height = 137
    inherited Label2: TLabel
      Caption = 'CPF:'
      Top = 48
      Width = 23
    end
    object Label9: TLabel [1]
      Caption = 'Data Venda:'
      Left = 8
      Top = 8
      Width = 60
      Height = 13
    end
    object Label1: TLabel [2]
      Caption = 'Cliente:'
      Left = 136
      Top = 48
      Width = 37
      Height = 13
    end
    object Label3: TLabel [3]
      Caption = 'ISBN:'
      Left = 8
      Top = 88
      Width = 27
      Height = 13
    end
    object Label6: TLabel [4]
      Caption = 'Livro:'
      Left = 136
      Top = 88
      Width = 27
      Height = 13
    end
    inherited edtDescricao: TEdit
      TabOrder = 3
      Top = 64
      Width = 121
      OnExit = edtDescricaoExit
    end
    inherited btnPesquisar: TButton
      TabOrder = 2
      Left = 227
      OnClick = btnPesquisarClick
    end
    object edtDtVenda: TDateTimePicker
      Date = 38067.7717048148
      Time = 38067.7717048148
      ShowCheckbox = True
      TabOrder = 0
      Left = 8
      Top = 24
      Width = 105
      Height = 21
      OnChange = edtDtVendaChange
    end
    object edtHrVenda: TDateTimePicker
      Date = 38067.7788610301
      Time = 38067.7788610301
      ShowCheckbox = True
      Kind = dtkTime
      TabOrder = 1
      Left = 112
      Top = 24
      Width = 105
      Height = 21
      OnChange = edtHrVendaChange
    end
    object edtCliente: TEdit
      Enabled = False
      MaxLength = 30
      TabOrder = 4
      Left = 136
      Top = 64
      Width = 290
      Height = 21
    end
    object btnPCliente: TButton
      Caption = '...'
      TabOrder = 5
      Left = 429
      Top = 64
      Width = 19
      Height = 21
      OnClick = btnPClienteClick
    end
    object edtISBN: TEdit
      MaxLength = 13
      TabOrder = 6
      Left = 8
      Top = 104
      Width = 121
      Height = 21
      OnExit = edtISBNExit
    end
    object edtLivro: TEdit
      Enabled = False
      MaxLength = 50
      TabOrder = 7
      Left = 136
      Top = 104
      Width = 290
      Height = 21
    end
    object btnPLivro: TButton
      Caption = '...'
      TabOrder = 8
      Left = 429
      Top = 104
      Width = 19
      Height = 21
      OnClick = btnPLivroClick
    end
  end
  inherited gridConsulta: TDBGrid
    Top = 137
    Width = 457
    Height = 103
  end
  inherited Panel2: TPanel
    Top = 240
    Width = 457
    Height = 65
    inherited labRegistros: TLabel
      Top = 36
    end
    object Label5: TLabel [1]
      Anchors = [akRight, akBottom]
      Caption = 'Pre'#231'o total:'
      Left = 269
      Top = 4
      Width = 56
      Height = 13
    end
    inherited btnFechar: TButton
      Left = 379
      Top = 36
    end
    inherited btnLimpar: TButton
      Left = 299
      Top = 36
      OnClick = btnLimparClick
    end
    object edtPrecoTotal: TEdit
      Anchors = [akRight, akBottom]
      Enabled = False
      MaxLength = 13
      TabOrder = 2
      Text = 'R$ 0,00'
      Left = 328
      Top = 4
      Width = 121
      Height = 21
    end
  end
  inherited DSConsulta: TDataSource
    Left = 112
    Top = 276
  end
  inherited Consulta: TSQLQuery
    Left = 144
    Top = 276
  end
  inherited CDSConsulta: TClientDataSet
    Left = 112
    Top = 240
  end
  inherited DSPConsulta: TDataSetProvider
    Left = 152
    Top = 240
  end
  object ConsTotal: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 176
    Top = 276
  end
  object ConsCampo: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 208
    Top = 276
  end
end
