bool is_operand(const char* token);
bool is_operator(const char* token);
bool is_binary(const char* token);

int rpn_eval(const int n, const char* tab[]);