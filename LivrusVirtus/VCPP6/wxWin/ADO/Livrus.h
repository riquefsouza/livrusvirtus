#ifndef LIVRUS_H
#define LIVRUS_H

#include <wx/snglinst.h>

class CLivrusApp : public wxApp
{
public:
    bool OnInit();
    int OnExit();
private:
    wxSingleInstanceChecker *checaInstanciaUnica;
};

#endif

