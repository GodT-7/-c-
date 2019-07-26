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

void init(PSTACK);//初始化 
void push(PSTACK,int);//压栈 
void traverse(PSTACK);//遍历 
bool pop(PSTACK pS,int *val);//出栈 
bool empty(PSTACK pS);//判断是否为空 
void clear(PSTACK pS);//清空 

int main(){
	STACK S;
	int val;
	
	init(&S);//造出一个空栈 
	push(&S,1);//压栈 
	push(&S,2);
	push(&S,3);
	push(&S,4);
	traverse(&S);//输出 
	
	if(pop(&S,&val)){//出栈 
		printf("出栈成功，出栈的元素是:%d\n",val);
	}
	traverse(&S);

	clear(&S);//清空

	traverse(&S);
	//printf("hello");
	return 0;
}

void init(PSTACK pS){
	pS->pTop=(NODE*)malloc(sizeof(NODE));
	if(NULL==pS->pTop){
		printf("动态内存分配空间失败!\n");
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


bool pop(PSTACK pS,int *val){//出栈一次，返回出栈的数据，出站失败返回false 
	if(empty(pS)){
		printf("出栈失败!\n");
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
