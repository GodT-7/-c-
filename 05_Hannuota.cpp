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
	/*伪算法 
	如果是一个盘子
		直接将A柱子上的移到C//此时的A,C并不是A,C柱子，而是这两个参数所代表的柱子,下面同理 
	否则
		先将A柱子上的n-1个盘中借助C移动到B
		直接将A柱子上的盘子从A移到C
		最后将B柱子上的n-1个盘子借助A移到C 
	*/
	if(n==1)
		std::cout<<"将编号为"<<n<<"的盘子直接从"<<A<<"柱子移到"<<C<<"柱子\n";
	else{
		hannuotasuanfa(n-1,A,C,B);
		std::cout<<"将编号为"<<n<<"的盘子直接从"<<A<<"柱子移到"<<C<<"柱子\n";
		hannuotasuanfa(n-1,B,A,C);
	}
	return;	
}
Hannuota::Hannuota(){
	A='A';
	B='B';
	C='C';
	
	std::cout<<"请输入要移动的盘中的个数:";
	std::cin>>n; 
}
