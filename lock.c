#include <LPC214x.h>

#define THRE (1<<5)
#define RDR  (1<<0)

unsigned char pass[5] = "5555";

void delay(void);

void uart0_init(void);

void uart0_tx(unsigned char data);

unsigned char uart0_rx(void);

void uart0_string(char *str);

int main()
{
    unsigned char rx_arr[4];
    int i;

    VPBDIV = 0x01;

    uart0_init();

    while(1)
    {
        uart0_string("\r\nEnter Password: ");

        for(i = 0; i < 4; i++)
        {
            rx_arr[i] = uart0_rx();

            uart0_tx('*');
        }

        if(
            pass[0] == rx_arr[0] &&
            pass[1] == rx_arr[1] &&
            pass[2] == rx_arr[2] &&
            pass[3] == rx_arr[3]
          )
        {
            uart0_string("\r\nAccess Granted\r\n");
        }
        else
        {
            uart0_string("\r\nWrong Password\r\n");
        }

        delay();
    }
}

/* UART INIT */

void uart0_init()
{
    PINSEL0 = 0x00000005;

    U0LCR = 0x83;

    U0DLL = 97;
    U0DLM = 0;

    U0LCR = 0x03;
}

/* UART TRANSMIT */

void uart0_tx(unsigned char data)
{
    while(!(U0LSR & THRE));

    U0THR = data;
}

/* UART RECEIVE */

unsigned char uart0_rx()
{
    while(!(U0LSR & RDR));

    return U0RBR;
}

/* UART STRING */

void uart0_string(char *str)
{
    while(*str)
    {
        uart0_tx(*str++);
    }
}

/* DELAY */

void delay()
{
    unsigned int i,j;

    for(i=0;i<100;i++)
    {
        for(j=0;j<60000;j++);
    }
}
