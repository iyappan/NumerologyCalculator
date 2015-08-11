/***************************************************************
 * Name:      NumerologyCalculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Iyappan c ()
 * Created:   2015-08-09
 * Copyright: Iyappan c ()
 * License:
 **************************************************************/

#include "NumerologyCalculatorMain.h"
#include <wx/msgdlg.h>
//(*InternalHeaders(NumerologyCalculatorFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(NumerologyCalculatorFrame)
const long NumerologyCalculatorFrame::ID_STATICTEXT1 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT2 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT3 = wxNewId();
const long NumerologyCalculatorFrame::ID_TEXTCTRL1 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT4 = wxNewId();
const long NumerologyCalculatorFrame::ID_TEXTCTRL2 = wxNewId();
const long NumerologyCalculatorFrame::ID_LISTBOX1 = wxNewId();
const long NumerologyCalculatorFrame::ID_BUTTON1 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT5 = wxNewId();
const long NumerologyCalculatorFrame::ID_TEXTCTRL3 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT6 = wxNewId();
const long NumerologyCalculatorFrame::ID_BUTTON2 = wxNewId();
const long NumerologyCalculatorFrame::ID_LISTBOX2 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT7 = wxNewId();
const long NumerologyCalculatorFrame::ID_LISTBOX3 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT8 = wxNewId();
const long NumerologyCalculatorFrame::ID_BUTTON4 = wxNewId();
const long NumerologyCalculatorFrame::ID_BUTTON5 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT9 = wxNewId();
const long NumerologyCalculatorFrame::ID_LISTBOX4 = wxNewId();
const long NumerologyCalculatorFrame::ID_STATICTEXT10 = wxNewId();
const long NumerologyCalculatorFrame::ID_BUTTON3 = wxNewId();
const long NumerologyCalculatorFrame::ID_BUTTON6 = wxNewId();
const long NumerologyCalculatorFrame::idMenuQuit = wxNewId();
const long NumerologyCalculatorFrame::idMenuAbout = wxNewId();
const long NumerologyCalculatorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NumerologyCalculatorFrame,wxFrame)
    //(*EventTable(NumerologyCalculatorFrame)
    //*)
END_EVENT_TABLE()

