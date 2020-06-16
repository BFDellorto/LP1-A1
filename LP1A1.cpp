#include <stdio.h>
#include <iostream>
#include <string.h>

int main(int argc, char *argv[])
{
    using namespace std;
    int i;
    string message;
    
    //mensagem para nenhum comando sendo utilizado
    if (argc == 1){
        cout << "Uso: " << argv[0] << " add" << " <menssagem>";
        return 1;
    }
    
    //mensagem para caso algum comando seja utilizado
    if (argc > 1){
        
        //comando 'add'
        if (strcmp(argv[1],"add") == 0) {
            
            //comando 'add' sem mensagem no terminal
            if(argc == 2){
                cout << "Digite uma mensagem" << endl;
                getline(cin, message);
                cout << message;
                return 0;
            }
            
            //comando 'add' com mensagem no terminal
            else if(argc > 2){
                message = "";
                for(i=2; i < argc; i++){
                    message = message + argv[i];
                    message = message + " ";
                }
                cout << message;
                return 0;
            }
            
            //mensagem para erros estranhos
            else{
                cout << "ERROR. Unknown error";
                return 1;
            }
        }
        
        //mensagem para comandos desconhecidos
        else{
            cout << "ERROR. Unknown command";
            return 1;
        }
    }
    
    //mensagem para erros estranhos
    cout << "ERROR. Unknown error";
    return 1;
}

