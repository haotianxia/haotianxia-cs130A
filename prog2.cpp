#include"minMaxHeap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

int main (int argv, char** argc){
        minMaxHeap m1;
        ///autograder/submission/PA2_dataset.txt
        ifstream file("/autograder/submission/PA2_dataset.txt");
        int number;
        string a;
        while(getline(file,a)){
         stringstream geek(a);
         geek >> number;
         m1.insert(number);
        }
        file.close();
        stringstream ss(argc[1]);
        string s;
        while(ss.good()){
            getline(ss, s, ',');
            if (s.substr(0,1).compare(" ")==0){
                s = s.substr(1);
            }
            if (s.substr(0,9).compare("printHeap")==0){
                m1.printHeap();
            }
            else if (s.substr(0,6).compare("getMin")==0){
                //cout<<endl<<endl;
                m1.printMin();
                cout<<endl;
            }
            else if (s.substr(0,6).compare("getMax")==0){
                cout<<"max = "<<m1.getMax()<<endl;
            }
            else if(s.substr(0,9).compare("deleteMin")==0){
                cout<<"deleted "<<m1.getMin()<<endl;
                m1.deleteMin();
            }
            else if (s.substr(0,9).compare("deleteMax")==0){
                cout<<"deleted "<<m1.getMax()<<endl;
                m1.deleteMax();
            }
            else if(s.substr(0,6).compare("insert")==0){
                string a=s.substr(7);
                stringstream geek(a);
                int number;
                geek >> number;
                m1.insert(number);
                cout<<"inserted "<<number<<endl;
                //cout<<endl;
            }
    }
}