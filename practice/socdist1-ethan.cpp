/*#include <iostream>
#include <stdio.h>
#include <vector>*/

//#include <bits/stdc++.h>
#include "a_headerfiles.hpp"

using namespace std;
const int MIN=-1e9;
const int MAX=1e9;
vector<int>csts1;
vector<int>csts2;
//vector<int>lens;

int main(){

#ifndef LOOKIDKWHATAMACROISBUTSEEMSCOOL
  freopen("socdist1.in","r",stdin);
  freopen("socdist1.out","w",stdout);
#endif
  cin.tie(0)->sync_with_stdio(0);

  //in to var
  int n;
  cin>>n;
  string stls;
  cin>>stls;

  //initialize the needed variables
  int i=0,j=n-1,pre=0,pst=0;

  //for loops
  //find the first 1
  for(;i<=n-1;i++,pre++)
    if(stls[i]!='0')
        break;
  
  //find the last 1
  for(;j>=0;j--,pst++)
    if(stls[j]!='0')
        break;

  //if the entire string is 0s, return n-1
  // %i\n is a format string–%i means print an integer
  if(pre==n)
    printf("%i\n",n-1),
    exit(0);

  //add the length of the string of 0s when a cow is added
  //before the first 1 to csts
  //same with adding a cow after the last 1
  csts1.push_back(pre);
  csts1.push_back(pst);

  //add the length of the string if you add 2 cows to the
  //leading 0s and lagging 0s
  csts2.push_back(pre/2);
  csts2.push_back(pst/2);

  //go through and add to the vectors the length (cost?) 
  //of adding 1 (or two) cows to each chain of 0s 
  //len represents the length of each chain of 0s
  //low represents the smallest chain of 0s
  int len=1,low=MAX;
  for(int k=i+1;k<=j;k++){
    if(stls[k]=='0')
        len++;
    else{
      csts1.push_back(len/2);
      csts2.push_back(len/3);
      low=min(low,len);
      len=1;
    }
  }

  //sort csts from large to small
  sort(csts1.begin(),csts1.end(),greater<int>());
  sort(csts2.begin(),csts2.end(),greater<int>());

  //choose the integer to compare against the original min
  int res=MIN;

  //if there are two or more intances where you only add one cow to a chain, 
  //(there will basically always be)
  //set the lowest created (? words) num to the 2nd biggest length
  //this simulates the normal situation where you add one cow per chain
  if(csts1.size()>=2)
    res=max(res,csts1[1]);

  //if there is one or more instances where you add two cows to a chain, 
  //(there will basically a lways be)
  //set the lowest created num to whichever one is the max between
  //the previous num and the greatest gap created when you add two cows to a chain
  //this accounts for when adding two cows to one fat chain of 0s
  //would create more space between cows than adding one to two separate chains
  if(csts2.size()>=1)
    res=max(res,csts2[0]);

  //check to see if the created min is lower than the old min
  //if not, change the result to the old min
  res=min(res,low);

  //return
  printf("%i\n",res);
}