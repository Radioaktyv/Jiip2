
#include<iostream>
#include<math.h>
#include "MatrixLib.h"
#include <stdbool.h>
#include <limits>

using namespace std;
void show();

int ** fillMatrix(int w, int k,int ** tab){
    //show(tab,w,k);
    cout << "Podaj wartosci tablicy"<<endl;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
                while (true)
                {
                    cin >> tab[i][j];;
                    if (!cin)
                    {
                        cout << "Podaj liczbe" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    else break;
                }
    return tab;
}
double ** fillMatrix(int w, int k,double ** tab){
    //show(tab,w,k);
    cout << "Podaj wartosci tablicy"<<endl;
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            cin >> tab[i][j];

    return tab;
}
void show(int ** tab, int w, int k){
    for (int i = 0; i < w; i++) {
        cout << endl;
        for (int j = 0; j < k; j++)
            cout << tab[i][j] << " ";
    }
}
void show(double ** tab, int w, int k){
    for (int i = 0; i < w; i++) {
        cout << endl;
        for (int j = 0; j < k; j++)
            cout << tab[i][j] << " ";
    }
}
int** addMatrix(int ** tab1, int ** tab2, int w, int k) {
    for (int i = 0; i < w; i++) {
        cout << endl;
        for (int j = 0; j < k; j++){
            tab1[i][j]+=tab2[i][j];
           // cout << "wiersz:"<< j <<" kolumna:" << i << " " << tab1[i][j] <<endl;
           }
    }
    return tab1;
}
double** addMatrix(double ** tab1, double ** tab2, int w, int k) {
    for (int i = 0; i < w; i++) {
        cout << endl;
        for (int j = 0; j < k; j++){
            tab1[i][j]+=tab2[i][j];
            // cout << "wiersz:"<< j <<" kolumna:" << i << " " << tab1[i][j] <<endl;
        }
    }
    return tab1;
}
int** subtractMatrix(int ** tab1, int ** tab2, int w, int k) {
    for (int i = 0; i < w; i++) {
        cout << endl;
        for (int j = 0; j < k; j++)
            tab1[i][j]-=tab2[i][j];
    }
    return tab1;
}
double** subtractMatrix(double ** tab1, double ** tab2, int w, int k) {
    for (int i = 0; i < w; i++) {
        cout << endl;
        for (int j = 0; j < k; j++)
            tab1[i][j]-=tab2[i][j];
    }
    return tab1;
}
int** multiplyMatrix(int ** tab1, int ** tab2, int k1, int k2, int w) {
    int **temp = matrix_allocate<int>(w, k2);
    for(int i = 0; i < w; i++)
        for(int j = 0; j < k2; j++)
        {
            temp[i][j]=0;
        }
    for(int i = 0; i < w; i++)
        for(int j = 0; j < k2; j++){
            for(int k = 0; k < k1; k++)
            {
                temp[i][j] += tab1[i][k] * tab2[k][j];
            }}
    return temp;
}
double** multiplyMatrix(double ** tab1, double ** tab2, int k1, int k2, int w) {
    double **temp = matrix_allocate<double>(w, k2);
    for(int i = 0; i < w; i++)
        for(int j = 0; j < k2; j++)
        {
            temp[i][j]=0;
        }
    for(int i = 0; i < w; i++)
        for(int j = 0; j < k2; j++){
            for(int k = 0; k < k1; k++)
            {
                temp[i][j] += tab1[i][k] * tab2[k][j];
            }}
    return temp;
}
int** multiplyByScalar(int ** tab, int w, int k, int skalar) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++)
            tab[i][j]*=skalar;
    }
    return tab;
}
double** multiplyByScalar(double ** tab, int w, int k, double skalar) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++)
            tab[i][j]*=skalar;
    }
    return tab;
}

int** transpozeMatrix(int ** tab, int w, int k) {
    int** temp = matrix_allocate<int>(k,w);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < w; j++)
            temp[i][j] = tab[j][i];
    }
    return temp;
}
double** transpozeMatrix(double ** tab, int w, int k) {
    double** temp = matrix_allocate<double>(k,w);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < w; j++)
            temp[i][j] = tab[j][i];
    }
    return temp;
}

