
#ifndef clinic_management_system
#define clinic_management_system

enum CMS_vid_add_new_patient
{
	empty, /* for empty appointment */
	male, /* for gender data*/
	female /* for gender data*/
};

struct patient_struct
{
	u8 name[20];
	u32 age;
	u32 gender;
	u32 id;
	struct patient_struct * next; /* pointer to the struct of the next patient */
};

typedef struct patient_struct new_patient;


/* functions proto types */
u8 CMS_u8_admin_mode();
void CMS_vid_user_mode();
void CMS_vid_add_new_patient();
void CMS_vid_edit_patient();
void CMS_vid_reserve_reservation();
void CMS_vid_cancel_reservation();
void CMS_vid_view_patient_record();
void CMS_vid_view_reservations_today();


#endif