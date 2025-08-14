#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream fout;
    fout.open("one.csv",ios::out | ios::app);
    cout<<"CSV file created successfully";
}