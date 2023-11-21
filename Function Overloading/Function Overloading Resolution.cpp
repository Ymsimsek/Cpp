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








*/  
