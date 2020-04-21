# include "hash.h"
# include <algorithm>
#include<iostream>
using namespace std;

hashTable :: hashTable() {}

size_t hashTable :: hash(string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i< word.size(); i++){
		accumulator += (word.at(i))^2;
	}
	return accumulator% capacity;

}

void hashTable :: addWord(string word){
	int index = hash(word);
	for (size_t i = 0; i< table[index].size(); i++){
		if (table[index][i].first==word){
			 ++ table[index][i].second;
			 //cout<<word<<" inserted, new count = "<<table[index][i].second<<endl;
		}
	}
	table[index].push_back(pair<string,size_t>(word,1));
	//cout<<word<<" inserted, new count = 1"<<endl;
}
void hashTable:: deleteWord(string word){
	int index= hash(word);
	for (auto i= table[index].begin(); i!= table[index].end(); i++){
		if ((*i).first == word){
			--(*i).second;
			if ((*i).second == 0){
				table[index].erase(i);
				cout<<word<<" deleted"<<endl;
			}
			else{
				cout<<word<<" deleted, new count = "<<(*i).second<<endl;
				break;
			}
		}
	}
}
void hashTable :: search(string word){
	int index= hash(word);
	for (auto i = table[index].begin(); i!= table[index].end(); i++){
		if ((*i).first == word){
			cout<<word<<" found, count = "<<(*i).second<<endl;		
			return;
		}
	}
	cout<<word<<" not found"<<endl;		
}
void hashTable :: insertWord(string word){
	int index = hash(word);
	for (size_t i = 0; i< table[index].size(); i++){
		if (table[index][i].first==word){
			 ++ table[index][i].second;
			 cout<<word<<" inserted, new count = "<<table[index][i].second<<endl;
			return;
		}
	}
	table[index].push_back(pair<string,size_t>(word,1));
	cout<<word<<" inserted, new count = 1"<<endl;
}