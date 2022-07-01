// For compilers that support precompilation, includes "wx/wx.h".
#include <iostream>
#include <string>
#include <wx/wxprec.h>

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


enum
{
  ID_Hello    = 0,
  ID_ONE      = 1,
  ID_TWO      = 2,
  ID_THREE    = 3,
  ID_FOUR     = 4,
  ID_FIVE     = 5,
  ID_SIX      = 6,
  ID_SEVEN    = 7,
  ID_EIGHT    = 8,
  ID_NINE     = 9,
  ID_ZERO     = 10,
  ID_DECIMAL  = 11,
  ID_PLUS     = 12,
  ID_MINUS    = 13,
  ID_MULT     = 14,
  ID_DIVIDE   = 15,
  ID_POWER    = 16,
  ID_ROOT     = 17,
  ID_EQUAL    = 18,
  ID_CLEAR    = 19,
  ID_CLEARE   = 20,

  ID_RESULT_TEXT_CONTROL = 21
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
  MyFrame *frame = new MyFrame(wxT("Calculator"));
  frame->Show(true);
  return true;
}

MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(270, 400))
{
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");
  SetMenuBar( menuBar );

  CreateStatusBar();
  SetStatusText("Welcome to my First GUI!");

  Bind(wxEVT_MENU, &MyFrame::onHello, this, ID_Hello);
  Bind(wxEVT_MENU, &MyFrame::onAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &MyFrame::onExit, this, wxID_EXIT);



  wxTextValidator validator(wxFILTER_INCLUDE_CHAR_LIST);

  wxArrayString list;

  wxString valid_chars(wxT("0123456789."));
  size_t len = valid_chars.Length();
  for (size_t i=0; i<len; i++)
      list.Add(wxString(valid_chars.GetChar(i)));

  validator.SetIncludes(list);


  sizer = new wxBoxSizer(wxVERTICAL);

  display = new wxTextCtrl(this, ID_RESULT_TEXT_CONTROL, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), 0, validator);

  sizer->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);
  gs = new wxGridSizer(5, 4, 3, 3);

  //calculator grid
  gs->Add(new wxButton(this, ID_CLEAR, wxT("C")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_CLEARE, wxT("CE")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_ROOT, wxT("sqrt")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_POWER, wxT("pow")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_SEVEN, wxT("7")), 0, wxEXPAND); 
  gs->Add(new wxButton(this, ID_EIGHT, wxT("8")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_NINE, wxT("9")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_DIVIDE, wxT("/")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_FOUR, wxT("4")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_FIVE, wxT("5")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_SIX, wxT("6")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_MULT, wxT("*")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_ONE, wxT("1")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_TWO, wxT("2")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_THREE, wxT("3")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_MINUS, wxT("-")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_ZERO, wxT("0")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_DECIMAL, wxT(".")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_EQUAL, wxT("=")), 0, wxEXPAND);
  gs->Add(new wxButton(this, ID_PLUS, wxT("+")), 0, wxEXPAND);

  //mouse-click event listeners for grid
  Connect(ID_ONE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onOneClick));
  Connect(ID_TWO, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onTwoClick));
  Connect(ID_THREE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onThreeClick));
  Connect(ID_FOUR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onFourClick));
  Connect(ID_FIVE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onFiveClick));
  Connect(ID_SIX, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onSixClick));
  Connect(ID_SEVEN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onSevenClick));
  Connect(ID_EIGHT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onEightClick));
  Connect(ID_NINE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onNineClick));
  Connect(ID_ZERO, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onZeroClick));
  Connect(ID_DECIMAL, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onDecimalClick));

  Connect(ID_PLUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onPlusClick));
  Connect(ID_MINUS, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onMinusClick));
  Connect(ID_MULT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onMultiplyClick));
  Connect(ID_DIVIDE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onDivideClick));
  Connect(ID_POWER, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onPowClick));
  Connect(ID_ROOT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onRootClick));


  Connect(ID_EQUAL, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onEqualClick));
  Connect(ID_CLEAR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onClearClick));
  Connect(ID_CLEARE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::onClearEntryClick));

  //TODO: add keyboard listeners for Numpad_K for operator functions.


  sizer->Add(gs, 1, wxEXPAND);
  SetSizer(sizer);
  SetMinSize(wxSize(270, 220));

  Centre();
}


void MyFrame::onExit(wxCommandEvent& event)
{
  Close(true);
}

