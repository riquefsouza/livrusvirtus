object frmAlterarSenha: TfrmAlterarSenha
  Left = 329
  Top = 384
  BorderStyle = bsSingle
  Caption = 'Altera'#231#227'o de Senha'
  ClientHeight = 137
  ClientWidth = 251
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
    Top = 8
    Width = 29
    Height = 13
    Caption = 'Login:'
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 61
    Height = 13
    Caption = 'Nova senha:'
  end
  object Label3: TLabel
    Left = 112
    Top = 48
    Width = 79
    Height = 13
    Caption = 'Confirmar senha:'
  end
  object Label4: TLabel
    Left = 112
    Top = 8
    Width = 60
    Height = 13
    Caption = 'Senha atual:'
  end
  object btnSalvar: TButton
    Left = 8
    Top = 104
    Width = 75
    Height = 25
    Caption = '&Salvar'
    TabOrder = 4
    OnClick = btnSalvarClick
  end
  object btnLimpar: TButton
    Left = 88
    Top = 104
    Width = 75
    Height = 25
    Caption = '&Limpar'
    TabOrder = 5
    OnClick = btnLimparClick
  end
  object btnFechar: TButton
    Left = 168
    Top = 104
    Width = 75
    Height = 25
    Caption = '&Fechar'
    TabOrder = 6
    OnClick = btnFecharClick
  end
  object edtLogin: TEdit
    Left = 8
    Top = 24
    Width = 90
    Height = 21
    Enabled = False
    MaxLength = 10
    TabOrder = 0
  end
  object edtNovaSenha: TEdit
    Left = 8
    Top = 64
    Width = 90
    Height = 21
    MaxLength = 10
    PasswordChar = '*'
    TabOrder = 2
  end
  object edtConfirmarSenha: TEdit
    Left = 112
    Top = 64
    Width = 90
    Height = 21
    MaxLength = 10
    PasswordChar = '*'
    TabOrder = 3
  end
  object edtSenhaAtual: TEdit
    Left = 112
    Top = 24
    Width = 90
    Height = 21
    MaxLength = 10
    PasswordChar = '*'
    TabOrder = 1
  end
  object Arquiva: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 216
    Top = 64
  end
end
