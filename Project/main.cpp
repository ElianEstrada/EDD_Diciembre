#include <iostream>
#include <cstdlib>
#include <fstream>
#include "./includes/Classes/User.h"
#include "./includes/SparseMatrix/SparseMatrix.h"

using namespace std;

void keyPass();
void start();
void login();
void adminMenu();
void registerUser();
void sparseMatrixReport();
void departmentAvailableAssetsReport();
void companyAvailableAssetsReport();
void transactionsReport();
void userAssetsReport();
void userAssetsRented();
void orderTransaction();
void userMenu(User *user);
void addAsset(User *user);
void removeAsset(User *user);
void updateAsset(User *user);
void rentAsset(User *user);
void rentedAssets(User *user);
void myRentedAssets(User *user);

SparseMatrix *matrix = new SparseMatrix();

int main() {
    srand(time(nullptr));
    /*string hola = "Norma";
    cout << hola.compare("Elian") << endl;*/

    matrix->insertUser(new User("elian_estrada", "1234", "Elian", "guatemala", "igss"));
    matrix->insertUser(new User("juanito", "1234", "Juan", "jutiapa", "max"));
    matrix->insertUser(new User("pedrito", "1234", "Elian", "jalapa", "usac"));
    matrix->insertUser(new User("mafer", "1234", "Elian", "peten", "cinepolis"));
    matrix->insertUser(new User("juanma", "1234", "Elian", "guatemala", "usac"));
    matrix->insertUser(new User("casimiro", "1234", "Elian", "guatemala", "max"));
    matrix->insertUser(new User("fuego03", "1234", "Elian", "jutiapa", "cinepolis"));
    matrix->insertUser(new User("azurdia", "1234", "Elian", "jutiapa", "usac"));
    start();

    return 0;
}

void keyPass() {
    cout << "\nPress key Into to continue...";
    cin.get();
    system("clear");
}

void start() {

    int option = 0;

    cout << " __        _______ _     ____ ___  __  __ _____   _____ ___       _    ____ ____  _____ _____ ____    ___ _   _  ____ ___  __  __ _____ \n"
            " \\ \\      / / ____| |   / ___/ _ \\|  \\/  | ____| |_   _/ _ \\     / \\  / ___/ ___|| ____|_   _/ ___|  |_ _| \\ | |/ ___/ _ \\|  \\/  | ____|\n"
            "  \\ \\ /\\ / /|  _| | |  | |  | | | | |\\/| |  _|     | || | | |   / _ \\ \\___ \\___ \\|  _|   | | \\___ \\   | ||  \\| | |  | | | | |\\/| |  _|  \n"
            "   \\ V  V / | |___| |__| |__| |_| | |  | | |___    | || |_| |  / ___ \\ ___) |__) | |___  | |  ___) |  | || |\\  | |__| |_| | |  | | |___ \n"
            "    \\_/\\_/  |_____|_____\\____\\___/|_|  |_|_____|   |_| \\___/  /_/   \\_\\____/____/|_____| |_| |____/  |___|_| \\_|\\____\\___/|_|  |_|_____|\n"
            "                                                                                                                                        " << endl;

    cout << "1. Login\n2. Exit" << endl;
    cout << "\nEnter a option: ";
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            keyPass();
            login();
            break;
        case 2:
            cout << "Thanks for use program" << endl;
            keyPass();
            exit(0);
        default:
            cout << "The option isn't valid, please enter valid option" << endl;
            start();
    }
}

void login() {

    string username;
    string password;

    cout << "\n  _     ___   ____ ___ _   _ \n"
            " | |   / _ \\ / ___|_ _| \\ | |\n"
            " | |  | | | | |  _ | ||  \\| |\n"
            " | |__| |_| | |_| || || |\\  |\n"
            " |_____\\___/ \\____|___|_| \\_|\n"
            "                             " << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Insert your password: ";
    cin >> password;

    if (username == "admin" && password == "admin") {
        cin.ignore();
        keyPass();
        adminMenu();
        start();
    }

    string department;
    string company;

    cout << "Enter your department: ";
    cin >> department;
    cout << "Enter your company: ";
    cin >> company;
    cin.ignore();
    // Search user in Sparse Matrix

    User *user = nullptr;

    if (user != nullptr) {
        userMenu(user);

        user = nullptr;
    }

    cout << "The user: " + username + " don't exist" << endl;
    keyPass();
    start();
}

