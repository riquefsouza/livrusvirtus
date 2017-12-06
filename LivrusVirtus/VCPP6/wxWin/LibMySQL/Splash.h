#ifndef SPLASH_H
#define SPLASH_H

class CfrmSplash: public wxSplashScreen {
public:
  CfrmSplash(wxWindow *parent);
  ~CfrmSplash();

protected:
	void OnClose(wxCloseEvent& event);

private:
  void IniciaControles();

  DECLARE_EVENT_TABLE();
};

#endif


