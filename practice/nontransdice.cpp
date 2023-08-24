//#include <bits/stdc++.h>
#include "a_headerfiles.hpp";
using namespace std;

using Die = array<int, 4>;

bool beats(const Die& a, const Die& b) {
	int wins = 0, losses = 0;
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) {
		if (a[i] > b[j]) ++wins;
		if (a[i] < b[j]) ++losses;
	}
	return wins > losses;
}

bool non_transitive(const Die& A, const Die& B) {
	for(int a = 1; a <= 10; a++) for(int b = 1; b <= 10; b++) for(int c = 1; c <= 10; c++) for(int d = 1; d <= 10; d++) {
		Die C{a,b,c,d};
		if (beats(A,B) && beats(B,C) && beats(C,A)) return 1;
		if (beats(B,A) && beats(C,B) && beats(A,C)) return 1;
	}
	return 0;
}

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		Die A, B;
		for(int j = 0; j < 4; j++) cin >> A[j];
		for(int j = 0; j < 4; j++) cin >> B[j];
		if(non_transitive(A,B)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}