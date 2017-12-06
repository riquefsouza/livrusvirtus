using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class TextValidatorCtrl : wx.TextCtrl
	{
		public static int FILTER_NONE = 0;
		public static int FILTER_ALPHA = 1;
		public static int FILTER_NUMERIC = 2;
    private int nLocalFiltro;

    public TextValidatorCtrl(wx.Window parent, int id, System.String valor, 
      System.Drawing.Point pos, System.Drawing.Size size, long estilo, int nfiltro)
      : base(parent, id, valor, pos, size, estilo, null, "") {
      
      nLocalFiltro = nfiltro;
      EVT_CHAR(new EventListener( OnChar ));
		}

		public void OnChar( object sender, Event e )	{
      KeyEvent ke = (KeyEvent) e;
      int nChave = ke.KeyCode;

      if (nLocalFiltro != FILTER_NONE) {
        if (nChave < (int)wx.KeyCode.WXK_SPACE || 
          nChave == (int)wx.KeyCode.WXK_DELETE || nChave > 255) {
          e.Skip();
        } else if (nLocalFiltro == FILTER_ALPHA) {
          if ((nChave >= 65 && nChave <= 90) || 
              (nChave >= 97 && nChave <= 122) ) {
            e.Skip();
          }
        } else if (nLocalFiltro == FILTER_NUMERIC) {
          if (nChave >= 48 && nChave <= 57) {
            e.Skip();
          }
        } else
           e.Skip();
      } else
        e.Skip();
		}

	}
}
