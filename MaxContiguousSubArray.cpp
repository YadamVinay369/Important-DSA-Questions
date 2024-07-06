/*
Question: From given array containing both +ve and -ve numbers, 
find contiguous subarray having maximum sum and its sum.
*/

/*
In this code we compare brute vs optimal (kadane algorithm) for 
finding contiguous subarray having maximum sum using high_resolution_clock
*/

#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void brute(vector<int> arr) {
    int s = arr.size();
    int sum = 0;
    int max = 0;
    int first = 0;
    int last= 0;
    for(int i=0;i<s;i++){
        for(int j=i;j<s;j++){
            sum+=arr[j];
            if(sum>max){
                first = i;
                last = j;
                max=sum;
            }
        }
        sum=0;
    }
    cout<<endl<<"Brute solution: "<<endl;
    cout<<"max contiguous subarray: { ";
    for(int i=first;i<=last;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"} and"<<" max-sum: "<<max<<endl;
}

void kadane(vector<int> arr) {
    int sum=0;
    int max=0;
    int cur = 0;
    int first = 0;
    int last = 0;
    int s=arr.size();
    for(int i=0; i<s ; i++){
        sum+=arr[i];
        if(sum<0){
            cur=i+1;
            sum=0;
        }
        if(sum>max){
            first=cur;
            last=i;
            max=sum;
        }
    }
    
    cout<<endl<<"Kadane solution: "<<endl;
    cout<<"max contiguous subarray: { ";
    for(int i=first;i<=last;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"} and"<<" max-sum: "<<max<<endl;
}

int main() {
    
  vector<int> arr;
  int siz;
  cout << "enter size of array: ";
  cin>>siz;
  int i=0;
  int dummy;
  cout<< "enter elements: ";
  while(i < siz ){
      cin>>dummy;
      arr.push_back(dummy);
      i++;
  }
  
  auto start = high_resolution_clock::now();
  brute(arr);
  auto stop = high_resolution_clock::now();
  int bt = duration_cast<microseconds>(stop - start).count(); 


  start = high_resolution_clock::now();
  kadane(arr);
  stop = high_resolution_clock::now();
  int k = duration_cast<microseconds>(stop - start).count();
  cout<<endl;
  cout << "brute function implemented and time taken: "
       <<bt<< endl;

  cout << "kadane algorithm implemented and time taken: "
       <<k<< endl;

  return 0;
}