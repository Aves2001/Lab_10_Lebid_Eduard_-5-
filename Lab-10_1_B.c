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
int minABS(const int *arr, int n); // повертає індекс мінімального за модулем елемента масиву
void dobutok00(const int *arr, int n); // добуток елементів масиву, розташованих між першим й останнім нульовими елементами

int main()
{
	start_cfg(); //default_cfg.h
	int *a; // вказівник на масив
	int n;
	do{
	printf("Введіть розмір масива: ");
	_yellow
	scanf("%d", &n);
	_green
	if (n < 1)
	{
		Error_RED();
		printf("Кількість рядків не може бути меше одиниці.\n\n");
	}
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
	printf("\r\n\n 1) Мінамальний за модулем елемент:");
	_yellow
	printf(" a[%d] = %d", minABS(a, n), a[minABS(a, n)]);
	_green
	dobutok00(a, n);

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
int minABS(const int *arr, int n)
{
	int min = arr[0];
	int min_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(arr[i]) < abs(min))
		{
			min = arr[i];
			min_index = i;
		}
	}
return min_index;
}
/////////////////////////////////////////////////////////////////////////////
void dobutok00(const int *arr, int n){
	int dob = 1;
	int index_1 = -1;
	int index_2 = -1;

	for (int i = 0; i < n; i++) // індекс першого нуля
	{
		if (arr[i] == 0)
		{
			index_1 = i;
			break;
		}
	}

	for (int j = n-1; j >= 0; j--) // індекс останнього нуля
	{
		if (arr[j] == 0)
		{
			index_2 = j;
			break;
		}
	}

	if (index_1 == -1 && index_2 == -1)
	{
		_red
		printf("\r\n\n У масиві немає нульових елементів");
		end_cfg();
		exit(1);
	} else if (index_1 == index_2)
	{
		_red
		printf("\r\n\n У масиві тільки один нульовий елемент");
		end_cfg();
		exit(2);
	} else if (index_2 - index_1 == 1)
	{
		_red
		printf("\r\n\n У масиві два нульові елементи, які знаходяться поряд один з одним");
		end_cfg();
		exit(3);
	}
		for (int i = index_1+1; i < index_2; i++)
		{
			dob *= arr[i];
		}

		printf("\r\n 2) добуток елементів масиву,\n розташованих між першим й останнім\n нульовими елементами = ");
		_yellow 
		printf("%d\n", dob);
		_green
return;
}