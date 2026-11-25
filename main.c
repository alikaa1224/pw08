//2 вариант(10,17,28)

#include <stdio.h>
#include "myarrfunc.h"

int main(void){
    char vibor = 0;
    int run = 1;
    int arr[SIZE];
    int n = 0;

    while (run){
        printf("a.Задать размер массива\n");
        printf("b.Заполнить массив\n");
        printf("c.Представление массива(значения,адреса)\n");
        printf("d.Вычислить сумму элементов в заданном диапазоне индексов k-m\n");
        printf("e.Определить индексы элементов массива, находящихся в заданном диапазоне значений k-m\n");
        printf("f.Вычислить индексы элементов, значения которых выше среднего значения массива\n");
        printf("g.Выход\n");
        printf("Выберите пункт: ");

        if (scanf(" %c", &vibor) != 1){
            printf("Конец ввода\n");
            break;
        }
        clear_input();

        switch (vibor){
            case 'a':
                n = arr_size(n);
                break;
            case 'b':
                arr_fill(arr,n);
                break;
            case 'c':
                arr_print(arr,n);
                break;
            case 'd':
                arr_sum(arr,n);
                break;
            case 'e':
                arr_between(arr,n);
                break;
            case 'f':
                arr_above_average(arr,n);
                break;
            case 'g':
                run = 0;
                break;
            default:
                printf("Ошибка\n");
                break; 
        }
    }
    return 0;
}