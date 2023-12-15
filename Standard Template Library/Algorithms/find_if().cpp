/*
Ex:

int main(){
  
  using namespace std;
  
  list<string> slist{"ali","veli","ahmet","kırmızı","mavi","gol","kablo"};
  char c;
  cout<<"Hangi harf: ";
  cin>>c;

  auto iter = find_if(slist.begin(),slist.end(),[c](const string &s){return s.contains(c);});

  if (iter!= slist.end()){
    cout<<"bulundu... idx= "<<distance(slist.begin(),iter)<<'\n';
  }
  else{
    cout<<"bulunamadı.";
  }
}




































*/
