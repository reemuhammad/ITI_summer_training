#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define NOT_PRESSED 101
#define KPD_U8ARR { \
					{'7','8','9','/'}, \
					{'4','5','6','*'}, \
					{'1','2','3','-'}, \
					{'C','0','=','+'}  \
				  } \


#define KPD_u8PORT     Port_C
/* The columns pins : OUTPUT */
#define KPD_u8COLUMN0_PIN    Pin_0
#define KPD_u8COLUMN1_PIN    Pin_1
#define KPD_u8COLUMN2_PIN    Pin_2
#define KPD_u8COLUMN3_PIN    Pin_3

/* The rows pins : INPUT */
#define KPD_u8ROW0_PIN       Pin_4
#define KPD_u8ROW1_PIN       Pin_5
#define KPD_u8ROW2_PIN       Pin_6
#define KPD_u8ROW3_PIN       Pin_7

#endif
