/* C++ code that compares the brute and optimal (using euclidean algorithm) for 
   finding GCD of 2 given numbers. 
   We use high_resolution_clock for finding time for each approach */

#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void brute(int m, int n) {
  int ma = 0;
  int mi = min(m, n);
  for (int i = 1; i < mi; i++) {
    if (m % i == 0 && n % i == 0) {
      if (i > ma) {
        ma = i;
      }
    }
  }
  cout << "gcd using brute force: " << ma << endl;
}

int optimal(int m, int n) {
  // Using Euclidean algorithm
  if (m == 0)
    return n;
  if (n == 0)
    return m;
  if (m == n)
    return n;
  if (m > n)
    return optimal(m - n, n);
  if (m < n)
    return optimal(m, n - m);
  return 0;
}

int main() {
  int m, n;
  cout << "enter input: ";
  cin >> m >> n;

  auto start = high_resolution_clock::now();
  brute(m, n);
  auto stop = high_resolution_clock::now();
  cout << "brute function implemented and time taken: "
       << duration_cast<microseconds>(stop - start).count() << endl;

  start = high_resolution_clock::now();
  int ans = optimal(m, n);
  cout << "GCD using optimal function: " << ans << endl;
  stop = high_resolution_clock::now();
  cout << "optimal function implemented and time taken: "
       << duration_cast<microseconds>(stop - start).count() << endl;

  return 0;
}