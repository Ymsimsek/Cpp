/*
Constructor Initializer List, sınıfın data member'larının initialize ediliş syntaxıdır. 

Ex:
class myClass{
public:
  myClass():mx(19),my(20){}
  void print()const{
    std::cout<<"mx= "<<mx<<"my= "<<my;
  }
  int mx,my;
};

//veya 

class myClass{
public:
  myClass(){}
private:
  int mx,my; // Bu yanlış bir kullanımdır. Private değişkenleri client tarafından initialize edilmesi mantıklı değildir.
};

int main(){
  myClass::myClass:mx(10),my(20){}  // initialize yapılırken "{}" veya "()" kullanılabilir. "{...}" narrowing conversion'da syntax hatası verir.
}

-> Ctor initialize edilmemiş data member'lar garbage/indetermined value olurlar. (Eğer initialize edilmemişse)

-> Sınıf nesnesinin data memberlarının hayata geliş sırası bildirimdeki gibidir, initializer'daki sıra önemli değildir. 

Ex:
myclass():my(10),mx(my/3){}  // Undefined Behavior. my henüz initialize edilmediği için değeri henüz kullanılamaz. Bildirim sırasında my, mx'ten daha önce tanımlanmalıdır. 
int mx,my; 

-> const nesneler default initialize edilemezler. Eğer const daha member initialize edilmemişse ve default initialize edilmişse ctor initializer list'te initialize edilmelidirler. 

-> Referanslar da default initialize edilemezler.

*/
