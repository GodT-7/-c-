#include <iostream> 

typedef struct BTNode{
	char data;
	struct BTNode *pLchild;//p��ָ��,l����child�Ǻ���
	struct BTNode *pRchild; 
}BTNode ,*PBTNode;

class Btnode{
public:
	PBTNode pT;
	
	Btnode();//���캯����������̬������ 
	void PreTraverseBTree();//������� 
	void PreOrder(PBTNode);//���� 
	void InTraverseBTree();//������� 
	void InOrder(PBTNode);//����
	void PostTraverseBTree(); //�������
	void PostOrder(PBTNode);//����
	//~Btnode();//��������,�ͷſռ� 
	void freeTree();//�ͷſռ�
	void free(PBTNode);//�ͷ� 
};

int main(void){
	Btnode p;
	
	p.PreTraverseBTree();
	std::cout<<"\n";
	p.InTraverseBTree();
	std::cout<<"\n";
	p.PostTraverseBTree();
	std::cout<<"\n";
	
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
	//�ȷ��ʸ�
	//���������������
	//���������������
	if(pT!=NULL){
		std::cout<<pT->data<<" ";
		//pT->pLchild���Դ�������������
		if(NULL!=pT->pLchild)
			PreOrder(pT->pLchild);
		if(NULL!=pT->pRchild)
			PreOrder(pT->pRchild);
	}else
		return;
}

void Btnode::InOrder(PBTNode pT){
	//��������������� 
	//�ٷ��ʸ�
	//���������������� 
	if(pT!=NULL){
		//pT->pLchild���Դ�������������
		if(NULL!=pT->pLchild)
			InOrder(pT->pLchild);
		std::cout<<pT->data<<" ";
		if(NULL!=pT->pRchild)
			InOrder(pT->pRchild);
	}else
		return;
}

void Btnode::PostOrder(PBTNode pT){
	//�Ⱥ������������ 
	//�ٺ������������
	//�����ʸ�
	if(pT!=NULL){
		//pT->pLchild���Դ�������������
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
