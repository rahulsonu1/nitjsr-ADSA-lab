
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <ctype.h>  // for isdigit

// // #define MAX 100

// // // -------- Stack Implementation --------
// // char stack[MAX];
// // int top = -1;

// // void push(char c) {
// //     if (top == MAX - 1) {
// //         printf("Error: Stack Overflow\n");
// //         exit(1);
// //     }
// //     stack[++top] = c;
// // }

// // char pop() {
// //     if (top == -1) {
// //         printf("Error: Stack Underflow\n");
// //         exit(1);
// //     }
// //     return stack[top--];
// // }

// // char peek() {
// //     if (top == -1) return '\0';  // safe return if empty
// //     return stack[top];
// // }

// // // -------- Helper Functions --------
// // int precedence(char op) {
// //     switch (op) {
// //         case '/': return 3;
// //         case '*': return 2;
// //         case '+': return 1;
// //         case '-': return 1;
// //         default: return 0;
// //     }
// // }

// // int isOperator(char c) {
// //     return (c == '+' || c == '-' || c == '*' || c == '/');
// // }

// // // -------- Infix to Postfix Conversion --------
// // void infixToPostfix(char* infix, char* postfix) {
// //     int i = 0, k = 0;
// //     char c;

// //     while ((c = infix[i++]) != '\0') {
// //         if (isdigit(c)) {
// //             // Operand → directly add to postfix
// //             postfix[k++] = c;
// //         }
// //         else if (c == '(') {
// //             push(c);
// //         }
// //         else if (c == ')') {
// //             // Pop until '('
// //             while (top != -1 && peek() != '(') {
// //                 postfix[k++] = pop();
// //             }
// //             if (top == -1) {
// //                 printf("Error: Unbalanced parentheses\n");
// //                 exit(1);
// //             }
// //             pop(); // remove '('
// //         }
// //         else if (isOperator(c)) {
// //             // Pop while precedence of stack top >= current operator
// //             while (top != -1 && precedence(peek()) >= precedence(c)) {
// //                 postfix[k++] = pop();
// //             }
// //             push(c);
// //         }
// //         else {
// //             printf("Error: Invalid character '%c'\n", c);
// //             exit(1);
// //         }
// //     }

// //     // Pop remaining operators
// //     while (top != -1) {
// //         if (peek() == '(') {
// //             printf("Error: Unbalanced parentheses\n");
// //             exit(1);
// //         }
// //         postfix[k++] = pop();
// //     }

// //     postfix[k] = '\0'; // null terminate string
// // }

// // // -------- Main Function --------
// // int main() {
// //     char infix[MAX], postfix[MAX];

// //     printf("Enter infix expression: ");
// //     scanf("%s", infix);

// //     infixToPostfix(infix, postfix);

// //     printf("Postfix expression: %s\n", postfix);

// //     return 0;
// // }

// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <ctype.h>
// // #define MAX 100

// // char st[MAX]; int top=-1;
// // void push(char c){ st[++top]=c; }
// // char pop(){ return st[top--]; }
// // char peek(){ return top==-1?'\0':st[top]; }
// // int prec(char c){ return c=='/'?3:c=='*'?2:(c=='+'||c=='-'); }

// // int main(){
// //     char in[MAX],post[MAX]; int i=0,k=0; char c;
// //     printf("Enter infix: "); scanf("%s",in);

// //     while((c=in[i++])){
// //         if(isdigit(c)) post[k++]=c;
// //         else if(c=='(') push(c);
// //         else if(c==')'){
// //             while(top!=-1 && peek()!='(') post[k++]=pop();
// //             if(top==-1){ printf("Error: Unbalanced parentheses\n"); return 1; }
// //             pop();
// //         }
// //         else if(c=='+'||c=='-'||c=='*'||c=='/'){
// //             while(top!=-1 && prec(peek())>=prec(c)) post[k++]=pop();
// //             push(c);
// //         }
// //         else { printf("Error: Invalid char %c\n",c); return 1; }
// //     }
// //     while(top!=-1){
// //         if(peek()=='('){ printf("Error: Unbalanced parentheses\n"); return 1; }
// //         post[k++]=pop();
// //     }
// //     post[k]='\0';
// //     printf("Postfix: %s\n",post);
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #define MAX 100
// int evaluatePostfix(char post[]);

// char st[MAX]; int top=-1;
// void push(char c){ st[++top]=c; }
// char pop(){ return st[top--]; }
// char peek(){ return top==-1?'\0':st[top]; }
// int prec(char c){ return c=='/'?3:c=='*'?2:(c=='+'||c=='-'); }

// int main(){
//     char in[MAX],post[MAX]; int i=0,k=0; char c;
//     printf("Enter infix: "); scanf("%s",in);

