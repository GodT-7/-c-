#include <iostream>

class QuickArray{
public:
	int *a;//要排序的数组 
	int num;//数组大小
	
	QuickArray();//构造函数，初始化 
	void QuickSort(int low ,int high);//快排 
	int FindPos(int low,int high);//找到第一个数字的下标 
};


int main(){
	QuickArray array;
	
	array.QuickSort(0,array.num-1);//第二个参数表示第一个元素的下标，第三个参数表示最后一个元素的下标
	 
	for(int i=0;i<array.num;i++)
		std::cout<<array.a[i]<<" ";
	std::cout<<"\n";
	
	return 0;
} 

void QuickArray::QuickSort(int low ,int high){
	int pos;
	
	if(low<high){
		pos=FindPos(low,high);
		QuickSort(low,pos-1);
		QuickSort(pos+1,high);
	}
	else
		return;
}

int QuickArray::FindPos(int low,int high){
	int val=a[low];
	
	while(low<high){
		while(low<high && a[high]>=val)
			--high;
		a[low]=a[high];
		
		while(low<high && a[low]<=val)
			++low; 
		a[high]=a[low];
	}//中止while循环后low和high一定是相等的 
	
	a[low]=val;
	
	return low;//low=high
}

QuickArray::QuickArray(){
	std::cout<<"请输入你想排序的数字数量:\n";
	std::cin>>num;
	a=new int(num);
	std::cout<<"请输入要排序的数字:\n";
	for(int i=0;i<num;i++)
		std::cin>>*(a+i);
	return;
}
