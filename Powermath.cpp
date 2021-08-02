#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

string ver = "v1.1.0";
int itime=0;
int pt=0;
int verf=rand();
int main();
void dis();
void init2() {
	dis();
		printf("请稍候\n");
		printf("        |");
		sleep(0.5);
		dis();
		printf("请稍候\n");
		printf("        / ");
		sleep(0.5);
		dis();
		printf("请稍候\n");
		printf("        —");
		sleep(0.5);
		dis();
		printf("请稍候\n");
		printf("        \\");
		sleep(0.5);
		dis();
		printf("请稍候\n");
		printf("        |");
		sleep(0.5);
		dis();
		printf("请稍候\n");
		printf("        / ");
		sleep(0.5);
		dis();
		printf("请稍候\n");
		printf("        —");
		sleep(0.5);
		dis();
		printf("请稍候\n");
		printf("        \\");
		sleep(0.5);
		dis();
}
void init1() {
	itime++;
	if(itime>1) return;
	for(int i=1; i<=1; i++) {
		printf("请稍候\n");
		printf("        |");
		sleep(0.5);
		system("cls");
		printf("请稍候\n");
		printf("        / ");
		sleep(0.5);
		system("cls");
		printf("请稍候\n");
		printf("        —");
		sleep(0.5);
		system("cls");
		printf("请稍候\n");
		printf("        \\");
		sleep(0.5);
		system("cls");
		printf("请稍候\n");
		printf("        |");
		sleep(0.5);
		system("cls");
		printf("请稍候\n");
		printf("        / ");
		sleep(0.5);
		system("cls");
		printf("请稍候\n");
		printf("        —");
		sleep(0.5);
		system("cls");
		printf("请稍候\n");
		printf("        \\");
		sleep(0.5);
		system("cls");
	}
	init2();
}
void dis() {
	system("cls");
	printf("__________________________________________________________________\n");
	printf("                         POWERMATH\n");
	printf("------------------------------------------------------------------\n");
}
void dedis() {
	system("cls");
	printf("__________________________________________________________________\n");
	printf("                    POWERMATH 调试模式\n");
	printf("------------------------------------------------------------------\n");
}
void eyyc( ) {
	dis();
	float a,b,c,d,e,f;
	cout<<"请输入二元一次方程组\n"<<"  ax+by+c=0\n"<<"  dx+ey+f=0\n";
	cout<<"a=";
	cin>>a;
	cout<<"b=";
	cin>>b;
	cout<<"c=";
	cin>>c;
	cout<<"d=";
	cin>>d;
	cout<<"e=";
	cin>>e;
	cout<<"f=";
	cin>>f;
	if(a*e==b*d) {
		cout<<"方程组无解。\n";
		system("pause");
	} else {
		cout<<"x="<<(b*f-e*c)/(a*e-b*d)<<endl;
		cout<<"y="<<(a*f-d*c)/(b*d-a*e)<<endl;
		system("pause");
	}
	main();
}
void yyec() {
	dis();
	float a,b,c,root1,root2;
	cout<<"请输入一元二次方程的系数（a,b,c a^2*x+bx+c=0）:"<<endl;
	cin>>a>>b>>c;
	if(a==0) {
		cout<<"不是一个一元二次方程"<<endl;
		system("pause");
		main();
	}
	float t =b*b-4*a*c;
	if(t<0) {
		cout<<"方程没有实根"<<endl;
		system("pause");
		main();
	}
	if(t==0) { //判断议程是否有等根
		root1=root2=-b/(2*a);
	} else {
		root1=(-b+sqrt(t))/(2*a);
		root2=(-b-sqrt(t))/(2*a);
	}
	cout<<"方程的根为:"<<root1<<"和"<<root2<<endl;
	system("pause");
	system("cls");
	main();
}

void yyyc() {

	main();
}
void js() {

	main();
}
void fjzys() {
	dis();
	int i,n;
	printf("请输入需要分解质因数的数：");
	scanf("%d",&n);
	printf("\n%d=",n);
	for(i=2; i<=n; i++) {
		while(n!=i) {
			if(n%i==0) {
				printf("%d*",i);
				n=n/i;
			} else break;
		}
	}
	printf("%d\n",n);
	system("pause");
	main();
}
void sum() {
	dis();
	cout << "请输入求和终点：";
	long long n,i,sum=0;
	cin >> n;
	for(i=1;i<=n;i++)
		sum+=i;
	cout <<"求和结果：" << sum << endl;
	system("pause");
	main();
}
void about() {
	dis(); 
	cout << "检查更新?(y/n)\n";
	char up;
	cin >> up;
	verf=rand();
	if(up=='y') {
		cout << "查找新版本。。。\n";
		sleep(0.2); 
		cout << "更新中。。。\n";
		sleep(0.1); 
		ver = "v1.1.1";
	}
	cout << "           Powermath (c) 2017-2021 lijunhao2023.\n                   All Rights Reserved.\n";
	system("pause");
	cout << "当前版本: v1.1." << verf << endl;
	system("pause");
	main();
}
void de() {
	dedis();
	cout << "1        ";
	cout << "99 退出"; 
	main();
}
void debug() {
	dis();
	int sup;
	printf("sudo: pasword for root :");
	if(pt==3) {
		 cout << "超时.\n";
		 sleep(1);
		 main();
	}
	else cin >> sup;
	if(sup!=8806) {
		cout << "密码错误！";
		sleep(2);
		pt++;
		debug();
	}
	if(sup==8806) de();
}
int main() {
	init1();
	dis();
	int inp=0;
	cout <<
	     "                     1 解二元一次方程\n"           <<
	     "                     2 解一元一次方程（未实现）\n" <<
	     "                     3 解一元二次方程\n"           <<
	     "                     4 基本计算      （未实现）\n" <<
	     "                     5 分解质因数              \n" <<
		 "                     6 求和                    \n" <<
	     "                     98 调试模式               \n"
	     <<
	     "                     99 关于&更新&日志         \n"

	     ;
	cin >> inp;
	switch(inp) {
		case 1:
			eyyc();
			break;
		case 2:
			yyyc();
			break;
		case 3:
			yyec();
			break;
		case 4:
			js();
			break;
		case 5:
			fjzys();
			break;
		case 6:
			sum();
			break;
		case 98:
			debug();
			break;
		case 99:
			about();
			break;
		default:
			cout << "无效输入\n";
			sleep(0.2);
			main();
	}
	return 0;
}
