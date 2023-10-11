#include "stm32f10x.h"
#include "i2c_lcd.h"
#include <stdio.h>

//dht11.c
void dht11_init(void)
{
	GPIO_InitTypeDef gpioInit;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	gpioInit.GPIO_Mode = GPIO_Mode_Out_OD;
	gpioInit.GPIO_Pin = GPIO_Pin_8;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &gpioInit);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_8);
}


uint8_t dht11_read(uint8_t *pu8Data)
{
	uint16_t u16Tim;
	uint8_t u8Buff[5];
	uint8_t u8CheckSum;
	uint8_t i;
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	Delay_Ms(20);
	GPIO_SetBits(GPIOB, GPIO_Pin_8);
	
	/* cho chan PB12 len cao */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 10) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if (u16Tim >= 10) {
		return 0;
	}
	
	/* cho chan PB12 xuong thap */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 45) {
		if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if ((u16Tim >= 45) || (u16Tim <= 5)) {
		return 0;
	}
	
	/* cho chan PB12 len cao */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 90) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if ((u16Tim >= 90) || (u16Tim <= 70)) {
		return 0;
	}
	
	/* cho chan PB12 xuong thap */
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 95) {
		if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
			break;
		}
	}
	u16Tim = TIM_GetCounter(TIM2);
	if ((u16Tim >= 95) || (u16Tim <= 75)) {
		return 0;
	}
	
	/* nhan byte so 1 */
	for (i = 0; i < 8; ++i) {
		/* cho chan PB12 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* cho chan PB12 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[0] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[0] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[0] &= ~1;
		}
	}
	
	/* nhan byte so 2 */
	for (i = 0; i < 8; ++i) {
		/* cho chan PB12 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* cho chan PB12 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[1] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[1] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[1] &= ~1;
		}
	}
	
	/* nhan byte so 3 */
	for (i = 0; i < 8; ++i) {
		/* cho chan PB12 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* cho chan PB12 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[2] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[2] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[2] &= ~1;
		}
	}
	
	/* nhan byte so 4 */
	for (i = 0; i < 8; ++i) {
		/* cho chan PB12 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* cho chan PB12 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[3] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[3] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[3] &= ~1;
		}
	}
	
	/* nhan byte so 5 */
	for (i = 0; i < 8; ++i) {
		/* cho chan PB12 len cao */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 65) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 65) || (u16Tim <= 45)) {
			return 0;
		}
		
		/* cho chan PB12 xuong thap */
		TIM_SetCounter(TIM2, 0);
		while (TIM_GetCounter(TIM2) < 80) {
			if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) {
				break;
			}
		}
		u16Tim = TIM_GetCounter(TIM2);
		if ((u16Tim >= 80) || (u16Tim <= 10)) {
			return 0;
		}
		u8Buff[4] <<= 1;
		if (u16Tim > 45) {
			/* nhan duoc bit 1 */
			u8Buff[4] |= 1;
		} else {
			/* nhan duoc bit 0 */
			u8Buff[4] &= ~1;
		}
	}
	
	u8CheckSum = u8Buff[0] + u8Buff[1] + u8Buff[2] + u8Buff[3];
	if (u8CheckSum != u8Buff[4]) {
		return 0;
	}
	
	for (i = 0; i < 4; ++i) {
		pu8Data[i] = u8Buff[i];
	}
	
	return 1;
}
 //dht11.c











void Delay1Ms(void);
void Delay_Ms(uint32_t u32DelayInMs);
void delay_us(uint32_t delay);

void Delay1Ms(void)
{
	
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < 1000) {
	}
}

void delay_us(uint32_t delay)
{
	
	TIM_SetCounter(TIM2, 0);
	while (TIM_GetCounter(TIM2) < delay) {
	}
}

void Delay_Ms(uint32_t u32DelayInMs)
{
	
	while (u32DelayInMs) {
		Delay1Ms();
		--u32DelayInMs;
	}
}

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
uint8_t i2c_write(uint8_t u8Data);
uint8_t i2c_read(uint8_t u8Ack);

#define SDA_0 GPIO_ResetBits(GPIOA, GPIO_Pin_0)
#define SDA_1 GPIO_SetBits(GPIOA, GPIO_Pin_0)
#define SCL_0 GPIO_ResetBits(GPIOA, GPIO_Pin_1)
#define SCL_1 GPIO_SetBits(GPIOA, GPIO_Pin_1)
#define SDA_VAL (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))

void i2c_init(void)
{
	GPIO_InitTypeDef gpioInit;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	gpioInit.GPIO_Mode = GPIO_Mode_Out_OD;
	gpioInit.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &gpioInit);
	
	SDA_1;
	SCL_1;
}

