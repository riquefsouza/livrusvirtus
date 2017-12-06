inherited frmConClientes: TfrmConClientes
  Caption = 'Consulta de Clientes'
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inherited Panel1: TPanel
    inherited Label2: TLabel
      Caption = 'Cliente:'
      Width = 37
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
