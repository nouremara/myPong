// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Own string Class

/**========================================================================
 * @file      utilstring.h
 * @brief     implementation of own string class.
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de, nour
 * @repo      https://github.com/nouremara/cpp_mystring
 * @createdOn 23.11.2022
 * @version   1.0.0
 * @description
 *
 * This file presents an implementation of a class named string.
 * This class behavior will be similar and compatible to the std::string.
 * This file contains the prototypes for the class, its methods and eventually
 * any macros, constants, or global variables you will need to use it.
 *========================================================================**/

#ifndef SQLITEDB_H
#define SQLITEDB_H

#include "userinfo.h"

#include <sqlite3.h>

#include <cassert>
#include <exception>
#include <iostream>
#include <string>

namespace myPong {
static std::vector<myPong::UserInfo> __users;

/**
 * @brief Implementation of of own class to manage a SQLite Database Connection.
 *
 * A Database object manage a list of all SQLite Statements associated with the
 * underlying SQLite 3 database connection.
 */
class SQLiteDatabase {
  sqlite3 *DB;
  std::string dbFileName;
  std::string db_status_message;
  int db_status;
  std::string sql;

public:
  /*=========================================================================*
   *                         Constructors                                    *
   *=========================================================================*/
  /**
   * @brief default constructor with empty initialization
   *
   * This constructor is ommitted as database can nnot be created without a file
   * name.
   */
  SQLiteDatabase() = delete;

  /**
   * @brief Open the provided database filename.
   *
   * Uses sqlite3_open_v2() with SQLITE_OPEN_READWRITE flag, which is the
   * opposite behavior of the old sqlite3_open() function (READWRITE+CREATE).
   * This makes sense as it prevents creation of a void file when a required DB
   * file is missing.
   *
   * Exception is thrown in case of error, then the Database object is NOT
   * constructed.
   *
   * @param[in] fileName  path/uri to the database file ("filename" sqlite3
   * parameter)
   *
   * @throw SQLite::Exception in case of error
   */
  SQLiteDatabase(const std::string fileName) : dbFileName(fileName) {
    /*
     * Open the database for read and write.
     * The database file must pre-exist or an error will be given.
     */
    int db_status =
        sqlite3_open_v2(dbFileName.c_str(), &DB, SQLITE_OPEN_READWRITE, NULL);

    if (db_status != SQLITE_OK) {
      // db_status_message = "Error open DB [" + std::to_string(db_status) + "]
      // " + sqlite3_errmsg(DB);
      db_status_message =
          "in\n" + std::string(__FILE__) + "\n" + __func__ + " : " +
          std::to_string(__LINE__) + " for sqlite3_open_v2() with:\ncode:[" +
          std::to_string(db_status) + "] message: " + sqlite3_errmsg(DB);

      // std::cerr << db_status_message<<std::endl;
      throw db_status_message;
    } else {
      db_status_message = "Opened Database Successfully!";
    }
  }

  /*=========================================================================*
   *                         Destructor                                      *
   *=========================================================================*/
  /** Destructor to do the final cleanup and memory deallocation */
  ~SQLiteDatabase() {
    db_status = sqlite3_close(DB); // Calling sqlite3_close() with a nullptr
                                   // argument is a harmless no-op.

    // Only case of error is SQLITE_BUSY: "database is locked" (some statements
    // are not finalized) Never throw an exception in a destructor :
    if (!(SQLITE_OK == db_status)) {
      // Print a message to the standard error output stream, and abort the
      // program.
      std::cerr << __FILE__ << ":" << __LINE__ << ":"
                << " error: assertion failed (sqlite3_close()) in " << __func__
                << "() with message: database is locked\n";
      assert(SQLITE_OK == db_status);
      // std::abort();
    }
  }

  std::string get_db_status() { return db_status_message; }

  std::vector<myPong::UserInfo> & getUserData(
	const std::string desiredUserName = "",
	const std::string desiredUserPassword = ""
  ) {
    // delete all previous users inf
    __users.clear();

    /** Create SQL statement 
	   e.g., SELECT * FROM USERS WHERE userName ='abc' AND password ='xyz'
	*/
    if (desiredUserName.empty() && desiredUserPassword.empty()) {
      sql = "SELECT * FROM USERS;";
    } else if (desiredUserPassword.empty()) {
      sql = "SELECT * FROM USERS WHERE userName ='" + desiredUserName + "';";
    } else {
      sql = "SELECT * FROM USERS WHERE userName ='" + desiredUserName +"' AND password ='" + desiredUserPassword + "';";
    }

    /* Execute SQL statement */
    char *zErrMsg = 0;
    db_status = sqlite3_exec(DB, sql.c_str(), callback, NULL, &zErrMsg);
    return __users;
  }

  static int callback(
      void *data,       /*< Data provided in the 4th argument of sqlite3_exec() */
      int colCount,     /*< The number of columns in row */
      char **rowFields, /*< An array of strings representing fields in the row */
      char **azColName  /*< An array of strings representing column names */
  ) {
	// fill the users vector with current record data
    __users.push_back(UserInfo(atoi(rowFields[0]), rowFields[1], rowFields[2],
                               atoi(rowFields[3]), atoi(rowFields[4]),
                               atoi(rowFields[5]), atoi(rowFields[6]),
                               atoi(rowFields[7]), atoi(rowFields[8])));
    return 0;
  }

  void insertNewUser(std::string userName, std::string password, int score = 0,
                     int level = 0, int ballX = -1, int ballY = -1,
                     int leftPaddelY = -1, int rightPaddelY = -1) {
    char *zErrMsg = 0;

    /* Create SQL statement */
    sql = "INSERT INTO USERS "
          "(userName,password,score,level,ballX,ballY,leftPaddelY,rightPaddelY)"
          " VALUES ('" +
          userName + "', '" + password + "', " + std::to_string(score) + "," +
          std::to_string(level) + "," + std::to_string(ballX) + "," +
          std::to_string(ballY) + "," + std::to_string(leftPaddelY) + "," +
          std::to_string(rightPaddelY) + ");";

    /* Execute SQL statement */
    db_status = sqlite3_exec(DB, sql.c_str(), NULL, NULL, &zErrMsg);
    if (db_status != SQLITE_OK) {
      std::cerr << "Error adding new user: " << zErrMsg << std::endl;
      sqlite3_free(zErrMsg);

      throw db_status_message;
    } else {
      std::cout << "Adding new user done successfully" << std::endl;
    }
  }

  void throwException(int valueToCheck, char *errMsg, std::string op) {
    if (valueToCheck != SQLITE_OK) {
      db_status_message = "in\n" + std::string(__FILE__) + "\n" + __func__ +
                          " : " + std::to_string(__LINE__) + " for " + op +
                          " with:\ncode:[" + std::to_string(valueToCheck) +
                          "] message: " + errMsg;
      sqlite3_free(errMsg);
    } else {
      std::cout << op << " done successfully" << std::endl;
    }
  }
};

} // namespace myPong

#endif /* SQLITEDB_H */