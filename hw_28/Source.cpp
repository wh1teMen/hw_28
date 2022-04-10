#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

template<typename T> void fillArr(T arr[],int length,int min, int max) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}
template<typename T> void printArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ", ";
	}
		cout << "\b\b]\n";
}
template<typename T> T* resizeArr(T arr[], unsigned int &length,  int newlength) {
	length = newlength;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[]arr;
	arr = new T[length];
	for (int i = 0; i < length; i++)
		arr[i] = tmp[i];
	delete[]tmp;
		
	return arr; 
}


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n, m;
	system("title Домашняя работа №28 - Динамический массив");
	cout << "Задача 1\n";
	cout << "Введите длину массива: ";
	cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];
	int* C = new int[n + m];
	fillArr(A, n, 10, 31);
	fillArr(B, m, 50, 71);
	cout << "Изначальный массив 1:\n";
	printArr(A, n);
	cout << "Изначальный массив 2:\n";
	printArr(B, m);
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i <n+ m; i++)
		C[i] = B[i-n];
	cout << "Итоговый массив:\n";
	printArr(C, n + m);
	delete[]A;
	delete[]B;

	cout << "\nЗадача 2\n";
	unsigned int size = 10;
	int* arr2 = new int[size];
	fillArr(arr2, size,15 ,60 );
	cout << "Изначальный массив:\n";
	printArr(arr2, size);
	int sizeF;
	cout << "Введите новую длину: ";
	cin >> sizeF;
	arr2=resizeArr(arr2, size, sizeF);
	cout << "Итоговый массив:\n";
	printArr(arr2, size);
	

	
	system("pause>nul");
	return 0;
}