/*
-> Global isim alanı kapsamında bir fonksiyonu veya değişkeni vs. ikinci kez tanımladığımızda syntax hatası olur. C dilinde farklı başlık dosyalarında kullanılan aynı isimlendirmeleriyle de
karşı karşıya kalınabilir ve syntax hatası oluşur. Buna "global namespace pollution problem" denir.

-> Yazılan programlarda çok fazla isim kullanılır. Sadece standart kütüphaneden binin üzerinde isim kullanılabilir haldedir. Haliyle isimlerin çakışmasından korunmamız gerekir. Namespaces (isim alanları)
bu karışıklığı azaltmak için var olan bir kavramdır. Farklı kapsamlar (scope) içindeki isimlerin birbiriyle karışmamasını sağlar. 

-> Namespace, C'de olmayan fakat C++'da global isimlerin, farklı kütüphane veya modüllerden gelecek global isimlerin, birbirleriyle çakışmasını engellemek üzere dile eklenen araçtır.

-> Unary çözünürlük operatörüyle global namespace'teki öğeye erişim sağlayabildiğimizi hatırlayalım.

-> Global namespace içerisinde başka namespace'ler de oluşturulabilir ve hatta iç içe dahi kullanılabilirler.

Ex:
//Global Namespace
namespace Neco{
  namespace Erg{

  }
}

-> Standart kütüphane "std" namespace'i içerisinde yer alır.

-> Bir namespace içerisinde namespace oluşturulabilirken, bir fonksiyon veya bir sınıf içerisinde namespace oluşturulamaz. 

-> Namespace içinde tanımlanan değişkenler yine global değişkenlerdir.

-> Namespace bir scope belirtir. C'deki file scope'un C++'daki karşılığıdır.

-> Aynı scope'ta aynı ismi birden fazla kez vermek yine syntax hatası verir.

-> Binary çözünürlük operatörünün sol operandı bir namespace veya sınıf olarak belirtirsek sağ operandı o scope içerisinde aranır.

-> Kullanılan namespace'in içindeki namespace'e yine çözünürlük operatörüyle erişim sağlanabilir.

Ex:
#include <chrono>
int main(){
  std::chrono::duration // vs.
}

-> Derleyici yapılan bir namespace tanımından sonra, tekrar aynı isimli bir namespace görürse bunları kümülatif olarak ele alır. 

Ex:
namespace onur{
  int a{};
  int b{};
}
namespace onur{
  int c{};
}

-> Namespace'i isimsiz olarak tanımlasak unnamed namespace olur. Syntax hatası olmaz. Global namespace'i belirtmez.

-> Bir namespace içindeki ismin nitelenmeden scope resolution operator kullanmadan derleyici tarafından bulunması için 3 tane ayrı araç vardır.
- using declaration
- using (namespace) directive
- ADL (Argument Dependent Lookup)

*/
