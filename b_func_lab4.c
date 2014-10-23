#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define 	FILLED			1
#define		CLEAR			0
#define		RIGHTEDGE		10
#define		LEFTEDGE		0
#define		TOPEDGE			1
#define		BOTTOMEDGE		6

typedef signed char int8;

void main() {

	int8	xPos, yPos, xVel, yVel ;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */

	init();
	initNokia();
	clearDisplay();
	xPos=4;		yPos=4;		xVel = 1; 	yVel = 1;
	drawBlock(yPos,xPos);

	while(1) {

		unsigned int i;
			if(xPos > RIGHTEDGE)
				xVel *= -1;
			if(xPos <= LEFTEDGE)
				xVel *= -1;
			if(yPos < TOPEDGE)
				yVel *= -1;
			if(yPos > BOTTOMEDGE)
				yVel *= -1;
		xPos = xPos + xVel;
		yPos = yPos + yVel;

		clearDisplay();
		drawBlock(yPos,xPos);
		__delay_cycles(2000000);

			}
		}
