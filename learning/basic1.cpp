//add a header file library that lets us 
//work with input and output objects, such as 
//cout (used in line 5). Header files add 
//functionality to C++ programs.
#include <iostream>

//other header file libraries
#include <stdio.h>

//so I don't have to do the std:: thing
using namespace std;

int main(){
    //print things, no new line
    //this would print as hihello
    cout << "hi";
    cout << "hello";
    
    //for new line, put \n INSIDE the string
    cout << "hi \n";
    cout << "hello";
    //two \n will be a blank line
    cout << "hi \n\n";
    cout << "hello";

    //OR, use the endl manipulator
    //most people use \n though
    cout << "hi" << endl;
    cout << "hello";

    // \n is called an escape sequence that
    //forces the cursor to change its position 
    //to the beginning of the next line on the 
    //screen, resulting in a new line.

    //other valid escape sequences include:
    // \t Creates a horizontal tab
    // \\ Inserts a backslash character (\)
    // \" Inserts a double quote character
}