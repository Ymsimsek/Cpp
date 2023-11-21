/*
Classes: Classes are user-defined types.

  
Class Definition Syntax:

class myClass{
        //class scope
int x; // class member
};


Class Members:

-> Data Members:
- Static Data Members
- Non-Static Data Members

-> Member Functions:
- Static Member Functions
- Non-Static Member Functions

-> Member Types/ Type Members/ Nested Types


Member Selection Operators: ".", "->"


Name Lookup: Bir ismin class scope'ta aranması için 3 tipik senaryo vardır. Bu senaryolara nitelenmiş isim kullanımı denir.

- .x
- ->y
- ::a

Yukarıdaki a,x ve y class scope'ta aranır. 

Kullanım Şekilleri:

- classname.x
- ptr->y
- classname::a 

!!Class member olmadan tanımlanan classlara empty class adı verilir.  

class myClass{
  int mx; //non-static data member
};

Access Control Keywords:
- Public
- Private 
- Protected 

Access kontrol anahtar sözcükleri; üye fonksiyonları, data üyelerini, veya üye türlerini niteleyebilir.

Public Members: Client ve sınıflara açık (herkese).
Private Members: Sadece tanımlandığı sınıfa açık.
Protected Members: Sınıfına ve kalıtım edilen sınıflara açık.

-> Class tanımlanırken default olarak private'dır. Public veya protected member'lar için ek belirtme yapılır. Private kullanmak da dil içinde legaldir.

Ex:
class Data{
public:
  int x;
private:
  int y;
protected:
  int z;
};



*/
