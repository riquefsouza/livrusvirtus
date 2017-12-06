package Livrus;

import org.wxwindows.wxApp;
import org.wxwindows.wxPoint;
import org.wxwindows.wxSize;

public class LivrusApp extends wxApp{
  public boolean OnInit(){
    wxInitAllImageHandlers();

    RotinasGlobais.Rotinas = new RotinasGlobais();
    ConsultasSQL.ConsSQL = new ConsultasSQL();
    frmPrincipal.fPrincipal = new frmPrincipal();

    if (RotinasGlobais.Rotinas.ConectaBanco()==false)
      return false;

    frmSplash.fSplash = new frmSplash();
    frmSplash.fSplash.Show(true);

    //frmPrincipal.fPrincipal.Show(true);
    return true;
  }

  public static void main(String args[]){
    wxApp aplicativo = new LivrusApp();
    aplicativo.MainLoop();
  }
}
