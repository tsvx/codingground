#include <stdio.h>
#include <stdlib.h>

char buf[256] = { '\0' };
char* b;

typedef struct
{
	char a, b, c, d;
} cmd;

void change_cmd(cmd* p, char x)
{
	printf("p=%p\n", p);
	p->a = x++;
	p->b = x++;
	p->c = x++;
	p->d=0;
}

void print_cmd(char* p)
{
	printf("cmd=%s\n", p);
}

int main(void) {
    printf("ptr is char [256]\n");
	print_cmd(buf);
	change_cmd(buf, '1');
	print_cmd(buf);
	change_cmd(&buf, 'a');
	print_cmd(buf);
	printf("ptr is char*\n");
	b=(char*)malloc(256);
	print_cmd(b);
	change_cmd(b, '7');
	print_cmd(b);
	change_cmd(&b, 'g');
	print_cmd(b);
	free(b);
	return 0;
}
