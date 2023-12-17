/*
-> STL'de remove, remove_if, unique olarak adlandırılan, silme işlevini yerine getiren algoritmalardır. Silme algoritmalarının geri
dönüş değeri türü iter'dir. Logic_end dediğimiz bir değer döndürür.

remove: Bir rangede belirli değere sahip olan öğeleri siler. Aslında fiilen bir silme işlemi yapmaz. Range'i öğeler silinmiş gibi düzenler 
ve silinmemiş son öğeden sonraki konumu döndürür. Remove'un döndürdüğü iterator'u vektorün end() ile range yapıp erase'e gönderirsek
gerçekten silinmiş olur.

remove_if: Belirli koşulları sağlayan, unary predicate'ın true değer verdiği öğeleri siler.

unique: Ardışık aynı değerdeki öğelerin sayısını bire indirir.

remove():
Ex:
int main(){
  using namespace std;
  vector<string>svec{"ali","can","veli","mehmet","can"};
  auto logic_end_iter = remove(svec.begin(),svec.end(),"can");
  cout<<"size= "<<svec.size()<<'\n'; //size: 5

  cout<<"silinmemis oge sayisi: "<<distance(svec.begin(),logic_end_iter)<<'\n';
  cout<<"silinmis oge sayisi: "<<distance(logic_end_iter,svec.end())<<'\n';

  svec.erase(logic_end_iter,svec.end());
  cout<<"size= "<<svec.size()<<'\n'; //size: 3
}

Remove-Erase Idiom: Tek satırda yukarıdaki işlev tamamlanabilir. 
svec.erase(remove(svec.begin(),svec.end(),"can"),svec.end());

C++20 ile doğrudan containerdeki belirli öğelerin tümünü silip, silinen öğe sayısını döndüren bir erase() overload'ı dile eklendi.
auto n = erase(svec,"can"); //C++20

remove_if(): Removeden farklı olarak bir unary predicate argümanı alır.
Ex:
int main(){
  vector<string>svec{"ali","can","veli","mehmet","can"};
  size_t len = 6;
  svec.erase(remove_if(svec.begin(),svec.end(),[len](const string& s){return s.size()==len;}),svec.end());//mehmet silindi uzunluğu 6 olanları silmek
}

erase_if() kullanarak da bu işi yapabilirdik:
auto n = erase_if(svec,[len](const string& s){return s.size()==len;});
cout<< n <<"  eleman silindi";

unique():
Ex:
int main(){
  using namespace std;
  vector vec{2,5,6,5,5,7,8,3,3,3,3,9,9,8,2,9,1};
  vec.erase(unique(vec.begin(),vec.end()),vec.end()); //Her sayıdan sadece birer adet kaldı. Yine erase-remove'daki gibi erase-unique kullanıldı.

}
Ex:
int main(){
  using namespace std;
  vector vec{2,-5,6,5,5,7,8,-3,3,3,3,-9,9,8,2,9,1};
  vec.erase(unique(vec.begin(),vec.end(),[](int a, int b){return abs(a)==abs(b);}),vec.end()); // negatif değerlerden de sonradan gelenler silindi.
//2,-5,6,7,8,-3,-9,1
}

Elle girilen dizide boşlukların sayısını bire indirme örneği:
Ex:
int main(){
  using namespace std;
  string str;
  cout<<"bir yazi girin: ";
  getline(cin,str);
  cout<<"["<<str<<"]\n";
  str.erase(unique(str.begin(),str.end(),[](char c1,char c2){return isspace(c1)&&isspace(c2);}),str.end());
  cout<<str;
}


























*/ 
