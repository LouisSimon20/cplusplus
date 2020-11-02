bool is_operand(char* token);
bool is_operator(char* token);
bool is_binary(char* token);

void push(int* pile, int a, int* top);
int pop(int* pile, int* top);

void print(int* tab, int* top);
void delete_stack(int* stack);
int* init_stack(int size);
int strlen(char tab[]);