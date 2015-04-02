#include <iostream>

using namespace std;

double Trapun(double[], double[], int);

int main(){
	int n;
	double *x, *y;

	cout << "Problem 5" << endl;
	cout << "Enter the value of n: ";
	cin >> n;

	x = new double[n + 1];
	y = new double[n + 1];

	for (int i = 0; i < n + 1; i++){
		cout << "Enter x value " << i + 1 << ": ";
		cin >> x[i];
	}
	double temp;
	for (int i = 0; i < n + 1; i++){
		cout << "Enter y value " << i + 1 << ": ";
		cin >> temp;
		y[i] = temp*4;
	}
	double I = Trapun(x, y, n);
	cout << endl;
	cout << "n: " << n << endl;
	cout << "I: " << I << endl;
	cout << endl;
	return 0;

}

double Trapun(double x[], double y[], int n){
	double sum = 0;
	for (int i = 1; i < n; i++){
		sum = sum + (x[i] - x[i - 1])*(y[i - 1] + y[i]) / 2;
	}
	return sum;
}