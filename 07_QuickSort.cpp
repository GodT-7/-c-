#include <iostream>

class QuickArray{
public:
	int *a;//Ҫ��������� 
	int num;//�����С
	
	QuickArray();//���캯������ʼ�� 
	void QuickSort(int low ,int high);//���� 
	int FindPos(int low,int high);//�ҵ���һ�����ֵ��±� 
};


int main(){
	QuickArray array;
	
	array.QuickSort(0,array.num-1);//�ڶ���������ʾ��һ��Ԫ�ص��±꣬������������ʾ���һ��Ԫ�ص��±�
	 
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
	}//��ֹwhileѭ����low��highһ������ȵ� 
	
	a[low]=val;
	
	return low;//low=high
}

QuickArray::QuickArray(){
	std::cout<<"�����������������������:\n";
	std::cin>>num;
	a=new int(num);
	std::cout<<"������Ҫ���������:\n";
	for(int i=0;i<num;i++)
		std::cin>>*(a+i);
	return;
}
