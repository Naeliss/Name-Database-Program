#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

std::string menu(std::string &input);
void searchName(std::vector<std::string> &names);
void addName();
void removeName();

int main(int argc, char* argv[]){
  bool quit = false;

  std::string choice;
  std::string line;

  std::vector<std::string> names;

  std::ifstream file("names.txt");

  if (!file.is_open()){
    std::cout << "Error: File not found!\n";
    return 1;
  }

  while(std::getline(file, line)){
    names.push_back(line);
  }
  
  do{
    std::sort(names.begin(), names.end());
    
    int choice_int;

    menu(choice);

    try {
       choice_int = std::stoi(choice);
    }
    catch (std::invalid_argument const &e) {
      std::cout << "GEEN NUMMER!\n" << std::endl;
      choice_int = -1;
    } 

    switch(choice_int){
      case -1:
        break;
      case 1:
        searchName(names);
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        quit = true;
        break;
      case 7070:      /* for debugging */
        for(int i =0; i < names.size(); i++){
          std::cout << "index: " << i << "\t" << names[i] << std::endl;
        }
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

void searchName(std::vector<std::string> &names){
  std::string name;

  std::cout << "Voer naam in die je wilt zoeken: ";
  std::cin >> name;
  
  int nameLength = name.length();

  bool digitInName;

  for(int i = 0; i < name.length(); i++){
    digitInName = std::isdigit(name[i]);

    if(std::isdigit(name[i])) {
      std::cout << "Geen geldige naam!\n" << std::endl;
      return;
    }    
  }

  std::vector<std::string> matchingNames;
  
  for(int i = 0; i < names.size(); i++){
    bool found = names[i].find(name) != std::string::npos;
    if(found){
      matchingNames.push_back(names[i]);
    }
  }

  if(matchingNames.empty()){
    std::cout << "Geen namen gevonden!" << std::endl;
  } 
  else{
    for(int i = 0; i< matchingNames.size(); i++){
      std::cout << "Gevonden namen: " << matchingNames[i] << std::endl;
    }
  }
  
} 


