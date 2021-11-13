#ifndef LAB1_ZAD_DOM_CALC_H
#define LAB1_ZAD_DOM_CALC_H

//int ** generateMatrix(int kolumny, int wiersze) {}
int ** fillMatrix(int w, int k, int ** tab);
double ** fillMatrix(int w, int k, double ** tab);
void show(int ** tab,int w, int k);
void show(double ** tab,int w, int k);
int** addMatrix(int ** tab1, int ** tab2, int w, int k);
double** addMatrix(double ** tab1, double ** tab2, int w, int k);
int** subtractMatrix(int ** tab1, int ** tab2, int w, int k);
double** subtractMatrix(double ** tab1, double ** tab2, int w, int k);
int** multiplyMatrix(int ** tab1, int ** tab2, int k1, int k2, int w);
double** multiplyMatrix(double ** tab1, double ** tab2, int k1, int k2, int w);
int** multiplyByScalar(int ** tab, int w, int k, int skalar);
double** multiplyByScalar(double ** tab, int w, int k, double skalar);
int** transpozeMatrix(int ** tab, int w, int k);
double** transpozeMatrix(double ** tab, int w, int k);
int** powerMatrix(int ** tab, int w, int k, unsigned int potega);
double** powerMatrix(double ** tab, int w, int k, unsigned int potega);
int determinantMatrix(int ** tab, int w, int k);
int determinantMatrix(double ** tab, int w, int k);
bool matrixIsDiagonal(int ** tab, int w, int k);
bool matrixIsDiagonal(double ** tab, int w, int k);
void swap(int * a, int * b);
void swap(double * a, double * b);
void sortRow(int ** tab, int w, int k);
void sortRow(double ** tab, int w, int k);
void sortRowsInMatrix(int ** tab, int w, int k);
void sortRowsInMatrix(double ** tab, int w, int k);
void help();
void matrixDel(int **matrix,int w);
void matrixDel(double **matrix,int w);
template< typename T >
T** matrix_allocate(const int w, const int k) {
    T** matrix = new T*[w];
    for(int i = 0; i < w; i++) {
        matrix[i] = new T[k];
    }
    return matrix;
}


#endif //LAB1_ZAD_DOM_CALC_H
