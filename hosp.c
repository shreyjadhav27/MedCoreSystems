#include<stdio.h>
#include<string.h>


//--------------------------------------------------------------//

//FUNCTIONS 

void patientsign();
void patientlogin();
void PatientName();
void bookappoin();
void AllDetails();
void calculateBill();
void roombooking();


//-------------------------------------------------------------------//

//STRUCTURES 

struct sign{

      char name[100];
      long long int MobileNo;
      char pass[100];
      
    };
   
    struct sign l;

  //-----------------------------------------------------------------//                             

  struct appion{

    char day[30];
    char date[50];
    char time[20];
    char  disease[50];
    char doctorName[100];
    int age;
    char gender[20];

    };

  struct appion a;

  //-----------------------------------------------------------------//  

  struct info{

    char name[100];
    char pass[100];

  };

  struct info i;

  //--------------------------------------------------------------------//

  struct room{

    
    char name[100];
    int days;

  };
  struct room r;


    int loginSuccess = 0; 

//-------------------------------------------------------------------//

  int main(){

    
   printf("\n\n");
printf("=====================================================================\n");
printf("||                                                                 ||\n");
printf("||                     WELCOME TO MEDCORE SYSTEMS                  ||\n");
printf("||         -------------------------------------------------       ||\n");
printf("||             Healthcare Software Solutions Powered By C          ||\n");
printf("||                                                                 ||\n");
printf("=====================================================================\n");
printf("||                                                                 ||\n");
printf("||        Patient Management  |  Billing  |  Room Booking         ||\n");
printf("||                                                                 ||\n");
printf("=====================================================================\n");
    
    printf("\n");

    char ch;

    label:

   printf("\n");
printf("==========================================");
printf("\n         MEDCORE MAIN MENU");
printf("\n========================================");

printf("\n\t[A] SIGNUP");
printf("\n\t[B] LOGIN");
printf("\n\t[C] EXIT");

printf("\n\n========================================");

printf("\nEnter Your Choice : ");
 scanf(" %c",&ch);

    if(ch=='A' || ch=='B' || ch=='C'){
    switch(ch){

      case 'A':

       patientsign();
       
         break;

      case 'B':

      patientlogin();

         break;

      case 'C':

        printf("Thanku..!!!");
          return 0;

         break;
    }
  }
    else{
      printf("Enter Valid Character Thanku..!!!");
       return 0;
    }
    
    if(ch=='A' || ch=='B'){
     printf("\n");
printf("====================================");
printf("\n         LOGIN MENU");
printf("\n====================================");

printf("\n\t[A] LOGIN");
printf("\n\t[B] EXIT");

printf("\n\n====================================");
printf("\nEnter Your Choice : ");
scanf(" %c",&ch);

    switch (ch){

      case 'A':

       patientlogin();
       
         break;

     

      case 'B':

        printf("Thanku..!!!");
    
          return 0;

         break;
    
  }
}
  else{
    printf("Enter Valid Character Thanku..!!!");
    return 0;
  }
      if(loginSuccess == 0){

                
     printf("\nTry Again...\n");
       return 0;
}

    printf("\nHow can WE help u...?\n");

    int num;
    char name[100];
    char pass[100];

   
    printf("\nWHAT KIND OF INFORMATION DO U WANT...?\n");

    printf("\nJust Enter a number : \n");

     while(1){

   printf("\n");
printf("====================================================");
printf("\n              MEDCORE DASHBOARD");
printf("\n==================================================");

printf("\n\t[1] Book Patient Appointment");
printf("\n\t[2] All Patient Details");
printf("\n\t[3] Total Bill");
printf("\n\t[4] Book Room");
printf("\n\t[0] Exit");

printf("\n\n==================================================");

printf("\nEnter Your Choice : ");
scanf("%d",&num);

    if(num==0){

    printf("Returning To Main Menu...\n");
    goto label;
}

     else{

    
     if( loginSuccess == 1){

      //------------------------------------------------------------------------------//

    switch(num){

   
     case 1: 
            bookappoin();
           break;

           //This case shows the information of Patient
     case 2:
           AllDetails();
              break;
              
           //This case is used for Calculating the Bill

      case 3:
           calculateBill();

            break;

            //ThiS Case Used For Room Booking

      case 4:
          roombooking();

           break;
                   
    default:
    printf("Enter valid number");
           break;

}
        }

   //---------------------------------------------------------------------------------//
    
    else {
        printf(" Can not identified User name ");
    }
   }
  }
    return 0;
   }
  

  //----------------------------------------------------------------------------------------//

  void patientsign(){

  
     printf("Enter Patient Name : ");
     scanf(" %[^\n]", l.name);
   

     printf("\n");
do{
    printf("Enter Mobile Number : ");
    scanf("%lld", &l.MobileNo);

    if(l.MobileNo < 1000000000 || l.MobileNo > 9999999999)
    {
      printf("Invalid Number !!"); 
      printf("Enter 10 digit number only!\n");
    }

} while(l.MobileNo < 1000000000 || l.MobileNo > 9999999999);


    printf("\n");

    printf("Enter Password : ");
    scanf("%s",l.pass);

    loginSuccess = 1;

   printf("\n\n");
printf("*****************************************************");
printf("\n\t        WELCOME TO MEDCORE SYSTEM");
printf("\n*****************************************************");

printf("\n\n\t\tYOUR INFORMATION");
printf("\n-----------------------------------------------------");

printf("\n\tPatient Name      : %s", l.name);
printf("\n\tPatient Mobile No : %lld", l.MobileNo);
printf("\n\tPatient Password  : %s", l.pass);

printf("\n-----------------------------------------------------");
printf("\n\t  Thank You For Visiting MedCore");
printf("\n*****************************************************");
    

  }
  //--------------------------------------------------------------------//

  void patientlogin(){

    
    char name[100], pass[100];

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", name);

    printf("\nEnter Password : ");
    scanf("%s", pass);

    if(strcmp(name, l.name)==0 && strcmp(pass, l.pass)==0){

     printf("\n-----------------------------------\n");

        printf("\nLogin Successful!");

     printf("\n-----------------------------------\n");

         loginSuccess = 1; 

    }
    else{

        printf("\nInvalid Username or Password\n");
         loginSuccess = 0; 

         printf("Thanku!!!");

         return;
         
    }

  }

  //-----------------------------------------------------------------------//


  //------------------------------------------------------------------------//
  
   void bookappoin(){

    printf("\nEnter Day : ");
    scanf(" %[^\n]", a.day);
    

    printf("Enter Date (DD MON YR): ");
    scanf(" %[^\n]", a.date);

    printf("Enter Time (00:00 AM/PM): ");
    scanf(" %[^\n]", a.time);

    printf("Enter Disease : ");
    scanf(" %[^\n]", a.disease);

    printf("\n\n");
printf("=============================================================\n");
printf("                    MEDCORE DOCTOR LIST                      \n");
printf("=============================================================\n");

printf("  [1] Dr. Arjun Mehta     - Cardiologist\n");
printf("-------------------------------------------------------------\n");

printf("  [2] Dr. Priya Sharma    - Neurologist\n");
printf("-------------------------------------------------------------\n");

printf("  [3] Dr. Rahul Verma     - Orthopedic Surgeon\n");
printf("-------------------------------------------------------------\n");

printf("  [4] Dr. Sneha Patil     - Pediatrician\n");
printf("-------------------------------------------------------------\n");

printf("  [5] Dr. Vikram Joshi    - Dermatologist\n");
printf("-------------------------------------------------------------\n");

printf("  [6] Dr. Anjali Desai    - General Physician\n");

printf("=============================================================\n");

    printf("\nEnter Doctor Name : ");
    scanf(" %[^\n]", a.doctorName);

    printf("Enter Age : ");
    scanf("%d", &a.age);

    printf("Enter Gender : ");
    scanf(" %[^\n]", a.gender);

   printf("\n\n\n");
printf("===============================================================\n");
printf("                APPOINTMENT SUCCESSFULLY BOOKED                \n");
printf("===============================================================\n");

printf("  Appointment ID   : %s.@123hosp\n", l.name);
printf("---------------------------------------------------------------\n");

printf("  Patient Name     : %s\n", l.name);
printf("  Mobile Number    : %lld\n", l.MobileNo);
printf("  Doctor Name      : %s\n", a.doctorName);
printf("  Disease          : %s\n", a.disease);
printf("  Day              : %s\n", a.day);
printf("  Date             : %s\n", a.date);
printf("  Time             : %s\n", a.time);
printf("  Age              : %d\n", a.age);
printf("  Gender           : %s\n", a.gender);
printf("  Booking Charge   : 200 Rs\n");

printf("===============================================================\n");
printf("            THANK YOU FOR CHOOSING MEDCORE SYSTEM !!!          \n");
printf("===============================================================\n");
}
  
