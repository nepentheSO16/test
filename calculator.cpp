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
	double c[l],C[L];//��¼һ���ж��ٸ����Լ��ж��������мӼ����� 
	char d[l-1],D[L-1];//��¼һ���ж���������Լ��ж��ټӼ������ 
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
double duishuyunsuan(){//������ʽֻ֧��logx��Y����xΪ������ 
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
	cout<<"�ȽϵĽ��Ϊ��";
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
	cout<<"��Լ���У�"; 
	for(int i=1;i<=min(A,B);i++){
		if((int)(A)%i==0&&(int)(B)%i==0){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	for(int i=max(A,B);1;i++){
		if(i%(int)(A)==0&&i%(int)(B)==0){
			cout<<"��С������Ϊ��"<<i<<endl;
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
	cout<<"���̵Ľ�Ϊ��"<<a[I+1]<<"="<<C/B<<endl;
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
	cout<<"���̵Ľ�Ϊ��"<<a[j+1]<<"="<<B/C<<endl;
}
int yiyuanerci(){
	string x;
	cin>>x;
	double a,b,c;
	string A="1",B="0",C="0";
	int I=1,j=0,J=0;
	for(int i=x.length()-1;i>=0;i--){
		if((x[i]=='+'||x[i]=='-')&&I==1){
			j=i;
			I++;
		}
		if((x[i]=='+'||x[i]=='-')&&I==2){
			J=i;
		}
	}
	for(int i=0;i<x.length();i++){
		if(x[i]=='*'&&x[i+2]=='^'){
			A=x.substr(0,i);
		}
		else if(x[i]=='*'&&x[i+2]!='^'){
			B=x.substr(J+1,i-J-1);
		}
		else if(x[i]=='='){
			C=x.substr(j+1,i-j-1);
		}
	}
	a=jinzhishibie(A);
	if(x[0]=='-') a=-a;
	b=jinzhishibie(B);
	if(x[j]=='-') b=-b;
	c=jinzhishibie(C);
	if(x[J]=='-') c=-c;
	double d=b*b-4*a*c;
	if(d<0){
		cout<<"�÷����޽�"<<endl;
		return 0;
	} 
	double x1,x2;
	x1=(-b-sqrt(d))/(2*a);
	x2=(-b+sqrt(d))/(2*a);
	if(x1==x2) cout<<"�÷��̵Ľ�Ϊ��"<<x1<<endl; 
	else cout<<"�÷��̵Ľ�Ϊ��"<<x1<<"��"<<x2<<endl; 
}
void zhishu(){
	string x;
	cin>>x;
	string a,b;
	int I=0;
	for(int i=0;i<x.length();i++){
		if(x[i]=='*'){
			I=i;
			a=x.substr(0,i);
			b=x.substr(i+4,x.length()-i-4);	
			break;
		}
	}
	double A,B;
	A=jinzhishibie(a);
	B=jinzhishibie(b);
	cout<<"�÷��̵Ľ�Ϊ��"<<x[I+2]<<"="<<log(B)/log(A)<<endl;
}
void duishu(){
	string x;
	cin>>x;
	string a,b;
	int I;
	for(int i=0;i<x.length();i++){
		if(x[i]=='='){
			I=i;
			a=x.substr(i+1,x.length()-i-1);
			b=x.substr(3,i-6);
			break;
		}
	}
	cout<<a<<" "<<b<<endl;
	double A,B;
	A=jinzhishibie(a);
	B=jinzhishibie(b);
	cout<<"�÷��̵Ľ�Ϊ��"<<x[I-2]<<"="<<pow(B,A)<<endl;
}
int main(){
	cout<<"��ѡ������Ҫ��ɵĹ��ܣ�"<<endl;
	cout<<"��������������1   ʮ���ƶ�������������2   ������������3   ���Ǻ�������������4   ����������������֮��Ƚ�����������5"<<endl;
	cout<<"��Լ������С����������������6   һԪһ�η������������7   �������������������8   һԪ���η������������9"<<endl;
	cout<<"ָ���������������10   �����������������11"<<endl;
	int i;
	cin>>i;
	switch(i){
		case 1: cout<<"����ʽ�Ľ��Ϊ��"<<sizeyunsuan();
				break;
		case 2: cout<<"����ʽ��������Ľ��Ϊ��"<<duishuyunsuan();
				break;
		case 3: cout<<"������Ľ��Ϊ��"<<miyunsuan();
				break;
		case 4: cout<<"���Ǻ����ļ�����Ϊ��"<<sanjiaohanshu();
				break;
		case 5: bijiao();
				break;
		case 6: gongyueshugongbeishu();
				break;
		case 7: yiyuanyici();
				break;
		case 8: fanbili();
				break; 
		case 9: yiyuanerci();
				break;
		case 10: zhishu();
				break;
		case 11: duishu();
				break;
	}	
} 
