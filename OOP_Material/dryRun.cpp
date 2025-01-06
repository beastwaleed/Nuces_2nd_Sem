#include<iostream>
using namespace std;

void mystery(int* ptr, int s)
{
    
ptr = new int[s];
for (int i = 0, j = s; i < s; ++i, j--)
*(ptr + i) = j;
}

int main(){

int* ptr, s = 5;
mystery(ptr, s);
for (int i = 0; i <s; ++i)
cout << ptr[i] << " ";
delete[] ptr;
return 0;

}