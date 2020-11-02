#include <iostream>

int strlen(char tab[]){
    int i=0;
    while (tab[i] != '\0'){
        i=i+1;
    }
    return i;
}

void print(int* tab, int* top){
    std::cout << "[";
    for(int i=0; i<*top;i++){
        std::cout << tab[i] << " ";
    }
    std::cout << "[" << std::endl;
    
}
int* init_stack(int size){
    int* stack = new int[size];
    return stack;
}
void delete_stack(int* stack){
    delete [] stack;
}

bool is_operand(char* token){
    bool res=1;
    int len = strlen(token);
    for (int i=0; i<len; i++){
        res = res*(token[i] >= '0' and token[i]<='9');
    }
    return res; //pb de 45g qui est opérande
}
bool is_operator(char* token){
    char tok = token[0];
    return((tok == 'x') or (tok == '!') or (tok == '+') or (tok == '-') or (tok == '/'));
}
bool is_binary(char* token){
    char tok = token[0];
    return((tok == 'x') or (tok == '+') or (tok == '-') or (tok == '/'));
}
void push(int* pile, int a, int* top){
    pile[*top] = a;
    *top = *top + 1; //on met la valeur dans la pile et on se place sur la case d'apres
}
int pop(int* pile, int* top){
    *top = *top - 1; // on baisse top de 1 puis on copie
    return pile[*top];
}