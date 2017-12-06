inherited frmConProfissoes: TfrmConProfissoes
  Caption = 'Consulta de Profiss'#245'es'
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    inherited Label2: TLabel
      Caption = 'Profiss'#227'o:'
      Width = 48
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
