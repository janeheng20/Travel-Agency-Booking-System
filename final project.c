#include<stdio.h>
#include<string.h>

int x;

struct travel
{
	char tour;
	int dest,day,npeople;
}travelt;

struct shotal
{
	char hname[9][50],fhotel[9][250],photel[9][50],rhotel[9][50], htype[50];
	float ph[3][3];
	int room;
}vhotel;

float total_price(float*, char[], float*, float*, float*, char[],int,float*,float*);
void choice_package();
int hotel();
void hotel_data();
void destination();

void main()
{
	float price,transf,pd,tourf,time[2],cdisc;
	char choose, lastchoose;
	char name[50],phone[50],disc[50],trans[50],tourg[50], dest[50], discount[50];
	float totalp, hotelfee, travelfee;
	int a,b,hn;
	
	beginning:
	beginning1:
	fflush(stdin);
	printf("********************************************************************");
    printf("\n                 welcome to Cuti-cuti Malaysia website");
    printf("\n********************************************************************");
	printf("\n\nchoose your package( [P/p] for package; [S/s] for self customize):");
	scanf("%c", & choose);
	
	if(choose=='P'||choose=='p') 
	{
		printf("\n\n");
		choice_package();
		sure1:
		fflush(stdin);
		printf("\nAre you sure the information is correct?[Y/N]\n");
		scanf("%c", &lastchoose);
		if(lastchoose=='Y'|| lastchoose=='y')
		{
			printf("We will proceed your order.");
		}
		else if(lastchoose=='N'|| lastchoose=='n')
		{
			system("cls");
			goto beginning1;
		}
		else
		{
			goto sure1;
		}
	}
	else if(choose=='S'||choose=='s') 
	{	
		printf("\n1) Penang (more details please presss 'P/p')");
		printf("\n2) Langkawi (more details please presss 'L/l')");
		printf("\n3) Melaka (more details please presss 'M/m')");
		printf("\nOr press 'N/n' to select your destination"); 
		destination();
		
		system("cls");
		printf("1) Penang");
		printf("\n2) Langkawi");
		printf("\n3) Melaka");
		printf("\n\nChoose your destination: ");
		scanf("%d", &travelt.dest);
		
		if(travelt.dest==1)
		{
			strcpy(dest, "Penang");
		}
		else if(travelt.dest==2)
		{
			strcpy(dest, "Langkawi");
		}
		else if(travelt.dest==3)
		{
			strcpy(dest, "Melaka");
		}
		else
		{
			strcpy(dest, "Invalid!");
		}
		
		fflush(stdin);
		printf("Do you want tourist guide? (Enter [Y/y] if want, Enter [N/n] if dont):");
		scanf("%c", &travelt.tour);
		
		printf("How many days you want to stay? : ");
		scanf("%d", &travelt.day);
		
		printf("Enter number of people : ");
		scanf("%d", &travelt.npeople);
		
		fflush(stdin);
		printf("\nEnter your name \t: ");
		gets(name);
		printf("Enter your phone number : ");
		scanf("%s", &phone);
		printf("\n\n");
		
		a=hotel();
		
		
		system("cls");
		for(b=0;b<3;b++)
		{
			printf("%s [%d]", vhotel.hname[a],b+1);
			printf("\n");
			a++;
		}
		printf("\n\nEnter hotel number[1/2/3] : ");
		scanf("%d", &hn);
		checkmate:
		printf("Check in(Time) [12pm/3pm/6pm] : ");
		scanf("%f", &time[0]);
		printf("Check out(Time) [12pm/3pm/6pm] : ");
		scanf("%f", &time[1]);
		if(time[0]!=12 && time[0]!=3 && time[0]!=6 || time[1]!=12 && time[1]!=3 && time[1]!=6)
		{
			printf("Invalid time!\n\n");
			system("pause"); 
			goto checkmate;
		}
			
		else
		{
			fflush(stdin);
			printf("Enter your discount code (Note: If you don't have, enter 'no') :");
			gets(disc);
			if(strcmp(disc,"CUTICUTIMALAYSIAISTHEBEST88")==0)
			{
				cdisc=0.7;
				strcpy(discount, "30%");
			}
			else if(strcmp(disc,"CUTICUTIMALAYSIAISTHEBEST99")==0)
			{
				cdisc=0.5;
				strcpy(discount, "50%");
			}
			else
			{
				cdisc=1;
				strcpy(discount, "No discount available.");
			}	
			
			
			
			totalp = total_price(&price, trans, &transf, &pd, &tourf, tourg,hn,&hotelfee,&travelfee);	
			totalp = totalp*cdisc;


			system("cls");
			printf("=======================================================================================\n");
			printf("                                   TRAVEL RECEIPT                                  \n");
			printf("=======================================================================================");
			printf("\nYour name                             : %s", name);
			printf("\nYour phone number                     : %s", phone);
			printf("\nPlace that you had choose to travel   : %s", dest);
			printf("\nTransport that you will taken         : %s", trans);
			printf("\nHow many person                       : %d", travelt.npeople);
			printf("\nHow many days do you want to stay     : %d", travelt.day);
			printf("\nTourist guide                         : %s\n", tourg);
			
			system("pause");

			
			printf("=======================================================================================\n");
			printf("                                   HOTEL RECEIPT                                   \n");
			printf("=======================================================================================");
			printf("\nHotel name                            : %s", vhotel.hname);
			printf("\nHotel type                            : %s", vhotel.htype);
			printf("\nCheck in time                         : %.2fpm ", time[0]);
			printf("\nCheck out time                        : %.2fpm\n", time[1]);
			
			system("pause");
			//system("cls");			
			printf("=======================================================================================\n");
			printf("                                   PRICE RECEIPT                                   \n");
			printf("=======================================================================================");
			
			printf("\nSo we will calculate price by adding Hotel fee and Travel fee.");
			printf("\nHotel fee is room price multiple to quantity of room per day.");
			printf("\nTravel fee is transport fee plus the price of destination,");
			printf("\nAnd multiple them with number of people and days.");
			printf("\nWe will also add extra charges for tourist guide if user required.\n");
			printf("We will also discount for user if they have discount code.");
			printf("\nEquation      = RM%.2f + RM%.2f", hotelfee, travelfee);
			printf("\nHotel fee     = RM%.2f * %d * %d", vhotel.ph[x/3][hn-1], vhotel.room, travelt.day );
			printf("\nTravel fee    = (RM%.2f + RM%.2f) * %d * %d + RM%.2f",transf,pd, travelt.npeople, travelt.day, tourf);
			printf("\nDiscount      = %s", discount);
			printf("\nTotal price   = RM%.2f (Discount included.)\n", totalp);
		}
		system("pause");
		sure:
		fflush(stdin);
		printf("\nAre you sure the information is correct?[Y/N]\n");
		scanf("%c", &lastchoose);
		if(lastchoose=='Y'|| lastchoose=='y')
		{
			printf("We will proceed your order.");
		}
		else if(lastchoose=='N'|| lastchoose=='n')
		{
			system("cls");
			goto beginning;
		}
		else
		{
			goto sure;
		}
	}
		
}

