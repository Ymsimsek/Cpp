#include <iostream>
enum class weekDay{
  Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday
};

weekDay& operator++(weekDay& wd){
  using enum weekDay;
  return wd=wd==Saturday?Sunday:static_cast<weekDay>(static_cast<int>(wd)+1);
}

weekDay operator++(weekDay& wd, int){
  weekDay temp{wd};
  ++wd;
  return temp;
}

std::ostream& operator<<(std::ostream& os, const weekDay& wd){
  static const char* const pwdays[] = {"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
  return os<< pwdays[static_cast<int>(wd)];
}

int main(){
  weekDay wd{weekDay::Saturday};
  std::cout<<wd++<<" "<<wd;
}
