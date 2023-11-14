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

// -> const L value references can be initialized with R value expressions. 

const int& r{10};

/*

int temp_obj1{10};
const int& rr{temp_obj1};

*/

//Similarly

int ival{5};
const double& dr{ival};

/* 

double temp_obj2{ival};
const double& fr{temp_obj2};

*/

  
/*

          |   L Value    |    const L Value    |    R Value    |
  ________|______________|_____________________|_______________|
  T&      |  Can Bind    |    Can not Bind     |    Can Bind   |
  ________|______________|_____________________|_______________|
  const T&|  Can Bind    |    Can not Bind     |    Can Bind   |
  ________|______________|_____________________|_______________|

*/