int** powerMatrix(int ** tab, int w, int k, unsigned int potega){
    int** temp = matrix_allocate<int>(w,k);
    temp = tab;
    for (int i = 1; i < potega; i++){
        tab = multiplyMatrix(tab, temp, k,k,w);
    }
    return tab;
}
double** powerMatrix(double ** tab, int w, int k, unsigned int potega){
    double** temp = matrix_allocate<double>(w,k);
    temp = tab;
    for (int i = 1; i < potega; i++){
        tab = multiplyMatrix(tab, temp, k,k,w);
    }
    return tab;
}
int determinantMatrix(int ** tab, int w, int k) {
    if(k != w){
        cout << "Ta macierz nie jest macierzą kwadratową";
        return 0  ;
    }
    else {
        int det = 0;
        int** temp = matrix_allocate<int>(w,k);
        if (w == 2)
            return ((tab[0][0] * tab[1][1]) - (tab[1][0] * tab[0][1]));
        else {
            for (int x = 0; x < w; x++) {
                int subi = 0;
                for (int i = 1; i < w; i++) {
                    int subj = 0;
                    for (int j = 0; j < w; j++) {
                        if (j == x)
                            continue;
                        temp[subi][subj] = tab[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * tab[0][x] * determinantMatrix( temp, w - 1,k - 1 ));
            }
        }
        return det;
    }
}
int determinantMatrix(double ** tab, int w, int k) {
    if(k != w){
        cout << "Ta macierz nie jest macierzą kwadratową";
        return 0  ;
    }
    else {
        int det = 0;
        int** temp = matrix_allocate<int>(w,k);
        if (w == 2)
            return ((tab[0][0] * tab[1][1]) - (tab[1][0] * tab[0][1]));
        else {
            for (int x = 0; x < w; x++) {
                int subi = 0;
                for (int i = 1; i < w; i++) {
                    int subj = 0;
                    for (int j = 0; j < w; j++) {
                        if (j == x)
                            continue;
                        temp[subi][subj] = tab[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * tab[0][x] * determinantMatrix( temp, w - 1,k - 1 ));
            }
        }
        return det;
    }
}
bool matrixIsDiagonal(int ** tab, int w, int k)  {
    if(k != w){
        cout << "Ta macierz nie jest macierza kwadratowa";
        return false  ;
    }
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            if ((i != j) && (tab[i][j] != 0))
                return false;
    return true;
}
bool matrixIsDiagonal(double ** tab, int w, int k)  {
    if(k != w){
        cout << "Ta macierz nie jest macierza kwadratowa";
        return false  ;
    }
    for (int i = 0; i < w; i++)
        for (int j = 0; j < k; j++)
            if ((i != j) && (tab[i][j] != 0))
                return false;
    return true;
}
void swap(int * a, int * b) {
    int temp = * a;
    * a = * b;
    * b = temp;
}
void swap(double * a, double * b) {
    int temp = * a;
    * a = * b;
    * b = temp;
}
void sortRow(int ** tab, int w, int k) {
    int i, j;
    for (i = 0; i < k-1; i++)

        // Last i elements are already in place
        for (j = 0; j < k-i-1; j++)
            if (tab[w][j] > tab[w][j+1])
                swap(&tab[w][j], &tab[w][j+1]);
}
void sortRow(double ** tab, int w, int k) {
    int i, j;
    for (i = 0; i < k-1; i++)

        // Last i elements are already in place
        for (j = 0; j < k-i-1; j++)
            if (tab[w][j] > tab[w][j+1])
                swap(&tab[w][j], &tab[w][j+1]);
}
void sortRowsInMatrix(int ** tab, int w, int k) {
    for (int i = 0; i < w; i++)
        sortRow(tab,i,k);
}
void sortRowsInMatrix(double ** tab, int w, int k) {
    for (int i = 0; i < w; i++)
        sortRow(tab,i,k);
}
void help() {
    cout << "matrixApp" << endl << "Matrixcalc [nazwa dzialania]" << endl;
    cout << "Dzialania na macierzach:" << endl;
    cout << "addMatrix" << endl << "\t Dodawanie dwoch macierzy o tych samych wymiarach"<<endl;
    cout << "subtractMatrix" << endl << "\t Odejmowanie dwoch macierzy o tych samych wymiarach"<<endl;
    cout << "multiplyMatrix" << endl << "\t Mnozenie dwoch macierzy gdzie kolumny pierwszej macierzy sa rowne liczbie wierszy drugiej macierzy"<<endl;
    cout << "multiplyByScalar" << endl << "\t Mnozenie dowolnej macierzy przez skalar"<<endl;
    cout << "transpozeMatrix" << endl << "\t Transponowanie macierzy"<<endl;
    cout << "powerMatrix" << endl << "\t Potegowanie macierzy gdzie stopien potegi jest liczba dodatnia"<<endl;
    cout << "determinantMatrix" << endl << "\t Obliczenie wyznacznika podanej macierzy" << endl;
    cout << "matrixIsDiagonal" << endl << "\t Sprawdzenie czy macierz jest diagonalna" << endl;
    cout << "sortRow" << endl << "\t Posortowanie wybranego wiersza. (Liczba 1 odpowiada pierwszemu wierszowi)"<< endl;
    cout << "sortRowsInMatrix" << endl<< "\t Posorowanie wszystkich wierszy w macierzy" << endl;
    cout << "help" << endl << "\t wyswietla dokumentacje";
}

void matrixDel(int **matrix,int k) {
    if(matrix){
        for(int i = k; i <= 0; --i){
            delete [] matrix[i];
        }
        delete [] matrix;
    }
}
void matrixDel(double **matrix,int k) {
    if(matrix){
        for(int i = k; i <= 0; --i){
            delete [] matrix[i];
        }
        delete [] matrix;
    }
}

