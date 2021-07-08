#include<bits/stdc++.h>
#include<windows.h>
#define N_OPTR 9
using namespace std;

string ver = "v1.2.0";
int itime=0;
int pt=0;
int verf=rand();
stack<float> opnd;//存储数字
stack<char> optr;//存储字符

typedef enum {   //通过枚举给每一个运算符一个编号
    ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE
} Operator;
const char pri[N_OPTR][N_OPTR] = {        //运算符优先级表
	/*              |-------------------- 当 前 运 算 符 --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='

};
Operator convert(char s) { //返回枚举类型
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
bool isdigit(char s) { //判断读取到的字符是否是数字
	if ((s - '0') <= 9 && (s - '0') >= 0) return true;
	else return false;
}
float calcu(float popnd) { //阶乘单目运算
	if (popnd == 1) return 1;
	return popnd * calcu(popnd - 1);
}
float calcu(float a, char op, float b) { //普通双目运算
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
			break; //表达式错误，直接返回异常
	}
}
char orderBetween(char s1, char s2) {
	return pri[convert(s1)][convert(s2)];
}
void readNum(char *& s) { //处理数字，尤其是如23这种连在一块的数字
	opnd.push(static_cast<float>(*s - '0'));
	while (isdigit(*(++s))) {
		float res = opnd.top() * 10 + *s - '0';
		opnd.pop();
		opnd.push(res);
	}
	if (*s != '.') return; //判断是否有小数点
	float fration = 1; //进行小数点后面运算
	while (isdigit(*(++s))) {
		float res2 = opnd.top() + (*s - '0')*(fration /= 10);
		opnd.pop();
		opnd.push(res2);
	}
}
float evalue(char *s) {
	optr.push('\0'); //这个‘/0’与字符串末尾‘/0’呼应
	while (!optr.empty()) {
		if (isdigit(*s)) {
			readNum(s);
		} else {
			switch (orderBetween(optr.top(), *s)) { //不同优先级处理
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
	printf("请稍候\n");
	printf("        |");
	Sleep(100);
	dis();
	printf("请稍候\n");
	printf("        / ");
	Sleep(100);
	dis();
	printf("请稍候\n");
	printf("        —");
	Sleep(100);
	dis();
	printf("请稍候\n");
	printf("        \\");
	Sleep(100);
	dis();
	printf("请稍候\n");
	printf("        |");
	Sleep(100);
	dis();
	printf("请稍候\n");
	printf("        / ");
	Sleep(100);
	dis();
	printf("请稍候\n");
	printf("        —");
	Sleep(100);
	dis();
	printf("请稍候\n");
	printf("        \\");
	Sleep(100);
	dis();
}
void init1() {
	itime++;
	if(itime>1) return;
	system("color 0e");
	for(int i=1; i<=1; i++) {
		printf("请稍候\n");
		printf("        |");
		Sleep(100);
		system("cls");
		printf("请稍候\n");
		printf("        / ");
		Sleep(100);
		system("cls");
		printf("请稍候\n");
		printf("        —");
		Sleep(100);
		system("cls");
		printf("请稍候\n");
		printf("        \\");
		Sleep(100);
		system("cls");
		printf("请稍候\n");
		printf("        |");
		Sleep(100);
		system("cls");
		printf("请稍候\n");
		printf("        / ");
		Sleep(100);
		system("cls");
		printf("请稍候\n");
		printf("        —");
		Sleep(100);
		system("cls");
		printf("请稍候\n");
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
	printf("                    POWERMATH 调试模式\n");
	printf("------------------------------------------------------------\n");
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
	dis();
	cout << "输入表达式：\n";
	char opt[1024];
	cin >> opt;
	cout << evalue(opt) << endl;
	system("pause");
	main();
}
void fjzys() {
	dis();
	long long i,n;
	printf("请输入需要分解质因数的数：");
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
	cout << "请输入求和终点：";
	long long n,i,sum=0;
	cin >> n;
	for(i=1; i<=n; i++)
		sum+=i;
	cout <<"求和结果：" << sum << endl;
	system("pause");
	main();
}

void update(string type) {
	dis();
	if(type=="system") {
		cout << "查找新版本。。。\n";
		Sleep(200);
		cout << "更新中。。。\n";
		Sleep(1000);
		ver = "v1.2.1";
		cout << "           Powermath (c) 2017-2021 lijunhao2023.\n                   All Rights Reserved.\n";
		system("pause");
		cout << "当前版本: v1.2." << verf << endl;
		system("pause");
		return;
	} else if(type=="gamecenter") {

	}
}

void about() {
	dis();
	cout << "检查更新?(y/n)\n";
	char up;
	cin >> up;
	verf=rand()%10;
	if(up=='y') {
		update("system");
	}
	if(up=='n') {
		cout << "           Powermath (c) 2017-2021 lijunhao2023.\n                   All Rights Reserved.\n";
		system("pause");
		cout << "当前版本: " << ver << endl;
		system("pause");
	}
	main();
}
void de() {
	dedis();
	cout << "                     1        打开cmd                  \n";
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
	printf("请在支持的认证Hexagon及Light设备上接收验证码。\n请输入：\n");
	string dbin;
	cin >> dbin;
	if(dbin!="Light06")  {
		printf("密码错误.\n");
		main();
	} else de();
}


void debug() {
	dis();
	string sup;
	printf("管理员：（双重认证）输入密码 :");
	if(pt==3) {
		cout << "超时.\n";
		Sleep(500);
		main();
	} else cin >> sup;
	if(sup!="8806") {
		cout << "密码错误！";
		Sleep(500);
		pt++;
		debug();
	} else dbreg();
}

void game() {
	dis();
	cout << "欢迎来到PowerGame (c) Game Center.\n";
	cout << "这里汇聚了由 lijunhao2023 从全网搜刮(bushi)来的各类小游戏.\n";
	cout << "是否更新游戏数据库？(y\n) \n";
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
	cout << "                     1 显示斐波那契数列表          \n" <<
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
	cout << "                     1 绿色                 \n"  <<
	     "                     2 蓝色                 \n"  <<
	     "                     3 红色                 \n"  <<
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
			cout << "暂不支持此颜色。\n";
			break;
	}
	system("pause");
	main();
}

void settings() {
	dis();
	cout <<
	     "                     1 颜色             \n"  <<
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
			cout << "暂不支持。\n";
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
	     "                     1 解二元一次方程          \n" <<
	     "                     2 解一元一次方程（未实现）\n" <<
	     "                     3 解一元二次方程          \n" <<
	     "                     4 基本计算                \n" <<
	     "                     5 分解质因数              \n" <<
	     "                     6 求和                    \n" <<
	     "                     97 其他功能               \n" <<
	     "                     98 调试模式               \n" <<
	     "                     99 设置                   \n" <<
	     "                     100 关于&更新&日志        \n" <<
	     "                     101 退出                  \n"
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
