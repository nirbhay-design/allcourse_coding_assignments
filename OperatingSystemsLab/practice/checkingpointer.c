#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


int main() {
	int b;
	// char c;
	scanf("%d%*c",&b);
	// char * str = (char*) malloc(sizeof(char)*16);
	// fgets(str,16,stdin);
	// scanf("%[^\n]%*c",str);

	char * mystr =(char *) malloc(sizeof(char) * 16);
	// char c = getchar();
	// while (c != '\n' && c != EOF) {
	// 	c = getchar();
	// }
	fgets(mystr,16,stdin);
	printf("%d %s",b,mystr);
	// int b = 2;
	// char d = 'c';
	// void * p;
	// p = (void *) &b;
	// printf("%d\n",*(int *)p);
	// p = (void *) &d;
	// printf("%p %c\n",(char *)p,*(char*)p);
	return 0;
}
