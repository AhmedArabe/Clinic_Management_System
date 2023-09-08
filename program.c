
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

int array[5]={AVILABLE,AVILABLE,AVILABLE,AVILABLE,AVILABLE};
char array_2d[5][16] =
{   {"2 pm to 2:30 pm"},{"2:30 pm to 3 pm"}, {"3 pm to 3:30 pm"},{"4 pm to 4:30 pm"},{"4:30 pm to 5 pm"} };



void admin_init(void)
{
	head =NULL;
}


void admin_void_add_patient_record  (char name[] ,int age , char gender[] ,int id)
{
	patient* new_patient = (patient*) malloc(sizeof(patient));

	if(head ==NULL)
	{
		head = new_patient;

		strcpy(new_patient->name,name);
		new_patient->age =age;
		strcpy(new_patient->gender,gender);
		new_patient->id =id;
		new_patient->slot=NOT_RESERVED;
		new_patient->next=NULL;
	}
	else
	{
		patient *current ;
		current = head;
		while(current->id !=id && current->next !=NULL)
		{
			current=current->next;
		}
		if(current->id == id)
		{
			printf("Invalid ID\n");
		}

		new_patient->age =age;
		strcpy(new_patient->name,name);
		strcpy(new_patient->gender,gender);
		new_patient->id =id;

		new_patient->slot=AVILABLE;

		new_patient->next=NULL;
		current->next=new_patient;
	}
}




void admin_void_edit_patient_record     (int id  ,char *name ,int age , char *gender)
{
	patient * current = head;
	while(current->id != id && current->next != NULL)
	{
		current =current->next;
	}
	if(current->next  == NULL && current->id != id )
	{
		printf("Invalid Id\n");
	}
	else
	{
		current->age =age;
		strcpy(current->name,name);
		strcpy(current->gender,gender);
	}
}



void  admin_int_reserve_slot (int id)
{
	int slot;
	patient *current ;
	current = head;

	while(current->id !=id && current->next !=NULL)
	{
		current=current->next;
	}
	if(current->next ==NULL && current->id !=id)
	{
		printf("Invalid ID\n");
	}
	else
	{
		printf(" Our Clinic Slots\n");
		view_slot();
		printf("choose slot :   ");
		scanf("%d",&slot);
		if(array[slot-1]==NOT_AVILABLE)
		{
			printf("Sorry! This slot is Reserved\n");
		}
		else if(array[slot-1]==AVILABLE)
		{
			current->slot = slot-1;
			printf("your slot is  :     %s",array_2d[slot-1]);
			array[slot-1]=RESERVED;
		}
	}
}



void admin_void_cancel_reservation      (int id)
{
	patient *current ;
	current =head;

	while(current->id !=id && current->next !=NULL)
	{
		current=current->next;
	}
	if(current->next ==NULL&& current->id !=id)
	{
		printf("Invalid ID\n");
	}
	else
	{

		array[current->slot]=AVILABLE;
		current->slot=AVILABLE;
	}
}


void user_void_view_patient_record      (int id)
{

	patient *current ;
	current = head;


	while(current->id !=id && current->next !=NULL)
	{
		current=current->next;
	}
	if(current->next ==NULL && current->id !=id )
	{
		printf("Invalid ID\n");
	}
	else
	{
		printf("_______________________\n");
		printf("_______________________\n");

		printf(" name       :  %s   \n", current->name);
		printf(" Id         :  %d   \n", current->id);
		printf(" age        :  %d   \n", current->age);
		printf(" gender     :  %s   \n", current->gender);
		if(array[current->slot] == AVILABLE)
		{
			printf(" slot       : %s   \n",array_2d[current->slot]);
			printf("_______________________\n");
			printf("_______________________\n");
		}
		else
		{
			printf("_______________________\n");
			printf("_______________________\n");
		}
	}
}




void user_void_view_resrvation  (void)
{
	patient *current ;
	current = head;
	{
		printf("_______________________________\n");
		while(current!=NULL )
		{
			if(current->slot !=NOT_RESERVED)
			{
				printf("%s\n",array_2d[current->slot]);

				printf("_______________________________\n");
			}
			current =current->next;
		}
	}
}


void view_slot (void)
{
	int Local_Iterator1 = 0;
	int Local_Iterator2 = 1;
	printf("___________________________________\n");
	for(Local_Iterator1=0;Local_Iterator1<5;Local_Iterator1++)
	{
		if(array[Local_Iterator1]==NOT_AVILABLE)
		{
			printf("%d - %s      (Reserved)|\n",Local_Iterator2,array_2d[Local_Iterator1]);
			printf("___________________________________\n");
			Local_Iterator2++;
		}
		else
		{
			printf("%d - %s                |\n",Local_Iterator2,array_2d[Local_Iterator1]);
			printf("__________________________________\n");
			Local_Iterator2 ++;
		}
	}
}




