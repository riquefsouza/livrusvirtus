inherited frmCadLivros: TfrmCadLivros
  Caption = 'Cadastro de Livros'
  ClientHeight = 375
  ClientWidth = 506
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Label1: TLabel
    Caption = 'ISBN:'
    Width = 28
  end
  inherited Label2: TLabel
    Caption = 'T'#237'tulo:'
    Width = 31
  end
  object Label4: TLabel [2]
    Caption = 'Ano Publica'#231#227'o:'
    Left = 8
    Top = 88
    Width = 78
    Height = 13
  end
  object Label5: TLabel [3]
    Caption = 'Editora:'
    Left = 96
    Top = 88
    Width = 36
    Height = 13
  end
  object Label6: TLabel [4]
    Caption = 'Volume:'
    Left = 8
    Top = 128
    Width = 38
    Height = 13
  end
  object Label7: TLabel [5]
    Caption = 'Idioma:'
    Left = 96
    Top = 128
    Width = 34
    Height = 13
  end
  object Label8: TLabel [6]
    Caption = 'N'#186' P'#225'ginas:'
    Left = 8
    Top = 168
    Width = 56
    Height = 13
  end
  object Label9: TLabel [7]
    Caption = 'Qtd. Estoque:'
    Left = 8
    Top = 251
    Width = 65
    Height = 13
  end
  object Label10: TLabel [8]
    Caption = 'Pre'#231'o:'
    Left = 8
    Top = 211
    Width = 31
    Height = 13
  end
  object Label11: TLabel [9]
    Caption = 'Assunto:'
    Left = 96
    Top = 168
    Width = 41
    Height = 13
  end
  object Label12: TLabel [10]
    Caption = 'Autor:'
    Left = 96
    Top = 251
    Width = 28
    Height = 13
  end
  object Label3: TLabel [11]
    Caption = 'Edi'#231#227'o:'
    Left = 328
    Top = 48
    Width = 36
    Height = 13
  end
  inherited btnSalvar: TButton
    TabOrder = 17
    Left = 184
    Top = 343
    OnClick = btnSalvarClick
  end
  inherited btnExcluir: TButton
    TabOrder = 18
    Left = 264
    Top = 343
    OnClick = btnExcluirClick
  end
  inherited btnLimpar: TButton
    TabOrder = 25
    Left = 344
    Top = 343
  end
  inherited btnFechar: TButton
    TabOrder = 27
    Left = 424
    Top = 343
  end
  inherited btnPesquisar: TButton
    TabOrder = 26
    Left = 424
    OnClick = btnPesquisarClick
  end
  inherited btnAnterior: TButton
    TabOrder = 28
    Left = 424
  end
  inherited btnProximo: TButton
    TabOrder = 16
    Left = 424
  end
  inherited edtCodigo: TEdit
    MaxLength = 13
  end
  inherited edtDescricao: TEdit
    Width = 313
  end
  object edtEditora: TEdit [22]
    Enabled = False
    MaxLength = 13
    TabOrder = 6
    Left = 173
    Top = 104
    Width = 225
    Height = 21
  end
  object btnPEditora: TButton [23]
    Caption = '...'
    Enabled = False
    TabOrder = 7
    Left = 400
    Top = 104
    Width = 19
    Height = 21
    OnClick = btnPEditoraClick
  end
  object edtCodEditora: TEdit [24]
    Enabled = False
    MaxLength = 10
    TabOrder = 5
    Left = 96
    Top = 104
    Width = 73
    Height = 21
    OnExit = edtCodEditoraExit
  end
  object edtPreco: TEdit [25]
    Enabled = False
    MaxLength = 10
    TabOrder = 15
    Left = 8
    Top = 227
    Width = 81
    Height = 21
    OnExit = edtPrecoExit
  end
  object edtCodAssunto: TEdit [26]
    Enabled = False
    MaxLength = 10
    TabOrder = 11
    Left = 96
    Top = 183
    Width = 73
    Height = 21
    OnExit = edtCodAssuntoExit
  end
  object edtAssunto: TEdit [27]
    Enabled = False
    MaxLength = 13
    TabOrder = 12
    Left = 173
    Top = 183
    Width = 202
    Height = 21
  end
  object btnPAssunto: TButton [28]
    Caption = '...'
    Enabled = False
    TabOrder = 13
    Left = 400
    Top = 183
    Width = 19
    Height = 21
    OnClick = btnPAssuntoClick
  end
  object lstAssuntos: TListBox [29]
    Enabled = False
    ItemHeight = 13
    TabOrder = 14
    Left = 96
    Top = 207
    Width = 321
    Height = 42
    OnDblClick = lstAssuntosDblClick
  end
  object edtCodAutor: TEdit [30]
    Enabled = False
    MaxLength = 10
    TabOrder = 19
    Left = 96
    Top = 267
    Width = 73
    Height = 21
    OnExit = edtCodAutorExit
  end
  object edtAutor: TEdit [31]
    Enabled = False
    MaxLength = 13
    TabOrder = 20
    Left = 173
    Top = 267
    Width = 202
    Height = 21
  end
  object btnPAutor: TButton [32]
    Caption = '...'
    Enabled = False
    TabOrder = 21
    Left = 400
    Top = 267
    Width = 19
    Height = 21
    OnClick = btnPAutorClick
  end
  object lstAutores: TListBox [33]
    Enabled = False
    ItemHeight = 13
    TabOrder = 22
    Left = 96
    Top = 291
    Width = 321
    Height = 42
    OnDblClick = lstAutoresDblClick
  end
  object btnAdAssuntos: TButton [34]
    Caption = '+'
    Enabled = False
    TabOrder = 23
    Left = 376
    Top = 183
    Width = 19
    Height = 21
    OnClick = btnAdAssuntosClick
  end
  object btnAdAutores: TButton [35]
    Caption = '+'
    Enabled = False
    TabOrder = 24
    Left = 376
    Top = 267
    Width = 19
    Height = 21
    OnClick = btnAdAutoresClick
  end
  object cmbIdioma: TComboBox [36]
    Style = csDropDownList
    Enabled = False
    ItemHeight = 13
    TabOrder = 9
    Left = 96
    Top = 144
    Width = 321
    Height = 21
  end
  object edtEdicao: TEdit [37]
    Enabled = False
    TabOrder = 3
    Text = '1'
    Left = 328
    Top = 64
    Width = 89
    Height = 21
    OnExit = edtEdicaoExit
  end
  object edtAnoPubli: TEdit [38]
    Enabled = False
    TabOrder = 4
    Text = '0'
    Left = 8
    Top = 104
    Width = 81
    Height = 21
    OnExit = edtAnoPubliExit
  end
  object edtVolume: TEdit [39]
    Enabled = False
    TabOrder = 8
    Text = '1'
    Left = 8
    Top = 144
    Width = 81
    Height = 21
    OnExit = edtVolumeExit
  end
  object edtNPaginas: TEdit [40]
    Enabled = False
    TabOrder = 10
    Text = '1'
    Left = 8
    Top = 183
    Width = 81
    Height = 21
    OnExit = edtNPaginasExit
  end
  object edtQtdEstoque: TEdit [41]
    Enabled = False
    TabOrder = 29
    Text = '0'
    Left = 8
    Top = 267
    Width = 81
    Height = 21
    OnExit = edtQtdEstoqueExit
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