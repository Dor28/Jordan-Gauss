#include "lss_77_05.h"

const double EPSILON = 1e-9;
int lss_75_05(int n, double *A, double *B, double *X, double *tmp) {
    double *maxElement;
    int rowOfMaxElement;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        flag = checkConsistency(i, n, A, B);
        maxElement = MaxElementInColumn(i,i, n, A);
        rowOfMaxElement = FindOutRow(maxElement, n , A);
       Swap2Rows(i,rowOfMaxElement, n , A, B);
       ModuleGaussIteration( i,  i,  n, A,  B);
    }

    for (int i = n; i > -1; i--) {
        ReverseGaussIteration(i, i, n, A, B);
    }

    X[n-1] = B[n-1] / *getPointerByIndexes(n-1, n-1, n, A);
    for (int i = n - 2; i >= 0 ; --i) {
        for (int j = i + 1; j < n; ++j) {
            B[i]-= *getPointerByIndexes(i, j, n, A) * X[j];
        }
        if(fabs(*getPointerByIndexes(i,i,n,A))<=EPSILON) X[i]=0;
        else{
            X[i] = B[i] / *getPointerByIndexes(i, i, n, A);
        }

    }
    if (flag == 3){
        printf("\nSystem has no solutions\n");
        return 1;
    }
    return 0;
}


double *getPointerByIndexes(int i, int j, int n, double *Arr) {
    return Arr + i * n + j;
}

void Swap2Rows(int row_1, int row_2, int n, double *Arr, double *B) {
    double tmp;
    for (int i = 0; i < n; i++) {
        tmp = *getPointerByIndexes(row_1, i, n, Arr);
        *getPointerByIndexes(row_1, i, n, Arr) = *getPointerByIndexes(row_2, i, n, Arr);
        *getPointerByIndexes(row_2, i, n, Arr) = tmp;
    }
    tmp = 0.0;
    tmp = B[row_1];
    B[row_1] = B[row_2];
    B[row_2] = tmp;
}

double *MaxElementInColumn(int column, int SearchFrom, int n, double *Arr) {
    double *CurrentMax = getPointerByIndexes(SearchFrom, column, n, Arr);
    for (int i = SearchFrom; i < n; i++) {
        if (*CurrentMax < *getPointerByIndexes(i, column, n, Arr)) {
            CurrentMax = getPointerByIndexes(i, column, n, Arr);
        }
    }
    return CurrentMax;
}

int ModuleGaussIteration(int i, int j, int n, double *Arr, double *B) {
    //  i, j - индексы элемента в матрице А под которым мы зануляем весь столбец
    double divisor = *getPointerByIndexes(i, j, n, Arr);
    if (fabs(divisor) < EPSILON) return -1;
    for (int k = i + 1; k < n; ++k) {// цикл по строкам

        double element = *getPointerByIndexes(k, j, n, Arr);
        for (int l = 0; l < n; ++l) { // цикл по столбцам

            *getPointerByIndexes(k, l, n, Arr) -= *getPointerByIndexes(i, l, n, Arr) * element / divisor;

        }
        B[k] -= B[i] * element / divisor;
    }

    return 0;
}

int FindOutRow(double *value, int n, double *Arr){ // возвращает номер строки по указателю на элемент
    return (int)(value - Arr)/n;
}

int ReverseGaussIteration(int i, int j, int n, double *Arr, double *B){
    double divisor = *getPointerByIndexes(i,j,n, Arr);
    if (fabs(divisor) < EPSILON ) return -1;
    for (int k = i-1; k > -1 ; k--) {
        double element = *getPointerByIndexes(k, j, n, Arr);
        for (int l = n-1; l >-1; l--) {
            *getPointerByIndexes(k, l, n, Arr) -= *getPointerByIndexes(i, l, n, Arr) * element / divisor;
        }
        B[k] -= B[i] * element / divisor;
    }
    return 0;
}

int checkConsistency(int row,  int n, double *Arr, double *B) {
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        if(fabs(*getPointerByIndexes(row,i,n,Arr))>EPSILON){
           flag = 0;
        }
        else {
           flag = 1;
        }
    }
    if (flag==1){
       // if (fabs(B[row]) < EPSILON) flag = 2; // infinity solutions
        if (fabs(B[row]) > EPSILON) flag = 3; // no solutions
    }

    return flag;
}
