// PDF Parser prototype v1

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//function prototypes
string getFileName();
int lineCounter(fstream&);
int wordCounter(fstream&);
int characterCounter(fstream&);
void displayReport(string, int, int, int);
void saveReport(string, int, int, int);


int main()
{

    string fileName;
    int words, lines, chs;

    //get input file name
    fileName = getFileName();

    fstream userFile(fileName, ios::in);

    //check that it opened successfully, if not reenter
    while (userFile.fail())
    {
        cout << "Error, the file name either is not in this directory or it does not exist. Please enter a filename: " << endl;
        getline(cin, fileName);
        userFile.clear();
        userFile.open(fileName, ios::in);

    }

    cout << endl;
    // call counter functions for report
    lines = lineCounter(userFile);
    words = wordCounter(userFile);
    chs = characterCounter(userFile);

    //display parsing report on screen and save to an output file
    displayReport(fileName, lines, words, chs);
    saveReport(fileName, lines, words, chs);
    return 0;

}

// function counts lines by newline character
int lineCounter(fstream& file)
{
    int totalLine = 0;
    string line;

    while (getline(file, line))
    {
        totalLine++;
    }

    return totalLine;
}

//counts words space delimiter
int wordCounter(fstream& file)
{
    file.clear();
    file.seekg(0);
    int total = 0;
    string word;

    while (file >> word)
    {
        total++;
    }

    return total;
}

//counts full characters including whitespace
int characterCounter(fstream& file)
{
    file.clear();
    file.seekg(0);

    char ch;
    int total = 0;

    while (file >> ch)
    {
        total++;
    }

    return total;
}

//request the input filename from user
string getFileName()
{
    string file;
    cout << "Please enter a filename that you wish to work with: ";
    getline(cin, file);

    return file;
}

//displays the counter report on the screen, takes the returns
//from the counter functions as parameters
void displayReport(string file, int line, int word, int chars)
{
    for (int index = 0; index < 15; index++)
    {
        cout << "-";
    }

    cout << "\n\nPDF Analyzer v1.1\n\n";

    for (int index = 0; index < 15; index++)
    {
        cout << "-";
    }
    cout << endl << endl;

    cout << "File: " << file << endl;
    cout << "Lines: " << line << endl;
    cout << "Words: " << word << endl;
    cout << "Characters: " << chars << endl << endl;

    for (int index = 0; index < 15; index++)
    {
        cout << "-";
    }
}

//same as display report, but saves it in a new output file.
void saveReport(string file, int line, int word, int chars)
{
    string name;

    cout << "Please enter a name to save the report to: ";
    getline(cin, name);

    name += ".txt";

    ofstream outFile(name, ios::out);

    if (!outFile)
    {
        cout << "Error creating output file." << endl;
        return;
    }

    for (int index = 0; index < 15; index++)
    {
        outFile << "-";
    }

    outFile << "\n\nPDF Analyzer v1.1\n\n";

    for (int index = 0; index < 15; index++)
    {
        outFile << "-";
    }
    outFile << endl << endl;

    outFile << "File: " << file << endl;
    outFile << "Lines: " << line << endl;
    outFile << "Words: " << word << endl;
    outFile << "Characters: " << chars << endl << endl;

    for (int index = 0; index < 15; index++)
    {
        outFile << "-";
    }

    cout << "Report saved to " << name << endl;
}