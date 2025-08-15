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
    cout<<"Copied successfully.\n";
}
bool similarityCheck(const string &source,const string &destination)
{
    fstream src, dest;
    src.open(source,ios::in);
    dest.open(destination,ios::in);
    string one,two;
    bool flag=true;
    while(getline(src,one) && getline(dest,two))
    {
        if(one!=two)
        {
            flag=false;
            break;
        }
    }
    src.close();
    dest.close();
    return flag;
}
int main()
{
    
    if(!fileDoesExist(source))
    {
        cout<<"Source file does not exist by default.\n";
    }
    else
    {
        
            if(fileContainData(source))
            { 
                if(!fileDoesExist(destination))
                {
                    cout<<"Destination file does not exist by default, so creating destination file to copy things from source file.\n";
                    createCsvFile();
                    cout<<"Coping source file to destination file.\n";
                    copyingData(source,destination);
                } 
                else
                {
                    if(fileContainData(destination))
                    {
                        cout<<"Since the destination file does contain few data, we checking for the existence of same data in both files.\n";
                        if(similarityCheck(source,destination))
                        {
                            cout<<"Both files have same data, so no need to copy data from source file.\n";
                        }
                        else
                        {
                            cout<<"Coping source file to destination file.\n";
                            copyingData(source,destination);
                        }
                    }
                }
            }
            else
            {
                cout<<"Source file exists but it dosen't contain any data such that there is no data to copy.\n";
                fstream file(destination,ios::out | ios::trunc);
                file.close();
            }
    }
    return 0;
}