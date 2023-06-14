#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout<<"\n Enter the decimal number : ";
    cin>>n;

    int i = 0, ans = 0;
    if( n > 0){
    while(n != 0){
      int bit = n & 1;
      ans = bit * pow(10 , i) + ans;
      n = n>>1;
      i++;  
    }
    cout<< "\n The Answer is : "<<ans;

    }
    else if (n < 0)
    {
        n = n*(-1);
        while(n != 0){

      int bit = n & 1;
      ans = bit * pow(10 , i) + ans;
      n = n>>1;
      i++;
    }
    ans = ~(ans);
    cout<< "\n The Answer is : "<<ans;
    
    }
}