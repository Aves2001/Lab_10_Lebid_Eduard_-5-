   /*/----------------------!!!----------------------------/*/
  /*/ Before compilation Save with Encoding Windows 1251  /*/
 /*/              Saved in Encoding UTF-8                /*/
/*/-------------------------!!!-------------------------/*/
#include <stdio.h>
#include "default_cfg.h"
                                 /////////////////////////////////////////////////////////////
#define _yellow SetColor(14,0); // жовний вивід тексту на екран + чорний фон               //
#define _red SetColor(12,0);   // червоний вивід тексту на екран + чорний фон             //
#define _green SetColor(10,0);// повернення зеленого виводу тексту на екран + чорний фон //
                             /////////////////////////////////////////////////////////////

void init(int *a); // ініціалізація масива
void print(int *a); // вивід вмісту масива на екран
void index(int *index, int k); // перевірка правильності введення індекса, щоб користувач не ввів чило яке менше або більше існуючого індекса
void max_diapazon(int *A, int *max); // максимальне число в діапазоні

int i, j, n, m;

int main()
{
	start_cfg(); //default_cfg.h
	int *A; // вказівник на масив
	int max[3] = {0}; // масив для збереження максилального числа з вказаного діапазону, та його індекси
	do{
	printf("Задайте кількість рядків: ");
	_yellow
	scanf("%d", &n);
	_green
	if (n < 1)
	{
		Error_RED();
		printf("Кількість рядків не може бути меше одиниці.\n\n");
	}
	}while(n < 1);
	
	do{
	printf("Задайте кількість стовпців: ");
	_yellow
	scanf("%d", &m);
	_green
	if (m < 1)
	{
		Error_RED();
		printf("Кількість стовпців не може бути меше одиниці.\n\n");
	}
	}while(m < 1);
	
	// Виділення пам'яті
	A = (int*)malloc(n*m * sizeof(int));
	if (!A)
	{
		Error_RED();
		printf("Невдалося виділити пам'ять");
		end_cfg(); //default_cfg.h
		return 1;
	}
	init(A);
	print(A);
	
	max_diapazon(A, max);
	printf("\n\nМаксимальне число в заданому діапазоні: ");
	_yellow
	printf("A[%d][%d] = %d", max[0], max[1], max[2]);
	_green
	free(A);
	end_cfg(); //default_cfg.h
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
void index(int *index, int k){
	_Bool error = 0;
	do{
	error = 0;
	if (n == k && n != m)
	{
		printf("Введіть індекс рядка: ");
	}else if (m == k && n != m)
	{
		printf("Введіть індекс стовпчика: ");
	} else printf("Введіть індекс:");
	_yellow
	scanf("%d", index);
	_green
	if (*index >= k)
	{
		Error_RED();
		printf("Число не може бути більше за: %d\n\n", k-1);
		error = 1;
	}else if (*index < 0)
	{
		Error_RED();
		printf("Число не може бути менше за 0\n\n");
		error = 1;
	}
	}while(error == 1);
}

/////////////////////////////////////////////////////////////////////////////
void max_diapazon(int *A, int *max){
	if (n == 1 && m == 1) // якщо в масиві лише один елемкнт - то він і є максимальним
	{
		max[2] = *A;
		return;
	}
	
	int i, j;
	_Bool bre = 0; // для виходу з фора

	int index_n_1 = 0; // індекс рядка першого елемента
	int index_m_1 = 0; // індекс стовпчика першого елемента

	int index_n_2 = 0; // індекс рядка другого елемента
	int index_m_2 = 0; // індекс стовпчика другого елемента

	printf("\nВведіть координати двох елементів:\n\nПерший елемент:\n");

	index(&index_n_1, n);
	index(&index_m_1, m);

	printf("\n\nДругий елемент:\n");
	index(&index_n_2, n);
	index(&index_m_2, m);

	printf("\nВибраний діапазон:");
	_yellow
	printf("\n A[%d][%d] = %d", index_n_1, index_m_1, *(A + index_n_1*m + index_m_1));
	_green
	printf(" <---> ");
	_yellow
	printf("A[%d][%d] = %d", index_n_2, index_m_2, *(A + index_n_2*m + index_m_2));
	_green
	max[2] = *(A + index_n_1*m + index_m_1);
	for (i = index_n_1; i < n; i++)
	{
		for (j = index_m_1; j < m; j++)
		{
			if (*(A + i*m + j) >= max[2])
			{
				max[0] = i;
				max[1] = j;
				max[2] = *(A + i*m + j);
			}
		if (i == index_n_2 && j == index_m_2)
		{
			bre = 1;
			break;
		}
		}
		if (bre == 1)
		{
			break;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
void init(int *a){
	// Введення елементів масива
	printf("\nЗаповніть масив:\n");
	for (i = 0; i<n; i++) // цикл по рядках
	{
		for (j = 0; j<m; j++) // цикл по стовпцях
		{
			printf("A[%d][%d] = ", i, j);
			scanf("%d", (a + i*m + j));
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
void print(int *a){
	printf("\nМасив:\n");
	// Вивід елемента масиву
	for (i = 0; i<n; i++) // цикл по рядках
	{
		for (j = 0; j<m; j++) // цикл по стовпцях
		{
			printf("A[%d][%d] = %d\t", i, j, *(a + i*m + j)); // вивід елемента масиву виділяється місце 5 знаків
		}
		printf("\n");
	}
}