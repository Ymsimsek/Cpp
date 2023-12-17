/*
Geri dönüş değeri std::pair olan bu algoritma çağırıldığı container range'i için pair'in ilk elementinde min, ikinci elementinde max
değeri tutar.

Ex:
int main(){
  using namespace std;

  vector<string> svec{"Mehmet","Gul","Melek","Acar","Akalın","Akdağ","Akdemir","Aktan"};
  auto ip = minmax_element(svec.begin(),svec.end());
  cout<<"min= "<<*ip.first<<'\n'<<"max= "<<*ip.second; //min= Acar , max= Melek 
}






















*/
