#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <mysql/mysql.h>
#include "db_response.h"

using namespace std;

typedef struct connection_details
{
    const char *server, *user, *pwd, *database;
} Cdetails;


// Global Variable Movie Ticket Booking System in C++ with MySQL
int chooseUserType;
int running_system;


void login() {

    cout << "Login as user or editor?" << endl << endl;
    cout << "1. user" << endl;
    cout << "2. editor" << endl;
    cout << "Choose One: " << endl;
    cin >> chooseUserType;
}

void Welcome() {

    cout << "Welcome To Movie Ticket Booking System" << endl << endl;
    login();
}

int print_menu() {

    system("clear");
    cout << "====== Menu ======" << endl;

    int num = 1;
    int fin = 0;
    int chooseOneFromMenu;

    for (int i = 0; i < 1; i++) {
        // fin = num;
        cout << fin << ". Change User Type" << endl;
        fin += num;
        cout << fin << ". Book Ticket" << endl;
        fin += num;
        cout << fin << ". Show My Ticket" << endl;
        fin += num;
        cout << fin << ". Check Seat" << endl;
        fin += num;
        if (chooseUserType==2) 
            cout << fin << ". Add New Movie" << endl;
        fin += num;
        if (chooseUserType==2) 
            cout << fin << ". Edit Movie" << endl;
        fin += num;
        if (chooseUserType==2) 
            cout << fin << ". Delete Movie" << endl;
        fin += num;
        cout << fin << ". Show Movie List" << endl;
        fin += num;
        cout << fin << ". Exit" << endl << endl;
        cout << "Choose One: ";
    }
    cin >> chooseOneFromMenu;

    return chooseOneFromMenu;
}

void operate_system() {

    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;

    chooseOneFromMenu = print_menu();

    switch (chooseOneFromMenu)
    {
    case 0:
        login();
        break;
    case 1:
        running_system = DB_response::BookTicket();
        break;
    case 2:
        running_system = DB_response::ShowMyTicket();
        break;
    case 3:
        running_system = DB_response::CheckSeat();
        break;
    case 4:
        if (chooseUserType==1) {
            cout << "Permission denied!" << endl;
            break;
        }
        running_system = DB_response::AddNewMovie();
        break;
    case 5:
        if (chooseUserType==1) {
            cout << "Permission denied!" << endl;
            break;
        }
        running_system = DB_response::EditMovie();
        break;
    case 6:
        if (chooseUserType==1) {
            cout << "Permission denied!" << endl;
            break;
        }
        running_system = DB_response::DeleteMovie();
        break;
    case 7:
        running_system = DB_response::ShowMovieList();
        break;
    case 8:
        ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            running_system = 0;
            return ;
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("clear");
        }else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 7. Press Enter To Continue...";
        system("clear");
        break;
    }

}


#endif 
