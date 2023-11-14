/*
Trailing return type" is a method in C++ for specifying the return type of a function. In this approach, the return type is specified after the function declaration using the auto keyword. 
*/

int bar (int, int);

int (*foo())(int,int){
  return bar;
}

/* Can be written as; */

int bar2 (int, int);

auto func(){ // auto deducts int(*)(int, int)
return bar2;
}
// Example:

int a[100];
auto foo(){
  return a;
}

/* 

-> References that will be binded to an const expression should also be const reference.
Legal:
T*->const T*
int x{10};
const int &r=x;

Illegal:
const T* ->T*
int& func(void){
  int x{10};
  .
  .// some code here
  . 
  return x; // Return value can not be a automatic object
}
  
-> Static variables can be used as return value. 

auto foo(){
  static int a[10];
  return a;
}

-> In C++ the expressions with assignment operators are L valued and in C they are R valued. 

*/





