// Задача 3
// Разработайте программу для вычисления определённого
// интеграла с использованием метода прямоугольников.

#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main(){

int n = 1410065408; // 10**10
// int n = 1000000000; // 10**9
// int n = 1000000; // 10**6
// int n = 1000; // 10**3

//int *a = (int*) calloc(n, sizeof(int));
//int *b = (int*) calloc(n, sizeof(int));
//int *res = (int*) calloc(n, sizeof(int));
//int *res_par = (int*) calloc(n, sizeof(int));

float h,S,x;
int i;
h=(b-a) * 1.0 / n;
S=0;

double time_spent = 0.0;
double time_spent_par = 0.0;

// Расчет времени при последовательном выполнении
clock_t begin =  clock();
for(i=0;i<n-1;i++)
{
    x=a+i*h;
    S=S+(1+sin(x)/(1+cos(x)));
}
S=h*S;
clock_t end =  clock();
time_spent += (double)(end - begin) / (CLOCKS_PER_SEC);
printf("\nSequential work time is %.10f seconds", time_spent);

// Расчёт времени при параллельном выполнении
clock_t begin_par =  clock();
#pragma omp parallel for num_threads(10)
for(i=0;i<n-1;i++)
{
  x=a+i*h;
  S=S+(1+sin(x)/(1+cos(x)));
}
S=h*S;
clock_t end_par =  clock();
time_spent_par += (double)(end_par - begin_par) / (CLOCKS_PER_SEC);
printf("\nParallel work time is %.10f seconds", time_spent_par);

free(a);
free(b);
free(res);
return 0;
}