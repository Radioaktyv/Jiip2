#include <iostream>
#include "include/calc.h"
using namespace std;

int main(int argc, char** argv)
{
    if (string(argv[1]) == "add" && argc == 4)
        cout << add(argv);
    else if (string(argv[1]) == "subtract" && argc == 4)
        cout << subtract(argv);
    else if (string(argv[1]) == "volume" && argc == 6){
        auto wynik = volume(argv);
       if (wynik != -1) cout << wynik;
    }

    else if (string(argv[1])== "help" && argc == 2)
    help();
    else
    {
        cout << "zla liczba argumentow" << endl;
        help();
    }

    return 0;
}