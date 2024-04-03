#include "database.h"
#include <iostream>

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
//헤더파일에 get함수가 entry 포인터 타입으로 지정되어있으므로 포인터를 반환해야함
Entry *get(Database &database, std::string &key){
      //database의 size만큼 데이터베이스의 엔트리를 순회함.
      for (int i = 0; i < database.size; ++i) {
            //현재 엔트리의 키값과 파라미터로 입력받은 키값이 같으면
            if (database.entries[i].key == key) {
                  //해당 엔트리의 포인터를 반환함
                  return &database.entries[i];
            }
      }
      //없으면 nullptr 반환
      return nullptr;
}

//엔트리 값을 출력하는 함수
void entryPrint(Entry *entry){
      //엔트리의 키값을 출력한다.
      std::cout << entry -> key << ": ";

      // value가 void 포인터 타입이므로 원래 타입으로 변환하기 위해 캐스팅하여 출력함
      if (entry -> type == INT) {
            std::cout << *(int*)(entry -> value) << std::endl;
      } else if (entry -> type == DOUBLE) {
                  std::cout << *(double*)(entry -> value) << std::endl;
      } else if (entry -> type == STRING) {
            //출력 형식에 맞게 따옴표 추가
            std::cout << "\"" << *(std::string*)(entry -> value) <<  "\"" << std::endl;
      } else if (entry -> type == ARRAY) {
            Array* arr = (Array*)(entry -> value);
            std::cout << "[";
                  for (int j = 0; j < arr->size; ++j) {
                  if (j > 0) {
                        std::cout << ", ";
                  }
                  if (arr->type == INT) {
                        std::cout << *((int*)(arr->items) + j);
                  } else if (arr->type == DOUBLE) {
                        std::cout << *((double*)(arr->items) + j);
                  } else if (arr->type == STRING) {
                        //출력 형식에 맞게 따옴표 추가
                        std::cout << "\"" << *((std::string*)(arr->items) + j) << "\"";
                  } else if (arr->type == ARRAY) {
                        arrayPrint((Array*)(arr->items));
                  }
            }
            std::cout << "]" << std::endl;
      }
}