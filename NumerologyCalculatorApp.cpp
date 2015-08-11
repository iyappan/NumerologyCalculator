/***************************************************************
 * Name:      NumerologyCalculatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Iyappan c ()
 * Created:   2015-08-09
 * Copyright: Iyappan c ()
 * License:
 **************************************************************/

#include "NumerologyCalculatorApp.h"

//(*AppHeaders
#include "NumerologyCalculatorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(NumerologyCalculatorApp);

bool NumerologyCalculatorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	NumerologyCalculatorFrame* Frame = new NumerologyCalculatorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
