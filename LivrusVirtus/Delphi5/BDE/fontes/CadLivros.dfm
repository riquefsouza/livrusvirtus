inherited frmCadLivros: TfrmCadLivros
  Left = 137
  Top = 120
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
    Caption = 'Título:'
  end
  object Label4: TLabel [2]
    Left = 8
    Top = 88
    Width = 78
    Height = 13
    Caption = 'Ano Publicação:'
  end
  object Label5: TLabel [3]
    Left = 96
    Top = 88
    Width = 36
    Height = 13
    Caption = 'Editora:'
  end
  object Label6: TLabel [4]
    Left = 8
    Top = 128
    Width = 38
    Height = 13
    Caption = 'Volume:'
  end
  object Label7: TLabel [5]
    Left = 96
    Top = 128
    Width = 34
    Height = 13
    Caption = 'Idioma:'
  end
  object Label8: TLabel [6]
    Left = 8
    Top = 168
    Width = 56
    Height = 13
    Caption = 'Nº Páginas:'
  end
  object Label9: TLabel [7]
    Left = 8
    Top = 251
    Width = 65
    Height = 13
    Caption = 'Qtd. Estoque:'
  end
  object Label10: TLabel [8]
    Left = 8
    Top = 211
    Width = 31
    Height = 13
    Caption = 'Preço:'
  end
  object Label11: TLabel [9]
    Left = 96
    Top = 168
    Width = 41
    Height = 13
    Caption = 'Assunto:'
  end
  object Label12: TLabel [10]
    Left = 96
    Top = 251
    Width = 28
    Height = 13
    Caption = 'Autor:'
  end
  object Label3: TLabel [11]
    Left = 328
    Top = 48
    Width = 36
    Height = 13
    Caption = 'Edição:'
  end
  inherited btnSalvar: TButton
    Left = 184
    Top = 343
    TabOrder = 8
    OnClick = btnSalvarClick
  end
  inherited btnExcluir: TButton
    Left = 264
    Top = 343
    TabOrder = 14
    OnClick = btnExcluirClick
  end
  inherited btnLimpar: TButton
    Left = 344
    Top = 343
    TabOrder = 21
  end
  inherited btnFechar: TButton
    Left = 424
    Top = 343
    TabOrder = 23
  end
  inherited btnPesquisar: TButton
    Left = 424
    TabOrder = 22
    OnClick = btnPesquisarClick
  end
  inherited btnAnterior: TButton
    Left = 424
    TabOrder = 24
  end
  inherited btnProximo: TButton
    Left = 424
    TabOrder = 6
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
    TabOrder = 4
  end
  object btnPEditora: TButton [23]
    Left = 400
    Top = 104
    Width = 19
    Height = 21
    Caption = '...'
    Enabled = False
    TabOrder = 5
    OnClick = btnPEditoraClick
  end
  object edtCodEditora: TEdit [24]
    Left = 96
    Top = 104
    Width = 73
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 3
    OnExit = edtCodEditoraExit
  end
  object edtPreco: TEdit [25]
    Left = 8
    Top = 227
    Width = 81
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 13
    OnExit = edtPrecoExit
  end
  object edtCodAssunto: TEdit [26]
    Left = 96
    Top = 183
    Width = 73
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 9
    OnExit = edtCodAssuntoExit
  end
  object edtAssunto: TEdit [27]
    Left = 173
    Top = 183
    Width = 202
    Height = 21
    Enabled = False
    MaxLength = 13
    TabOrder = 10
  end
  object btnPAssunto: TButton [28]
    Left = 400
    Top = 183
    Width = 19
    Height = 21
    Caption = '...'
    Enabled = False
    TabOrder = 11
    OnClick = btnPAssuntoClick
  end
  object lstAssuntos: TListBox [29]
    Left = 96
    Top = 207
    Width = 321
    Height = 42
    Enabled = False
    ItemHeight = 13
    TabOrder = 12
    OnDblClick = lstAssuntosDblClick
  end
  object edtCodAutor: TEdit [30]
    Left = 96
    Top = 267
    Width = 73
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 15
    OnExit = edtCodAutorExit
  end
  object edtAutor: TEdit [31]
    Left = 173
    Top = 267
    Width = 202
    Height = 21
    Enabled = False
    MaxLength = 13
    TabOrder = 16
  end
  object btnPAutor: TButton [32]
    Left = 400
    Top = 267
    Width = 19
    Height = 21
    Caption = '...'
    Enabled = False
    TabOrder = 17
    OnClick = btnPAutorClick
  end
  object lstAutores: TListBox [33]
    Left = 96
    Top = 291
    Width = 321
    Height = 42
    Enabled = False
    ItemHeight = 13
    TabOrder = 18
    OnDblClick = lstAutoresDblClick
  end
  object btnAdAssuntos: TButton [34]
    Left = 376
    Top = 183
    Width = 19
    Height = 21
    Caption = '+'
    Enabled = False
    TabOrder = 19
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
    TabOrder = 7
  end
  object edtEdicao: TSpinEdit [37]
    Left = 328
    Top = 64
    Width = 89
    Height = 22
    Enabled = False
    MaxLength = 8
    MaxValue = 99999999
    MinValue = 1
    TabOrder = 25
    Value = 1
  end
  object edtAnoPubli: TSpinEdit [38]
    Left = 8
    Top = 104
    Width = 81
    Height = 22
    Enabled = False
    MaxLength = 8
    MaxValue = 2099
    MinValue = 1
    TabOrder = 26
    Value = 1
  end
  object edtVolume: TSpinEdit [39]
    Left = 8
    Top = 144
    Width = 81
    Height = 22
    Enabled = False
    MaxLength = 8
    MaxValue = 99999999
    MinValue = 1
    TabOrder = 27
    Value = 1
  end
  object edtNPaginas: TSpinEdit [40]
    Left = 8
    Top = 183
    Width = 81
    Height = 22
    MaxLength = 8
    MaxValue = 99999999
    MinValue = 1
    TabOrder = 28
    Value = 1
  end
  object edtQtdEstoque: TSpinEdit [41]
    Left = 8
    Top = 267
    Width = 81
    Height = 22
    Enabled = False
    MaxLength = 8
    MaxValue = 99999999
    MinValue = 0
    TabOrder = 29
    Value = 0
  end
  inherited Consulta: TQuery
    Left = 56
    Top = 344
  end
  inherited Arquiva: TQuery
    Left = 120
    Top = 344
  end
  object ConsLista: TQuery
    DatabaseName = 'DBLivrus'
    Left = 88
    Top = 344
  end
end
