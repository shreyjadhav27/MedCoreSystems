#include<stdio.h>
#include<string.h>

//=====================================================================//
//                    MEDCORE HEALTHCARE SYSTEM                        //
//=====================================================================//

//--------------------------------------------------------------//
// FUNCTIONS

void patientsign();
void patientlogin();
void bookappoin();
void calculateBill();

//--------------------------------------------------------------//
// STRUCTURES

struct sign{

    char name[100];
    char MobileNo[11];
    char pass[100];

};

// ARRAY FOR MULTIPLE ACCOUNTS
struct sign l[10];

int totalUsers = 0;
int currentUser = -1;

//--------------------------------------------------------------//

struct appion{

    char day[30];
    char date[50];
    char time[20];
    char doctorName[100];
    int age;
    char gender[20];

};

struct appion a;

//--------------------------------------------------------------//

int loginSuccess = 0;

// SLOT BOOKING SYSTEM

int booked[6][4] = {0};
char bookedDate[6][4][50];

//=====================================================================//
//                              MAIN                                   //
//=====================================================================//

int main(){

    printf("\n\n");

    printf("=====================================================================\n");
    printf("||                                                                 ||\n");
    printf("||                 WELCOME TO MEDCORE SYSTEMS                      ||\n");
    printf("||         ---------------------------------------------           ||\n");
    printf("||               ADVANCED HEALTHCARE MANAGEMENT                    ||\n");
    printf("||                                                                 ||\n");
    printf("=====================================================================\n");

    char ch;

label:

    printf("\n");
    printf("=====================================================================\n");
    printf("                         MEDCORE MAIN MENU                          \n");
    printf("=====================================================================\n");

    printf("\n\t[A] SIGNUP");
    printf("\n\t[B] LOGIN");
    printf("\n\t[C] EXIT");

    printf("\n\n=====================================================================\n");

    printf("\nEnter Your Choice : ");
    scanf(" %c",&ch);

    switch(ch){

        case 'A':
        case 'a':

            patientsign();
            break;

        case 'B':
        case 'b':

            patientlogin();

            if(loginSuccess == 1){

                int num;

                while(1){

                    printf("\n");
                    printf("=====================================================================\n");
                    printf("                         MEDCORE DASHBOARD                          \n");
                    printf("=====================================================================\n");

                    printf("\n\t[1] Book Patient Appointment");
                    printf("\n\t[2] Generate Bill");
                    printf("\n\t[0] Logout");

                    printf("\n\n=====================================================================\n");

                    printf("\nEnter Your Choice : ");
                    scanf("%d",&num);

                    while(getchar()!='\n');

                    if(num == 0){

                        loginSuccess = 0;

                        printf("\nLogging Out Successfully...\n");

                        goto label;
                    }

                    switch(num){

                        case 1:

                            bookappoin();
                            break;

                        case 2:

                            calculateBill();
                            break;

                        default:

                            printf("\nInvalid Choice! Please Enter Valid Number.\n");
                    }
                }
            }

            break;

        case 'C':
        case 'c':

            printf("\n====================================================\n");
            printf(" Thank You For Using MedCore Healthcare System !!!\n");
            printf("====================================================\n");

            return 0;

        default:

            printf("\nInvalid Character Entered!\n");
    }

    goto label;
}

//=====================================================================//
//                           SIGNUP                                    //
//=====================================================================//

