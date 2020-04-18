
#ifndef __HW_STM32F407VGT6U_H__
#define __HW_STM32F407VGT6U_H__

#define write_reg(addr, value)		*((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)		*((unsigned long int *)(addr)) & (mask)

/* RCC -Clock */
#define BASE_ADDR_RCC		0x40023800
#define RCC_AHB1ENR			(BASE_ADDR_RCC + 0x30u)

/* GPIO */
#define BASE_ADDR_GPIO		0x40020C00u
#define GPIOD_MODER			(BASE_ADDR_GPIO + 0x00u)
#define GPIO_MODER_INPUT	0x00u
#define GPIO_MODER_OUTPUT	0x01u
#define GPIO_MODER_ALT		0x02u
#define GPIO_MODER_ANL		0x03u

#define GPIOD_BSRR			(BASE_ADDR_GPIO + 0x18u)

/* Led 4 PD12 */
#define LD4_PIN				12

/* end file */
#endif /* HW_STM32F407VGT6U_H */

