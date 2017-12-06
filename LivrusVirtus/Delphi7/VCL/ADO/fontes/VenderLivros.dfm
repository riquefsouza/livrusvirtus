object frmVenderLivros: TfrmVenderLivros
  Left = 212
  Top = 210
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
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnMouseMove = FormMouseMove
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 48
    Width = 23
    Height = 13
    Caption = 'CPF:'
  end
  object Label9: TLabel
    Left = 8
    Top = 8
    Width = 60
    Height = 13
    Caption = 'Data Venda:'
  end
  object Label2: TLabel
    Left = 136
    Top = 48
    Width = 35
    Height = 13
    Caption = 'Cliente:'
  end
  object Label3: TLabel
    Left = 8
    Top = 88
    Width = 28
    Height = 13
    Caption = 'ISBN:'
  end
  object Label5: TLabel
    Left = 293
    Top = 248
    Width = 54
    Height = 13
    Caption = 'Preço total:'
  end
  object Label6: TLabel
    Left = 136
    Top = 88
    Width = 26
    Height = 13
    Caption = 'Livro:'
  end
  object Label4: TLabel
    Left = 8
    Top = 128
    Width = 88
    Height = 13
    Caption = 'Livros para vender'
  end
  object edtCPF: TEdit
    Left = 8
    Top = 64
    Width = 121
    Height = 21
    MaxLength = 14
    TabOrder = 1
    OnExit = edtCPFExit
  end
  object edtCliente: TEdit
    Left = 136
    Top = 64
    Width = 313
    Height = 21
    Enabled = False
    MaxLength = 30
    TabOrder = 2
  end
  object edtISBN: TEdit
    Left = 8
    Top = 104
    Width = 121
    Height = 21
    MaxLength = 13
    TabOrder = 4
    OnExit = edtISBNExit
  end
  object btnPLivro: TButton
    Left = 451
    Top = 104
    Width = 19
    Height = 21
    Caption = '...'
    TabOrder = 7
    OnClick = btnPLivroClick
  end
  object btnPCliente: TButton
    Left = 451
    Top = 64
    Width = 19
    Height = 21
    Caption = '...'
    TabOrder = 3
    OnClick = btnPClienteClick
  end
  object edtDtVenda: TEdit
    Left = 8
    Top = 24
    Width = 121
    Height = 21
    Enabled = False
    MaxLength = 13
    TabOrder = 0
  end
  object lstLivros: TListBox
    Left = 8
    Top = 144
    Width = 465
    Height = 97
    ItemHeight = 13
    TabOrder = 8
    OnDblClick = lstLivrosDblClick
  end
  object edtPrecoTotal: TEdit
    Left = 352
    Top = 248
    Width = 121
    Height = 21
    Enabled = False
    MaxLength = 13
    TabOrder = 9
    Text = 'R$ 0,00'
  end
  object btnVender: TButton
    Left = 240
    Top = 278
    Width = 75
    Height = 25
    Caption = '&Vender'
    TabOrder = 10
    OnClick = btnVenderClick
  end
  object btnLimpar: TButton
    Left = 320
    Top = 278
    Width = 75
    Height = 25
    Caption = '&Limpar'
    TabOrder = 11
    OnClick = btnLimparClick
  end
  object btnFechar: TButton
    Left = 399
    Top = 278
    Width = 75
    Height = 25
    Caption = '&Fechar'
    TabOrder = 12
    OnClick = btnFecharClick
  end
  object edtLivro: TEdit
    Left = 136
    Top = 104
    Width = 289
    Height = 21
    Enabled = False
    MaxLength = 50
    TabOrder = 5
  end
  object btnAdLivros: TButton
    Left = 428
    Top = 104
    Width = 19
    Height = 21
    Caption = '+'
    TabOrder = 6
    OnClick = btnAdLivrosClick
  end
  object Consulta: TADOQuery
    Connection = frmPrincipal.db
    Parameters = <>
    Left = 160
    Top = 272
  end
  object Arquiva: TADOQuery
    Connection = frmPrincipal.db
    Parameters = <>
    Left = 200
    Top = 272
  end
end
