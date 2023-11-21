//Ex:

void func(int(*)[10]);
void func(int(*)[20]);// Function Overloading with 2 overloads. 

//Ex:

void func(int(&)[10]);
void func(int(&)[20]);// Function Overloading with 2 overloads. 

//Ex:

void func(int(*)[10]);
void func(int[][10]);// Function Redeclaration

//Ex:

void func(int **);
void func(int(*)[]);// Function Redeclaration

//Ex:

void func(int&);
void func(int&&);
void func(const int&);
void func(const int&&);// Function Overloading with 4 overloads. 

//Ex:

void func(int *);
void func(int &);// Function Overloading with 2 overloads. 
