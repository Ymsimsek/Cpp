/* 
Ex:
template<typename InIter, typename OutIter>
OutIter Copy(InIter beg, InIter end, OutIter destbeg){ //Önce kaynak sonra hedef. Algoritmalarda exception throw mekanizması yoktur. destbeg'den sonra taşma oluyorsa tanımsız davranış, beg'den ilerlemeye başlayıp end'e gelinemiyorsa yine tanımsız davranış 
  //Algoritma yazma işlemi yapıyorsa geri dönüş değeri en son yazılan konumdan sonraki konumdur.   

  while(beg != end){
    *destbeg++ = *beg++; //Aynı container işlem yapma zorunluluğu yoktur.
  }
  return destbeg;
}


int main(){
  using namespace std;

  vector<int> ivec{2,4,6,7,8,2};
  list<int> ilist;

  //Copy(ivec.begin(),ivec.end(),ilist.begin());  Tanımsız davranış, boş listenin begin fonksiyonu çağırılabilir ancak dereference edemeyiz. Bu çağrıya uyması için en az 6 üye olması gerekir.
 
}

Ex:
template<typename InIter, typename OutIter>
OutIter Copy(InIter beg, InIter end, OutIter destbeg){ //Önce kaynak sonra hedef. Algoritmalarda exception throw mekanizması yoktur. destbeg'den sonra taşma oluyorsa tanımsız davranış, beg'den ilerlemeye başlayıp end'e gelinemiyorsa yine tanımsız davranış 
  //Algoritma yazma işlemi yapıyorsa geri dönüş değeri en son yazılan konumdan sonraki konumdur.   

  while(beg != end){
    *destbeg++ = *beg++; //Aynı container işlem yapma zorunluluğu yoktur.
  }
  return destbeg;
}
int main(){
  using namespace std;

  vector<int> ivec{2,4,6,7,8,2};
  list<int> ilist(10);
  auto iter = Copy (ivec.begin(),ivec.end(),ilist.begin());
}


Ex: 
#include <vector>
#include <algorithm>
#include <string>

int main(){

  using namespace std;

  const char* const p[] = {"ali","veli","mehmet","tamer", "gökhan"};
  vector<string> svec(6);
  
  copy(begin(p),end(p),begin(svec)); // p svec'e kopyalandı
  
}



*/
