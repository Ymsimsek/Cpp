/*
-> for_each(), range'deki öğeleri bir callable'a gönderir. Yani range'deki öğelerin hepsini bir işleme sokar. 

-> transform() fonksiyonundan farkı, transform() geri dönüş değerini bir range'e yazar ancak for_each yalnızca fonksiyon çağırır.

-> Fonksiyonun template'ine benzer uygulama:
template<typename Iter, typename F>
F ForEach(Iter beg, Iter end, F f){
  while (beg!=end){
    f(*beg++);
  }
  return f;
}

-> for_each()'in geri dönüş değeri kullanımı zorunlu değildir. for_each()'in geri dönüş değeri objenin kendisidir. 

Ex:
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
int main(){
  using namespace std;
  vector<string> svec {"ali","veli","ahmet","hasan"};
  for_each(svec.begin(),svec.end(),[](const auto& s){std::cout<<s<<'\n';}); 
}

Ex:
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
int main(){
  using namespace std;
  vector<string> svec {"ali","veli","ahmet","hasan"};
  for_each(svec.begin(),svec.end(),[](auto& s){
    s+="can";
    std::cout<<s<<'\n';}); 
} 








*/
