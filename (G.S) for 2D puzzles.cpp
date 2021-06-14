#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define test int t; cin>>t; while(t--)
#define low_bo(a, x) ((int)(lower_bound(a.begin(), a.end(), x) - a.begin()))
#define up_bo(a, x) ((int)(upper_bound(a.begin(), a.end(), x) - a.begin()))
#define MAX 1000001
#define mod 1000000007
#define endl "\n"
#define prq priority_queue

using namespace std;
ll fexp(long long a, long long b) {long long res = 1;while (b > 0) {if (b & 1)res = ((res%mod) * (a%mod))%mod;a = ((a%mod) * (a%mod))%mod;b = ((b%mod)>>1)%mod;}return res;}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll inverse(ll a, ll p){return fexp(a, p-2);}
bool IsVowel(char ch){return (ch=='A'||ch=='E'||ch=='I'||ch =='O'||ch=='U'||ch=='Y'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y');}//included Y


int main(){
	test{
int n,m,flag=0,indxw=-1,indyw=-1;cin>>n>>m;
	char a[n][m],b[n][m],res;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='W'&&flag==0){
				//finding the index and storing that char which came first.
				indxw=j;
				indyw=i;
				flag=1;
				res='W';
			}
			else if(a[i][j]=='R'&&flag==0){
				indxw=j;indyw=i;
				flag=1;
				res='R';
			}
		}
	}
	char strt,a1,a2;
	if((indxw%2==0&&indyw%2==0)||((indxw&1)&&(indyw&1))){
		//Note the position of first element is decided by the x,y index of the first occurance of 'W' or 'R';
		//so if x,y both are even then the chracter will play as a[0][0] or starting element 
		//OR
		//if x,y both are odd, then that charceter will play as a[0][0] or starting element
		a1=res;
		}
		else a1=(res=='R')?'W':'R';
		a2=(a1=='R')?'W':'R';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i][j]=(i&1)?(((j&1)==1)?a1:a2):(((j&1)==1)?a2:a1);
			/*
			i(even) j(even) -> a1(starter)
			i(even) j(odd)  -> a2
			i(odd)  j(even) -> a2
			i(odd)  j(odd)  -> a1
			*/
		}
	}
	int d=0;
	char c[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			 if((a[i][j]=='R'&&b[i][j]!='R')||(a[i][j]=='W'&&b[i][j]!='W')){
				cout<<"NO\n";
				d=1;
				break;}
				else c[i][j]=b[i][j]; 
		}if(d==1)break;
	}
		if(d==1){continue;}
		cout<<"YES\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<c[i][j];
			}cout<<endl;
		}
	}
return 0;
}
