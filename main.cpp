#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool read(double *array, unsigned int size){
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    for(unsigned int i=0; i<size; ++i){
        if(!(stream>>array[i])){
            cout<<"An error has occured while reading input data."<<endl;
            return false;
        }
    }
    return true;
}

void insertion_sort(double *array, unsigned int size){
    for(unsigned int i=0; i<size; ++i){
        for(unsigned int j=i; j>0; --j){
            if(array[j-1]>array[j]){
                swap(array[j-1], array[j]);
            }
            else{
                break;
            }
        }
    }
}

int main(){
    unsigned int size;
    string s;
    getline(cin, s);
    istringstream stream(s);
    if(!(stream>>size)){
        cout<<"An error has occured while reading input data."<<endl;
        return -1;
    }
    double *array=new double[size];
    if(read(array, size)){
        insertion_sort(array, size);
        for(unsigned int i=0; i<size; ++i){
            cout<<array[i]<<" ";
        }
    }
    delete[]array;
    return 0;
}
