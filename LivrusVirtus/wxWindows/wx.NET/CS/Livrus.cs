using System;
using System.Drawing;
using wx;

namespace Livrus
{		
	public class LivrusApp : wx.App
	{
		public override bool OnInit()
		{
      RotinasGlobais.Rotinas = new RotinasGlobais();
      ConsultasSQL.ConsSQL = new ConsultasSQL();
			frmPrincipal.fPrincipal = new frmPrincipal();

      if (RotinasGlobais.Rotinas.ConectaBanco(
        "File Name=C:\\LivrusVirtus\\bancos\\access\\Access2k_Livrus.udl")==false)
        return false;

      frmSplash.fSplash = new frmSplash(null);
      frmSplash.fSplash.Show(true);

			return true;
		}
		//---------------------------------------------------------------------
		[STAThread]
		static void Main()
		{
			LivrusApp aplicativo = new LivrusApp();
			aplicativo.Run();
		}
	}	
}
