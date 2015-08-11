#ifndef NUMEROLOGYCALCULATOR_H_INCLUDED
#define NUMEROLOGYCALCULATOR_H_INCLUDED
#include <wx/string.h>
#include<vector>
#include<map>
#include<string>
#include <sstream>
using namespace std;
typedef enum EStorageFile
{
    MATCHED_FILE = 0,
    SELECTED_FILE = 1,
    STORAGE_MAX = 2,
}EStorageFile;

class NumerologyCalculatorFrame;
class CNumerologyCalculator
{
public:
    void Initialize();
    void ApplyNumerology(int expectedNo, wxString& intial, wxString& newName);
    bool SaveAllNamesIntoFile(vector<string> &strNameList, EStorageFile fileType);
    CNumerologyCalculator(NumerologyCalculatorFrame * frame);

private:
    void FetchAndDisplayNamesFromFile(EStorageFile fileType);
    int DoMatch(wxString& name, stringstream &outputStr);
    int SumUpDigits(int val);

    map<char, int> m_NumerologyValues;
    string m_FileName[STORAGE_MAX];
    NumerologyCalculatorFrame *m_NumCalFrame;

};
#endif // NUMEROLOGYCALCULATOR_H_INCLUDED
