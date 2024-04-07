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
                  arrayPrint(arr);
                  std::cout << std::endl;
            }
      }
}

void arrayPrint(Array* array) {
      std::cout << "[";
      for (int i = 0; i < array->size; ++i) {
            if (array->type == INT) {
                  int* items = static_cast<int*>(array->items);
                  std::cout << items[i];
            } else if (array->type == DOUBLE) {
                  double* items = static_cast<double*>(array->items);
                  std::cout << items[i];
            } else if (array->type == STRING) {
                  std::string* items = static_cast<std::string*>(array->items);
                  std::cout << "\"" << items[i] << "\"";
            } else if (array->type == ARRAY) {
                  Array** items = static_cast<Array**>(array->items);
                  if (array->items == ""){
                        break;
                  }
                  arrayPrint(items[i]);
            }
            if (i < array->size - 1) {
                  std::cout << ", ";
            }
      }
      std::cout << "]";
}