float total_price(float *p, char trans[], float *tf, float *prd, float *tour, char tourg[],int hn,float *hf,float *travel)
{
	float price;
	int people;
	
	hotel_data();
	
	switch(travelt.dest)
		{
			case 1: 
			strcpy(trans,"Bus");
			*tf =50;
			*prd = 189;
			break;
			
			case 2: 
			strcpy(trans,"Aeroplane");
			*tf =150;
			*prd = 289;
			break;
			
			case 3: 
			strcpy(trans,"Bus");
			*tf=50;
			*prd = 119;
			break;
		}
		
		switch(travelt.tour)
		{
			case 'Y':
			case 'y':
			*tour =200;
			strcpy(tourg ,"We will arrange a tourist guide for you. Thank you.");
			break;
			
			case 'N':
			case 'n':
			*tour =0;
			strcpy(tourg,"We will not arrange a tourist guide for you. Thank you.");
			break;
			
			default:
			*tour =0;
			strcpy(tourg,"Code unvalid!");
		}
		
		people = travelt.npeople;
		
		vhotel.room=1;
		
		while(people>4)
		{
			vhotel.room++;
			people = people - 4;
		}
		
		*hf = vhotel.ph[x/3][hn-1] * vhotel.room * travelt.day;
		*travel = ((*tf + *prd) * travelt.day * travelt.npeople) + *tour;
		price = *hf + *travel;
		
		return price;
}



