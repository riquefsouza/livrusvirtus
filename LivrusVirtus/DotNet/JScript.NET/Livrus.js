import Livrus;

function main(): void {
  if (frmPrincipal.fPrincipal==null) {
     frmPrincipal.fPrincipal = new frmPrincipal();
    
     frmPrincipal.fPrincipal.db = new System.Data.OleDb.OleDbConnection();
     frmPrincipal.fPrincipal.db.ConnectionString=
     "File Name=C:\\LivrusVirtus\\bancos\\access\\Access2k_Livrus.udl";
    
      Application.Run(frmPrincipal.fPrincipal);

  } else
  MessageBox.Show("A Aplicação já está sendo executada.",
  "Livrus Virtus", MessageBoxButtons.OK);
}

main();