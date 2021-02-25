#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct status{
	int stat;	//0=WA 1=AC 2=TLE
};

inline void color(short x){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void cac(int ac,int al){
	double perc=ac*100.0/al;
	if(perc<=40)color(12);
	if(perc>=80)color(10);
	if(40<perc&&perc<80)color(14);
}
int main(){
	
	//////	Definition
	int cnt,cAC;
	int cMS,cS,cMIN,cH;
	int _h,_min,_sec,_ms;
	char tmp[1000],nme[1000],tnme[1000],ext[1000];
	SYSTEMTIME STime1,STime2;
	bool isinname;
	
	//////	Initialization
	memset(tmp,0,sizeof(tmp));
	memset(tmp,0,sizeof(nme));
	memset(tmp,0,sizeof(tnme));
	
	cnt=0,cAC=0;
	cMS=0,cS=0,cMIN=0,cH=0;
	_h=0,_min=0,_sec=0,_ms=0;
	
	isinname=false;
	//	true:  abcd1.in, abcd2.in, ...
	//	false: 1.in, 2.in, ...
	//////	
	color(7);
	cerr<<"Please Enter The Name Of Your Program.\n\ne.g. ";
	color(14);cerr<<"sequence";color(7);
	cerr<<" (using sequence.exe)\n\n>> ";
	color(14);scanf("%s",tnme);color(7);
	
	cerr<<"Please Enter The Range Of The Standard Input.\n\ne.g. ";
	color(14);cerr<<"10";color(7);
	cerr<<" (using 1.in, 2.in, ..., 10.in)\n\n>> ";
	color(14);scanf("%d",&cnt);color(7);
	
	cerr<<"Please Enter The Extension Name Of The Standard Output.\n\ne.g. ";
	color(14);cerr<<"ans";color(7);
	cerr<<" (using 1.ans, 2.ans, ..., 10.ans as the correct answer)\n\n>> ";
	color(14);scanf("%s",ext);color(7);
	
	for(int i=1;i<=cnt;i++){
		
		strcpy(nme,tnme);
		
		stringstream s;				// int 123-> string "123"
		s.str("");s<<i;s>>tmp;
		
		
	//	if(isinname){strcat(nme,tnme);}
		
		strcat(nme,".exe <");if(isinname){strcat(nme,tnme);}strcat(nme,tmp);strcat(nme,".in >");if(isinname){strcat(nme,tnme);}strcat(nme,tmp);strcat(nme,".JudgeOut ");	// *.exe <#.in >#.JudgeOut
		
		GetLocalTime(&STime1);
		
		system(nme);
		
		GetLocalTime(&STime2);//cout<<nme;
		
		strcpy(nme,"fc ");if(isinname){strcat(nme,tnme);}strcat(nme,tmp);strcat(nme,".JudgeOut ");if(isinname){strcat(nme,tnme);}strcat(nme,tmp);strcat(nme,".");strcat(nme,ext);		// fc *.JudgeOut *.xxx	
		_h=STime2.wHour-STime1.wHour;
		_min=STime2.wMinute-STime1.wMinute;
		_sec=STime2.wSecond-STime1.wSecond;
		_ms=STime2.wMilliseconds-STime1.wMilliseconds;
		if(_ms<0)_sec--,_ms+=1000;
		if(_sec<0)_min--,_sec+=60;
		if(_min<0)_h--,_min+=60;
		
		
		if(!system(nme)){
			if(_h==0&&_min==0&&_sec==0){
				cAC++;
				
				color(10);	cerr<<" AC      ";
				color(7);	cerr<<" with "<<_h<<" h "<<_min<<" min "<<_sec<<" s "<<_ms<<" ms\n";	
				cH+=_h;	cMIN+=_min;	cS+=_sec;	cMS+=_ms;
				if(cMS>=1000){cS+=cMS/1000;cMS%=1000;};	if(cS>=60){cMIN+=cS/60;cS%=60;};	if(cMIN>=60){cH+=cMIN/60;cMIN%=60;};
			}else{
				color(9);	cerr<<" TLE ";
				color(10);	cerr<<"(AC)";
				color(9);	cerr<<"";
				color(7);	cerr<<" with "<<_h<<" h "<<_min<<" min "<<_sec<<" s "<<_ms<<" ms\n";
			}
		}else{
			if(_h==0&&_min==0&&_sec==0){
				color(12);	cerr<<" WA      ";
				color(7);	cerr<<" with "<<_h<<" h "<<_min<<" min "<<_sec<<" s "<<_ms<<" ms\n";
			}else{
				color(9);	cerr<<" TLE ";
				color(12);	cerr<<"(WA)";
				color(9);	cerr<<"";
				color(7);	cerr<<" with "<<_h<<" h "<<_min<<" min "<<_sec<<" s "<<_ms<<" ms\n";
			}
		}
	}
	
	
	cerr<<"\n\nTest Finished.\n\n"<<" AC: ";
	cac(cAC,cnt);cerr<<cAC<<"/"<<cnt;color(7);
	cerr<<"    in "<<cH<<" h "<<cMIN<<" min "<<cS<<" s "<<cMS<<" ms\n"<<"\nEnter \"0\" To Exit . . . \n";
	
	
	while(getchar()!='0');
	return 0;
}
