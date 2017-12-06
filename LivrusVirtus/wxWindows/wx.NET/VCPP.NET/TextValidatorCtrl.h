#pragma once

namespace Livrus
{
	public __gc class TextValidatorCtrl : public wx::TextCtrl
	{
    private:
      int nLocalFiltro;
  	public:
		  static int FILTER_NONE = 0;
		  static int FILTER_ALPHA = 1;
		  static int FILTER_NUMERIC = 2;
    
      TextValidatorCtrl( wx::Window* parent, int id, System::String* valor, 
        System::Drawing::Point pos, System::Drawing::Size size, long estilo, 
        int nfiltro );
      System::Void OnChar( System::Object* sender, wx::Event* e );
  };
}