//-----------------------------------------------------------------------//

void AllDetails(){

      printf("\n\n");
printf("=====================================================\n");
printf("                 PATIENT DETAILS                     \n");
printf("=====================================================\n");

printf("  1] Patient ID   : %s.@123hosp\n", l.name);
printf("-----------------------------------------------------\n");

printf("  2] Name         : %s\n", l.name);
printf("  3] Age          : %d\n", a.age);
printf("  4] Gender       : %s\n", a.gender);
printf("  5] Disease      : %s\n", a.disease);
printf("  6] Contact      : %lld\n", l.MobileNo);

printf("=====================================================\n");

        printf("\n\n");

}
//-----------------------------------------------------------------------//

void roombooking(){

    int n, i;

    char name[5][100];   // stores 5 names
    long long int Mno [5][20];

    printf("Enter No of persons (up to 5): ");
    scanf("%d", &n);

    printf("Enter The No Of Days : ");
    scanf("%d", &r.days);

    int roomNo;

    printf("Enter Room Number : ");
    scanf("%d", &roomNo);

    // INPUT NAMES
    for(i = 0; i < n; i++){

        printf("Enter Person Name %d : ", i + 1);
        scanf(" %[^\n]", name[i]);

       do{
      printf("Enter Mobile Number : ");
      scanf("%lld", &l.MobileNo);

      if(l.MobileNo < 1000000000 || l.MobileNo > 9999999999)
     {
        printf("Enter 10 digit number only!\n");
     }

     }
 while(l.MobileNo < 1000000000 || l.MobileNo > 9999999999);

    }

    // PRINTING
    printf("\n\n");
    printf("=================================================================\n");
    printf("                    ROOM BOOKING CERTIFICATE                     \n");
    printf("=================================================================\n");

    for(i = 0; i < n; i++){

        printf("  Patient Name %d   : %s\n\n", i + 1, name[i]);

        printf("  Patient Contact %d   : %lld\n\n", i + 1, Mno[i]);
    }

    printf("-----------------------------------------------------------------\n");

    printf("  Room Number       : %d\n", roomNo);
    printf("  Days Booked       : %d\n", r.days);
    printf("  Room Charge       : 300 Rs Per Day\n");
    printf("  Total Bill        : %d Rs\n", 300 * n * r.days);

    printf("=================================================================\n");
    printf("                 ROOM SUCCESSFULLY BOOKED!                      \n");
    printf("=================================================================\n");

    printf("\n---------------------------------------------------------------\n");
    printf("  [#] Bill Generated And Marked As PAID Successfully\n");
    printf("  Thank You For Choosing MedCore Systems Hospital\n");
    printf("---------------------------------------------------------------\n");
}



