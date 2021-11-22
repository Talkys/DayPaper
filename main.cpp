#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int16_t now = 0;

//./DayPaper <directory> fuse interval

int main(int argc,char** argv)
{
    if(argc==3)
    {
        int8_t fuse = atoi(argv[2]);
        time_t raw;
        struct tm* ptm;
        int16_t tempo;
        string command;

        while(1)
        {


            time(&raw);
            ptm = gmtime(&raw);
            tempo = ((ptm->tm_hour+(fuse)%24)*60) + (ptm->tm_min);

            command = "cp "; //Comando de copiar do Linux
            command += string(argv[1]); //exemplo: /home/talkys/Imagens/Daypaper/
            command += to_string(tempo); //O código da imagem
            command += ".png "; //Se for usar outra extensão de imagem, troca aqui E NÃO TIRA O ESPAÇO NO FINAL!
            command += string(argv[1]); //Pasta do now.png
            command += "now.png"; //Troca o nome aqui se quiser

            if(tempo!=now)
            {
                now = tempo;
                system(command.c_str());
            }

            this_thread::sleep_for(chrono::milliseconds(30000));
        }
    }
    else if(argc==4)
    {
        int8_t fuse = atoi(argv[2]);
        time_t raw;
        struct tm* ptm;
        int16_t tempo;
        string command;
        int interval = atoi(argv[3]);
        while(1)
        {
            time(&raw);
            ptm = gmtime(&raw);
            tempo = ((ptm->tm_hour+(fuse)%24)*60) + (ptm->tm_min);

            command = "cp "; //Comando de copiar do Linux
            command += string(argv[1]); //exemplo: /home/talkys/Imagens/Daypaper/
            command += to_string(tempo); //O código da imagem
            command += ".png "; //Se for usar outra extensão de imagem, troca aqui E NÃO TIRA O ESPAÇO NO FINAL!
            command += string(argv[1]); //Pasta do now.png
            command += "now.png"; //Troca o nome aqui se quiser


            if(tempo!=now)
            {
                now = tempo;
                system(command.c_str());
            }

            this_thread::sleep_for(chrono::milliseconds(interval));
        }
    }
    else
    {
        cout<<"Argumentos inválidos, seu mané!"<<endl;
        cout<<"Coloque o diretório das imagens, o fuso horário (Brasil é -3) e opcionalmente um intervalo customizado (Em milisegundos)"<<endl;
    }
    return 0;
}
