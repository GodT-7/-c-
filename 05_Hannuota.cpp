#include <iostream>
class Hannuota{
public:
	char A;
	char B;
	char C;
	int n;
	
	Hannuota();
	void hannuotasuanfa(int n,char ,char,char);
};



int main(){
	
	Hannuota ta;
	
	ta.hannuotasuanfa(ta.n,ta.A,ta.B,ta.C);
	
	return 0;
} 

void Hannuota::hannuotasuanfa(int n,char A,char B,char C){
	/*α�㷨 
	�����һ������
		ֱ�ӽ�A�����ϵ��Ƶ�C//��ʱ��A,C������A,C���ӣ��������������������������,����ͬ�� 
	����
		�Ƚ�A�����ϵ�n-1�����н���C�ƶ���B
		ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C
		���B�����ϵ�n-1�����ӽ���A�Ƶ�C 
	*/
	if(n==1)
		std::cout<<"�����Ϊ"<<n<<"������ֱ�Ӵ�"<<A<<"�����Ƶ�"<<C<<"����\n";
	else{
		hannuotasuanfa(n-1,A,C,B);
		std::cout<<"�����Ϊ"<<n<<"������ֱ�Ӵ�"<<A<<"�����Ƶ�"<<C<<"����\n";
		hannuotasuanfa(n-1,B,A,C);
	}
	return;	
}
Hannuota::Hannuota(){
	A='A';
	B='B';
	C='C';
	
	std::cout<<"������Ҫ�ƶ������еĸ���:";
	std::cin>>n; 
}
