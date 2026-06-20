// PDF Parser prototype v1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

fstream getFileName();
void lineCounter(fstream&);
void wordCounter(fstream&);
void characterCounter(fstream&);

int main()
{
    string fileName = "lorem.txt";
    fstream inFile(fileName, ios::in);
    fstream userFile;

    userFile = getFileName();

  //  if (userFile.fail())
   // {
     //   cout << "Sorry could not open that file, it may not exist. Please enter another name." << endl;
       // userFile = getFileName();
    //}

   // cout << "Filename : " << fileName << endl;


    lineCounter(userFile);
    wordCounter(userFile);
    characterCounter(userFile);

    return 0;

}

void lineCounter(fstream& file)
{
    int totalLine = 0;
    string line;

    while (getline(file, line))
    {
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

fstream getFileName()
{
    string file;
    cout << "Please enter a filename that you wish to work with: ";
    getline(cin, file);

    fstream userfile(file, ios::in);

    while (userfile.fail())
    {
        cout << "Error, the file name either is not in this directory or it does not exist. Please enter a filename: " << endl;
        getline(cin, file);
        userfile.clear();
        userfile.open(file, ios::in);

    }


    cout << "File name is: " << file << endl;


    return userfile;
}