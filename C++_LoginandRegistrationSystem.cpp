#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// isLoggedIn will go through Username and Password to verify user is registered.
bool isLoggedIn() {

  string username, password, un, pw;

  cout << "Enter Username: ";
  cin >> username;
  cout << "Enter Password: ";
  cin >> password;

  // need to read the file and check for username and password
  ifstream read("data\\" + username + ".txt");
  getline(read, un);
  getline(read, pw);
  // checking for username and password in text file and returning true or false if they match
  if(un == username && pw == password)
  {
    return true;
  }
  else {

    return false;
  }

}

int main() {

  int choice;


  cout << "Register: 1\n Login: 2\n Your choice? :";
  cin >> choice;

  if(choice == 1){
    // asking for user input for username and password
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout<< "Enter your password: ";
    cin >> password;

    // creating file and saving username and password to file in format for isLoggedIn in read
    ofstream file;
    file.open("data\\" + username + ".txt");
    file << username << endl << password;
    file.close();

    main();
  }
  else if(choice == 2) {
    bool status = isLoggedIn();

    if(!status) {
      cout << "Invalid Login" << endl;
      system("pause");
      return 0;

    }
    else {
      cout << "Successful Login" << endl;
      return 1;

    }


  }







}
