#include <iostream>

using namespace std;

double f(double);
double g(double);
double Trapm(double, int, double[]);

int main(){
   double a, b, *y;
   int n;
   cout << "Problem 1" << endl << "Enter the value of a: ";
   cin>>a;
   cout<<"Enter the value of b: ";
   cin>>b;
   cout << endl;
   bool first = true;
   char cont = 'y';

   while (cont == 'y'){

	   cout << "Enter the value of n: ";
	   cin >> n;
	   cout << endl;

	   y = new double[n];

	   double h = (b - a) / n;
	   for (int i = 0; i < n; i++){
		   y[i] = f(a + i*h);
	   }
	   double I = Trapm(h, n, y);
	   cout << "a: " << a << endl;
	   cout << "b: " << b << endl;
	   cout << "n: " << n << endl;
	   cout << "h: " << h << endl;
	   cout << "I: " << I << endl;

	   cout << endl << "Continue?(y/n)";
	   cin >> cont;
   }
   return 0;
}

double Trapm(double h, int n, double f[]){
   double sum = f[0];
   for(int i = 1; i < n-1; i++){
      sum = sum + 2 * f[i];
   }
   sum = (sum + f[n-1]);
   return (h * sum/2);
}

double f(double x){
	return (sqrt(9.8*68.1 / 0.25)*log(cosh(sqrt(9.8*0.25 / 68.1)*x))) / sqrt(9.8*0.25 / 68.1);
}