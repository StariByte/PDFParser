// PDF Parser prototype v1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void lineCounter(fstream&);
void wordCounter(fstream&);
void characterCounter(fstream&);

int main()
{
    string fileName = "lorem.txt";
    fstream inFile(fileName, ios::in);

    if (inFile.fail())
    {
        cout << "Sorry could not open that file, it may not exist.";
    }

    cout << "Filename : " << fileName << endl;
    lineCounter(inFile);
    wordCounter(inFile);
    characterCounter(inFile);

    return 0;

}

void lineCounter(fstream& file)
{
    int totalLine = 0;
    string line;

    while (file >> line)
    {
        getline(file, line);
        totalLine++;
    }

    cout << "Total Lines: " << totalLine << endl;
}

void wordCounter(fstream& file)
{
    file.clear();
    file.seekg(0);
    int total = 0;
    string word;

    while (file >> word)
    {
        total++;
    }

    cout << "Total Words: " << total << endl;
}

void characterCounter(fstream& file)
{
    file.clear();
    file.seekg(0);

    char ch;
    int total = 0;

    while (file >> ch)
    {
        total++;
    }

    cout << "Total characters: " << total << endl;
}