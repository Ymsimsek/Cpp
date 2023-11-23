/*
-> Sınıfların tek parametreli ctorları varlık nedenlerinin yanı sıra sınıf türünden olmayan bir ifadeyi sınıf türüne dönüştürme görevini de gerçekleştirirler. Böyle ctor'lara conversion ctor denir. 

Ex:
class myClass{
public:
  myClass()=default;
  myClass(int); //conversion ctor
};
int main(){
  myClass mx;
  mx=5; //Legal
}

-> Derleyici myClass(int)'e çağrı yapıp bir geçici nesne oluşturur. Böylece atama operatörünün sağ tarafındaki '5' ifadesi derleyicinin örtülü olarak çağırdığı ctor kullanılarak bir myClass nesnesine
  dönüşecek ve burada myClass sınıfının atama operatör fonksiyonu çağırılacak. Varsa taşıma yoksa kopyalama atama fonksiyonlarıyla integer'ı örtülü olarak myClass'a dönüştürecek.

-> Eğer bir dönüşüm aşağıdaki dönüşüm sekanslarından biriyle gerçekleştirilebiliyorsa derleyici bu dönüşümü örtülü olarak yapmak zorundadır. 
- User defined conversion + standard conversion
- Standard conversion + user defined conversion

-> Bazı durumlarda üst üste iki kez user defined conversion yapılmak zorunda kalınırsa syntax hatası oluşur. 

*/ 
