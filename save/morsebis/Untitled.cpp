class X{
public:
    X(){
        pi = new int(2);
    }
    ~X(){
        delete pi;
    }

private:
    int* pi;
};

int main(){
    X x;
    return 0;
}

