# ifndef HASH_H
# define HASH_H

#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include <algorithm>

using namespace std;

class hashTable {
	public: 
		hashTable();
		void addWord(string word);
		void insertWord(string word);
		void deleteWord(string word);
		void search(string word);
	private:
		const static size_t capacity = 10000;
		std::vector<pair<string,int> > table[capacity];
		size_t hash(string word) const;

};
#endif