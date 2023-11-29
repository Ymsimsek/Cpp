/*
"#include <initializer_list>" ile programa eklenebilir ancak çoğu standart kütüphane ile eklenir. 

-> std::initializer_list<int> x{1,3,5,7,9}; şeklinde eleman oluşturulabilir.

-> x.size() // dizi boyutu

-> x.begin() // dizinin başlangıcının adresi

-> x.end() //dizinin bittiği yerin adresini döndürür.

-> Bir diziye hazır sıralı elemanları eklemek istediğimizde bunu parametresi std::initializer_list olan fonksiyon çağrılarıyla yapabiliriz.

-> Derleyici initializer list oluşturulurken, oluşturulan dizinin başlangıç ve bitiş adreslerini tutan bir sınıf nesnesi oluşturur. Böylece,
bir fonksiyona argüman olarak geçildiğinde uzunluk parametresine gerek kalmadan bir dizi veya dizinin subarray'ini geçmiş oluruz.

-> Initializer list'ler constant olarak tanımlanır. Oluşturulan dizi salt okunurdur. Değiştirilemez.

Ex:
std::initializer_list<int> x{3,6,8,9,10};
x.size(); //5 değerini döndürür.
x.begin(); //3'ün adresini döndürür.
x.end(); //10'un adresini döndürür.

// x'in adresi begin'in adresini döndürmez. x bir sınıf nesnesidir ve adresi üyelerinin adresinden farklıdır.

Ex:
using namespace std;
vector ivec {4,1,4,2,3};
ivec.insert(ivec.end(),{10,20,30,40}); //vektörünün sonuna bu değerler eklenir. Insert fonksiyonunun ikinci parametresi initializer list'tir.

Ex:
void func(int x, int y, int z){
  std::vector<int> ivec;
  ivec = {x,y,z}; //Atama operatör fonksiyonuna initializer list argüman olarak gider. x,y,z parametreleri ivec'in elemanları olurlar.
}

Ex:
auto x= {1,3,5,7}; //std::initializer_list<int> x
//initializer list söz konusuyken "auto x{1,3,5,7};" syntax hatası bildirir. Atama operatörüyle işlemin gerçekleştirilmesi gerekir. 


Ex:
auto y = {1} //init.list
auto z = {2,5,6}; //init.list   
auto t = {2,5,7.}; //syntax hatası, ill formed

-> C++ 14 öncesi "auto x{3,4,5}" legaldi. 


-> Initializer list parametreli ctor:

class myClass{
public: 
  myClass(std::initializer_list<int>){
    std::cout<<"myClass(init_list)\n";
  }
   myClass(int,int){
    std::cout<<"myClass(int, int)\n";
  }
   myClass(int){
    std::cout<<"myClass(int)\n";
  }
};

int main(){
  myClass m1(3,6,7,1); //myClass(int,int)
  myClass m2{3,6,7,1}; //myClass(std::initializer_list<int>
  myClass m3={3,6,7,1}; //myClass(std::initializer_list<int>
}

Ex:
int main(){
  std::vector<int> vec1(100); //size_t parametreli ctor çağırılır ve 100 adet 0 değeri ile başlatır.
  std::vector<int> vec2{100}; //initializer_list parametreli ctor çağırılır ve 1 adet 100 değeri ile başlatılır.
  std::vector<int> vec3(10,4); //10 adet 4 değeriyle başlatılır.
  std::cout<<"vec1.size()= " <<vec1.size()<<'\n'; // <<100
  std::cout<<"vec2.size()= " <<vec2.size()<<'\n'; // <<1
  std::cout<<"vec3.size()= " <<vec3.size()<<'\n'; // <<10
}





*/
