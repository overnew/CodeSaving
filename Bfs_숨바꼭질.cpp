//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n,k;
int short_cut[100000];

int HideSeekBFS(){
	queue<int> q;
	short_cut[n] = 0; //수빈이 위치 0부터 시작
	q.push(n);
	
	if(n==k)
		return 0;
	int now, temp;
	
	while(!q.empty()){
		now =q.front();
		q.pop();
		
		for(int i=0; i<3 ; ++i){
			if(i==0)
				temp = now +1;
			else if(i ==1)
				temp = now -1;
			else 
				temp = now +now;
			
			if(0<=temp && temp <= 100000) //범위확인
				if(short_cut[temp] == -1){ //방문 x의 경우
					q.push(temp);
					short_cut[temp] = short_cut[now] +1;
					
					if(temp == k)
						return short_cut[temp];
				}
			
		}
		
	}
	
}


int main(){
	cin>>n>>k;
	memset(short_cut, -1, sizeof(short_cut));
	
	cout<<HideSeekBFS()<<'\n';
	
	return 0;
}
