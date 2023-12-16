/*
-> Sonunda copy olan algoritmalar, o algoritmayı range'in kendisi üzerinde değil başka bir range'e yazma suretiyle gerçekleştirirler.

-> reverse_copy: Bir range'in tersini başka bir range'e kopyalar. 

-> replace_copy: Range'e yapılacak değişiklik yapılmış gibi alıp onu başka bir range'e kopyalar.

-> remove_copy: remove_copy, silinen öğeler haricindeki öğeleri başka bir range'e kopyalar. 

Ex:
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<list>

int main(){
  using namespace std;

  vector<string>svec{"ali","veli","ahmet","hasan"};
  for_each(svec.begin(),svec.end(),[](const auto& s){cout<<s<<' ';});
  list<string> slist;
  reverse_copy(svec.begin(),svec.end(),back_inserter(slist));
  for_each(slist.begin(),slist.end(),[](const auto& s){cout<<s<<' ';});
}


Ex:
int main(){
  using namespace std;

  vector ivec{1,2,3,4,1,3,2,5,4,6,7,1,1,1,2};
  vector<int> destvec(100);
  auto iter= remove_copy(ivec.begin(),ivec.end(),destvec.begin(),1);
  std::cout<<"toplam "<<distance(destvec.begin(),iter)<<"eleman kopyalandı\n";
  
}

Ex:
int main(){
  using namespace std;
  vector ivec{1,2,3,4,1,3,2,5,4,6,7,1,1,1,2};
  vector<int> iivec;

  replace_copy(ivec.begin(),ivec.end(),back_inserter(iivec),1,3);
  
}




*/
