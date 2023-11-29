/*
std::string: Bir sınıf şablonudur (class template). Container niteliği taşır. Sequence containers'a tabidir. String yazı isimleri için interface'i özelleştirilmiş
dinamik dizi sınıfıdır. Operator overloading'den çokça yararlanan bir kütüphanedir. Karşılaştırma operatörlerini, spaceship operatörü ile overload ederler (C++20 ile eklendi). 

-> String fonksiyonlarda, yazı uzunluğu türü, kapasite türü, bir ya da iki parmetre indeks değeri, karakterlerin adet sayısı, npos;"size_type" türü cinsindendir. (std::string::size_type)

-> String fonksiyonlarına girilebilen bazı argümanlar ve temsiliyetleri:
- const string& //whole string 
- const string&, size_type idx//sub string, indexten string sonuna
- const string&, size_type idx, size_type len //substring, indexten len kadar ileri
- const char* //cstring, son parametresi nullptr olan string
- const char*, size_type len //Data parameter, char* adresinden len kadar ileri
- char //karakter
- size_type n ,char c //n adet c karakteri
- iterator beg, iterator end //range parameter

Ex:
int main(){
  std::string s1(50,'A'); //50 Adet A karakterine sahip dizi 
  std::string s2{50,'A'} //2 ve A karakterlerine sahip dizi
}

String Sınıfının Fonksiyonları: 

Ex:
int main(){
  using namespace std;
  string s1; //Default ctor'u çağırılacak boş yazı tutacak 
  cout<<"s1.length()="<<s1.length()<<'\n'; // "0" değeri döndürülecek, dizinin uzunluğunu gösteren fonksiyon length()
  cout<<"s1.size()="<<s1.size()<<'\n'; //  "0" değeri döndürülecek, dizinin boyutunu gösteren fonksiyon size(), common container interface
}

-> Stl container'lerin tutuğu öğe sayısını döndüren fonksiyon size() öğe fonksiyonudur. (forward list hariç) (Generic programlamada)

Ex:
int main(){
  using namespace std;
  string s1;
  s1.empty(); // empty boolean fonksiyonudur. 0 veya 1 olarak çıktı verir. Eğer container boşsa 1 döndürür.
  }

Ex:
int main(){
  using namespace std;
  string str("ahmet");
  cout<<str.size(); // 5
}

Ex:
int main(){
  using namespace std;
  char ar[] = {'A','B'}; // C ctor
  string str(ar); //Undefined behaviour
}

Ex:
int main(){
  using namespace std;
  char ar[] = "murathan";
  string str(ar+3,2); //"ar+3" parametresi dizinin başlangıcını 3 karakter ileri attı ve "2" parametresi başlangıçtan 2 karakteri bastı
  cout<<str; // "at" ekrana basılır. 
}

Ex:
int main(){
  using namespace std;
  char ar[] = "murathan";
  string str(ar,20); // ub 
}

Ex:
int main(){
  using namespace std;
  char ar[] = "murat"; //dizi sonunda null character var
  string str(ar,6); // Hata yok 
}

-> Geçici nesne kullanabilirken nesneleri isimlendirdiğimizde boşuna copy elision veya taşıma devreye girer. Onun yerine geçici nesne ile sorunları çözmek daha iyi bir çözümdür.

Ex:
int main(){
  using namespace std;
  size_t n;
  cout<<"kaç tane";
  cin>>n;
  cout<<string(n,'*'); //n kadar '*' karakteri ekrana basılır. 
}

Ex:
int main(){
  using namespace std;
  string str(20,'\0'); // 20 adet null character tutar 
}

Ex:
int main(){
  using namespace std;
  string s1(100,'A'); 
  string s2(s1); //copy ctor çağırılır. l value verildi
  string s3(std::move(s1)); //move ctor çağırılır. s1'i sağ taraf referans yaptığı için move ctor çağırılır. 
}

Ders 29, 2:06:19



*/
