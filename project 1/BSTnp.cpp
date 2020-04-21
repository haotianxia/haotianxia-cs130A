#include "BSTnp.h"
using std:: cout;
using namespace std;

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
		root = new Node(value);
    
		return true;
	}
	return insert(value,root);
}

bool BST :: insert(string value, Node *n){
	if (value == n->info){
		n->count ++;
		return true;
	}
 if (value < (n->info)){
 	if (n->left){
 		return insert(value, n->left);
 	}
 	else{
 		n->left = new Node(value);
 		n->left->parent =n;
 		return true;
 	}
 }
 else{
 	if(n->right){
 		return insert(value,n->right);
 	}
 	else{
 		n->right = new Node(value);
 		n->right->parent = n;
 		 return true;
 	}
 }
}

BST:: Node* BST::getNodeFor(string value, Node* n) const{
	if(n==NULL){
		return NULL;
	}
	if(n->info==value){
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

	if(tmp->info == value && tmp->count>1){
		tmp->count--;
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
        if(tmp->parent->left && tmp->parent->left->info==value){
            tmp->parent->left=tmp->right;
        }
        else{
            tmp->parent->right=tmp->right;
           }
           delete tmp;
        }
   	else if(tmp->right==0){
       if (tmp->parent->left!=NULL && tmp->parent->left->info==value){
           tmp->parent->left=tmp->left;
       }
       else {
           tmp->parent->right=tmp->left;
           delete tmp;
           }
    }
  	else {
       string a=tmp->info;
       int b=tmp->count;
       Node*ptr=getPredecessor(value);
       tmp->info=ptr->info;
       tmp->count=ptr->count;
       ptr->info=a;
       ptr->count=b;
       remove(value);
  }
  return true;
}
void BST::printInOrder() const {
    printInOrder(root);
}
void BST::printInOrder(Node *n) const {
     if (n!=0){
         printInOrder(n->left);
         cout<<n->info<< " "<<n->count<<endl;
         printInOrder(n->right);
    }
}
void BST :: search(string value){
  if(Node *ptr = getNodeFor(value, root)){
  cout<< ptr->info<<" found, count="<<ptr->count<<endl;
  }
  else{
    cout<<value<<" not found"<<endl;
  }
}

void BST :: insertPrint(string value){
  if(Node *ptr = getNodeFor(value, root)){
    cout<< ptr->info<<" inserted, new count="<<ptr->count<<endl;
  }
} 
void BST :: removePrint(string value){
  if(Node *ptr = getNodeFor(value, root)){
    cout<< ptr->info<<" deleted, new count="<<ptr->count<<endl;
  }
  else{
    cout<<value<<" deleted"<<endl;
  }
}
void BST :: rangeSearchHelper(Node *n, string value1, string value2){
  if(NULL == n) return;
  if (value1< n->info) rangeSearchHelper(n->left,value1,value2);
  if (value1 <= n->info && value2 >= n->info) cout<< n->info<<endl;
  if (value2 > n->info) rangeSearchHelper(n->right,value1,value2);
}
void BST :: rangeSearch(string s){
  string value1;
  string value2;
  for (size_t i = 0; i<s.length(); i++){
    if(s.substr(i,4) == " to "){
      value1 = s.substr(0,i);
      value2 = s.substr(i+4);
    }
  }
  rangeSearchHelper(root, value1,value2);
} 