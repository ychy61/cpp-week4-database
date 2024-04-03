#ifndef DATABASE_H
#define DATABASE_H

#include <string>

enum Type { INT, DOUBLE, STRING, ARRAY };

struct Array {
  int size;
  Type type;
  void *items;
};

struct Entry {
  Type type;
  std::string key;
  void *value;
};

struct Database {
  Entry *entries;
  int size;
};

// 엔트리를 생성한다.
Entry *create(Type type, std::string key, void *value);

// 데이터베이스를 초기화한다.
void init(Database &database);

// 데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry);

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry *get(Database &database, std::string &key);

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key);

// 데이터베이스를 해제한다.
void destroy(Database &database);

/*-----추가 함수-----*/

//command를 입력 받는다.
std::string commandInput();

//key값을 입력 받는다.
std::string keyInput();

//type을 입력 받는다.
Type typeInput();

//값(value)을 입력 받는다.
void* valueInput(Type type);

//데이터베이스 목록을 출력한다.
void listPrint(Database &database);

//엔트리를 출력한다.
void entryPrint(Entry *entry);

Type typeCheck(std::string strType);

void* createArray(Type type, int size);
void* arrayInput(Type type);
void arrayPrint(Array* arr);

void *createMultiArray();

#endif