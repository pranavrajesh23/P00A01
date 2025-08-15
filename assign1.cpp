#include<iostream>
#include<fstream>
using namespace std;
string source="source.csv";
string destination="destination.csv";
bool fileDoesExist(const string &fileToBeChecked)
{
    fstream file(fileToBeChecked);
    return file.good();
}
void createCsvFile()
{
    fstream fout(destination,ios::out | ios::trunc);
    fout.close();
}
bool fileContainData(const string &fileToBeChecked)
{
    fstream file(fileToBeChecked);
    return file.peek() != fstream::traits_type::eof();
}
void copyingData(const string &source, const string &destination)
{
    fstream src(source),dest(destination);
    string line;
    while(getline(src,line))
    {
        dest<<line<<"\n";
    }
    src.close();
    dest.close();
}
int main()
{
    
    if(!fileDoesExist(source))
    {
        cout<<"Source file does not exist by default";
    }
    else
    {
        
            if(fileContainData(source))
            {
                cout<<"Coping source file to destination file\n";
                if(!fileDoesExist(destination))
                {
                    cout<<"Destination file does not exist by default, so creating destination file to copy things from source file\n";
                    createCsvFile();
                    copyingData(source,destination);
                } 
                copyingData(source,destination);
                cout<<"Copied data from source to destination\n";
            }
            else
            {
                cout<<"Source file exists but it dosen't contain any data such that there is no data to copy\n";
                fstream file(destination,ios::out | ios::trunc);
                file.close();
            }
    }
}