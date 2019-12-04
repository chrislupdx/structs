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

int loadData(ifstream &infile, Temperature[], int &rows);
Temperature findLow ( Temperature [], int rows );
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
int totalNums[24];
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
  if (!(i % 2 == 0)) //odd vals
  {
  // cout << "i is " << i << setw(15) << totalNums[i] << endl; 
    lowsIt++;
  }

  if (i % 2 == 0) //if number ordinal is divisible by 2
  {  
  highs[highsIt] = totalNums[i];
  //cout << "highsIt is " << highsIt << setw(10) << "i is " << i << setw(15) << "totalnums " << totalNums[i] << endl;  
   highsIt++;
  }
}
cout << endl;
for (int i = 0; i < rows; i++)
{
 cout << "highs[" << i << "] is " << highs[i] << endl;
}

infile.close();
return 0;
};
