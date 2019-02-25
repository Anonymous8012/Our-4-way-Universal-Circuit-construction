#include<iostream>
#include<fstream>
using namespace std;
int re18=0,re14=0,re10=0,re3=0;
class SN{
  public:
  	int m;
  	int p[4];
  	int pre[26][2],sub[26][2];
    void creat(){
      m=26;
      p[0]=4;p[1]=5;p[2]=6;p[3]=7;
      pre[0][0]=-1;pre[0][1]=-1;
      sub[0][0]=8;pre[0][1]=-1;
      pre[1][0]=-1;pre[1][1]=-1;
      sub[1][0]=8;pre[1][1]=-1;
	  pre[2][0]=-1;pre[2][1]=-1;
      sub[2][0]=9;pre[2][1]=-1;
	  pre[3][0]=-1;pre[3][1]=-1;
      sub[3][0]=9;pre[3][1]=-1;
      pre[4][0]=10;pre[4][1]=-1;
      sub[4][0]=12;sub[4][1]=-1;
      pre[5][0]=13;pre[5][1]=-1;
      sub[5][0]=14;sub[5][1]=-1;
      pre[6][0]=14;pre[6][1]=-1;
      sub[6][0]=15;sub[6][1]=-1;
      pre[7][0]=17;pre[7][1]=-1;
      sub[7][0]=19;sub[7][1]=-1;
      
      pre[8][0]=0;pre[8][1]=1;
      sub[8][0]=10;sub[8][1]=11;
      pre[9][0]=2;pre[9][1]=3;
      sub[9][0]=10;sub[9][1]=11;
      pre[10][0]=8;pre[10][1]=9;
      sub[10][0]=4;sub[10][1]=12;
      pre[11][0]=8;pre[11][1]=9;
      sub[11][0]=13;sub[11][1]=16;
      pre[12][0]=4;pre[12][1]=10;
      sub[12][0]=13;sub[12][1]=16;
      pre[13][0]=11;pre[13][1]=12;
      sub[13][0]=5;sub[13][1]=14;
      pre[14][0]=13;pre[14][1]=5;
      sub[14][0]=6;sub[14][1]=15;
      pre[15][0]=6;pre[15][1]=14;
      sub[15][0]=17;sub[15][1]=18;
      pre[16][0]=11;pre[16][1]=12;
      sub[16][0]=17;sub[16][1]=18;
      pre[17][0]=15;pre[17][1]=16;
      sub[17][0]=7;sub[17][1]=19;
      pre[18][0]=15;pre[18][1]=16;
      sub[18][0]=20;sub[18][1]=21;
      pre[19][0]=7;pre[19][1]=17;
      sub[19][0]=20;sub[19][1]=21;
      pre[20][0]=18;pre[20][1]=19;
      sub[20][0]=24;sub[20][1]=25;
      pre[21][0]=18;pre[21][1]=19;
      sub[21][0]=22;sub[21][1]=23;
      
      pre[22][0]=21;pre[22][1]=-1;
      sub[22][0]=-1;pre[22][1]=-1;
      pre[23][0]=21;pre[23][1]=-1;
      sub[23][0]=-1;pre[23][1]=-1;
	  pre[24][0]=20;pre[24][1]=-1;
      sub[24][0]=-1;pre[24][1]=-1;
	  pre[25][0]=20;pre[25][1]=-1;
      sub[25][0]=-1;pre[25][1]=-1;
      
      
	}//creat
};

