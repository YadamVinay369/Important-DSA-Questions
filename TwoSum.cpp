/*Question: Given an array of integers and a target value, find a pair of integers from 
given array such that their sum = target*/

/*This code shows the comparision between brute vs two-pointer vs hashing approach 
by comparing time taken using high_resolution_clock */

/*Note: there may be more than one pair of integers but this code only returns one pair*/

#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void brute(vector<int> arr,int target) {
    int s = arr.size();
    bool p = false;
    cout<<"Brute force solution: ";
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            if(arr[i]+arr[j] == target){
                cout<<"{ "<<arr[i]<<" "<<arr[j]<<" }"<<endl;
                p=true;
                break;
            }
        }
        if(p){
            break;
        }
    }
    if(!p){
     cout<<"There are no such pairs"<<endl;   
    }
}

void twoPointer(vector<int> arr,int target) {
    sort(arr.begin(),arr.end());
    int i=0;
    int j =arr.size()-1;
    cout<<"twoPointer solution: ";
    while(i<j){
        if(arr[i]+arr[j] == target){
            cout<<"{ "<<arr[i]<<" "<<arr[j]<<" }"<<endl;
            return;
        }else if(arr[i]+arr[j] > target){
            j--;
        }else{
            i++;
        }
    }
    cout<<" There are no such pairs."<<endl;
}

void hashing(vector<int> arr,int target) {
    unordered_map<int,bool> p;
    cout<<"hashing solution: ";
    for(int i:arr){
        if(p.find(target-i) != p.end()){
            cout<<"{ "<<i<<" "<<target-i<<" }"<<endl;
            return;
        }
        p[i]=true;
    }
    cout<<"There are no such pairs.";
}

int main() {
  int target;
  vector<int> arr;
  cout << "enter target: ";
  cin >> target;
  cout << "enter elements of array(if exit then enter -1): ";
  int dummy;
  while(dummy != -1){
      cin>>dummy;
      arr.push_back(dummy);
  }
  arr.pop_back();
  

  auto start = high_resolution_clock::now();
  brute(arr,target);
  auto stop = high_resolution_clock::now();
  int bt = duration_cast<microseconds>(stop - start).count(); 


  start = high_resolution_clock::now();
  twoPointer(arr,target);
  stop = high_resolution_clock::now();
  int tpt = duration_cast<microseconds>(stop - start).count(); 
 

  start = high_resolution_clock::now();
  hashing(arr,target);
  stop = high_resolution_clock::now();
  int ht = duration_cast<microseconds>(stop - start).count();
  cout<<endl;
    
    cout << "brute function implemented and time taken: "
       <<bt<< endl;
   cout << "two-pointer function implemented and time taken: "
       <<tpt<< endl;
  cout << "hashing function implemented and time taken: "
       <<ht<< endl;

  return 0;
}

/* link: https://leetcode.com/problems/two-sum/description/ */
