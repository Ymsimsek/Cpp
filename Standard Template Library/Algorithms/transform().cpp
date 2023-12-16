/*
Transform fonksiyon şablonunun yaklaşık tanımı:
template<typename InIter, typename OutIter, typename F>
OutIter Transform(InIter beg, InIter end, OutIter destbeg, F f){ //beg, end aralığındaki tüm öğeler f'e argüman olarak gönderilir. f'in geri dönüş değerini de destbeg'den başlayarak yazar.
  while(beg!=end){
    *destbeg++ = f(*beg++)
  }
  return destbeg;
}


Ex:
auto get_len(const std::string& s ){
  return s.size();  
}


int main(){
  
  using namespace std;

  vector<string> svec {"ali","fatma","hayri","gul","can"};
  list<size_t> lenlist;

  transform(svec.begin(),svec.end(), back_inserter(lenlist), get_len);  
}

--- Lambda ifadesiyle:  transform(svec.begin(),svec.end(), back_inserter(lenlist),[](conststring& s) {return s.size();});  ------------




*/
