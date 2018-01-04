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
   int A;
   printf("This program solves linear equations of n variables\n How to use?\n-Eg, if you want to solve for 2 variables, say x+y=2 and x-y=0, Enter number of variables 2 then input coefficients in the format\n1 1 2\n1 -1 0\n");

  B:
      printf("\nEnter the number of variables:\n ");
      scanf(" %d",&n);
      printf("\nEnter the coefficients and constants:\n ");

      double var[n+1][n][n];
      double in[n][n+1];
      double d[n+1];
      double x[n+1];

   for(i=0;i<n;i++){

        for(j=0;j<=n;j++){

            scanf("%lf",&in[i][j]);

        }
   }
   for(A=n;A>=0;A--){

        for(i=0;i<n;i++){
             k=0;
            for(j=0;j<=n;j++){
                if(j==A) continue;
                var[A][i][k]=in[i][j];

                k++;
            }
        }
   }




for(A=0;A<=n;A++){
        d[A]=1;x[A]=1;
        i=0; j=0;
while(i<(n-1)){
    k=1;p=1;
    while(k<(n-i)){
             if(var[A][i][i]==0){
                if(p==(n-i)){
                printf("Infinite or Undefined Solution \n");
                goto B;
                }
                for(o=0;o<n;o++){

                    swap(&var[A][i][o],&var[A][i+p][o]);

                }
                p++; continue;
            }
             l=LCM(var[A][i+k][i],var[A][i][i]);
          l=l/var[A][i][i];
          m=l*var[A][i][i]/var[A][i+k][i];
            x[A]=x[A]*l*m;
            j=i;

        while(j<n){
                var[A][i][j]*=l;
                var[A][i+k][j] = var[A][i+k][j]*m-(var[A][i][j]);
                j++;
              }
              k++;
    }
    i++;
}
    for(k=0;k<n;k++){

            d[A]=d[A]*var[A][k][k];

    }
}
    for(A=0;A<=n;A++){
       d[A]=d[A]/x[A];
       if(A<n){
       if(n%2==0){
            if(A%2==0) d[A]*=(-1);
       }
       else {
        if(A%2!=0) d[A]*=(-1);
       }
       }
    }


    for(i=0;i<n;i++){
           z=d[n];
          k=  HCF(d[i],z);
     d[i]/=k; z/=k;
        if(z>0)
        printf("\n x%d = %.0lf /%.0lf = %lf",i+1,d[i],z,d[i]/z);
        else  printf("\n x%d = %.0lf /%.0lf = %lf",i+1,(-1)*d[i],(-1)*z,d[i]/z);

    }


    getch();
    return 0;
}

void swap(double *a,double *b){
    double c,d;
    c=*b;
    d=*a;
    *a=c;*b=d;

}