class EUG{
  public:
  	int m,n;
  	int p[400];
  	int pre[10000][2],sub[10000][2];
  	void creat(){
  	  for (int i=0;i<10000;i++)
  	    for (int j=0;j<=1;j++){
  	        pre[i][j]=-1;
			sub[i][j]=-1; 	
		}//for ij
  	  m=0;
  	  n=0;
	}//creat
	void output (ofstream *fout){
		(*fout)<<"This EUG is for all DAG("<<n<<")."<<endl<<"The poles are:";
		for (int i=0;i<n;i++) {
			(*fout)<<p[i]<<" ";
		}
		(*fout)<<endl<<"There are "<<m<<" nodes in the EUG_1"<<endl<<"Prenodes:"<<endl;
		for (int i=0;i<m;i++){
			(*fout)<<i<<":";
			if (pre[i][0]!=-1) (*fout)<<pre[i][0]<<" ";
			if (pre[i][1]!=-1) (*fout)<<pre[i][1];
			(*fout)<<endl;
		}//for
		(*fout)<<"subnodes:"<<endl;
		for (int i=0;i<m;i++){
			(*fout)<<i<<":";
			if (sub[i][0]!=-1) (*fout)<<sub[i][0]<<" ";
			if (sub[i][1]!=-1) (*fout)<<sub[i][1];
			(*fout)<<endl;
		}//for
		return;
	}
  	void copy(int n,int head,int tail,SN sn,int p1,int p2,int p3,int p4){
  	  int pi[26];
  	  for (int i=0;i<=25;i++) pi[i]=-1;
  	  if ((head==1)&&(tail==1)){
  	    pi[0]=m-4;pi[1]=m-3;pi[2]=m-2;pi[3]=m-1;
  	    pi[4]=p1;pi[5]=p2;pi[6]=p3;pi[7]=p4;
  	    for (int i=8;i<=25;i++){
  	      pi[i]=m+i-8;	
	    }//for i
	    for (int i=0;i<=25;i++){
	      if (pi[i]!=-1){
	  	    if (sn.pre[i][0]!=-1){
	  	      if (pre[pi[i]][0]==-1) pre[pi[i]][0]=pi[sn.pre[i][0]];
	  	      else pre[pi[i]][1]=pi[sn.pre[i][0]];
	  	      if (sn.pre[i][1]!=-1) pre[pi[i]][1]=pi[sn.pre[i][1]];
		    }//if pre[i][0]!=-1
		    if (sn.sub[i][0]!=-1){
	  	      if (sub[pi[i]][0]==-1) sub[pi[i]][0]=pi[sn.sub[i][0]];
	  	      else sub[pi[i]][1]=pi[sn.sub[i][0]];
	  	      if (sn.sub[i][1]!=-1) sub[pi[i]][1]=pi[sn.sub[i][1]];
	  	    }//if sub[i][0]!=-1
	      }//if
	    }//for i
	    m=m+18;
	    re18++; 
      }//if head
      if ((head==0)&&(tail==1)){
    	pi[4]=p1;pi[5]=p2;pi[6]=p3;pi[7]=p4;
    	for (int i=12;i<=25;i++){
  	      pi[i]=m+i-12;	
	    }//for i
	    for (int i=0;i<=25;i++){
	      if (pi[i]!=-1){
	  	    if (sn.pre[i][0]!=-1){
	  	      if (pre[pi[i]][0]==-1) pre[pi[i]][0]=pi[sn.pre[i][0]];
	  	      else pre[pi[i]][1]=pi[sn.pre[i][0]];
	  	      if (sn.pre[i][1]!=-1) pre[pi[i]][1]=pi[sn.pre[i][1]];
		    }//if pre[i][0]!=-1
		    if (sn.sub[i][0]!=-1){
	  	      if (sub[pi[i]][0]==-1) sub[pi[i]][0]=pi[sn.sub[i][0]];
	  	      else sub[pi[i]][1]=pi[sn.sub[i][0]];
	  	      if (sn.sub[i][1]!=-1) sub[pi[i]][1]=pi[sn.sub[i][1]];
	  	    }//if sub[i][0]!=-1
	      }//if
	    }//for i
	    m=m+14;
	    re14++;
	  }
	  if ((head==1)&&(tail==0)){
    	pi[0]=m-4;pi[1]=m-3;pi[2]=m-2;pi[3]=m-1;
  	    pi[4]=p1;pi[5]=p2;pi[6]=p3;pi[7]=p4;
  	    for (int i=8;i<=17;i++){
  	      pi[i]=m+i-8;	
	    }//for i
	    for (int i=0;i<=17;i++){
	      if (pi[i]!=-1){
	  	    if (sn.pre[i][0]!=-1){
	  	      if (pre[pi[i]][0]==-1) pre[pi[i]][0]=pi[sn.pre[i][0]];
	  	      else pre[pi[i]][1]=pi[sn.pre[i][0]];
	  	      if (sn.pre[i][1]!=-1) pre[pi[i]][1]=pi[sn.pre[i][1]];
		    }//if pre[i][0]!=-1
		    if (sn.sub[i][0]!=-1){
	  	      if (sub[pi[i]][0]==-1) sub[pi[i]][0]=pi[sn.sub[i][0]];
	  	      else sub[pi[i]][1]=pi[sn.sub[i][0]];
	  	      if (sn.sub[i][1]!=-1) sub[pi[i]][1]=pi[sn.sub[i][1]];
	  	    }//if sub[i][0]!=-1
	      }//if
	    }//for i
	    m=m+10;
	    re10++;
	  }
	  if ((head==0)&&(tail==0)){
		pre[m][0]=p1;pre[m][1]=-1;
		sub[m][0]=p2;sub[m][1]=m+1;
		pre[m+1][0]=p2;pre[m+1][1]=m;
		sub[m+1][0]=p3;sub[m+1][1]=m+2;
		pre[m+2][0]=p3;pre[m+2][1]=m+1;
		sub[m+2][0]=p4;sub[m+2][1]=-1;
		if (sub[p1][0]==-1) sub[p1][0]=m; else sub[p1][1]=m;
		if (pre[p2][0]==-1) pre[p2][0]=m; else pre[p2][1]=m;
		if (sub[p2][0]==-1) sub[p2][0]=m+1; else sub[p2][1]=m+1;
		if (pre[p3][0]==-1) pre[p3][0]=m+1; else pre[p3][1]=m+1;
		if (sub[p3][0]==-1) sub[p3][0]=m+2; else sub[p3][1]=m+2;
		if (pre[p4][0]==-1) pre[p4][0]=m+2; else pre[p4][1]=m+2;
		m=m+3;
		re3++;
	  }
	  //cout<<m<<endl;
	}//copySN
	void construct(int n,int* a){
		SN sn;
		sn.creat();
		int b[4][2500];
		int head,tail;
		if (n<=0) return;
		for (int i=0;i<=(n-1)/4;i++){
			if (i==0) head=0;
			else head=1;
			if (i==(n-1)/4) tail=0;
			else tail=1;
		   copy(n,head,tail,sn,a[4*i],a[4*i+1],a[4*i+2],a[4*i+3]);
		   b[0][i]=m-4;
		   b[1][i]=m-3;
		   b[2][i]=m-2;
		   b[3][i]=m-1;
		}//for
		for (int i=0;i<=3;i++){
			construct((n-1)/4,b[i]);
		}//for
	}//construct
};
int main(){
  EUG eug;
  eug.creat();
  int n;
  cout<<"Please input the size of DAG:";
  cin>>n;
  ofstream fout;
  fout.open("UC_out.txt");
  int a[2500];
  eug.n=n;
  for (int i=0;i<n;i++) {
    a[i]=i;
    eug.p[i]=i;
  }
  eug.m=n;
  //cout<<eug.m<<endl;
  eug.construct(n,a);
  eug.output(&fout);
  //cout<<"re18:"<<re18<<";  "<<"re14:"<<re14<<";  "<<"re10:"<<re10<<";  "<<"re3:"<<re3<<endl;
  return 0;
} 
