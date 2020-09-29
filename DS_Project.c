#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX1 7
#define MAX2 13
#define MAX3 5
int ac[MAX2]={18,19,20,21,22,23,24,25,26,27,29,29,30},sel_m[MAX3];
char music[MAX3][100]={"song1","song2","song3","song4","song5"},gear[MAX1][50]={"Reverse","parcking","1","2","3","4","5"},song[MAX3][100];
int front_m=-1,front_ac=6,rear_g=1,count1=0,count2=0,count=-1,temp;
void gearup(){
	if(rear_g>=6)
	{
		printf("You are reched the maximum gear limit\n");
		printf("Current gear is : %s\n",gear[rear_g]);
	}
	else{
		if(rear_g==-1)
			rear_g=1;
		else
			rear_g++;
		printf("Current gear is : %s\n",gear[rear_g]);
}
	
}
void gearedown(){
	if(rear_g-1<0 )
	{
		printf("You can't dwon the gear as your car is in parcking mode or in reverse gear\n");
	}
	else{
		rear_g--;

	}
	printf("Current gear is : %s\n",gear[rear_g]);
}

void p_next(){

	if(count==MAX3-1 || count==-1)
		count=0;
	else
		count++;
	temp = sel_m[count]-1;
	printf("Current music : %s\n",music[temp]);
}

void p_pre(){
if(count==0 || count==-1)
		count=MAX3-1;
	else
		count--;
	temp = sel_m[count]-1;
printf("Current music : %s\n",music[temp]);
}


void music_next(){
	if(front_m==MAX3-1 || front_m==-1)
		front_m=0;
	else
		front_m++;
	printf("Current music : %s\n",music[front_m]);
}
void music_pre(){
	if(front_m==0 || front_m==-1)
		front_m=MAX3-1;
	else
		front_m--;
	printf("Current music : %s\n",music[front_m]);
}


void acup(){

	if(front_ac<MAX2-1)
		front_ac++;
	else
		printf("AC at hightest temprature");
	printf("Current AC temprature is : %d\n",ac[front_ac]);
}
void acdown(){
	if(front_ac==0)
		printf("This is the lowest temprature of AC\n");
	else
		front_ac--;

	printf("Current AC temprature is : %d\n",ac[front_ac]);
}

int music_i(){
	int sel;
	if(count2==MAX3){
		printf("Your storage is full\n1 add new song and delete last song\n(eg. If 5th is last song than 1st song going to delet)\n2 exit  \n");
		scanf("%d",&sel);
		if(sel==1)
		{
			count2=0;
			printf("Enter your song name : ");
			scanf("%s",&song);
			strcpy(music[count2],song);
			count2++;
		}
		else{
			return 0;
		}
	}
	else{
	printf("Enter your song name : ");
	scanf("%s",&song);
	printf("%d\n",count2 );
	strcpy(music[count2],song);
	count2++;
	
}
}



int m1(){
int chr1, chr2;

 	printf("\t\t\t\t+==================================================+\n");
 	printf("\t\t\t\t|Up and down arrow key for changing the gears      |\n");
 	printf("\t\t\t\t+--------------------------------------------------+\n");
	printf("\t\t\t\t|Right & left arrow key for changing song          |\n");
	printf("\t\t\t\t+--------------------------------------------------+\n");
 	printf("\t\t\t\t|PageUp & PageDown for changing the AC temprature  |\n");
 	printf("\t\t\t\t+==================================================+\n");
 c:chr1 = getch();
 if (chr1 == 0xE0) //to check scroll key interrupt
 {
  chr2 = getch();  //to read arrow key
  switch(chr2)
  {
case 72: gearup(); //up key
			goto c;
			break;
case 80: gearedown(); //down key
			goto c;
			break;
case 75: music_pre(); //left key
			goto c;
			break;
case 77: music_next();//right key 
			goto c;
			break;
case 73:acup();
			goto c;
			break;
case 81:acdown();
			goto c;
			break;
default:printf("Please enter a valid key\n");
			break;
  };
 }
 return 0;
}

int m2(){

int chr1, chr2;
	printf("\t\t\t\t+==================================================+\n");
	printf("\t\t\t\t|Right & left arrow key for changing song          |\n");
	printf("\t\t\t\t+--------------------------------------------------+\n");
 	printf("\t\t\t\t|PageUp & PageDown for changing the AC temprature  |\n");
 	printf("\t\t\t\t+==================================================+\n");
 a:chr1 = getch();
 if (chr1 == 0xE0) //to check scroll key interrupt
 {
  chr2 = getch();  //to read arrow key
  switch(chr2)
  {
case 75: 
if(count1==1)
	p_pre();
else
	music_pre();

			goto a;
			break;
case 77: 
if (count1==1)
	p_next();
else
	music_next();
			goto a;
			break;
case 73:acup();
			goto a;
			break;
case 81:acdown();
			goto a;
			break;
default:printf("Please enter a valid key\n");
			break;
  };
 }
 
 return 0;

}



int main(){
int sel,sel1;
  b:printf("\t\t\t\t\t\t+===================+\n");
    printf("\t\t\t\t\t\t|1 for start the car|\n");
    printf("\t\t\t\t\t\t+-------------------+\n");
	printf("\t\t\t\t\t\t|2 start the engine |\n");
	printf("\t\t\t\t\t\t+-------------------+\n");
	printf("\t\t\t\t\t\t|3 Exit             |\n");
	printf("\t\t\t\t\t\t+-------------------+\n");
	printf("\t\t\t\t\t\t|4 for stop the car |\n");
	printf("\t\t\t\t\t\t+-------------------+\n");
	printf("\t\t\t\t\t\t|5 Create Playlist  |\n");
	printf("\t\t\t\t\t\t+-------------------+\n");
	printf("\t\t\t\t\t\t|6 Set your songs   |\n");
	printf("\t\t\t\t\t\t+===================+\n");
scanf("%d",&sel);
switch(sel)
{
	case 1:
			m2();
			goto b;
			break;
	case 2:
			m1();
			goto b;
			break;
	case 3:

			return 0;
			break;
	case 4:
			rear_g=1;
			goto b;
			break;
	case 5:
			for (int i = 0; i < MAX3; i++)
			{

				e:printf("Enter music at %d position : ",i+1);
				scanf("%d",&sel_m[i]);
				if(sel_m[i]>5 || sel_m[i]<1)
				{
					printf("Try again...\n");
					goto e;
				}
				
			}
			count1=1;
			goto b;
			break;
	case 6:
			printf("How many songs you want to store : ");
			scanf("%d",&sel1);
			for(int i=0; i<sel1; i++)
				music_i();
			goto b;
			break;

	default:printf("Enter a valid number\n");
			break;


}
return sel;

}
