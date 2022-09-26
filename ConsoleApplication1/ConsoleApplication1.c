#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS


int main(void)
{
    int exit = 1;
    while (exit == 1) 
    {
        setlocale(LC_ALL, "Rus");
        printf("Указатели\n");
        printf("Меню: \n1 - Редактирование и вывод\n2 - Динамическое создание и удаление \n3 - Произвольная длина массива\n4 - Треугольная матрица\n");
        int num;
        scanf_s("%d", &num);
        switch (num)
        {
        case 1:
            printf("Вы выбрали <Редактирование и вывод> \n");
            Redactir();
            break;

        case 2:
            printf("Вы выбрали <Динамическое создание и удаление> \n");
            Dinam_massiv();
            break;

        case 3:
            printf("Вы выбрали <Произвольная длина массива> \n");
            int r = 0;
            scanf_s("%d", &r);
            int* mas = calloc(r, sizeof(int));
            for (int i = 0; i < r; i++)
            {
                *(mas + i) = i;

            }
            printf("n");
            Function_massiv(mas,r);
            break;

        case 4:
            printf("Вы выбрали <Треугольная матрица> \n");
            Treyg_massiv();
            break;

        default:
            printf("Такой команды нет");
            break;
        }
        printf("Вы хотите продолжить?\n 1-да\n0-нет\n");
        scanf_s("%d", &exit);
    }

    return 0;
}

Redactir()
{
    int pere = 1;
    while (pere == 1)
    {
        int i;
        int* p = &i;
        scanf_s("%d", p);
        printf("%p\n", p);
        printf("Хотите редактировать число?\n1-да\n0-нет\n");
        scanf_s("%d", &pere);
    }
}

Dinam_massiv()
{
    int n;
    scanf_s("%d", &n);
    int* a = malloc(n), sazeof(int);
    for (long i = 0; i < n; i++)
    {
        printf("%d", i);
        printf(" ");
        *(a + i);
    }
    int vix;
    printf("\nХотите удалить массив?\n1-да\n0-нет\n");
    scanf_s("%d", &vix);
    if (vix == 1)
    {
        free(a);
        printf("Массив успешно удален\n");
    }
    else if (vix == 0)
    {

    }
    else
    {
        printf("\nХотите удалить массив?\n1-да\n0-нет\n");
        scanf_s("%d", &vix);
    }
}

Function_massiv(int * a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", *(a + i));
    }
}

Treyg_massiv()
{
    printf("Введите размерность массива");
    int x;
    scanf_s("%d", &x);
    int** pp = malloc(x * sizeof(int));
    int per=0;
    for (int i = 0; i < x; i++)
    {
        *(pp+i) = malloc((i + 1) * sizeof(int));      
        for (int j = 0; j <= i; j++)
        {
            pp[i][j] = per;
            per++;

        }     
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", pp[i][j]);
          
        }
        printf("\n");
    }
    for (int i = 0; i < x; i++)
    {
        free(pp[i]);
    }
    free(pp);
}