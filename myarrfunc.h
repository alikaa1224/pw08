#include <stdio.h>

#define SIZE 100

int arr_sum_from_k_to_m(int *arrptr, int n, int k, int m, int *result);
int arr_ind_between_k_and_m(int *arrptr, int n, int k, int m, int *ind);
int arr_ind_above_average(int *arrptr, int n, int *ind);

void clear_input(void);
int arr_size(int n);
void arr_fill(int *arrptr, int n);
void arr_print(int *arrptr, int n);
void arr_sum(int *arrptr, int n);
void arr_between(int *arrptr, int n);
void arr_above_average(int *arrptr, int n);