#include<iostream>
using namespace std;
  
/* local variable is same as a member's name */
class Test
{

public:
   int x;
   void setX (int x)
   {
       // The 'this' pointer is used to retrieve the object's x
       // hidden by the local variable 'x'
      cout<<  "x is " << x <<endl;
      cout<< " this x is " << this->x<<endl;
   }
   
};
  
int main()
{
   Test obj;
   obj.x = 20;
   obj.setX(100);
  
   return 0;
}