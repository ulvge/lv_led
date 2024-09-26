/**
 ****************************************************************************************************
 * @file        lcd_ex.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-21
 * @brief       lcd_ex.c存放各个LCD驱动IC的寄存器初始化部分代码,以简化lcd.c,该.c文件
 *              不直接加入到工程里面,只有lcd.c会用到,所以通过include的形式添加.(不要在
 *              其他文件再包含该.c文件!!否则会报错!)
 *
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20200421
 * 第一次发布
 *
 ****************************************************************************************************
 */

#include "./BSP/LCD/lcd.h"
#include "./SYSTEM/delay/delay.h"

#define LCD_9314_DELAY_INIT_DELAY 1

/**
 * @brief       ST7789 寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_st7789_reginit(void)
{
}

/**
 * @brief       ILI9341寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_ili9341_reginit(void)
{
#if 0
    lcd_wr_regno(0xCF);
    lcd_wr_data(0x00);
    lcd_wr_data(0xC1);
    lcd_wr_data(0X30);
    lcd_wr_regno(0xED);
    lcd_wr_data(0x64);
    lcd_wr_data(0x03);
    lcd_wr_data(0X12);
    lcd_wr_data(0X81);
    lcd_wr_regno(0xE8);
    lcd_wr_data(0x85);
    lcd_wr_data(0x10);
    lcd_wr_data(0x7A);
    lcd_wr_regno(0xCB);
    lcd_wr_data(0x39);
    lcd_wr_data(0x2C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x34);
    lcd_wr_data(0x02);
    lcd_wr_regno(0xF7);
    lcd_wr_data(0x20);
    lcd_wr_regno(0xEA);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_regno(0xC0); /* Power control */
    lcd_wr_data(0x1B);  /* VRH[5:0] */
    lcd_wr_regno(0xC1); /* Power control */
    lcd_wr_data(0x01);  /* SAP[2:0];BT[3:0] */
    lcd_wr_regno(0xC5); /* VCM control */
    lcd_wr_data(0x30);  /* 3F */
    lcd_wr_data(0x30);  /* 3C */
    lcd_wr_regno(0xC7); /* VCM control2 */
    lcd_wr_data(0XB7);
    lcd_wr_regno(0x36); /*  Memory Access Control */
    lcd_wr_data(0x48);
    lcd_wr_regno(0x3A);
    lcd_wr_data(0x55);
    lcd_wr_regno(0xB1);
    lcd_wr_data(0x00);
    lcd_wr_data(0x1A);
    lcd_wr_regno(0xB6); /*  Display Function Control */
    lcd_wr_data(0x0A);
    lcd_wr_data(0xA2);
    lcd_wr_regno(0xF2); /*  3Gamma Function Disable */
    lcd_wr_data(0x00);
    lcd_wr_regno(0x26); /* Gamma curve selected */
    lcd_wr_data(0x01);
    lcd_wr_regno(0xE0); /* Set Gamma */
    lcd_wr_data(0x0F);
    lcd_wr_data(0x2A);
    lcd_wr_data(0x28);
    lcd_wr_data(0x08);
    lcd_wr_data(0x0E);
    lcd_wr_data(0x08);
    lcd_wr_data(0x54);
    lcd_wr_data(0XA9);
    lcd_wr_data(0x43);
    lcd_wr_data(0x0A);
    lcd_wr_data(0x0F);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_regno(0XE1);    /* Set Gamma */
    lcd_wr_data(0x00);
    lcd_wr_data(0x15);
    lcd_wr_data(0x17);
    lcd_wr_data(0x07);
    lcd_wr_data(0x11);
    lcd_wr_data(0x06);
    lcd_wr_data(0x2B);
    lcd_wr_data(0x56);
    lcd_wr_data(0x3C);
    lcd_wr_data(0x05);
    lcd_wr_data(0x10);
    lcd_wr_data(0x0F);
    lcd_wr_data(0x3F);
    lcd_wr_data(0x3F);
    lcd_wr_data(0x0F);
    lcd_wr_regno(0x2B);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x01);
    lcd_wr_data(0x3f);
    lcd_wr_regno(0x2A);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0xef);
    lcd_wr_regno(0x11); /* Exit Sleep */
    delay_ms(120);
    lcd_wr_regno(0x29); /* display on */
