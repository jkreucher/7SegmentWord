#include "segment.h"

// Segment-Bit order:
// PGFEDCBA

const unsigned char symbols[] = {
	0b00111111, // 0 ASCII:30h 48dec
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111, // 9
	0, // :
	0, // ;
	0, // <
	0, // =
	0, // >
	0, // ?
	0, // @
	0b01110111, // A
	0, // B
	0b01111100, // C
	0, // D
	0b01111001, // E
	0b01110001, // F
	0b00111101, // G
	0b01110110, // H
	0b00000110, // I
	0b00011110, // J
	0, // K
	0b00111000, // L
	0, // M
	0, // N
	0b00111111, // O
	0b01110011, // P
	0, // Q
	0, // R
	0b01101101, // S
	0, // T
	0b00111110, // U
	0, // V
	0, // W
	0, // X
	0b01110010, // Y
	0b01011011, // Z
	0, // [
	0, // \ 
	0, // ]
	0, // ^
	0b00001000, // _
	0, // '
	0, //
	0, // a
	0b01111100, // b
	0b01011000, // c
	0b01011110, // d
	0, // e
	0b00110001, // f
	0b01101111, // g
	0b01110100, // h
	0b00000100, // i
	0b00001110, // j
	0, // k
	0b00110000, // l
	0, // m
	0b01010100, // n
	0b01011100, // o
	0, // p
	0b01100111, // q
	0b01010000, // r
	0, // s
	0b01111000, // t
	0b00011100, // u
	0, // v
	0, // w
	0, // x
	0b01101110, // y
	0, // z
};

/*
void print_segment_letter(char x) {
	// convert symbol to segment inforamtion
	x = symbols[x-48];

	for(int r=0; r<9; r++) {
		for(int c=0; c<6; c++) {
			// Segment A
			if( (x & 0b00000001) && (c >= 1) && (c <= 4) && (r == 0) ) {
				printf("#");
			}
			// segment G
			else if( (x & 0b01000000) && (c >= 1) && (c <= 4) && (r == 4) ) {
				printf("#");
			}
			// segment D
			else if( (x & 0b00001000) && (c >= 1) && (c <= 4) && (r == 8) ) {
				printf("#");
			}
			// segment F
			else if( (x & 0b00100000) && (r >= 1) && (r <= 3) && (c == 0) ) {
				printf("#");
			}
			// segment B
			else if( (x & 0b00000010) && (r >= 1) && (r <= 3) && (c == 5) ) {
				printf("#");
			}
			// segment E
			else if( (x & 0b00010000) && (r >= 5) && (r <= 7) && (c == 0) ) {
				printf("#");
			}
			// segment C
			else if( (x & 0b00000100) && (r >= 5) && (r <= 7) && (c == 5) ) {
				printf("#");
			}
			// empty
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}
*/


/* Print a string with 7 Segments
 * ******************************
 * 
 * x -> Pointer to string
 */
void print_segment_str(char* x) {

	for(int r=0; r<9; r++) {
		for(int c=0; c<10*strlen(x); c++) {

			int num = c/10;                            // current letter number
			unsigned char sym = symbols[ x[num]-48 ]; // current symbol byte

			char csym = c%10; // current symbol column

			// Segment A
			if( (sym & 0b00000001) && (csym >= 1) && (csym <= 4) && (r == 0) ) {
				printf("#");
			}
			// segment G
			else if( (sym & 0b01000000) && (csym >= 1) && (csym <= 4) && (r == 4) ) {
				printf("#");
			}
			// segment D
			else if( (sym & 0b00001000) && (csym >= 1) && (csym <= 4) && (r == 8) ) {
				printf("#");
			}
			// segment F
			else if( (sym & 0b00100000) && (r >= 1) && (r <= 3) && (csym == 0) ) {
				printf("#");
			}
			// segment B
			else if( (sym & 0b00000010) && (r >= 1) && (r <= 3) && (csym == 5) ) {
				printf("#");
			}
			// segment E
			else if( (sym & 0b00010000) && (r >= 5) && (r <= 7) && (csym == 0) ) {
				printf("#");
			}
			// segment C
			else if( (sym & 0b00000100) && (r >= 5) && (r <= 7) && (csym == 5) ) {
				printf("#");
			}
			// empty
			else {
				printf(" ");
			}

		}
		printf("\n");
	}
}




int check_segment_letter(char c) {
	return symbols[c-48];
}

int check_segment_str(char* c) {
	for(int i=0; i<strlen(c); i++) {
		if( (check_segment_letter(c[i])==0) && (ignore_char(c[i])==0) ) {
			return 0;
		}
	}
	return 1;
}


const char ignore_these[] = {'\n'};
int ignore_char(char c) {
	for(int i=0; i<sizeof(ignore_these); i++) {
		if(c == ignore_these[i]) return 1;
	}
	return 0;
}