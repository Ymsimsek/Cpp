/*
Tür dönüşümü (Type Conversion) C++'da çok tercih edilmez. Örtülü tür dönüşümü veya görünür tür dönüşümü kullanmak
beraberinde riskleri de getirir ve niyet aanlaşılmamış olabilir. 

Bilerek ve isteyerek yaptığımız tür dönüşümlerinin program debug edilirken daha kolay incelenmesini sağlayan operatörlerdir. 

-> Dört adet Type Cast operatörü vardır:
1. static_cast
2. const_cast
3. reinterpret_cast
4. dynamic_cast

-> Operatörlerin kullanım syntaxı aynı olmasına karşın kullanım senaryolarında farklılık vardır. 

-> Bir cast operatörünün kullanım şekli dışında kullanılması syntax hatası oluşturur. Bazı durumlarda iki farklı cast
yapılabilse dahi sonuçta iki farklı anlam ortaya çıkar. 

Kullanım Şekli:

xxx_cast<type> (expression) 

-> Farklı tam sayı ve gerçek sayılar arasında type-cast yapılacaksa static_cast kullanılır. enum- tam sayı arasında da yine static_cast kullanılır.

Ex:
int x{10};
int y{30};
double dval{static_cast<double>(x / y)};

Ex:
enum Color{ blue, black, green};
int main(){
  int ival{2};
  Color mycolor{black};
  mycolor{static_cast<Color>(ival);
  ival= static_cast<int>(mycolor);
}

-> const nesne adresinden const olmayan nesne adresine dönüşüm yapılması gerekiyorsa const_cast kullanılmalıdır. 

Ex: 
int x{56};
const int* cp = &x;
int* iptr=const_cast<int*>(cp);

-> const nesneye kesinlikle operatör vasıtasıyla dönüşüm yaptırılmamalıdır. Syntax açısından legal olsa da tanımsız davranış olacaktır.

-> const_cast referans semantiğinde de geçerlidir. 
Ex:
int x{120};
const int& cr{x};
int& r = const_cast<int&>(cr);
  
-> Boolean expression döndüren fonksiyonlara "predicate" denir. Bir parametresi varsa "unary predicate" iki parametresi varsa "binary predicate" adı verilir. 

-> Bir nesneyi farklı türden bir nesneymiş gibi kullanma amaçlı yapılan bir dönüşümdür. 

Ex: 
double dval {5476.435};
char* p = reinterpret_cast<char*>(&dval);

Ex: 
using namespace std;
ifstream ifr{"numbers.dat", ios::binary};
// some code
int a[10];
ifs.read(reinterpret_cast<char*>(a).sizeof(int)*10);

-> const ifadeler asdece interpret cast ile dönüştürülemezler.

Ex:
double dval;
const double* dptr = &dval;
auto cp1 = const_cast<char*>(reinterpret_cast<const char*>(dptr);
auto cp2 = reinterpret_cast>char*> (const_cast<double*>(dptr);

-> void* nesne türünden inte* nesne türüne dönüşüm yapılırken static_cast tercih edilir. interpret_cast kullanılması gereken durumlar da vardır.




  
  
  
  
  
  */
