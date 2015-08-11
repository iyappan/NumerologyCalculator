#include"numerologycalculator.h"
#include"NumerologyCalculatorMain.h"
#include <fstream>

CNumerologyCalculator::CNumerologyCalculator(NumerologyCalculatorFrame * frame):m_NumCalFrame(frame)
{
}

/***************************************************************/
void CNumerologyCalculator::Initialize()
{
    m_NumerologyValues['A'] = 1;
    m_NumerologyValues['B'] = 2;
    m_NumerologyValues['C'] = 3;
    m_NumerologyValues['D'] = 4;
    m_NumerologyValues['E'] = 5;
    m_NumerologyValues['F'] = 8;
    m_NumerologyValues['G'] = 3;
    m_NumerologyValues['H'] = 5;
    m_NumerologyValues['I'] = 1;
    m_NumerologyValues['J'] = 1;
    m_NumerologyValues['K'] = 2;
    m_NumerologyValues['L'] = 3;
    m_NumerologyValues['M'] = 4;
    m_NumerologyValues['N'] = 5;
    m_NumerologyValues['O'] = 7;
    m_NumerologyValues['P'] = 8;
    m_NumerologyValues['Q'] = 1;
    m_NumerologyValues['R'] = 2;
    m_NumerologyValues['S'] = 3;
    m_NumerologyValues['T'] = 4;
    m_NumerologyValues['U'] = 6;
    m_NumerologyValues['V'] = 6;
    m_NumerologyValues['W'] = 6;
    m_NumerologyValues['X'] = 5;
    m_NumerologyValues['Y'] = 1;
    m_NumerologyValues['Z'] = 7;

    m_FileName[MATCHED_FILE] = "matchednames.txt";
    m_FileName[SELECTED_FILE] = "selectednames.txt";
    FetchAndDisplayNamesFromFile(MATCHED_FILE);
    FetchAndDisplayNamesFromFile(SELECTED_FILE);

}

/***************************************************************/
void CNumerologyCalculator::ApplyNumerology(int expectedNo, wxString& intial, wxString& newName)
{
    int calVal;
    stringstream outputStr1;
    stringstream outputStr2;
    wxString fullName = newName;
    wxString fullNameToPrint = newName;
    wxString tmpInitial = "";
    int i = 0;
    do
    {
        outputStr1 << "[" << fullNameToPrint.c_str() << "]=>";
        calVal = DoMatch(fullName, outputStr1);
        outputStr2 << fullNameToPrint << "(" << calVal << ")";
        m_NumCalFrame->UpdateMatchedResult(expectedNo == calVal, outputStr2);
        outputStr2.str("");
        tmpInitial = tmpInitial + intial.c_str()[i];
        fullName = tmpInitial + newName;
        fullNameToPrint = tmpInitial + "." + newName;
    }while(intial.c_str()[i++] != 0);

    m_NumCalFrame->UpdateDetailedResult(outputStr1);
}

/***************************************************************/
int CNumerologyCalculator::DoMatch(wxString& name, stringstream &outputStr)
{
    wxString strUpperName = name.Upper();
    int calVal = 0;
    int strSize = name.size();
    outputStr << "{";
    char letter;
    int numerologyVal;
    for (int i = 0 ; i < strSize; i++)
    {
        letter = strUpperName.c_str()[i];
        numerologyVal = m_NumerologyValues.find(letter)->second;
        outputStr << numerologyVal;
        calVal = calVal + numerologyVal;
        if (i != strSize -1)
        {
            outputStr << "+";
        }
    }
    outputStr << "}=>" << calVal;;
    while (calVal > 9)
    {
        calVal =  SumUpDigits(calVal);
    }
    outputStr << "=>[Final]="<<calVal <<"\n";
    return calVal;
}

/***************************************************************/
bool CNumerologyCalculator::SaveAllNamesIntoFile( vector<string> &strNameList, EStorageFile fileType)
{
    fstream myfile;
    myfile.open(m_FileName[fileType].c_str(),ios_base::out|ios_base::trunc );
    if (!myfile.good())
    {
       myfile.close();
       return false;
    }
   // myfile.seekg(0,ios::end);
    int namesCount = strNameList.size();
    for (int i = 0; i  < namesCount; i++)
    {
        myfile << strNameList[i] << "\r\n";
    }
    myfile.close();
    return true;
}

/***************************************************************/
void CNumerologyCalculator::FetchAndDisplayNamesFromFile( EStorageFile fileType)
{
    ifstream myfile(m_FileName[fileType].c_str(),ios::app);
    if (!myfile.good())
    {
       myfile.close();
       return;
    }
    string str;
    if (fileType == MATCHED_FILE)
    {

        while (std::getline(myfile, str))
        {
            m_NumCalFrame->InsertIntoOldNameList(str);

        }
    }
    else
    {
        while (std::getline(myfile, str))
        {
            m_NumCalFrame->InsertIntoSelectedNameList(str);

        }
    }
    myfile.close();
}

/***************************************************************/
int CNumerologyCalculator::SumUpDigits(int val)
{
    int calVal = 0;

    while ( val > 0)
    {
        calVal = calVal +  (val % 10);
        val = val / 10;
    }
    return calVal;
}
