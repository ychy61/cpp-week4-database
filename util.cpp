#include "database.h"
#include <iostream>
#include <string>

// 데이터베이스를 초기화한다.
void init(Database &database) {
      database.entries = nullptr;
      database.size = 0;
}

//명령어를 입력받는 함수
std::string commandInput(){
      std::string command;
      std::cout << "command (list, add, get, del, exit): ";
      std::cin >> command;
      return command;
}

//키를 입력받는 함수
std::string keyInput(){
      std::string key;
      std::cout << "Key: ";
      std::cin >> key;

      return key;
}

//타입을 입력받는 함수
Type typeInput(){
      std::string strType;
      std::cout << "type (int, double, string, array): ";
      std::cin >> strType;
      //typeCheck함수를 통해 문자열로 받은 타입값을 변환한다.
      Type type = typeCheck(strType);
      return type;
}

//문자열로 받은 타입값을 변환해줌
Type typeCheck(std::string strType){
      Type type;
      if (strType == "int"){
            type = INT;
            return type;
      } else if (strType == "double"){
            type = DOUBLE;
            return type;
      } else if (strType == "string"){
            type = STRING;
            return type;
      } else if (strType == "array"){
            type = ARRAY;
            return type;
      } else {
            //해당하는 type이 없으면 invalid type
            std::cout << "invalid type"<< std::endl;
      }
}

//INT, DOUBLE, STRING 타입의 값을 입력받는 함수
void *valueInput(Type type){
      //value가 void 포인터 타입이므로 포인터로 값을 반환해야함
      if (type == INT) {
            //int 타입의 값을 가리키는 포인터를 생성함
            int *value = new int;
            //value의 주소에 입력 받은 값 저장
            std::cout << "Value: ";
            std::cin >> *value;
            //value의 주소 반환
            return value;
      }
      if (type == DOUBLE) {
            double *value = new double;
            std::cout << "Value: ";
            std::cin >> *value;
            return value;
      }
      if (type == STRING) {
            std::string *value = new std::string;

            std::cout << "Value: ";
            std::cin >> *value;

            return value;
      }
}

//ARRAY 타입의 값을 입력 받는 함수
void *arrayInput(Type type){
      if (type == ARRAY) {
            //value가 void 포인터 타입이므로 포인터로 값을 반환해야함
            //Array 타입의 값을 가리키는 포인터를 생성함
            Array *value = new Array;

            std::string strType;//문자열로 타입값을 받는 변수

            int size;//배열의 사이즈

            //타입을 입력받음
            std::cout << "value: type (int, double, string, array): " ;
            std::cin >> strType;

            //문자열로 입력받은 type을 typechek함수를 통해서 변환함
            Type valueType = typeCheck(strType);

            //유효한 type일때만 이어서 입력받음
            if (valueType == INT || valueType == DOUBLE || valueType == STRING || valueType == ARRAY){
                  std::cout << "size: ";
                  std::cin >> size;
                  value->size = size;
                  value->type = valueType;
                  value->items = createArray(valueType,size);
                  return value;
            } else {
                  return nullptr;
            }

      }
}

//array를 생성하는 함수
void *createArray(Type type, int size){
      //배열의 items가 void 포인터 타입이므로 포인터로 값을 반환해야함
      if (type == INT) {
            //int 타입의 배열을 가리키는 포인터를 생성함
            int *arr = new int[size];

            for(int i = 0; i < size; i++){
                  std::cout << "item[" << i << "]: ";
                  std::cin >> arr[i];
            }

            return arr;
      } else if (type == DOUBLE){
            double *arr = new double[size];

            for(int i = 0; i < size; i++){
                  std::cout << "item[" << i << "]: ";
                  std::cin >> arr[i];
            }

            return arr;

      } else if (type == STRING) {
            std::string *arr = new std::string[size];

            std::string strValue;
            for(int i = 0; i < size; i++){
                  std::cout << "item[" << i << "]";
                  std::cin >> arr[i];
            }

            return arr;
      }
      else if (type == ARRAY){
            //각 배열 원소의 포인터를 지시하기 위해 Array타입의 이중 포인터를 생성함
            Array **arr = new Array*[size];
            for (int i = 0; i < size; ++i) {
                  std::cout << "item[" << i << "]: ";
                  //각 원소에 대한 배열을 입력받기 위해 createMultiArray함수 호출
                  arr[i] = (Array*)createMultiArray();
            }

            return arr;
      }

}

//다중배열 시 각 원소의 배열을 생성
void *createMultiArray(){
      int size;
      std::string typeStr;

      // 사용자로부터 배열의 타입을 입력 받음
      std::cout << "type (int, double, string, array): ";
      std::cin >> typeStr;

      Type type = typeCheck(typeStr);
      // 사용자로부터 배열의 크기를 입력 받음
      std::cout << "size: ";
      std::cin >> size;

      // createArray() 함수 호출하여 배열 생성 후 반환
      return createArray(type, size);
}

