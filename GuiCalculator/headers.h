#include <wx/wxprec.h>
#include "enum.h"

#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};


class MyFrame : public wxFrame
{
public:
  MyFrame(const wxString& title);

  wxBoxSizer *sizer;
  wxGridSizer *gs;
  wxTextCtrl *display;

private:
  void onHello(wxCommandEvent& event);
  void onExit(wxCommandEvent& event);
  void onAbout(wxCommandEvent& event);
  void onOneClick(wxCommandEvent& event);
  void onTwoClick(wxCommandEvent& event);
  void onThreeClick(wxCommandEvent& event);
  void onFourClick(wxCommandEvent& event);
  void onFiveClick(wxCommandEvent& event);
  void onSixClick(wxCommandEvent& event);
  void onSevenClick(wxCommandEvent& event);
  void onEightClick(wxCommandEvent& event);
  void onNineClick(wxCommandEvent& event);
  void onZeroClick(wxCommandEvent& event);
  void onDecimalClick(wxCommandEvent& event);

  void onPlusClick(wxCommandEvent& event);
  void onMinusClick(wxCommandEvent& event);
  void onMultiplyClick(wxCommandEvent& event);
  void onDivideClick(wxCommandEvent& event);
  void onRootClick(wxCommandEvent& event);
  void onPowClick(wxCommandEvent& event);
  void onEqualClick(wxCommandEvent& event);

  void onClearClick(wxCommandEvent& event);
  void onClearEntryClick(wxCommandEvent& event);
};