//     while((c=in[i++])){
//         if(isdigit(c)) post[k++]=c;
//         else if(c=='(') push(c);
//         else if(c==')'){
//             while(top!=-1 && peek()!='(') post[k++]=pop();
//             if(top==-1){ printf("Error: Unbalanced parentheses\n"); return 1; }
//             pop();
//         }
//         else if(c=='+'||c=='-'||c=='*'||c=='/'){
//             while(top!=-1 && prec(peek())>=prec(c)) post[k++]=pop();
//             push(c);
//         }
//         else { printf("Error: Invalid char %c\n",c); return 1; }
//     }
//     while(top!=-1){
//         if(peek()=='('){ printf("Error: Unbalanced parentheses\n"); return 1; }
//         post[k++]=pop();
//     }
//     post[k]='\0';
//     printf("Postfix: %s\n",post);

//     // call evaluate function here
//     printf("Result: %d\n", evaluatePostfix(post));
// }  

// int evaluatePostfix(char post[]) {
//     int valSt[MAX], vtop=-1;
//     for(int i=0; post[i]!='\0'; i++){
//         char c = post[i];
//         if(isdigit(c)){
//             valSt[++vtop] = c - '0'; // push digit
//         }
//         else if(c=='+' || c=='-' || c=='*' || c=='/'){
//             if(vtop < 1){ 
//                 printf("Warning: Not enough operands for '%c', skipping\n", c);
//                 continue; // skip invalid operator
//             }
//             int b = valSt[vtop--];
//             int a = valSt[vtop--];
//             switch(c){
//                 case '+': valSt[++vtop] = a + b; break;
//                 case '-': valSt[++vtop] = a - b; break;
//                 case '*': valSt[++vtop] = a * b; break;
//                 case '/': 
//                     if(b==0){ 
//                         printf("Warning: Division by zero, skipping\n"); 
//                         valSt[++vtop] = 0; 
//                     } else valSt[++vtop] = a / b; 
//                     break;
//             }
//         }
//         else {
//             // Warn but ignore invalid characters
//             printf("Warning: Ignoring invalid character '%c'\n", c);
//         }
//     }

//     if(vtop != 0){
//         printf("Warning: Postfix may be invalid, multiple values remain\n");
//     }

//     return valSt[vtop >= 0 ? vtop : 0]; // return 0 if stack is empty
// }


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int evaluatePostfix(char post[]);

char st[MAX]; 
int top=-1;

void push(char c){ st[++top]=c; }
char pop(){ return st[top--]; }
char peek(){ return top==-1?'\0':st[top]; }
int prec(char c){ return (c=='/'?3 : c=='*'?2 : (c=='+'||c=='-')); }

int main(){
    char in[MAX], post[MAX]; 
    int i=0, k=0; 
    char c;

    printf("Enter infix: "); 
    scanf("%s", in);

    while((c=in[i++])){
        if(isdigit(c)){
            post[k++] = c;  // only single digit
        }
        else if(c=='(') push(c);
        else if(c==')'){
            while(top!=-1 && peek()!='(') post[k++]=pop();
            if(top==-1){ 
                printf("Error: Unbalanced parentheses\n"); 
                return 1; 
            }
            pop(); // remove '('
        }
        else if(c=='+'||c=='-'||c=='*'||c=='/'){
            while(top!=-1 && prec(peek())>=prec(c)) 
                post[k++]=pop();
            push(c);
        }
        else { 
            printf("Error: Invalid char %c in infix\n", c); 
            return 1; 
        }
    }
    while(top!=-1){
        if(peek()=='('){ 
            printf("Error: Unbalanced parentheses\n"); 
            return 1; 
        }
        post[k++] = pop();
    }
    post[k]='\0';

    printf("Postfix: %s\n", post);
    printf("Result: %d\n", evaluatePostfix(post));
}  

int evaluatePostfix(char post[]) {
    int valSt[MAX], vtop=-1;

    for(int i=0; post[i]!='\0'; i++){
        char c = post[i];

        if(isdigit(c)){
            valSt[++vtop] = c - '0'; // push single digit
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/'){
            if(vtop < 1){ 
                printf("Warning: Not enough operands for '%c'\n", c);
                continue;
            }
            int b = valSt[vtop--];
            int a = valSt[vtop--];
            switch(c){
                case '+': valSt[++vtop] = a + b; break;
                case '-': valSt[++vtop] = a - b; break;
                case '*': valSt[++vtop] = a * b; break;
                case '/': 
                    if(b==0){ 
                        printf("Warning: Division by zero, using 0\n");
                        valSt[++vtop] = 0; 
                    } else valSt[++vtop] = a / b; 
                    break;
            }
        }
        else if(isalpha(c)){
            printf("Error: Invalid operand '%c' found in postfix (ignored)\n", c);
            // skip alphabet, do not crash
        }
        else {
            printf("Warning: Ignoring unknown character '%c'\n", c);
        }
    }

    if(vtop != 0){
        printf("Warning: Postfix may be invalid, multiple values remain\n");
    }

    return valSt[vtop >= 0 ? vtop : 0];
}
