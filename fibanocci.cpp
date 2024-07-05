// c++ code for finding fibanocci numbers till n 
// comparing time taken for brute vs recursive methods using high_resolution_clock

#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;


void print(vector<int> ans,int n){
    cout<<"fibanocci till "<<n<<" : 1 1 ";
   for(int i:ans){
       cout<<i<<" ";
   }
   cout<<endl;
}

void brute(int n) {
    vector<int> ans;
    int prev = 1;
    int cur = 1;
    for(int i=2;i<n;i++){
        ans.push_back(prev+cur);
        cur=cur+prev;
        prev=cur-prev;
    }
    
    //simply remove comment from below to print
    //print(ans,n)
}

int fab(int n){
   if(n<=2){
       return 1;
   }
   return fab(n-1)+fab(n-2);
}

void recursive(int n) {
    vector <int> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(fab(i));
    }
}

int main() {
  int n;
  cout << "enter input: ";
  cin >> n;

  auto start = high_resolution_clock::now();
  brute(n);
  auto stop = high_resolution_clock::now();
  cout << "brute function implemented and time taken: "
       << duration_cast<microseconds>(stop - start).count() << endl;

  start = high_resolution_clock::now();
  recursive(n);
  stop = high_resolution_clock::now();
  cout << "recursive function implemented and time taken: "
       << duration_cast<microseconds>(stop - start).count() << endl;

  return 0;
}