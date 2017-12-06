#include "stdafx.h"
#include "Sobre.h"

namespace Livrus
{
  frmSobre::frmSobre( wx::Window* parent )
   : wx::Dialog(parent, -1, "Sobre o Sistema", System::Drawing::Point(498, 310), 
      System::Drawing::Size(306, 240), wxDEFAULT_DIALOG_STYLE,"") {

    this->SetIcon(new wx::Icon( "xpms/livrus.xpm" ));
    this->Centre(wx::Orientation::wxBOTH);

  	labBmp = new wx::StaticBitmap(this, (int)idt::ID_FRMSOBRE_LABBMP, 
      new wx::Bitmap("xpms/livrusvirtus.xpm"),
      System::Drawing::Point(24, 20), System::Drawing::Size(254, 72));
  	labVersao = new wx::StaticText(this, (int)idt::ID_FRMSOBRE_LABVERSAO, 
      "Versão: 1.0.0", System::Drawing::Point(200, 96), System::Drawing::Size(63, 13) );
  	labDireitos = new wx::StaticText(this, (int)idt::ID_FRMSOBRE_LABDIREITOS, 
      "Todos os diretos reservados para: Henrique F. de Souza", 
      System::Drawing::Point(16, 112), System::Drawing::Size(266, 13) );
  	labSistema = new wx::StaticText(this, (int)idt::ID_FRMSOBRE_LABSISTEMA, 
      "Sistema integrante do projeto Livrus Virtus, versão programada em VCPP.NET usando a wx.NET.", 
      System::Drawing::Point(16, 131), System::Drawing::Size(264, 29), wx::Alignment::wxALIGN_CENTRE);
  	btnOk = new wx::Button(this, wxID_OK, "&Ok", 
      System::Drawing::Point(111, 180), System::Drawing::Size(75, 25));
  
  	btnOk->SetDefault();
  	FazLayout();
  }

  System::Void frmSobre::FazLayout() {
  	wx::BoxSizer *sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
  	wx::StaticBoxSizer *sizer_2 = new wx::StaticBoxSizer(
      new wx::StaticBox(this, -1,""), wx::Orientation::wxVERTICAL);
  	sizer_2->Add(labBmp, 0, wx::Alignment::wxALIGN_CENTER_HORIZONTAL, 0);
  	sizer_2->Add(labVersao, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
  	sizer_2->Add(labDireitos, 0, wx::Direction::wxALL, 2);
  	sizer_2->Add(labSistema, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_CENTER_HORIZONTAL|
      wx::Alignment::wxALIGN_CENTER_VERTICAL, 2);
  	sizer_1->Add(sizer_2, 1, wx::Direction::wxALL|wx::Stretch::wxEXPAND, 6);
  	sizer_1->Add(btnOk, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_CENTER_HORIZONTAL, 4);
  	this->SetSizer(sizer_1);
  	sizer_1->SetSizeHints(this);
  	sizer_1->Fit(this);
  	this->Layout();
  }
}
