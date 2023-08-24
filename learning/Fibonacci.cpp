#include <iostream>
using namespace std;

// define a array of up to MAX_INT
// at fib(N), you store result to arr[N]
// at read tiem, before recursion, read arr[N]
// preset arr[N] to be -1 so you know which is calculated before

int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
    return 0;
}
