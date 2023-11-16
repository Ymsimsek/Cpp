/*
-> Type Deduction: Derleyicinin türü yazılmamış ifadeyi çıkarım yoluyla bulmasıdır. 
  
-> Type deduction derleme zamanında gerçekleşir. 

-> Auto Keyword: Tür çıkarımı auto için yapılır. Auto için yapılan çıkarım, auto'yla tanıtılan değişkenlerin türünün belirlenmesinde kullanılır.
  
-> Auto ile yapılan çıkarım için bir initializer gerekir;
auto x = ... ;

*/

void Example(){
  const int x{10};
  auto y{x}; // auto anahtar sözcüğü int olur. const int olmaz. 
}

void Example2(){
  int x{10};
  int &r{x};
  auto y{r};// auto becomes int because r is an int not int&.
}

void Example3(){
  int x{10};
  const int& r{x};
  auto t{r};// auto is int. 
}

void Example4(){
  int a[10]{};
  auto b{a}; // int*b = a;
}

void Example5(){
  const int a[10]{};
  auto p{a};//const int*
}

void Example6(){ 
  auto ps{mucahit};//const char*
}

void Example7(){ 
  int func(int);
  auto x=func;//int(*)int: function names becomes function adresses.
}

