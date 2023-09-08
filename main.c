#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


int main()
{

    int mode, count =0 , password,  id, age , admin_option , admin_repeat=1, user_option  , user_reapeat =1;
    char name[15];
    char gender[15];


    printf("\n\n\n");
    printf("            ************************ Welcome To Clinic System *************************\n");
    printf("\n\n\n");
    while (1)
    {


    printf("enter mode :\n");
    printf("                       1 - admin mode \n");
    printf("                       2 - user mode\n");
    scanf("%d",&mode);

    if( mode ==1 ) // admin mode
    {
        printf("enter password     :     ");
        scanf("%d",&password);
        while(password!=1234 && count<3)
        {
            printf("Wrong Password enter password again \n");
            printf("enter password     :     ");
            scanf("%d",&password);
            count++;
        }
        if(password !=1234 && count==3)
        {
            printf("Wrong Password\n");
            return 0;
        }
        else
        {
             admin_repeat =1;
            while( admin_repeat ==1)
            {


            printf("\n\nwelcome admin : ");
            printf("you can use this feature \n\n");
            printf("_____________________________\n");
            printf("1- Add_new_Patient_Record    |\n");
            printf("_____________________________|\n");
            printf("2- Edit_Patient_Record       |\n");
            printf("_____________________________|\n");
            printf("3- Reserve_Slot              |\n");
            printf("_____________________________|\n");
            printf("4- Cancel reservation        |\n");
            printf("_____________________________|\n");
            printf("\nyou can choose 1 - 2 - 3 - 4\n");

            scanf("%d",&admin_option);

            if(admin_option==1)
            {
                printf("enter id     : ");
                scanf("%d",&id);
                printf("enter name   : ");
                scanf("%s",&name);
                printf("enter age    : ");
                scanf("%d",&age);
                printf("enter gender : ");
                scanf("%s",&gender);
                admin_void_add_patient_record(name,age,gender,id);


            }
             else if(admin_option==2)
            {
                printf("enter id     : ");
                scanf("%d",&id);
                printf("enter name   : ");
                scanf("%s",&name);
                printf("enter age    : ");
                scanf("%d",&age);
                printf("enter gender : ");
                scanf("%s",&gender);
                admin_void_edit_patient_record(id,name,age,gender);

            }
            else if(admin_option==3)
            {

                printf("enter Id\n");
                scanf("%d",&id);
                admin_int_reserve_slot(id);

            }
           else if(admin_option==4)
            {
                printf("enter id\n");
                scanf("%d",&id);
                admin_void_cancel_reservation(id);
                printf("\navailable slot after your canceling : \n");
                view_slot();


            }
            printf("\nif you want to use another feature enter choose 1  else choose 0\n ");
            scanf("%d",&admin_repeat);

          }
        }
     }

   else if (mode == 2 ) // user mode
    {
        user_reapeat =1;
        while (user_reapeat ==1)
        {


        printf("welcome user : you can use this feature\n\n");
        printf("_____________________________\n");
        printf("1- View_Patient_Record       |\n");
        printf("_____________________________|\n");
        printf("2- View_Today_Reservations   |\n");
        printf("_____________________________|\n");

        printf("you can choose 1 - 2\n");
        scanf("%d",&user_option);
        if(user_option==1)
        {
            printf("enter id     : ");
            scanf("%d",&id);

            user_void_view_patient_record(id);

        }
        else if(user_option==2)
        {
            printf("Our Today Slot : \n");
            user_void_view_resrvation();

        }
       printf("\nif you want to use another feature enter choose  1  else choose 0\n ");
       scanf("%d",&user_reapeat);
     }

    }
 }
    return 0;
}
