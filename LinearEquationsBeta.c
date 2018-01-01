#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Factors.h"
#include "properfraction.h"
void swap(double *a,double *b);


int main(){

   int n=10;
   int i,j,k;
   double l,m;
   double z;
   int r,t;
   int o=0;int p;
   double q=1;
   printf("This program solves linear equations of n variables\n How to use?\n-Eg, if you want to solve for 2 variables, say x+y=2 and x-y=0, Enter number of variables 2 then input coefficients in the format\n1 1 2\n1 -1 0\n");

  A:
      printf("\nEnter the number of variables:\n ");
      scanf(" %d",&n);
      printf("\nEnter the coefficients and constants:\n ");

      double var[n][n+1];
      int ans[n][2];
      double x[n];

   for(i=0;i<n;i++){

        for(j=0;j<=n;j++){

            scanf("%lf",&var[i][j]);

        }
   }

i=0; j=0;


while(i<(n-1)){
    k=1;p=1;
    while(k<(n-i)){

             l=LCM(var[i+k][i],var[i][i]);
          l=l/var[i][i];
          m=l*var[i][i]/var[i+k][i];
            j=i;
        while(j<(n+1)){

                var[i+k][j] = var[i+k][j]*m-(var[i][j]*l);
                j++;
              }
              k++;
    }
    i++;
}



for(i=0;i<n;i++){
    x[i]=0.0;
}
for(i=n-1;i>=0;i--){
    l=var[i][n];
    for(j=0;j<n;j++){
        l-= (var[i][j]*x[j]);
    }
    if(var[i][i]==0){
            printf("\nInfinite or Undefined Solution\n");
            goto A;}
    x[i]=l/var[i][i];

}
}


