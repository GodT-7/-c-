#include <iostream> 

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}Node;

typedef struct{
	Node *root;
}Tree;

class BTree{
	public:
		Tree *tree;
		int num;//数量 
	
		BTree();
		void preorder(Node *);
		void pre();//前序 
		void insert(int val);//插入 
		int  get_height();//求树的深度，递归求法 
		int  geth(Node *node);
		int  getm(Node *node);
		int  get_max();//求树的最大值，递归求法 
		void freeTree();//释放空间
		void free(Node *);//释放 
};

int main(){
	BTree t;
	
	t.pre();
	int height=t.get_height();
	std::cout<<"深度="<<height<<"\n";
	int max=t.get_max();
	std::cout<<"最大值="<<max<<"\n";
	
	return 0;
}

BTree::BTree(){
	std::cout<<"请输入数的数量:";
	std::cin>>num;
	int arr[num];
	std::cout<<"请输入结点大小:\n";
	for(int i=0;i<num;i++)
		std::cin>>arr[i];
	tree=new Tree();
	tree->root=NULL;
	for(int i=0;i<num;i++){
		insert(arr[i]);
	}
	return;
}

void BTree::preorder(Node * root){
	if(root != NULL){
		std::cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right); 
	}
}

void BTree::pre(){
	preorder(this->tree->root);
	std::cout<<"\n";
	return;
}

void BTree::insert(int val){
	Node *node=new Node();
	node->data=val;
	node->left=node->right=NULL;
	
	if(this->tree->root==NULL)
		this->tree->root=node;
	else{
		Node *temp=this->tree->root;
		while(temp!=NULL){
			if(val<temp->data){
				if(temp->left==NULL){
					temp->left=node;
					return;
				}else{
					temp=temp->left;
				}	
			}else{
				if(temp->right==NULL){
					temp->right=node;
					return;
				}else{
					temp=temp->right;
				}
			}
		}
	}
}

int BTree::get_height(){
	return geth(this->tree->root);
}

int BTree::geth(Node *node){//用递归分而治之，求左边的深度再求右边的深度不断递归 
	if(node==NULL) //递归出口 
		return 0;
	else{
		int left_h=geth(node->left);
		int right_h=geth(node->right);
		int max=left_h;
		if(right_h>max)
			max=right_h;
		return max+1;
	}
}

int BTree::get_max(){
	return getm(this->tree->root);
	std::cout<<"\n";
}

int BTree::getm(Node *node){
	if(NULL==node){///递归出口 
		return -1;
	}else{
		int m1=getm(node->left);
		int m2=getm(node->right);
		int m3=node->data;
		int max=m1;
		if(m2>max)
			max=m2;
		if(m3>max)
			max=m3;
		return max;
	}
}

void BTree::freeTree(){
	free(this->tree->root);
}

void BTree::free(Node *pT){
	if(NULL!=pT){
		Node* lchild=pT->left;
		Node* rchild=pT->right;
		delete(pT);
		pT=NULL;
		delete(lchild);
		lchild=NULL;
		delete(rchild);
		lchild=NULL;
	}else
		return;
} 
