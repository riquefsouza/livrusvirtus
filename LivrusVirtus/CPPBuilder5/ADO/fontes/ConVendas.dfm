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
      Top = 48
      Width = 23
      Caption = 'CPF:'
    end
    object Label9: TLabel [1]
      Left = 8
      Top = 8
      Width = 60
      Height = 13
      Caption = 'Data Venda:'
    end
    object Label1: TLabel [2]
      Left = 136
      Top = 48
      Width = 35
      Height = 13
      Caption = 'Cliente:'
    end
    object Label6: TLabel [3]
      Left = 136
      Top = 88
      Width = 26
      Height = 13
      Caption = 'Livro:'
    end
    object Label3: TLabel [4]
      Left = 8
      Top = 88
      Width = 28
      Height = 13
      Caption = 'ISBN:'
    end
    inherited edtDescricao: TEdit
      Top = 64
      Width = 121
      OnExit = edtDescricaoExit
    end
    inherited btnPesquisar: TButton
      Left = 227
      OnClick = btnPesquisarClick
    end
    object edtDtVenda: TDateTimePicker
      Left = 8
      Top = 24
      Width = 105
      Height = 21
      CalAlignment = dtaLeft
      Date = 38067.7717048148
      Time = 38067.7717048148
      ShowCheckbox = True
      Checked = False
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 2
      OnChange = edtDtVendaChange
    end
    object edtHrVenda: TDateTimePicker
      Left = 112
      Top = 24
      Width = 105
      Height = 21
      CalAlignment = dtaLeft
      Date = 38067.7788610301
      Time = 38067.7788610301
      ShowCheckbox = True
      Checked = False
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkTime
      ParseInput = False
      TabOrder = 3
      OnChange = edtHrVendaChange
    end
    object edtCliente: TEdit
      Left = 136
      Top = 64
      Width = 290
      Height = 21
      Enabled = False
      MaxLength = 30
      TabOrder = 4
    end
    object btnPCliente: TButton
      Left = 429
      Top = 64
      Width = 19
      Height = 21
      Caption = '...'
      TabOrder = 5
      OnClick = btnPClienteClick
    end
    object btnPLivro: TButton
      Left = 429
      Top = 104
      Width = 19
      Height = 21
      Caption = '...'
      TabOrder = 6
      OnClick = btnPLivroClick
    end
    object edtLivro: TEdit
      Left = 136
      Top = 104
      Width = 290
      Height = 21
      Enabled = False
      MaxLength = 50
      TabOrder = 7
    end
    object edtISBN: TEdit
      Left = 8
      Top = 104
      Width = 121
      Height = 21
      MaxLength = 13
      TabOrder = 8
      OnExit = edtISBNExit
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
      Left = 269
      Top = 4
      Width = 54
      Height = 13
      Anchors = [akRight, akBottom]
      Caption = 'Preço total:'
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
      Left = 328
      Top = 4
      Width = 121
      Height = 21
      Anchors = [akRight, akBottom]
      Enabled = False
      MaxLength = 13
      TabOrder = 2
      Text = 'R$ 0,00'
    end
  end
  inherited DSConsulta: TDataSource
    Top = 272
  end
  inherited Consulta: TADOQuery
    Top = 272
  end
  object ConsTotal: TADOQuery
    Connection = frmPrincipal.db
    Parameters = <>
    Left = 192
    Top = 272
  end
  object ConsCampo: TADOQuery
    Connection = frmPrincipal.db
    Parameters = <>
    Left = 224
    Top = 272
  end
end
