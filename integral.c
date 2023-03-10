#include <stdio.h>
#include<conio.h>
#include <math.h>

double func(double x) {
    // Define your function to be integrated here
    return log(1+x);
}

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (func(a) + func(b))/2 ;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }

    return h * sum;
}

int main() {
     double a=0; /*lower limit of integration*/
    double b=3.14;  // upper limit of integration
  // number of intervals
int n=1;
    double result = trapezoidal(a, b, n);

    printf("Result: %f\n", result);

    return 0;
}
// more we increase the value of n more the exact answer we get 
    