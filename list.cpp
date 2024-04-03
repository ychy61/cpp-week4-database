#include "database.h"
#include <iostream>

// 데이터베이스 목록을 출력한다.
void listPrint(Database &database) {
      for (int i = 0; i < database.size; ++i) {
            //엔트리의 키값을 출력한다.
            std::cout << database.entries[i].key << ": ";

            // 엔트리의 value가 void 포인터 타입이므로 원래 타입으로 변환하기 위해 캐스팅을 함
            if (database.entries[i].type == INT) {
                  std::cout << *((int*)(database.entries[i].value)) << std::endl;
            } else if (database.entries[i].type == DOUBLE) {
                  std::cout << *((double*)(database.entries[i].value)) << std::endl;
            } else if (database.entries[i].type == STRING) {
                  std::cout << "\"" << *((std::string*)(database.entries[i].value)) <<  "\"" << std::endl;
            } else if (database.entries[i].type == ARRAY) {
                  Array* arr = (Array*)(database.entries[i].value);

                  //출력 형식에 맞게 대괄호 추가함
                  std::cout << "[";
                  arrayPrint(arr);

                  std::cout << "]" << std::endl;
            }
      }
}

//배열을 출력한다.
void arrayPrint(Array* arr){
      for (int j = 0; j < arr->size; ++j) {
            if (j > 0) {
                  std::cout << ", ";
            }
            if (arr->type == INT) {
                  std::cout << *((int*)(arr->items) + j);
            } else if (arr->type == DOUBLE) {
                  std::cout << *((double*)(arr->items) + j);
            } else if (arr->type == STRING) {
                  std::cout << "\"" << *((std::string*)(arr->items) + j) << "\"";
            } else if (arr->type == ARRAY) {

                  std::cout << "[";
                  for (int i = 0; i < arr->size; ++i) {
                        if (i > 0) {
                        std::cout << ", ";
                        }
                              arrayPrint(((Array**)(arr->items))[i]); // 재귀 호출로 다음 차원의 배열 출력
                  }
                  std::cout << "]";
            }
      }
}
