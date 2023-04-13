// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include <cassert>
#include <vector>
#include "p1_library.h"
#include <cmath>
using namespace std;
vector<vector<double> > summarize(vector<double> v) {
  sort(v);
  vector<vector<double> > result;
  int counter = 0;
  for(size_t i = 0; i < v.size(); i++) {
    for (size_t j = 0; j < v.size(); j++) {
      if(v[i] == v[j]) {
        for(size_t k = 0; k < result.size(); k++) {
          if(result[k][0] == j) {
            break;
          }
        }
        result[counter].push_back(j);
      }
      // figure out better solution; should not add to the counter if nothing has been added, if v[i] does not match v[j] but
      // nothing was added since the last addition and counter has already been updated.
      else if(v[i] != v[j]) {
        counter++;
        break;
      }
    }
  }
  return result;
  assert(false);
}
int count(vector<double> v) {
  int count = v.size();
  return count;
  assert(false);
}
double sum(vector<double> v) {
  int count = v.size();
  double sum = 0;
  for(int i = 0; i < count; i++) {
    sum = sum + v[i];
  }
  return sum;
  assert(false);
}
double mean(vector<double> v) {
  double dataSum = sum(v);
  double mean = dataSum / v.size();
  return mean;
  assert(false);
}
double median(vector<double> v) {
  sort(v);
  double median;
  int size = v.size();
  double avg;
  if(size % 2 == 0) {
    avg = v[(size/2)-1] + v[(size/2)];
    median = avg/2;
  }
  else if(size % 2 == 1) {
    median = v[size/2];
  }
  return median;
  assert(false);
}
double mode(vector<double> v) {
  sort(v);
  int mode = v[0];

// write function for mode here

  return mode;
  assert(false);
}
double min(vector<double> v) {
  sort(v);
  double min;
  min = v[0];
  return min;
  assert(false);
}
double max(vector<double> v) {
  sort(v);
  int size = v.size();
  double max;
  max = v[size - 1];
  return max;
  assert(false);
}
double stdev(vector<double> v) {
  double dataMean = mean(v);
  double size = v.size();
  for(size_t i = 0; i < size; i++) {
    v[i] = v[i] - dataMean;
  }
  for(size_t j = 0; j < size; j++) {
    v[j] = v[j]*v[j];
  }
  double dataSum = sum(v);
  double dataVariance = dataSum / (size - 1);
  double dataSTDEV = sqrt(dataVariance);
  return dataSTDEV;
  assert(false);
}
double percentile(vector<double> v, double p) {
  double size = v.size();
  p = p * 100.;
  double n = (p/100.)*(size - 1.) + 1.;
  double k = floor(n);
  double d = n - k;
  double percentile = v[k-1] + d*(v[k] - v[k-1]);
  return percentile;
  assert(false);
}