void i2c_start(void)
{
	
	SCL_1;
	delay_us(3);
	SDA_1;
	delay_us(3);
	SDA_0;
	delay_us(3);
	SCL_0;
	delay_us(3);
}

void i2c_stop(void)
{
	
	SDA_0;
	delay_us(3);
	SCL_1;
	delay_us(3);
	SDA_1;
	delay_us(3);
}

uint8_t i2c_write(uint8_t u8Data)
{
	uint8_t i;
	uint8_t u8Ret;
	
	for (i = 0; i < 8; ++i) {
		if (u8Data & 0x80) {
			SDA_1;
		} else {
			SDA_0;
		}
		delay_us(3);
		SCL_1;
		delay_us(5);
		SCL_0;
		delay_us(2);
		u8Data <<= 1;
	}
	
	SDA_1;
	delay_us(3);
	SCL_1;
	delay_us(3);
	if (SDA_VAL) {
		u8Ret = 0;
	} else {
		u8Ret = 1;
	}
	delay_us(2);
	SCL_0;
	delay_us(5);
	
	return u8Ret;
}

uint8_t i2c_read(uint8_t u8Ack)
{
	uint8_t i;
	uint8_t u8Ret;
	
	SDA_1;
	delay_us(3);
	
	for (i = 0; i < 8; ++i) {
		u8Ret <<= 1;
		SCL_1;
		delay_us(3);
		if (SDA_VAL) {
			u8Ret |= 0x01;
		}
		delay_us(2);
		SCL_0;
		delay_us(5);
	}
	
	if (u8Ack) {
		SDA_0;
	} else {
		SDA_1;
	}
	delay_us(3);
	
	SCL_1;
	delay_us(5);
	SCL_0;
	delay_us(5);
	
	return u8Ret;
}

void send(uint8_t u8Data);

void send(uint8_t u8Data)
{
	uint8_t i;
	
	for (i = 0; i < 8; ++i) {
		if (u8Data & 0x80) {
			GPIO_SetBits(GPIOA, GPIO_Pin_0);
			Delay_Ms(4);
			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			Delay_Ms(1);
		} else {
			GPIO_SetBits(GPIOA, GPIO_Pin_0);
			Delay_Ms(1);
			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			Delay_Ms(4);
		}
		u8Data <<= 1;
	}
}

int main(void)
{
	dht11_init();
	GPIO_InitTypeDef gpioInit;
	TIM_TimeBaseInitTypeDef timerInit;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	gpioInit.GPIO_Pin = GPIO_Pin_13;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &gpioInit);
	
	gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
	gpioInit.GPIO_Pin = GPIO_Pin_0;
	gpioInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &gpioInit);
	
	timerInit.TIM_CounterMode = TIM_CounterMode_Up;
	timerInit.TIM_Period = 0xFFFF;
	timerInit.TIM_Prescaler = 72 - 1;
	
	TIM_TimeBaseInit(TIM2, &timerInit);
	
	TIM_Cmd(TIM2, ENABLE);
	
	i2c_init();
	
	I2C_LCD_Init();
	I2C_LCD_Clear();
	I2C_LCD_BackLight(1);
	I2C_LCD_Puts("STM32F103C8T6");
	I2C_LCD_NewLine();
	I2C_LCD_Puts("STM32 DHT11 LCD I2C");
	
	while (1) {
		uint8_t dhtData[5];
        char tempStr[16];
		
			char szDisplay[17];
	uint8_t u8Buff[4];
		
		

        // Read data from DHT11
        if (dht11_read(u8Buff))
        {
            // Calculate temperature and humidity values
        //    float temperature = (float)dhtData[2] + ((float)dhtData[3] / 10.0);
         //   float humidity = (float)dhtData[0] + ((float)dhtData[1] / 10.0);

            // Display temperature and humidity on LCD
            I2C_LCD_Clear();
           // sprintf(szDisplay, "Temp: %.1fC", u8Buff[2]);
					  sprintf(szDisplay, "Do am: %d       ", u8Buff[0]);
            I2C_LCD_Puts(szDisplay);
            I2C_LCD_NewLine();
           // sprintf(szDisplay, "Humidity: %.1f%%", u8Buff[0]);
					sprintf(szDisplay, "Nhiet do: %d    ", u8Buff[2]);
            I2C_LCD_Puts(szDisplay);
        }
        else
        {
            // Display an error message if DHT11 reading fails
            I2C_LCD_Clear();
            I2C_LCD_Puts("DHT11 Error");
        }

        // Delay for a while before reading again
        Delay_Ms(2000);	
		
		
		
		
		
		
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		Delay_Ms(500);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		Delay_Ms(500);
	}
	
}
