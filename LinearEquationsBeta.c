#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void swap(double *a,double *b);
void fraction(double a,int *x,int *y);

int main(){

   int n=10;
   int i,j,k;
   double l;
   double z;
   int r,t;
   int o=0;int p;
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

            if(var[i][i]==0){
                if(p==(n-i)){
                printf("Infinite or Undefined Solution \n");
                goto A;
                }
                for(o=0;o<=n;o++){

                    swap(&var[i][o],&var[i+p][o]);

                }
                p++; continue;
            }
          l=var[i+k][i]/var[i][i];
            j=i;
        while(j<(n+1)){

                var[i+k][j] = var[i+k][j]-(var[i][j]*l);
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
for(i=0;i<n;i++){

    fraction(x[i],&ans[i][0],&ans[i][1]);
   //printf(" %d %d ",ans[i][0],ans[i][1]);
    r=(int)(((double)ans[i][0]/ans[i][1])*1000000);
    t=(int)(x[i]*1000000);
    printf("\n x%d = ",i+1);
    if(((t-r)<=1) && ((r-t)<=1)){
    if(ans[i][1]==1)
    printf("%d = ",ans[i][0]);
else
     printf("%d/%d = ",ans[i][0],ans[i][1]);
    }
    printf(" %lf ",x[i]);
}

    getch();
    return 0;
}
void fraction(double a,int *x,int *y){
    int m=1,n=1;
    int k,z,p;
   p=z=(int)(a*1000000);
   if(z<0) { z=z*(-1);}
   if(z!=0){
    for(m=1;m<=100000;m++){
        for(n=1;n<=100000;n++){
            k=(int)(1000000*(double)m/n);
			if((k+1)<z) break;
            if(((k-z)<=1) && ((z-k)<=1) ){
                if (z==p){
                *x=m;
                *y=n;}
                else {
                    *x=m*(-1);
                    *y=n;
                }
                break;
            }

        }
         if(((k-z)<=1) && ((z-k)<=1)) break;
   }
   if(m==1001 && n==1001){
        *x=1;*y=1;
   }
   }


   if(z==0){

    *x=0;
    *y=1;
   }


}
void swap(double *a,double *b){
    double c,d;
    c=*b;
    d=*a;
    *a=c;*b=d;

}
