// generated 2005/1/16 14:04:21 BRST by hfs@localhost.(none)
// using glademm V1.1.2
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/hfs/KDevelop/glade2/plivrus.glade
// for gtk 1.2.10 and gtkmm 1.2.10
//
// Please modify the corresponding derived classes in ./CPP/frmConsultas.cc

#include "config.h"
#include "frmConsultas.hh"

frmConsultas_glade::frmConsultas_glade(
) : Gtk::Window(GTK_WINDOW_TOPLEVEL)
{  
   
   Gtk::Window *frmConsultas = this;
   frmConsultas->set_title("");
   frmConsultas->set_modal(false);
   frmConsultas->show();
   frmConsultas->show.connect(SigC::slot(this, &frmConsultas_glade::on_frmConsultas_show));
   frmConsultas->destroy.connect(SigC::slot(this, &frmConsultas_glade::on_frmConsultas_destroy));
}

frmConsultas_glade::~frmConsultas_glade()
{  
}