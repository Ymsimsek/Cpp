/*
-> Containerler'in iterator nested type'ları vardır. Birçok operatorü overload ederler.

Ex:
template<typename<Iter>
void print_array(Iter beg, Iter end){
  while(beg!=end){
    std::cout<<*beg<<' ';
    ++beg;
    }
  std::cout<<'\n';
}
int main(){
  double a[5] = {1.2,34.2,42.2,13.3,34.3,12.23};
  print_array(a,a+3);
  print_array(a+1,a+5);

  std::vector<double> dvec{1.2,3.4,5.6,7.8,9.7,};
  print_array(dvec.begin(),dvec.end());
  std::list<std::string> names{"ali","veli","can","burak","damla"};
  print_array(names.begin(),names.end());
}

-> Yukarıdaki örnekte iteratörlerin işlevleri gösterilmeye çalışıldı. Aşağıda ise temsili bir vector sınıfı içerisindeki iteratör
nested type oluşu gösterilmiştir.

Ex:
template<typename T, typename A>
class vector{
public:
  class iterator{
  public:
    //
    T& operator*();
    bool operator!= (const Iterator&) const;
    operator++(){
    
    }
    operator++(int){
    
    }
  };
  iterator begin();
  iterator end();
}

-> Iterator öyle bir soyutlamadır ki ++ operator'unun operatndı yaparsak veri yapısındaki bir sonraki öğenin konumunu tutar hale gelir.
Iterator'ü dereference edersek, o konumdaki nesneye eriştir. Ok operatörünün operandı yaparsak, o konumdaki öğenin veri elemanlarına, 
fonksiyonlarına erişim sağlatır. -- operatorünün operandı yaparsak bir önceki elemanın konumunu tutar. Böylelikle, veri yapıları üstünde
çalıştırılacak algoritmalar veri yapısından bağımsız olarak ifade edebiliriz.

Ex:
#include <algorithm>
#include <vector>
#include <iostream>

int main(){
using namespace std;

vector<int> ivec{4,6,7,8,9,1,5,23};

sort(ivec.begin(),ivec.end());

for (auto i: ivec)
  std::cout<<i<<' ';
}

-> Iterator sınıflarının hangi  operasyonlara destek sağladığı yine generic programlama araçlarıyla belirlenir.

int main(){
  using namespace std;
  vector<int> ivec{32,67,89,12};
  auto iter = ivec.begin(); //Iterator elde edildi. Sınıfın begin fonksiyonu bir iterator döndürür döndürüğü iterator containerin ilk elementinin konumudur.
  list<string> slist;
  auto iter2 = slist.begin();
}

-> C tip arraylerin begin fonksiyonu olmadığı için begin fonksiyonu modern C++'da argüman olarak container almaya başladı.(Global fonksiyon şablonu) 

Ex:
int main(){
  using namespace std;
  vector<int> ivec(1000);
  int ar[1000];
  auto iter = begin(ar);  // C tip container ile iterator bağlandı. 
}

-> Iterator Category: Iterator interface'inde hangi özellik olduğunu belirleyen yapıdır. Her kategorinin desteklediği operasyonlar vardır.
- Input Iterator: ostream_iterator, osterambuf_iterator | copy constructible | ++it, it++, *it, it->
- Output Iterator: istream_iterator, isterambuf_iterator | copy constructible | ++it, it++, *it, it->, it1 ==it2, it1!=it2
- Forward Iterator: forward_list, unordered_set, unordered_multiset, unordered_map, unordered_multimap | copy constructible, default constructible | ++it, it++, *it, it->, it1 ==it2, it1!=it2
- Bidirectional Operator: list, set, multiset, map, multimap  | copy constructible, default constructible | ++it, it++, *it, it->, it1 ==it2, it1!=it2
- Random Access Iterator: vector, deque, array, string, C arrays | copy constructible, default constructible | ++it, it++, *it, it->, it1 ==it2, it1!=it2, it+n, n+it, it-n, it+=n, it-=n, it1-it2, it[n], <,=<,>,>=

-> STL kaplarının her birinin iterator kategorisi baştan belirlenmiştir

-> Iterator kategorileri tag class(empty class) şeklinde nested type olarak bulunurlar.

template<typename Iter>
void algo(Iter beg, Iter end){
  if constexpr(std::is_same_v<typename Iter::iterator_category, std::random_access_iterator_tag>){
  //
  }
  else if constexpr(std::is_same_v<typename Iter::iterator_category, std::bidirectional_access_iterator_tag>){
  //
  }
  //
  //
  //
}

-> Salt okuma amaçlı bir range erişmek istiyorsak "const_iterator" kullanabiliriz.

Ex:
int main(){
  using namespace std;

  vector<string> svec{"ali","can","ece","tan"};

  vector<string>::const_iterator iter = svec.begin(); //iter öğeleri gezebilir ancak öğeleri değiştiremez. 

  cout<<*iter<<'\n';
}


-> begin() ve end() çağrılarının geri dönüş türü iteratordür. "auto" ile oluşturulan iterator nesnelerini const yapmak istiyorsak
cbegin() ve cend() fonksiyonlarına çağrı yapabiliriz.

Ex:
int main(){
  using namespace std;

  vector<string> svec{"ali","can","ece","tan"};

  auto iter = svec.cbegin();
}

Reverse Iterator: Bir iterator adepter sınfıtır. rbegin() ve rend() fonksiyonları yardımıyla kullanılabilir. İçerik operatör fonksiyonu
sarmaladığı iteratör'ün gösterdiği nesneyi döndürmez. Sarmalanan iteratör end konumunu tutuyorsa bu nesne çağırıldığında container'deki
tutulan end konumundan bir önceki konumu tutar. Artırma işlemi yapıldığında ise bir önceki öğeye doğru ilerler.
Ex:
int main(){
  using namespace std;
  vector<string> svec{"bilge", "gurkan","halid","kutay"};
  vector<string>::reverse_iterator iter = svec.rbegin();
  auto it = iter.base();
  cout<<(it==svec.end());
}

-> Reverse iterator'den bahsedebilmek için sarmalanan iteratörün minimum bidirection iterator kategorisinde olması gerekir. 


-> Yazma işlemi yapan bir algoritmanın, bir container'a push_back'e dönüştürmesi için hedef yazı başlangıç konumuna back_inserter ile çağrı yapabiliriz. 

-> front_inserter ile container'in push_front fonksiyonu kullanılmış olarak arzu edilen range, hedefin ön sıralarından başlanarak eklemeye tabi tutulur.

-> inserter fonksiyon çağrıları ile container'in insert fonksiyonu ile yapılan çağrıya dönüştürür. Insertion'un belirli bir iterator konumuna arzu edilen hedef aralığını eklemek için kullanılabilir. 

STL'de iteratorleri manipule eden algoritmalar:  Bunlar fonksiyon şablonlarıdır ve parametre olarak iterator alırdır.

- advance(ref): Iteratorü n pozisyon artırmak eğer bidrectional ise n poziston için azaltmak için kullanılır. Gönderilen ifadeyi değiştirir. 

- distance(iter1,iter2): İki iterasyon arasındaki öğe sayısını bulur. distance(vec.begin(),vec.end()), vecte tutulan öğe sayısı yani size'ını bildirir.

- next(iter,4): Iterator ve tam sayı alır. Iteratorden tam sayı kadar sonraki iteratörü döndürür. Girilen argüman iteratörü değiştirmez. 

- prev(iter,3): Aynı next gibi çalışır. Iteratorden girilen tam sayı kadar önceki iteratorü dödürür. Girilen argüman değiştirilmez.

- iter_swap(iter_x,iter_y): iter_x konumundaki nesne ile iter_y konumundaki nesneler takas eder. 

Tag Dispatch: 
Ex:
template<typename Iter>
void func_impl(Iter beg, Iter end, std::random_access_iterator_tag){
  std::cout<<"random access\n";
}
template<typename Iter>
void func_impl(Iter beg, Iter end, std::bidirectional_iterator_tag){
  std::cout<<"bidirectional\n";
}
template<typename Iter>
void func_impl(Iter beg, Iter end, std::forward_iterator_tag){
  std::cout<<"forward\n";
}
template<typename Iter>
void func(Iter beg, Iter end,){
  func_impl(beg,end,typename Iter::iterator_category{});
}
int main(){
  using namespace std;
  vector<int> ivec;
  list<int> ilist;
  forward_list<int> flist;
  func(ivec.begin(),ivec.end()); //Derleyici compile time da func'a gönderilen vektörün iteratör türünü anlar. Funciton overload res. ile random access seçilir.
  func(ilist.begin(),ilist.begin()); //bidirectional 
  func(flist.begin(),flist.end()); //forward
}


Ex:
template<typename Iter>
void func(Iter beg,Iter end){
  using cat= typename Iter::iterator_category;

  if constexpr (std::is_same_v<cat,std::random_access_iterator_tag>){
    std::cout<<"random access\n";
  }
  else if constexpr(std::is_same_v<cat,std::bidirectional_iterator_tag>){
    std::cout<<"bidirectional\n";
  }
  else if constexpr(std::is_same_v<cat,std::forward_iterator_tag>){
    std::cout<<"forward\n";
  }
}

Ex. advance():

int main(){
  
  using namespace std;

  vector<int> ivec{2,4,6,7,9,3,1};
  vector<int> ilist{2,4,6,7,9,3,1};

  auto vec_iter= ivec.begin();
  auto list_iter=ilist.begin();

  advance(vec_iter,3); //iteratörün değerini değiştirir. 
  advance(list_iter,3);

  cout<<vec_iter[0]; //7 basıldı
}

Ex. distance():
int main(){

    using namespace std;

    list mylist{2,5,6,7,4,23,5};

    auto iter1=mylist.begin();
    auto iter2=mylist.end(); 
    advance(iter1,2);
    advance(iter2,-1);

    auto n=distance(iter1,iter2);
    cout<<"n= "<<n<<'\n';
    
}

Ex. next():

int main(){

    using namespace std;

    list mylist{2,5,6,7,4,23,5};
 
    auto iter = next(mylist.begin(),3); //default olarak ikinci parametre 1 değer alır ve birinci parametre sonrasındaki elemanı işaret eder.

    cout<<iter; //next iteratörün kendisini değiştirmez. call by value

}

Ex. prev():

int main(){

  using namespace std;

  list mylist{2,5,6,7,4,23,5};

  auto iter = prev(mylist.end());//iteratörün kendisini değiştirmez. call by value

  cout<<iter;

}


Ex. iter_swap:

template<typename Iter1, typename Iter2>
void IterSwap(Iter1 it1, Iter2 it2){
  std::swap(*it1,*it2);
}

Ex.2 iter_swap:

int main(){

  using namespace std;

  vector<string> svec{"ali","can","ela"};
  list<string> slist{"gul","eda","naz"};

  iter_swap(svec.begin(),slist.begin());

}

Osteram Iterator Adepter: Bir algoritmanın yazma işlemini bir stream'e, insertion'a, dönüştürür. Referans semantiğiyle bir stream
nesnesini sarmalar ve seperator string alır. Default olarak aldığı separator string, null string'dir(""). 

Ex:
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
int main(){
  using namespace std;
  vector<string> svec{"ali","can","ela"};
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
  cout<<'\n';
  copy_if(svec.begin(),svec.end(),ostream_iterator<string>{cout," "}, [svec](const string& s){return s=="ali";});
}

Iterator Invalidation: Bazı durumlarda iteratorlerin de tıpkı pointerler gibi(dangling pointer) geçersiz hale gelmesi söz konusudur.
Geçersiz hale gelen iteratorlerin kullanımı büyük hatalardır. 




*/
