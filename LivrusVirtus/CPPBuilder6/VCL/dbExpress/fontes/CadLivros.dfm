inherited frmCadLivros: TfrmCadLivros
  Left = 251
  Top = 143
  Caption = 'Cadastro de Livros'
  ClientHeight = 375
  ClientWidth = 506
  OldCreateOrder = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Width = 28
    Caption = 'ISBN:'
  end
  inherited Label2: TLabel
    Width = 31
    Caption = 'T'#237'tulo:'
  end
  object Label6: TLabel [2]
    Left = 8
    Top = 128
    Width = 38
    Height = 13
    Caption = 'Volume:'
  end
  object Label7: TLabel [3]
    Left = 96
    Top = 128
    Width = 34
    Height = 13
    Caption = 'Idioma:'
  end
  object Label8: TLabel [4]
    Left = 8
    Top = 168
    Width = 56
    Height = 13
    Caption = 'N'#186' P'#225'ginas:'
  end
  object Label9: TLabel [5]
    Left = 8
    Top = 251
    Width = 65
    Height = 13
    Caption = 'Qtd. Estoque:'
  end
  object Label10: TLabel [6]
    Left = 8
    Top = 211
    Width = 31
    Height = 13
    Caption = 'Pre'#231'o:'
  end
  object Label11: TLabel [7]
    Left = 96
    Top = 168
    Width = 41
    Height = 13
    Caption = 'Assunto:'
  end
  object Label12: TLabel [8]
    Left = 96
    Top = 251
    Width = 28
    Height = 13
    Caption = 'Autor:'
  end
  object Label5: TLabel [9]
    Left = 96
    Top = 88
    Width = 36
    Height = 13
    Caption = 'Editora:'
  end
  object Label4: TLabel [10]
    Left = 8
    Top = 88
    Width = 78
    Height = 13
    Caption = 'Ano Publica'#231#227'o:'
  end
  object Label3: TLabel [11]
    Left = 328
    Top = 48
    Width = 36
    Height = 13
    Caption = 'Edi'#231#227'o:'
  end
  inherited btnSalvar: TButton
    Left = 184
    Top = 343
    TabOrder = 26
    OnClick = btnSalvarClick
  end
  inherited btnExcluir: TButton
    Left = 264
    Top = 343
    TabOrder = 27
    OnClick = btnExcluirClick
  end
  inherited btnLimpar: TButton
    Left = 344
    Top = 343
    TabOrder = 28
  end
  inherited btnFechar: TButton
    Left = 424
    Top = 343
    TabOrder = 29
  end
  inherited btnPesquisar: TButton
    Left = 424
    TabOrder = 23
    OnClick = btnPesquisarClick
  end
  inherited btnAnterior: TButton
    Left = 424
    TabOrder = 24
  end
  inherited btnProximo: TButton
    Left = 424
    TabOrder = 25
  end
  inherited edtCodigo: TEdit
    MaxLength = 13
  end
  inherited edtDescricao: TEdit
    Width = 313
  end
  object edtEditora: TEdit [22]
    Left = 173
    Top = 104
    Width = 225
    Height = 21
    Enabled = False
    MaxLength = 13
    TabOrder = 6
  end
  object btnPEditora: TButton [23]
    Left = 400
    Top = 104
    Width = 19
    Height = 21
    Caption = '...'
    Enabled = False
    TabOrder = 7
  end
  object edtCodEditora: TEdit [24]
    Left = 96
    Top = 104
    Width = 73
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 5
    OnExit = edtCodEditoraExit
  end
  object edtPreco: TEdit [25]
    Left = 8
    Top = 227
    Width = 81
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 16
    OnExit = edtPrecoExit
  end
  object edtCodAssunto: TEdit [26]
    Left = 96
    Top = 183
    Width = 73
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 11
    OnExit = edtCodAssuntoExit
  end
  object edtAssunto: TEdit [27]
    Left = 173
    Top = 183
    Width = 202
    Height = 21
    Enabled = False
    MaxLength = 13
    TabOrder = 12
  end
  object btnPAssunto: TButton [28]
    Left = 400
    Top = 183
    Width = 19
    Height = 21
    Caption = '...'
    Enabled = False
    TabOrder = 14
    OnClick = btnPAssuntoClick
  end
  object lstAssuntos: TListBox [29]
    Left = 96
    Top = 207
    Width = 321
    Height = 42
    Enabled = False
    ItemHeight = 13
    TabOrder = 15
    OnDblClick = lstAssuntosDblClick
  end
  object edtCodAutor: TEdit [30]
    Left = 96
    Top = 267
    Width = 73
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 18
    OnExit = edtCodAutorExit
  end
  object edtAutor: TEdit [31]
    Left = 173
    Top = 267
    Width = 202
    Height = 21
    Enabled = False
    MaxLength = 13
    TabOrder = 19
  end
  object btnPAutor: TButton [32]
    Left = 400
    Top = 267
    Width = 19
    Height = 21
    Caption = '...'
    Enabled = False
    TabOrder = 21
    OnClick = btnPAutorClick
  end
  object lstAutores: TListBox [33]
    Left = 96
    Top = 291
    Width = 321
    Height = 42
    Enabled = False
    ItemHeight = 13
    TabOrder = 22
    OnDblClick = lstAutoresDblClick
  end
  object btnAdAssuntos: TButton [34]
    Left = 376
    Top = 183
    Width = 19
    Height = 21
    Caption = '+'
    Enabled = False
    TabOrder = 13
    OnClick = btnAdAssuntosClick
  end
  object btnAdAutores: TButton [35]
    Left = 376
    Top = 267
    Width = 19
    Height = 21
    Caption = '+'
    Enabled = False
    TabOrder = 20
    OnClick = btnAdAutoresClick
  end
  object cmbIdioma: TComboBox [36]
    Left = 96
    Top = 144
    Width = 321
    Height = 21
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 9
  end
  object edtEdicao: TCSpinEdit [37]
    Left = 328
    Top = 64
    Width = 89
    Height = 22
    Enabled = False
    MaxValue = 99999999
    TabOrder = 3
  end
  object edtAnoPubli: TCSpinEdit [38]
    Left = 8
    Top = 104
    Width = 81
    Height = 22
    Enabled = False
    MaxValue = 999999999
    TabOrder = 4
  end
  object edtVolume: TCSpinEdit [39]
    Left = 8
    Top = 144
    Width = 81
    Height = 22
    Enabled = False
    MaxValue = 999999999
    TabOrder = 8
  end
  object edtNPaginas: TCSpinEdit [40]
    Left = 8
    Top = 184
    Width = 81
    Height = 22
    Enabled = False
    MaxValue = 999999999
    TabOrder = 10
  end
  object edtQtdEstoque: TCSpinEdit [41]
    Left = 8
    Top = 267
    Width = 81
    Height = 22
    Enabled = False
    MaxValue = 999999999
    TabOrder = 17
  end
  inherited Consulta: TSQLQuery
    Left = 96
    Top = 344
  end
  inherited Arquiva: TSQLQuery
    Left = 136
    Top = 344
  end
  inherited CDSConsulta: TClientDataSet
    Left = 16
    Top = 304
  end
  inherited DSPConsulta: TDataSetProvider
    Left = 56
    Top = 304
  end
  object ConsLista: TSQLQuery
    NoMetadata = True
    SQLConnection = frmPrincipal.db
    Params = <>
    Left = 56
    Top = 344
  end
end
