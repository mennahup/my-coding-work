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

//
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
  /// std::cout<<"generic mm"<<multiple/y[i]<<std::endl;
    m[i]=multiple/y[i];
}
 //show
// for(int t=0;t<n;++t)
//   std::cout<<"mm"<<m[t]<<std::endl;
for(int i=0;i<n;i++){
 deal[i]=deal[i]*m[i];
 ///std::cout<<deal[i]<<std::endl;
}
//sort
for(int i=0;i<n-1;++i){
  for(int i=0;i<n-1;++i){
   // std::cout<<"befor i"<<deal[i]<<std::endl;
   // std::cout<<"before i+1"<<deal[i+1]<<std::endl;
    if(deal[i+1]>deal[i]){  
      temp=deal[i];
      temp1=m[i];
      deal[i]=deal[i+1];
      m[i]=m[i+1];
      deal[i+1]=temp;
      m[i+1]=temp1;

    }
    //  std::cout<<"after i"<<deal[i]<<std::endl;
   // std::cout<<"after i+1"<<deal[i+1]<<std::endl;
  }
}
int tempfinal;
//show sorted
for(int i=0;i<n;++i)
 /// std::cout<<deal[i]<<std::endl;
//convert to orginal form
for(int j=0;j<n-1;++j){
for(int t=0;t<n-1;++t){
  //  std::cout<<"t"<<t<<std::endl;
  //  std::cout<<"large"<<deal[t]<<std::endl;
  //  std::cout<<"m of i"<<m[t]<<std::endl;
  //  std::cout<<"last step "<<deal[t]/m[t]<<std::endl;
  //  deal[t]=deal[t]/m[t]; 
  //try to fix bug 21 2
 //std::cout<<"m[t+1]"<<m[t+1]<<std::endl;
 // std::cout<<"deal[t}/multiple"<<deal[t]/multiple<<std::endl;
 // std::cout<<"deal[t+1]"<<deal[t+1]<<std::endl;
  if(m[t+1]==multiple && deal[t]/multiple==deal[t+1]/m[t+1]){ 
       ///  std::cout<<"check condition"<<std::endl;
      //   std::cout<<"deal[t+1]/mult "<<deal[t+1]/(multiple)<<std::endl;
      //   std::cout<<"deal[t]%multiple "<<deal[t]%multiple<<std::endl;
       //  std::cout<<"deal1[t+1]"<<deal[t+1]<<std::endl;
       //  std::cout<<"deal1[t]"<<deal[t]<<std::endl;
       // int x1=deal[t]%(multiple);
       // int x2=deal[t+1]/multiple;
       //std::cout<<"x1"<<x1<<std::endl;
       // std::cout<<"x2"<<x2<<std::endl;
        // std::cout<<"deal1[t+1]"<<deal[t+1]<<std::endl;
        // std::cout<<"deal1[t]"<<deal[t]<<std::endl;
        
   // while(x1<x2){
     //   std::cout<<"check condition 2"<<std::endl;
         // tempfinal=deal[t];
         // deal[t]=deal[t+1];
         // deal[t+1]=tempfinal;
       //  std::cout<<"deal2[t+1]"<<deal[t+1]<<std::endl;
        // std::cout<<"deal2[t]"<<deal[t]<<std::endl;
      //  } 
      int y1=deal[t]%multiple;
       int  y2=deal[t+1]/multiple;
       /// std::cout<<"y1 "<<y1<<std::endl;
       /// std::cout<<"y2 "<<y2<<std::endl;
      if(deal[t]%multiple<deal[t+1]/multiple){
        // std::cout<<"switch"<<std::endl;
        //  std::cout<<"deal2[t+1]"<<deal[t+1]<<std::endl;
        // std::cout<<"deal2[t]"<<deal[t]<<std::endl;
    //   for(int i=0;i<n;i++){
         tempfinal=deal[t];
         int tempfinalm=m[t];
       //  std::cout<<"tempfinal"<<tempfinal<<std::endl;
         deal[t]=deal[t+1];
         m[t]=m[t+1];
         deal[t+1]=tempfinal;
         m[t+1]=tempfinalm;
        /// std::cout<<"deal3[t+1]/m[t+1]"<<deal[t+1]/m[t+1]<<std::endl;
        /// std::cout<<"deal3[t]/m[t]"<<deal[t]/m[t]<<std::endl;
       // } 
      }
    //}
  }   
}
}
for(int t=0;t<n;++t){   
  //  std::cout<<"byd50l hena"<<std::endl;
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
