#include <main.h>
#include <lcd.c>
void DC_left(int saniye)
{
   output_high(PIN_B1);
   delay_ms(saniye*1000);
   output_low(PIN_B1);
}
void DC_right(int saniye)
{
   output_high(PIN_B2);
   delay_ms(saniye*1000);
   output_low(PIN_B2);
}
void DC_stop()
{
   output_low(PIN_B1);
   output_low(PIN_B2);
   delay_ms(1000);
}
void suAlma(int saniye)
{
   output_high(PIN_B3);
   delay_ms(saniye*1000);
   output_low(PIN_B3);
}
void suBosaltma(int saniye)
{
   output_high(PIN_B4);
   delay_ms(saniye*1000);
   output_low(PIN_B4);
}
void deterjan()
{
   output_high(PIN_B5);
   delay_ms(3000);
   output_low(PIN_B5);
}
void main()
{  
   lcd_init();
   set_tris_b(0x01);
   set_tris_d(0xFF);
   output_b(0x00);
   while(TRUE)
   {
      printf(lcd_putc,"\fBaslatmak icin\nButona basin...");
      if (input(PIN_B0))
      {
         printf(lcd_putc,"\fYikama islemi\nbasladi.");
         delay_ms(2000);
         printf(lcd_putc,"\fSu hatti\ntemizleniyor.");
         suAlma(2);
         suBosaltma(2);
         printf(lcd_putc,"\fSu ve Deterjan\naliniyor.");
         suAlma(2);
         deterjan();
         printf(lcd_putc,"\fYikama islemi\nbasladi.");
         DC_left(3);
         DC_stop();
         DC_right(3);
         DC_stop();
         DC_left(3);
         DC_stop();
         DC_right(3);
         DC_stop();
         DC_left(3);
         DC_stop();
         DC_right(3);
         DC_stop();
         printf(lcd_putc,"\fSu tahliye\nediliyor.");
         suBosaltma(2);
         printf(lcd_putc,"\fDurulama\nbasladi.");
         suAlma(2);
         DC_left(3);
         DC_stop();
         DC_right(3);
         DC_stop();
         DC_left(3);
         DC_stop();
         DC_right(3);
         DC_stop();
         DC_left(3);
         DC_stop();
         DC_right(3);
         DC_stop();
         printf(lcd_putc,"\fSu tahliye\nediliyor.");
         suBosaltma(2);
         printf(lcd_putc,"\fSikma islemi\nyapiliyor.");
         DC_left(3);
         DC_stop();
         DC_right(3);
         DC_stop();
         printf(lcd_putc,"\fSikma\ntamamlandi.");
         delay_ms(3000);
      }
   }

}
