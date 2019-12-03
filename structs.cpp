//structs lab
//12/2/19 Chris Lu
//something something structs
//sources: none

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
struct Temperature
{
  string Month;
  int low;
  int high; 
};


//have a struct that holds a month, high (as int, low (as int
//there should be an array of these structs (dynamical constant)

//grabs data out of a filestream, returns temp and rows
int loadData(ifstream &infile, Temperature[], int &rows);

Temperature findLow ( Temperature [], int rows ); //functions have types oh yeah
Temperature findHigh ( Temperature [], int rows );

int main()
{
ifstream infile;
int rows;
Temperature Temp[12];//where are we getting arr size


loadData(infile, Temp, rows);


return 0;
}


int loadData(ifstream &infile, Temperature[], int &rows)
{
string query = "temps.txt";
string recieved;
infile.open(query);
if (!infile)
{
  cout << "Can't open file" << endl << "Bye!" << endl;
  return -1;
}

while (infile >> recieved)
{
cout << recieved << endl; 
}


};
