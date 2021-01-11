#include "lss_77_05.h"

int read_input(char *input_file, double **A, double **B, int *n){
    int i, check_input;
    FILE *input = fopen(input_file, "r");
    check_input = fscanf(input, "%d", n);
    if (check_input == EOF){
        return 4;
    }
    if (check_input ==0 || *n <=0){
        return 1;
    }
    *A = malloc((*n) * (*n) * sizeof(double ));
    *B = malloc((*n) * sizeof(double ));

    for(i=0;i<(*n)*(*n);i++){
        check_input = fscanf(input, "%lf", (*A + i));
        if (check_input==EOF){
            return 2;
        }
        if(check_input==0){
            return 3;
        }
    }
    for(i=0; i < (*n); i++){
        check_input = fscanf(input, "%lf", (*B+i));
        if (check_input==EOF){
            return 5;
        }
        if(check_input==0){
            return 3;
        }
    }
    fclose(input);
    return 0;
}

void write_answer(char *output_file, int n, const double *X, int result){
    int i;
    FILE *output = fopen(output_file, "w");
    if(result!=0){
        fprintf(output, "%d\n", 0);
    }
    else{
        fprintf(output, "%d\n", n);
        for(i=0; i<n; i++){
            fprintf(output,"1.9lf\n", *(X+1));
        }
    }
    fclose(output);
}
void print_system(int n, double *A, double *B) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%1.9lf ", A[i * n + j]);
        }
        printf("\t%1.9lf", B[i]);
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    int n =0;
    double *A, *B;
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    read_input(input_file,&A, &B, &n);
    print_system(n, A, B);
    free(A);
    free(B);

    return 0;
};