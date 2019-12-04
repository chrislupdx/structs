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
string gotLine;
int highsIt = 0; //ordinal counter for high temps
int lowsIt = 0;
int highs[rows];
int lows[rows];
int lines = 0;
int numOrd = 0;
int totalNums[numOrd];
infile.open(query);
if (!infile)
{
  cout << "Can't open file" << endl << "Bye!" << endl;
  return -1;
}

while (infile >> recieved) //calcluate # of rows
{
  while(getline(infile, gotLine))
  {
    ++lines;
  }
  rows = lines;
}
infile.close();

infile.open(query);
while (infile >> recieved) //parse months and parse temps
{
  if (recieved.length() == 2) //parse nums
  {
    totalNums[numOrd] = stoi(recieved); //stores nums with ordinal values
    numOrd++; //count the # of nums coming in 
  }
}

for (int i = 0; i < numOrd; i++) //go throughall the numbres
{
  if (i % 2 == 0)
  {   
//    cout << "I is " << i << " totalNums[i] " << totalNums[i] << endl; //grabbing right ones
//    cout << "highsIt " << highsIt << endl;

    highs[highsIt] = totalNums[i]; //this transfer is brokend
    highsIt++;
  }
}

for (int i = 0; i < highsIt; i++)
{
  cout << "highs[" << i << "] is " << highs[i] << endl;
}

infile.close();

};
