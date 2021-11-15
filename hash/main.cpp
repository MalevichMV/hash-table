#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "hash.h"

using namespace table;
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int Elem,k;
	ifstream FileIn("input.txt");
	if (FileIn.is_open())
	{
		Hash table(17);
		while (!FileIn.eof())
		{
			FileIn >> Elem;
			table.Add(Elem);
		}
		FileIn.close();
		cout << table << endl << endl;
		cout << "Введите ключ по которому вы хотите найти элемент:";
		cin >> k;
		cout << "Поиск элемента со значением " << k << ":" << table.Search(k) << endl;
	}
	else
		cout << "Error!" << endl;
	return 0;
}