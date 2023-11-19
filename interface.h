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


/****************************************************
* Function name :    admin_init.                    *          
* Purpose       :    To Init A Linked List.         *
* Parameters    :   (void) No parameters.           *    
* Return value  :   (void) No parameters.           *                  
*****************************************************/
void admin_init (void);


/****************************************************
* Function name :   admin_void_add_patient_record.  *          
* Purpose       :   Add A Patient Record.           *
* Parameters    :   1- char [] --> name of patient .*
*                   2- int     --> age of patient   *
*                   3- int     --> id of patient    * 
* Return value  :  (void) No parameters.            *                  
*****************************************************/
void admin_void_add_patient_record (char name[] ,int age , char gender[] ,int id);


/*******************************************************
* Function name :   admin_void_edit_patient_record.    *          
* Purpose       :   Edit the Patient Record.           *
* Parameters    :   1- int     --> id of patient .     *
*                   2- char [] --> name of patient     *
*                   3- int     --> age of patient      *
*                   4- char [] --> gender of patient   * 
* Return value  :  (void) No parameters.               *                  
********************************************************/
void admin_void_edit_patient_record (int id  ,char *name ,int age , char *gender);


/**************************************************
* Function name :   admin_int_reserve_slot.       *          
* Purpose       :   reserve a slot for patient.   *
* Parameters    :   1- int  --> id of patient .   *
* Return value  :  (void) No parameters.          *                  
**************************************************/
void  admin_int_reserve_slot (int id);


/**************************************************
* Function name :   admin_void_cancel_reservation.*          
* Purpose       :   Cancel a reservation .        *
* Parameters    :   1- int  --> id of patient .   *
* Return value  :  (void) No parameters.         *                  
**************************************************/
void admin_void_cancel_reservation (int id);


/**************************************************
* Function name :   user_void_view_patient_record.*          
* Purpose       :   show the patient record.      *
* Parameters    :   1- int  --> id of patient .   *
* Return value  :  (void) No parameters.          *                  
**************************************************/
void user_void_view_patient_record (int id);


/**************************************************
* Function name :    user_void_view_resrvation.   *          
* Purpose       :    show today reservation.      *
* Parameters    :   (void) No parameters.         *
* Return value  :   (void) No parameters.         *                  
**************************************************/
void user_void_view_resrvation (void);


/**************************************************
* Function name :    view_slot.                   *            
* Purpose       :    show available slot.         *
* Parameters    :   (void) No parameters.         *
* Return value  :   (void) No parameters.         *                  
**************************************************/
void view_slot(void);

#endif // INTERFACE_H_INCLUDED
