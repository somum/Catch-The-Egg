/*
	author: somum
	
*/
# include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/
int i=66,y=250,x=83,p,flag=0;
int menu=0;
char string1[1000],string2[1000],string3[1000],string4[1000];
void rrandom1(),level1(),level2(),rrandom2();
int score=0,level=1;
int timer,mode=0,life=3;
int bx,by;
int timer2,name_box_col1=100,name_box_col2=100,name_box_col3=100;
char tempName[10000];int count,playerNum,start,namelen;

struct playernamescore{
char name[500];
int score;
}player[1000000],temp;

void highscorePage()
{
	FILE *fp,*fp1;
	int i,y=300,val;
	char name[100],score[100];
	iShowBMP(0,0,"highscore.bmp");
	
	fp=fopen("finalscore.txt","r");

		iSetColor(255,255,255);
		fp1=fopen("playerNumber.txt","r");
		fscanf(fp1,"%d",&playerNum);
		fclose(fp1);
		if(playerNum>5)
		{
			for(i=0;i<5;i++)
			{
				
					fscanf(fp,"%s %d",&name,&val);
					sprintf(score,"%d",val);
					iText(50,y,name,GLUT_BITMAP_TIMES_ROMAN_24);
					iText(200,y,score,GLUT_BITMAP_TIMES_ROMAN_24);
					y-=50;
				
			}
		}
		else
		{
			for(i=0;i<playerNum;i++)
			{
					fscanf(fp,"%s %d",&name,&val);
					sprintf(score,"%d",val);
					iText(50,y,name,GLUT_BITMAP_TIMES_ROMAN_24);
					iText(200,y,score,GLUT_BITMAP_TIMES_ROMAN_24);
					y-=50;
				//}
			}
		}
	//}
	fclose(fp);
}

