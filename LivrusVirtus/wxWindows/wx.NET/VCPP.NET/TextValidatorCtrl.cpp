#include "stdafx.h"
#include "TextValidatorCtrl.h"
#include "Login.h"

namespace Livrus
{
  TextValidatorCtrl::TextValidatorCtrl( wx::Window* parent, int id, 
    System::String* valor, System::Drawing::Point pos, 
    System::Drawing::Size size, long estilo, int nfiltro  )
  	: wx::TextCtrl(parent, id, valor, pos, size, estilo, 0, ""){
    nLocalFiltro = nfiltro;
  	EVT_CHAR( new wx::EventListener( this, OnChar ) );
  }

  System::Void TextValidatorCtrl::OnChar( System::Object* sender, 
    wx::Event* e ){
    KeyEvent* ke = dynamic_cast<KeyEvent*>(e);
    int nChave = ke->KeyCode;

    if (nLocalFiltro != FILTER_NONE) {
      if (nChave < (int)wx::KeyCode::WXK_SPACE || 
        nChave == (int)wx::KeyCode::WXK_DELETE || nChave > 255) {
        e->Skip();
      } else if (nLocalFiltro == FILTER_ALPHA) {
        if ((nChave >= 65 && nChave <= 90) || 
            (nChave >= 97 && nChave <= 122) ) {
          e->Skip();
        }
      } else if (nLocalFiltro == FILTER_NUMERIC) {
        if (nChave >= 48 && nChave <= 57) {
          e->Skip();
        }
      } else
         e->Skip();
    } else
      e->Skip();
  }
}
