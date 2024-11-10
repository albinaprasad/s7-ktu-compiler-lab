%{
#include<stdio.h>
char str[20];
int vow_count=0;
int consonant_count=0;    
%}
%%
[AEIOUaeiou] {vow_count++;}
[A-Za-z] {consonant_count++;}
%%
int yywrap(){
    return 1;
}
int main(){
    printf("Enter the string of vowels and consonants : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    yy_scan_string(str);
    yylex();
    printf("Number of vowels are: %d\n", vow_count);
    printf("Number of consonants are: %d\n", consonant_count);
    return 0;
}