#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);
extern void drawPaddle(unsigned char row, unsigned char col);

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

	int8	xPos, yPos, xVel, yVel, xPosP, yPosP, xPosP2, yPosP2, exit;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */

	init();
	initNokia();
	clearDisplay();
	xPos=4;		yPos=4;		xVel = 1; 	yVel = 1;
	xPosP=1;	yPosP=3;
	exit = 1;
	xPosP2=xPosP;	yPosP2=yPosP +1;
	drawBlock(yPos,xPos);

	while(exit == 1) {

		unsigned long i;
			if(xPos > RIGHTEDGE)
				xVel *= -1;
			if((xPos == xPosP && yPos == yPosP)||(xPos == xPosP2 && yPos == yPosP2))
				xVel *= -1;
			if(yPos < TOPEDGE)
				yVel *= -1;
			if(yPos > BOTTOMEDGE)
				yVel *= -1;
			if(xPos <= LEFTEDGE)
				exit = 0;
		xPos = xPos + xVel;
		yPos = yPos + yVel;

		for(i=0;i<100000;i++) {
			while (UP_BUTTON == 0) {
				while(UP_BUTTON == 0);
				if (yPosP >= 1) yPosP -= 1;
				if (yPosP2 >= 2) yPosP2 -= 1;
			}

			while (DOWN_BUTTON == 0) {
				while (DOWN_BUTTON == 0);
				if (yPosP <= 5) yPosP += 1;
				if (yPosP2 <= 6) yPosP2 += 1;
			}
		}

		clearDisplay();
		drawBlock(yPos,xPos);
		drawPaddle(yPosP,xPosP);
		drawPaddle(yPosP2,xPosP2);


			}
		}
