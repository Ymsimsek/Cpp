/*
-> Yazma işlemi yapan bir algoritmanın, bir container'a push_back'e dönüştürmesi için hedef yazı başlangıç konumuna back_inserter ile çağrı yapabiliriz.

Ex: 
int main(){
  using namespace std;
  rfill(svec, 10000,[]{return rname()+' '+rfname();});
  vector<string> dvec;
  size_t len;

  cout<<"uzunluğu kaç olanlar kopyalansın: ";
  cin>>len;

  copy_if(svec.begin(),svec.end(), back_inserter(dvec),[len](const string& s){return s.length()==len;}); 

  std::ofstream ofs{"out.txt"};
  if(!ofs){
    std::cerr<<"out.txt dosyası oluşturulamadı.\n";
    exit(EXIT_FAILURE);
  }
  print(dvec,"\n",ofs);
}


-> front_inserter ile container'in push_front fonksiyonu kullanılmış olarak arzu edilen range, hedefin ön sıralarından başlanarak eklemeye tabi tutulur.

-> inserter fonksiyon çağrıları ile container'in insert fonksiyonu ile yapılan çağrıya dönüştürür. Insertion'un belirli bir iterator konumuna arzu edilen hedef aralığını eklemek için kullanılabilir. 







*/
