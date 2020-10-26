#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  int temp;
  int temp1;
  int n;
  n=a.size();
  int multiple=1;
  int m[n]={1};
  int max=0;
  int deal[n]={0};
 //find max
 for(int i=0;i<n;++i){
  deal[i]=std::stoi(a[i]);
  
 }
 for(int i=0;i<n;++i){
   if(deal[i]>max)
    max=deal[i];
   

 }       

//find the no of digits of the greatest no
while(max/multiple!=0)
multiple=multiple*10; 

multiple=multiple/10; 

//have all digits as numbers with the same number of digits ex: 21 3 9 they came 21 30 90 all of them have same number of digits 
int y[n];
for(int i=0;i<n;++i){
   if(deal[i]==0){
      m[i]=1;
      continue;
    }  
    y[i]=multiple;
   while(deal[i]/y[i]==0){
     y[i]=y[i]/10;
     
   }
  /// std::cout<<"generic number of digits "<<multiple/y[i]<<std::endl;
    m[i]=multiple/y[i];
}

for(int i=0;i<n;i++){
 deal[i]=deal[i]*m[i];
}
//sort
for(int i=0;i<n-1;++i){
  for(int i=0;i<n-1;++i){
   // sort the digits in the new form in descending order
    if(deal[i+1]>deal[i]){  
      temp=deal[i];
      temp1=m[i];
      deal[i]=deal[i+1];
      m[i]=m[i+1];
      deal[i+1]=temp;
      m[i+1]=temp1;

    }
  }
}
int tempfinal;

for(int i=0;i<n;++i)
//convert to orginal form
for(int j=0;j<n-1;++j){
for(int t=0;t<n-1;++t){
  if(m[t+1]==multiple && deal[t]/multiple==deal[t+1]/m[t+1]){ 
      int y1=deal[t]%multiple;
       int  y2=deal[t+1]/multiple;
      if(deal[t]%multiple<deal[t+1]/multiple){
         tempfinal=deal[t];
         int tempfinalm=m[t];
         deal[t]=deal[t+1];
         m[t]=m[t+1];
         deal[t+1]=tempfinal;
         m[t+1]=tempfinalm;  
     
      }
  }   
}
}
for(int t=0;t<n;++t){   
 
    deal[t]=deal[t]/m[t];
} 

  std::stringstream ret;
  for (int i = 0; i<n; i++) {
    ret << deal[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
