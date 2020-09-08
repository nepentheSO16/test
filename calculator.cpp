#include<iostream>
#include<string> 
#include<cmath>
using namespace std;
int jinzhizhuanhuan(string a,int h,int n){
	int l=0;
	for(int i=0;i<n;i++){
		l=l+(int)(a[n-i-1]-'0')*pow(h,i);	
	}
	return l;
}
int jinzhishibie(string a){
	int i;
	int n=a.length();
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
int sizeyunsuan(){
	string a;
	cin>>a;
	int l=1,L=1;
	for(int i=0;i<a.length();i++){
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/') l++;
		if(a[i]=='-'||a[i]=='+') L++; 
	}
	string b;
	int c[l],C[L];//记录一共有多少个数以及有多少数进行加减运算 
	char d[l-1],D[L-1];//记录一共有多少运算符以及有多少加减运算符 
	int I=0;
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
int main(){
	cout<<"请选择您想要完成的功能："<<endl;
	cout<<"四则运算请输入1";
	int i;
	cin>>i;
	switch(i){
		case 1: cout<<"输入式的结果转换为十进制为："<<sizeyunsuan();
				break;
	}	
} 
