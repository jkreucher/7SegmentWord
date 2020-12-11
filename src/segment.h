#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <stdio.h>
#include <string.h>

const unsigned char symbols[128];

void print_segment_letter(char c);
void print_segment_str(char* c);

int check_segment_letter(char c);
int check_segment_str(char* c);
int ignore_char(char c);

#endif
