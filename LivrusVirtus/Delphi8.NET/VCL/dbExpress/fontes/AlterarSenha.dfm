object frmAlterarSenha: TfrmAlterarSenha
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
    Caption = 'Login:'
    Left = 8
    Top = 8
    Width = 29
    Height = 13
  end
  object Label2: TLabel
    Caption = 'Nova senha:'
    Left = 8
    Top = 48
    Width = 61
    Height = 13
  end
  object Label3: TLabel
    Caption = 'Confirmar senha:'
    Left = 112
    Top = 48
    Width = 79
    Height = 13
  end
  object Label4: TLabel
    Caption = 'Senha atual:'
    Left = 112
    Top = 8
    Width = 60
    Height = 13
  end
  object btnSalvar: TButton
    Caption = '&Salvar'
    TabOrder = 4
    Left = 8
    Top = 104
    Width = 75
    Height = 25
    OnClick = btnSalvarClick
  end
  object btnLimpar: TButton
    Caption = '&Limpar'
    TabOrder = 5
    Left = 88
    Top = 104
    Width = 75
    Height = 25
    OnClick = btnLimparClick
  end
  object btnFechar: TButton
    Caption = '&Fechar'
    TabOrder = 6
    Left = 168
    Top = 104
    Width = 75
    Height = 25
    OnClick = btnFecharClick
  end
  object edtLogin: TEdit
    Enabled = False
    MaxLength = 10
    TabOrder = 0
    Left = 8
    Top = 24
    Width = 90
    Height = 21
  end
  object edtNovaSenha: TEdit
    MaxLength = 10
    PasswordChar = '*'
    TabOrder = 2
    Left = 8
    Top = 64
    Width = 90
    Height = 21
  end
  object edtConfirmarSenha: TEdit
    MaxLength = 10
    PasswordChar = '*'
    TabOrder = 3
    Left = 112
    Top = 64
    Width = 90
    Height = 21
  end
  object edtSenhaAtual: TEdit
    MaxLength = 10
    PasswordChar = '*'
    TabOrder = 1
    Left = 112
    Top = 24
    Width = 90
    Height = 21
  end
  object Arquiva: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = frmPrincipal.db
    Left = 216
    Top = 64
  end
end
