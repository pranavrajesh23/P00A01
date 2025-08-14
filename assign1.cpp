#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream fout;
    fout.open("one.csv",ios::out | ios::app);
    cout<<"CSV file created successfully"<<endl;

    int n;
    cout<<"Enter the no. of rows required"<<endl;
    cin>>n;

    fout<<"Name,Age,Place\n";
    cout<<"Enter the details"<<endl;
    
    int age;
    string name,place;
    
    for(int i=0;i<n;i++)
    {
        cin>>name>>age>>place;
        fout<<name<<","<<age<<","<<place<<"\n";
    }
    cout<<"CSV file is created and data are appended successfully";
}