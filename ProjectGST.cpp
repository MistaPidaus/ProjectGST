/** My GST Programming Code
Developed By Pidaus
Copyright 2016
**/
//Starting the header
#include <iostream>
#include <ctype.h>//For isalpha function
using namespace std;

//Structure:
struct DataS {
  char name[32];
  float item_price;
  float tax_before;
  float gst6_difftaxb4; 
  float tax_after_prev;
  float gst6_price; 
  float total_gst6; 
  char item_label; 
};

//Selection case, Charges of old tax rate to certain label
float kiraGST(char p, float lah)
{
  float kira = 0;
  if (p =='P' || p == 'p')
  {
  kira = lah * 0.1;
  return kira;
  }
  if (p == 'S' || p == 's')
  {
  kira = lah * 0.05;
  return kira;
  }
  if (!(p == 'p' || p == 'P' || p == 'S' || p == 's'))
  {
  kira = lah * 0;
  return kira;
  }
}
//Calculate GST 6% Tax
float GSTCal(char gst, float huhu)
{
  float si = 0;
  if (gst == 'S' || gst == 's' || gst == 'p' || gst == 'P')
  {
  si = huhu * 0.06;
  printf("6%% tax (GST)  :  RM%.2f\n", si);
  return si;
  }
  if (!(gst == 'p' || gst == 'P' || gst == 's' || gst == 'S'))
  {
  si = huhu * 0;
  printf("6%% tax (GST)  :  RM%.2f\n", si);
  return si;
  }
}

int main()
{
   int inputs;
   //Starting Pointer
   DataS DataGsT;
   DataS *gstData;
   gstData = &DataGsT;

   while(true)
	{
   //Menu:
   cout <<"---------------------------------------------" << endl;
   cout <<".:: Welcome to GST Calculator! ::. \nInput 1: To start the calculator. \nInput 2: Exit the program\nEnter your action: "; 
   cin >> inputs;
   if (inputs==2)
		{
		break;
		}
   else
		{
   cout << "Enter your Name: ";
   cin >> gstData->name;
   cout << "Enter price :   RM"; //2nd line for first string
   cin >> gstData->item_price;

   cout << "Enter Item Label : "; //Enter Item Label
   cin >> gstData->item_label;
      if (!isalpha(gstData->item_label))//Only accept letter/Alphanumeric function
	  {
	  	cout << "ERROR! Invalid Character. Alphanumeric only\n"; //echo error
	  	break;
	  }
      gstData->tax_before = kiraGST(gstData->item_label, gstData->item_price);
      gstData->tax_after_prev = gstData->item_price+gstData->tax_before;
      cout <<"---------------------------------------------" << endl;
      cout<< "Data you Entered: \nName: "<< gstData->name <<"\nPrice: RM" << gstData->item_price << "\nItem Label: " << gstData->item_label<<endl;
      cout <<"---------------------------------------------" << endl;
	  printf("Price (including previous tax) :  RM%.2f\n", gstData->tax_after_prev);
	  cout<< "Price after excluding previous tax :  RM" << gstData->item_price <<endl;
	  gstData->gst6_price = GSTCal(gstData->item_label, gstData->item_price);
	  gstData->total_gst6 = gstData->item_price + gstData->gst6_price;
      printf("Price after include 6%% tax  :  RM%.2f\n", gstData->total_gst6);
      gstData->gst6_difftaxb4 = gstData->gst6_price - gstData->tax_before;
      printf("Different price between before and after 6%% GST  :  RM%.2f\n", gstData->gst6_difftaxb4);
     // display the output
        
   cout << ".:: Developed by Pidaus ::.\n---------------------------------------------\n\n";
		}
	}
   return 0;
}

