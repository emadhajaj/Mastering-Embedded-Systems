# Interrupts Labs

# Lab1
- Write C Code to enable Ext Interrupt for **Stm32F103XX**
- Functions
    - Clock initialization (clock_Init) enables clock signals for the I/O port A and Alternate Function I/O.
    - GPIO initialization (gpio_Init) configures PortA Pin 13 as output and PortA Pin 0 as input with floating input.
    - NVIC initialization (nvic_Init) enables NVIC IRQ6 (External Interrupt 0) to handle interrupts from EXTI0.
    - EXTI initialization (exti_Init) configures EXTI0 to respond to rising edge triggers on PortA Pin 0.
- Interrupt Service Routine (ISR)
    - The project defines an ISR (EXTI0_IRQHandler) to handle interrupts from EXTI0 triggered by rising edges on PortA Pin 0. Inside the ISR, the LED connected to PortA Pin 13 is toggled, and the pending request for line 0 is cleared.



# Lab2
- Write C Code using the 3 eternal interrupts on **ATmega32**, We have also 3 leds (PD5,6,7) (led0,1,2).
    - External Interrupt 0 (INT0) - PD2. >> irq occur when “any logical change”
    - External Interrupt 1 (INT1) - PD3. >> irq occur when “rising edge”
    - External Interrupt 2 (INT2) - PB2. >> irq occur when “Falling edge”
- Each interrupt just make the led 0N for 1 sec
- The main function is always make all the leds off
