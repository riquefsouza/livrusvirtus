inherited frmConAssuntos: TfrmConAssuntos
  Left = 339
  Top = 180
  Caption = 'Consulta de Assuntos'
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
