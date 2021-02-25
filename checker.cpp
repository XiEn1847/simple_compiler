#include<bits/stdc++.h>
/*  */
#include<windows.h>
using namespace std;
char tmp[1000],nme[1000],tnme[1000];
void color(short x){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void cac(int ac,int al){
	double perc=ac*100.0/al;
	if(perc<=40)color(12);
	if(perc>=80)color(10);
	if(40<perc&&perc<80)color(14);
}
int main(){
	SYSTEMTIME STime1,STime2;
	int cnt;
	int cAC=0;
	int cMS=0,cS=0,cMIN=0,cH=0;
	int _h,_min,_sec,_ms;
	
	cerr<<"Please Enter The Name Of Your Program.\n\n e.g. sequence (if you're using sequence.exe)\n\n>>";
	scanf("%s",tnme);
	cerr<<"Please Enter The Range Of Data.\n\n e.g. 10 (if you're using 1.in, 2.in, ..., 10.in)\n\n>>";
	scanf("%d",&cnt);
	
	for(int i=1;i<=cnt;i++){
		
		strcpy(nme,tnme);	// int 123-> string "123"
		stringstream s;
		s.str("");s<<i;s>>tmp;
		
		strcat(nme,".exe <");strcat(nme,tmp);strcat(nme,".in >");strcat(nme,tmp);strcat(nme,".out");	// *.exe <#.in >#.out
		GetLocalTime(&STime1);system(nme);GetLocalTime(&STime2);
		strcpy(nme,"fc ");strcat(nme,tmp);strcat(nme,".out ");strcat(nme,tmp);strcat(nme,".ans");		// fc *.out *.ans
		
		_h=STime2.wHour-STime1.wHour;
		_min=STime2.wMinute-STime1.wMinute;
		_sec=STime2.wSecond-STime1.wSecond;
		_ms=STime2.wMilliseconds-STime1.wMilliseconds;
		if(_ms<0)_sec--,_ms+=1000;
		if(_sec<0)_min--,_sec+=60;
		if(_min<0)_h--,_min+=60;
			
		if(!system(nme)){
			if(_h==0&&_min==0&&_sec==0){
				color(10);cerr<<" AC";
				color(7);cerr<<" with ";
				cAC++;
				cerr<<_h<<" h "<<_min<<" min "<<_sec<<" s "<<_ms<<" ms\n";	
				cH+=_h;	cMIN+=_min;	cS+=_sec;	cMS+=_ms;
				if(cMS>=1000){cS+=cMS/1000;cMS%=1000;};	if(cS>=60){cMIN+=cS/60;cS%=60;};	if(cMIN>=60){cH+=cMIN/60;cMIN%=60;};
			}else{
				color(9);cerr<<" TLE";
				color(7);cerr<<" with ";
				cerr<<_h<<" h "<<_min<<" min "<<_sec<<" s "<<_ms<<" ms\n";
			}
		}else{
			color(12);cerr<<" WA";
			color(7);cerr<<" with ";
			cerr<<_h<<" h "<<_min<<" min "<<_sec<<" s "<<_ms<<" ms\n";
		}
	}
	cerr<<"\n\nTest Finished.\n\n"<<" AC: ";
	cac(cAC,cnt);cerr<<cAC<<"/"<<cnt;color(7);
	cerr<<"    in "<<cH<<" h "<<cMIN<<" min "<<cS<<" s "<<cMS<<" ms\n"<<"\nPress Enter To Exit . . . \n";
	while(1);
}