void patientsign(){

    int valid, i;
    char tempName[100];
    char tempMobile[11];
    char tempPass[100];

    if(totalUsers >= 10){

        printf("\nMaximum User Limit Reached!\n");
        return;
    }

    printf("\n");
    printf("=====================================================================\n");
    printf("                         PATIENT SIGNUP                             \n");
    printf("=====================================================================\n");

    printf("\nEnter Patient Name : ");
    scanf(" %[^\n]", tempName);

    printf("\n");

    do{

        valid = 1;

        printf("Enter Mobile Number : ");
        scanf("%s", tempMobile);

        if(strlen(tempMobile) != 10){

            valid = 0;
        }

        for(i = 0; tempMobile[i] != '\0'; i++){

            if(tempMobile[i] < '0' || tempMobile[i] > '9'){

                valid = 0;
                break;
            }
        }

        if(valid == 0){

            printf("\nInvalid Mobile Number!\n");
            printf("Enter Only 10 Digit Numbers!\n\n");
        }

    } while(valid == 0);

    printf("\n");

    printf("Enter Password : ");
    scanf("%s", tempPass);

    // CHECK DUPLICATE ACCOUNT

    for(i = 0; i < totalUsers; i++){

        if(strcmp(tempName, l[i].name) == 0 &&
           strcmp(tempMobile, l[i].MobileNo) == 0 &&
           strcmp(tempPass, l[i].pass) == 0){

            printf("\n=====================================================================\n");
            printf("               ACCOUNT ALREADY EXISTS                               \n");
            printf("=====================================================================\n");

            return;
        }
    }

    strcpy(l[totalUsers].name, tempName);
    strcpy(l[totalUsers].MobileNo, tempMobile);
    strcpy(l[totalUsers].pass, tempPass);

    printf("\n");
    printf("=====================================================================\n");
    printf("                    SIGNUP SUCCESSFUL                               \n");
    printf("=====================================================================\n");

    printf("\nPatient Name      : %s", l[totalUsers].name);
    printf("\nMobile Number     : %s", l[totalUsers].MobileNo);

    printf("\n\n=====================================================================\n");
    printf("            THANK YOU FOR REGISTERING WITH MEDCORE                  \n");
    printf("=====================================================================\n");

    totalUsers++;
}

//=====================================================================//
//                              LOGIN                                  //
//=====================================================================//

void patientlogin(){

    char name[100], pass[100];
    int i, found = 0;

    printf("\n");
    printf("=====================================================================\n");
    printf("                          PATIENT LOGIN                             \n");
    printf("=====================================================================\n");

    printf("\nEnter Patient Name : ");
    scanf(" %[^\n]", name);

    printf("\nEnter Password : ");
    scanf("%s", pass);

    for(i = 0; i < totalUsers; i++){

        if(strcmp(name, l[i].name)==0 &&
           strcmp(pass, l[i].pass)==0){

            found = 1;
            currentUser = i;
            break;
        }
    }

    if(found == 1){

        printf("\n=====================================================================\n");
        printf("                     LOGIN SUCCESSFUL                               \n");
        printf("=====================================================================\n");

        loginSuccess = 1;
    }

    else{

        printf("\n=====================================================================\n");
        printf("                 INVALID USERNAME OR PASSWORD                       \n");
        printf("=====================================================================\n");

        loginSuccess = 0;
    }
}

//=====================================================================//
//                      BOOK APPOINTMENT                               //
//=====================================================================//

