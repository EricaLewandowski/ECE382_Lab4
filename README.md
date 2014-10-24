ECE382_Lab4
===========
Goals: Use CCS in C language to create and etch a sketch and a pong game

#Prelab

Table 1

|Size  |Signed/Unsigned	|Type| Min value |	Max value |
|------|----------------|----|-----------|------------|
|8-bit |	unsigned	    |Char| 0 or -128 |	255 or 127|
|8-bit |	signed	      |Signed char|	-128|	127
|16-bit|	unsigned	    |unsigned short	|0 |	65535
|16-bit|	signed	      |Signed short|	-32768 |	32767
|32-bit|	unsigned	    |Unsigned long|	0	| 4294967295
|32-bit|	signed	      |Long, signed long|	-2,147,483,648 |	2147483647
|64-bit|	unsigned	    |Unsigned long long|	0	| 18446744073709551615
|64-bit|	signed	      |Long long, signed long long|	-9223372036854775808 |	9223372036854775807


Table 2

|Type	 | Meaning	              |  C typedef declaration |
|------|------------------------|------------------------|
|int8	 | unsigned 8-bit value	  |typedef	unsigned char int8; |
|sint8 |  signed 8-bit value	  |  typedef	signed char sint8;
|int16 | unsigned 16-bit value  |	  typedef unsigned short int16;
|sint16|signed 16-bit value	    | typedef	signed short sint16;
|int32 | unsigned 32-bit value	|  typdef unsigned long int32;
|sint32|signed 32-bit value	    |typedef	signed long sint32;
|int64 | unsigned 64-bit value	| typedef unsigned long long int64;
|sint64|signed 64-bit value	    | typedef signed long long sint64;

Table 3

|Iteration	| a |	b |	c |	d |	e |
|-----------|---|---|---|---|---|
|1st	      |2	|2	|3	|4	|2 |
|2nd	      |8	|9	|8	|7	|8|
|3rd	      |14	|15	|14	|13	|14|
|4th	      |20	|21	|20	|19	|20|
|5th	      |26	|27	|26	|25	|26|

Table 4

|Parameter	| Value Sought |
|-----------|--------------|
|Starting address of func |	0xC0BA |
|Ending address of func |	0xC0C6 |
|Register holding w |	R12 |
|Register holding x |	R13 |
|Register holding y |	R14 |
|Register holding z |	R15 |
|Register holding return value |	R12 |

Q1: What is the role of the extern directive in a .c file?

An extern is the opposite of a local variable. Using the extern directive allows for outside use per say, so that other files linked to a header to main file might access it. The difference between extern and using a local variable however is that extern only declares a variable. It does not define the variable. 

Q2: What is the role of the .global directive in an .asm file (used in lines 28-32)? 

The .global directive allows for a symbol to be defined in the current file and used in another, or defined in another file and used in the current one. 

#Req. Functionality

#B Functionality

#A Functionality 

#Documentation: C2C Nathan Ruprecht assisted me with B & A Functionality. We went through his code and he explained it in English, 
and then we translated it to my code. 
