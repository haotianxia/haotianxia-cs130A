#include "minMaxHeap.h"
#include <math.h>
#include <iostream>
#include<vector>
#include <list>
using namespace std;

void minMaxHeap :: insert(int value){
	array[index] = value;
	//cout <<index<<" "<<endl;
	//percolateup(index);
	index= index+1;
	//cout<<index<<" "<<endl;
	percolateup(index-1);
}

void minMaxHeap :: percolateup(int index){
	//<<index<<" ";
	int level = getLevel(index);
	//cout<<level<<endl;
	int parentIndex = getParentIndex(index);
	if ( level>0){
		if (isMinLevel(level)){
			if (array[index]>array[parentIndex]){
				swap(index, parentIndex);
				percolateup_max(parentIndex);
			}
			else{
				percolateup_min(index);
			}
		}
		else{
			if (array[index]< array[parentIndex]){
				swap(index,parentIndex);
				percolateup_min(parentIndex);
			}
			else{
				percolateup_max(index);
			}
		}
	}
}

int minMaxHeap :: getLevel(int index){
	return log(index+1)/log(2);//(floor(log(index+1)));
}

int minMaxHeap :: getParentIndex (int index){
	return (index-1)/2;
}

bool minMaxHeap :: isMinLevel(int level){
	return level % 2 ==0;
} 

void minMaxHeap :: swap(int index1, int index2){
 	//int tmp = index1;
	//index1 = index2;
	//index2=tmp; 
	int tmp = array[index1];
	array[index1] = array[index2];
 	array[index2] = tmp;
}

void minMaxHeap :: percolateup_max(int index) {
	int parentIndex = getParentIndex(index);
	int grandParentIndex = getParentIndex(parentIndex);
	if (parentIndex > 0){
		if (array[index] > array[grandParentIndex]){
			swap(index, grandParentIndex);
			percolateup_max(grandParentIndex);
		}
	}
}

void minMaxHeap :: percolateup_min(int index) {
	int parentIndex = getParentIndex(index);
	int grandParentIndex = getParentIndex(parentIndex);
	if (parentIndex > 0){
		if (array[index] < array[grandParentIndex]){
			swap(index, grandParentIndex);
			percolateup_min(grandParentIndex);
		}
	}
}

bool minMaxHeap :: deleteMin(){
	if (index == 0){
		return false;
	}
	if (index ==1){
		int deleteValue = array[index];
		array[index]=0;
		return true;
	}
	int deleteValue = array[0];
	array[0] = array[index-1];
	array[index-1]=NULL;
	index=index-1;
	percolatedown_min(0);
}

void minMaxHeap :: percolatedown(int rootindex){
	int level = getLevel(rootindex);
		if (isMinLevel(level)){
			percolatedown_min(rootindex);
		}
		else{
			percolatedown_max(rootindex);
		}
}

void minMaxHeap ::  percolatedown_min (int rootindex){
	vector<int> childrenIndexs;
	//cout<<endl<<getChilrenIndex(rootindex)<<endl;
	//if (array[getChilrenIndex(rootindex)]!=0){
	/*for (int i = 0; i<2; i++){
		if (array[getChilrenIndex(rootindex)+i] !=0){
			childrenIndexs.push_back(getChilrenIndex(rootindex)+i);
		}
	}*/	
	if(array[getChilrenIndex(rootindex)]==NULL){
		return;}
	childrenIndexs.push_back(getChilrenIndex(rootindex));
	if (array[getChilrenIndex(rootindex)+1] !=0){
	
	
	childrenIndexs.push_back((getChilrenIndex(rootindex)+1));
	}
	//cout<<childrenIndexs[1]<<endl;
	vector<int> grandChildrenIndexs;
	for (int i=0; i<4; i++){
		if (array[getGrandChilrenIndex(rootindex)+i] !=0){
			grandChildrenIndexs.push_back(getGrandChilrenIndex(rootindex)+i);
		}
	}
	/*for (int i=0; i<grandChildrenIndexs.size();i++){
		cout<<grandChildrenIndexs[i]<<' ' ;
	}*/
	vector<int> fullIndex;
	for (int i =0; i < childrenIndexs.size(); i++){
		fullIndex.push_back(childrenIndexs[i]);
	}
	for (int i = 0; i < grandChildrenIndexs.size(); i++){
		fullIndex.push_back(grandChildrenIndexs[i]);
	}
	int secondMIn = array[fullIndex[0]];
	int secondMinIndex=fullIndex[0];
	for (int i = 0; i != fullIndex.size(); i++){
		if (array[fullIndex[i]]<secondMIn){
			secondMIn = array[fullIndex[i]];
			secondMinIndex=fullIndex[i];
		}
	}
	//cout<<secondMinIndex<<endl;
	//cout<<secondMIn<< ' ';
	if (array[secondMinIndex]<array[rootindex]){
		//cout<<array[rootindex]<<' ';
		//cout<<array[secondMinIndex]<<' ';
		swap(secondMinIndex,rootindex);
		if (find(grandChildrenIndexs.begin(), grandChildrenIndexs.end(), secondMinIndex) !=grandChildrenIndexs.end()){
			int parentIndex = getParentIndex(secondMinIndex);
			if(parentIndex >= 0 && parentIndex < index && array[secondMinIndex]>array[parentIndex]){
				swap(secondMinIndex,parentIndex);
			}
		percolatedown_min(secondMinIndex);
		}
	}
}

