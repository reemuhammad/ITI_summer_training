/*calculating total money needed for employees */
#include<stdio.h>
#include"std_types.h"

struct employee 
	{
		u32 salary;
		u32 bonus;
		u32 deductions;
	}; /* define a new struct by  writing "struct employee" */

u32 employee_money(struct employee);	

u32 main()
{
	/* asking the user to enter salary, bonus,
	deductions for 3 employees */
	struct employee Ahmed, Amr, Waleed;
	printf("Please enter Ahmed salary: ");
	scanf("%d", &Ahmed.salary);
	printf("Please enter Ahmed bonus: ");
	scanf("%d", &Ahmed.bonus);
	printf("Please enter Ahmed deductions: ");
	scanf("%d", &Ahmed.deductions);
	printf("Please enter Amr salary: ");
	scanf("%d", &Amr.salary);
	printf("Please enter Amr bonus: ");
	scanf("%d", &Amr.bonus);
	printf("Please enter Amr deductions: ");
	scanf("%d", &Amr.deductions);
	printf("Please enter Waleed salary: ");
	scanf("%d", &Waleed.salary);
	printf("Please enter Waleed bonus: ");
	scanf("%d", &Waleed.bonus);
	printf("Please enter Waleed deductions: ");
	scanf("%d", &Waleed.deductions);
	
	/* printing total value for 3 employees */
	printf("Total value nedded is %d", (employee_money(Ahmed)+employee_money(Amr)+employee_money(Waleed)));
}

u32 employee_money(struct employee id)
{
	return(id.salary+id.bonus-id.deductions); /* returns money needed for employee */
}