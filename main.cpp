#include <iostream>
#include <string>

using namespace std;

/*Argument format: program / wallpaper foler / file extension*/

int main(int argc, char** argv)
{
    if(argc==3)
    {
        cout<<"<background>"<<endl;
        cout<<"  <starttime>"<<endl;
        cout<<"    <year>2021</year>"<<endl;
        cout<<"    <month>01</month>"<<endl;
        cout<<"    <day>11</day>"<<endl;
        cout<<"    <hour>0</hour>"<<endl;
        cout<<"    <minute>00</minute>"<<endl;
        cout<<"    <second>00</second>"<<endl;
        cout<<"  </starttime>"<<endl;

        for(int i=0;i<1440;i++)
        {
            cout<<"  <static>"<<endl;
            cout<<"    <duration>55.0</duration>"<<endl;
            cout<<"    <file>"<<string(argv[1])<<"/"<<i<<string(argv[2])<<"</file>"<<endl;
            cout<<"  </static>"<<endl;
            cout<<"  <transition type=\"overlay\">"<<endl;
            cout<<"    <duration>5.0</duration>"<<endl;
            cout<<"    <from>"<<string(argv[1])<<"/"<<i<<string(argv[2])<<"</from>"<<endl;
            cout<<"    <to>"<<string(argv[1])<<"/"<<i+1<<string(argv[2])<<"</to>"<<endl;
            cout<<"  </transition>"<<endl;
        }

        cout<<"</background>";
    }
}
