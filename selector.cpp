#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main(int argc,char** argv)
{
    if(argc==4)
    {
        int fuse = atoi(argv[1]);
        time_t raw;
        struct tm* ptm;

        time(&raw);
        ptm = gmtime(&raw);

        int horas = (ptm->tm_hour+(fuse)%24);
        int minutos = (ptm->tm_min);
        int tempo = (horas*60)+minutos;

        /*Aqui é o pulo do gato, o esperado dos argumentos 2 e 3
        são os endereços das pastas onde os wallpapers ficam. O 2 é o endereço
        do set e o 3 é o endereço do now.png que deve ser setado como wallpaper
        ELE DEVE SE CHAMAR now.png SE QUISER TROCAR, MUDA ISSO AQUI NO CÓDIGO!*/

        string command = "cp "; //Comando de copiar do Linux
        command += string(argv[2]); //exemplo: /home/talkys/Imagens/Daypaper/
        command += to_string(tempo); //O código da imagem
        command += ".png "; //Se for usar outra extensão de imagem, troca aqui E NÃO TIRA O ESPAÇO NO FINAL!
        command += string(argv[3]); //Pasta do now.png
        command += "now.png"; //Troca o nome aqui se quiser

        system(command.c_str());

    }
}