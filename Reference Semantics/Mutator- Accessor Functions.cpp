/*
Mutator Funcitons: Mutator functions allow external code to change the state of an object by updating the values of its private members. They often return void, indicating that they do not return a value. 
Mutator functions usually take one or more parameters, representing the new values that will be assigned to the private data members.

Can be in format of;
______________________________
void set(T&); 
______________________________
or 
______________________________
void mutate(T* ptr);
______________________________

Accessor Functions: In C++, accessor functions, also known as getter functions, are member functions of a class that provide access to the private data members (attributes) of the class. These functions are used to 
retrieve the values of private data members, allowing external code to read the state of an object without directly accessing or modifying its private data. They often return the value of a private 
data member or some derived information. Accessor functions usually do not take any parameters, or they may take const parameters to indicate that the function does not modify the object's state.

Can be in format of;
______________________________
void get(const T&); 
______________________________
or 
______________________________
void access(const T* ptr);
______________________________

*/
