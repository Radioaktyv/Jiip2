
#include<iostream>
#include "calc.h"
using namespace std;
int add(char** argv){

    return stoi(argv[2])+stoi(argv[3]);
}
int subtract(char** argv){

    return stoi(argv[2])-stoi(argv[3]);
}
int volume(char** argv){
    for (int i = 2; i <= 5; i++)
    {
        if (stoi(argv[i]) == 0)
        {
            cout <<"Zly argument, popraw sie"<< endl;
            help();
            return -1;
        }
    }
    return (stoi(argv[2])+stoi(argv[3]))/2*stoi(argv[4])*stoi(argv[5]);
}
void help(){
    cout << "Simple calculator" << endl << "simpleCalc [nazwa dzialania]" << endl;
    cout << "Dzialania:"<< endl;
    cout << "add [a] [b]" << endl << "\t Dodawanie dwoch liczb ([a] i [b]) calkowitych." << endl;
    cout << "substract [a] [b]" << endl << "\t Odejmowanie dwoch liczb ([a] i [b]) calkowitych." << endl;
    cout << "volume [a] [b] [h] [H]" << endl << "\t Oblicznanie objetosci graniastoslupa z trapezem u podstawy."<<
         endl <<"\t Gdzie [a] i [b] to podstawy trapezu, [h] wysokosc trapezu, [H] wysokosc graniastoslupa" << endl;
    cout << "help" << endl << "\t wyswietla dokumentacje";
}