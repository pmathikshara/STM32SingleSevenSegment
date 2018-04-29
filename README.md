# STM32SingleSevenSegment
To interface a single seven segment with STM32F103RB common cathode and common anode mode for the Standard Peripheral Library
  
/*****************************DETAILS FOR SEVEN SEGMENT PROJECT***********************************/
/*

pins: 0,1,2,3,4,5,6,7
port: C

Common cathode : ON - 0 , OFF - 1
Common anode : ON - 1 , OFF - 0

Common Anode: 						
0	01000000	C0  
1	01111001	F9
2	00100100	A4
3	00110000	B0
4	00011001	99
5	00010010	92
6	00000010	82
7	01111000	F8
8	00000000	80
9	00010000	90

Common Cathode:
0	0111111	3F
1	0000110	06
2	1011011	5B
3	1001111	4F
4	1100110	66
5	1101101	6D
6	1111101	7D
7	0000111	07
8	1111111	7F
9	1001111	4F

I am using common anode configuration here. 

*/
