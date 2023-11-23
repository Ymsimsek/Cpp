/*
    Aşağıdaki metin derleyicinin hangi durumlarda hangi özel fonksiyonu yazıp yazmayacağını içerir. 
  
-> Eğer sınıfa herhangi bir special member function bildirimi yapılmazsa derleyici, sınıfın altı özel üye fonksiyonunu da implicitly declare eder.

-> Eğer default ctor olmayan, special function da olmayan bir ctor yazarsak derleyici default ctor haricindeki tüm special function'ları kendisi yazar.

-> Eğer destructor user-declared olursa, derleyici default ctor'u yazar. Destructor default edilmez. Copy ctor ve copy assignment da yazılır ancak move memberlar yazılmaz.

-> Eğer copy ctor user-declared olursa, derleyici default ctor'u default etmez. Destructor, derleyici tarafından default edilir. Copy assignment'i yine derleyici yazar ve felakete sebep olur. Yine move memberlar bulunmaz.

-> Eğer copy assignment user-declared olursa default ctor ve destructor default edilir. Copy ctor' da default edilir ve yine felakete yol açar. Move memberler yine bulunmaz.

-> Eğer move ctor user-declared olursa, (derleyici tarafından) default ctor yazılmaz. Destructor default edilir. Copy ctor ve copy assignment delete edilir. (derleyici tarafından) Move assignment yazılmaz.

-> Eğer move assignment yazarsak derleyici default ctor'u ve destructoru default eder. Copy memberları delete eder ve move ctor'u yazmaz. 
  
*/
