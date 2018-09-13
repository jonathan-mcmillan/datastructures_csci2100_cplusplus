#include<iostream>
using namespace std;
 
class Test
{
public:
   Test() {}
   Test(const Test &t)
   {
      cout<<"Copy constructor called "<<endl;
   }
   Test& operator = (const Test &t)
   {
      cout<<"Assignment operator called "<<endl;
   }
};
 
int main()
{
  Test t1;
  Test t2 = t1;
  Test t3(t2);
  Test t4, t5;
  t5 = t4;
  return 0;
}

