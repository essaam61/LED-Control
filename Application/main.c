#include "IntCtrl.h"
#include "GPIO.h"
#include "Systick.h"
#include "LED_BP.h"
#include "Std_Types.h"

int main()
{
	
	Dio_Init();
	Systick_SetCallBack(TimerCount);
	Systick_Init();
	IntCtrl_Init(None, SysTick);
	
	while(1)
	{
		   LED_Blink (Red, 5, 3);
	}
	
	
}

