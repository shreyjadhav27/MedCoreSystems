#include<stdio.h>
#include<string.h>

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

struct sign l;

//--------------------------------------------------------------//

struct appion{

    char day[30];
    char date[50];
    char time[20];
    //char disease[50];
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

//--------------------------------------------------------------//

int main(){

    printf("\n\n");
    printf("=====================================================================\n");
    printf("||                                                                 ||\n");
    printf("||                     WELCOME TO MEDCORE SYSTEMS                  ||\n");
    printf("||         -------------------------------------------------       ||\n");
    printf("||                    Healthcare Software Solutions                ||\n");
    printf("||                                                                 ||\n");
    printf("=====================================================================\n");

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
                    printf("==================================================");
                    printf("\n              MEDCORE DASHBOARD");
                    printf("\n==================================================");

                    printf("\n\t[1] Book Patient Appointment");
                    printf("\n\t[2] Generate Bill");
                    printf("\n\t[0] Logout");

                    printf("\n\n==================================================");

                    printf("\nEnter Your Choice : ");
                    scanf("%d",&num);

                    if(num == 0){

                        loginSuccess = 0;

                        printf("\nLogging Out...\n");

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

                            printf("\nEnter Valid Number!\n");
                    }
                }
            }

            break;

        case 'C':
        case 'c':

            printf("\nThank You For Using MedCore System!\n");
            return 0;

        default:

            printf("\nEnter Valid Character!\n");
    }

    goto label;
}

//--------------------------------------------------------------//

void patientsign(){

    int valid, i;

    printf("Enter Patient Name : ");
    scanf(" %[^\n]", l.name);

    printf("\n");

    do{

        valid = 1;

        printf("Enter Mobile Number : ");
        scanf("%s", l.MobileNo);

        if(strlen(l.MobileNo) != 10){

            valid = 0;
        }

        for(i = 0; l.MobileNo[i] != '\0'; i++){

            if(l.MobileNo[i] < '0' || l.MobileNo[i] > '9'){

                valid = 0;
                break;
            }
        }

        if(valid == 0){

            printf("Invalid Mobile Number!\n");
            printf("Enter Only 10 Digit Numbers!\n");
        }

    } while(valid == 0);

    printf("\n");

    printf("Enter Password : ");
    scanf("%s", l.pass);

    printf("\n\n");
    printf("*****************************************************");
    printf("\n\t        WELCOME TO MEDCORE SYSTEM");
    printf("\n*****************************************************");

    printf("\n\n\t\tYOUR INFORMATION");
    printf("\n-----------------------------------------------------");

    printf("\n\tPatient Name      : %s", l.name);
    printf("\n\tPatient Mobile No : %s", l.MobileNo);

    printf("\n-----------------------------------------------------");
    printf("\n\t  Thank You For Visiting MedCore");
    printf("\n*****************************************************");
}

//--------------------------------------------------------------//

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
    }
}

//--------------------------------------------------------------//

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

    printf("\nEnter Day : ");
    scanf(" %[^\n]", a.day);

    printf("Enter Date (DD MON YR): ");
    scanf(" %[^\n]", a.date);

    //printf("Enter Disease : ");
    //scanf(" %[^\n]", a.disease);

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

    printf("\nEnter Doctor Choice : ");
    scanf("%d", &choice);

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

    printf("\nAvailable Time Slots:\n");

    switch(choice){

        case 1:

            printf("\n[1] %s", slots[0][0]);
            printf("\n[2] %s", slots[0][1]);
            printf("\n[3] %s", slots[0][2]);
            printf("\n[4] %s", slots[0][3]);
            break;

        case 2:

            printf("\n[1] %s", slots[1][0]);
            printf("\n[2] %s", slots[1][1]);
            printf("\n[3] %s", slots[1][2]);
            printf("\n[4] %s", slots[1][3]);
            break;

        case 3:

            printf("\n[1] %s", slots[2][0]);
            printf("\n[2] %s", slots[2][1]);
            printf("\n[3] %s", slots[2][2]);
            printf("\n[4] %s", slots[2][3]);
            break;

        case 4:

            printf("\n[1] %s", slots[3][0]);
            printf("\n[2] %s", slots[3][1]);
            printf("\n[3] %s", slots[3][2]);
            printf("\n[4] %s", slots[3][3]);
            break;

        case 5:

            printf("\n[1] %s", slots[4][0]);
            printf("\n[2] %s", slots[4][1]);
            printf("\n[3] %s", slots[4][2]);
            printf("\n[4] %s", slots[4][3]);
            break;

        case 6:

            printf("\n[1] %s", slots[5][0]);
            printf("\n[2] %s", slots[5][1]);
            printf("\n[3] %s", slots[5][2]);
            printf("\n[4] %s", slots[5][3]);
            break;
    }

    printf("\n\nSelect Time Slot : ");
    scanf("%d", &slotChoice);

    if(booked[choice-1][slotChoice-1] == 1 &&
       strcmp(bookedDate[choice-1][slotChoice-1], a.date) == 0){

        printf("\n\nThis Time Slot Is Already Booked On %s\n", a.date);

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
    printf("  Mobile Number    : %s\n", l.MobileNo);
    printf("  Doctor Name      : %s\n", a.doctorName);
    //printf("  Disease          : %s\n", a.disease);
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

//--------------------------------------------------------------//

void calculateBill(){

    int appointmentCharge = 200;

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

    printf("  Appointment Booking Charge                        : %d Rs\n", appointmentCharge);

    printf("--------------------------------------------------------------------\n");

    printf("  TOTAL BILL                                        : %d Rs\n",
           appointmentCharge);

    printf("====================================================================\n");
    printf("                 PAYMENT STATUS : PAID SUCCESSFULLY !!              \n");
    printf("====================================================================\n");

    printf("\n");
    printf("        Thank You For Choosing MedCore Systems Hospital !!!\n");
    printf("====================================================================\n");
}
