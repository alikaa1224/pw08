#include <stdio.h>
#include "myarrfunc.h"

int arr_sum_from_k_to_m(int *arrptr, int n, int k, int m, int *result)
{
    int i;
    int sum = 0;
    if (k < 0 || m < k || m >= n)
        return -1;
    for (i = k; i <= m; i++)
        sum += *(arrptr + i);
    *result = sum;
    return 0;
}

int arr_ind_between_k_and_m(int *arrptr, int n, int k, int m, int *ind)
{
    int i;
    int count = 0;
    for (i = 0; i < n; i++) {
        if (*(arrptr + i) >= k && *(arrptr + i) <= m) {
            ind[count] = i;
            count++;
        }
    }
    return count;
}

int arr_ind_above_average(int *arrptr, int n, int *ind)
{
    int i;
    int count = 0;
    int sum = 0;
    float average;
    if (n == 0)
        return 0;
    for (i = 0; i < n; i++)
        sum += *(arrptr + i);
    average = (float)sum / n;
    for (i = 0; i < n; i++) {
        if (*(arrptr + i) > average) {
            ind[count] = i;
            count++;
        }
    }
    return count;
}

void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        continue;
}

int arr_size(int n)
{
    int size;
    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1 || size < 1 || size > SIZE) {
        printf("Ошибка\n");
        clear_input();
        return n;
    }
    return size;
}

void arr_fill(int *arrptr, int n)
{
    int i;
    if (n == 0) {
        printf("Сначала задайте размер массива\n");
        return;
    }
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        if (scanf("%d", arrptr + i) != 1) {
            printf("Ошибка\n");
            clear_input();
            return;
        }
    }
}

void arr_print(int *arrptr, int n)
{
    int i;
    if (n == 0) {
        printf("Сначала задайте размер массива\n");
        return;
    }
    for (i = 0; i < n; i++)
        printf("arr[%d] = %d, адрес %p\n", i, *(arrptr + i), arrptr + i);
}

void arr_sum(int *arrptr, int n)
{
    int k;
    int m;
    int sum;
    printf("Введите k и m: ");
    if (scanf("%d %d", &k, &m) != 2) {
        printf("Ошибка\n");
        clear_input();
        return;
    }
    if (arr_sum_from_k_to_m(arrptr, n, k, m, &sum) == 0)
        printf("Сумма элементов с %d по %d: %d\n", k, m, sum);
    else
        printf("Ошибка\n");
}

void arr_between(int *arrptr, int n)
{
    int i;
    int k;
    int m;
    int count;
    int ind[SIZE];
    printf("Введите k и m: ");
    if (scanf("%d %d", &k, &m) != 2) { {
        printf("Ошибка\n");
        clear_input();
        return;
    }
    count = arr_ind_between_k_and_m(arrptr, n, k, m, ind);
    if (count == 0)
        printf("Элементов нет\n");
    else {
        printf("Индексы:");
        for (i = 0; i < count; i++)
            printf(" %d", ind[i]);
        printf("\n");
    }
}

void arr_above_average(int *arrptr, int n)
{
    int i;
    int count;
    int ind[SIZE];
    count = arr_ind_above_average(arrptr, n, ind);
    if (count == 0)
        printf("Элементов нет\n");
    else {
        printf("Индексы:");
        for (i = 0; i < count; i++)
            printf(" %d", ind[i]);
        printf("\n");
    }
}