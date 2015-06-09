#include "ov_bitmap.h"


/**
 * @brief   初始化bitmap
 *
 * @param   size
 *
 * @return  1：成功，0：失败 
 */
int bitmap_init(int size)
{
    g_size = size/8 + 1;
    g_bitmap = new char[g_size];
    if(NULL == g_bitmap)
    {
        return 0;
    }
    memset(g_bitmap, 0x0, g_size);
    return 1;
}


/**
 * @brief   置位
 *
 * @param   index
 *
 * @return  0：失败，1：成功
 */
int bitmap_set(int index)
{
    int quo = index / 8;
    int remainder = index % 8;
    unsigned char x = (0x1 << remainder);
    if(quo > g_size)
        return 0;
    g_bitmap[quo] |= x;
    return 1;
}


int bitmap_get(int index)
{
    int quo = index / 8;
    int remainder = index % 8;
    unsigned char x = (0x1 << remainder);
    if(quo > g_size)
    {
        return 0;
    }
    unsigned char res = g_bitmap[quo] & x;
    return res>0? 1 : 0;
}
