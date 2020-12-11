#include <stdio.h>
#include "segment.h"

int main() {
	FILE* file = fopen("ngerman", "r");
	char line[128];

	char max_len_word[128];
	
	// iterate through whole file
	while( fgets(line, sizeof(line), file) ) {
		if( check_segment_str(line) ) {
			if( strlen(line) > strlen(max_len_word) ) {
				// remember longest word
				strcpy(max_len_word, line);
				
				/*
				// print every new word thats longer
				print_segment_str(line);
				printf("\n\n");
				*/
			}
		}
	}

	// print longest word
	print_segment_str(max_len_word);
	
	return 0;
}

