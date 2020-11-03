#include <iostream>
#include <cstdlib>
#include "stack.h"

bool is_operand(const char* token){
    bool res=1;
    int len = strlen(token);
    for (int i=0; i<len; i++){
        res = res*(token[i] >= '0' and token[i]<='9');
    }
    return res; //pb de 45g qui est opérande
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
            int operand = atoi(tab[i]); //transformation en int
            push(stack, operand, &top);
        }

        if (is_operator(tab[i])){
            
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
                        int rep = a+b;
                        push(stack,rep, &top);
                        break;
                    }
                    case '-':{
                        int rep = b-a;
                        push(stack, rep, &top);
                        break;
                    }
                    case 'x':{
                        int rep = a*b;
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
        if(!is_operand(tab[i]) and !is_operator(tab[i])){
            std::cout << "ERREUR : mauvais caractère" << std::endl;
            i = n; //Pour sortir de la boucle de calcul
            erreur = true;
            }
    }
    if(erreur == 0){
        int res = stack[0];
        delete_stack(stack);
        return res;
    }
    return 1;
}