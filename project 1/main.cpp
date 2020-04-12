#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include "BST.cpp"
using namespace std;

int main(){
	BST b1;
	ifstream file("dataset.txt");
	string word;
	while(getline(file, word)){
		b1.insert(word);
	}
	file.close();
	b1.contains("hello");
}