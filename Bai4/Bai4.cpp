#include<stdio.h>
#include<stdlib.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode{
    	Data infor;
    	struct tagNode *link;
}Node;
typedef struct{
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;
void initList(LList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
bool emptyList(LList L){
    return (L.spt == 0); 
}
void insert_Head(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
void insert_Tail(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    		L->pHead = pp;
    		L->pTail = pp;
		}
		else{
			L->pTail->link = pp;
			L->pTail = pp;
		}
		L->spt++;
    }
void insert(LList *L, int ma, Data x)
	{
		Node *p = L->pHead;
		while(p != NULL && p->infor.masv != ma){
			p = p->link;
		}
		if(p==NULL){
			printf("Khong tim thay sv!\n");
		}
		else{
			Node *pp;
			pp = (Node*)malloc(sizeof(Node));
		if(pp == NULL) return;
		pp->infor = x;
		pp->link = p->link;
		p->link = pp;
		if(p == L->pTail){
			L->pTail = pp;
		}
		L->spt++;
	}
}	    
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ten sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void inList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); 
        	pp = pp->link;
    	}
}
int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L); 
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap so thong tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap thong tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0)
	                insert_Tail(&L, x);
            	break;
            case 3:
            	int ma;
	            printf("Nhap them thong tin sv can them\n");
	            scanf("%d",&ma);
	            printf("Nhap thong tin sv moi them");
	            nhap(&x);
	            if(x.masv > 0)
	                insert(&L, ma, x);
            	break;
            case 9: 
                inList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}
