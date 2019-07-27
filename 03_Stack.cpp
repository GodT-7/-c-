#include <iostream>
#include <stdlib.h> 

typedef struct node{
	int data;
	struct node *pNext;
}NODE,*PNODE;

class stack{
public:
	PNODE pTop;
	PNODE pButton;
	
	stack();//��ʼ�� 
	~stack();//��� 
	//void init(PSTACK);//��ʼ�� 
	void push(int);//ѹջ 
	void traverse();//���� 
	bool pop(int *val);//��ջ 
	bool empty();//�ж��Ƿ�Ϊ�� 
	//void clear(PSTACK pS);//��� 	
};

int main(){
	stack S;
	int val;
	
	S.push(1);//ѹջ 
	S.push(2);
	S.push(3);
	S.push(4);
	S.traverse();//��� 
	
	if(S.pop(&val)){//��ջ 
		std::cout<<"��ջ�ɹ�����ջ��Ԫ����:"<<val<<"\n";
	}
	S.traverse();

	//clear(&S);//���
	S.~stack();

	S.traverse();
	//printf("hello");
	return 0;
}

stack::stack(){
	pTop=new NODE();
	if(NULL==pTop){
		std::cout<<"��̬�ڴ����ռ�ʧ��!\n";
		exit(-1);
	}else{
		pTop->pNext=NULL;
		pButton=pTop;
	}
	return;
}

void stack::push(int val){
	PNODE pNew = new NODE();
	
	pNew->data=val;
	pNew->pNext=pTop;
	pTop=pNew;
	
	return;
}

void stack::traverse(){
	PNODE p=pTop;
	while(p!=pButton){
		std::cout<<p->data<<" ";
		p=p->pNext; 
	}
	std::cout<<"\n";
	return;
} 

bool stack::empty(){
	if(pTop==pButton){
		return true;
	}else{
		return false;
	}
}


bool stack::pop(int *val){//��ջһ�Σ����س�ջ�����ݣ���վʧ�ܷ���false 
	if(this->empty()){
		std::cout<<"��ջʧ��!\n";
		return false;
	}else{
		PNODE p=pTop;
		*val=p->data;
		pTop=pTop->pNext;
		//free(p);
		delete p;
		p=NULL;
		
		return true;
	}
}

stack::~stack(){
	if(this->empty()){
		return;
	}else{
		PNODE q=NULL;
		
		while(pTop!=pButton){
			q=pTop->pNext;
			delete pTop;
			pTop=q;	
		}
		return;
	}
}
