#include "iostream"

using namespace std;

int myMin(int r, int g, int b);
int myMax(int WinR, int WinG, int WinB);
int win(int A, int C, int r, int g, int b);

int main(){
	int t, A, C, r, g, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> A >> C;
		cin >> r >> g >> b;
		int WinR = win(A, C, r+1, g, b);
		int WinG = win(A, C, r, g+1, b);
		int WinB = win(A, C, r, g, b+1);
		int max = myMax(WinR, WinG, WinB);
		if (WinR == max) {
			cout << "RED" << endl;
		}
		else if (WinG == max) {
			cout << "GREEN" << endl;
		}
		else {
			cout << "BLUE" << endl;
		}
	}
	return 0;
}

int myMin(int r, int g, int b) {
	int min;
	if (r <= b && r <= g)
		min = r;
	else if (g <= b && g <= r)
		min = g;
	else
		min = b;
	return min;
}

int myMax(int WinR, int WinG, int WinB) {
	int max;
	if (WinR >= WinB && WinR >= WinG)
		max = WinR;
	else if (WinG >= WinB && WinG >= WinR)
		max = WinG;
	else
		max = WinB;
	return max;
}

int win(int A, int C, int r, int g, int b) {

	return A * (r * r + b * b + g * g) + C * myMin(r, g, b);
}
