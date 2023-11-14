//Without reference:

int g{35};
int* foo(void){
  return &g;
}

//With reference:

int m{35};
int& func(void){
  return m;
}

/* 
In C++ if the return value type of a function is L valued, expression of the calling function is also in L value category. 

Let T is a type;

T foo();
T& bar();

foo() -> PR Value
bar() -> L Value

If a return value type of a function is L value reference type, then L value reference expression can be binded to function call, in other words return variable.

*/

