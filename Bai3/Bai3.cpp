#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char ten[30];
	int msv;
	float d1,d2,d3;
}SV;
void nhap(SV* a,int n){
	for(int i=0;i<n;i++){
		scanf(" %[^\n]",a[i].ten);
		scanf("%d%f%f%f",&a[i].msv,&a[i].d1,&a[i].d2,&a[i].d3);
		getchar();
	}
}
void in(SV *a,int n){
	for(int i=0;i<n;i++){
		printf("%s %d %.2f %.2f %.2f\n",a[i].ten,a[i].msv,a[i].d1,a[i].d2,a[i].d3);				
	}
}
int main(){
	SV *a;
	int n;
	scanf("%d",&n);
	a=(SV*)malloc(n*sizeof(SV));
	nhap(a,n);
	in(a,n);
	free(a);
}
