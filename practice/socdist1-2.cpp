// #include <bits/stdc++.h> // header file that imports ALL header files
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0); // this makes input/output REALLY fast
    freopen("socdist1.in", "r", stdin);   // reassign input to this file
    freopen("socdist1.out", "w", stdout); // reassign output to this file

    //put info from socdist1.in into variables
    int n;
    cin >> n;
    const int NUM = n;
    string stallsString;
    cin >> stallsString;
    int stalls[NUM];

    //Convert stallsString to an array called stalls
    int a;
    for (a = 0; a < NUM; a++) {
        //stalls[a] = stallsString[a]-48;
        stalls[a] = stallsString[a] - '0';
    }

    //Find out where the first 1 is (start_counting)

    //Find out where the last 1 is (end_counting)

    //Find the minimum number of zeros between the first 1 and the last 1

    //Find the maximum and 2nd maximum number of zeros between the first 1 and the last 1

    //Using (start_counting) and (NUM - end_counting - 1) 
    //check to see if either is larger than the two largest strings of zero plus one divided by two

    //if both are larger, return min_count, break

    //if only start_counting is larger, check to see how (start_counting + 1)/2 compares to (max_count + 1)/2
    // > compare the larger number to min_count
    // > return the smaller number, break 

    //if only (NUM - end_counting - 1) is larger, same thing


    //


    
}
