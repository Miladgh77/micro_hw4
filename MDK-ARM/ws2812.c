#include "ws2812.h"

void set_color(led_conf_t* rgb_led, color_t *colors, uint16_t led_num){
	rgb_led->led_colors = (uint16_t*)malloc((led_num *24)* sizeof(*(rgb_led->led_colors)));
//	uint16_t data[led_num *24];
	for(int i =0; i<led_num ; i++)
		{
				for(int j=0 ; j<8 ; j++)
					{
						rgb_led->led_colors[(24*i)+j] = (colors[i].G & ((2^(j%8)) == 1)) ? 20 : 10;
					}
				for(int j=8 ; j<16 ; j++)
					{
						rgb_led->led_colors[(24*i)+j] = (colors[i].R & ((2^(j%8)) == 1)) ? 20 : 10;
					}
				for(int j=16 ; j<24 ; j++)
					{
						rgb_led->led_colors[(24*i)+j] = (colors[i].B & ((2^(j%8)) == 1)) ? 20 : 10;
					}
		}
	HAL_TIM_PWM_Start_DMA(&htim1,TIM_CHANNEL_1,(uint32_t*)rgb_led->led_colors, led_num * 24);
	free((void*)rgb_led->led_colors);
}
