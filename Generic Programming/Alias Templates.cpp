/*
-> Type alias C++'da çok önemli bir yer tutar ve genellikle using bildirimleri kullanarak oluşturulur. Using bildiriminin template
olarak kullanılmasına da alias template adı verilir.

-> Derleyici alias template'den faydalanarak o template'in specialization'unu oluşturduğunda bir alias declaration ortaya çıkar. 

Ex:
template<typename T>
using ptr=T*;

int main(){
  ptr<int> p; //p'nin türü int*
  ptr<double> dp; //dp'nin türü double*
}

Ex:
template<typename T>
using Ar10 = T[10];

int main(){
  Ar10<int> x; //x 10 elemanlı integer dizi
  Ar10<double> y; //y 10 elemanlı double dizi
}

Ex:
template<int N>
using Ar = int[N];

int main(){
  Ar<10> x; //x 10 elemanlı bir int dizi
}

Ex:
template<typename T, std::size_t N>
struct Array;

template<std::size_t N>
using intAr= Array<int,N>

int main(){
  intar<20> x; //Array'in int,20 açılımı
}




*/
