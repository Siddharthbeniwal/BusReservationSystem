#include <iostream>
#include <string.h>

using namespace std;

int p = 0;
class BusReservation
{ 
 char busno[5], arrival[10], depart[10], from[10], to[10], seat[10][4][10];
 
 public:
 void addbus();
 void allotseat();
 void empty();
 void businfo();
 void showseats(int s);

} bus[10];

//for adding a new bus
void BusReservation::addbus()
{
 cout<<"Enter Bus number:  ";
 cin>>bus[p].busno;

 cout<<"Enter Arrival time:  ";
 cin>>bus[p].arrival;

 cout<<"Enter Depature time:  ";
 cin>>bus[p].depart;

 cout<<"From:  ";
 cin>>bus[p].from;


 cout<<"To:  ";
 cin>>bus[p].to;

 bus[p].empty();

 cout<<"\nNew bus added succesfully!\n\n";
 
 p++; 
}

// for marking all seats empty
void BusReservation::empty() 
{
  for(int i=0; i<10;i++)
   {
    for(int j=0;j<4;j++)

      { strcpy(bus[p].seat[i][j],"  -  "); } 
   }
}

// for allotting seat to passenger
void BusReservation::allotseat()
{
 int seat;
 char entered_no[5];
 
 top:

 cout<<"Enter bus number:  ";
 cin>>entered_no;
 
 int i;
 for(i=0; i<=p; i++)
 
  { if(strcmp(bus[i].busno, entered_no) == 0)  
    break;  // we get index of bus when we come out of this loop 
  }

if(i<=p)
{
 s:
 cout<<"Enter seat number you want to reserve:  "; 
 cin>>seat;

 if(seat>40)
   { cout<<"There are only 40 seats in this bus.\n";
     goto s;
   }
 else
  {
    if(strcmp(bus[i].seat[seat/4][(seat % 4)- 1], "  -  ") == 0)  // used to break the seat number in row-column basis
     {
      cout<<"Enter name of passenger: ";
      cin >> bus[i].seat[seat/4][(seat%4)-1] ;
      cout<<"\nSeat reserved successfully! \n\n";
      return;
     }
    else
     {
      cout<<"This seat is already reserved.\n";
      goto s;
     }
  }
}
if(i>p)
 { cout<<"Invalid bus no.!\n";
   goto top;
 }

}

//for bus information
void BusReservation::businfo() 
{
 w:
 char en[5];
 cout<<"Enter bus number:  ";
 cin>>en;
 
 int n; 
 for(n=0; n<p; n++)
  { 
   if(strcmp(bus[n].busno , en) == 0  )
   break;
  }

  if(n<p)
  {
   cout<<"\n\n"<<"Bus number: "<< bus[n].busno<<"\n\n";
    
   cout<<"Arrival time:  "<<bus[n].arrival<<"\t  Departure time:  "<<bus[n].depart << endl;

   cout<<"From:  "<<bus[n].from<<"\t\t  Destination:  "<<bus[n].to << "\n\n";

   bus[n].showseats(n);
    
  }
  else
  { cout<<"Invalid bus number!\n";
    goto w;
  }
}  

//for showing seat details 
void BusReservation::showseats(int s)  
{
  int x=0;    // counts no. of total seats
  int y=0;    // counts no. of empty  seats

for (int i =0; i<10;i++)
{ cout<<"\n";
  for (int j = 0;j<4; j++)
  { x++;
    if(strcmp(bus[s].seat[i][j], "  -  ")==0)
    { 
     cout.width(5);
     cout.fill(' ');
     cout<< x <<".";
     
     cout.width(10);
     cout.fill(' ');
     cout<<bus[s].seat[i][j];
     
     y++;
    }
   else
    {
     cout.width(5);
     cout.fill(' ');
     cout<< x <<".";
     
     cout.width(10);
     cout.fill(' ');
     cout<< bus[s].seat[i][j];
    }
  }
}

cout<<"\n\n";
cout<<"   There are "<<y<<" seats available in bus number "<< bus[s].busno <<". \n\n";

}

//main function
int main()
{
while(1)
{ 
 cout<<"\n\n";
 cout<<" \t 1. Add bus.\n";
 cout<<" \t 2. Reserve a seat.\n";
 cout<<" \t 3. See bus information.\n";
 cout<<" \t 4. Exit.\n\n\n";

 int choice;
 cout<<"\t Enter your choice:  ";
 cin>>choice;
 cout<<"\n\n";

 switch (choice)
  {
  case 1:
    bus[p].addbus();
    break;
 
  case 2:
    bus[p].allotseat();
    break;
 
  case 3:
    bus[p].businfo();
    break;
  
  case 4:
    cout<<"\n\t Thanks for visiting!\n\n";
    return 0;
 
  default:
    cout<<"Enter a valid choice! \n\n";
    break;
  };
 
}
return 0;
}