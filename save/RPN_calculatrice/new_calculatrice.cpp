#include <iostream>
#include <cstdlib>
#include <cstring>
#include "stack.h"

bool is_operand(const char* token){
    bool res=true;
    int len = strlen(token);
    for (int i=0; i<len; i++){
        if (not ((token[i] >= '0') and (token[i]<='9')))
            return false;
    }
    return res;
}
bool is_operator(const char* token){
    char tok = token[0];
    return((tok == 'x') or (tok == '!') or (tok == '+') or (tok == '-') or (tok == '/'));
}
bool is_binary(const char* token){
    char tok = token[0];
    return((tok == 'x') or (tok == '+') or (tok == '-') or (tok == '/'));
}

int rpn_eval(const int n, const char* tab[]){
    bool erreur=0;
    int top=0;
    int size = (n+1)/2;
    int* stack = init_stack(size);
    for(int i=0; i<n; i++){      
        print(stack, &top);
        if (is_operand(tab[i])){
            int operand = atoi(tab[i]);
            push(stack, operand, &top);
        }

        else if (is_operator(tab[i])){
            
            if (!is_binary(tab[i])){ //uniquement pour le ! (-1)
                int a = (-1)*pop(stack, &top);
                push(stack, a, &top);
            }
            
            else{ //L'opérande est binaire
                int a = pop(stack, &top);
                int b = pop(stack, &top);
                char c = tab[i][0];
                
                switch (c) {
                    case '+':{
                        int rep = b+a;
                        push(stack,rep, &top);
                        break;
                    }
                    case '-':{
                        int rep = b-a;
                        push(stack, rep, &top);
                        break;
                    }
                    case 'x':{
                        int rep = b*a;
                        push(stack, rep, &top);
                        break;
                    }                    
                    case '/':{
                        int rep = b/a;
                        push(stack, rep, &top);
                        break;
                    }
                }    
            }
        }
        else {
            std::cout << "ERREUR : mauvais caractère" << std::endl;
            erreur = true;
            break;
            }
    }
    if(erreur == 0){
        int res = stack[0];
        delete_stack(stack);
        return res;
    }
    delete_stack(stack);
    return 1;
}