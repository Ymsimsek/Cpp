/*
namespace nec_project{
  int a;
  class myClass{};
}
namespace nec=nec_project;
int main(){
  namespace rng=std::ranges;
  rng::adjacent_find;
}

-> C++20 ile inline kelimesi nested namespace'in başının dışındaki kullanımlar da legal hale geldi. (namespace ali::veli::inline can)

-> İsim vermeden kaynak dosyada bir namespace oluşturursak namespace'in içindeki isimler doğrudan iç bağlantıdalardır.

-> İsimsiz namespace'de bir isim oluşturmak adeta aynı şey olmasa da "static int x" gibi global static değişken, fonksiyon vs. sayılabilirler.

-> Unnamed namespace'in getirilerinden biri, dışarıyla alakası olması istenmeyen, sadece global değişkenlerin değil, fonksiyon ve türlerin de isimsiz isim alanlarında ODR'ı ihlal etmeden sadece o modül
veya implementasyonda kullanılacak öğe olduğunu hem okuyana gösterip hem de ODR'ı ihlal etmemiş oluruz. 

Ex:
//mehmet.cpp
namespace{
  int x{10};
  class Array{};
}
//ahmet.cpp
namespace{
  double x{102};
  class Array{};
}
//veli.cpp
namespace{
  int x{120};
  class Array{};
}

-> Unnamed namespace içerisindeki isimler, derleyici tarafından isim atanıp ardından using ile bildirilmiş gibi ele alınabilir.

-> Unnamed namespace'ler de kümülatiftir.

*/
