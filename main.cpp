#include "database.h"
#include <iostream>
#include <string>

int main(){
      Database db;
      init(db);

      while(true){
            std::string command = commandInput();

            if (command == "add"){
                  std::string key = keyInput();
                  Type type = typeInput();
                  void *value;
                  //type이 유효할때만
                  if (type == ARRAY){
                        value = arrayInput(type);
                        if ( value != nullptr){
                              Entry *entry = create(type, key, value);
                              add(db, entry);
                        }

                  } else if (type == INT || type == DOUBLE || type == STRING){
                        value = valueInput(type);
                        Entry *entry = create(type, key, value);
                        add(db, entry);
                  }

            } else if (command == "list"){
                  listPrint(db);
            } else if (command == "get"){
                  std::string key = keyInput();
                  Entry *entry = get(db, key);
                  if (entry != nullptr){
                        entryPrint(entry);
                  } else {
                        std::cout << "not found";
                        std::cout << std::endl;
                  }
            } else if (command == "del"){
                  std::string key = keyInput();
                  remove(db, key);
            } else if (command == "exit"){
                  destroy(db);
                  break;
            } else{
                  std::cout << "invalid command";
                  std::cout << std::endl;
            }
            std::cout << std::endl;
      }

      return 0;
}