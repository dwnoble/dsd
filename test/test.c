#include <stdio.h>
#include "string.h"
#include "common.h"

void test_string();
void assert(unsigned char b);
int main(int argc, char *argv[]) {
	printf("DSD Test Driver\n");
	test_string();	
	return 0;
}

void assert(unsigned char b){
	if (b) printf("Assertion passed\n");
	else printf("FAILED assertion\n");
}

void test_string(){
	printf("Testing memcpy...\n");
	unsigned char source[] = {1,2,3};
	unsigned char dest[] = {4,5,6};
	int i;	
	memcpy(dest,source,2);
	for(i = 0; i < 2; i ++ ) {
		printf("Testing: dest[%d] == source[%d] == %d\n", i,i, dest[i]);
		assert(dest[i]==source[i]);
	}
	printf("Testing: dest[2] == 6\n");
	assert(dest[2]==6);
	return;
}
