#include <iostream>
#include<cmath>
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l){
    
    if (l % a == 0 && l % b == 0)
      return l;
      
  }   
        return (long long) a * b;
}
long long lcm_faster(long long int a, long long int b){
 int remainder;
  int prev_remainder;
   int y;
  if(a==b)
  return (a*b)/a;
  if(a==1 || b==1)
  return (a*b);
  if(a>b){
  remainder=a%b;
  prev_remainder=remainder;
  if(prev_remainder==0)
   return(a*b)/b;
  remainder=b%remainder;
   }
  else {
  remainder=b%a;
  prev_remainder=remainder;
  if(prev_remainder==0)
   return (a*b)/a;
  remainder=a%remainder;
  }
  if (remainder==0)
  return (a*b)/prev_remainder;
  int rn=prev_remainder;
  int rn1=remainder;
  while(1){
     y=rn%rn1;
     rn=rn1;
     rn1=y;

  if(y==0)
   break;
 }
  return(a*b)/rn;

  }






int main() {
 long long int a, b;
  std::cin >> a >> b;
//std::cout <<"naive"<<lcm_naive(a, b) << std::endl;
 std::cout << lcm_faster(a, b) << std::endl;
  return 0;
}
