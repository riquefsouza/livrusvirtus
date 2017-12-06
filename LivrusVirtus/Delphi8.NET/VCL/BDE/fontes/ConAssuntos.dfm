inherited frmConAssuntos: TfrmConAssuntos
  Caption = 'Consulta de Assuntos'
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    inherited Label2: TLabel
      Caption = 'Assunto:'
      Width = 43
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