void adminMenu(){

    cout << "     _    ____  __  __ ___ _   _   __  __ _____ _   _ _   _ \n"
            "    / \\  |  _ \\|  \\/  |_ _| \\ | | |  \\/  | ____| \\ | | | | |\n"
            "   / _ \\ | | | | |\\/| || ||  \\| | | |\\/| |  _| |  \\| | | | |\n"
            "  / ___ \\| |_| | |  | || || |\\  | | |  | | |___| |\\  | |_| |\n"
            " /_/   \\_\\____/|_|  |_|___|_| \\_| |_|  |_|_____|_| \\_|\\___/ \n"
            "                                                            " << endl;

    int option;

    cout << "1. Register User\n2. Sparse Matrix Report\n3. Department Available Assets Report\n4. Company Available Assets Report\n5. Transactions Report\n6. User Assets Report"
            "\n7. Assets Rented by a User\n8. Sort Transactions\n9. Sign Out" << endl;

    cout << "Enter a option: ";
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            keyPass();
            registerUser();
            adminMenu();
            break;
        case 2:
            sparseMatrixReport();
            adminMenu();
            break;
        case 3:
            departmentAvailableAssetsReport();
            break;
        case 4:
            companyAvailableAssetsReport();
            break;
        case 5:
            transactionsReport();
            break;
        case 6:
            userAssetsReport();
            break;
        case 7:
            userAssetsRented();
            break;
        case 8:
            orderTransaction();
            break;
        case 9:
            keyPass();
            return;
        default:
            cout << "The option: " + to_string(option) + " is not valid, please enter a valid option" << endl;
            keyPass();
            adminMenu();
    }
}

void userMenu(User *user) {
    cout << "  _   _ ____  _____ ____    __  __ _____ _   _ _   _ \n"
            " | | | / ___|| ____|  _ \\  |  \\/  | ____| \\ | | | | |\n"
            " | | | \\___ \\|  _| | |_) | | |\\/| |  _| |  \\| | | | |\n"
            " | |_| |___) | |___|  _ <  | |  | | |___| |\\  | |_| |\n"
            "  \\___/|____/|_____|_| \\_\\ |_|  |_|_____|_| \\_|\\___/ \n"
            "                                                     " << endl;
    int option;

    cout << "1. Add Asset\n2. Remove Asset\n3. Update Asset\n4. Rent Asset\n5. Rented Assets\n6. My Rented Assets"
            "\n7. Sing Out" << endl;

    cout << "Enter a option: ";
    cin >> option;
    cin.ignore();

    switch (option) {
        case 1:
            addAsset(user);
            break;
        case 2:
            removeAsset(user);
            break;
        case 3:
            updateAsset(user);
            break;
        case 4:
            rentAsset(user);
            break;
        case 5:
            rentedAssets(user);
            break;
        case 6:
            myRentedAssets(user);
            break;
        case 7:
            keyPass();
            return;
        default:
            cout << "The option: " + to_string(option) + " is not valid, please enter a valid option" << endl;
    }
}

void registerUser() {

    cout << "  ____  _____ ____ ___ ____ _____ _____ ____    _   _ ____  _____ ____  \n"
            " |  _ \\| ____/ ___|_ _/ ___|_   _| ____|  _ \\  | | | / ___|| ____|  _ \\ \n"
            " | |_) |  _|| |  _ | |\\___ \\ | | |  _| | |_) | | | | \\___ \\|  _| | |_) |\n"
            " |  _ <| |__| |_| || | ___) || | | |___|  _ <  | |_| |___) | |___|  _ < \n"
            " |_| \\_\\_____\\____|___|____/ |_| |_____|_| \\_\\  \\___/|____/|_____|_| \\_\\\n"
            "                                                                        " << endl;

    string username;
    string password;
    string fullname;
    string department;
    string company;

    cout << "Into Username: ";
    cin >> username;
    cout << "Into Password: ";
    cin >> password;
    cout << "Into Fullname: ";
    cin >> fullname;
    cout << "Into department: ";
    cin >> department;
    cout << "Into Company: ";
    cin >> company;
    cin.ignore();

    matrix->insertUser(new User(username, password, fullname, department, company));

    keyPass();
    return;
}

void sparseMatrixReport() {

    string result = matrix->report();

    string path = "/mnt/d/Documentos/Elian/2024/Usac/Vacaciones_Diciembre/Curso/Clase1/Project/Reports/";
    //string path = "/home/elian_edd/";

    ofstream file(path + "sparseMatrix.dot");

    if(!file) {
        cout << "Error to create file" << endl;
        keyPass();
        return;
    }

    file << result;
    file.close();

    string command = "dot -Tsvg " + path + "sparseMatrix.dot -o " + path + "sparseMatrix.svg > error.log";
    system(command.c_str());

    command = "feh " + path + "sparseMatrix.svg";
    system(command.c_str());
    keyPass();
}

void departmentAvailableAssetsReport() {

}

void companyAvailableAssetsReport() {

}

void transactionsReport() {

}

void userAssetsReport() {

}

void userAssetsRented() {

}

void orderTransaction() {

}

void addAsset(User *user) {

}

void removeAsset(User *user) {

}

void updateAsset(User *user) {

}

void rentAsset(User *user) {

}

void rentedAssets(User *user) {

}

void myRentedAssets(User *user) {

}