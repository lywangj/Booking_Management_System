// g++ main.cpp -o output -L/usr/lib/mysql -lmysqlclient

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "interface.h"
#include "db_response.h"
#include <mysql/mysql.h>


using namespace std;


// int main(int argc, char *argv[]) {
int main() {

    system("clear");

    Cdetails mysqlD;
    mysqlD.server = "localhost";  // where the mysql database is
    mysqlD.user = "root";         // user
    mysqlD.pwd = "og21893";       // the password for the database
    mysqlD.database = "movie";	  // the databse

    DB_response::ConnectionFunction(mysqlD.server, mysqlD.user, mysqlD.pwd, mysqlD.database);

    // set system status
    running_system = 1;

    Welcome();

    while (running_system) {

        operate_system();
    }

    return 0;
}

