#include "bsp_log.h"

#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"
#include <stdio.h>


void BSPLogInit()
{
    SEGGER_RTT_Init();
}

int PrintLog(const char *fmt, ...)
{
    va_list args;           // 可变参数列表
    va_start(args, fmt);        // 初始化可变参数列表，从fmt开始获取参数，args指向fmt
    int n = SEGGER_RTT_vprintf(BUFFER_INDEX, fmt, &args); // 一次可以开启多个buffer(多个终端),我们只用一个
    va_end(args);        // 结束可变参数列表，释放资源
    return n;
}

// 浮点数转换为字符串
// @param str 输出字符串缓冲区
// @param va 浮点数
// @return 无返回值,结果保存在str中,格式为"整数部分.小数部分",小数部分保留三位
void Float2Str(char *str, float va)
{
    int flag = va < 0;
    int head = (int)va;
    int point = (int)((va - head) * 1000);
    head = abs(head);
    point = abs(point);
    if (flag)
        sprintf(str, "-%d.%d", head, point);
    else
        sprintf(str, "%d.%d", head, point);
}

