#include <iostream> 

typedef struct BTNode{
	char data;
	struct BTNode *pLchild;//p是指针,l是左，child是孩子
	struct BTNode *pRchild; 
}BTNode ,*PBTNode;

class Btnode{
public:
	PBTNode pT;
	
	Btnode();//构造函数，创建静态二叉树 
	void PreTraverseBTree();//先序输出 
	void PreOrder(PBTNode);//先序 
	void InTraverseBTree();//中序输出 
	void InOrder(PBTNode);//中序
	void PostTraverseBTree(); //后序输出
	void PostOrder(PBTNode);//后序
	//~Btnode();//析构函数,释放空间 
	void freeTree();//释放空间
	void free(PBTNode);//释放 
	int  get_height();//求树的深度，递归求法 
	int  geth(PBTNode node);
	int  getmax(PBTNode node);
	int  get_max();//求树的最大值，递归求法
	int  getmin(PBTNode node);
	int  get_min();//求树的最小值，递归求法 
};

int main(void){
	Btnode p;
	
	p.PreTraverseBTree();
	std::cout<<"\n";
	p.InTraverseBTree();
	std::cout<<"\n";
	p.PostTraverseBTree();
	std::cout<<"\n";
	int height=p.get_height();
	std::cout<<"深度="<<height<<"\n";
	int max=p.get_max();
	std::cout<<"最大值="<<max<<"\n";
	int min=p.get_min();
	std::cout<<"最小值="<<min<<"\n"; 
	
	return 0;
} 

void Btnode::PreTraverseBTree(){
	PreOrder(this->pT);
	return;
} 

void Btnode::InTraverseBTree(){
	InOrder(this->pT);
	return;
}

void Btnode::PostTraverseBTree(){
	PostOrder(this->pT);
	return;
}

Btnode::Btnode(){
	PBTNode pA=new BTNode();
	PBTNode pB=new BTNode();
	PBTNode pC=new BTNode();
	PBTNode pD=new BTNode();
	PBTNode pE=new BTNode();
	
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';
	
	pA->pLchild=pB;
	pA->pRchild=pC;
	pB->pLchild=pB->pRchild=NULL;
	pC->pLchild=pD;
	pC->pRchild=NULL;
	pD->pLchild=NULL;
	pD->pRchild=pE;
	pE->pLchild=pE->pRchild=NULL;
	
	this->pT=pA;
	return;
}
/*
Btnode::~Btnode(){
	this->freeTree();
}
*/
void Btnode::freeTree(){
	free(pT);
}

void Btnode::PreOrder(PBTNode pT){
	//先访问根
	//在先序访问左子树
	//再先序访问右子树
	if(pT!=NULL){
		std::cout<<pT->data<<" ";
		//pT->pLchild可以代表整个左子树
		if(NULL!=pT->pLchild)
			PreOrder(pT->pLchild);
		if(NULL!=pT->pRchild)
			PreOrder(pT->pRchild);
	}else
		return;
}

void Btnode::InOrder(PBTNode pT){
	//先中序访问左子树 
	//再访问根
	//最后中序访问右子树 
	if(pT!=NULL){
		//pT->pLchild可以代表整个左子树
		if(NULL!=pT->pLchild)
			InOrder(pT->pLchild);
		std::cout<<pT->data<<" ";
		if(NULL!=pT->pRchild)
			InOrder(pT->pRchild);
	}else
		return;
}

void Btnode::PostOrder(PBTNode pT){
	//先后序访问左子树 
	//再后序访问右子树
	//最后访问根
	if(pT!=NULL){
		//pT->pLchild可以代表整个左子树
		if(NULL!=pT->pLchild)
			PostOrder(pT->pLchild);
		if(NULL!=pT->pRchild)
			PostOrder(pT->pRchild);
		std::cout<<pT->data<<" ";
	}else
		return;
}

void Btnode::free(PBTNode pT){
	if(NULL!=pT){
		PBTNode lchild=pT->pLchild;
		PBTNode rchild=pT->pRchild;
		delete(pT);
		pT=NULL;
		free(lchild);
		free(rchild);
	}else
		return;
}

int Btnode::get_height(){
	return geth(this->pT);
}

int Btnode::geth(PBTNode node){//用递归分而治之，求左边的深度再求右边的深度不断递归 
	if(node==NULL) //递归出口 
		return 0;
	else{
		int left_h=geth(node->pLchild);
		int right_h=geth(node->pRchild);
		int max=left_h;
		if(right_h>max)
			max=right_h;
		return max+1;
	}
}

int Btnode::get_max(){
	return getmax(this->pT);
	std::cout<<"\n";
}

int Btnode::getmax(PBTNode node){
	if(NULL==node){///递归出口 
		return -1;
	}else{
		int m1=getmax(node->pLchild);
		int m2=getmax(node->pRchild);
		int m3=node->data;
		int max=m1;
		if(m2>max)
			max=m2;
		if(m3>max)
			max=m3;
		return max;
	}
}

int Btnode::get_min(){
	return getmin(this->pT);
	std::cout<<"\n";
}

int Btnode::getmin(PBTNode node){
	if(NULL==node){///递归出口 
		return 10000;
	}else{
		int m1=getmin(node->pLchild);
		int m2=getmin(node->pRchild);
		int m3=node->data;
		int min=m1;
		if(m2<min)
			min=m2;
		if(m3<min)
			min=m3;
		return min;
	}
}
