//Titulo:    Livrus Virtus
//Versao:    1.0.0
//Autor:     Henrique Figueiredo de Souza
//Linguagem: JAVA

package Livrus;

import javax.swing.*;

public class Livrus {
  boolean packFrame = false;

  //Constroi a aplicacao
  public Livrus() {
    try {
     RotinasGlobais.Rotinas = new RotinasGlobais();
     frmPrincipal.fPrincipal = new frmPrincipal();

     if (packFrame)
      frmPrincipal.fPrincipal.pack();
     else
      frmPrincipal.fPrincipal.validate();

     RotinasGlobais.Rotinas.CentralizaFrm(frmPrincipal.fPrincipal);
    }catch (Exception ex) {
      ex.printStackTrace();
    }
  }

  public static void main(String[] args) {
    try  {

      //UIManager.setLookAndFeel(new com.sun.java.swing.plaf.windows.WindowsLookAndFeel());
      //UIManager.setLookAndFeel(new com.sun.java.swing.plaf.motif.MotifLookAndFeel());
      UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
      //UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
    }
    catch (Exception ex) {
      System.err.println("Erro: Carregando Look&Feel: " + ex);
    }
    new Livrus();
  }
}
