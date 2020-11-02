bool is_operand(char* token);
bool is_operator(char* token);
bool is_binary(char* token);

int rpn_eval(int n, char* tab[]);