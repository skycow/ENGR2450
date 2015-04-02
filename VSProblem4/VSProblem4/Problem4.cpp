#include <iostream>

using namespace std;

double Trap(double, double, double);
double Simp13(double, double, double, double);
double Simp38(double, double, double, double, double);
double Simp13m(double, int, double[]);
double SimpInt(double, double, int, double[]);

int main(){
	double a, b, *y;
	int n;
	cout << "Problem 4" << endl;
	cout << "Enter the value of a: ";
	cin >> a;
	cout << "Enter the value of b: ";
	cin >> b;
	cout << "Enter the value of n: ";
	cin >> n;

	y = new double[n + 1];

	double h = (b - a) / n;
	double temp;
	for (int i = 0; i < n + 1; i++){
		cout << "Enter value " << i + 1 << ": ";
		cin >> temp;
		y[i]= temp*100;
	}
	double I = SimpInt(a, b, n, y);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "n: " << n << endl;
	cout << "h: " << h << endl;
	cout << "I: " << I << endl;
	return 0;
}

double Trap(double h, double f0, double f1){
	return h / 2 * (f0 + f1);
}

double Simp13(double h, double f0, double f1, double f2){
	return 2 * h*(f0 + 4 * f1 + f2) / 6;
}

double Simp38(double h, double f0, double f1, double f2, double f3){
	return 3 * h*(f0 + 3 * (f1 + f2) + f3) / 8;
}

double Simp13m(double h, int n, double f[]){
	double sum = f[0];
	for (int i = 1; i < n - 2; i += 2){
		sum = sum + 4 * f[i] + 2 * f[i + 1];
	}
	sum = sum + 4 * f[n - 1] + f[n];
	return h*sum / 3;
}

double SimpInt(double a, double b, int n, double f[]){
	double h = (b - a) / n;
	double sum = 0.0;
	if (n == 1){
		sum = Trap(h, f[n - 1], f[n]);
	}
	else{
		int m = n;
		//double odd = (n / 2 - int(n / 2));
		double odd = n % 2;
		if (odd > 0 && n > 1){
			sum = sum + Simp38(h, f[n - 3], f[n - 2], f[n - 1], f[n]);
			m = n - 3;
		}
		if (m > 1){
			sum = sum + Simp13m(h, m, f);
		}
	}
	return sum;
}


