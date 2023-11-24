/*
Using Declaration: Kullanımı "using namespace_isim::isim;" şeklindedir. Using bildiriminin bir kapsamı vardır ve o kapsam
içinde etkin olur. Bildirilen isim, isim alanına enjekte edilir ve sanki o kapsamda tanımlanmış gibi etki gösterir.

Ex:
namespace emre{
  int x{};
}
int main(){
  int x{45};
  using emre::x;//syntax hatası
}

Ex:
namespace emre{
  int x{};
}
int main(){
  using emre::x;
  x+=1; //Legal, maine injekte edildi.
}

Ex:
namespace emre{
  int x{};
}
void foo(){
  int x{};
}
void bar(){
  x=2;      //Hata using daha yukarıda belirtilmeli.
}
using emre::x; 

Ex:
namespace ali{
  int x;
}
namespace veli{
  using ali::x;
}
int main(){
  using veli::x;
  x=15; //Geçerli
}

*/
