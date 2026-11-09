#include<stdio.h>
#include<stdlib.h>
void nhap(float** a,int h,int c){
	for(int i=0;i<h;i++) for(int j=0; j<c;j++) scanf("%f",&a[i][j]);
}
void in(float** a,int h,int c){
	for(int i=0;i<h;i++){
		for(int j=0;j<c;j++) printf("%.2f ",a[i][j]);
		printf("\n");
	}
}
int main(){
	float** a;
	int h,c;
	scanf("%d%d",&h,&c);
	a=(float**)malloc(h*sizeof(float*));
	for(int i=0;i<h;i++){
		a[i]=(float*)malloc(c*sizeof(float));
	}
	nhap(a,h,c);
	in(a,h,c);
	for(int i=0;i<h;i++){
		free(a[i]);
	}
	free(a);
}
