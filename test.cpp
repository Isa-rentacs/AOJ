#include <iostream>
#include <cstdio>
#include <cstring>

char MAP[104][104];
int nx,ny,vx=0,vy=-1;
void rotate(){ //右回りに回転する
	int tx=vx,ty=vy;
	vx=-ty;vy=tx;
}
int main(){
	int s; //マップの広さ
	int n; //処理する個数
	int t; //終了判定用
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s);
		memset(MAP,'#',104*104);
		for(int x=1;x<1+s+2;x++){
			for(int y=1;y<1+s+2;y++){
				MAP[x][y]=' ';
			}
		}
		nx=2,ny=s+1;t=0;vx=0;vy=-1;
		while(1){
			MAP[nx][ny]='#';
			if(MAP[nx+vx*2][ny+vy*2]=='#'){
				if(t>0) break;
				t=2;
				rotate();
			} else {
				t--;
				nx+=vx;ny+=vy;
			}
		}
		//表示
		if(i!=0) puts("");
		for(int y=2;y<1+s+1;y++){
			for(int x=2;x<1+s+1;x++){
				printf("%c",MAP[x][y]);
			}
			puts("");
		}
	}
	return 0;
}
