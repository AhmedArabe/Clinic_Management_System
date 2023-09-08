#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#define AVILABLE            1
#define NOT_AVILABLE        0

#define RESERVED            0
#define NOT_RESERVED        255


typedef struct Patient
{
  char name[30];
  char age;
  char gender[30];
  char id;
  struct Patient *next;
  int slot;

}patient;


patient * head ;



void admin_init (void);

void admin_void_add_patient_record (char name[] ,int age , char gender[] ,int id);

void admin_void_edit_patient_record (int id  ,char *name ,int age , char *gender);

void  admin_int_reserve_slot (int id);

void admin_void_cancel_reservation (int id);


void user_void_view_patient_record (int id);

void user_void_view_resrvation (void);

void view_slot(void);

#endif // INTERFACE_H_INCLUDED
