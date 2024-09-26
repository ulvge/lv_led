/**
 ****************************************************************************************************
 * @file        key.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-20
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
 * V1.0 20200420
 * 第一次发布
 *
 ****************************************************************************************************
 */

#include "./BSP/KEY/key.h"
#include "./BSP/Types.h"
#include "./SYSTEM/delay/delay.h"


/**
 * @brief       按键初始化函数
 * @param       无
 * @retval      无
 */
void key_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    KEY1_GPIO_CLK_ENABLE();                                     /* KEY1时钟使能 */
    WKUP_GPIO_CLK_ENABLE();                                     /* WKUP时钟使能 */

    gpio_init_struct.Pin = KEY1_GPIO_PIN;                       /* KEY1引脚 */
    gpio_init_struct.Mode = GPIO_MODE_INPUT;                    /* 输入 */
    gpio_init_struct.Pull = GPIO_PULLUP;                        /* 上拉 */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;              /* 高速 */
    HAL_GPIO_Init(KEY1_GPIO_PORT, &gpio_init_struct);           /* KEY1引脚模式设置,上拉输入 */

    gpio_init_struct.Pin = WKUP_GPIO_PIN;                       /* WKUP引脚 */
    gpio_init_struct.Mode = GPIO_MODE_INPUT;                    /* 输入 */
    gpio_init_struct.Pull = GPIO_PULLDOWN;                      /* 下拉 */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;              /* 高速 */
    HAL_GPIO_Init(WKUP_GPIO_PORT, &gpio_init_struct);           /* WKUP引脚模式设置,下拉输入 */
}

Key_ScanST g_key1 = {
    .port = KEY1_GPIO_PORT,
    .pin = KEY1_GPIO_PIN
}; 
Key_ScanST g_key2 = {
    .port = WKUP_GPIO_PORT,
    .pin = WKUP_GPIO_PIN
}; 

/// @brief count pluse ms of the pin
/// @param pin 
/// @param lastMs 
/// @return The duration of the key pressed
UINT32 KeyPressedDurationMs(Key_ScanST *key)
{
    #define KEY_DEBOUNCE_DELAY  20
    uint32_t durationMs;
    if (HAL_GPIO_ReadPin(key->port, key->pin)) {
        key->isLastPressed = true;
        durationMs = HAL_GetTick() - key->preesedStartTick;
        if (durationMs >= KEY_DEBOUNCE_DELAY) {
            key->isPreesed = true;
        }
        return durationMs;
    }else{
        if (key->isLastPressed == true) {
            key->isLastPressed = false; 
            key->isPreesed = false;
            key->isReleased = true;
            durationMs = HAL_GetTick() - key->preesedStartTick;
        } else{
            key->isReleased = false;
			durationMs = 0;
        }
        key->preesedStartTick = HAL_GetTick(); //update to newest tick
        return durationMs;
    }
}
// 需要周期性call
uint8_t key_scan(uint8_t mode)
{
    KeyPressedDurationMs(&g_key1);
    KeyPressedDurationMs(&g_key2);
    if (g_key1.isPreesed) {
    }
    return 0;
}









