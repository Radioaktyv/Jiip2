#include <iostream>
#include <math.h>
using namespace std;
//prostokat
double pole(double a, double b)
{
    return a*b;
}
//kwadrat
double pole(double a)
{
    return a*a;
}
double pole(double a, double b, double c)
{
    double p = (a + b + c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool sprawdz(double a,double b,double c)
{
    if (a > b && a > c) {
        if (a < (b+c))
            return true;
    }
    if (b > a && b > c) {
        if (b < (a + c))
            return true;
    }
    if ( c > (b+a))
        return true;
    return false;
}
int main() {
    double a,b,c;
    cout << "Podaj bok a" <<endl;
    cin >> a;
    cout << "Podaj bok b" <<endl;
    cin >> b;
    cout << "Podaj bok c" <<endl;
    cin >> c;
    cout << "Pole kwadratu wynosi " << pole(a) << endl;
    cout << "Pole prostokata wynosi "<< pole(a,b) << endl;
    if (sprawdz(a,b,c))
        cout << "Pole trojkata wynosi " << pole(a,b,c)<< endl;
    else
        cout << "Z podanych dlugosci nie mozna stworzyc trojkata"<< endl;
    return 0;
}

