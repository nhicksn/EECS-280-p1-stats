// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {

  //Open file
  string userInput;
  string columnName;
  cout << "Enter your input file name" << endl;
  cin >> userInput;
  cout << "Enter the column name" << endl;
  cin >> columnName;
  vector<double> data = extract_column(userInput, columnName);
  cout << "reading column " << columnName << " from " << userInput << endl;

  // Summary
  /*
  vector<vector<double> > summary = summarize(data);
  cout << "Summary (value: frequency)" << endl;
  for(int i = 0; i < static_cast<int>(summary.size()); i++) {
    cout << summary[i][0] << ": " << summary[i].size() << endl;
  }
  cout << "\n";
  */

  // Count
  double dataCount = count(data);
  cout << "count = " << dataCount << endl;
  
  // Sum
  double dataSum = sum(data);
  cout << "sum = " << dataSum << endl;
  
  // Mean
  double dataMean = mean(data);
  cout << "mean = " << dataMean << endl;
  
  //Standard Deviation
  double dataSTDEV = stdev(data);
  cout << "stdev = " << dataSTDEV << endl;
  
  // Median
  double dataMedian = median(data);
  cout << "median = " << dataMedian << endl;
  
  // Mode
  /*
  int dataMode = mode(data);
  cout << "mode = " << dataMode << endl;
  */
 
  // Minimum
  double dataMin = min(data);
  cout << "min = " << dataMin << endl;
  
  // Maximum 
  double dataMax = max(data);
  cout << "max = " << dataMax << endl;

  // Percentile
  double zeroPercentile = percentile(data, 0);
  cout << "  0th percentile = " << zeroPercentile << endl;
  double twentyFifthPercentile = percentile(data, .25);
  cout << " 25th percentile = " << twentyFifthPercentile << endl;
  double FiftiethPercentile = percentile(data, .5);
  cout << " 50th percentile = " << FiftiethPercentile << endl;
  double seventyFifthPercentile = percentile(data, .75);
  cout << " 75th percentile = " << seventyFifthPercentile << endl;
  double oneHundredthPercentile = percentile(data, 1);
  cout << "100th percentile = " << oneHundredthPercentile << endl;
}