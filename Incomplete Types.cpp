/*
Incomplete Type: Derleyici eğer bir türün varlığından haberdar ise fakat henüz onun tanımını görmemişse o tür derleyicinin bakış açısıyla "incomplete type"'dır.

Ex:
class myClass; //Forward Declaration
int main(){
// myClass incomplete type
}

-> Bazı işlemler ve bildirimler için bir sınıfın complete type olması gerekmez.

-> Incomplete types kullanılarak pointer ya da referans değişkeni tanımlayabiliriz.

Ex:
class Ali;
Ali* foo();
Ali& bar();
void baz(Ali& r);

int main(){
  Ali* p = foo();
  Ali& r = bar();
  baz(r);
}

-> Başka modullerde tanımı yapılmış olan ifadeler için "extern" anahtar kelimesi kullanılabilir. 
class Emre;
extern Emre ge;
extern Emre ga[];

-> C'de bir yapının kendi türünden non-static veri elemanı olamaz ancak kendi türünden static elemanı olabilir. 

-> "void" bir türdür ve incomplete type'dır.

-> Incomplete type olan bir sınıf için değişken tanımlanırsa:
class Nec{};
int main(){
  Nec mynec; //Hata!
}
Pointer değişken tanımlanabilir ancak elemanlara erişmek için kullanılamaz. 
class Mert;
Mert* foo();
int main(){
  Mert* p = foo(); // Geçerli
  *p =  .. // Geçersiz
  p-> x = 5 // Geçersiz
}
Yani incomplete type pointer dereference edilemez.

-> Incomplete type'ları sizeof operatörünün operandı olamaz.

*/

  

