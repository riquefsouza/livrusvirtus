object frmVenderLivros: TfrmVenderLivros
  BorderStyle = bsSingle
  Caption = 'Vender Livros'
  ClientHeight = 311
  ClientWidth = 482
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Caption = 'CPF:'
    Left = 8
    Top = 48
    Width = 23
    Height = 13
  end
  object Label9: TLabel
    Caption = 'Data Venda:'
    Left = 8
    Top = 8
    Width = 60
    Height = 13
  end
  object Label2: TLabel
    Caption = 'Cliente:'
    Left = 136
    Top = 48
    Width = 35
    Height = 13
  end
  object Label3: TLabel
    Caption = 'ISBN:'
    Left = 8
    Top = 88
    Width = 28
    Height = 13
  end
  object Label5: TLabel
    Caption = 'Pre'#231'o total:'
    Left = 293
    Top = 248
    Width = 54
    Height = 13
  end
  object Label6: TLabel
    Caption = 'Livro:'
    Left = 136
    Top = 88
    Width = 26
    Height = 13
  end
  object Label4: TLabel
    Caption = 'Livros para vender'
    Left = 8
    Top = 128
    Width = 88
    Height = 13
  end
  object edtCPF: TEdit
    MaxLength = 14
    TabOrder = 1
    Left = 8
    Top = 64
    Width = 121
    Height = 21
    OnExit = edtCPFExit
  end
  object edtCliente: TEdit
    Enabled = False
    MaxLength = 30
    TabOrder = 2
    Left = 136
    Top = 64
    Width = 313
    Height = 21
  end
  object edtISBN: TEdit
    MaxLength = 13
    TabOrder = 4
    Left = 8
    Top = 104
    Width = 121
    Height = 21
    OnExit = edtISBNExit
  end
  object btnPLivro: TButton
    Caption = '...'
    TabOrder = 7
    Left = 451
    Top = 104
    Width = 19
    Height = 21
    OnClick = btnPLivroClick
  end
  object btnPCliente: TButton
    Caption = '...'
    TabOrder = 3
    Left = 451
    Top = 64
    Width = 19
    Height = 21
    OnClick = btnPClienteClick
  end
  object edtDtVenda: TEdit
    Enabled = False
    MaxLength = 13
    TabOrder = 0
    Left = 8
    Top = 24
    Width = 121
    Height = 21
  end
  object lstLivros: TListBox
    ItemHeight = 13
    TabOrder = 8
    Left = 8
    Top = 144
    Width = 465
    Height = 97
    OnDblClick = lstLivrosDblClick
  end
  object edtPrecoTotal: TEdit
    Enabled = False
    MaxLength = 13
    TabOrder = 9
    Text = 'R$ 0,00'
    Left = 352
    Top = 248
    Width = 121
    Height = 21
  end
  object btnVender: TButton
    Caption = '&Vender'
    TabOrder = 10
    Left = 240
    Top = 278
    Width = 75
    Height = 25
    OnClick = btnVenderClick
  end
  object btnLimpar: TButton
    Caption = '&Limpar'
    TabOrder = 11
    Left = 320
    Top = 278
    Width = 75
    Height = 25
    OnClick = btnLimparClick
  end
  object btnFechar: TButton
    Caption = '&Fechar'
    TabOrder = 12
    Left = 399
    Top = 278
    Width = 75
    Height = 25
    OnClick = btnFecharClick
  end
  object edtLivro: TEdit
    Enabled = False
    MaxLength = 50
    TabOrder = 5
    Left = 136
    Top = 104
    Width = 289
    Height = 21
  end
  object btnAdLivros: TButton
    Caption = '+'
    TabOrder = 6
    Left = 428
    Top = 104
    Width = 19
    Height = 21
    OnClick = btnAdLivrosClick
  end
  object Consulta: TQuery
    DatabaseName = 'DBLivrus'
    Left = 160
    Top = 272
  end
  object Arquiva: TQuery
    DatabaseName = 'DBLivrus'
    Left = 200
    Top = 272
  end
end
