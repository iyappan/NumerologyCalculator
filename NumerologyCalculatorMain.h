/***************************************************************
 * Name:      NumerologyCalculatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Iyappan c ()
 * Created:   2015-08-09
 * Copyright: Iyappan c ()
 * License:
 **************************************************************/

#ifndef NUMEROLOGYCALCULATORMAIN_H
#define NUMEROLOGYCALCULATORMAIN_H
#include"numerologycalculator.h"

//(*Headers(NumerologyCalculatorFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class NumerologyCalculatorFrame: public wxFrame
{
    public:

        NumerologyCalculatorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~NumerologyCalculatorFrame();
        void UpdateMatchedResult(bool IsMatched, stringstream &outputStr);
        void UpdateDetailedResult(stringstream &outputStr);
        void InsertIntoOldNameList(string &str);
        void InsertIntoSelectedNameList(string &str);

    private:
        bool SaveAll();
        CNumerologyCalculator m_NumCalcy;
        bool m_IsAnyToSave;

        //(*Handlers(NumerologyCalculatorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnListBox1Select(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnBnCalculateClick(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnBnSaveClick(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(NumerologyCalculatorFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL2;
        static const long ID_LISTBOX1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT6;
        static const long ID_BUTTON2;
        static const long ID_LISTBOX2;
        static const long ID_STATICTEXT7;
        static const long ID_LISTBOX3;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT9;
        static const long ID_LISTBOX4;
        static const long ID_STATICTEXT10;
        static const long ID_BUTTON3;
        static const long ID_BUTTON6;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(NumerologyCalculatorFrame)
        wxStaticText* StaticText9;
        wxListBox* LstMatched;
        wxTextCtrl* TxtNewName;
        wxButton* Button4;
        wxStaticText* StDetailedResult;
        wxStaticText* StaticText2;
        wxListBox* LstNotMatched;
        wxButton* Button1;
        wxStaticText* StaticText6;
        wxTextCtrl* TxtInitial;
        wxStaticText* StaticText8;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* BnSave;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStatusBar* StatusBar1;
        wxButton* BnCalculate;
        wxListBox* LstSelectedName;
        wxListBox* LstExistingNames;
        wxStaticText* StaticText4;
        wxTextCtrl* TxtExpectedNumber;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // NUMEROLOGYCALCULATORMAIN_H
