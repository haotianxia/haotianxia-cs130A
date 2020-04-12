#include "BST.h"
#include <iostream>
using std:: cout;

BST :: BST() : root(0){ }

BST :: ~BST() {
	clear (root);
}

void BST :: clear(Node* n){
	if(n){
		clear(n->left);
		clear(n->right);
		delete n;
	}
}

bool BST :: insert(string value){
	if(!root){
		root = new Node(value,1);
		return true;
	}
	return insert(value,root);
}

bool BST :: insert(string value, Node *n){
	if (value == n->word.first){
		n->word.second++;
		return true;
	}
 if (value < n->word.first){
 	if (n->left){
 		return insert(value, n->left);
 	}
 	else{
 		n->left = new Node(value,1);
 		n->left->parent =n;
 		return true;
 	}
 }
 else{
 	if(n->right){
 		return insert(value,n->right);
 	}
 	else{
 		n->right = new Node(value,1);
 		n->right->parent = n;
 		 return true;
 	}
 }
}

BST:: Node* BST::getNodeFor(string value, Node* n) const{
	if(n==NULL){
		return NULL;
	}
	if(n->word.first==value){
		return n;
	}
	Node* leftptr = getNodeFor(value, n->left);
	if(leftptr){
		return leftptr;
	}
	else{
		return getNodeFor(value, n->right);
	}	
}
bool BST::contains(string value) const { 
	return (getNodeFor(value,root)!= NULL);
}

BST::Node* BST::getPredecessor(string value) const{
	Node*tmp=getNodeFor(value,root);
  	if (tmp->left!=NULL){
       	tmp=tmp->left;
       	while(tmp->right!=NULL){
            	tmp=tmp->right;
       	}
       	return tmp;
       	}
   	else{

       	while( tmp->parent && tmp->parent->left == tmp){
            	tmp = tmp->parent;   
        	}
        if(tmp->parent) return tmp->parent;
        return NULL;
      }

}



bool BST :: remove(string value){
	if(root==NULL){
		return false;
	}
	Node* tmp=getNodeFor(value,root);
	if(tmp==NULL){
		return false;
	}

	if(tmp->word.first == value && tmp->word.second>1){
		tmp->word.second --;
		return true;
	}
	if(tmp->left==0 && tmp->right==0){
        if (tmp->parent==NULL){
            root=0;
        }
        else if (tmp->parent->left==tmp){
            tmp->parent ->left=0;
        }
        else{
            tmp->parent->right=0;
        }   
        delete tmp;
     }
    else if (tmp->left==0){
        if(tmp->parent->left && tmp->parent->left->word.first==value){
            tmp->parent->left=tmp->right;
        }
        else{
            tmp->parent->right=tmp->right;
           }
           delete tmp;
        }
   	else if(tmp->right==0){
       if (tmp->parent->left!=NULL && tmp->parent->left->word.first==value){
           tmp->parent->left=tmp->left;
       }
       else {
           tmp->parent->right=tmp->left;
           delete tmp;
           }
    }
  	else {
       pair<string,int> a=tmp->word;
       Node*ptr=getPredecessor(value);
       tmp->word=ptr->word;
       ptr->word=a;
       remove(value);
  }
  return true;
}
