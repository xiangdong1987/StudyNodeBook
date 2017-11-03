#include <assert.h>
#include <stdio.h>

int main(void){
	int a=1;
	printf("%d",a);
	a--;
	assert(a);
	printf("%d",a);
	return a;
}
