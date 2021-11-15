#pragma once
namespace table 
{
	class Hash
	{
	private:
		int size;
		int* table;
		int* test;
		int* EmptyOrNot;
		int HashFun(int k);
	public:
		Hash();
		Hash(int S);
		~Hash();
		void Add(int key);
		void Del(int key);
		int Search(int key);
		friend std::ostream& operator<<(std::ostream& out, const Hash& obj);
	};
}