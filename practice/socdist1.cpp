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
    
    
    //try to convert stalls to an array
    // Traverse the string
    int a;
    for (a = 0; a < NUM; a++) {
        //stalls[a] = stallsString[a]-48;
        stalls[a] = stallsString[a] - '0';
    }
    
    //printing array to check if its right
    /*
    int j;
    for (j = 0; j < NUM; j++){
        cout << stalls[j];
    }
    */

   //find where to start counting
   int start_counting = -1;
   for (int i = 0; i < n; i++) {
        if (stalls[i] == 1) {
            start_counting = i + 1;
            break;
        }
    }

    //find where to end counting
    int end_counting = -1;
    for (int i = 0; i < n; i++) {
        if (stalls[i] == 1) {
            end_counting = i;
        }
    }
    

   //find min # of zeros
    int min_count = 1000000;
    int tempcount = 0;
    for (int i = start_counting; i < end_counting; i++) {
        if (stalls[i] == 0) {
            tempcount++;
        }
        else {
            min_count = min(tempcount, min_count);
            tempcount = 0;
        }
    }


   //find max # and 2nd max # of zeros
    int max_count = 0;
    int count = 0;
    int second_max_count;
    for (int i = 0; i < NUM; i++) {
        if (stalls[i] == 0) {
            count++;
        }
        else {
            //second_max_count = count;
            if (count >= max_count){
                second_max_count = max_count;
            }
            max_count = max(count, max_count);
            count = 0;
        }
    }

    if (max_count < start_counting +1){
        if (second_max_count < start_counting + 1){
            cout<< min_count;
            return 0;
        }
    }
    if (max_count < NUM - end_counting - 1){
        if (second_max_count < start_counting + 1){
            cout << min_count;
            return 0;
        }
    }



    
    //cout << count + 1 << endl;
    //cout << max(count, max_count) + 1;
    /*cout << second_max_count << endl;;
    cout << min_count << endl;;
    cout << max_count << endl;;*/

    //fuckin weird edge case and i cannot get the code for this part right

    int max_count_thirds;
    max_count_thirds = (max_count+1)/3;
    if (max_count_thirds < (second_max_count+1)/2){
        max_count_thirds = 1000000000;
    }
    max_count = (max_count+1)/2;


    /*if ((second_max_count+1)/2 <= max_count/2 && max_count <= min_count) {
        cout << (max_count*2)/3;;
        return 0;
    }
        if ((second_max_count+1)/2 <= (max_count*2)/3 && (second_max_count+1)/2 <= min_count) {
        cout << (second_max_count+1)/2;;
        return 0;
    }
        if ((second_max_count+1)/2 <= (max_count*2)/3 && max_count >= min_count) {
        cout << min_count;;
        return 0;
    }*/


    second_max_count = (second_max_count+1)/2;

    /*cout << second_max_count << endl;;
    cout << min_count << endl;;
    cout << max_count << endl;;*/

    int smallest = max_count;
    if (min_count < smallest) {
        smallest = min_count;
    }
    if (second_max_count < smallest) {
        smallest = second_max_count;
    }
    if (max_count_thirds < smallest) {
        smallest = max_count_thirds;
    }

    cout << smallest;
    return 0;
    
    /*if (second_max_count <= max_count && second_max_count <= min_count) {
        cout << second_max_count;;
        return 0;
    }
    if (min_count <= max_count && second_max_count >= min_count) {
        cout << min_count;;
        return 0;
    }
    if (second_max_count >= max_count && max_count <= min_count) {
        cout << max_count;;
        return 0;
    }*/
    
}
