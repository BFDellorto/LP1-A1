#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace std;
    int i;
    string message;
    ofstream arquivo_saida;
    ifstream arquivo_entrada;
    
    //mensagem para nenhum comando sendo utilizado
    if (argc == 1){
        cout << "Uso: " << argv[0] << " <comando>" << " <menssagem>";
        return 1;
    }

    //mensagem para caso o comando 'add' seja utilizado
    if (strcmp(argv[1],"add") == 0) {
        arquivo_saida.open("diario.txt", ios::app);
        if (arquivo_saida.fail()){
           cerr << "ERROR. Nao foi possivel criar o arquivo";
           return 1;
        }
        //comando 'add' sem mensagem no terminal
        if(argc == 2){
            cout << "Digite uma mensagem" << endl;
            getline(cin, message);
            arquivo_saida << message << endl;
            arquivo_saida.close();
            return 0;
        }
            
        //comando 'add' com mensagem no terminal
        else {
            arquivo_saida << argv[2] << endl;
            arquivo_saida.close();
            return 0;
        }
    }

    //mensagem para caso o comando 'list' seja utilizado
    if (strcmp(argv[1],"list") == 0) {
        arquivo_entrada.open("diario.txt");
        int line = 0;
        while(!arquivo_entrada.eof()){
            line++;
            getline(arquivo_entrada, message);
            if (message.size() == 0){continue;}
            cout << line << ". " << message << endl;
        }
        arquivo_entrada.close();
        return 0;
            
    }
        
    //mensagem para comandos desconhecidos
    cerr << "ERROR. Unknown command";
    return 1;
}


