#include <vector>      // using STL vector
#include <cstdlib>     // provides atoi
#include <iostream>
#include <iomanip>
#include <time.h>      // for accessing timing operations
#include <sys/time.h>  // better granularity timing based on gettimeofday
using namespace std;

#define USE_GETTIMEOFDAY


void usage() {
  cout << "Usage:   vectortime N [mode]" << endl
       << "  where N > 0 is number of elements" << endl
       << "  and optional mode is interpreted as: " << endl
       << "      A:  repeated push_back  [the default]" << endl
       << "      B:  repeated insert at front" << endl
       << "      C:  repeated push_back with initial reserve" << endl
       << "      D:  repeated insert with initial reserve" << endl;
}


#ifdef USE_GETTIMEOFDAY
double toSeconds(const timeval& t) {
  return (double) t.tv_sec + ((double) t.tv_usec)/1000000.0;
}
double diff(const timeval& start, const timeval& stop) {
  return stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec)/1000000.0;
}
#else
double toSeconds(const clock_t& t) {
  return ((double) t)/CLOCKS_PER_SEC;
}
double diff(const clock_t& start, const clock_t& stop) {
  return ((double) stop - start)/CLOCKS_PER_SEC;
}
#endif




int main(int argc, const char* argv[]) {
  int N = 0;
  char mode = 'A';

  if (argc>1 && argv[1] == "-h") {
    usage();
    return(0);
  }
  
  if (argc>1)
    N = atoi(argv[1]);

  if (N < 1) {
    usage();
    return(1);
  }

  if (argc>2) {
    mode = argv[2][0];
    switch (mode) {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
      break;
    default:
      usage();
      cout << "Unrecognized mode: " << argv[2] << endl;
      return(1);
    }
  }


  // variables to keep track of timing
#ifdef USE_GETTIMEOFDAY
  timeval  start, stop;
#else
  clock_t  start, stop;
#endif
  double elapsed, cumulative, worst;

#ifndef USE_GETTIMEOFDAY
  cout << "Note:  clock granularity on this machine is " << CLOCKS_PER_SEC << " ticks per second." << endl;
#endif

  vector<double> v;
  cumulative = worst = 0.0;

  switch (mode) {
  case 'A':
  case 'B':
    v.resize(10);
    break;
  case 'C':
  case 'D':
    v.resize(N);
  }
  cout << "Using initial capacity of " << v.capacity() << endl;

  int trial;
  for (trial=0; trial<N; trial++) {
    double data = trial*3.14159;

    switch (mode) {
    case 'A':
    case 'C':
#ifdef USE_GETTIMEOFDAY
      gettimeofday(&start,NULL);
#else
      start = clock();
#endif

      v.push_back(data);

#ifdef USE_GETTIMEOFDAY
      gettimeofday(&stop,NULL);
#else
      stop = clock();
#endif
      break;


    case 'B':
    case 'D':
#ifdef USE_GETTIMEOFDAY
      gettimeofday(&start,NULL);
#else
      start = clock();
#endif

      v.insert(v.begin(),data);

#ifdef USE_GETTIMEOFDAY
      gettimeofday(&stop,NULL);
#else
      stop = clock();
#endif
    }

    elapsed = diff(start,stop);
    cumulative += elapsed;
    if (elapsed > worst) {
      worst = elapsed;
      cout << "New max thus far is "
       << setprecision(8) << fixed << worst
       << " seconds (trial " << trial << ")" << endl;
    }
  }
    
  cout << endl;
  cout << "Cumulative time was " << setprecision(8) << fixed << cumulative << " seconds" << endl;
  cout << "Average time was " << setprecision(8) << fixed << cumulative/N << " seconds" << endl;
  cout << "Worst time was " << setprecision(8) << fixed << worst << " seconds" << endl;

}
