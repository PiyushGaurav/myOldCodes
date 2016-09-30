#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>

void player_move();
void computer_move();
int check_for_win(char);
void display();
int defend();
int make();

char p1[20],p2[20],p3[20],ch,p_sign,c_sign;
int data1[9],data[9],choice,turn=0,pos1,pos2,winner=0,sign,player,flag=0,i,j,k,play;



void main()
{
char p1[20],p2[20],ch, data1[9];
int turn,winner,sign,player,flag,i,j,k,pos;

int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TC\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      //exit(1); /* terminate with an error code */
   }

cleardevice();
setbkcolor(BLUE);
gotoxy(10,10);
printf("TIC-TAC-TOE (also known as Noughts and crosses or Xs and Os) is \n	a paper-and-pencil game for two players, X and O, who take turns \n	marking the spaces in a 3 X 3 grid. \n\n  1. It's a two player game so the program takes the name of two players and \n     assign O and X to the players. \n  2. Players enter their move turn by turn, into the box they choose. \n  3. The player who succeeds in placing three of their marks in a horizontal, \n     vertical, or diagonal row wins the game.\n\n\n\n		   press ANY KEY to play the game.....");
getch();

start:

while(1)
	{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	gotoxy(30,5);
	printf("TIC TAC TOE");
	gotoxy(25,6);
	printf("*******************");
	gotoxy(25,8);
	printf("1.Play with friend");
	gotoxy(25,10);
	printf("2.Play with Computer");
	gotoxy(25,12);
	printf("3.Exit");
	gotoxy(25,14);
	scanf("%d",&play);

		switch(play)
		{
		case 1:goto start1;break;
		case 2:goto start2;break;
		case 3:
			clrscr();
			cleardevice();
			setbkcolor(RED);
			gotoxy(25,20);
			printf("Thanks you for playing this game");
			gotoxy(30,23);
			printf("Coded by PIYUSH GAURAV");
			getch();
			closegraph();
			exit(0);
		default:goto start;
		}
	}
