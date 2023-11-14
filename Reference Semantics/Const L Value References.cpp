/*
  
->The reference that will be binded with a const object should also be const.

->const references can not apply any mathematical operations. They can not change. 

Usage: 
const T x{}; //T is any type.
const T& rx{x};

Examples:
  
Legal:
const int x{10};
const int& r{x};

Illegal:
const int x{10};
int& r{x};

Illegal:
int x{10};
const int& r{x};
x=45;
r=45; // Because r=x and r can not be equalized with another variable but x can be changed. 

*/ 


