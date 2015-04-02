#include <iostream>

using namespace std;

double Trapm(double, int, double[]);

int main(){
	double a, b, *y;
	int n;
	cout << "Problem 2" << endl;
	cout << "Enter the value of a: ";
	cin >> a;
	cout << "Enter the value of b: ";
	cin >> b;
	cout << "Enter the value of n: ";
	cin >> n;

	y = new double[n+1];

	double h = (b - a) / n;

	for (int i = 0; i < n+1; i++){
		cout << "Enter value " << i + 1 << ": ";
		cin >> y[i];
	}
	double I = Trapm(h, n+1, y);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "n: " << n << endl;
	cout << "h: " << h << endl;
	cout << "I: " << I << endl;
	return 0;
}

double Trapm(double h, int n, double f[]){
	double sum = f[0];
	for (int i = 1; i < n - 1; i++){
		sum = sum + 2 * f[i];
	}
	sum = (sum + f[n - 1]);
	return (h * sum / 2);

}


