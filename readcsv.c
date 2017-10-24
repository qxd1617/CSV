#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){

	long zipCount = -1;
	long totalPop = 0;
	long lowZip = 0;
	long lowPop = 1000000000;
	long highZip = 0;
	long highPop =0;
	char line[1024];

	while (fgets (line, sizeof(line), stdin) != NULL){

		zipCount++;
		int spot = 0;
		int i;
		int length = strlen (line);	
		char thisPop[13] = "";
		char thisZip[6] = "";
		int popI = 0;
		int zipI = 0;
		for (i = 0; i <length; i++){
			char ch = line[i];
			if(ch  == ','){
				spot++;
			}
			else{
				if (spot == 0){
					thisZip[zipI] = ch;
					zipI++;
				}
				if (spot == 1){
					thisPop[popI] = ch;
					popI++;
				}	
			}
		}
		char *zipEnd;
		char *popEnd;
		long zip = strtol(thisZip, &zipEnd, 10);
                long pop = strtol(thisPop, &popEnd, 10);
		//printf("The number of people living in %lu is %lu\n", zip, pop);
		if (pop != 0){
			if (pop > highPop){
				highPop = pop;
				highZip = zip;
			}
			if (pop < lowPop){
				lowPop = pop;
				lowZip = zip;
			} 
			totalPop += pop;
		}

	
	}
	printf("Total population across %lu zipcodes is %lu.\n", zipCount, totalPop);	
	printf("The fewest people live in %lu, population %lu.\n", lowZip, lowPop);
	printf("The most people live in %lu, population %lu.\n", highZip, highPop);
	return 0;
}

