#include <iostream>
#include <stdlib.h>

//结点定义 
typedef struct Node{
	int data;//数据域 
	struct Node* pNext;//指针域 
} NODE,*PNODE;

//类定义
class  LinkList{
public:
	Node *pHead;

	LinkList();//创建 ,构造函数，只要创立变量就有 
	//~LinkList();//删除,析构函数，只要运行结束就有 
	void traverse_list();//遍历 
	bool is_empty();//判断是否为空 
	int length_list();//返回链表长度
	bool insert_list(int ,int);//插入//并且pos从1开始 
	bool delete_list(int,int *); 
	void sort_list();//排序 
};




int main(){
	LinkList pHead;
	int val;
	 
	pHead.traverse_list();
	
	/*if(is_empty(pHead)){
		printf("链表为空!\n");
	}else{
		printf("链表不空\n");
	}*/
	//printf("链表长度为:%d",length_list(pHead));
	
	//sort_list(pHead);
	
	pHead.insert_list(1,33);
	if(pHead.delete_list(2,&val)){
		std::cout<<"删除成功,您删除的元素是:"<<val<<"\n";
	} else{
		std::cout<<"删除失败\n";
	}
	
	
	pHead.traverse_list();
	
	return 0;
}

LinkList::LinkList(){
	int len;
	int val;//用来临时存放用户输入的结点的值 
	
	//分配了一个不存放有效数据的头结点 
	pHead=new NODE();
	if(NULL==pHead){
		printf("内存分配失败，程序中止!");
		exit(-1);
	}
	
	//pTail为尾节点 
	PNODE pTail=pHead;
	pTail->pNext=NULL;
	
	printf("请输入您需要生成的链表节点的个数:len=");
	scanf("%d",&len);
	
	for(int i=0;i<len;i++){
		std::cout<<"请输入第"<<i+1<<"个节点的值:";
		//scanf("%d",&val);
		std::cin>>val;
		
		PNODE pNew=new NODE();
		if(NULL==pNew){
		printf("内存分配失败，程序中止!");
		std::cout<<"内存分配失败，程序中止!";
		exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
}

void LinkList::traverse_list(){
	PNODE p=this->pHead->pNext;
	while(p!=NULL){
		std::cout<<p->data<<" ";
		p=p->pNext;
	}
	std::cout<<"\n";
	return;//仅为了考诉别人该函数已结束 
}

bool LinkList::is_empty(){
	if(this->pHead->pNext==NULL){
		return true;
	}else{
		return false;
	}
}

int LinkList::length_list(){
	PNODE p=this->pHead->pNext;
	int len=0;
	while(p!=NULL){
		len++;
		p=p->pNext;
	}
	return len;
}

//在pHead所指向链表的第pos个节点前面插入一个新的节点//并且pos从1开始 
bool LinkList::insert_list(int pos,int val){
	int i=0;
	PNODE p=this->pHead;
	while(NULL!=p&&i<pos-1){//找到第pos-1位的结点 
		p=p->pNext;
		i++;
	}
	if(i>pos-1||NULL==p)
		return false;
		
	PNODE pNew=new NODE();
	if(NULL==pNew){
		std::cout<<"动态内存分配失败!\n";
		exit(-1);
	}
	pNew->data=val;
	PNODE q=p->pNext;
	p->pNext=pNew;
	pNew->pNext=q;
	
	return true;
}

bool LinkList::delete_list(int pos,int *pVal){
	int i=0;
	PNODE p=this->pHead;
	while(NULL!=p->pNext&&i<pos-1){//找到pos-1这个结点，因为不能删除头结点，所以NULL=p->pNext 
		p=p->pNext;
		i++;
	}
	if(i>pos-1||NULL==p->pNext)//如果传入的参数是正确的,i=pos-1,p=第pos-1位的结点 
		return false;		
	
	PNODE q=p->pNext;
	*pVal=q->data;
	
	//删除p节点后面的结点
	p->pNext=p->pNext->pNext;
	delete q;
	q=NULL;
	 
	return true;
}

void LinkList::sort_list(){
	int i,j,t;
	PNODE p,q;
	for(i=0,p=this->pHead->pNext;i<length_list()-1;i++,p=p->pNext){
		for(j=i+1,q=p->pNext;j<length_list();j++,q=q->pNext){
			if(p->data>q->data){
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
		}
	}
	return;
}

