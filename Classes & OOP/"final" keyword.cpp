/*
final Keyword: Eğer bir sınıftan kalıtım yapılması istenmiyorsa syntax düzeyinde kalıtım yapıldığında hata verilmesini sağlayan contextual keyword olan "final" kelimesi kullanılır.

Ex:
class Base final{};

//veya

class Der final: public Base{};

-> Eğer bir fonksiyonun override edilmesini istemiyorsak da final kelimesini kullanabiliriz.

Ex:
void func() override final;

*/