#else
    /*  Power control B (CFh)  */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xCF);
    lcd_wr_data(0x00);
    lcd_wr_data(0x81);
    lcd_wr_data(0x30);

    /*  Power on sequence control (EDh) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xED);
    lcd_wr_data(0x64);
    lcd_wr_data(0x03);
    lcd_wr_data(0x12);
    lcd_wr_data(0x81);

    /*  Driver timing control A (E8h) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xE8);
    lcd_wr_data(0x85);
    lcd_wr_data(0x10);
    lcd_wr_data(0x78);

    /*  Power control A (CBh) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xCB);
    lcd_wr_data(0x39);
    lcd_wr_data(0x2C);
    lcd_wr_data(0x00);
    lcd_wr_data(0x34);
    lcd_wr_data(0x03);

    /* Pump ratio control (F7h) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xF7);
    lcd_wr_data(0x20);

    /* Driver timing control B */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xEA);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);

    /* Frame Rate Control (In Normal Mode/Full Colors) (B1h) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xB1);
    lcd_wr_data(0x00);
    lcd_wr_data(0x1B);

    /*  Display Function Control (B6h) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xB6);
    lcd_wr_data(0x0A);
    lcd_wr_data(0xA2);

    /* Power Control 1 (C0h) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xC0);
    lcd_wr_data(0x35);

    /* Power Control 2 (C1h) */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0xC1);
    lcd_wr_data(0x11);

    /* VCOM Control 1 (C5h) */
    lcd_wr_regno(0xC5);
    lcd_wr_data(0x45);
    lcd_wr_data(0x45);

    /*  VCOM Control 2 (C7h)  */
    lcd_wr_regno(0xC7);
    lcd_wr_data(0xA2);

    /* Enable 3G (F2h) */
    lcd_wr_regno(0xF2);
    lcd_wr_data(0x00);

    /* Gamma Set (26h) */
    lcd_wr_regno(0x26);
    lcd_wr_data(0x01);
    delay_ms(LCD_9314_DELAY_INIT_DELAY);

    /* Positive Gamma Correction */
    lcd_wr_regno(0xE0); // Set Gamma
    lcd_wr_data(0x0F);
    lcd_wr_data(0x26);
    lcd_wr_data(0x24);
    lcd_wr_data(0x0B);
    lcd_wr_data(0x0E);
    lcd_wr_data(0x09);
    lcd_wr_data(0x54);
    lcd_wr_data(0xA8);
    lcd_wr_data(0x46);
    lcd_wr_data(0x0C);
    lcd_wr_data(0x17);
    lcd_wr_data(0x09);
    lcd_wr_data(0x0F);
    lcd_wr_data(0x07);
    lcd_wr_data(0x00);

    /* Negative Gamma Correction (E1h) */
    lcd_wr_regno(0XE1); // Set Gamma
    lcd_wr_data(0x00);
    lcd_wr_data(0x19);
    lcd_wr_data(0x1B);
    lcd_wr_data(0x04);
    lcd_wr_data(0x10);
    lcd_wr_data(0x07);
    lcd_wr_data(0x2A);
    lcd_wr_data(0x47);
    lcd_wr_data(0x39);
    lcd_wr_data(0x03);
    lcd_wr_data(0x06);
    lcd_wr_data(0x06);
    lcd_wr_data(0x30);
    lcd_wr_data(0x38);
    lcd_wr_data(0x0F);

    /* memory access control set */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0x36);
    lcd_wr_data(0xC8); /*竖屏  左上角到 (起点)到右下角 (终点)扫描方式*/
    delay_ms(LCD_9314_DELAY_INIT_DELAY);

    /* column address control set */
    lcd_wr_regno(CMD_SetCoordinateX);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0xEF);

    /* page address control set */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(CMD_SetCoordinateY);
    lcd_wr_data(0x00);
    lcd_wr_data(0x00);
    lcd_wr_data(0x01);
    lcd_wr_data(0x3F);

    /*  Pixel Format Set (3Ah)  */
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    lcd_wr_regno(0x3a);
    lcd_wr_data(0x55);

    /* Sleep Out (11h)  */
    lcd_wr_regno(0x11);
    // ILI9341_Delay ( 0xAFFf<<2 );
    delay_ms(LCD_9314_DELAY_INIT_DELAY);
    delay_ms(LCD_9314_DELAY_INIT_DELAY);

    /* Display ON (29h) */
    lcd_wr_regno(0x29);
#endif
}

/**
 * @brief       NT35310寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_nt35310_reginit(void)
{
}

/**
 * @brief       NT35510寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_nt35510_reginit(void)
{
}

/**
 * @brief       SSD1963寄存器初始化代码
 * @param       无
 * @retval      无
 */
void lcd_ex_ssd1963_reginit(void)
{
}
