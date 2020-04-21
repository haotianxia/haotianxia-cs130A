#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include "BSTnp.h"
#include "hash.h"
using namespace std;

int main(int argv, char** argc){
	
	BST b1;
	hashTable h1;
	ifstream file("dataset.txt");
	string word;
	while(getline(file, word)){
		b1.insert(word);
		h1.addWord(word);
	}
	file.close();
	/*b1.search("hello");
	h1.search("hello");
	b1.insert("hello");
	h1.insertWord("hello");
	b1.insert("hello");
	h1.insertWord("hello");
	b1.insertPrint("hello");
	b1.search("hello");
	h1.search("hello");
	b1.remove("hello");
	b1.removePrint("hello");
	h1.insertWord("hello");
	h1.deleteWord("hello");
	h1.deleteWord("hello");
	b1.remove("hello");
	b1.removePrint("hello");
	b1.rangeSearch("yang to zoo");
	*/
	stringstream ss(argc[1]);
	string s;
	while(ss.good()){
		getline(ss, s, ',');
		if(s.substr(0,1).compare(" ")==0){
			s = s.substr(1);
		}
		
		if(s.substr(0,6).compare("search")==0){
			b1.search(s.substr(7));
			h1.search(s.substr(7));
		}
		else if(s.substr(0,6).compare("insert")==0){
			b1.insert(s.substr(7));
			b1.insertPrint(s.substr(7));
			h1.insertWord(s.substr(7));
		}
		else if(s.substr(0,6).compare("delete")==0){
			b1.remove(s.substr(7));
			b1.removePrint(s.substr(7));
			h1.deleteWord(s.substr(7));
		}
		else if(s.substr(0,12).compare("range search")==0){
			b1.rangeSearch(s.substr(13));
		}
	}
}