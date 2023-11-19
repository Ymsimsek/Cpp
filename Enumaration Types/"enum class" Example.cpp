enum class Color{Blue, Red, Purple};

void func(){
  using enum Color;//C++20
  Color c1 = Red;
  c1=Purple;
  Color c2= Black;
}

void func2(){
  using Color::Blue;//C++20
  Color c1{Blue};// Legal
  // Color c2{Red}; Syntax Error
  using Color:: Red;
  Color c2=Red; // Legal
}

enum class baseColor{Blue, Red, Purple};
enum class screenColor{Blue,Red};
void func3(){
  using enum baseColor;
 // using enum screenColor; Syntax Error
}
