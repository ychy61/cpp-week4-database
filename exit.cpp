#include "database.h"
// 데이터베이스를 해제한다.
void destroy(Database &database){
      delete database.entries;
}