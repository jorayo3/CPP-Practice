#include <iostream>
using namespace std;

int main() {
	int first = -1;
	int second = -1;
	int subtotal = 0;
	int sum = 0;
	cout << "Please enter integers.\n";
	do {
		second = first;
		cin >> first;
		subtotal += first;
		if (first == 0 && second != 0) { //condition prevents printing subtotal twice
			cout << "Subtotal " << subtotal << "\n";
			sum += subtotal; //add subtotal and reset
			subtotal = 0;
		}
	}
	while (first != 0 || second != 0);
	
	cout << "Total " << sum;
	
}
