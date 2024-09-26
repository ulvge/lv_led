/**
 ****************************************************************************************************
 * @file        key.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-19
 * @brief       按键输入 驱动代码
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
 * V1.0 20200419
 * 第一次发布
 *
 ****************************************************************************************************
 */

#ifndef __KEY_H
#define __KEY_H

#include "../Types.h"
#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* 引脚 定义 */

#define KEY1_GPIO_PORT                  GPIOA
#define KEY1_GPIO_PIN                   GPIO_PIN_0
#define KEY1_GPIO_CLK_ENABLE()          do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)   /* PE口时钟使能 */

#define WKUP_GPIO_PORT                  GPIOC
#define WKUP_GPIO_PIN                   GPIO_PIN_13
#define WKUP_GPIO_CLK_ENABLE()          do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PA口时钟使能 */

/******************************************************************************************/

#define KEY1       HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_GPIO_PIN)     /* 读取KEY1引脚 */
#define WK_UP       HAL_GPIO_ReadPin(WKUP_GPIO_PORT, WKUP_GPIO_PIN)     /* 读取WKUP引脚 */


#define KEY1_PRES    1              /* KEY1按下 则强调执行校准程序 对应板上 KEY1*/
#define WKUP_PRES    4              /* KEY_UP按下(即WK_UP)  对应 对应板上 KEY2 */

void key_init(void);                /* 按键初始化函数 */
uint8_t key_scan(uint8_t mode);     /* 按键扫描函数 */


typedef struct {
    UINT32 isLastPressed : 1; // May be invalid
    UINT32 isPreesed : 1;     // valid Preesed
    UINT32 isReleased : 1;
    GPIO_TypeDef* port;
    uint16_t pin;
    UINT32 preesedStartTick;
} Key_ScanST;

UINT32 KeyPressedDurationMs(Key_ScanST *key);
extern Key_ScanST g_key1;
extern Key_ScanST g_key2;
#endif
