#include "lss_77_05.h"

int lss_75_05(int n, double *A, double *B, double *X, double *tmp) {
    Swap2Rows(0,4, n, A);
    printf("\n%lf \n", *MaxRow(2,0,n, A));
    return 0;
}


double *getPointerByIndexes(int i, int j, int n, double *Arr){
    return Arr + i*n + j ;
}

void Swap2Rows(int row_1, int row_2, int n, double *Arr){
    double *R_1, *R_2;
    double tmp;
    for(int i=0; i<n; i++){
        tmp = *getPointerByIndexes(row_1,i,n, Arr);
        *getPointerByIndexes(row_1,i,n, Arr) = *getPointerByIndexes(row_2,i,n, Arr);
        *getPointerByIndexes(row_2,i,n, Arr) = tmp;
    }
}

double *MaxRow(int column, int SearchFrom, int n, double *Arr){
    double *CurrentMax = getPointerByIndexes(SearchFrom,column, n , Arr);
    for(int i =SearchFrom; i<n; i++){
        if(*CurrentMax < *getPointerByIndexes(i,column, n , Arr)){
            CurrentMax = getPointerByIndexes(i,column, n , Arr);
        }
    }
    return CurrentMax;
}

void ModuleGaussIteration(int i, int j, int n, double *Arr, double *B){
  //  i, j - индексы элемента в матрице А под которым мы зануляем весь столбец
}