//----------------------------------------------------------------------------//
  void calculateBill(){

    int sum=0,d;

   
     printf("Tell Me The number of days of Medicine Course : \n");
     scanf("%d",&d);

                
     
    int arr[10] = {500,100,150,200,250,300,350,400,450,500};

     for(int i=0;i<10;i++){
      sum=sum+arr[i];
     }

printf("\n\n");
printf("=====================================================\n");
printf("           MEDICINES FOR %s DISEASE                 \n", a.disease);
printf("=====================================================\n");

printf(" No.   Medicine Name           Price\n");
printf("-----------------------------------------------------\n");

printf(" [1]   Paracetamol          Rs %d\n", arr[0]);
printf(" [2]   Dolo 650             Rs %d\n", arr[1]);
printf(" [3]   Azithromycin         Rs %d\n", arr[2]);
printf(" [4]   Cetirizine           Rs %d\n", arr[3]);
printf(" [5]   Amoxicillin          Rs %d\n", arr[4]);
printf(" [6]   Pantoprazole         Rs %d\n", arr[5]);
printf(" [7]   Crocin               Rs %d\n", arr[6]);
printf(" [8]   Insulin Injection    Rs %d\n", arr[7]);
printf(" [9]   Pain Relief Gel      Rs %d\n", arr[8]);
printf(" [10]  Vitamin Tablets      Rs %d\n", arr[9]);

printf("=====================================================\n");

printf("       Total                Rs %d\n",sum);
printf("=====================================================\n");

         
     int sm=0;
    // Extra Facilities Charges
 int arr1[5] = {50,50,40,100,60};
 
 for(int i = 0; i < 5; i++){
    sm = sm + arr1[i];
}

 printf("\n\n");
 printf("=====================================================\n");
 printf("                EXTRA FACILITIES                     \n");
 printf("=====================================================\n");

 printf(" No.   Facility Name             Charge\n");
 printf("-----------------------------------------------------\n");

 printf(" [1]   WiFi Service           Rs %d\n", arr1[0]);
 printf(" [2]   TV Facility            Rs %d\n", arr1[1]);
 printf(" [3]   AC Room Service        Rs %d\n", arr1[2]);
 printf(" [4]   Food Service           Rs %d\n", arr1[3]);
 printf(" [5]   Nurse Assistance       Rs %d\n", (r.days)*arr1[4]);

 printf("-----------------------------------------------------\n");
 printf(" Total Extra Charges          Rs %d\n", sm);

 printf("=====================================================\n");

     printf("\n");
     printf("\n");
     printf("\n");

       printf("\n");
       printf("\n\n");
printf("====================================================================\n");
printf("                 MEDCORE SYSTEMS - OFFICIAL BILL                    \n");
printf("====================================================================\n");

printf("  Bill No.            : BILL-01\n");
printf("  Patient Name        : %s\n", l.name);
printf("  Doctor Name         : %s\n", a.doctorName);
printf("  Appointment Date    : %s\n", a.date);
printf("  Appointment Time    : %s\n", a.time);

printf("--------------------------------------------------------------------\n");
printf("  SERVICE DETAILS                                   AMOUNT (Rs)\n");
printf("--------------------------------------------------------------------\n");

printf("  Appointment Booking Charge                        : 200 Rs\n");
printf("--------------------------------------------------------------------\n");

printf("  Extra Facilities                                  : %d Rs\n", sm);
printf("--------------------------------------------------------------------\n");

printf("  %d Days Patient Room Charge                        : %d Rs\n", d, (sm) * (r.days));
printf("--------------------------------------------------------------------\n");

printf("  TOTAL BILL                                        : %d Rs\n",
       sm + (sum * d) + 200);

printf("====================================================================\n");
printf("                 PAYMENT STATUS : PAID SUCCESSFULLY !!              \n");
printf("====================================================================\n");

printf("\n");
printf("        Thank You For Choosing MedCore Systems Hospital !!!\n");
printf("====================================================================\n");
          
     
     printf("\n\n\n-------------------------------------------");
      printf("\n");
               
     
  }

  //----------------------------------------------------------------------------------------//