void choice_package()
{
	int packagenum, noPeople,ch=1;
	char guide;
	char package[30], name[30], phone[15];
	float charge, price;
	const float PENANG = 259, LANGKAWI = 620, MELAKA = 452;
	
	back_package:
	if(ch!=1)
	{
		system("cls");
	}	
	printf("For package we have:");
	
	printf("\n\n 1.Penang\t-2 days 1 night RM 259 per person (min 2 person)");
	printf("\n   \t\t-One Night Stay in 'Yote 28' (40 minutes from airport by car)");
	printf("\n   \t\t-Hiking and visting The Habitat Penang Hill");
	printf("\n   \t\t-Driver included in package, Tourist guide available to choose if more than 4 person (extra charge RM80 for tourist guide)");
		
	printf("\n\n 2.Langkawi\t-3 days 2 night	RM 620 per person (min 4 person)");
	printf("\n   \t\t-Two nights stay in 'Four Seasons Resort Langkawi' (25 minutes from airport by car)");
	printf("\n   \t\t-Visiting Wildlife Park, Sky Bridge and Seven Wells Waterfall");
	printf("\n   \t\t-Driver and Tourist Guide included in package");
	
	printf("\n\n 3.Melaka\t-3 days 2 night	RM 452 per person (min 4 person)");
	printf("\n   \t\t-Two nights stay in 'Perfect Portrait Hotel' (15 minutes from airport by car)");
	printf("\n   \t\t-Visiting Stadthuys, Kee Ann Food Street, Jonker Street and The Shore Sky Tower");
	printf("\n   \t\t-Driver and Tourist Guide included in package");
	printf("\n\nEnter 1 to view each destination tourist attraction\nEnter 2 to view the hotel details of each package\nEnter 3 to select your package\n");
	scanf("%d", &ch);
	
	if(ch==2)
	{
		printf("\n\nYou can view the hotel details of each package by pressing the following keys");
		printf("\nPackage 1-'A/a'");
		printf("\nPackage 2-'B/b'");
		printf("\nPackage 3-'C/c'");
		while(ch==2)
		{
			if(kbhit())
			{
				switch (getch())
				{
					case'A':
					case'a':
					travelt.dest=1;
					hotel_data();
					printf("\n\nHotel Type : Economy Hotel");
					printf("\nHotel Name :%s", vhotel.hname[6]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[6]);
					printf("\n\nCheck in and check out time is : 12.00p.m.");					
					printf("\nRating \t\t               : %s\n\n",vhotel.rhotel[6]);
					system("pause");
					ch=3;
					goto back_package;
					break;
					
					case'B':
					case'b':
					travelt.dest=2;
					hotel_data();
					printf("\n\nHotel Type : Resort Hotel");
					printf("\nHotel Name :%s",vhotel.hname[0]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[0]);
					printf("\n\nCheck in and check out time is : 3.00p.m.");
					printf("\nRating\t\t               :%s\n\n",vhotel.rhotel[0]);
					system("pause");
					ch=3;
					goto back_package;
            		break;
            		
            		case'C':
            		case'c':
            		travelt.dest=3;
            		hotel_data();
            		printf("\n\nHotel Type : Personalized Theme Hotel");
					printf("\nHotel Name :%s",vhotel.hname[5]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[5]);
					printf("\n\nCheck in and check out time is : 6.00p.m.");					
					printf("\nRating\t\t               : %s\n\n",vhotel.rhotel[5]);
					system("pause");
					ch=3;
					goto back_package;
            		break;
				}
			}
		}
	}
	else if(ch==1)
	{
		printf("\nmore details of Penang please presss 'P/p'");
		printf("\nmore details of Langkawi please presss 'L/l'");
		printf("\nmore details of Melaka please presss 'M/m'");	
		destination();
		ch=3;
		goto back_package;
	}
	
	printf("\n\nSelect the package you want (1/2/3) \t: ");
	scanf("%d", &packagenum);
	
	printf("Enter the number of people \t\t: ");
	scanf("%d", &noPeople);
	fflush(stdin);
	if(packagenum==1 && noPeople>=2)
	{
		if(noPeople>=4)
		{
			printf("Do you need a tourist guide?(extra charge RM80) [Y/N] : "); 
			scanf("%c", &guide);
		}
		else
			guide = 'N';
		
		strcpy(package, "Package 1 (Penang)");
		
		if(guide=='Y'||guide=='y') 
			charge = 80.00;
		else if(guide=='N'||guide=='n') 
			charge = 0.00;
		price = (noPeople * PENANG) + charge;
	}
		
	else if(packagenum==2 && noPeople>=4)
	{
		strcpy(package, "Package 2 (Langkawi)");
		price = noPeople * LANGKAWI;
		guide = 'Y';
	}
		
	else if(packagenum==3 && noPeople>=4)
	{
		strcpy(package, "Package 3 (Melaka)");
		price = noPeople * MELAKA;
		guide = 'Y';
	}
		
	else
	{
		if(packagenum!=1&&packagenum!=2&&packagenum!=3)
		{
			printf("\nInvalid package!");
			price=0;
		}
		
		else if(packagenum==1 && noPeople<2 || packagenum==2 && noPeople<4||packagenum==3 && noPeople<4)
		{
			printf("\nYou didn't reached the minimum number of people!");
			price=0;	
		}
	}
		
	fflush(stdin); 
	if(price>0)
	{
		printf("Enter your name \t\t\t: ");
		gets(name);
		printf("Enter your phone number \t\t: ");
		scanf("%s", &phone);	
		
		printf("\n--------------------------------------------------------------------");
		printf("\n				Receipt					");
		printf("\n--------------------------------------------------------------------");
		printf("\nCustomer name \t\t\t: %s", name);
		printf("\nCustomer phone number \t\t: %s", phone);
		printf("\nThe package have choosen \t: %s", package); 
		printf("\nNumber of people \t\t: %d", noPeople);
		printf("\nTourist Guide \t\t\t: %c", guide);
		printf("\nExtra charge \t\t\t: RM %.2f", charge);
		printf("\nTotal Price \t\t\t: RM %.2f", price);
	}
}

