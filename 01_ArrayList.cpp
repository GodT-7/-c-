#include <iostream>
#include <stdlib.h>//������exit 

//Arr������ 
class Arr{
public:
	int  *pBase;//�洢�������һ��Ԫ�صĵ�ַ
	int len;//������������ɵ����Ԫ�صĸ���
	int cnt;//��ǰ������ЧԪ�صĸ���
	//int increment;//�Զ��������� 
	
	void init_arr(int length);//��ʼ��  
	bool append_arr(int val);//׷�� 
	bool insert_arr(int pos,int val);//���� ,pos��1��ʼ 
	bool delete_arr(int pos,int *pVal);//ɾ�� 
	int get();//��ȡ�±� 
	bool is_empty();
	bool is_full();
	void sort_arr();
	void show_arr();
	void inversion_arr();
};



int main(){
	Arr arr;
	int val;
	//��ʼ�� 
	arr.init_arr(6); 
	//׷��
	arr.append_arr(1);
	arr.append_arr(2); 
	arr.append_arr(3); 
	arr.append_arr(4); 
	arr.append_arr(5);
	
	//����
	arr.insert_arr(1,99); 
	
	//ɾ��
	if(arr.delete_arr(1,&val)){
		std::cout<<"��ɾ����Ԫ�سɹ� �ǣ�"<<val;
	}
	  
	//���
	arr.show_arr();
	
	//����
	arr.inversion_arr();
	
	//���
	arr.show_arr();
	
	//����
	arr.sort_arr();
	 
	 //���
	arr.show_arr();
	
	return 0;
} 

void Arr::init_arr(int length){
	this->pBase=new int(sizeof(int)*length);
	if(NULL==this->pBase){
		std::cout<<"��̬�ڴ����ʧ��!\n";
		exit(-1);//��ʾ��ֹ�������� 
	}else{
		this->len=length;
		this->cnt=0;
	}
	return;
}

void Arr::show_arr(){
	if(this->is_empty()){
		std::cout<<"����Ϊ��\n";
	}
	else{
		for(int i=0;i<this->cnt;i++){
			std::cout<<this->pBase[i];
		std::cout<<"\n";
		}
	}
} 

bool Arr::is_empty(){
	if(this->cnt==0){
		return true;
	}else{
		return false;
	}
}

bool Arr::append_arr(int val){
	if(this->is_full()){//����ʱ�򷵻�false 
		return false;
	}else{//������ʱ����� 
		this->pBase[this->cnt]=val;
		(this->cnt)++;
		return true;
	}
}

bool Arr::is_full(){
	if(this->cnt==this->len){
		return true;
	}else{
		return false;
	}
}

bool Arr::insert_arr(int pos,int val){
	if(this->is_full())
		return false;
	if(pos<1||pos>this->cnt+1)
		return false; 
	
	for(int i=this->cnt-1;i>=pos-1;i--){
		this->pBase[i+1]=this->pBase[i];
	}
	this->pBase[pos-1]=val;
	this->cnt++;
	return true;
}

bool Arr::delete_arr(int pos,int *pVal){
	if(this->is_empty())
		return false;
	if(pos<1||pos>this->cnt+1)
		return false;
		
	*pVal=this->pBase[pos-1];
	for(int i=pos;i<this->cnt;i++){
		this->pBase[i-1]=this->pBase[i];
	}
	this->cnt--;
	return true;
}

void Arr::inversion_arr(){
	int sum=this->cnt;
	for(int i=0;i<=this->cnt/2;i++){
		int temp=this->pBase[i];
		this->pBase[i]=this->pBase[sum-1];
		this->pBase[sum-1]=temp;
		sum--;	
	} 
	return;
}

void Arr::sort_arr(){
	int i,j;
	for(i=0;i<this->cnt;i++){
		for(j=i+1;j<this->cnt;j++){
			if(this->pBase[i]>this->pBase[j]){
				int temp=this->pBase[i];
				this->pBase[i]=this->pBase[j];
				this->pBase[j]=temp;
			}
		}
	} 
}
