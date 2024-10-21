// Version 1
// Reads character by character from file
// and prints immediately a token is discovered

#include <stdio.h>
#include <string.h>

int state = 0, bcount = 0;
FILE *fp;

int reset() { bcount = 0; state = 0; fseek(fp, -1, SEEK_CUR); }

int isDigi(char ch) {
	if(ch >= '0' && ch <= '9') return 1;
	return 0;
}

int isIden(char ch) {
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_') return 1;
	return 0;
}

int isOper(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') return 1;
	return 0;
}

int isSymb(char ch) {
	if(ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ';' || ch == ',') return 1;
	return 0;
}

int isWhit(char ch) {
	if(ch == ' ' || ch == '\t' || ch == '\n') return 1;
	return 0;
}

int isKeyw(char *b) {
	if(!strcmp(b, "main") || !strcmp(b, "void") || !strcmp(b, "int")) return 1;
	return 0;
}

void main() {
	char buffer[128], ch;
	fp = fopen("input_1.txt", "r");
	
	while((ch = fgetc(fp)) != EOF) {
		buffer[bcount++] = ch;
		switch(state) {
			case 0:
				if(isDigi(ch)) 
					state = 1;
				if(isIden(ch)) 
					state = 2;
				if(isOper(ch))
					state = 3;
				if(isSymb(ch))
					state = 4;
				if(isWhit(ch)) 
					bcount = 0;
				break;
			case 1:
				if(!isDigi(ch)) {
					buffer[bcount - 1] = '\0';
					printf("Number: \t%s\n", buffer);
					reset();
				}
				break;
			case 2:
				if(!isIden(ch) && !isDigi(ch)) {
					buffer[bcount - 1] = '\0';
					if(isKeyw(buffer)) printf("Keyword: \t%s\n", buffer);
					else printf("Identifier: \t%s\n", buffer);
					reset();
				}
				break;
			case 3:
				if(ch == '/' && buffer[bcount - 2] == '/') 
					state = 5;
				if(!isOper(ch)) {
					buffer[bcount - 1] = '\0';
					printf("Operator: \t%s\n", buffer);
					reset();
				}
				break;
			case 4:
            if(!isSymb(ch)) {
				buffer[bcount - 1] = '\0';
				printf("Symbol: \t%s\n", buffer);
				reset();
            }
				break;
			case 5:
				if(ch == '\n') {
					bcount = 0; 
					state = 0; 
					break;
				}
		}
	}
	fclose(fp);
}