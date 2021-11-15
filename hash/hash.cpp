#include <iostream>
#include <iomanip>
#include "hash.h"

using namespace std;

namespace table 
{
	Hash::Hash()
	{
		cout << "Хеш-таблица создана" << endl;
		table = new int[15]();
		test = new int[15]();
		EmptyOrNot = new int[15]();
		size = 15;
	}

	Hash::Hash(int S)
	{
		if (S != 0)
		{
			table = new int[S]();
			test = new int[S]();
			EmptyOrNot = new int[S]();
			size = S;
			cout << "Хеш-таблица создана" << endl;
		}
		else
			throw "Size error!";
	}

	Hash::~Hash()
	{
		cout << "Хеш-таблица удалена" << endl;
		delete[]table;
		delete[]test;
		delete[]EmptyOrNot;
		size = 0;
	}

	void Hash::Add(int key)
	{
		int i = 0;
		int HashCode = HashFun(key);
		if (EmptyOrNot[HashCode] == 1)
		{
			while (EmptyOrNot[HashCode] == 1) {
				if (i > size)
				{
					cout << "\nТаблица заполнена" << endl;
					return;
				}
				i++;
				HashCode = (HashFun(key) + i * HashFun(key))% size;
			}
			table[HashCode] = key;
			test[HashCode] = i;
			EmptyOrNot[HashCode] = 1;
		}
		else
		{
			table[HashCode] = key;
			test[HashCode] = i;
			EmptyOrNot[HashCode] = 1;
		}
	}

	void Hash::Del(int key)
	{
		int i = 0;
		int HashCode = HashFun(key);
		if (EmptyOrNot[HashCode] != key)
		{
			while (EmptyOrNot[HashCode] != key) {
				if (i > size)
				{
					cout << "\nЭлемента не существует" << endl;
					return ;
				}
				i++;
				HashCode = (HashFun(key) + i * HashFun(key)) % size;
			}
			table[HashCode] = 0;
			test[HashCode] = 0;
			EmptyOrNot[HashCode] = 0;
		}
		else
		{
			table[HashCode] = 0;
			test[HashCode] = 0;
			EmptyOrNot[HashCode] = 0;
		}
	}

	int Hash::Search(int key)
	{
		int i = 0;
		int HashCode = HashFun(key);
		if (table[HashCode] != key)
		{
			while (table[HashCode] != key) {
				if (EmptyOrNot[HashCode] == 0)
					return -1;
				if (i > size)
				{
					cout << "\nЭлемента не существует" << endl;
					return -1;
				}
				i++;
				HashCode = (HashFun(key) + i * HashFun(key)) % size;
			}
			cout << "количесвто проб при поиске: " << i << endl;
			return HashCode;
		}
		else
		{
			cout << "количесвто проб при поиске: " << i << endl;
			return HashCode;
		}
	}

	int Hash::HashFun(int key)
	{
		int integer = int(key * 0.618033);
		return int(size * (key * 0.618033 - integer));
	}

	ostream& operator<<(ostream& out, const Hash& other) {
		double Width = out.width() == 0 ? 10 : out.width();
		for (int i = 0; i < other.size; i++)
			out << std::setw(Width) << i << "\t" << other.table[i] << "\tКоличество проб:" << other.test[i] << "\n";
		return out;
	}
}