void bookappoin(){

    char slots[6][4][20] = {

        {"10:00 AM", "11:00 AM", "12:00 PM", "1:00 PM"},
        {"2:00 PM", "3:00 PM", "4:00 PM", "5:00 PM"},
        {"9:00 AM", "10:00 AM", "11:00 AM", "12:00 PM"},
        {"1:00 PM", "2:00 PM", "3:00 PM", "4:00 PM"},
        {"5:00 PM", "6:00 PM", "7:00 PM", "8:00 PM"},
        {"8:00 AM", "9:00 AM", "10:00 AM", "11:00 AM"}

    };

    int choice, slotChoice;

    printf("\n");
    printf("=====================================================================\n");
    printf("                    BOOK APPOINTMENT                                \n");
    printf("=====================================================================\n");

    printf("\nEnter Day : ");
    scanf(" %[^\n]", a.day);

    printf("Enter Date (DD MON YYYY): ");
    scanf(" %[^\n]", a.date);

    printf("\n");
    printf("=====================================================================\n");
    printf("                        MEDCORE DOCTOR LIST                         \n");
    printf("=====================================================================\n");

    printf(" [1] Dr. Arjun Mehta      - Cardiologist\n");
    printf("---------------------------------------------------------------------\n");

    printf(" [2] Dr. Priya Sharma     - Neurologist\n");
    printf("---------------------------------------------------------------------\n");

    printf(" [3] Dr. Rahul Verma      - Orthopedic Surgeon\n");
    printf("---------------------------------------------------------------------\n");

    printf(" [4] Dr. Sneha Patil      - Pediatrician\n");
    printf("---------------------------------------------------------------------\n");

    printf(" [5] Dr. Vikram Joshi     - Dermatologist\n");
    printf("---------------------------------------------------------------------\n");

    printf(" [6] Dr. Anjali Desai     - General Physician\n");

    printf("=====================================================================\n");

    printf("\nEnter Doctor Choice : ");
    scanf("%d", &choice);

    while(getchar()!='\n');

    switch(choice){

        case 1:
            strcpy(a.doctorName, "Dr. Arjun Mehta");
            break;

        case 2:
            strcpy(a.doctorName, "Dr. Priya Sharma");
            break;

        case 3:
            strcpy(a.doctorName, "Dr. Rahul Verma");
            break;

        case 4:
            strcpy(a.doctorName, "Dr. Sneha Patil");
            break;

        case 5:
            strcpy(a.doctorName, "Dr. Vikram Joshi");
            break;

        case 6:
            strcpy(a.doctorName, "Dr. Anjali Desai");
            break;

        default:
            printf("\nInvalid Doctor Choice!\n");
            return;
    }

    printf("\n");
    printf("=====================================================================\n");
    printf("                     AVAILABLE TIME SLOTS                           \n");
    printf("=====================================================================\n");

    switch(choice){

        case 1:{

            int i;

            for(i=0;i<4;i++){

                printf("\n[%d] %-10s",i+1,slots[0][i]);

                if(booked[0][i]==1 &&
                   strcmp(bookedDate[0][i],a.date)==0){

                    printf(" --> BOOKED");
                }

                else{

                    printf(" --> AVAILABLE");
                }
            }

            break;

        }

        case 2:{

            int i;

            for(i=0;i<4;i++){

                printf("\n[%d] %-10s",i+1,slots[1][i]);

                if(booked[1][i]==1 &&
                   strcmp(bookedDate[1][i],a.date)==0){

                    printf(" --> BOOKED");
                }

                else{

                    printf(" --> AVAILABLE");
                }
            }

            break;
        }

        case 3:{

            int i;

            for(i=0;i<4;i++){

                printf("\n[%d] %-10s",i+1,slots[2][i]);

                if(booked[2][i]==1 &&
                   strcmp(bookedDate[2][i],a.date)==0){

                    printf(" --> BOOKED");
                }

                else{

                    printf(" --> AVAILABLE");
                }
            }

            break;
        }

        case 4:{

            int i;

            for(i=0;i<4;i++){

                printf("\n[%d] %-10s",i+1,slots[3][i]);

                if(booked[3][i]==1 &&
                   strcmp(bookedDate[3][i],a.date)==0){

                    printf(" --> BOOKED");
                }

                else{

                    printf(" --> AVAILABLE");
                }
            }

            break;
        }

        case 5:{

            int i;

            for(i=0;i<4;i++){

                printf("\n[%d] %-10s",i+1,slots[4][i]);

                if(booked[4][i]==1 &&
                   strcmp(bookedDate[4][i],a.date)==0){

                    printf(" --> BOOKED");
                }

                else{

                    printf(" --> AVAILABLE");
                }
            }

            break;
        }

        case 6:{

            int i;

            for(i=0;i<4;i++){

                printf("\n[%d] %-10s",i+1,slots[5][i]);

                if(booked[5][i]==1 &&
                   strcmp(bookedDate[5][i],a.date)==0){

                    printf(" --> BOOKED");
                }

                else{

                    printf(" --> AVAILABLE");
                }
            }

            break;
        }
    }

    printf("\n\nSelect Time Slot : ");
    scanf("%d", &slotChoice);

    while(getchar()!='\n');

    if(booked[choice-1][slotChoice-1] == 1 &&
       strcmp(bookedDate[choice-1][slotChoice-1], a.date) == 0){

        printf("\n=====================================================================\n");
        printf("            THIS SLOT IS ALREADY BOOKED                             \n");
        printf("=====================================================================\n");

        return;
    }

    switch(choice){

        case 1:
            strcpy(a.time, slots[0][slotChoice - 1]);
            break;

        case 2:
            strcpy(a.time, slots[1][slotChoice - 1]);
            break;

        case 3:
            strcpy(a.time, slots[2][slotChoice - 1]);
            break;

        case 4:
            strcpy(a.time, slots[3][slotChoice - 1]);
            break;

        case 5:
            strcpy(a.time, slots[4][slotChoice - 1]);
            break;

        case 6:
            strcpy(a.time, slots[5][slotChoice - 1]);
            break;
    }

    booked[choice-1][slotChoice-1] = 1;

    strcpy(bookedDate[choice-1][slotChoice-1], a.date);

    printf("\nEnter Age : ");
    scanf("%d", &a.age);

    while(getchar()!='\n');

    printf("Enter Gender : ");
    scanf(" %[^\n]", a.gender);

    printf("\n");
    printf("=====================================================================\n");
    printf("               APPOINTMENT SUCCESSFULLY BOOKED                      \n");
    printf("=====================================================================\n");

    printf(" Appointment ID   : %s@123HOSP\n", l[currentUser].name);

    printf("---------------------------------------------------------------------\n");

    printf(" Patient Name     : %s\n", l[currentUser].name);
    printf(" Mobile Number    : %s\n", l[currentUser].MobileNo);
    printf(" Doctor Name      : %s\n", a.doctorName);
    printf(" Day              : %s\n", a.day);
    printf(" Date             : %s\n", a.date);
    printf(" Time             : %s\n", a.time);
    printf(" Age              : %d\n", a.age);
    printf(" Gender           : %s\n", a.gender);
    printf(" Booking Charge   : 200 Rs\n");

    printf("=====================================================================\n");
    printf("           THANK YOU FOR CHOOSING MEDCORE SYSTEM                    \n");
    printf("=====================================================================\n");
}

