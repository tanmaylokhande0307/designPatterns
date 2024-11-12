#include <iostream>
using namespace std;

void print(int* p){
    (*p)++;
}

int main()
{
    int p=1;
    int *ptr = &p;
    print(ptr);
    cout << p<< endl;
    return 0;
}