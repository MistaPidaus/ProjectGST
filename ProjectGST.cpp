/** My GST Programming Code
Developed By Pidaus
Copyright 2016
**/
#include <iomanip>
#include <iostream>
using namespace std;

//Structure:
struct DataS {
  char name[32];
  float item_price = 0;
  float tax_before = 0;
  float gst6_difftaxb4 = 0; 
  float tax_after_prev = 0;
  float gst6_price = 0; 
  float total_gst6 = 0; 
  char item_label; 
};

//Only accept letter, not numbers
char checkLabel(char x)
{
if (!((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))) 
   {
       cout << "ERROR! Invalid Character.\n"; //echo error
   }return x;
}

//Selection case
float test(char p, float lah)
{
  float kira = 0, jap;
  if (p =='P' || p == 'p')
  {
  kira = lah * 10/100;
  return kira;
  }
  if (p == 'S' || p == 's')
  {
  kira = lah * 5/100;
  return kira;
  }
  if (!(p == 'p' || p == 'P' || p == 'S' || p == 's'))
  {
  kira = lah * 0/100;
  return kira;
  }
}
//Calculate GST 6% Tax
float GSTCal(char gst, float huhu)
{
  float ntah, si = 0;
  if (gst == 'S' || gst == 's' || gst == 'p' || gst == 'P')
  {
  si = ntah * 6/100;
  cout<< "6% tax (GST)  :  RM" << si << endl;
  return si;
  }
  if (!(gst == 'p' || gst == 'P' || gst == 's' || gst == 'S'))
  {
  si = gst * 0/100;
  cout<< "6% tax (GST)  :  RM" << si << endl;
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
   if (inputs==2){break;}
   else
   {
   cout << "Enter your Name: ";
   cin >> gstData->name;
   cout << "Enter price :   RM"; //2nd line for first string
   cin >> gstData->item_price;

   cout << "Enter Item Label : "; //Enter Item Label
   cin >> gstData->item_label;
      checkLabel(gstData->item_label);
      gstData->tax_before = test(gstData->item_label, gstData->item_price);
      gstData->tax_after_prev = gstData->item_price+gstData->tax_before;
      cout <<"---------------------------------------------" << endl;
      cout<< "Data you Entered: \nName: "<< gstData->name <<"\nPrice: RM" << gstData->item_price << "\nItem Label: " << gstData->item_label<<endl;
      cout <<"---------------------------------------------" << endl;
	  cout<< "Price (including previous tax) :  RM" << gstData->tax_after_prev<<endl;
	  cout<< "Price after excluding previous tax :  RM" << gstData->item_price <<endl;
	  gstData->gst6_price = GSTCal(gstData->item_label, gstData->item_price);
	  gstData->total_gst6 = gstData->item_price + gstData->gst6_price;
      cout << "Price after include 6% tax  :  RM"  << gstData->total_gst6 << endl;
      gstData->gst6_difftaxb4 = gstData->gst6_price - gstData->tax_before;
      cout << "Different price between before and after 6% GST  :  RM" << gstData->gst6_difftaxb4 << endl;
     // display the output
        
   cout << ".:: Developed by Pidaus ::.\n---------------------------------------------\n\n";
}
}
   return 0;
}
