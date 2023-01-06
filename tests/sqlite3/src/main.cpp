#include "sqlitedatabase.h"

#include <string>
#include <iostream>
#include <sqlite3.h>


int main(int argc, char **argv)
{

try{
   myPong::SQLiteDatabase myDB("myPongDB.db3");

  // get info of a specific user
   std::vector<myPong::UserInfo> users=myDB.getUserData("nour","123");
   for (myPong::UserInfo user: users){
         user.print();
         std::cout<<std::endl;
   }

   std::cout<< "Found: "<<users.size() <<" users\n----------------------------\n" <<std::endl;
   std::cout<< "Found: "<<myPong::__users.size() <<" users\n----------------------------\n" <<std::endl;


/*
// test inserting record
   myDB.insertNewUser("moaz", "abc");
   
   // get all users info
   users=myDB.getUserData();
   for (myPong::UserInfo user: users){
         user.print();
         std::cout<<std::endl;
   }
*/

}catch (std::string e){
   std::cout << "Exception: "<< e << std::endl;
   return EXIT_FAILURE; // unexpected error : exit the example program
}







   return (0);
}