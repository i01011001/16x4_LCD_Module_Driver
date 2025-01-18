#include <driver/gpio.h>
#include <esp_log.h>

#define TAG "main"

static int gpio_init(gpio_num_t gpio_num);
static int lcd_init();

void app_main(void)
{
	lcd_init();
}

static int gpio_init(gpio_num_t gpio_num){
	int err=0;
	gpio_config_t gpio= {
		.mode = GPIO_MODE_OUTPUT,
		.pin_bit_mask = 1U <<  gpio_num,
	};
	err = gpio_config(&gpio);
	if(err < 0){
		ESP_LOGE(TAG, "gpio config failed for GPIO_NUM_%d", gpio_num);
		return -1;
	}
	return 0;
}

static int lcd_init(){
	gpio_init(GPIO_NUM_4);
	gpio_init(GPIO_NUM_5);
	gpio_init(GPIO_NUM_6);
	gpio_init(GPIO_NUM_7);
	gpio_init(GPIO_NUM_15);
	gpio_init(GPIO_NUM_16);
	gpio_init(GPIO_NUM_17);
	gpio_init(GPIO_NUM_18);

	return 0;
}
