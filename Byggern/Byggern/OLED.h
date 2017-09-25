#ifndef oled_h_
#define oled_h_

void init_OLED();
void write_c(unsigned char out_command);
void OLED_Reset(void);
void write_d(unsigned char out_data);
void RD(char stat);
void RW(char stat);
void DC(char stat);
void RES(char stat);
void CS(char stat);
void LCD_out(unsigned char cmd);
unsigned int get_LCD_port(unsigned char data);



#endif