NumerologyCalculatorFrame::NumerologyCalculatorFrame(wxWindow* parent,wxWindowID id):m_NumCalcy(this),m_IsAnyToSave(false)
{
    //(*Initialize(NumerologyCalculatorFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(1200,600));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Numerology Calculator"), wxPoint(248,32), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(255,0,255));
    StaticText1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText1Font(16,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Alphabets Values\n1 => [A   I   J   Q   Y]\n2 => [B   K   R]\n3 => [C  G  L  S]\n4 => [D  M  T]\n5 => [E  H  N  X]\n6 => [U  V  W]\n7 => [O  Z]\n8 => [F  P ]"), wxPoint(792,16), wxSize(136,109), 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(255,0,255));
    StaticText2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText2Font(12,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Name Initial           :"), wxPoint(24,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxColour(255,128,255));
    wxFont StaticText3Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    TxtInitial = new wxTextCtrl(this, ID_TEXTCTRL1, _("IT"), wxPoint(168,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("New Name             :"), wxPoint(24,152), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText4->SetForegroundColour(wxColour(255,128,255));
    wxFont StaticText4Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    TxtNewName = new wxTextCtrl(this, ID_TEXTCTRL2, _("pa"), wxPoint(168,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    LstNotMatched = new wxListBox(this, ID_LISTBOX1, wxPoint(24,232), wxSize(304,192), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BnCalculate = new wxButton(this, ID_BUTTON1, _("Calculate"), wxPoint(280,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BnCalculate->SetForegroundColour(wxColour(0,0,255));
    wxFont BnCalculateFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    BnCalculate->SetFont(BnCalculateFont);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Expected Number  :"), wxPoint(24,96), wxSize(137,16), 0, _T("ID_STATICTEXT5"));
    StaticText5->SetForegroundColour(wxColour(255,128,255));
    wxFont StaticText5Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    TxtExpectedNumber = new wxTextCtrl(this, ID_TEXTCTRL3, _("3"), wxPoint(168,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Matched List"), wxPoint(344,208), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText6->SetForegroundColour(wxColour(255,128,255));
    wxFont StaticText6Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    BnSave = new wxButton(this, ID_BUTTON2, _(" Save All"), wxPoint(712,448), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BnSave->SetForegroundColour(wxColour(0,0,255));
    wxFont BnSaveFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    BnSave->SetFont(BnSaveFont);
    LstMatched = new wxListBox(this, ID_LISTBOX2, wxPoint(336,232), wxSize(256,192), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Not Matched"), wxPoint(24,208), wxSize(96,16), 0, _T("ID_STATICTEXT7"));
    StaticText7->SetForegroundColour(wxColour(255,128,255));
    wxFont StaticText7Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    LstSelectedName = new wxListBox(this, ID_LISTBOX3, wxPoint(648,232), wxSize(248,200), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX3"));
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Selected Name"), wxPoint(656,208), wxSize(112,16), 0, _T("ID_STATICTEXT8"));
    StaticText8->SetForegroundColour(wxColour(255,128,255));
    wxFont StaticText8Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText8->SetFont(StaticText8Font);
    Button1 = new wxButton(this, ID_BUTTON4, _(">>"), wxPoint(600,296), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button1->SetForegroundColour(wxColour(0,0,160));
    wxFont Button1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button2 = new wxButton(this, ID_BUTTON5, _("<<"), wxPoint(600,328), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button2->SetForegroundColour(wxColour(0,0,255));
    wxFont Button2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    StDetailedResult = new wxStaticText(this, ID_STATICTEXT9, _("Detail result"), wxPoint(472,96), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StDetailedResult->SetForegroundColour(wxColour(0,255,0));
    LstExistingNames = new wxListBox(this, ID_LISTBOX4, wxPoint(968,80), wxSize(192,432), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX4"));
    StaticText9 = new wxStaticText(this, ID_STATICTEXT10, _("Old Saved Names"), wxPoint(976,48), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    StaticText9->SetForegroundColour(wxColour(255,128,255));
    wxFont StaticText9Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText9->SetFont(StaticText9Font);
    Button3 = new wxButton(this, ID_BUTTON3, _("<<"), wxPoint(904,336), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetForegroundColour(wxColour(0,0,255));
    wxFont Button3Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    Button4 = new wxButton(this, ID_BUTTON6, _(">>"), wxPoint(904,304), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button4->SetForegroundColour(wxColour(0,0,255));
    wxFont Button4Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button4->SetFont(Button4Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnTextCtrl1Text);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnListBox1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnBnCalculateClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnBnSaveClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnButton1Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnButton3Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnButton4Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&NumerologyCalculatorFrame::OnAbout);
    //*)
    m_NumCalcy.Initialize();
}
NumerologyCalculatorFrame::~NumerologyCalculatorFrame()
{
    //(*Destroy(NumerologyCalculatorFrame)
    //*)
    if(m_IsAnyToSave) {SaveAll();}
}

void NumerologyCalculatorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void NumerologyCalculatorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to Numerology Calculator"));
}

void NumerologyCalculatorFrame::OnListBox1Select(wxCommandEvent& event)
{
}

void NumerologyCalculatorFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

/***************************************************************/
void NumerologyCalculatorFrame::OnBnCalculateClick(wxCommandEvent& event)
{
    int expectedNo = atoi(TxtExpectedNumber->GetValue());
    if (expectedNo < 1)
    {
        wxMessageBox( _("Expected number can not be empty"));
        return;
    }

    wxString strNewName = TxtNewName->GetValue();
    if (strNewName.empty())
    {
        wxMessageBox( _("New name can not be empty"));
        return;
    }
    wxString strInitial = TxtInitial->GetValue();
    m_NumCalcy.ApplyNumerology(expectedNo, strInitial, strNewName);
}

/***************************************************************/
void NumerologyCalculatorFrame::UpdateMatchedResult(bool IsMatched, stringstream &outputStr)
{
    if(IsMatched)
    {
        LstMatched->AppendAndEnsureVisible(outputStr.str());
        LstMatched->SetSelection(LstMatched->GetCount() - 1);
        m_IsAnyToSave = true;
    }
    else
    {
        LstNotMatched->AppendAndEnsureVisible(outputStr.str());
        LstNotMatched->SetSelection(LstNotMatched->GetCount() - 1);
    }
}

/***************************************************************/
void NumerologyCalculatorFrame::UpdateDetailedResult(stringstream &outputStr)
{
    StDetailedResult->SetLabel(outputStr.str());
}

/***************************************************************/
void NumerologyCalculatorFrame::OnButton1Click(wxCommandEvent& event)
{
    int index = LstMatched->GetSelection();
    if (index < 0) return;
    LstSelectedName->AppendAndEnsureVisible(LstMatched->GetString(index));
    LstMatched->Delete(index);
    m_IsAnyToSave = true;
}

/***************************************************************/
void NumerologyCalculatorFrame::OnButton2Click(wxCommandEvent& event)
{
    int index = LstSelectedName->GetSelection();
    if (index < 0) return;
    LstMatched->AppendAndEnsureVisible(LstSelectedName->GetString(index));
    LstSelectedName->Delete(index);
    m_IsAnyToSave = true;
}

/***************************************************************/
void NumerologyCalculatorFrame::OnBnSaveClick(wxCommandEvent& event)
{
    if (!m_IsAnyToSave)
    {
        wxMessageBox( _("There is no new matched name to save."));
        return;
    }
    if( SaveAll())
    {
        wxMessageBox( _("Matched Names have been Saved into file"));
        m_IsAnyToSave = false;
        return;
    }
    wxMessageBox( _("Saving failed!"));
}

/***************************************************************/
bool NumerologyCalculatorFrame::SaveAll()
{
    string str;
    vector<string> strNameList;
    int matchedCount = LstMatched->GetCount();
    int selectedCount = LstSelectedName->GetCount();
    int oldNameCount = LstExistingNames->GetCount();
    if (matchedCount == 0 && selectedCount == 0 && oldNameCount)
    {
        return false;
    }
    for(int i = 0; i < matchedCount; i++)
    {
      str = (LstMatched->GetString(i)).c_str();
      strNameList.push_back(str);
    }
    for(int i = 0; i < oldNameCount; i++)
    {
      str = (LstExistingNames->GetString(i)).c_str();
      strNameList.push_back(str);
    }

    bool retMatchedData = m_NumCalcy.SaveAllNamesIntoFile(strNameList, MATCHED_FILE);

    strNameList.clear();
    for(int i = 0; i < selectedCount; i++)
    {
       str = (LstSelectedName->GetString(i)).c_str();
       strNameList.push_back(str);
    }
    bool retSelectedData = m_NumCalcy.SaveAllNamesIntoFile(strNameList, SELECTED_FILE);
    return (retMatchedData || retSelectedData);
}

/***************************************************************/
void NumerologyCalculatorFrame::InsertIntoOldNameList(string &str)
{
    if (0 > LstExistingNames->FindString(str.c_str()))
    {
        LstExistingNames->AppendAndEnsureVisible(str.c_str());
    }
}

/***************************************************************/
void NumerologyCalculatorFrame::InsertIntoSelectedNameList(string &str)
{
    if (0 > LstSelectedName->FindString(str.c_str()))
    {
        LstSelectedName->AppendAndEnsureVisible(str.c_str());
    }
}

/***************************************************************/
void NumerologyCalculatorFrame::OnButton3Click(wxCommandEvent& event)
{
    int index = LstExistingNames->GetSelection();
    if (index < 0) return;
    LstSelectedName->AppendAndEnsureVisible(LstExistingNames->GetString(index));
    LstExistingNames->Delete(index);
    m_IsAnyToSave = true;
}

void NumerologyCalculatorFrame::OnButton4Click(wxCommandEvent& event)
{
    int index = LstSelectedName->GetSelection();
    if (index < 0) return;
    LstExistingNames->AppendAndEnsureVisible(LstSelectedName->GetString(index));
    LstSelectedName->Delete(index);
    m_IsAnyToSave = true;
}