int hotel()
{	
	system("pause");
	printf("\n");
	
	char type;
	int ch,a;
	float ph;
	hotel_type:
		
	hotel_data(); 
	
	system("cls");
	printf("---------------------------------------------------------\n");
	printf("		Type of Hotels");
	printf("\n---------------------------------------------------------");
	printf("\nResort Hotel(R/r)		Personalized Theme Hotel(P/p) \n	        Economy Hotel(E/e)");
	
	fflush(stdin);
	printf("\n\nEnter the type of hotel: "); 
	scanf("%c", &type);
	
	
	while(type!='R'&&type!='r'&&type!='P'&&type!='p'&&type!='E'&&type!='e')
	{
		printf("\n\nInvalid hotel type. Please enter again:");
		scanf("%c", &type);
	}
	
	if(type=='R'||type=='r')
	{
		strcpy(vhotel.htype,"Resort Hotel");
		x=0;
		printf("\nRecommended hotels for Resort Hotel: ");
		printf("\n%s(More details of this hotel, please press (A/a)",vhotel.hname[x]);
		printf("\n\nOthers hotel:");
		printf("\n%s(More details of this hotel, please press (B/b)",vhotel.hname[x+1]);
		printf("\n%s(More details of this hotel, please press (C/c)\n",vhotel.hname[x+2]);
		printf("\nNote: Press (N/n) to make a booking\n");
		a=0;
		
		while(ch<=1)
		{
			if(kbhit())
        	{
        		switch (getch()) 
				{
        			case 'a':
        			case 'A':	
        			system("cls");
            		printf("Hotel Type : Resort Hotel");
					printf("\nHotel Name :%s",vhotel.hname[0]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[0]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)", vhotel.ph[0][0]);
					printf("\nRating\t\t               :%s",vhotel.rhotel[0]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (B/b)\nMore details of %s, please press (C/c)\nEnter (N/n) to book your hotel",vhotel.hname[x+1],vhotel.hname[x+2]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
        			case 'b':
        			case 'B':	
        			system("cls");	
            		printf("Hotel Type : Resort Hotel");
					printf("\nHotel Name :%s",vhotel.hname[1]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[1]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)", vhotel.ph[0][1]);
					printf("\nRating\t\t               : %s",vhotel.rhotel[1]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (A/a)\nMore details of %s, please press (C/c)\nEnter (N/n) to book your hotel",vhotel.hname[x],vhotel.hname[x+2]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
        			case 'c':
        			case 'C':	
        			system("cls");
            		printf("Hotel Type : Resort Hotel");
					printf("\nHotel Name :%s", vhotel.hname[2]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[2]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)",vhotel.ph[0][2]);
					printf("\nRating \t\t               :%s",vhotel.rhotel[2]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (A/a)\nMore details of %s, please press (B/b)\nEnter (N/n) to book your hotel",vhotel.hname[x],vhotel.hname[x+1]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
            		case 'n':
            		case 'N':	
            		ch=2; 
					break;
					
					case 'R':
					case 'r':
					system("cls");	
					goto hotel_type;
					break;
				}
     		}	
		}
	}
	else if(type=='P'||type=='p')
	{
		strcpy(vhotel.htype,"Personalized Theme Hotel");
		x=3;
		printf("\nRecommended hotels for Personalized Theme Hotel: ");
		printf("\n%s(More details of this hotel, please press (A/a)",vhotel.hname[x]);
		printf("\n\nOthers hotel:");
		printf("\n%s(More details of this hotel, please press (B/b)",vhotel.hname[x+1]);
		printf("\n%s(More details of this hotel, please press (C/c)\n",vhotel.hname[x+2]);
		printf("\nNote: Press (N/n) to make a booking\n");
		a=3;
		
		while(ch<=1)
		{
			if(kbhit())
        	{
        		switch (getch()) 
				{
        			case 'a':
        			case 'A':	
        			system("cls");
            		printf("Hotel Type : Personalized Theme Hotel");
					printf("\nHotel Name :%s",vhotel.hname[3]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[3]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)",vhotel.ph[1][0]);
					printf("\nRating\t\t               : %s",vhotel.rhotel[3]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (B/b)\nMore details of %s, please press (C/c)\nEnter (N/n) to book your hotel",vhotel.hname[x+1],vhotel.hname[x+2]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;  				
            		
        			case 'b':
        			case 'B':	
        			system("cls");	
            		printf("Hotel Type : Personalized Theme Hotel");
					printf("\nHotel Name :%s",vhotel.hname[4]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[4]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)",vhotel.ph[1][1]);
					printf("\nRating\t\t               : %s",vhotel.rhotel[4]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (A/a)\nMore details of %s, please press (C/c)\nEnter (N/n) to book your hotel",vhotel.hname[x],vhotel.hname[x+2]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
        			case 'c':
        			case 'C':	
        			system("cls");
            		printf("Hotel Type : Personalized Theme Hotel");
					printf("\nHotel Name :%s",vhotel.hname[5]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[5]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)",vhotel.ph[1][2]);
					printf("\nRating\t\t               : %s",vhotel.rhotel[5]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (A/a)\nMore details of %s, please press (B/b)\nEnter (N/n) to book your hotel",vhotel.hname[x],vhotel.hname[x+1]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
            		case 'n':
            		case 'N':	
            		ch=2;
            		break;
            		
            		case 'R':
					case 'r':
					system("cls");	
					goto hotel_type;
					break;
				}
     		}	
		}		
	}
	else if(type=='E'||type=='e')
	{
		strcpy(vhotel.htype,"Economy Hotel");
		x=6;
		printf("\nRecommended hotels for Economy Hotel: ");
		printf("\n%s(More details of this hotel, please press (A/a)",vhotel.hname[x]);
		printf("\n\nOthers hotel:");
		printf("\n%s(More details of this hotel, please press (B/b)",vhotel.hname[x+1]);
		printf("\n%s(More details of this hotel, please press (C/c)\n",vhotel.hname[x+2]);
		printf("\nNote: Press (N/n) to make a booking\n");
		a=6;		
		
		while(ch<=1)
		{
			if(kbhit())
        	{
        		switch (getch()) 
				{
        			case 'a':
        			case 'A':	
        			system("cls");
            		printf("Hotel Type : Economy Hotel");
					printf("\nHotel Name :%s", vhotel.hname[6]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[6]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)",vhotel.ph[2][0]);
					printf("\nRating \t\t               : %s",vhotel.rhotel[6]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (B/b)\nMore details of %s, please press (C/c)\nEnter (N/n) to book your hotel",vhotel.hname[x+1],vhotel.hname[x+2]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
        			case 'b':
        			case 'B':	
        			system("cls");	
            		printf("Hotel Type : Economy Hotel");
					printf("\nHotel Name :%s", vhotel.hname[7]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[7]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)",vhotel.ph[2][1]);
					printf("\nRating \t\t               : %s",vhotel.rhotel[7]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (A/a)\nMore details of %s, please press (C/c)\nEnter (N/n) to book your hotel",vhotel.hname[x],vhotel.hname[x+2]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
        			case 'c':
        			case 'C':	
        			system("cls");
            		printf("Hotel Type : Economy Hotel");
					printf("\nHotel Name :%s", vhotel.hname[8]);
					printf("\n\nFeatures of Hotel:%s",vhotel.fhotel[8]);
					printf("\n\nCheck in and check out time is : [12.00p.m./3.00p.m./6.00p.m.]");					
					printf("\nPrice                          : RM%.2f for one room per night (max 4 person per room)",vhotel.ph[2][2]);
					printf("\nRating \t\t               : %s",vhotel.rhotel[8]);
					printf("\n\n\n\n\n");
					printf("More details of %s, please press (A/a)\nMore details of %s, please press (B/b)\nEnter (N/n) to book your hotel",vhotel.hname[x],vhotel.hname[x+1]);
					printf("\nOr press (R/r) to select again the type of hotel");
            		break;
            		
            		case 'n':
            		case 'N':	
            		ch=2;
            		break;
            	
					case 'R':
					case 'r':
					system("cls");	
					goto hotel_type;
					break;					
				}
     		}	
		}		
	}
	return a;
}

void destination()
{
	int ch=1;
	
	while(ch==1)
	{
		if(kbhit())
		{
			switch (getch())
			{
				case 'P':
				case 'p':
				system("cls");	
				printf("1. The Habitat Penang Hill\n");
				printf("----------------------------------\n");
				printf("The Habitat Penang Hill is a rainforest experience that takes you into the heart of \nthe jungle and lets you truly feel all the sounds, colors, and smells up close. Your \nfirst contact with nature is through the 1.6-kilometer-long nature trail, which cuts \nthrough the ancient forest, over rolling hills and far above the Andaman Sea-all of \nwhich you can see from several lookout points along the way.\n\n");
				printf("For an even more stunning view of the surroundings, visitors can take the Langur \nWay Canopy Walk, 15 meters up in the air and 230 meters long, gently curving \naround and through the trees. Or they can try the ziplines for an up-close \nexperience of the jungle.\n\n");
				printf("For those wanting to catch a glimpse of George Town, as well as the surrounding \njungle, nothing beats the Curtis Crest Tree Top Walk, a circular platform with 360-\ndegree views and the highest point in the island. Special tours guided by naturalists \ntake place here as the sun sets, when you can see not only a stunning array of colors \non the sky, but also catch a glimpse of giant flying red squirrels, bats, and the \nPenang gecko.\n\n");
				system("pause");
				
				printf("\n2. Clan Jetties, George Town\n");
				printf("----------------------------------\n\n");
				printf("The Clan Jetties are one of the most significant historical areas in Penang-a \ntraditional village consisting of structures and houses built on stilts right over \nthe water.\n\n");
				printf("Clan jetties are a very unique type of water settlement created by Chinese \nimmigrants in the late 19th century. Originally, they consisted of a single structure \nused as a sort of small warehouse where the loading and unloading of products and \nmaterials (including firewood, charcoal, and boat transportation) for a particular \ntrade or industry happened. Over the years, families (or clans) took over certain \nindustries and unofficially claimed a certain area of the dock, with each clan getting \nbigger and building more huts along the way.\n\n");
				printf("There are now six jetties on the waterfront-all of them still home to Chinese \ndescendants and considered a historical reminder of the industries that helped \nshape Penang. While they are technically private property where families live, most \nof the jetties welcome visitors for a glimpse of their local temple, photos of the \nsunset over the water, and a nostalgic walk over the walkway surrounding the \nstilt-houses.\n\n");
				system("pause");
				
				printf("\n3. Entopia by Penang Butterfly Farm\n");
				printf("----------------------------------\n\n");
				printf("Entopia is Penang's new butterfly farm, a massive glass conservatory where over \n15,000 free-flying butterflies live among waterfalls, lush tropical greenery, and \nre-created natural features.\n\n");
				printf("Trails crisscross through the greenhouse, offering many chances to see butterflies in \ntheir natural element, including small caves, a wild garden, a backyard area, and \nmore. Special events throughout the day allow visitors to interact with butterflies up \nclose and learn about unique and rare species.\n\n");
				printf("Entopia is divided into two main sections: Natureland and Cocoon. Natureland is a \nliving garden vivarium that encompasses the main butterfly area, plus ponds and \nspecial areas where snapping turtles, frogs, iguanas, and a number of large insects \nlive. Cocoon is Entopia's discovery center, where visitors can learn more about \nbutterflies and participate in hands-on activities.\n\n");
				printf("___________________\n");
				printf("More details of Langkawi, please press (L/l)\nMore details of Melaka, please press (M/m)\nPress (N/n) to select your destination");
				break;
				
				case 'L':
				case 'l':
				system("cls");
				printf("1. Langkawi Sky Bridge\n");
				printf("----------------------------------\n");
				printf("A ride on a cable car takes tourists to Langkawi Sky Bridge - a true highlight of the region, elevated at a height \nof 2300 feet above sea level. From the top of this bridge, the mesmerising views of the rainforest along with the \nTelaga Tujuh waterfalls make sure to leave visitors spellbound.\n\n");
				printf("It attracts nature lovers, photographers, and adventure enthusiasts alike. Here, tourists can also indulge in \nsome shopping at the number of stalls that sell souvenirs, toys, drinks, and snacks. The bridge certainly is one \nof the top places to visit in Langkawi.\n\n");
				printf("Timings: 10 am to 10 pm\n\n");
				system("pause");
				
				printf("\n2. Underwater World\n");
				printf("----------------------------------\n");
				printf("One of the most popular tourist attractions in Langkawi - the underwater world spread across six acres introduces \ntourists to over 200 species of marine life and fishes. These include rockhopper, harbour seals, giant rays, \npenguins, sharks, and the unusual Amazonian arapaima, which is the largest freshwater fish discovered in \nthe world.\n\n");
				printf("Moreover, the educational research centre, three-dimensional theatre and various sections of the park-Temperate,\ntropical rainforest and sub - Antarctic have also grabbed the attention of visitors alike. These interesting \nand thoughtful attractions make Underwater World one of the best places to see in Langkawi.\n\n");
				printf("Timings: 9:30 am to 6:30 pm from Monday to Friday and 9:30 am to 10:30 pm on weekends\n\n");
				system("pause");
				
				printf("\n3. Pulau Payar Marine Park\n");
				printf("----------------------------------\n");			
				printf("On the list of places to visit in Langkawi, Pulau Payar marine life makes its name well deservingly. The marine \npark has and continues to attract snorkeling and diving enthusiasts from all over the world who are keen on \ndiscovering Langkawi’s underwater life. The park comprises of four islands - Pulau Payar, Pulau Kaca, Pulau \nLembu, and Pulau Senangtang; Pulau Payar being the largest one.\n\n");
				printf("The best part is that none of these islands remains inhabited and is preserved by the fisheries department of \nKedah, who make sure the pristine condition of these islands are maintained. Tourists here can avail a variety of \nfacilities like barbeque pits, gazebos, picnic tables and lots more.\n\n");
				printf("Location:30 Kilometers south of Langkawi.\n\n");
				printf("___________________\n");
				printf("More details of Penang, please press (P/p)\nMore details of Melaka, please press (M/m)\nPress (N/n) to select your destination");
				break;
				
				case 'M':
				case 'm':
				system("cls");
				printf("1. Cheng Hoon Teng Chinese Temple\n");
				printf("-----------------------------------------------\n");
				printf("Cheng Hoon Teng Chinese Temple has the claim to fame of being the oldest Chinese temple of its kind in \nMalaysia and dates from the 17th century.\n\n");
				printf("The temple is an important place of worship for the Buddhist Chinese community in Malacca and a visit \nhere is a great way to learn more about their culture and history.\n\n");
				printf("Make sure to check out the inscription that dates from 1685 and which is dedicated to Kapitan Li Wei \nKing as well as the statue of Guanyin who is the Goddess of Compassion.\n\n");
				system("pause");
				
				printf("\n2. Taming Sari Revolving Tower\n");
				printf("-----------------------------------------------\n");
				printf("It is hard not to notice Taming Sari Revolving Tower when you are in Malacca as it soars to a height of \n110 meters and can seat 66 passengers at one time.\n\n");
				printf("The ride in the tower takes around 7 minutes to complete as you will ascend and then get to spend 5 \nminutes at the top taking in the views over the city before descending again.\n\n");
				printf("From the tower you can take in panoramic vistas across the city which stretch all the way to the coast.\n\n");
				system("pause");
				
				printf("\n3. Admire the Sultanate Palace\n");
				printf("-----------------------------------------------\n");
				printf("The Sultanate Palace is actually a model of the original wooden palace that belonged to Sultan Mansur Shah \nwho would have been the ruler of Malacca from 1456 to 1477. The home has now been transformed into \na cultural museum which is flanked by pretty gardens and what makes the building even more \nimpressive is that it was made without using any nails to hold it together.\n\n");
				printf("Instead the structure stands as a result of some clever engineering and a series of wooden grooves and \nslots and the reconstruction was done after taking detailed notes of how the original palace would have \nlooked according to the Malay Annals.\n\n");
				printf("___________________\n");
				printf("More details of Penang, please press (P/p)\nMore details of Langkawi, please press (L/l)\nPress (N/n) to select your destination");
				break;
				
				case'N':
				case'n':
				ch=2;
				break;	
				
			}
		}
	}
}

void hotel_data()
{
	if(travelt.dest==1)
	{
		strcpy(vhotel.hname[0],"'A'Famosa Resort'");
		strcpy(vhotel.hname[1],"'Bayou Lagoon Park Resort'");
		strcpy(vhotel.hname[2],"'D'Village Resort'");
		strcpy(vhotel.hname[3],"'Timez Hotel'");
		strcpy(vhotel.hname[4],"'The Settlement Hotel'");
		strcpy(vhotel.hname[5],"'1825 Gallery Hotel'");
		strcpy(vhotel.hname[6],"'Yote 28'");
		strcpy(vhotel.hname[7],"'TheBlanc Boutique Hotel'");
		strcpy(vhotel.hname[8],"'The Pillohouzzze'");
		strcpy(vhotel.fhotel[0],"\n-Breathtaking sea view (You can enjoy the sunset every evening!)\n-Provide entertainment facilities like water park, karaoke(24 hours) and spa\n-Provide free buffet breakfast and seafood buffet(dinner), only RM150 per person");
		strcpy(vhotel.fhotel[1],"\n-Free wifi, free pool access, free fitness centre access and free spa access\n-Breakfast is included and RM70 per person for dinner(BBQ)\n-Near to the airport and 300 meters to public transportation");
		strcpy(vhotel.fhotel[2],"\n-Free internet access\n-24-hour room service and 24-hour security\n-Provide airport transfer service and have own shuttle bus");
		strcpy(vhotel.fhotel[3],"\n-Customer service by robots\n-Have a LCD TV in bathroom (You can watch a movie while chilling in the jacuzzi)\n-Voice control for in-room features");
		strcpy(vhotel.fhotel[4],"\n-Abstract drawing by famous artist in every room\n-Small gallery along the corridor\n-Floor-to-Ceiling marble bathroom");
		strcpy(vhotel.fhotel[5],"\n-A variety of musical instruments hanging on the lobby's wall\n-Provide professional recording studio\n-Many music venues and clubs will be conducted");
		strcpy(vhotel.fhotel[6],"\n-Complimentary wireless internet access and pool access\n-Provide laundry service and wake up service\n-Provide local breakfast for free");
		strcpy(vhotel.fhotel[7],"\n-Free wifi access\n-One and the half hour drive to the airport\n-Provide daily housekeeping service and 24-hour front desk");
		strcpy(vhotel.fhotel[8],"\n-Beautiful city view especially at night time\n-Provide shuttle service and luggage storage\n-Fully equipped with kitchen like microwave, fridge and others");
		strcpy(vhotel.rhotel[0],"4.6/5.0(9999+)");
		strcpy(vhotel.rhotel[1],"4.0/5.0(8790)");
		strcpy(vhotel.rhotel[2],"3.8/5.0(3671)");
		strcpy(vhotel.rhotel[3],"4.5/5.0(9999+)");
		strcpy(vhotel.rhotel[4],"4.9/5.0(4329)");
		strcpy(vhotel.rhotel[5],"4.7/5.0(7112)");
		strcpy(vhotel.rhotel[6],"4.4/5.0(9999+)");
		strcpy(vhotel.rhotel[7],"1.9/5.0(993)");
		strcpy(vhotel.rhotel[8],"3.7/5.0(6110)");
		vhotel.ph[0][0]=400;
		vhotel.ph[0][1]=375;
		vhotel.ph[0][2]=450;
		vhotel.ph[1][0]=300;
		vhotel.ph[1][1]=290;
		vhotel.ph[1][2]=300;
		vhotel.ph[2][0]=188.88;
		vhotel.ph[2][1]=270;
		vhotel.ph[2][2]=230;
	}
	else if(travelt.dest==2)
	{
		strcpy(vhotel.hname[0],"'Four Seasons Resort Langkawi'");
		strcpy(vhotel.hname[1],"'Best Star Resort'");
		strcpy(vhotel.hname[2],"'Langgura Baron Resort'");
		strcpy(vhotel.hname[3],"'The Datai Langkawi'");
		strcpy(vhotel.hname[4],"'Casa del Mar, Langkawi'");
		strcpy(vhotel.hname[5],"'Dash Resort'");
		strcpy(vhotel.hname[6],"'Chill Suites Langkawi'");
		strcpy(vhotel.hname[7],"'Bayview Hotel Langkawi'");
		strcpy(vhotel.hname[8],"'Myvilla Langkawi Hotel'");
		strcpy(vhotel.fhotel[0],"\n-Provide daily breakfast, lunch and dinner, tropical fruit basket welcome amenity \n-25% off massages at Geo Spa\n-all-day access to Lutong Kids Club and Kawan Club Games Room");
		strcpy(vhotel.fhotel[1],"\n-Offers air-conditioned guest rooms in Pantai Cenang \n-Free WiFi \n-Underwater World Langkawi is 500 m from Best Star Resort and Langkawi International Airport is 11 km from the resort");
		strcpy(vhotel.fhotel[2],"\n-Fully air-conditioned, every room comes with a flat-screen TV and coffee/tea making facilities\n-Plenty of dining options serving local favorites are located a short walk away \n-Tour arrangements can be made at the tour desk");
		strcpy(vhotel.fhotel[3],"\n-It boasts a golf course, well-appointed spa and swimming pool \n-Offers a menu of massage and body treatments \n-Mountain bikes are also available for usage, at no charge");
		strcpy(vhotel.fhotel[4],"\n-All rooms have air conditioning, a seating area and a flat-screen TV with satellite channels \n-Guests at the accommodation can enjoy a continental or a buffet breakfast\n-offers a 24-hour front desk and room service");
		strcpy(vhotel.fhotel[5],"\n-Free Wi-Fi and private parking are provided \n-All rooms are fitted with a minibar and TV with cable channels \n-Laundry and ironing services are available upon request");
		strcpy(vhotel.fhotel[6],"\n-3-star hotel \n-provides a 24-hour front desk, a concierge service and organising tours for guests \n-Guests at the accommodation can enjoy a ?la carte breakfast");
		strcpy(vhotel.fhotel[7],"\n-It houses 3 dining options, an outdoor pool and extensive wellness facilities \n-Free WiFi is available in hotel \n-Langkawi Night Market opens twice a week and is located 500 m from the hotel");
		strcpy(vhotel.fhotel[8],"\n-Offers an outdoor swimming pool and air-conditioned accommodation \n-Luggage storage is free \n-Myvilla Langkawi Hotel is 19 km from Seven Wells Waterfall and Langkawi Cable Car is 22 km from the hotel");
		strcpy(vhotel.rhotel[0],"4.2/5.0(8212)");
		strcpy(vhotel.rhotel[1],"4.5/5.0(5648)");
		strcpy(vhotel.rhotel[2],"4.1/5.0(6077)");
		strcpy(vhotel.rhotel[3],"4.9/5.0(9500)");
		strcpy(vhotel.rhotel[4],"4.1/5.0(9999+)");
		strcpy(vhotel.rhotel[5],"3.5/5.0(2415)");
		strcpy(vhotel.rhotel[6],"4.3/5.0(4268)");
		strcpy(vhotel.rhotel[7],"4.9/5.0(5002)");
		strcpy(vhotel.rhotel[8],"3.8/5.0(6820)");
		vhotel.ph[0][0]=450;
		vhotel.ph[0][1]=500;
		vhotel.ph[0][2]=420;
		vhotel.ph[1][0]=630;
		vhotel.ph[1][1]=550;
		vhotel.ph[1][2]=400;
		vhotel.ph[2][0]=350;
		vhotel.ph[2][1]=300;
		vhotel.ph[2][2]=380;
	}
	else if(travelt.dest==3)
	{
		strcpy(vhotel.hname[0],"'Sweet Garden Hotel'");
		strcpy(vhotel.hname[1],"'Moonlight Suite Hotel'");
		strcpy(vhotel.hname[2],"'Royal Hotel'");
		strcpy(vhotel.hname[3],"'Golden Star Hotel'");
		strcpy(vhotel.hname[4],"'Buildie Tech Hotel'");
		strcpy(vhotel.hname[5],"'Perfect Portrait Hotel'");
		strcpy(vhotel.hname[6],"'Poppin Melody Hotel'");
		strcpy(vhotel.hname[7],"'Dream Space Hotel'");
		strcpy(vhotel.hname[8],"'Leisure Comfy Hotel'");
		strcpy(vhotel.fhotel[0],"\n-Located in the heart of the city, within a ten-minute walk to famous Jonker Street\n-Provide wedding service\n-Free internet access and free fitness centre acess");
		strcpy(vhotel.fhotel[1],"\n-Wifi available in all areas\n-Currency exchange and mini market on-site and \n-Provide baby sitting or child care service");
		strcpy(vhotel.fhotel[2],"\n-Located in shopping district,within a 5-minute walk to Dataran Pahlawan Melaka Megamall\n-Concierge service provided\n-Widespread buffet breakfast");
		strcpy(vhotel.fhotel[3],"\n-Audio-streaming service, and mood lighting controlled via an app\n-Provide unlimited data\n-Meals are delivered by a robot");
		strcpy(vhotel.fhotel[4],"\n-Art-filled halls, rooms and lobby\n-Located near art galleries and museums\n-Provide drawing and painting activities");
		strcpy(vhotel.fhotel[5],"\n-The rooms decorated with real guitar\n-Provide 20% discount at music pub from 10-1pm\n-Provide music album rental service");
		strcpy(vhotel.fhotel[6],"\n-Free local delicious breakfast\n-Beautiful river view\n-Provide airport shuttle");
		strcpy(vhotel.fhotel[7],"\n-24-hour security and front desk\n-Free wifi, free water bottles and hair dryers\n-Provide BBQ and hotpot facilities");
		strcpy(vhotel.fhotel[8],"\n-30-minute to Melaka International Airport\n-Private parking available on-site\n-Near to tourist attraction");
		strcpy(vhotel.rhotel[0],"4.7/5.0(3974)");
		strcpy(vhotel.rhotel[1],"4.5/5.0(5284)");
		strcpy(vhotel.rhotel[2],"4.8/5.0(9999)");
		strcpy(vhotel.rhotel[3],"4.3/5.0(2057)");
		strcpy(vhotel.rhotel[4],"4.4/5.0(7196)");
		strcpy(vhotel.rhotel[5],"4.1/5.0(4629)");
		strcpy(vhotel.rhotel[6],"3.6/5.0(6301)");
		strcpy(vhotel.rhotel[7],"3.7/5.0(1736)");
		strcpy(vhotel.rhotel[8],"4.0/5.0(8482)");
		vhotel.ph[0][0]=400;
		vhotel.ph[0][1]=350;
		vhotel.ph[0][2]=420;
		vhotel.ph[1][0]=380;
		vhotel.ph[1][1]=402;
		vhotel.ph[1][2]=399;
		vhotel.ph[2][0]=226;
		vhotel.ph[2][1]=275;
		vhotel.ph[2][2]=250;
	}
}
//name,phone number,destination,number of people and day,transport,guilde,hotel,price
