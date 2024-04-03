#include "database.h"
//add command 관련 함수

//엔트리를 생성한다.
//헤더파일에 create함수가 entry 포인터 타입으로 지정되어있으므로 포인터를 반환해야함
Entry *create(Type type, std::string key, void *value) {
      //함수를 포인터 타입으로 지정한 이유는 함수 호출이 종료되어도 엔트리 객체가 유지되어야 하기 때문임

      //Entry 타입의 값을 가리키는 포인터를 생성함
      Entry *entry = new Entry;

      //파라미터로 입력받은 type, key, value값을 엔트리의 type, key, value 값에 할당함
      entry->type = type;
      entry->key = key;
      entry->value = value;

      return entry;
}

//데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry){
      //database의 size만큼 데이터베이스의 엔트리를 순회함
      for (int i = 0; i < database.size; ++i) {
            //현재 엔트리의 키값과 추가하고싶은 엔트리의 키값이 같으면
            if (database.entries[i].key == entry->key) {
                  //새로 추가하려는 엔트리의 값으로 할당해줌
                  database.entries[i].value = entry->value;
                  database.entries[i].type = entry->type;
                  return;
            }
      }

      //데이터베이스의 크기+1한 size인 Entry를 생성함
      Entry *entries = new Entry[database.size + 1];

      // 새로 생성한 엔트리에 기존 엔트리의 값을 할당함
      for (int i = 0; i < database.size; ++i) {
            entries[i] = database.entries[i];
      }

      // 새로 생성한 엔트리에 값을 다 옮긴뒤, 기존 엔트리 값을 해제함
      delete[] database.entries;

      // 새로 생성한 엔트리의 마지막 인덱스에 파라미터로 입력받은 entry값을 할당함
      entries[database.size] = *entry;

      // 데이터베이스 엔트리 값을 새로 생성한 엔트리 값으로 할당함
      database.entries = entries;

      // 엔트리가 추가 되었으므로 사이즈를 증가시킴
      database.size++;
}