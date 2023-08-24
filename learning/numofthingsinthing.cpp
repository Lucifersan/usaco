//#include <bits/stdc++.h>
#include "a_headerfiles.hpp"

using namespace std;

vector<int> indicesOfThing;

int main() {
  //get input
  string everything;
  cin >> everything;

  //take input, go through, put the indexes of the location of things in array
  for (int i = 0; i < everything.size(); i++) {
    if (everything[i] == 'X') indicesOfThing.push_back(i);
  }

  //get input for.... number of queries...?
  //oh I understand, basically theres multiple test cases
  int queries;
  cin >> queries;

  //for loop thru the queries
  for (int i = 0; i < queries; i++) {
    //get input for left and right indexes
    int left, right;
    cin >> left >> right;

    //probably write this part a lot messier and more basic to match with skill lvl... ethan u literally made me
    //unintentionally cheat >:( bad ethan

    //lower_bound(indicesOfThing.begin(), indicesOfThing.end(), left) gets the min index between the left index,
    //the first thing, and the last thing
    //indicesOfThing.begin() gets the index of the first thing–this gives the index from the vector
    int leftBound = lower_bound(indicesOfThing.begin(), indicesOfThing.end(), left) - indicesOfThing.begin();

    //basically does the same thing for the right bound
    int rightBound = upper_bound(indicesOfThing.begin(), indicesOfThing.end(), right) - indicesOfThing.begin();

    //if u subtrect the index of the last thing that matters from the first thing that matters, 
    //u get the number of things
    cout << (rightBound - leftBound) << endl;
  }
}