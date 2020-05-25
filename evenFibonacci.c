#include<stdio.h>




int fibon(int n){
   if (n==1 || n ==2){
       return n;
   }
   return fibon(n-1)+fibon(n-2);
}

int main(){
   int sum = fibon(500);
    printf("Sum is %d\n", sum);
}