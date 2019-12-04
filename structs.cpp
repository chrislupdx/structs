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

int loadData(ifstream &infile, Temperature [], int &rows);
Temperature findLow ( Temperature [], int rows ); //we can call it int loaddata lawl
Temperature findHigh ( Temperature [], int rows );

int main()
{
ifstream infile;
int rows;
Temperature Temp[12];

loadData(infile, Temp, rows);

for (int i = 0; i < rows; i++)
{
  cout << Temp[i].Month << "fuk" << endl;
}



//findHigh(Temp, rows);

return 0;
}

Temperature findHigh(Temperature Temp[], int rows) //accessing+passing the struct is hard
{
  int highest = 1;

  Temperature highestTemp[highest];
  //id the highest temp and return the struct?
  //int highest = Temperature[0].high;
  //cout << highest << endl;
  for (int i = 0; i < rows; i++)
  {
  //cout << highestTemp[i].Month << " " << highestTemp[i].high << " " << highestTemp[i].low <<  endl;
  //cout << Temperature[i].high << endl; //temps are still blank
  }
return highestTemp[highest];
};


int loadData(ifstream &infile, Temperature Temp[], int &rows) //struct array # declaration how
{
string query = "temps.txt";
string recieved;
string gotLine;
string months[12];
int highsIt = 0; //ordinal counter for high temps
int lowsIt = 0;
int monthsIt = 0;
int highs[rows];
int lows[rows];
int lines = 0;
int numOrd = 0;
int totalNums[24];
//Temperature Temp[12]; //segfaults if you put in rows bc delcaration/order etc

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
//cout << "Months in file: " << rows << endl << endl;
infile.close();

infile.open(query);
while (infile >> recieved) //parse months and parse temps
{
  if (recieved.length() == 2) //parse nums
  {
    totalNums[numOrd] = stoi(recieved); //stores nums with ordinal values
    numOrd++; //count the # of nums coming in 
  }
  if (recieved.length() >= 3) //grab months and put them in a string array
  {
   months[monthsIt] = recieved;
   monthsIt++;
  } 
}

for (int i = 0; i < numOrd; i++) //go throughall the numbres
{
  if (!(i % 2 == 0)) //odd vals
  {
    lows[lowsIt] = totalNums[i]; //puts low vals into lows
    lowsIt++;
  }

  if (i % 2 == 0) //if number ordinal is divisible by 2
  {  
    highs[highsIt] = totalNums[i]; //put the high vals into highs
    highsIt++;
  }
}

for (int i = 0; i < rows; i++) //assign the values to the structs
{
  Temp[i].low = lows[i];
  Temp[i].high = highs[i];
  Temp[i].Month = months[i]; 
}

infile.close();
return 0;
};
