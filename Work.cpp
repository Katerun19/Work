#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
using namespace std;

//Write simple camel_case function for strings. All words must have their ﬁrst letter capitalized without spaces.
//camel_case("hello case");  => "HelloCase" 
//camel_case("camel case word");  => "CamelCaseWord

void camel_case(string a)
{
	vector <int> Letter;  //массив для запоминания позиции, тех букв которые надо увеличить
	int NumberGap = 0;		//переменная для подсчета пробелов в фразе
	int size = a.length();
	char *b = new char[size];

	if (isalpha(a[0]) != 0) {		//если первый элемент буква
		Letter.push_back(0);
		for (int i = 0, j = 0; i < size; i++, j++) {
			if (a[i] != ' ') {			//если не пробел добавить в массив
				b[j] = a[i];
			}
			else {  //если пробел уменьшить порядок в новом массиве
				Letter.push_back(j);
				j = j - 1;
				NumberGap++;
			}
		}
	}
	else if (a[0] != ' ' && isalpha(a[0]) == 0) {  //если первый лемент не пробел и не буква
		Letter.push_back(1);
		for (int i = 0, j = 0; i < size; i++, j++) {
			if (a[i] != ' ') {
				b[j] = a[i];
			}
			else {
				Letter.push_back(j);
				j = j - 1;
				NumberGap++;
			}
		}
	}
	else {												//если первый элемент пробел
		for (int i = 0, j = 0; i < size; i++, j++) {
			if (a[i] != ' ') {
				b[j] = a[i];
			}
			else {
				Letter.push_back(j);
				j = j - 1;
				NumberGap++;
			}
		}
	}
	char *c = new char[size - NumberGap];				//новый массив, в которы запишим строку без пробелов и буквами со сменой регистра
	for (int i = 0; i < size - NumberGap; i++) {
		c[i] = b[i];									//заполняем весь иассив
		for (int j = 0; j < Letter.size(); j++) {
			if (Letter[j] == i) {						//меняем только те буквы что нужны по условию
				c[i] = (char)toupper(b[i]);
			}
		}
	}

	for (int i = 0; i < size - NumberGap; i++) {		//выводим на экран
		cout << c[i];
	}
	delete[] b;
	delete[] c;
}



int main()
{
	setlocale(LC_ALL, "ru");
	string a;
	cout << "Введите фразу для преобразования: ";
	getline(cin, a);
	camel_case(a);
	return 0;
}