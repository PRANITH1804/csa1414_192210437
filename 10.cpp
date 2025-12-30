#include <stdio.h>
#include <string.h>

char stack[20]; int top=-1;
void push(char c){stack[++top]=c;}
char pop(){return stack[top--];}
char peek(){return top>=0?stack[top]:'\0';}

char N[]={'E','X','T','Y','F'};
char T[]={'i','+','*','(',')','$'};
char *P[5][6]={{"TX","","","TX","",""},{"","+TX","","","e","e"},{"FY","","","FY","",""},{"","e","*FY","","e","e"},{"i","","","(E)","",""}};

int r(char c){for(int i=0;i<5;i++)if(N[i]==c)return i; return -1;}
int c(char a){for(int i=0;i<6;i++)if(T[i]==a)return i; return -1;}

void parse(char *in){
    push('$'); push('E'); int ip=0; char a=in[ip], x=peek();
    while(x!='$'){
        if(x==a){pop(); a=in[++ip];}
        else if(strchr(T,x)){printf("Error\n"); return;}
        else{
            int i=r(x), j=c(a);
            if(i==-1||j==-1||strlen(P[i][j])==0){printf("Error\n"); return;}
            pop();
            if(strcmp(P[i][j],"e"))for(int k=strlen(P[i][j])-1;k>=0;k--) push(P[i][j][k]);
        }
        x=peek();
    }
    if(a=='$') printf("Accepted\n");
    else printf("Rejected\n");
}

int main(){
    char in[20];
    scanf("%s",in);
    parse(in);
    return 0;
}
