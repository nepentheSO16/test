#include<iostream>
#include<string> 
#include<cmath>
using namespace std;
struct A{
	string n;
};
int jinzhizhuanhuan(string a,int h,int n){
	cout<<"�������ת����ʮ����Ϊ��";
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
			cout<<"����һ����������"<<endl;
			a[1]='0';
			i=2;
		}
		else if(a[1]=='x'||a[1]=='X'){
			cout<<"����һ��ʮ��������"<<endl;
			a[1]='0';
			i=16; 
		}
		else {
			cout<<"����һ���˽�����"<<endl;
			i=8; 
		}
	}
	else{
		cout<<"����һ��ʮ������"<<endl;
		i=10;
	}
	jinzhizhuanhuan(a,i,n);
}
int sizeyunsuan(){
	string a;
	cin>>a;
}
int main(){
	cout<<"��ѡ������Ҫ��ɵĹ��ܣ�"<<endl;
	cout<<"��������������1";
	int i;
	cin>>i;
	switch(i){
		case 1:
	}	
} 