start1:
{


	cleardevice();
	setbkcolor(RED);
	gotoxy(30,5);
	printf("TIC TAC TOE");
	gotoxy(25,6);
	printf("*******************");
	gotoxy(25,8);
	printf("Enter Player 1 Name : ");
	gotoxy(47,8);
	scanf("%s",p1);
	gotoxy(25,10);
	printf("Enter Player 2 Name : ");
	gotoxy(47,10);
	scanf("%s",p2);

	s1:
	turn=0;flag=0;pos=0;winner=0;
	clrscr();
	cleardevice();
	setbkcolor(RED);
	for(i=0;i<9;i++)
	data1[i]=' ';
    while(turn<9)
    {
	clrscr();
	flag=0;
	cleardevice();
	setbkcolor(RED);
	line(100,200,400,200);
	line(100,300,400,300);
	line(200,100,200,400);
	line(300,100,300,400);
	outtextxy(200,10,"     TIC TAC TOE");
	outtextxy(200,20,"***********************");
	outtextxy(200,40,"Unregistered Vesion 1.0");
	outtextxy(80,70,"press 0 to exit");

	if(data1[0]=='X'){line(110,110,190,190);line(110,190,190,110);}
	else if(data1[0]=='O')circle(150,150,40);

	if(data1[1]=='X'){line(210,110,290,190);line(210,190,290,110);}
	else if(data1[1]=='O')circle(250,150,40);

	if(data1[2]=='X'){line(310,110,390,190);line(310,190,390,110);}
	else if(data1[2]=='O')circle(350,150,40);

	if(data1[3]=='X'){line(110,210,190,290);line(110,290,190,210);}
	else if(data1[3]=='O')circle(150,250,40);

	if(data1[4]=='X'){line(210,210,290,290);line(210,290,290,210);}
	else if(data1[4]=='O')circle(250,250,40);

	if(data1[5]=='X'){line(310,210,390,290);line(310,290,390,210);}
	else if(data1[5]=='O')circle(350,250,40);

	if(data1[6]=='X'){line(110,310,190,390);line(110,390,190,310);}
	else if(data1[6]=='O')circle(150,350,40);

	if(data1[7]=='X'){line(210,310,290,390);line(210,390,290,310);}
	else if	(data1[7]=='O')circle(250,350,40);

	if(data1[8]=='X'){line(310,310,390,390);line(310,390,390,310);}
	else if(data1[8]=='O')circle(350,350,40);

	outtextxy(410,110,"(X) Player 1 : ");
	outtextxy(550,110,p1);
	outtextxy(410,130,"(O) Player 2 : ");
	outtextxy(550,130,p2);
	if(turn%2==0)
	{
		sign='X';
		player=1;
	}
	else
	{
		sign='O';
		player=2;
	}
	gotoxy(50,15);
	printf("MOVE FOR PLAYER %d  (1-9)",player);
	gotoxy(50,16);
	scanf("%d",&pos1);
	if(pos1==0)
	exit(0);
	else if(pos1<1||pos1>9&&pos1!=0)
	{       gotoxy(50,17);
		printf("INVALID ! ENTER POSITION 1 - 9 ONLY");
		sleep(1);
		continue;
	}
	else if(data1[pos1-1]=='X'||data1[pos1-1]=='O')
	{
		gotoxy(50,17);
		printf("POSITION ALREADY OCCUPIED !!");
		sleep(1);
		//getch();
		continue;
	}
	data1[pos1-1]=sign;
	turn++;

	for(i=0;i<9;i++)
	{
		if(i%3==0)
		flag=0;

		if(data1[i]==sign)
		flag++;

		if(flag==3)
		{
			winner=1;
			goto win;
		}
	}
	flag=0;
	for(i=0;i<3;i++)
	{
		for(k=i;k<=i+6;k=k+3)
		{
			if(data1[k]==sign)
			flag++;
		}
		if(flag==3)
		{
			winner=1;
			goto win;
		}
		flag=0;
	}
	if((data1[0]==sign&&data1[4]==sign&&data1[8]==sign)||(data1[2]==sign&&data1[4]==sign&&data1[6]==sign))
	{
		winner=1;
		goto win;
	}
    }
	win:
	clrscr();
	cleardevice();
	setbkcolor(RED);
	line(100,200,400,200);
	line(100,300,400,300);
	line(200,100,200,400);
	line(300,100,300,400);


	outtextxy(200,10,"     TIC TAC TOE");
	outtextxy(200,20,"***********************");
	outtextxy(200,40,"Unregistered Vesion 1.0");
	outtextxy(80,70,"press 0 to exit");

	if(data1[0]=='X'){line(110,110,190,190);line(110,190,190,110);}
	else if(data1[0]=='O')circle(150,150,40);

	if(data1[1]=='X'){line(210,110,290,190);line(210,190,290,110);}
	else if(data1[1]=='O')circle(250,150,40);

	if(data1[2]=='X'){line(310,110,390,190);line(310,190,390,110);}
	else if(data1[2]=='O')circle(350,150,40);

	if(data1[3]=='X'){line(110,210,190,290);line(110,290,190,210);}
	else if(data1[3]=='O')circle(150,250,40);

	if(data1[4]=='X'){line(210,210,290,290);line(210,290,290,210);}
	else if(data1[4]=='O')circle(250,250,40);

	if(data1[5]=='X'){line(310,210,390,290);line(310,290,390,210);}
	else if(data1[5]=='O')circle(350,250,40);

	if(data1[6]=='X'){line(110,310,190,390);line(110,390,190,310);}
	else if(data1[6]=='O')circle(150,350,40);

	if(data1[7]=='X'){line(210,310,290,390);line(210,390,290,310);}
	else if	(data1[7]=='O')circle(250,350,40);

	if(data1[8]=='X'){line(310,310,390,390);line(310,390,390,310);}
	else if(data1[8]=='O')circle(350,350,40);


	outtextxy(410,110,"(X) Player 1 : ");
	outtextxy(550,110,p1);
	outtextxy(410,130,"(O) Player 2 : ");
	outtextxy(550,130,p2);

	if(winner)
	{
		if(player == 1)
		{
		gotoxy(50,23);
		printf("%s won the game",p1);
		}
		else
		{
		gotoxy(50,23);
		printf("%s won the game",p2);
		}
	}
	else
	{
		gotoxy(50,23);
		printf("Match draw ....Best of Luck for both :\n");
	}
	gotoxy(50,24);
	printf("PLAY AGAIN...press (Y/N)");
	ch=getch();
	if(ch=='y'|| ch=='Y')
	{goto s1;}
	else
	{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	gotoxy(25,20);
	printf("Thanks you for playing this game");
	gotoxy(30,23);
	printf("Coded by PIYUSH GAURAV");
	getch();
	closegraph();
	}

}

