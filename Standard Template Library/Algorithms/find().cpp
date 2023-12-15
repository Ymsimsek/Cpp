/*
-> STL'deki arama algoritmalarının geri dönüş değeri iteratördür. Aranan değer bulunursa öğenin konumu döndürülür. Yoksa fonksiyona geçilen end konumu döndürülür.
Ex:
InIter Find(InIter beg, InIter end, const Key& val){
  while(beg!=end){
    if(*beg==val)
      return beg;

    ++beg;
  }
  return beg;
}

int main(){
  using namespace std;
  
  vector<int> ivec{4,6,7,8,9,1,24,7,9};

  int ival{1};

  auto iter = Find(ivec.begin(),ivec.end(),ival);
  if(iter != ivec.end()){
    cout<<"bulundu"<<iter<<'\n';
    cout<<"indeks= "<<iter-ivec.begin()<<'\n';
  }
  else{
    cout<<"bulunamadı.\n";
  }
}





*/
