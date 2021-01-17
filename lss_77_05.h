#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lss_75_05(int n, double* A, double* B, double* X, double* tmp);
double *getPointerByIndexes(int i, int j, int n, double *Arr);
void Swap2Rows(int row_1, int row_2, int n, double *Arr);
double *MaxRow(int column, int SearchFrom, int n, double *Arr);