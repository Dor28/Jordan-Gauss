#include "lss_77_05.h"

const double EPSILON = 1e-9;

int lss_75_05(int n, double *A, double *B, double *X, double *tmp) {

    int *blackList = (int *) tmp;
    for (int i = 0; i < n; ++i) blackList[i] = 0;

    double *maxElement;
    int rowOfMaxElement;
    int flag = 0;

    for (int i = 0; i < n; ++i) {
        flag = checkConsistency(i, n, A, B);
        if(flag == -1) return 1;

        maxElement = MaxElementInColumn(i, i, blackList, n, A);

        if (fabs(*maxElement) < EPSILON) continue;

        rowOfMaxElement = FindOutRow(maxElement, n, A);

        blackList[i] = 1;

        if (i != rowOfMaxElement)
            Swap2Rows(i, rowOfMaxElement, n, A, B);

        ModuleGaussIteration(i, i, n, A, B);

    }

/*
    for (int i = n - 1; i > -1; --i) {
        ReverseGaussIteration(i, i, n, A, B);
        print_system(n, A, B);
    }
*/
    flag = checkConsistency(n-1, n, A, B);
    if(flag == -1) return 1;
    double elem = *getPointerByIndexes(n - 1, n - 1, n, A);
    if(fabs(elem)<EPSILON)
        X[n-1] = 0;
    else
        X[n - 1] = B[n - 1] / *getPointerByIndexes(n - 1, n - 1, n, A);


    for (int i = n - 2; i >= 0; --i) {
        flag = checkConsistency(i, n, A, B);
        if(flag == -1) return 1;
        for (int j = i + 1; j < n; ++j) {
            B[i] -= *getPointerByIndexes(i, j, n, A) * X[j];
        }
        if (fabs(*getPointerByIndexes(i, i, n, A)) <= EPSILON) X[i] = 0;
        else {
            X[i] = B[i] / *getPointerByIndexes(i, i, n, A);
        }

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

double *MaxElementInColumn(int column, int SearchFrom, int *blackList, int n, double *Arr) {
    double *CurrentMax = getPointerByIndexes(SearchFrom, column, n, Arr);
    for (int i = 0; i < n; i++) {

        if(blackList[i]) continue;

        if (fabs(*CurrentMax) < fabs(*getPointerByIndexes(i, column, n, Arr))) {
            CurrentMax = getPointerByIndexes(i, column, n, Arr);
        }
    }
    return CurrentMax;
}

int ModuleGaussIteration(int i, int j, int n, double *Arr, double *B) {
    //  i, j - индексы элемента в матрице А под которым мы зануляем весь столбец
    double divisor = *getPointerByIndexes(i, j, n, Arr);
    if (fabs(divisor) < EPSILON) return -1;
    for (int k = 0; k < n; ++k) {// цикл по строкам
        if(k==i) continue;
        double element = *getPointerByIndexes(k, j, n, Arr);
        for (int l = 0; l < n; ++l) { // цикл по столбцам

            *getPointerByIndexes(k, l, n, Arr) -= *getPointerByIndexes(i, l, n, Arr) * element / divisor;

        }
        B[k] -= B[i] * element / divisor;
    }

    return 0;
}

int ReverseGaussIteration(int i, int j, int n, double *Arr, double *B) {
    double divisor = *getPointerByIndexes(i, j, n, Arr);
    if (fabs(divisor) < EPSILON) return -1;
    for (int k = i - 1; k > -1; k--) { // строки
        double element = *getPointerByIndexes(k, j, n, Arr);
        for (int l = n - 1; l > -1; l--) { // столбцы
            *getPointerByIndexes(k, l, n, Arr) -= *getPointerByIndexes(i, l, n, Arr) * element / divisor;
        }
        B[k] -= B[i] * element / divisor;
    }
    return 0;
}

int FindOutRow(double *value, int n, double *Arr) { // возвращает номер строки по указателю на элемент
    return (int) (value - Arr) / n;
}

int checkConsistency(int row, int n, double *Arr, double *B) {
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        if (fabs(*getPointerByIndexes(row, i, n, Arr)) > EPSILON) {
            flag = 1;
            break;
        }
    }
    if (!flag) {
        if (fabs(B[row]) > EPSILON) return -1; // no solutions
    }

    return 0;
}