#include<iostream>
#include<fstream>
using namespace std;

bool fileDoesExist(const string &fileToBeChecked)
{
    fstream file(fileToBeChecked);
    return file.good();
}
int main()
{
    string source="source.csv";
    if(!fileDoesExist(source))
    {
        cout<<"Source file does not exist by default";
    }
    else{
        cout<<"File exist";
    }
}