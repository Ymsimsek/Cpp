/*
Bazı sınıflar move edilebilirler ancak copy ctor ve copy assignment çağrılınca sytnax hatası olur. Çünkü copy memberlar delete edilmiştir.

Ex:
class Nec{
public:
  Nec();
  Nec(const Nec&) = delete;
  Nec& operator=(cont Nec&)= delete;
  Nec(const Nec&&);
  Nec& operator=(cont Nec&&);
};

-> Stardart kütüphanede başta "std::unit*" olmak üzere "iostream" sınıfı gibi sınıflar da taşınabilir ancak kopyalanamayan sınıflardır.

-> Hem kopyalama hem de taşımaya kapatılmak istenen sınıflar için copy memberların delete edilmesi yeterlidir.

-> Asla move member'ları delete etmemeliyiz çünkü edildiğinde copy'e fallback edilecek çağrı syntax hatası durumuna gelir. 

-> Move member'lara yapılacak çağrı move yoksa copy'e fallback olur.

*/
