/*
-> Tür dönüştürme operatör fonksiyonlarının geri dönüş değeri türü en başa yazılmaz çünkü geri dönüş değeri türü operator anahtar sözcüğünü izleyen türdür.

-> Fonksiyonun geri dönüş değeri türünün, yani dönüştürmenin yapılacağı hedef tür, pointer, referans, başka bir sınıf türü vs. olabilir. Bu konuda kısıtlama yoktur. 

Ex:
class Erg{};
class Nec{
public:
  operator int();
  operator double();
  operator Erg();
};

int main(){
  Nec myNec;
  Erg myErg;
  myErg=myNec; // Geçerlidir
}

-> Tür dönüştürme operatör fonksiyonları birçok faydayı sağlasa da çok büyük risk de içerir. Böyle fonksiyon bildirimleri, derleme aşamasında örtülü dönüşümü tetikleyecektir. Bu dönüşüm user-defined conversion'a örnektir.

-> Modern C++'da "explicit" anahtar sözcüğüyle kullanabiliriz. "explicit" kelimesi örtülü dönüşümü engeller.

-> Sınıfların operator bool fonksiyonları (hemen her zaman) explicit olarak bildirilir. Logic ifadeler, fonksiyon explicit olduğunda da bir logic state bildirdikleri için kullanılabilirler.

-> Birçok standart kütüphane sınıfı operator bool()'u overload ettiği için logic statementlara argüman olarak dahil edilebilirler.

*/
