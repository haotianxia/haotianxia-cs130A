#ifndef BST_H	
#define BST_H

#include <iostream>
#include <utility>
#include <string>
using namespace std;
class BST {
	public:
		BST();
		~BST();
		bool insert(string word);
		bool contains(string value) const;
		bool remove(string value);
	private:
		struct Node{
		pair<string, int> word;
		Node * left, *right, *parent;
		Node(pair<string,int> w): word("",0), left(0),right(0),parent(0){ }
	};

	Node* root;
	Node* getNodeFor(string value, Node*n) const;
	bool insert(string value, Node*n);
	void clear(Node* n);
	Node* getPredecessor(string value) const;
};
#endif