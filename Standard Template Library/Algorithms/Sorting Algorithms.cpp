/*
sort(): Rangedeki öğeleri belirli bir kritere göre konumlandırmaktır. n log(n) karmaşıklığındadır. Sort'un stable olma zorunluluğu
yoktur.

Ex:
int main(){
  using namespace std;
  vector<string>svec{"ali","veli","ahmet","hasan","ayse","can","melda","selda"};
  sort(svec.begin(),svec.end());
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
}

Ex:
int main(){
  using namespace std;
  vector<string>svec{"ali","veli","ahmet","hasan","ayse","can","melda","selda"};
  sort(svec.begin(),svec.end(),greater{});
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
}

stable_sort(): Bidirectional iterator ister. Sıralama algoritmaları stable veya unstable olabilir. Stable olması aynı değere sahip key'lerin (örneğin bir isim
grubundaki aynı isimler), sıralama yapıldıktan sonra yapılmadan önceki sıralamalarının aynı olacağının garanti olduğu anlamına gelir.
Ex:

stable_sort(svec.begin(),svec.end(),[](const string& x, const string& y){return x.second<y.second;}); //second ifadesi std::pair ile çiftlenen gruptan gelir.

partial_sort: Range'deki öğelerin tamamını değil ilk n tanesini konumlandırmaktır. Birinci ve üçüncü parametreye sıralanacak range'in
iteratorleri geçilir. İkinci parametreye ilk kaç öğe sıralanacaksa onun değeri geçilir. 
Ex:
int main(){
  using namespace std;
  vector<string>svec{"ali","veli","ahmet","hasan","ayse","can","melda","selda"};
  partial_sort(svec.begin(),svec.begin()+2,svec.end());
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
}
Ex:
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
int main(){
  using namespace std;
  vector<string>svec{"ali","veli","ahmet","hasan","ayse","can","melda","selda"};
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
  cout<<'\n';
  partial_sort(svec.begin(),svec.begin()+3,svec.end());
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
  vector<string> ssvec(10);
  cout<<'\n';
  partial_sort_copy(svec.begin(),svec.begin()+3,ssvec.begin(),ssvec.end());
  copy(ssvec.begin(),ssvec.end(),ostream_iterator<string>{cout," "});
}

nth element: Bu algoritma n. elemanı yerine koyar. n'den öncekile.r ondan küçük, sonrakiler ondan büyüktür. Öncekiler ve sonrakiler 
kendi içinde sıralı olmak zorunda değillerdir. En tipik kullanımı: Medyan değeri
Ex:
int main(){
  using namespace std;
  vector<string>svec{"ali","veli","ahmet","hasan","ayse","can","melda","selda"};
  nth_element(svec.begin(),svec.begin()+4,svec.end()); //ali ahmet ayse can hasan melda selda veli  
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "}); 
}

Ex:
int get_median(std::vector<int> vec){
  using namespace std;
  nth_element(vec.begin(),next(vec.begin(),vec.size()/2),vec.end());
  return vec[vec.size()/2];
}
int main(){
  using namespace std;
  vector ivec{1,35,37,6,53,6,4,7,9,1,3,5,87,1};
  cout<<"median: "<<get_median(ivec);
}

partition: Bir kritere göre bölümleme yapmak demektir. O kritere uyanları başa uymayanları sona dizmektir. Stability önemlidir. 
Ex:
int main(){
  using namespace std;
  vector<string>svec{"ali","veli","ahmet","hasancan","ayse","can","melda","seldacan"};
  partition(svec.begin(),svec.end(),[](const string& s){return s=="can";}); //can veli ahmet hasancan ayse ali melda seldacan  a  
  copy(svec.begin(),svec.end(),ostream_iterator<string>{cout," "});
} 


















*/