void nameBox()
{
	iSetColor(name_box_col1,name_box_col2,name_box_col3);
	iText(71,96,"Enter Your Name",GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(40,50,300,30);
	iSetColor(100,100,100);
	iText(40, 35, "Click to activate the box, enter to finish.");
}

void iDraw()
{
	iClear();
	if(menu==0){
	iShowBMP(0,0,"home.bmp");
	if(bx>=144 && bx<=261 && by>=16 && by<=77)
		menu=1;
	if(bx>=47 && bx<=131 && by>=9 && by<=50)
		iShowBMP(0,0,"help.bmp");
	if(bx>=265 && bx<=360 && by>=5 && by<=54)
       highscorePage();
	}
	if(menu==1){
	level1();
	}
	if(menu==3){
	level2();
	}

	if(menu==2){
		
		iShowBMP(5,5,"gameover.bmp");
		nameBox();
		if(mode == 1)
		{
			iSetColor(255, 255, 255);
			iText(52,67,tempName);
		}
	}
}




void writeAfterSort(int n)
{

	int i;
	FILE *fp;
	fp=fopen("finalscore.txt","w");

	if(n>5){
	
		for(i=0;i<5;i++){
		
			fprintf(fp,"%s\t%d\n",player[i].name,player[i].score);
		}

	}

	else{
	
		for(i=0;i<n;i++){
		
			fprintf(fp,"%s\t%d\n",player[i].name,player[i].score);
		}
	}
	fclose(fp);
}



void scoreSort(){

	FILE *fp;
	int i=0,j,k;
	fp=fopen("playerNameList.txt","r");
	while((fscanf(fp,"%s %d",&player[i].name,&player[i].score))!=EOF)
		i++;
	fclose(fp);
    fp=fopen("playerNumber.txt","w");
	   fprintf(fp,"%d",i);

    fclose(fp);

	for(j=0;j<(i-1);j++)
	{
	
		for(k=j+1;k<i;k++){
		
			if (player[k].score>player[j].score){
			
				temp=player[j];
				player[j]=player[k];
				player[k]=temp;
			}
		}
	}

	writeAfterSort(i);
}


void move1(){
    if(y>100){
	  y-=2;
   }
    if(x>=i && x<=i+65 && y>120 && y<125)
	{ 
		y=300;
	  rrandom1();
	  
	  score+=5;
	  if(score==10){
		  iPauseTimer(timer);
		  iResumeTimer(timer2);
	    menu=3;
		level+=1;
	  }
	  
   }
    if(y<120)
   {
	   if(life<=0){menu=2;}
	   else{life--;
	   y=300;
	   rrandom1();}
	   
   }
}
void move2(){
    if(y>100){
	  y-=3;
   }
    if(x>=i && x<=i+65 && y>120 && y<125)
	{ 
		y=300;
	  rrandom2();
	  score+=5;
   }
    if(y<120)
   {
	 if(life<=0){menu=2;}
	   else{life--;
	   y=300;
	   rrandom2();}
   }
}

void rrandom2(){

	
	p=rand() % 4;

	if (p==0) x =85;
	else if (p==1) x = 180;
	else if (p==2) x = 280;
	else if (p==3) x = 330;


}
void rrandom1(){
	p=rand() % 3; 
	if (p==0) x =85;
	else if (p==1) x = 180;
	else if (p==2) x = 280;

}
void level1(){
iResumeTimer(timer);
    iShowBMP(0,0,"background.bmp");
	iSetColor(0,0,225);
	iSetColor(0,0,225);
    iText(760,550,string1);
	iShowBMPWOBG(50,330,"duck.bmp");
	iShowBMPWOBG(150,330,"duck.bmp");	
	iShowBMPWOBG(250,330,"duck.bmp");
	iShowBMPWOBG(x,y,"egg.bmp");
	iShowBMPWOBG(i,83,"bucket.bmp");
	iText(250,9,string1,GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(string1,"Score: %d",score);
	iText(30,9,string2,GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(string2,"Level-%d",level);
	iText(150,9,string4,GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(string4,"Life-%d",life);
}
void level2(){
iResumeTimer(timer);
    iShowBMP(0,0,"background.bmp");
	iSetColor(0,0,225);
	iSetColor(0,0,225);
    iText(760,550,string1);
	iShowBMPWOBG(50,330,"duck.bmp");
	iShowBMPWOBG(150,330,"duck.bmp");	
	iShowBMPWOBG(250,330,"duck.bmp");
	iShowBMPWOBG(320,330,"duck.bmp");
	iShowBMPWOBG(x,y,"egg.bmp");
	iShowBMPWOBG(i,83,"bucket.bmp");
	iText(250,9,string1,GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(string1,"Score: %d",score);
	iText(30,9,string3,GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(string3,"Level-%d",level);
	iText(150,9,string4,GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf(string4,"Life-%d",life);
}
/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	
	printf("x=%d \n y=%d",mx,my);
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		bx=mx;
	    by=my;
		if(mx>=38 && mx<=338 && my>=51 && my<=83 && menu==2)
			{
				mode=1;
				name_box_col1=255; name_box_col2=255; name_box_col3=255;
			}


		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		
		}

	}

/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	FILE *fp;

	if(menu==2)
	{
	
	   if(key=='\r')
	   {
		   fp =fopen("playerNameList.txt","a");
		       fprintf(fp,"%s\t%d\n",tempName,score);
           fclose(fp);
		   playerNum++;
		   start=0;
		   scoreSort();
	   }
	
	   else  if(key==8){
	   namelen--;
	   tempName[namelen]=0;
	   
	   }
	   else {
	     
		   tempName[namelen]=key;
		   namelen++;
		
	   }


	}
	
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{   if(key==GLUT_KEY_RIGHT){i+=7;}
	if(key==GLUT_KEY_LEFT){i-=7;}

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}
//

int main()
{
	//place your own initialization codes here. 
	
	srand(1);
	timer=iSetTimer(1,move1);
	timer2=iSetTimer(100, move2);
	iPauseTimer(timer2);
    iPauseTimer(timer);
	iInitialize(400,400,"Catch The Egg");
	return 0;
}