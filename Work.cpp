﻿#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

//Сгенерировать массив случайных чисел (тип long, 1000000 значений), отсортировать по убыванию. 
//
//Контейнер в виде vectora выбран т.к является динамическим массивом, что позволяет задавать массив любого размера.
//Имеются встроенные функции, что позволяет уменьшить код по оъему. Функция sort выбрана т. к построена на алгоритме быстрой сортировки, 
//для массива с большим объемом данных это важно.

void FillArr(vector <long> *A, int size) { //заполнение массива
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		A->push_back(rand());
	}
}
void ShowArr(const vector <long> &A) {  //ввывод массива на экран
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	vector <long> RandomArr;
	int size;
	cout << "Введите размер массива:	";
	cin >> size;
	FillArr(&RandomArr, size);
	sort(RandomArr.begin(), RandomArr.end(), greater <long>());
	ShowArr(RandomArr);

	return 0;
}
