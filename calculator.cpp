#include<iostream>
#include<string> 
#include<cmath>
using namespace std;
struct A{
	string n;
};
int jinzhizhuanhuan(string a,int h,int n){
	cout<<"将这个数转换成十进制为：";
	int l=0;
	for(int i=0;i<n;i++){
		l=l+(int)(a[n-i-1]-'0')*pow(h,i);	
	}
	cout<<l;
	return l;
}
void jinzhishibie(string a){
	int i;
	int n=a.length();
	if(a[0]=='0'){
		if(a[1]=='b'||a[1]=='B'){
			cout<<"这是一个二进制数"<<endl;
			a[1]='0';
			i=2;
		}
		else if(a[1]=='x'||a[1]=='X'){
			cout<<"这是一个十六进制数"<<endl;
			a[1]='0';
			i=16; 
		}
		else {
			cout<<"这是一个八进制数"<<endl;
			i=8; 
		}
	}
	else{
		cout<<"这是一个十进制数"<<endl;
		i=10;
	}
	jinzhizhuanhuan(a,i,n);
}
int sizeyunsuan(){
	string a;
	cin>>a;
}
int main(){
	cout<<"请选择您想要完成的功能："<<endl;
	cout<<"四则运算请输入1";
	int i;
	cin>>i;
	switch(i){
		case 1:
	}	
} 
