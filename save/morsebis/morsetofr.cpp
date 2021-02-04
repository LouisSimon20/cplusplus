#include <iostream>
#include <cstring>
#include <string>

void read_morse(std::string morse){
    char cara; //caractère francais
    int i = 0; // itérateur message
    int j = 0; //itérateur mots
    while(i<strlen(morse.c_str())){
        switch (morse[i+j])// 1er niveau : e ou t ou
        {
        case '.':{
            cara = 'e';
            j++;
            switch (morse[i+j])//2ème niveau
            {
            case '.':{
                j++;
                cara = 'i';
                switch (morse[i+j])//3ème niveau
                {
                case '.':{
                    cara = 's';
                    j++;
                    switch (morse[i+j]) 
                    {
                    case '.':{
                        cara = 'h'; //FINI (pour le moment)
                        std::cout << cara;
                        i=i+j+2;
                        j=0;
                        break;
                    }

                    case '-':{
                        cara ='v'; //FINI (pour le moment)
                        break;
                    }

                    case ' ':{
                        std::cout << cara;
                        i=i+j+1;
                        j=0;
                        break;
                    }
                    }
                    break;
                }
        
                case '-':{
                    cara ='u';
                    j++;
                    switch (morse[i+j])
                    {
                    case '.':{
                        cara = 'f';//FIN
                        j++;
                        break;
                    }

                    case ' ':{
                        std::cout << cara;
                        i=i+j+1;
                        j=0;
                        break;
                    }
                    }
                    break;
                }

                case ' ':{
                    std::cout << cara;
                    i=i+j+1;
                    j=0;
                    break;
                }
                }
                break;
            }

            case '-':{
                j++;
                cara ='a';
                switch (morse[i+j]){
                case '.':{
                    cara = 'r';
                    j++;
                    switch (morse[i+j])
                    {
                    case '.':{
                        cara = 'l';
                        j++;
                        //FIN
                        break;
                    }

                    case ' ':{
                        std::cout << cara;
                        i=i+j+1;
                        j=0;
                        break;
                    }
                    }
                    break;
                }
        
                case '-':{
                    cara ='w';
                    switch (morse[i+j])
                    {
                    case '.':{
                        cara = 'p';
                        j++;//FIN
                        break;
                    }
        
                    case '-':{
                        cara ='j';//FIN
                        break;
                    }

                    case ' ':{
                        std::cout << cara;
                        i=i+j+1;
                        j=0;
                        break;
                    }
                    }
                }

                case ' ':{
                    std::cout << cara;
                    i=i+j+1;
                    j=0;
                    break;
                }
                }
            }

            case ' ':{ // le code est celui de e :
                std::cout << cara;
                i=i+j+1;
                j=0;
                //std::cout << "i:"<<i<<" j:"<<j;
                break;
            }
            }
            break;
        }
        
        case '-':{
            cara ='t';
            switch (morse[i+j])
            {
            case '.':{
                cara = 'n';
                j++;
                break;
            }
        
            case '-':{
                cara ='m';
                break;
            }

            case ' ':{
                std::cout << cara;
                i=i+j+1;
                j=0;
                break;
            }
            }
            break;
        }

        case '/':{ //normalement on vient de passer un ' ' donc j=0
            std::cout << ' ';
            i=i+2;
            break;
        }
        }
    }
}

/* int main()
{
    std::string morse;
    //char car;
    getline(cin, morse);
    read_morse(morse);
} */


/*     switch (morse[i+j])
    {
    case '.':{
        cara = '';
        j++;
    }
    
    case '-':{
        cara ='';
    }

    case ' ':{
        std::cout << cara;
        i=i+j+1;
        j=0;
    }
    } */