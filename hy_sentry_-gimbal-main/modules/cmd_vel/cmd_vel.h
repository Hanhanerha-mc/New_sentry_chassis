/*
 * @Description: 
 * @Author: changfeng
 * @brief: 
 * @version: 
 * @Date: 2025-02-01 20:35:00
 * @LastEditors:  
 * @LastEditTime: 2025-03-13 01:42:54
 */
#ifndef CMD_VEL_H
#define CMD_VEL_H

#include "stdint.h"
#include "bsp_usart.h"
#include "daemon.h"
#include "bsp_log.h"
#include "usart.h"
#include "robot_def.h"

#pragma pack(1)
typedef struct 
{
    float x;
    float y;
    float z;
} Vector3;  //通用三维向量结构体


typedef struct 
{
    float vx;
    float vy;
    float vz;
    chassis_mode_e mode;
} Radar_Data;
#pragma pack()

/* ------------------------- Internal Data ----------------------------------- */

/**
 * @brief 初始化导航接收
 * @param {UART_HandleTypeDef} *cmd_vel_uasrt_handle
 * @return 
 */
Radar_Data *CmdVelControlInit(UART_HandleTypeDef *cmd_vel_uasrt_handle);

/**
 * @brief 检查遥控器是否在线
 * @return 
 */
uint8_t CmdVelControlIsOnline();

#endif  