#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

typedef struct node{
	int data;
	struct node *pNext;
}NODE,*PNODE;

typedef struct Stack{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

void init(PSTACK);//��ʼ�� 
void push(PSTACK,int);//ѹջ 
void traverse(PSTACK);//���� 
bool pop(PSTACK pS,int *val);//��ջ 
bool empty(PSTACK pS);//�ж��Ƿ�Ϊ�� 
void clear(PSTACK pS);//��� 

int main(){
	STACK S;
	int val;
	
	init(&S);//���һ����ջ 
	push(&S,1);//ѹջ 
	push(&S,2);
	push(&S,3);
	push(&S,4);
	traverse(&S);//��� 
	
	if(pop(&S,&val)){//��ջ 
		printf("��ջ�ɹ�����ջ��Ԫ����:%d\n",val);
	}
	traverse(&S);

	clear(&S);//���

	traverse(&S);
	//printf("hello");
	return 0;
}

void init(PSTACK pS){
	pS->pTop=(NODE*)malloc(sizeof(NODE));
	if(NULL==pS->pTop){
		printf("��̬�ڴ����ռ�ʧ��!\n");
		exit(-1);
	}else{
		pS->pTop->pNext=NULL;
		pS->pBottom=pS->pTop;
	}
}

void push(PSTACK pS,int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	
	pNew->data=val;
	pNew->pNext=pS->pTop;
	pS->pTop=pNew;
	
	return;
}

void traverse(PSTACK pS){
	PNODE p=pS->pTop;
	while(p!=pS->pBottom){
		printf("%d ",p->data);
		p=p->pNext; 
	}
	
	return;
} 

bool empty(PSTACK pS){
	if(pS->pTop==pS->pBottom){
		return true;
	}else{
		return false;
	}
}


bool pop(PSTACK pS,int *val){//��ջһ�Σ����س�ջ�����ݣ���վʧ�ܷ���false 
	if(empty(pS)){
		printf("��ջʧ��!\n");
		return false;
	}else{
		PNODE p=pS->pTop;
		*val=p->data;
		pS->pTop=pS->pTop->pNext;
		free(p);
		p=NULL;
		
		return true;
	}
}

void clear(PSTACK pS){
	if(empty(pS)){
		return;
	}else{
		PNODE q=NULL;
		
		while(pS->pTop!=pS->pBottom){
			q=pS->pTop->pNext;
			free(pS->pTop);
			pS->pTop=q;	
		}
		return;
	}
}
