inherited frmConEnderecos: TfrmConEnderecos
  Caption = 'Consulta de Endere'#231'os'
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    inherited Label2: TLabel
      Caption = 'Logradouro:'
      Width = 59
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
