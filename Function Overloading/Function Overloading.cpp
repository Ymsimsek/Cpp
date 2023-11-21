/*
Derleme zamanına ilişkin bir araçtır. Aynı isimde olan iki veya daha fazla fonksiyondan birinin çağrısında 
derleyicinin hangi fonksiyonun çağrısının yapıldığını anlaması olayıdır. Fonksiyon çağrısı derleme zamanında
belirleniyorsa (koda bakarak)  fonksiyonlara bağlanma açısından kullanılan iki terim vardır;
"Static Binding" ve "Early Binding. İki terim de aynı anlamdadır. Eğer çağrı run-time'da yapılıyorsa buna da;
"Dynamic Binding" veya "Late Binding" denir. 

-> Signature of a Function: Fonksiyonun aldığı parametrelerin cinsi ve sayısını  belirtir. 

Ex: void foo(int, int) // (int, int) is the signature of the function.

Function overloading olması için gerekli koşullardan biri fonksiyonların kapsam(scope)'larının aynı olmasıdır.
Diğer şart ise signature'larının farklı olmasıdır. Eğer signature ve return type aynı ise bu duruma function 
redeclaration denir. Parametrelerin cost'luğu ayrı declaration berlirtmez. 

Ex:
int foo(int);
int foo(const int); // function redeclaration

Function redeclaration yani fonksiyonun ikinci kez tanımlanması syntax hatasıdır. (ODR ihlali).

Fonksiyonun low level const pointer ile tanımlanması redeclaration değildir. 
Ex:
void func(int* ptr);
void func(const int* ptr); // Function Overloading

Ex:
void func(int* ptr);
void func(int* const ptr); // Function Redeclaration

Ex:
void func(int* ptr);
void func(int const* ptr); // Function Overloading


Eğer imzalar aynı ve return type farklı ise bu durum syntax hatası olacaktır. 

Ex:
int foo(int,int);
double foo(int,int); // Syntax Error

Ex:
void func(int*);
void func(int[]); // Syntax Error

Fonksiyonların int* veya int[] şeklinde tanımlanmalarının farkı yoktur. int[] tanımlaması bir pointer belirtir. 

Ex:
void func(int(int));
void func(int(*)(int)); // Function Redeclaration

int(int) bir function type, int(*)(int) ise bir function pointer type ancak fonksiyon parametresi olduğunda function type, function pointer'a dönüştürülür. !! (Decay) 

Bir türe eş isim vermek yeni tür yaratmaz. 

Ex:
typedef int Nec;
void func(int);
void func(Nec); // Function Redeclaration

Signed char ve unsigned char distinct type örnekleridir. 

Ex:
void func(char);
void func(signed char);
void func(unsigned char);// Function Overloading with 3 overloads 








  




