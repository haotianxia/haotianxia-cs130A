#ifndef BST_H	
#define BST_H

#include <iostream>
#include <utility>
#include <string>
#include <sstream>
using namespace std;
class BST {
	public:
		BST();
		~BST();
		BST (string value);
		bool insert(string word);
		void insertPrint(string value);
		void removePrint(string value);
		void rangeSearch(string s);
		bool contains(string value) const;
		bool remove(string value);
		void printInOrder() const; 
		void search(string value);
	private:
		struct Node{
		string info;
		int count;
		Node * left, *right, *parent;
		Node(string value="") : info(value),count(1),left(0), right(0), parent(0) { }
		//Node(string word){
		//	word=make_pair(word,0);
		//	parent=right=left=0;
		};

	Node* root;
	Node* getNodeFor(string value, Node*n) const;
	bool insert(string value, Node*n);
	void clear(Node* n);
	Node* getPredecessor(string value) const;
	void printInOrder(Node *n) const;
	void rangeSearchHelper(Node* n, string value1,string value2);
};
#endif