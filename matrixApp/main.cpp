#include "MatrixLib/MatrixLib.h"
#include <iostream>
#include <stdbool.h>
using namespace std;
int main(int argc, char** argv){
    // iniciacja zmiennych
    int kolumny;
    int wiersze;
    int rodzaj_zmiennej;
    // Zczytanie wielkości tablicy 1
    do {
        cout << "Dla int wpisz 1, dla double wpisz 2:";
        cin >> rodzaj_zmiennej;
    }while(!(rodzaj_zmiennej == 1 || rodzaj_zmiennej == 2));
    if (rodzaj_zmiennej == 1)
        cout << "Wybrales rodzaj zmiennej typu INT"<<endl;
    else
        cout << "Wybrales rodzaj zmiennej typu DOUBLE"<<endl;



    //sprawdzenie argumentu
    if (string(argv[1]) == "addMatrix"){
        cout << "Podaj ilosc kolumn macierzy 1 i 2:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy 1 i 2:" << endl;
        cin >> wiersze;
        if (rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        int** tab2 = matrix_allocate<int>(wiersze,kolumny);
        int** output = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        tab2 = fillMatrix(wiersze,kolumny,tab2);
        output = addMatrix(tab,tab2,wiersze,kolumny);
        show(output,wiersze,kolumny);
        matrixDel(tab,wiersze);
        matrixDel(tab2,wiersze);
        matrixDel(output,wiersze);}
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            double** tab2 = matrix_allocate<double>(wiersze,kolumny);
            double** output = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            tab2 = fillMatrix(wiersze,kolumny,tab2);
            output = addMatrix(tab,tab2,wiersze,kolumny);
            show(output,wiersze,kolumny);
            matrixDel(tab,wiersze);
            matrixDel(tab2,wiersze);
            matrixDel(output,wiersze);}
        }
    else if (string(argv[1]) == "subtractMatrix") {
        cout << "Podaj ilosc kolumn macierzy 1 i 2:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy 1 i 2:" << endl;
        cin >> wiersze;
        if (rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        int** tab2 = matrix_allocate<int>(wiersze,kolumny);
        int** output = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        tab2 = fillMatrix(wiersze,kolumny,tab2);
        output = subtractMatrix(tab,tab2,wiersze,kolumny);
        show(output,wiersze,kolumny);
        matrixDel(tab,wiersze);
        matrixDel(tab2,wiersze);
        matrixDel(output,wiersze);}
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            double** tab2 = matrix_allocate<double>(wiersze,kolumny);
            double** output = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            tab2 = fillMatrix(wiersze,kolumny,tab2);
            output = subtractMatrix(tab,tab2,wiersze,kolumny);
            show(output,wiersze,kolumny);
            matrixDel(tab,wiersze);
            matrixDel(tab2,wiersze);
            matrixDel(output,wiersze);
        }
    }
    else if (string(argv[1]) == "multiplyByScalar"){
        if(rodzaj_zmiennej == 1){
        int skalar;
        cout << "Podaj ilosc kolumn macierzy:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy:" << endl;
        cin >> wiersze;
        cout << "Podaj skalar:" << endl;
        cin >> skalar;
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        int** output = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        output = multiplyByScalar(tab,wiersze,kolumny,skalar);
        show(output,wiersze,kolumny);
        matrixDel(tab,wiersze);
        matrixDel(output,wiersze);}
        else {
            double skalar;
            cout << "Podaj ilosc kolumn macierzy:" << endl;
            cin >> kolumny;
            cout << "Podaj ilosc wierszy macierzy:" << endl;
            cin >> wiersze;
            cout << "Podaj skalar:" << endl;
            cin >> skalar;
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            double** output = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            output = multiplyByScalar(tab,wiersze,kolumny,skalar);
            show(output,wiersze,kolumny);
            matrixDel(tab,wiersze);
            matrixDel(output,wiersze);
        }
    }
    else if (string(argv[1]) == "multiplyMatrix"){
        cout << "Podaj ilosc kolumn macierzy 1:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy 1:" << endl;
        cin >> wiersze;
        int wiersze2,kolumny2;
        cout << "Podaj ilosc kolumn macierzy 2:" << endl;
        cin >> kolumny2;
        cout << "Podaj ilosc wierszy macierzy 2:" << endl;
        cin >> wiersze2;
        if(kolumny!=wiersze2){
            cout << "Nie mozna pomnozyć tych macierzy";
        }
        else{
            if(rodzaj_zmiennej == 1){
            int** tab = matrix_allocate<int>(wiersze,kolumny);
            int** tab2 = matrix_allocate<int>(wiersze2,kolumny2);
            int** output = matrix_allocate<int>(wiersze,kolumny2);
            tab = fillMatrix(wiersze,kolumny,tab);
            cout << "XD";
            tab2 = fillMatrix(wiersze2,kolumny2,tab2);
            output = multiplyMatrix(tab,tab2,kolumny,kolumny2,wiersze);
            show(output,wiersze,kolumny2);
            matrixDel(tab,wiersze);
            matrixDel(output,wiersze);
        }
            else{
                double** tab = matrix_allocate<double>(wiersze,kolumny);
                double** tab2 = matrix_allocate<double>(wiersze2,kolumny2);
                double** output = matrix_allocate<double>(wiersze,kolumny2);
                tab = fillMatrix(wiersze,kolumny,tab);
                tab2 = fillMatrix(wiersze2,kolumny2,tab2);
                output = multiplyMatrix(tab,tab2,kolumny,kolumny2,wiersze);
                show(output,wiersze,kolumny2);
                matrixDel(tab,wiersze);
                matrixDel(output,wiersze);
            }
        }
    }
    else if (string(argv[1]) == "transpozeMatrix"){
        cout << "Podaj ilosc kolumn macierzy:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy:" << endl;
        cin >> wiersze;
        if(rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        int** output = matrix_allocate<int>(kolumny,wiersze);
        tab = fillMatrix(wiersze,kolumny,tab);
        output = transpozeMatrix(tab,wiersze,kolumny);
        show(output,kolumny,wiersze);
        matrixDel(tab,wiersze);
        matrixDel(output,kolumny);}
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            double** output = matrix_allocate<double>(kolumny,wiersze);
            tab = fillMatrix(wiersze,kolumny,tab);
            output = transpozeMatrix(tab,wiersze,kolumny);
            show(output,kolumny,wiersze);
            matrixDel(tab,wiersze);
            matrixDel(output,kolumny);
        }
    }
    else if (string(argv[1]) == "powerMatrix"){
        unsigned int potega;
        cout << "Podaj ilosc kolumn macierzy:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy:" << endl;
        cin >> wiersze;
        cout << "Podaj stopien potegi:" << endl;
        cin >> potega;
        if (rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        int** output = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        output = powerMatrix(tab,wiersze,kolumny,potega);
        show(output,wiersze,kolumny);
        matrixDel(tab,wiersze);
        matrixDel(output,wiersze);}
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            double** output = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            output = powerMatrix(tab,wiersze,kolumny,potega);
            show(output,wiersze,kolumny);
            matrixDel(tab,wiersze);
            matrixDel(output,wiersze);
        }
    }
    else if (string(argv[1]) == "determinantMatrix"){
        cout << "Podaj ilosc kolumn macierzy:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy:" << endl;
        cin >> wiersze;
        if(rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        int output = determinantMatrix(tab,wiersze,kolumny);
        cout << "Wyznacznik macierzy: " << output;
        matrixDel(tab,wiersze);}
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            double output = determinantMatrix(tab,wiersze,kolumny);
            cout << "Wyznacznik macierzy: " << output;
            matrixDel(tab,wiersze);
        }
    }
    else if (string(argv[1]) == "matrixIsDiagonal"){
        cout << "Podaj ilosc kolumn macierzy:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy:" << endl;
        cin >> wiersze;
        if (rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        if(matrixIsDiagonal(tab,wiersze,kolumny))
            cout << "Macierz jest diagonalna";
        else
            cout << "Macierz nie jest diagonalna";
        matrixDel(tab,wiersze);
    }
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            if(matrixIsDiagonal(tab,wiersze,kolumny))
                cout << "Macierz jest diagonalna";
            else
                cout << "Macierz nie jest diagonalna";
            matrixDel(tab,wiersze);
        }
    }
    else if (string(argv[1]) == "sortRow"){
        int ktory;
        cout << "Podaj ilosc kolumn macierzy:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy:" << endl;
        cin >> wiersze;
        cout << "Ktory wiersz chcesz posortowac?";
        cin >> ktory;
        ktory--;
        if (rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        sortRow(tab, ktory,kolumny);
        show(tab,wiersze,kolumny);
        matrixDel(tab,wiersze);}
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            sortRow(tab, ktory,kolumny);
            show(tab,wiersze,kolumny);
            matrixDel(tab,wiersze);
        }
    }
    else if (string(argv[1]) == "sortRowsInMatrix"){
        cout << "Podaj ilosc kolumn macierzy:" << endl;
        cin >> kolumny;
        cout << "Podaj ilosc wierszy macierzy:" << endl;
        cin >> wiersze;
        if (rodzaj_zmiennej == 1){
        int** tab = matrix_allocate<int>(wiersze,kolumny);
        tab = fillMatrix(wiersze,kolumny,tab);
        sortRowsInMatrix(tab,wiersze,kolumny);
        show(tab,wiersze,kolumny);
        matrixDel(tab,wiersze);}
        else{
            double** tab = matrix_allocate<double>(wiersze,kolumny);
            tab = fillMatrix(wiersze,kolumny,tab);
            sortRowsInMatrix(tab,wiersze,kolumny);
            show(tab,wiersze,kolumny);
            matrixDel(tab,wiersze);
        }
    }
    else if (string(argv[1])== "help")
        help();
    else
        help();
}