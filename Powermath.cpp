#include<bits/stdc++.h>
#include<windows.h>
#define N_OPTR 9
using namespace std;

string ver = "v1.2.0";
int itime=0;
int pt=0;
int verf=rand();
stack<float> opnd;//�洢����
stack<char> optr;//�洢�ַ�

typedef enum {   //ͨ��ö�ٸ�ÿһ�������һ�����
    ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE
} Operator;
const char pri[N_OPTR][N_OPTR] = {        //��������ȼ���
	/*              |-------------------- �� ǰ �� �� �� --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* ջ  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* ��  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* ��  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='

};
Operator convert(char s) { //����ö������
	switch (s) {
		case '+':
			return ADD;
			break;
		case '-':
			return SUB;
			break;
		case '*':
			return MUL;
			break;
		case '/':
			return DIV;
			break;
		case '^':
			return POW;
			break;
		case '!':
			return FAC;
			break;
		case '(':
			return L_P;
			break;
		case ')':
			return R_P;
			break;
		case '\0':
			return EOE;
			break;
	}
}
bool isdigit(char s) { //�ж϶�ȡ�����ַ��Ƿ�������
	if ((s - '0') <= 9 && (s - '0') >= 0) return true;
	else return false;
}
float calcu(float popnd) { //�׳˵�Ŀ����
	if (popnd == 1) return 1;
	return popnd * calcu(popnd - 1);
}
float calcu(float a, char op, float b) { //��ͨ˫Ŀ����
	switch (op) {
		case '+':
			return (a + b);
			break;
		case '-':
			return (a - b);
			break;
		case '*':
			return (a*b);
			break;
		case '/':
			return (a / b);
			break;
		case '^':
			return (pow(a, b));
			break;
		default:
			exit(-1);
			break; //���ʽ����ֱ�ӷ����쳣
	}
}
char orderBetween(char s1, char s2) {
	return pri[convert(s1)][convert(s2)];
}
void readNum(char *& s) { //�������֣���������23��������һ�������
	opnd.push(static_cast<float>(*s - '0'));
	while (isdigit(*(++s))) {
		float res = opnd.top() * 10 + *s - '0';
		opnd.pop();
		opnd.push(res);
	}
	if (*s != '.') return; //�ж��Ƿ���С����
	float fration = 1; //����С�����������
	while (isdigit(*(++s))) {
		float res2 = opnd.top() + (*s - '0')*(fration /= 10);
		opnd.pop();
		opnd.push(res2);
	}
}
float evalue(char *s) {
	optr.push('\0'); //�����/0�����ַ���ĩβ��/0����Ӧ
	while (!optr.empty()) {
		if (isdigit(*s)) {
			readNum(s);
		} else {
			switch (orderBetween(optr.top(), *s)) { //��ͬ���ȼ�����
				case '<': {
					optr.push(*s);
					s++;
				}
				break;
				case '>': {
					char op = optr.top();
					optr.pop();
					if (op == '!') {
						float popnd = opnd.top();
						opnd.pop();
						opnd.push(calcu(popnd));
					} else {
						float popnd1 = opnd.top();
						opnd.pop();
						float popnd2 = opnd.top();
						opnd.pop();
						opnd.push(calcu(popnd1, op, popnd2));
					}
				}
				break;
				case '=': {
					optr.pop();
					s++;
				}
				break;
				default:
					exit(-1);
			}
		}
	}
	return opnd.top();
}
int main();
void dis();
void init2() {
	dis();
	system("color 0a");
	printf("���Ժ�\n");
	printf("        |");
	Sleep(100);
	dis();
	printf("���Ժ�\n");
	printf("        / ");
	Sleep(100);
	dis();
	printf("���Ժ�\n");
	printf("        ��");
	Sleep(100);
	dis();
	printf("���Ժ�\n");
	printf("        \\");
	Sleep(100);
	dis();
	printf("���Ժ�\n");
	printf("        |");
	Sleep(100);
	dis();
	printf("���Ժ�\n");
	printf("        / ");
	Sleep(100);
	dis();
	printf("���Ժ�\n");
	printf("        ��");
	Sleep(100);
	dis();
	printf("���Ժ�\n");
	printf("        \\");
	Sleep(100);
	dis();
}
void init1() {
	itime++;
	if(itime>1) return;
	system("color 0e");
	for(int i=1; i<=1; i++) {
		printf("���Ժ�\n");
		printf("        |");
		Sleep(100);
		system("cls");
		printf("���Ժ�\n");
		printf("        / ");
		Sleep(100);
		system("cls");
		printf("���Ժ�\n");
		printf("        ��");
		Sleep(100);
		system("cls");
		printf("���Ժ�\n");
		printf("        \\");
		Sleep(100);
		system("cls");
		printf("���Ժ�\n");
		printf("        |");
		Sleep(100);
		system("cls");
		printf("���Ժ�\n");
		printf("        / ");
		Sleep(100);
		system("cls");
		printf("���Ժ�\n");
		printf("        ��");
		Sleep(100);
		system("cls");
		printf("���Ժ�\n");
		printf("        \\");
		Sleep(100);
		system("cls");
	}
	init2();
}
void dis() {
	system("cls");
	printf("____________________________________________________________\n");
	printf("                         POWERMATH\n");
	printf("------------------------------------------------------------\n");
}
void dedis() {
	system("cls");
	printf("____________________________________________________________\n");
	printf("                    POWERMATH ����ģʽ\n");
	printf("------------------------------------------------------------\n");
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
	dis();
	cout << "������ʽ��\n";
	char opt[1024];
	cin >> opt;
	cout << evalue(opt) << endl;
	system("pause");
	main();
}
void fjzys() {
	dis();
	long long i,n;
	printf("��������Ҫ�ֽ�������������");
	scanf("%lld",&n);
	printf("\n%lld=",n);
	for(i=2; i<=n; i++) {
		while(n!=i) {
			if(n%i==0) {
				printf("%lld*",i);
				n=n/i;
			} else break;
		}
	}
	printf("%lld\n",n);
	system("pause");
	main();
}
void sum() {
	dis();
	cout << "����������յ㣺";
	long long n,i,sum=0;
	cin >> n;
	for(i=1; i<=n; i++)
		sum+=i;
	cout <<"��ͽ����" << sum << endl;
	system("pause");
	main();
}

void update(string type) {
	dis();
	if(type=="system") {
		cout << "�����°汾������\n";
		Sleep(200);
		cout << "�����С�����\n";
		Sleep(1000);
		ver = "v1.2.1";
		cout << "           Powermath (c) 2017-2021 lijunhao2023.\n                   All Rights Reserved.\n";
		system("pause");
		cout << "��ǰ�汾: v1.2." << verf << endl;
		system("pause");
		return;
	} else if(type=="gamecenter") {

	}
}

void about() {
	dis();
	cout << "������?(y/n)\n";
	char up;
	cin >> up;
	verf=rand()%10;
	if(up=='y') {
		update("system");
	}
	if(up=='n') {
		cout << "           Powermath (c) 2017-2021 lijunhao2023.\n                   All Rights Reserved.\n";
		system("pause");
		cout << "��ǰ�汾: " << ver << endl;
		system("pause");
	}
	main();
}
void de() {
	dedis();
	cout << "                     1        ��cmd                  \n";
	int dei;
	cin >> dei;
	switch(dei) {
		case 1:
			system("cmd");
			break;
		default:
			break;
	}
	system("pause");
	main();
}

void dbreg() {
	dis();
	printf("����֧�ֵ���֤Hexagon��Light�豸�Ͻ�����֤�롣\n�����룺\n");
	string dbin;
	cin >> dbin;
	if(dbin!="Light06")  {
		printf("�������.\n");
		main();
	} else de();
}


void debug() {
	dis();
	string sup;
	printf("����Ա����˫����֤���������� :");
	if(pt==3) {
		cout << "��ʱ.\n";
		Sleep(500);
		main();
	} else cin >> sup;
	if(sup!="8806") {
		cout << "�������";
		Sleep(500);
		pt++;
		debug();
	} else dbreg();
}

void game() {
	dis();
	cout << "��ӭ����PowerGame (c) Game Center.\n";
	cout << "���������� lijunhao2023 ��ȫ���ѹ�(bushi)���ĸ���С��Ϸ.\n";
	cout << "�Ƿ������Ϸ���ݿ⣿(y\n) \n";
	char ch;
	cin >> ch;
	if(ch=='y') ;
	else if(ch=='n') ;
	else {
		cout << "?\n";
		game();
	}

}

void others() {
	dis();
	cout << "                     1 ��ʾ쳲��������б�          \n" <<
	     "                     2 Game Center                 \n"    <<
	     ""
	     ;
	int opt;
	cin >> opt;
	switch(opt) {
		case 2:
			game();
		default:
			break;
	}
	main();
}

void colors() {
	dis();
	cout << "                     1 ��ɫ                 \n"  <<
	     "                     2 ��ɫ                 \n"  <<
	     "                     3 ��ɫ                 \n"  <<
	     "                     4                      \n"
	     ;
	int col;
	cin >> col;
	switch(col) {
		case 1:
			system("color 0a");
			break;
		case 2:
			system("color 0b");
			break;
		case 3:
			system("color 0c");
			break;
		default:
			cout << "�ݲ�֧�ִ���ɫ��\n";
			break;
	}
	system("pause");
	main();
}

void settings() {
	dis();
	cout <<
	     "                     1 ��ɫ             \n"  <<
	     "                     2                  \n"  <<
	     "                     3                  \n"
	     ;
	int col;
	cin >> col;
	switch(col) {
		case 1:
			colors();
			break;
		default:
			cout << "�ݲ�֧�֡�\n";
			break;
	}
	system("pause");
	main();
}
int main() {
	srand(time(NULL));
	system("mode con cols=60 lines=20");
	system("title Powermath by lijunhao2023");
	dis();

	unsigned long long inp=0;
	cout <<
	     "                     1 ���Ԫһ�η���          \n" <<
	     "                     2 ��һԪһ�η��̣�δʵ�֣�\n" <<
	     "                     3 ��һԪ���η���          \n" <<
	     "                     4 ��������                \n" <<
	     "                     5 �ֽ�������              \n" <<
	     "                     6 ���                    \n" <<
	     "                     97 ��������               \n" <<
	     "                     98 ����ģʽ               \n" <<
	     "                     99 ����                   \n" <<
	     "                     100 ����&����&��־        \n" <<
	     "                     101 �˳�                  \n"
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
		case 97:
			others();
			break;
		case 98:
			debug();
			break;
		case 99:
			settings();
			break;
		case 100:
			about();
			break;
		case 101:
			system("pause");
			PostMessage(GetConsoleWindow(),WM_QUIT,0,0);
			exit(0);
		default:
			cout << "?\n";
			Sleep(200);
			main();
	}
	return 0;
}
