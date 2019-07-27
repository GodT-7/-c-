#include <iostream> 

class Queue{
public:
	int *pBase;
	int front;
	int rear;

	//void init(QUEUE *);//��ʼ������ 
	Queue();
	bool en_queue(int val);
	void traverse_queue();
	bool full_queue();
	bool out_queue(int *);
	bool emput_queue();
};


int main(){
	Queue Q;
	int val;
	
	//init(&Q);
	Q.en_queue(1);
	Q.en_queue(2);
	Q.en_queue(3);
	Q.en_queue(4);
	Q.en_queue(5);
	Q.en_queue(6);
	Q.en_queue(7);
	
	Q.traverse_queue();
	if(Q.out_queue(&val)){
		std::cout<<"���ӵ�ֵΪ: "<<val<<" ";
	}
	std::cout<<"\n";
	Q.traverse_queue();
	
	return 0;
} 

Queue::Queue(){
	pBase=new int(6);
	front=rear=0;
	return;
} 

bool Queue::en_queue(int val){
	if(this->full_queue())//�ж��Ƿ��� 
		return false;
	else{
		pBase[rear]=val;
		rear=(rear+1)%6;
		
		return true;
	}
}

void Queue::traverse_queue(){
	int i=front;
	while(i!=rear){
		std::cout<<pBase[i];
		i=(i+1)%6;
	}
	return;
}

bool Queue::full_queue(){
	if((rear+1)%6==front)
		return true;
	else
		return false;
}

bool Queue::out_queue(int *pVal){
	if(this->emput_queue())
		return false;
	else{
		*pVal=pBase[front];
		front=(front+1)%6;
		
		return true;
	}
}

bool Queue::emput_queue(){
	if(front==rear)
		return true;
	else
		return false;
}
