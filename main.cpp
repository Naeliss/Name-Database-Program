#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <ctype.h>

std::string menu(std::string &input);
void searchName();
void addName();
void removeName();

int main(int argc, char* argv[])
{
  // std::cout << "Hello World!\n";
  
  bool quit = false;

  std::string line;
  std::string choice;

  std::ifstream file("names.txt");
  if (!file.is_open()){
    std::cout << "Error: File not found!\n";
    return 1;
  }

  //while(std::getline(file, line)){
    // std::cout << line << std::endl;
  //}
  
  do{
    int choice_int;

    menu(choice);

    try {
       choice_int = std::stoi(choice);
    }
    catch (std::invalid_argument const &e) {
      std::cout << "GEEN NUMMER!\n" << std::endl;
    } 

    switch(choice_int){
      case 1:
        searchName();
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        quit = true;
        break;
      default:
        std::cout << "Ongeldige keuze!\n" << std::endl;
        break;
    }

    
    }while(!quit);

  return 0;
}

std::string menu(std::string &input){

  std::cout << "Wat wil je doen?" << std::endl;
  std::cout << "\t1. Naam zoeken" << std::endl;
  std::cout << "\t2. Naam toevoegen" << std::endl;
  std::cout << "\t3. Naam verwijderen" << std::endl;
  std::cout << "\t4. Stoppen" << std::endl;
  std::cout << "Keuze: ";
  std::cin >> input;

  return input;
}

void searchName(){
  std::string name;

  std::cout << "Voer naam in die je wilt zoeken: ";
  std::cin >> name;
  
  bool digitInName;

  for(int i = 0; i < name.length(); i++){
    digitInName = std::isdigit(name[i]);

    if(std::isdigit(name[i])) {
      std::cout << "Geen geldige naam!\n" << std::endl;
      return;
    }

  }
} 
