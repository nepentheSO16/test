#include<iostream>
#include<string> 
#include<cmath>
#define pi 3.14159265358979
using namespace std;
double jinzhizhuanhuan(string a,double h,double n){
	int j=n;
	for(int i=0;i<n;i++){
		if(a[i]=='.') j=i+1;
	}
	double l=0;
	for(int i=j-n,I=0;I<n;I++,i++){
		if(a[n-I-1]=='.') {
			I++;
		}
		if(a[n-I-1]=='-'){
			l=-l;
			break;
		}
		l=l+(double)(a[n-I-1]-'0')*pow(h,i);	
	}
	return l;
}
double jinzhishibie(string a){
	double i;
	int n=a.length();
	if(a[0]!='-'){
		if(a[0]=='0'){
			if(a[1]=='b'||a[1]=='B'){
				a[1]='0';
				i=2;
			}
			else if(a[1]=='x'||a[1]=='X'){
				a[1]='0';
				i=16; 
			}
			else {
				i=8; 
			}
		}
		else{
			i=10;
		}
	return jinzhizhuanhuan(a,i,n);
	}
	else if(a[0]=='-'){
		if(a[1]=='0'){
			if(a[2]=='b'||a[2]=='B'){
				a[2]='0';
				i=2;
			}
			else if(a[2]=='x'||a[2]=='X'){
				a[2]='0';
				i=16; 
			}
			else {
				i=8; 
			}
		}
		else if(a[1]!='0'){
			i=10;
		}
		return jinzhizhuanhuan(a,i,n);
	}
}
double sizeyunsuan(){
	string a;
	cin>>a;
	int l=1,L=1;
	for(int i=0;i<a.length();i++){
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/') l++;
		if(a[i]=='-'||a[i]=='+') L++; 
	}
	string b;
	double c[l],C[L];//记录一共有多少个数以及有多少数进行加减运算 
	char d[l-1],D[L-1];//记录一共有多少运算符以及有多少加减运算符 
	double I=0;
	int j=0,J=0;
	for(int i=0;i<=a.length();i++,I++){
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
			d[j]=a[i];
		}
		if(a[i]=='+'||a[i]=='-'){
			D[J]=a[i];
			J++;
		}
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='\0'){
			b=a.substr(i-I,I);
			i++;
			I=0;
			c[j]=jinzhishibie(b);
			j++;
		}
	}
	C[0]=c[0];
	J=0;
	for(int i=0;i<l-1;i++){
		if(d[i]=='*'){
			C[J]=C[J]*c[i+1];
		}
		else if(d[i]=='/'){
			C[J]=C[J]/c[i+1];
		}
		else{
			J++;
			C[J]=c[i+1];
		}
	}
	I=C[0];
	for(int i=0;i<L-1;i++){
		if(D[i]=='+') I=I+C[i+1];
		else if(D[i]=='-') I=I-C[i+1];	
	}
	return I;
}
double duishuyunsuan(){//对数形式只支持logx（Y）（x为底数） 
	string a;
	cin>>a;
	string b,c;
	int j=0,J=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='(') j=i;
		if(a[i]==')'){
			J=i;
			break;
		}
	}
	b=a.substr(3,j-3);
	c=a.substr(j+1,J-j-1);
	double A;
	double B,C;
	B=jinzhishibie(b);
	C=jinzhishibie(c);
	A=log(double(C))/log(double(B));
	return A;
}
double miyunsuan(){
	string a;
	cin>>a;
	int j;
	for(int i=0;i<a.length();i++){
		if(a[i]=='*'){
			j=i;
			break; 
		}
	}
	string b,c;
	b=a.substr(0,j);
	c=a.substr(j+2,a.length()-j-2);
	double A,B,C;
	B=jinzhishibie(b);
	C=jinzhishibie(c);
	cout<<B<<" "<<C;
	A=pow(B,C);
	return A;
} 
double sanjiaohanshu(){
	string a;
	cin>>a;
	string b,c;
	b=a.substr(0,3);
	c=a.substr(4,a.length()-5);
	double A,C;
	C=jinzhishibie(c);
	C=C/180.0*pi;
	if(b=="cos") A=cos(C);
	else if(b=="sin") A=sin(C);
	else if(b=="tan") A=tan(C);
	else if(b=="cot") A=1.0/tan(C);
	else if(b=="sec") A=1.0/cos(C);
	else if(b=="csc") A=1.0/sin(C);
	return A;
}
void bijiao(){
	string a,b;
	cin>>a;
	cin>>b;
	double A,B;
	A=jinzhishibie(a);
	B=jinzhishibie(b);
	cout<<"比较的结果为：";
	if(A>B) cout<<a<<">"<<b<<endl;
	else if(A==B) cout<<a<<"="<<b<<endl;
	else if(A<B) cout<<a<<"<"<<b<<endl; 
} 
void gongyueshugongbeishu(){
	string a,b;
	cin>>a;
	cin>>b;
	double A,B;
	A=jinzhishibie(a);
	B=jinzhishibie(b);
	cout<<"公约数有："; 
	for(int i=1;i<=min(A,B);i++){
		if((int)(A)%i==0&&(int)(B)%i==0){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	for(int i=max(A,B);1;i++){
		if(i%(int)(A)==0&&i%(int)(B)==0){
			cout<<"最小公倍数为："<<i<<endl;
			break; 
		}
	}
}
void yiyuanyici(){
	string a;
	cin>>a;
	int I,j,J; 
	for(int i=0;i<a.length();i++){
		if(a[i]=='*') I=i;
		else if(a[i]=='-'||a[i]=='+') j=i;
		else if(a[i]=='=') J=i;
	}
	string b,c;
	b=a.substr(0,I);
	c=a.substr(j+1,J-j-1);
	double B,C;
	B=jinzhishibie(b);
	C=jinzhishibie(c);
	if(a[j]=='+') C=-C;
	cout<<"方程的解为："<<a[I+1]<<"="<<C/B<<endl;
}
void fanbili(){
	string a;
	cin>>a;
	int j,J; 
	for(int i=0;i<a.length();i++){
		if(a[i]=='/') j=i;
		else if(a[i]=='=') J=i;
	}
	string b,c;
	b=a.substr(0,j);
	c=a.substr(J+1,a.length()-J-1);
	double B,C;
	B=jinzhishibie(b);
	C=jinzhishibie(c);
	cout<<"方程的解为："<<a[j+1]<<"="<<B/C<<endl;
}
void yiyuanerci(){
	string a;
	cin>>a;
	
}
int main(){
	cout<<"请选择您想要完成的功能："<<endl;
	cout<<"四则运算请输入1   十进制对数运算请输入2   幂运算请输入3   三角函数计算请输入4   任意两个进制数字之间比较运算请输入5"<<endl;
	cout<<"公约数、最小公倍数计算请输入6   一元一次方程求解请输入7   反比例函数求解请输入8"<<endl;
	int i;
	cin>>i;
	switch(i){
		case 1: cout<<"输入式的结果为："<<sizeyunsuan();
				break;
		case 2: cout<<"输入式对数运算的结果为："<<duishuyunsuan();
				break;
		case 3: cout<<"幂运算的结果为："<<miyunsuan();
				break;
		case 4: cout<<"三角函数的计算结果为："<<sanjiaohanshu();
				break;
		case 5: bijiao();
				break;
		case 6: gongyueshugongbeishu();
				break;
		case 7: yiyuanyici();
				break;
		case 8: fanbili();
				break; 
	}	
} 
