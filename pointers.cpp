#include <iostream>
using namespace std;

void swap (char *x, char *y) 
{
   cout<<x << " "<<y << endl;

  char *t = x;
  x = y;
  y = t;
   cout<<x << " "<<y << endl;

}

int main()
{
   char *x = "ninjasquiz";
   char *y = "codingninjas";
   char *t;
   swap(x, y);
   cout<<x << " "<<y;

    return 0;
}