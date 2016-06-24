#include "Sci.h"

void Sci_Init(void)
{
	EALLOW;
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;     // Enable pull-up for GPIO28  (SCIRXDA)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;

	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;   // Asynch input GPIO28 (SCIRXDA)

	/* Configure SCI-A pins MUX*/
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;

	/* scia_fifo_init */
    SciaRegs.SCIFFTX.all=0xE040;
    SciaRegs.SCIFFRX.all=0x2044;
    SciaRegs.SCIFFCT.all=0x0;

	SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
	                                   // No parity,8 char bits,
	                                   // async mode, idle-line protocol
	SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
								   // Disable RX ERR, SLEEP, TXWAKE
	SciaRegs.SCICTL2.all =0x0003;
	SciaRegs.SCICTL2.bit.TXINTENA =1;
	SciaRegs.SCICTL2.bit.RXBKINTENA =1;
	SciaRegs.SCIHBAUD    =0x0000;
	SciaRegs.SCILBAUD    =0x0007;
//	SciaRegs.SCICCR.bit.LOOPBKENA = 1; // Enable loop back
	SciaRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset

	EDIS;
}

/*
void SCITX(unsigned char dat)
{
	SciaRegs.SCITXBUF = dat;
	while(SciaRegs.SCIFFTX.bit.TXFFST == 0){}
}
*/

void SCITX(long data)
{
	char i = 0;

	for ( i = 4; i > 0; i -- )
	{
		SciaRegs.SCITXBUF = data>>((i-1)*8);
		while(SciaRegs.SCIFFTX.bit.TXFFST == 0){}
	}
}

/*
int fputc(int c,FILE *file)
{
	SciaRegs.SCITXBUF = c;
	while( 0 == SciaRegs.SCIFFTX.bit.TXFFST );
	return c;
}
*/

unsigned char SCIRX(void)
{
	unsigned char dat = 0;

	dat = SciaRegs.SCIRXBUF.all;

	return dat;
}