void MyFrame::onAbout(wxCommandEvent& event)
{
  wxMessageBox("This is a wxWidgets Hello World example",
               "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::onHello(wxCommandEvent& event)
{
  wxLogMessage("Hello world from wxWidgets!");
}


std::string first{}, last{}, result{};
// char last_op{};
bool last_op;
int operand1{}, operand2{}, operators{};
float answer{};


void MyFrame::onOneClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("1");
  }
  else
  {
    display->AppendText("1");
  }
}


void MyFrame::onTwoClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("2");
  }
  // else if (last_op == '+')
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("2");
  }
}


void MyFrame::onThreeClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("3");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("3");
  }
}


void MyFrame::onFourClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("4");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("4");
  }
}


void MyFrame::onFiveClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("5");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("5");
  }
}


void MyFrame::onSixClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("6");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("6");
  }
}


void MyFrame::onSevenClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("7");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("7");
  }
}


void MyFrame::onEightClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("8");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("8");
  }
}


void MyFrame::onNineClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("9");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("9");
  }
}


void MyFrame::onZeroClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue("0");
  }
  else if (last_op)
  {
    display->SetValue(result);
  }
  else
  {
    display->AppendText("0");
  }
}


void MyFrame::onDecimalClick(wxCommandEvent& event)
{
  if (display->GetValue() == "")
  {
    display->SetValue(".");
  }
  else
  {
    display->AppendText(".");
  }
}



/* 
TODO: currently, only round numbers are utilized for most functions.
Need to specify int vs float variables for operands and if-conditionals
Might need to have a second switch case with second "operators" variable.
*/

void MyFrame::onPlusClick(wxCommandEvent& event)
{
  // if (last_op == '+')
  if (last_op)
  {
    last = display->GetValue();
    operand2 = wxAtoi(last);
    answer = float(operand1) + float(operand2);
    result = wxString::Format(wxT("%g"), answer);
    display->SetValue(result);
    // last_op == '+';
    last_op = true;
  }
  else
  {
    first = display->GetValue();
    operand1 = wxAtoi(first);
    operators = 1; // +
    display->SetValue("");
    // last_op = '+';
    last_op = true;
  }
}


void MyFrame::onMinusClick(wxCommandEvent& event)
{
  first = display->GetValue();
  operand1 = wxAtoi(first);
  operators = 2; // -
  display->SetValue("");  
}


void MyFrame::onMultiplyClick(wxCommandEvent& event)
{
  first = display->GetValue();
  operand1 = wxAtoi(first);
  operators = 3; // +
  display->SetValue("");  
}


void MyFrame::onDivideClick(wxCommandEvent& event)
{
  first = display->GetValue();
  operand1 = wxAtoi(first);
  operators = 4; // +
  display->SetValue("");  
}


void MyFrame::onRootClick(wxCommandEvent& event)
{
  first = display->GetValue();
  operand1 = wxAtoi(first);
  operators = 5; // +
  display->SetValue("");  
}


void MyFrame::onPowClick(wxCommandEvent& event)
{
  first = display->GetValue();
  operand1 = wxAtoi(first);
  operators = 6; // +
  display->SetValue("");
}


void MyFrame::onEqualClick(wxCommandEvent& event)
{
  // last_op = '=';
  last_op = true;
  last = display->GetValue();
  operand2 = wxAtoi(last);
  switch (operators)
  {
    case 1:
      answer = float(operand1) + float(operand2);
      result = wxString::Format(wxT("%g"), answer);
      display->SetValue(result);
      break;
    case 2:
      answer = float(operand1) - float(operand2);
      result = wxString::Format(wxT("%g"), answer);
      display->SetValue(result);
      break;
    case 3:
      answer = float(operand1) * float(operand2);
      result = wxString::Format(wxT("%g"), answer);
      display->SetValue(result);
      break;
    case 4:
      answer = float(operand1) / float(operand2);
      result = wxString::Format(wxT("%g"), answer);
      display->SetValue(result);
      break;
    case 5:
      answer = float(std::pow(operand1, 1/operand2));
      result = wxString::Format(wxT("%g"), answer);
      display->SetValue(result);
      break;
    case 6:
      answer = float(std::pow(operand1, operand2));
      result = wxString::Format(wxT("%g"), answer);
      display->SetValue(result);
      break;
  }
}


void MyFrame::onClearClick(wxCommandEvent& event)
{
  //set all input variables
  first = "";
  last = "";
  operand1 = 0;
  operand2 = 0;
  operators = 0;
  last_op = ' ';
  display->SetValue("");
}


void MyFrame::onClearEntryClick(wxCommandEvent& event)
{
  //clear only current input
  display->SetValue("");
}


