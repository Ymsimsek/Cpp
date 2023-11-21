/* 
Kodun hangi fonksiyonu overload edeceğini derleyicinin anlamasının çözünürlüğüdür.
Bu sırada meydana gelebilecek 3 senaryo mevcuttur;
1. Derleyici overloading'i bulur ve uygular.
2. "No match" hatası olur. Overloading olmasa da hata verecek çağrı olabilir.
3. Derleyici overloading'i anlamayabilir, birbirinin aynı iki ya da daha fazla fonksiyon olduğu çıkarımını yapabilir.

Function Overloading Resolution Proces:
1. Compiler detects the candidate functions. Then finds the functions that have same name. At this stage their signatures does not matter.
2. Detection of viable functions. Compiler fonksiyon çağrısıyla tanımlanmış fonksiyonları denetler ve legal çağrıya uyumlu fonksiyonları bulur.
Tek tek tüm fonksiyon tanımlarına bakıp o çağrının legal olup olmadığına bakaraj viable fonksiyonlar bulunmuş olur. Burada uygun fonksiyon bulunmazsa 
syntax hatası oluşur.
3. Eğer iki ya da daha fazla viable function varsa, derleyici belirli kurallara göre fonksiyonların en iyisini (best viable or best match functions)
bulacak ve çağrıyı o fonksiyona bağlayacak. Eğer iki ya da daha fazla fonksiyon arasında seçim yapamazsa "ambiguity error" (belirsizlik hatası) oluşacak.

Best Viable Function Detection. 

-> Variyetik parametresi olan fonksiyonlar her zaman son seçilir. 

Ex:
void func(...){} // Varietic Function
void func(double){}

int main(){
  func(12);// double parametreli fonksiyon seçilir. 
}

-> Dilin müsade ettiği dönüşümlere standard conversion, class yaratmak veya başka şekillerde müsade edilmeyi mümkün kılan dönüşümlere user-defined conversion adı verilir.

-> User- defined conversion'lar best viable funstion detection aşamasında variyetik fonksiyonların önünde ve genel olarak diğer tüm fonksiyonların gerisinde yer alırlar.

Ex:
void func(myclass){}
void func(double){}

//in main:

func(23);// double parametreli fonksiyon seçilecek.

-> İki user- defined conversion arasında overloading yapılmaz belirsizlik hatası oluşur. 

-> User- defined conversion da elendikten sonra geriye standard conversion kalır ve burada sıralama için kullanılan üç terim vardır;
1. Exact Match
2. Promotion
3. Conversion

Exact Match: Argüman ve parametrenin türü aynı ise ilk seçilecek fonksiyondur ve exact match olarak adlandırılır.

Ex:
void func(int){}//(1)
void func(long){}//(2)
void func(float){}//(3)
void func(double{})//(4)

func(1);//(1), Exact Match
func(2L);//(2), Exact Match
func(3.4f);//(3), Exact Match
func(4.1);//(4), Exact Match

!Ek Bilgi: Scientific Notation kullanılan sayılar da double'dır. Örneğin "3e3".

Ex: 
void func(int*){}
int x{10};
func(&x); // Exact Match

Ex:
void func(int(*)(int)){}
int foo(int){}

//in main
func(foo);//int(int), Burada function to pointer dönüşümü yapılır. Derleyici foo ismini foo fonksiyonunun adresine dönüştürür. func(&foo); şeklinde çağrı yapılır yine exact match olur.

-> Exact Match içeren diğer durumlar:
- L value to R value
- const conversion
- array decay (array to pointer conversion)
- function to pointer conversion

Promotions:
a)Integral promotions:
- char to int
- bool to int
- short to int
b)Float to double promotion. 

Ex:
void func(int){}//(1)
void func(double){}//(2)
void func(long){}//(3)
void func(long double{})//(4)

//in main

func('A');//(1)
func(2.3F);//(2)

Ex:
void func(unsigned int){}
void func(long double){}

//in main

int ival{};
func(ival); // Exatc match veya promotion yok. 2 adet conversion var ve ambiguity mevcut.

Ex:
void func(long double){}
void func(char){}

//in main

func(3.4); // ambiguity mevcur double to long double promotion olmaz.

-> const tanımlanmış ifadeler argüman olarak geçildiğinde const parametre bekleyen fonksiyonlar ile exact match oluştururlar. 

Ex:

void func(T*){} //(1)
void func(const T*){} //(2)

void foo(){
const T t;
func(&t); //(2) çağırılır. Exact Match
}

Ex:
void func(int&){} //(1)
void func(int){} //(2)

//in main

int x{67};
func(x); //Ambiguity mevcuttur. Call by value ve call by reference arasında seçilebilirlik farkı bulunmaz. Eğer "x" yerine tam sayı gönderilseydi, L value olmadığı için exact match ile (2) çağırılacaktı.

Ex:
void func(const int&){}
void func(int){}

func(12); //Ambiguity mevcut. const ref R value'ya bağlanabilir.

Ex:
void func (int*){}
void func (int){}

//in main

func(nullptr);// (1) conversion ile overload edilmesi için seçilir. 2 tane overload mevcut.

Ex:
void func(int*){}
void func(double*){}

//in main

func(nullptr);// Ambiguity

Ex:
void func(int*){}
void func(double*){}
void func(std::nullptr_t){}

//in main

func(nullptr); // (3) overload edilir. Exact match

-> enum türlerden inte dönüşüm vardır. enum class ise dönüşmez.

->T&, const T&, T&&, parametreleri fonksiyon tanımlamalarında;
- L value ile çağırılırlarsa, T&
- const L value ile çağırılırlarsa, const T&
- R value ile çağırılırlarsa, T&&
- L value ile çağırılır ve T& yoksa, const T& çağırılır.

!!!! İSTİSNA !!!!

void func(bool){}
void func(void*){}
int x{677};
func{&x};

-> Normalde ambiguity olmalı çünkü int'ten dönüşüm void*'a da bool'a da vardır. Ancak bu koşullarda void* seçilir.

-> Çoklu parametreli olan fonksiyonlardan birinin seçilebilmesi için en az bir argüman için o parametrede diğerlerine üstünlük kurmalı ve diğer argümalar da daha kötü olmamalıdır.!!!!!!!

Ex:
void foo(int,double,long){} //(1)
void foo(bool,float,int){} //(2)
void foo(long,double,float){} //(3)

foo(12,12,45u); //(1) seçilir.
foo(12,12.f,45u); // ambiguity oluşur.
foo(57u,4.5L,true); //(2) seçilir.

*/  
