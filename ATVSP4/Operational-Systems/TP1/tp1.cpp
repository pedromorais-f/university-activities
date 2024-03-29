#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 
#include <string.h>

using namespace std;

void clearScreen(){
    getchar();
    system("clear");
}

void printFiles(string filepath){
    fstream file;
    string line;

    file.open(filepath, ios::in);

    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
}



int main(int argc, char const *argv[]){
    
    //File paths
    string versionFilePath = "/etc/lsb-release";
    string studentFilePath = "PedroMorais.txt";

    //Command strings
    string killAllCommand = "killall ";
    string pkillCommand = "pkill ";
    string reniceCommand = "renice ";
    const char *command;

    //Input
    string input;
    string pid;


    //Printing informations in "PedroMorais.txt"
    printFiles(studentFilePath);
    clearScreen();

    //Printing system version
    printFiles(versionFilePath);
    clearScreen();

    //First command "top"
    system("top");
    clearScreen();

    //Second command "ps"
    system("ps");
    clearScreen();

    //Third command "pstree"
    system("pstree");
    clearScreen();

    //Forth command "kill" or "kill -9"
    system("top");
    cout << "Write the command(kill Pids or kill -9 Pids):" << endl;
    getline(cin, input, '\n');
    command = input.c_str();
    system(command);

    cout << "\n" << endl;

    //Fifth command "killall"
    system("top");
    cout << "Write the software:" << endl;
    cin >> input;
    killAllCommand = killAllCommand + input;
    command = killAllCommand.c_str();
    system(command);
    cin.clear();

    cout << "\n" << endl;

    //Sixth command "pkill"
    system("top");
    cout << "Write the software:" << endl;
    cin >> input;
    pkillCommand = pkillCommand + input;
    command = pkillCommand.c_str();
    system(command);
    cin.clear();

    cout << "\n" << endl;

    //Seventh command "renice"
    system("top");
    cout << "Write the priority:" << endl;
    cin >> input;
    cout << "Write the PID:" << endl;
    cin >> pid;
    reniceCommand = reniceCommand + input + " -p " + pid;
    command = reniceCommand.c_str();
    system(command);
    cin.clear();

    cout << "\n" << endl;

    system("top");

    return 0;
}