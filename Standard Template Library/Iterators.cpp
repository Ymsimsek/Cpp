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












*/
