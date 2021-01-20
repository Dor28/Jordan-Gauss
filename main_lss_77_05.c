#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lss_77_05.h"

char flag_debug = 0, flag_errors = 0, flag_print_matrix = 0, flag_time = 0, flag_help = 0, max_iter = 0;


int validateFile(char const *filename) {
    FILE *f = fopen(filename, "rb");
    int err = f == NULL;

    if (!err) {
        fclose(f);
    }

    return err;
}

unsigned int stringLength(char const *input) {
    int length = 0;

    while (input[length] != '\0') {
        length++;
    }

    return length;
}

int validateParams(int argc, char **argv) {
    int i, count = 0;

    if (argc == 1) {
        return 0;
    }

    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && stringLength(argv[i]) == 2) {
            switch (argv[i][1]) {
                case 'd': {
                    flag_debug = 1;
                    break;
                }
                case 'h': {
                    flag_help = 1;
                    break;
                }
                case '?': {
                    flag_help = 1;
                    break;
                }
                case 'e': {
                    flag_errors = 1;
                    break;
                }
                case 'p': {
                    flag_print_matrix = 1;
                    break;
                }
                case 't': {
                    flag_time = 1;
                    break;
                }
                default: {
                    return 1;  // no such flag
                }
            }
        } else if (argv[i][0] == '-') {
            return 1;  // no such flag
        } else {
            count++;
        }
    }

    if (count > 2) {
        return 2;  // too much filenames
    }

    return 0;
}

int read_input(char *input_file, double **A, double **B, int *n) {
    int i, check_input;
    FILE *input = fopen(input_file, "r");
    check_input = fscanf(input, "%d", n);
    if (check_input == EOF) {
        return 4;
    }
    if (check_input == 0 || *n <= 0) {
        return 1;
    }
    *A = malloc((*n) * (*n) * sizeof(double));
    *B = malloc((*n) * sizeof(double));

    for (i = 0; i < (*n) * (*n); i++) {
        check_input = fscanf(input, "%lf", (*A + i));
        if (check_input == EOF) {
            return 2;
        }
        if (check_input == 0) {
            return 3;
        }
    }
    for (i = 0; i < (*n); i++) {
        check_input = fscanf(input, "%lf", (*B + i));
        if (check_input == EOF) {
            return 5;
        }
        if (check_input == 0) {
            return 3;
        }
    }
    fclose(input);
    return 0;
}

void write_answer(char *output_file, int n, const double *X, int result) {
    int i;
    FILE *output = fopen(output_file, "w");
    if (result != 0) {
        fprintf(output, "%d\n", 0);
    } else {
        fprintf(output, "%d\n", n);
        for (i = 0; i < n; i++) {
            fprintf(output, "%1.9lf\n", *(X + i));
        }
    }
    fclose(output);
}

void print_system(int n, double *A, double *B) {
    int i, j;
    printf("%d\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%1.9lf ", A[i * n + j]);
        }
        printf("\t%1.9lf", B[i]);
        printf("\n");
    }
    printf("\n");
}

void printHelp() {
    printf(
            "Usage: lss [input_file_name] [output_file_name] [options]\n"
            "Where options include:\n"
            " -d                print debug messages [default OFF]\n"
            " -e                print errors [default OFF]\n"
            " -p                print matrix [default OFF]\n"
            " -t                print execution time [default OFF]\n"
            " -h, -?            print this and exit\n");
}

int main(int argc, char *argv[]) {
    int set_input = 0;
    int n = 0;
    double *A = NULL;
    double *B = NULL;
    double *tmp = NULL;

    char *input_file = "lss_77_05_in.txt";
    char *output_file = "lss_77_05_out.txt";
    switch (validateParams(argc, argv)) {
        case 1: {
            if (flag_errors) {
                printf("ValidationError: Wrong syntax of parameters. Too much filenames\n");
            }
            return 2;
        }
        case 2: {
            if (flag_errors) {
                printf(
                        "ValidationError: Wrong syntax of parameters. There is no such parameter or "
                        "you haven't set value to one of the parameters\n");
            }
            return 3;
        }
        default: {
            break;
        }
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            if (!set_input) {
                if (i != 1) {
                    if (flag_errors) {
                        printf("ValidationError: Wrong order of parameters.\n");
                    }
                    return 4;
                }
                input_file = argv[i];
                if (validateFile(input_file)) {
                    if (flag_errors) {
                        printf("ValidationError: There is no such file.\n");
                    }
                    return 5;
                }
                set_input = 1;
            } else {
                if (i != 2) {
                    if (flag_errors) {
                        printf("ValidationError: Wrong order of parameters.\n");
                    }
                    return 4;
                }
                output_file = argv[i];
            }
        }
    }

    if (!set_input) {
        if (validateFile(input_file)) {
            if (flag_errors) {
                printf("ValidationError: There is no such file.\n");
            }
            return 5;
        }
    }

    switch (read_input(input_file, &A, &B, &n)) {
        case 1: {
            if (flag_errors) {
                printf("ValidationError. File is empty.\n");
            }
            return 6;
        }
        case 2: {
            if (flag_errors) {
                printf("ValidationError. n is not a positive integer.\n");
            }
            return 7;
        }
        case 3: {
            if (flag_errors) {
                printf("ValidationError. Not enough elements in the matrix.\n");
            }
            return 8;
        }
        case 4: {
            if (flag_errors) {
                printf("ValidationError. One of the elements of the matrix or constant terms vector is not a number.\n");
            }
            return 9;
        }
        default: {
            break;
        }
    }
    if (flag_print_matrix) {
        print_system(n, A, B);
    }
    double *X = malloc(n * sizeof(double));
    clock_t begin = clock();

    tmp = malloc( n * sizeof(double));

    int result = lss_75_05(n, A, B, X, tmp);

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    if (flag_time) {
        printf("\nExecution time: %1.9lf\n", time_spent);
    }

    write_answer(output_file, n, X, result);
    if (flag_print_matrix) {
        print_system(n, A, B);
    }
    free(A);
    free(B);

    return result;
};