//=====================================================================//
//                        CALCULATE BILL                               //
//=====================================================================//

void calculateBill(){

    int appointmentCharge = 200;

    printf("\n");
    printf("=====================================================================\n");
    printf("                  MEDCORE OFFICIAL BILL                             \n");
    printf("=====================================================================\n");

    printf(" Bill No.            : BILL-01\n");
    printf(" Patient Name        : %s\n", l[currentUser].name);
    printf(" Doctor Name         : %s\n", a.doctorName);
    printf(" Appointment Date    : %s\n", a.date);
    printf(" Appointment Time    : %s\n", a.time);

    printf("---------------------------------------------------------------------\n");

    printf(" SERVICE DETAILS                                   AMOUNT (Rs)\n");

    printf("---------------------------------------------------------------------\n");

    printf(" Appointment Booking Charge                        : %d Rs\n",
           appointmentCharge);

    printf("---------------------------------------------------------------------\n");

    printf(" TOTAL BILL                                        : %d Rs\n",
           appointmentCharge);

    printf("=====================================================================\n");
    printf("                PAYMENT STATUS : PAID                               \n");
    printf("=====================================================================\n");

    printf("\n");
    printf("         THANK YOU FOR VISITING MEDCORE HOSPITAL                    \n");

    printf("=====================================================================\n");
}
