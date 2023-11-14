/* 
Default Initialization:
int x; // x is not a specific value. When a variable or porinter is initialized default, it has no determined value.

Value Initialization: 
int x{}; //x is initialized with zero.

Direct Initialization:
int x(10); // x=10. 

Most Vexing Parse:
While defining a variable using "()" compiler may think it as a function declaration. Instead we can use "{}" (Uniform Initialization).

Uniform Initialization:
int x{10};// x=10.

-> There are some other initialization types such as static and value initialization etc., firstly, zero initialization takes place and the first value becomes zero, for pointers it becomes null and for bool it becomes false. 

Narrowing Conversion:
While defining a variable information can be lost, to prevent it uniform initialization can be used since, it does not allow type conversion. 
*/
