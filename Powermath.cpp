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
		printf("���Ժ�\n");
		printf("        |");
		sleep(0.5);
		dis();
		printf("���Ժ�\n");
		printf("        / ");
		sleep(0.5);
		dis();
		printf("���Ժ�\n");
		printf("        ��");
		sleep(0.5);
		dis();
		printf("���Ժ�\n");
		printf("        \\");
		sleep(0.5);
		dis();
		printf("���Ժ�\n");
		printf("        |");
		sleep(0.5);
		dis();
		printf("���Ժ�\n");
		printf("        / ");
		sleep(0.5);
		dis();
		printf("���Ժ�\n");
		printf("        ��");
		sleep(0.5);
		dis();
		printf("���Ժ�\n");
		printf("        \\");
		sleep(0.5);
		dis();
}
void init1() {
	itime++;
	if(itime>1) return;
	for(int i=1; i<=1; i++) {
		printf("���Ժ�\n");
		printf("        |");
		sleep(0.5);
		system("cls");
		printf("���Ժ�\n");
		printf("        / ");
		sleep(0.5);
		system("cls");
		printf("���Ժ�\n");
		printf("        ��");
		sleep(0.5);
		system("cls");
		printf("���Ժ�\n");
		printf("        \\");
		sleep(0.5);
		system("cls");
		printf("���Ժ�\n");
		printf("        |");
		sleep(0.5);
		system("cls");
		printf("���Ժ�\n");
		printf("        / ");
		sleep(0.5);
		system("cls");
		printf("���Ժ�\n");
		printf("        ��");
		sleep(0.5);
		system("cls");
		printf("���Ժ�\n");
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
	printf("                    POWERMATH ����ģʽ\n");
	printf("------------------------------------------------------------------\n");
}
void eyyc( ) {
	dis();
	float a,b,c,d,e,f;
	cout<<"�������Ԫһ�η�����\n"<<"  ax+by+c=0\n"<<"  dx+ey+f=0\n";
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
		cout<<"�������޽⡣\n";
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
	cout<<"������һԪ���η��̵�ϵ����a,b,c a^2*x+bx+c=0��:"<<endl;
	cin>>a>>b>>c;
	if(a==0) {
		cout<<"����һ��һԪ���η���"<<endl;
		system("pause");
		main();
	}
	float t =b*b-4*a*c;
	if(t<0) {
		cout<<"����û��ʵ��"<<endl;
		system("pause");
		main();
	}
	if(t==0) { //�ж�����Ƿ��еȸ�
		root1=root2=-b/(2*a);
	} else {
		root1=(-b+sqrt(t))/(2*a);
		root2=(-b-sqrt(t))/(2*a);
	}
	cout<<"���̵ĸ�Ϊ:"<<root1<<"��"<<root2<<endl;
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
	printf("��������Ҫ�ֽ�������������");
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
	cout << "����������յ㣺";
	long long n,i,sum=0;
	cin >> n;
	for(i=1;i<=n;i++)
		sum+=i;
	cout <<"��ͽ����" << sum << endl;
	system("pause");
	main();
}
void about() {
	dis(); 
	cout << "������?(y/n)\n";
	char up;
	cin >> up;
	verf=rand();
	if(up=='y') {
		cout << "�����°汾������\n";
		sleep(0.2); 
		cout << "�����С�����\n";
		sleep(0.1); 
		ver = "v1.1.1";
	}
	cout << "           Powermath (c) 2017-2021 lijunhao2023.\n                   All Rights Reserved.\n";
	system("pause");
	cout << "��ǰ�汾: v1.1." << verf << endl;
	system("pause");
	main();
}
void de() {
	dedis();
	cout << "1        ";
	cout << "99 �˳�"; 
	main();
}
void debug() {
	dis();
	int sup;
	printf("sudo: pasword for root :");
	if(pt==3) {
		 cout << "��ʱ.\n";
		 sleep(1);
		 main();
	}
	else cin >> sup;
	if(sup!=8806) {
		cout << "�������";
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
	     "                     1 ���Ԫһ�η���\n"           <<
	     "                     2 ��һԪһ�η��̣�δʵ�֣�\n" <<
	     "                     3 ��һԪ���η���\n"           <<
	     "                     4 ��������      ��δʵ�֣�\n" <<
	     "                     5 �ֽ�������              \n" <<
		 "                     6 ���                    \n" <<
	     "                     98 ����ģʽ               \n"
	     <<
	     "                     99 ����&����&��־         \n"

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
			cout << "��Ч����\n";
			sleep(0.2);
			main();
	}
	return 0;
}
