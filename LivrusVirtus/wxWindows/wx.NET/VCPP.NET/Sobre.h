#pragma once

namespace Livrus
{
	public __gc class frmSobre : public wx::Dialog
	{
  	public:
      __value enum idt { ID_FRMSOBRE_LABBMP = 300, ID_FRMSOBRE_LABVERSAO, 
      ID_FRMSOBRE_LABDIREITOS, ID_FRMSOBRE_LABSISTEMA, ID_FRMSOBRE_BTNOK };
  		static frmSobre* fSobre;
      frmSobre( wx::Window* parent );

    private:
      wx::StaticBitmap *labBmp;
      wx::StaticText *labVersao;
      wx::StaticText *labDireitos;
      wx::StaticText *labSistema;
      wx::Button *btnOk;

      System::Void FazLayout();
  };
}
