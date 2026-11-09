#include<stdio.h>
#include<stdlib.h>
void nhap(float *a,int n){
	for(int i=0;i<n;i++) scanf("%f",&a[i]);
}
void in(float *a,int n){
	for(int i=0;i<n;i++) printf("%.2f ",a[i]);
}
int main(){
	float* a;
	int n;
	scanf("%d",&n);
	a=(float*)malloc(n*sizeof(float));
	nhap(a,n);
	in(a,n);
	free(a);
}
