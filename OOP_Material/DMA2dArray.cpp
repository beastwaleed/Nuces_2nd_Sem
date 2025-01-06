// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int rows,col;
    cout<<"Enter Rows and Colums: ";
    cin>>rows>>col;
    int **arr= new int *[rows];
    
    for(int i=0; i<rows ; i++){
        arr[i]=new int [col];
    }
    
    cout<<"Taking Inputs\n";
    for(int i=0; i<rows ; i++){
        for(int j=0;j<col;j++){
       cin>>arr[i][j];
            
        }
}

    cout<<"Displaying Array: \n\n";
    for(int i=0; i<rows ; i++){
        for(int j=0;j<col;j++){
       cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    
    cout<<"Deleting Array from Heap\n";
    for(int i=0;i<rows; i++){
        delete [] arr[i];
    }
    
    delete [] arr;
    
    cout<<"\nDisplaying Array After Deleting: \n\n";
    for(int i=0; i<rows ; i++){
        for(int j=0;j<col;j++){
       cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    
    return 0;
}