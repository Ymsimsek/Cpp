/*
Using directive, bir bildirimdir. Tüm bildirimlerde olduğu gibi bu bildirimin de bir kapsamı vardır ve bu bildirim, bildirim kapsamında etkindir. 

Ex:
namespace ali{
  int x,y,z;
}
int main(){
  using namespace ali;
  x=5;
  y=5;
  z=3; // 3 tanım da geçerli.
}

Ex:
namespace ali{
  int x=99,y,z;
}
int main(){
  using namespace ali;
  x=5; //Geçerli x =5 
}

Ex:
namespace ali{
  int x=99;
}
namespace veli{
  int x=99;
}
int main(){
  using namespace ali;   //Hata yok
  using namespace veli; //Hata yok
  x=4; //Ambiguity Error
 
}

*/
