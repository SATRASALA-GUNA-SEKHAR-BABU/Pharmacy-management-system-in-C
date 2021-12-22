#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct
{
  char drug_name[30];
  int drug_code;
  int drug_count;
}medicine;

int add_cdrug(medicine a[],medicine b[],int c)
{
  int i,code;
  printf("Enter the Drug code to be added :");
  scanf("%d",&code);
  for(i=0;i<c;i++)
  {
    if(b[i].drug_code==code) 
    { 
      int Qu;
      printf("Enter the Quantity :");
      scanf("%d",&Qu);
       if(Qu>b[i].drug_count){ printf("Not sufficient Quantity in Pharmacy!!\n"); break;}
      else {
        printf("\nMedcine Added THANK YOU!!!\n");
        strcpy(a[0].drug_name,b[i].drug_name);  
        a[0].drug_code=b[i].drug_code; 
        a[0].drug_count=Qu;
        //a[i]=b[i];
        return 1;
      }
      
    }
  }
    
      printf("\nEnter the Correct Drug code!!!\n ");
      return 0;
    

}



void print_cart(medicine cmed[],int ctotal,medicine med[])
{
  if(ctotal>0){
  int c=0;
  printf("----Drug Code \t Drug Name\t\tQuantity -----------\n");
  for(int i=0;i<ctotal;i++)
  {
    printf("\t%6d \t  %13s \t %5d\n",cmed[i].drug_code,cmed[i].drug_name,cmed[i].drug_count);
    c=c+cmed[i].drug_count;
    //amt=amt+(cmed[i].drug_count*med[i].drug_count[i]);
  }
  printf("\nThe Total Quantity %d :\n",c);
  }
  else printf("Cart Empty!!!\n");
}





int add_drug(medicine med[],int total)
{ 
  if(total<=25){
  char arr[20];
  printf("Enter the drug name:"); scanf("%s",arr); strcpy(med[total].drug_name,arr);
  printf("Enter the drug code:"); scanf("%d",&(med[total].drug_code));
  printf("Enter the drug quantity:"); scanf("%d",&(med[total].drug_count));
  printf("\nThe Drug added successfully!!!\n");
  return 1;
  }
  else return 0;
}



int delete_drug(medicine med[],int total){
  printf("\nEnter the drug code to be deleted :");
  int code,t;
  scanf("%d",&code);
  for(t=0;t<total;t++) 
  {
    if((med[t].drug_code)==code) break;;
  }
  if(t==total) {printf("\nEnter the correct Drug code!!!"); return 0;}
  else{
  for(int i=t;i<total;i++)
  {
    strcpy(med[i].drug_name,med[i+1].drug_name);
    med[i].drug_code=med[i+1].drug_code;
    med[i].drug_count=med[i+1].drug_count;
    printf("\nThe Drug Deleted successfully!!!\n");
  }
  return 1;
  }
  
}





void update_drug(medicine med[],int total){
  printf("\nEnter the drug code to be updated :");
  int code,t;
  scanf("%d",&code);
  for(t=0;t<total;t++) 
  {
    if((med[t].drug_code)==code) break;
  }
  if(t==total) printf("\nEnter the correct Drug code!!!");
  else{
    printf("Enter the Quantity to be updated :");
    int k;
    scanf("%d",&k);
    med[t].drug_count=k;
    printf("\nThe Drug updated successfully!!!\n");
  }
}




void print_stock(medicine med[],int total)
{ 
  if(total>0)
  {
  printf("----Drug Code \t Drug Name\t\tQuantity -----------\n");
  for(int i=0;i<total;i++)
  {
    printf("\t%6d \t  %13s \t %5d\n",med[i].drug_code,med[i].drug_name,med[i].drug_count);
  }
  }
  else printf("\nEmpty cart !!!\n");
}






int main(void) {
  char c;
  int total,ctotal=0;
  medicine med[25],cmed[25];
  strcpy(med[0].drug_name,"Amoxicillin");    med[0].drug_code=8576;  med[0].drug_count=34;
  strcpy(med[1].drug_name,"Vitamin D");      med[1].drug_code=9457;  med[1].drug_count=20;
  strcpy(med[2].drug_name,"Ibuprofen");      med[2].drug_code=3478;  med[2].drug_count=41;
  strcpy(med[3].drug_name,"Azithromycin");   med[3].drug_code=4123;  med[3].drug_count=12;
  strcpy(med[4].drug_name,"Cephalexin");     med[4].drug_code=1789;  med[4].drug_count=39;
  strcpy(med[5].drug_name,"Prednisone");     med[5].drug_code=9872;  med[5].drug_count=45;
  strcpy(med[6].drug_name,"Lisinopril");     med[6].drug_code=3654;  med[6].drug_count=50;
  total=7;
  int c1;
  

  printf("                       WELCOME!"
         "\n               ...  ONLINE PHARMACY..."
         "\n          All your medicines in one place!!!");

  printf("\n\nAre you the pharmacist(p) or a customer(c) ?(p/c) :");

  scanf("%c",&c);
   switch (c) {

  case 'p':
    while(1){
    printf("\n\nWhat would you like to do?"
             "\n1.Add drug"
             "\n2.Delete drug"
             "\n3.Update drug"
             "\n4.View inventory"
             "\n5.Logout\n");
      printf("Enter the choice :");
      scanf("%d", &c1);
     
      switch (c1) {

      case 1:

        total+=add_drug(med,total);
        
        break;

      case 2:

        total-=delete_drug(med,total);
        
        break;

      case 3:

        update_drug(med,total);
        break;

      case 4:

        print_stock(med,total);
        break;

      case 5:

        exit(0);
        break;

      default:

        printf("\nInvalid choice!!! Please try again.....");
        break;
      }}
         break;
  case 'c':
  
     while(1){
       
       char c2;
        printf("\nWhat would you like to do ? "
               "\n1.Add to cart."
               "\n2.Delete from cart."
               "\n3.Clear cart "
               "\n4.Buy."
               "\n5.View cart."
               "\n6.View medicines."
               "\n7.Logout.\n");
       printf("Enter the choice :");
       scanf("%d", &c1);
       switch (c1) {
        case 1:
        
        ctotal+=add_cdrug(cmed,med,total);
        
        break;

      case 2:

        ctotal-=delete_drug(cmed,ctotal);
        
        break;

      case 3:

        ctotal=0;
        break;
      case 4:
        print_cart(cmed,ctotal,med);
        break;
      case 5:

        print_stock(cmed,ctotal);
        break;
      case 6:

        print_stock(med,total);
        break;

      case 7:

        exit(0);
        break;

      default:

        printf("\nInvalid choice!!! Please try again.....");
        break;

       }
       
     }break;

  default : printf("\nEnter valid input!!!!");
}
return 0;
}

