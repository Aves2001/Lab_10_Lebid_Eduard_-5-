   /*/----------------------!!!----------------------------/*/
  /*/ Before compilation Save with Encoding Windows 1251  /*/
 /*/              Saved in Encoding UTF-8                /*/
/*/-------------------------!!!-------------------------/*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "default_cfg.h"
                                 /////////////////////////////////////////////////////////////
#define _yellow SetColor(14,0); // жовний вивід тексту на екран + чорний фон               //
#define _red SetColor(12,0);   // червоний вивід тексту на екран + чорний фон             //
#define _green SetColor(10,0);// повернення зеленого виводу тексту на екран + чорний фон //
                             /////////////////////////////////////////////////////////////

#define _Low -100 // мінімальне число для генерації випадкових чисел
#define _High 100 // максимальне число для генерації випадкових чисел

void init(int *a, int n); // ініціалізація масива
void print(int *a, int n); // вивід вмісту масива на екран
void summ_kil(int *a, int n); // визначає суми першої і другої половини динамічного масиву та кількість додатних елементів у кожній

int main()
{
	start_cfg(); //default_cfg.h
	int *a; // вказівник на масив
	int n; // розмір масива
	do{
	printf("Введіть розмір масива: ");
	_yellow
	scanf("%d", &n);
	_green
	}while(n < 1);
	// Виділення пам'яті
	a = (int*)malloc(n * sizeof(int));
	if (!a)
	{
		Error_RED();
		printf("Невдалося виділити пам'ять");
		end_cfg(); //default_cfg.h
		return 1;
	}
	init(a, n);
	print(a, n);
	summ_kil(a, n);
	
	free(a);
	end_cfg(); //default_cfg.h
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
void init(int *a, int n){

const int Low = _Low, High = _High; 
srand((unsigned)time(0)+rand()); // для генерації нових чисел кожного разу при запуску програми
for (int i = 0; i < n; i++)
{
	a[i] = Low + rand() % (High - Low + 1); //заповнення масива випадковими числами в діапазоні від Low до High
}
}
/////////////////////////////////////////////////////////////////////////////
void print(int *a, int n){
 printf("\nМасив:");
 // Вивід елементів масива
 for (int i = 0; i<n; i++)
 printf("\na[%d] = %d", i, a[i]);
}
/////////////////////////////////////////////////////////////////////////////
void summ_kil(int *a, int n){
	if (n == 1)
	{
		printf("\n");
		Error_RED();
		printf("У масиві лише один елемент");
		
		free(a);
		end_cfg(); //default_cfg.h
		exit(1);
	}
	int summ1 = 0;
	int summ2 = 0;
	int dod1 = 0;
	int dod2 = 0;
	
	for (int i = 0; i < n/2; i++)
	{
		summ1 += a[i];
		if (a[i] > 0)
		{
			dod1++;
		}
	}
	_yellow
	printf("\n\n\nДіапазон першої половини масиву: a[0] <--> a[%d]", (n/2)-1);
	_green
	
	printf("\n\nСумма першої половини масиву: ");
	_yellow
	printf("%d", summ1);
	_green
	
	printf("\nКількість додатних чисел в першій половині масиву: ");
	_yellow
	printf("%d", dod1);
	_green

	for (int j = (n/2); j < n; j++)
	{
		summ2 += a[j];
		if (a[j] > 0)
		{
			dod2++;
		}
	}
	_yellow
	printf("\n\n\nДіапазон другої половини масиву: a[%d] <--> a[%d]", n/2, n-1);
	_green

	printf("\n\nСумма другої половини масиву: ");
	_yellow
	printf("%d", summ2);
	_green

	printf("\nКількість додатних чисел в другій половині масиву: ");
	_yellow
	printf("%d", dod2);
	_green
}