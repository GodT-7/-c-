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
	
	stack();//初始化 
	~stack();//清空 
	//void init(PSTACK);//初始化 
	void push(int);//压栈 
	void traverse();//遍历 
	bool pop(int *val);//出栈 
	bool empty();//判断是否为空 
	//void clear(PSTACK pS);//清空 	
};

int main(){
	stack S;
	int val;
	
	S.push(1);//压栈 
	S.push(2);
	S.push(3);
	S.push(4);
	S.traverse();//输出 
	
	if(S.pop(&val)){//出栈 
		std::cout<<"出栈成功，出栈的元素是:"<<val<<"\n";
	}
	S.traverse();

	//clear(&S);//清空
	S.~stack();

	S.traverse();
	//printf("hello");
	return 0;
}

stack::stack(){
	pTop=new NODE();
	if(NULL==pTop){
		std::cout<<"动态内存分配空间失败!\n";
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


bool stack::pop(int *val){//出栈一次，返回出栈的数据，出站失败返回false 
	if(this->empty()){
		std::cout<<"出栈失败!\n";
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
