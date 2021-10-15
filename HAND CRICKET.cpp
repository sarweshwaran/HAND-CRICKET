#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

//class cricket to controll entier game
class cricket
{
	int pscore=0, cscore=0, p=0, com=0, count=0;
	
	public:
		
		void display();		//to display score board and last move
		
		void winchk();		//to check the victor of the player and print victory message
		
		void toss();		//to initiallize the game
		
		void player();		//used while user is batting 
		
		void computer();	//used while player is bowling
		
		void rules();		//to print the instructions
};

//defining member functions


void cricket::rules()
{
	system("cls");
	cout<<"\nINTRUCTIONS :\n1. THERE ARE MAXIMUM 20 BALLS PER TEAM.\n2. SCORE OF EACH TEAM WILL APPEAR AT THE TOP OF THE SCREEN.\n3. YOU CAN ONLY ENTER NUMBER BETWEEN 1 TO 6\nELSE THE BALL IS CONSIDERED AS INVALID.\n4. STROKE IS NOT ALLOWED.\n5. IF BOTH OF YOUR NUMBERS ARE SAME THEN ITS MEAN THAT IT IS A WICKET.\n\n\t*** ALL THE BEST *** \n\nPRESS ENTER TO CONTINUE";
	cin.ignore();
	cin.get();
}

void cricket::toss()
{
	char c;
	int n, flag =0, m =(rand()%6+1);		//m = choosing a random number 
	
	// printing title 
	
	cout<<"\n\t#####################################\n\t\tHAND CRICKET LEAGUE\n\t\tWELCOME TO THE HCL\n\t#####################################\n";
	
	// making toss 
	
	cout<<"\n\nCHOOSE ODD OR EVEN (ODD=o / EVEN=e) :";		//asking user to choose odd or even to toss
	cin>>c;
	
	cout<<"\n\n ENTER YOUR NUMBER (1-6):";					//getting user's number for the toss
	cin>>n;
	
	system("cls");
	
	cout<<"\n\t#####################################\n\t\tHAND CRICKET LEAGUE\n\t\tWELCOME TO THE HCL\n\t#####################################\n";
	
	
	cout<<"\nYOU : "<<n<<"\t OPPONENT : "<<m;				//printing the move made by both i.e, user and computer
	
	
	//checking for who won the toss
	
	if((n+m)%2==0)
	{
		if(c=='e')
		{
			cout<<"\n\n\t\t**** YOU WON THE TOSS ****"<<endl;
			flag=1;
		}
		else
		{
			cout<<"\n\n\t\t---- OPPONENT WON THE TOSS ----"<<endl;
		}
		sleep(3);
	}
	
	else
	{
		if(c!='e')
		{
			cout<<"\n\n\t\t**** YOU WON THE TOSS ****"<<endl;
			flag=1;
		}
		else
		{
			cout<<"\n\n\t\t---- OPPONENT WON THE TOSS ----"<<endl;
		}
		sleep(3);
	}
	
	rules();		//printing instruction
	
	
	if(flag)		//if user won the toss
	{
		char b;
		
		cout<<"\n\nCHOOSE TO BAT OR BOWL (BAT=t / BOWL=l) : ";		//asking the user to choose whether he/she like to bat or bowl
		cin>>b;
		
		if(b=='t')
		{
			player();		//if user choose to bat 
		}
		
		else
		{
			computer();		//if user choose to bowl
		}
	}
	
	else					//if user lost tthe toss
	{
		
		cout<<"\n\nOPPONENT CHOOSE TO BOWL"<<endl;		//making user to bat first by default
		sleep(3);
		
		player();
	}
}



