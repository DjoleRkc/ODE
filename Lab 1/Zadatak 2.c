int main() {

	ANSELB = 0; // Configure PORTB pins as digital
	TRISB = 0; //  Configure PORTB as output
	TRISA = 0x0F; // set RA0, RA1, RA2, RA3 pin as input

	LATB = 0x00; // Turn OFF LEDs on PORTB

	while (1) {
		if (BUTTON(&PORTA, 0, 5, 1)) {
			LATB ^= 0x01;
			delay_ms(1000);
		}

		if (BUTTON(&PORTA, 1, 5, 1)) {
			LATB ^= 0x02;
			delay_ms(1000);
		}
		if (BUTTON(&PORTA, 2, 5, 1)) {
			LATB ^= 0x04;
			delay_ms(1000);
		}
		if (BUTTON(&PORTA, 3, 5, 1)) {
			LATB ^= 0x08;
			delay_ms(1000);
		}
   	}
}
