unit TextValidatorCtrl;

interface

uses
  System.Drawing, wx;

type
  TTextValidatorCtrl = class(wx.TextCtrl)
  private
    nLocalFiltro: integer;
  public
    constructor Create(parent: wx.Window; id: integer; valor: string;
      pos: System.Drawing.Point; size: System.Drawing.Size;
      estilo, nfiltro: integer);
    procedure OnChar(sender: System.Object; e: wx.Event);
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(TTextValidatorCtrl))]

const
	FILTER_NONE: integer = 0;
	FILTER_ALPHA: integer = 1;
	FILTER_NUMERIC: integer = 2;

implementation

constructor TTextValidatorCtrl.Create(parent: wx.Window; id: integer;
  valor: string; pos: System.Drawing.Point; size: System.Drawing.Size;
  estilo, nfiltro: integer);
begin
  inherited Create(parent, id, valor, pos, size, estilo, nil, '');

  nLocalFiltro := nfiltro;
	EVT_CHAR( OnChar );
end;

procedure TTextValidatorCtrl.OnChar(sender: System.Object; e: wx.Event);
var ke: wx.KeyEvent;
  nChave: integer;
begin
  ke := wx.KeyEvent(e);
  nChave := ke.KeyCode;

  if (nLocalFiltro <> FILTER_NONE) then begin
    if (nChave < integer(wx.KeyCode.WXK_SPACE)) or (nChave = integer(wx.KeyCode.WXK_DELETE))
      or (nChave > 255) then
      e.Skip()
    else if (nLocalFiltro = FILTER_ALPHA) then begin
      if ((nChave >= 65) and (nChave <= 90)) or
         ((nChave >= 97) and (nChave <= 122))  then
        e.Skip();
    end else if (nLocalFiltro = FILTER_NUMERIC) then begin
      if (nChave >= 48) and (nChave <= 57) then
        e.Skip();
    end else
      e.Skip();
  end else
    e.Skip();
end;

end.
