#include<iostream>
#include<fstream>
using namespace std;     //calculate the number of AND gates in our UC

int compute (int n){     //calculate the size of EUG_2(n) 
  if (n<=2) return 0;
  if (n==3) return 2;
  if (n==4) return 3;
  int f[4]={10,0,2,6},s[4]={18,17,18,18};
  int m=0,r=0,d=0;
  r=n%4;
  d=(n-r)/4;
  if (r!=0) d=d+1;
  for (int i=1;i<=d;i++){
    if (i<d-1){
	    m=m+18;
	}
	if (i==d-1){
		m=m+s[r];
	}
	if (i==d){
	    m=m+f[r];
	}
	if (i==1) m=m-4;
  }//for
  if (r==0) m=m+4*compute(d-1);
  else m=m+r*compute(d-1)+(4-r)*compute(d-2);
  return m;
}//compute
int main(){
  int n;
  char ch;
  cout<<"Please input the size of the DAG (circuits):";
  cin>>n;
  cout<<"The size of EUG_2("<<n<<") is: "<<2*compute(n)+n<<endl;
  cout<<"Input a char to finish.";
  cin>>ch;
  return 0;
} 
