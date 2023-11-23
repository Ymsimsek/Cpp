/*
Moved from State (Taşınmış Nesne Durumu)

Ex:
#include<string>
#include<iostream>

std::string foo();

int main(){
  using namespace std;
  string s;
  s=foo();// foo() R value exp o yüzden move assgn çağırıldı
  string str(100'000,'A');
  s=str;//str L value, copy assgn çağırıldı.
  string sx= std::move(str);// Kaynağı çalınır, henüz str'nin destr. çağırılmadı. Str hayatta ancak kaynağı yok yani moved from state
}

-> Tipik olarak (Zorunlu olmamakla beraber) move memberlar kaynağı çalınmış diğer nesneyi default construct edilmiş state'te bırakırlar.

-> Kaynağı çalınmış nesne, geçerli bir durumda (in a valid state) veya değeri bilinmeyen şekilde olabilir(value unknown). 

-> Moved-from state'de olan nesneyi ancak yerine başka bir atama yaparak kullanabiliriz. 

*/
