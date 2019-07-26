#include <iostream>
#include <stdlib.h>//包含了exit 

//Arr数组类 
class Arr{
public:
	int  *pBase;//存储的数组第一个元素的地址
	int len;//数组的所能容纳的最大元素的个数
	int cnt;//当前数组有效元素的个数
	//int increment;//自动增长因子 
	
	void init_arr(int length);//初始化  
	bool append_arr(int val);//追加 
	bool insert_arr(int pos,int val);//插入 ,pos从1开始 
	bool delete_arr(int pos,int *pVal);//删除 
	int get();//获取下标 
	bool is_empty();
	bool is_full();
	void sort_arr();
	void show_arr();
	void inversion_arr();
};



int main(){
	Arr arr;
	int val;
	//初始化 
	arr.init_arr(6); 
	//追加
	arr.append_arr(1);
	arr.append_arr(2); 
	arr.append_arr(3); 
	arr.append_arr(4); 
	arr.append_arr(5);
	
	//插入
	arr.insert_arr(1,99); 
	
	//删除
	if(arr.delete_arr(1,&val)){
		std::cout<<"你删除的元素成功 是："<<val;
	}
	  
	//输出
	arr.show_arr();
	
	//倒置
	arr.inversion_arr();
	
	//输出
	arr.show_arr();
	
	//排序
	arr.sort_arr();
	 
	 //输出
	arr.show_arr();
	
	return 0;
} 

void Arr::init_arr(int length){
	this->pBase=new int(sizeof(int)*length);
	if(NULL==this->pBase){
		std::cout<<"动态内存分配失败!\n";
		exit(-1);//表示终止整个操作 
	}else{
		this->len=length;
		this->cnt=0;
	}
	return;
}

void Arr::show_arr(){
	if(this->is_empty()){
		std::cout<<"数组为空\n";
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
	if(this->is_full()){//满的时候返回false 
		return false;
	}else{//不满的时候加入 
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
