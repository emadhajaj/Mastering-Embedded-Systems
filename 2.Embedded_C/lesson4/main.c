#define SYSCTL_RCGC2_R    (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R  (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R  (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))

int main(){
	SYSCTL_RCGC2_R = 0x20;

	//delay for the GPIO to run
	volatile unsigned long delayCount =0; // to prevent optimization
	for (delayCount = 0; delayCount < 200; ++delayCount);

	GPIO_PORTF_DIR_R |= 1<<3; // set Pin3 Output 
	GPIO_PORTF_DEN_R |= 1<<3; // enable Pin3

	while(1){
		//ON
		GPIO_PORTF_DATA_R |= 1<<3;
		for (delayCount = 0; delayCount < 20000; ++delayCount);

		//OFF
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for (delayCount = 0; delayCount < 20000; ++delayCount);
	} 
}