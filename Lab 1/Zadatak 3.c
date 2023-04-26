


char uart_rd;
int tmp, rem;

int main() {

	ANSELB = 0; // Configure PORTB pins as digital
	TRISB = 0; //  Configure PORTB as output
	TRISA = 0x0F; // set RA0, RA1, RA2, RA3 pin as input

	LATB = 0x00; // Turn OFF LEDs on PORTB

	UART1_Init(9600); // Initialize UART module at 9600 bps
	Delay_ms(100); // Wait for UART module to stabilize
	UART1_Write_Text("Start");
	UART1_Write(13);
	UART1_Write(10);

	

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

		if (UART1_Data_Ready()){ // If data is received,
			uart_rd = UART1_Read(); // read the received data,
			if (uart_rd == 'r') { // If data is 'r'
				tmp = LATB;
				tmp /= 10;
				if(tmp) UART1_Write(tmp + '0');
				rem = tmp % 10;
				UART1_Write(rem + '0');
				 // send data via UART

				UART1_Write(13);
				UART1_Write(10);
				}
			}
			 
		}

	}
