/*
There are two sets of rules:

1. Rule Set:
- decltype(x)
- decltype(a.b)
- decltype(ptr->c)

2. Rule Set:
- decltype(10)
- decltype(x+5)
- decltype((a))

First Rule Set: (Value Rule Set)

Ex:
int x{120};
decltype(x) y = 5; // decltype deducts int.

Ex:
const int x{120};
decltype(x) y =100; // const int

Ex:
int x{5};
int& r{x};
decltype(r) y = x; // int& y =x;

Ex:
int x{56};
decltype(x)* p =&x;// int *p =&x

Ex:
int** p{};
decltype(p)//int**


Second Rule Set:(Expression Rule Set)
-> decltype(expression)

-> T, bir tür olmak üzere exp ifadesinin türü T olsun.

Eğer T'nin primary value category
    PR Value -> elde edilen tür -> T
    L Value  -> elde edilen tür -> T&
    X Value  -> elde edilen tür -> T&&

Ex:
int x{10};
decltype(x+5); // int

Ex:
int a[5]{};
decltype(a[2]);// int & because a[2] is L valued.

Ex:
int x{435};
int* p{&x};
decltype (*p);//int&
decltype(x++);//int

-> Fonksiyon çağrı ifadelerinde decltype çıkarımı ifadenin değer kategorisi fonksiyonun geri dönüş türünün nasıl bir değer olduğuna bağlıdır:

Eğer:
int foo(){}//-> PR Value
int& bar(){}//-> L value
int&& baz(){} //-> x Value

Ex:

decltype(foo()) //int
decltype(bar()) //int&
decltype(baz()) //int&&

Ex:
int x{10};
int& y{20};

decltype(x) a=y;// int a=y
decltype((x)) b = y; //int&b =y 

-> decltype bir unevaluated context örneğidir. 

Ex:
int x{10};
decltype(++x) y=x; //x'in değeri değişmez hala 10'dur. 


  
    




