
#include "hw_stm32f407vgt6u.h"

/****************************************************************/
void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}
/****************************************************************/

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void enable_clock()
{
	unsigned int temreg;
	temreg = read_reg(RCC_AHB1ENR, ~(1 << 3));
	temreg = temreg | (1 << 3);
	write_reg(RCC_AHB1ENR, temreg);
}

void init_pin(void)
{
	/* det mode Ld4 */
	unsigned int temreg;
	temreg = read_reg(GPIOD_MODER, ~(0x03 << 24));
	temreg = temreg | (GPIO_MODER_OUTPUT << 24);
	write_reg(GPIOD_MODER, temreg);
}

void led_on(unsigned char pin_number)
{
	write_reg(GPIOD_BSRR, 1u <<  pin_number);
}

void led_off(unsigned char pin_number)
{
	write_reg(GPIOD_BSRR, 1u <<  (pin_number + 16u));
}

void main(void)
{
	enable_clock();
	init_pin();
	
	while(1)
	{
		led_on(LD4_PIN);
		delay(0xff);
		led_off(LD4_PIN);
		delay(0xff);
	}
}

