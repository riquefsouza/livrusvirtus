inherited frmConAssuntos: TfrmConAssuntos
  Left = 376
  Top = 190
  Caption = 'Consulta de Assuntos'
  OldCreateOrder = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    inherited Label2: TLabel
      Width = 41
      Caption = 'Assunto:'
    end
    inherited btnPesquisar: TButton
      OnClick = btnPesquisarClick
    end
  end
  inherited Panel2: TPanel
    inherited btnLimpar: TButton
      OnClick = btnLimparClick
    end
  end
end