start2:
{
	for(i=0;i<9;i++)
	data[i]=' ';
	clrscr();
	cleardevice();
	setbkcolor(RED);
	gotoxy(30,5);
	printf("TIC TAC TOE");
	gotoxy(25,6);
	printf("*******************");
	gotoxy(25,8);
	printf("Enter Your Name : ");
	gotoxy(47,8);
	scanf("%s",p3);
	gotoxy(27,12);
	printf("1. Play with X");
	gotoxy(27,13);
	printf("2. Play with O");
	gotoxy(27,14);
	printf("3. Exit");
	gotoxy(37,15);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			p_sign='X';
			c_sign='O';
			display();
			player_move();
			break;
		case 2:
			p_sign='O';
			c_sign='X';
			computer_move();
			break;
		case 3:exit(1);
		default:printf("Invalid choice !!");goto start2;
	}

	display();
	}
}



void player_move()
{
	if(turn>8)
	{
	display();
	gotoxy(60,23);
	printf("GMAE DRWA");
	getch();
	exit(0);
	}

	display();
	gotoxy(55,15);
	printf("Enter your move (1-9): ");
	gotoxy(50,16);
	scanf("%d",&pos2);
	if(pos2==0)
	exit(0);
	else if(data[pos2-1]!= ' ')
	{
	display();
	gotoxy(55,18);
	printf("Invalid move, try again.\n");
	player_move();
	}
	else data[pos2-1] = p_sign;


	if(check_for_win(p_sign))
	{
	display();
	gotoxy(60,23);
	printf("You win !!");
	getch();
	exit(0);
	}
	else
	{
	turn++;
	computer_move();
	}
}



void computer_move(void)
{
	if(turn>8)
	{
	display();
	gotoxy(60,23);
	printf("GMAE DRWA");
	getch();
	exit(0);
	}

	if(defend())
	 data[defend()] = c_sign;
	else
	 data[make()]=c_sign;
	display();

	if(check_for_win(c_sign))
	{
	display();
	gotoxy(60,23);
	printf("Computer win !!\n");
	getch();
	exit(0);
	}
	else
	{
	turn++;
	player_move();
	}

}


int check_for_win(char sign)
{
flag=0;
for(i=0;i<9;i++)
	{
		if(i%3==0)
		flag=0;

		if(data[i]==sign)
		flag++;

		if(flag==3)
		{
			return 1;
		}
	}
	flag=0;
	for(i=0;i<3;i++)
	{
		for(k=i;k<=i+6;k=k+3)
		{
			if(data[k]==sign)
			flag++;
		}
		if(flag==3)
		{
			return 1;
		}
		flag=0;
	}
	if((data[0]==sign&&data[4]==sign&&data[8]==sign)||(data[2]==sign&&data[4]==sign&&data[6]==sign))
	{
		return 1;
	}
	else return 0;

}