void cricket::player()
{
	int j=20;		//as total balls per team is limited to 20
	
	count++;		//to check whether it is first batting or not
	
	while(j--)
	{
		display();
		
		com=(rand()%6)+1;		//picking random number to be made from bowling side
		
		if(count==2)
		{
			cout<<"\nTARGET : "<<cscore+1<<endl;		//printing target
		}
		cout<<"\nBALLS LEFT : "<<j+1<<"\n\nYOU ARE BATING \n\nENTER YOUR RUN : ";	//to display balls left and get the number from the user to made from batting side
		cin>>p;
		
		while(p>6 || p<1)		//while the entered value is invalid
		{
			cout<<"\nINVALID RUN \nENTER A VALID RUN : ";
			cin>>p;
		}
		
		
		if(p==com)		//checking for wicket
		{
			display();
			
			cout<<"\a\n\n\t**** OH! NO YOU LOST YOUR WICKET ****"<<endl;
			sleep(4);
			
			if(count<2)
			{
				computer();
				return;
			}
			else
			{
				winchk();
				return;
			}
		}
		else
		{
			pscore+=p;
			if(count==2)
			{
				if(pscore>cscore)
				{
					winchk();
					return;
				}
				
			}
			
		}
	}
	
	if(count<2)
	{
		system("cls");
		cout<<"\n\n\t**BALLS ARE OVER**";
		sleep(3);
		computer();
	}
	
	else
	{
		system("cls");
		cout<<"\n\n\t**BALLS ARE OVER**";
		sleep(3);
		winchk();
		return;
	}
	
}

void cricket::computer()
{
	int j=20;
	
	count++;
	
	while(j--)
	{
		display();
		
		com=(rand()%6)+1;
		
		cout<<"\nBALLS LEFT : "<<j+1<<"\n\nYOU ARE BOWLING \n\nGUSSE THE RUN GOING TO BE SCORED : ";
		cin>>p;
		
		if(p==com)
		{
			display();
			cout<<"\a\n\n\t**** HURRAY! YOU TAKE DOWN THE WICKET ****"<<endl;
			sleep(3);
			if(count<2)
			{
				player();
				return;
			}
			
			else
			{
				winchk();
				return;
			}
		}
		else
		{
			cscore+=com;
			if(count==2)
			{
				if(cscore>pscore)
				{
					winchk();
					return;
				}
			}
		}
	}
	if(count<2)
	{
		system("cls");
		cout<<"\n\n\t**BALLS ARE OVER**";
		sleep(3);
		player();
	}
	
	else
	{
		system("cls");
		cout<<"\n\n\t**BALLS ARE OVER**";
		sleep(3);
		winchk();
		return;
	}
}



void cricket::display()
{
	system("cls");
	cout<<"\n\t#####################################\n\t\tHAND CRICKET LEAGUE\n\t\tWELCOME TO THE HCL\n\t#####################################\n";
	cout<<"\n\t\tSCORE BOARD\n";
	cout<<"\n-----------------------------------------\n|\tYOU\t|\tOPPONENT\t|\n-----------------------------------------\n|\t"<<pscore<<"\t|\t"<<cscore<<"\t\t|\n-----------------------------------------";
	cout<<"\n\n LAST MOVE\n\n YOU : "<<p<<"\t OPPONENT : "<<com<<endl;
}



void cricket::winchk()
{
	if(pscore>cscore)
	{
		system("cls");
		cout<<"\a\n\t**************************************************\n\t\t\t HURRAY!!!\n\t\tYOU WON THE MATCH BY "<<pscore-cscore<<" RUNS\n\t**************************************************";
		cout<<"\n\n LAST MOVE\n YOU : "<<p<<"\t OPPONENT : "<<com<<endl;
		cout<<"\n\nSCORE: \nYOU : "<<pscore<<"\tOPPONENT : "<<cscore;
		return;
	}
	else if(pscore<cscore)
	{
		system("cls");
		cout<<"\a\n\t--------------------------------------------------\n\t\t\t OOPS....\n\t\tYOU LOST THE MATCH BY "<<cscore-pscore<<" RUNS\n\t--------------------------------------------------";
		cout<<"\n\n LAST MOVE\n\n YOU : "<<p<<"\t OPPONENT : "<<com<<endl;
		cout<<"\n\nSCORE: \nYOU : "<<pscore<<"\tOPPONENT : "<<cscore;
		return;
	}
	else
	{
		system("cls");
		cout<<"\a\n\t====================================================\n\n\t\t\t WELL PLAYED\n\t\t\tTHE MATCH IS TIE \n\n\t====================================================";
		cout<<"\n\n LAST MOVE\n YOU : "<<p<<"\t OPPONENT : "<<com<<endl;
		cout<<"\n\nSCORE: \nYOU : "<<pscore<<"\tOPPONENT : "<<cscore;
		return;
	}
}



int main()
{
	cricket a;
	srand(time(0));
	a.toss();
}
