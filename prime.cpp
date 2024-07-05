// C++ code for finding a list of prime numbers till N
// compares brute, better, and optimal (sieve of Erathosthenes) approach using high_resolution_clock.

#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void print(vector<int> ans,int n){
  int s = ans.size();
  if(s == 0){
    cout<<"no prime numbers till "<<n<<endl;
  }else{
    cout<<"prime numbers till "<<n<<" are: ";
    for(int i=0;i<s;i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
}

void brute(int n){
  vector<int> ans;
  if(n<2){
    cout<<"invalid input"<<endl;
  }else{
    for(int i=2;i<n;i++){
      bool check = true;
      for(int j=2;j<i;j++){
        if(i%j == 0){
          check = false;
          break;
        }
      }
      if(check){
        ans.push_back(i);
      }
    }
  }
  
}

void better(int n){
  vector<int> ans;
  if(n<2){
    cout<<"invalid input";
  }
  for(int i=2;i<n;i++){
    bool check = true;
    for(int j=2;j*j<i;j++){
      if(i%j == 0){
        check = false;
        break;
      }
    }
    if(check){
      ans.push_back(i);
    }
  }
}

void optimal(int n){
  // sieve of Erathosthenes
  vector<int> ans;
  bool a[n+1];
  for(int i=2;i<n;i++){
    for(int j=i*i;j<n;j+=i){
      a[j]=false;
    }
  }
  for(int i=2;i<n;i++){
    if(a[i]){
      ans.push_back(i);
    }
  }

  //want to print then remove comments from below line
  //print(ans,n);
}

int main(){
  int n;
  cout<<"enter number: ";
  cin>>n;

  auto start = high_resolution_clock::now();
  brute(n);
  auto stop = high_resolution_clock::now();
  cout<<"brute function implemented and time taken: "<<duration_cast<microseconds>(stop - start).count()<<endl;

  start = high_resolution_clock::now();
  better(n);
  stop = high_resolution_clock::now();
  cout<<"better function implemented and time taken: "<<duration_cast<microseconds>(stop - start).count()<<endl;

  start = high_resolution_clock::now();
  optimal(n);
  stop = high_resolution_clock::now();
  cout<<"optimal function implemented and time taken: "<<duration_cast<microseconds>(stop - start).count()<<endl;
  
}