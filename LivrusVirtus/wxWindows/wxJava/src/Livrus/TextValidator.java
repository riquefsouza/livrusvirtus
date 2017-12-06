package Livrus;

import org.wxwindows.wxKeyEvent;
import org.wxwindows.wxKeyListener;
import org.wxwindows.wxObject;
import org.wxwindows.wxValidator;
import org.wxwindows.wxWindow;
import org.wxwindows.wxTextCtrl;

public class TextValidator
    extends wxValidator {
  public static int FILTER_NONE = 0;
  public static int FILTER_ALPHA = 1;
  public static int FILTER_NUMERIC = 2;
  private int nLocalFiltro, nLocalMaxTam, nTam;
  private wxTextCtrl edtLocal;

  public TextValidator(wxTextCtrl edt, int nfiltro, int nMaxTam) {
    super();
    edtLocal = edt;
    nLocalFiltro = nfiltro;
    nLocalMaxTam = nMaxTam;
    nTam = 0;
    EVT_CHAR(new OnChar());
  }

  public wxObject Clone() {
    return new TextValidator(edtLocal, nLocalFiltro, nLocalMaxTam);
  }

  public boolean Validate(wxWindow window) {
    return false;
  }

  private class OnChar
      implements wxKeyListener {
    public void handleEvent(wxKeyEvent event) {
        int key = event.GetKeyCode();
        nTam = edtLocal.GetValue().length();
        if ( (key == WXK_LEFT) || (key == WXK_RIGHT) || (key == WXK_HOME) ||
             (key == WXK_END)) {
          event.Skip();
          return;
        }
        if ( (key == WXK_BACK) || (key == WXK_DELETE)) {
          if (nTam > 0)
            nTam--;
          event.Skip();
          return;
        }
        if ( (key < WXK_SPACE) || (key > 255)) {
          if (nTam < nLocalMaxTam){
            nTam++;
            event.Skip();
          }
          return;
        }
      if (nLocalFiltro != FILTER_NONE) {
        char ch = (char) key;
        if ( (nLocalFiltro == FILTER_ALPHA) && Character.isLetter(ch)) {
          if (nTam < nLocalMaxTam){
            nTam++;
            event.Skip();
          }
          return;
        }
        if ( (nLocalFiltro == FILTER_NUMERIC) && Character.isDigit(ch)) {
          if (nTam < nLocalMaxTam){
            nTam++;
            event.Skip();
          }
          return;
        }
        if (!wxValidator.IsSilent()) {
          wxBell();
        }
        return;
      } else {
        if (nTam < nLocalMaxTam){
          nTam++;
          event.Skip();
        }
        return;
      }

    }
  }

  public boolean TransferFromWindow() {
    return true;
  }

  public boolean TransferToWindow() {
    return true;
  }

}