void minMaxHeap ::  percolatedown_max (int rootindex){
	vector<int> childrenIndexs;
	if(array[getChilrenIndex(rootindex)]==NULL){
		return;}
	childrenIndexs.push_back(getChilrenIndex(rootindex));
	if (array[getChilrenIndex(rootindex)+1] !=NULL){
		childrenIndexs.push_back((getChilrenIndex(rootindex)+1));
	}
	vector<int> grandChildrenIndexs;
	for (int i=0; i<4; i++){
		if (array[getGrandChilrenIndex(rootindex)+i] !=NULL){
			grandChildrenIndexs.push_back(getGrandChilrenIndex(rootindex)+i);
		}
	}
	vector<int> fullIndex;
	for (int i =0; i < childrenIndexs.size(); i++){
		fullIndex.push_back(childrenIndexs[i]);
	}
	for (int i = 0; i < grandChildrenIndexs.size(); i++){
		fullIndex.push_back(grandChildrenIndexs[i]);
	}
	int secondMax = array[fullIndex[0]];
	int secondMaxIndex=fullIndex[0];
	for (int i = 0; i< fullIndex.size(); i++){
		if (array[fullIndex[i]]>secondMax){
			secondMax = array[fullIndex[i]];
			secondMaxIndex=fullIndex[i];
		}
	}
	if (array[secondMaxIndex]>array[rootindex]){
		swap(secondMaxIndex,rootindex);
		/*int parentIndex = 0;
		for (int i =0; i<grandChildrenIndexs.size(); i++){
			if (secondMaxIndex == grandChildrenIndexs[i]){
				int parentIndex = getParentIndex(secondMaxIndex);
			}
		}*/
		if (find(grandChildrenIndexs.begin(), grandChildrenIndexs.end(), secondMaxIndex) !=grandChildrenIndexs.end()){
			int parentIndex = getParentIndex(secondMaxIndex);
			if(parentIndex >= 0 && parentIndex < index && array[secondMaxIndex]<array[parentIndex]){
			swap(secondMaxIndex,parentIndex);
			}
			percolatedown_max(secondMaxIndex);
		}
	}
}

int minMaxHeap :: getChilrenIndex(int rootindex){
	if (array[rootindex*2+1]!=0){
	return rootindex*2+1;
	}
}
int minMaxHeap :: getGrandChilrenIndex(int rootindex){
	if(array[(rootindex*2+1)*2+1]!=0)
	return (rootindex*2+1)*2+1;
} 

int minMaxHeap :: getMin(){
	return array[0];
}

int minMaxHeap :: getMax(){
	if (array[1]>array[2]){
		return array[1];
	}
	else return array[2];
}

bool minMaxHeap :: deleteMax(){
	if (index == 0){
		return false;
	}
	if (index ==1){
		int deleteValue = array[index];
		array[index]=0;
		return true;
	}
	if (array[1]<array[2]){
		array[2] = array[index-1];
		array[index-1]=NULL;
		index=index-1;
		percolatedown_max(2);
	}
	if(array[1]>array[2]){
		array[1] = array[index-1];
		array[index-1]=NULL;
		index=index-1;
		percolatedown_max(1);		
	}
}
void minMaxHeap :: printHeap(){
	cout<<"heap = ";
	for (int i =0 ; i<index; i++){
		cout<<array[i]<<' ';
	}
	cout<<endl;
}
void minMaxHeap :: printMin(){
	cout << "min = "<<getMin();
}