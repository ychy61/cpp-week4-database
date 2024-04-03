#include "database.h"
#include <iostream>

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key){
      bool check = false; //// 키값이 발견됐는지를 알 수 있는 변수, true면 키값이 있고 false면 키값이 없는 것임

      //데이터베이스의 크기-1한 size인 Entry를 생성함
      Entry *entries = new Entry[database.size - 1];

      int new_index = 0;//새로 생성한 엔트리의 index

      //database의 size만큼 데이터베이스의 엔트리를 순회함.
      for (int i = 0; i < database.size; ++i) {
            //현재 엔트리의 키값과 파라미터로 입력받은 키값이 같으면

            //현재 엔트리 뒤에 있는 값들을 땡겨서 저장함
            if (database.entries[i].key == key) {
                  check = true;
                  continue;
            }
            entries[new_index] = database.entries[i];
            new_index++;

      }
      //기존 엔트리 값을 해제함
      delete[] database.entries;

      //데이터베이스 엔트리 값을 새로 생성한 엔트리 값으로 할당함
      database.entries = entries;

      //엔트리가 제거되었으므로 사이즈를 감소시킴
      database.size--;
      // 키값을 발견하지 못한 경우 출력함
      if (check == false) {
            std::cout << "not found" << std::endl;
      }
}