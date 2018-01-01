#include <stdio.h>

float HCF(float a,float b){
	float c;
	while(a!=0){
		c=(int)b%((int)a);
		b=a;
		a=(float)c;
	}
	return b;
}

float LCM(float a,float b){
	float d=a,e=b;
	int c;
	while(a!=0){
		c=(int)b%((int)a);
		b=a;
		a=(float)c;
	}
	return d*e/b;
}