int defend()
{
	if(data[0]=='X'&&data[1]=='X'&&data[2]==' ')return 2;
	if(data[0]=='X'&&data[1]==' '&&data[2]=='X')return 1;
	if(data[0]==' '&&data[1]=='X'&&data[2]=='X')return 0;

	if(data[3]=='X'&&data[4]=='X'&&data[5]==' ')return 5;
	if(data[3]=='X'&&data[4]==' '&&data[5]=='X')return 4;
	if(data[3]==' '&&data[4]=='X'&&data[5]=='X')return 3;

	if(data[6]=='X'&&data[7]=='X'&&data[8]==' ')return 8;
	if(data[6]=='X'&&data[7]==' '&&data[8]=='X')return 7;
	if(data[6]==' '&&data[7]=='X'&&data[8]=='X')return 6;

	if(data[0]=='X'&&data[3]=='X'&&data[6]==' ')return 6;
	if(data[0]=='X'&&data[3]==' '&&data[6]=='X')return 3;
	if(data[0]==' '&&data[3]=='X'&&data[6]=='X')return 0;

	if(data[1]=='X'&&data[4]=='X'&&data[7]==' ')return 7;
	if(data[1]=='X'&&data[4]==' '&&data[7]=='X')return 4;
	if(data[1]==' '&&data[4]=='X'&&data[7]=='X')return 1;

	if(data[2]=='X'&&data[5]=='X'&&data[8]==' ')return 8;
	if(data[2]=='X'&&data[5]==' '&&data[8]=='X')return 5;
	if(data[2]==' '&&data[5]=='X'&&data[8]=='X')return 2;

	if(data[0]=='X'&&data[4]=='X'&&data[8]==' ')return 8;
	if(data[0]=='X'&&data[4]==' '&&data[8]=='X')return 4;
	if(data[0]==' '&&data[4]=='X'&&data[8]=='X')return 0;

	if(data[2]=='X'&&data[4]=='X'&&data[6]==' ')return 6;
	if(data[2]=='X'&&data[4]==' '&&data[6]=='X')return 4;
	if(data[2]==' '&&data[4]=='X'&&data[6]=='X')return 2;

	return 0;
}

int make()
{
    if(data[4] == ' ')
	return 4;
    if(data[1] == ' ')
	return 1;
    if(data[7] == ' ')
	return 7;
    if(data[3] == ' ')
	return 3;
    if(data[5] == ' ')
	return 5;
    if(data[2] == ' ')
	return 2;
    if(data[6] == ' ')
	return 6;
    if(data[0] == ' ')
	return 0;
    if(data[8] == ' ')
	return 8;
}

void display()
{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	line(100,200,400,200);
	line(100,300,400,300);
	line(200,100,200,400);
	line(300,100,300,400);
	outtextxy(200,10,"     TIC TAC TOE");
	outtextxy(200,20,"***********************");
	outtextxy(200,40,"Unregistered Vesion 1.0");
	outtextxy(80,70,"press 0 to exit");

	if(data[0]=='X'){line(110,110,190,190);line(110,190,190,110);}
	else if(data[0]=='O')circle(150,150,40);

	if(data[1]=='X'){line(210,110,290,190);line(210,190,290,110);}
	else if(data[1]=='O')circle(250,150,40);

	if(data[2]=='X'){line(310,110,390,190);line(310,190,390,110);}
	else if(data[2]=='O')circle(350,150,40);

	if(data[3]=='X'){line(110,210,190,290);line(110,290,190,210);}
	else if(data[3]=='O')circle(150,250,40);

	if(data[4]=='X'){line(210,210,290,290);line(210,290,290,210);}
	else if(data[4]=='O')circle(250,250,40);

	if(data[5]=='X'){line(310,210,390,290);line(310,290,390,210);}
	else if(data[5]=='O')circle(350,250,40);

	if(data[6]=='X'){line(110,310,190,390);line(110,390,190,310);}
	else if(data[6]=='O')circle(150,350,40);

	if(data[7]=='X'){line(210,310,290,390);line(210,390,290,310);}
	else if(data[7]=='O')circle(250,350,40);

	if(data[8]=='X'){line(310,310,390,390);line(310,390,390,310);}
	else if(data[8]=='O')circle(350,350,40);

	outtextxy(420,115,"Player VS  Computer");

}

