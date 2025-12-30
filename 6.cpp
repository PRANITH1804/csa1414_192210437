#include <stdio.h>
#include <stdlib.h>

char *input;
int ip=0;

char look() { return input[ip]; }

void match(char c) { 
    if(look()==c) ip++; 
    else { 
        printf("Error\n"); 
        exit(0); 
    } 
}

void E(); void X(); void T(); void Y(); void F();

void E(){ T(); X(); }
void X(){ if(look()=='+'){ match('+'); T(); X(); } }
void T(){ F(); Y(); }
void Y(){ if(look()=='*'){ match('*'); F(); Y(); } }
void F(){ 
    if(look()=='i') match('i'); 
    else if(look()=='('){ match('('); E(); match(')'); } 
    else { printf("Error\n"); exit(0); } 
}

int main(){
    char str[20];
    printf("Enter input ending with $: ");
    scanf("%s",str);
    input = str;
    E();
    if(input[ip]=='$') printf("Accepted\n");
    else printf("Rejected\n");
    return 0;
}
