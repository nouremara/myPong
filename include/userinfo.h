// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Own string Class

/**========================================================================
 * @file      userinfo.h
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

#ifndef USERINFO_H
#define USERINFO_H

#include <iostream>
#include <string>
#include <vector>


namespace myPong
{
    /**
     * @brief Implementation of of struct to manage user data.
     */
    struct UserInfo
    {
        int userID;
        std::string userName;
        std::string password;
        int score;
        int level;
        int ballX;
        int ballY;
        int leftPaddelY;
        int rightPaddelY;

        /*=========================================================================*
         *                         Constructors                                    *
         *=========================================================================*/
        /**
         * @brief default constructor with empty initialization
         */
        UserInfo()
        {
            userID = -1;
            userName = "Guest";
            password = "";
            score = 0;
            level = 0;
            ballX = -1;
            ballY = -1;
            leftPaddelY = -1;
            rightPaddelY = -1;
        }

        /**
         * @brief
         * @param[in]
         */
        UserInfo(int userID, std::string userName, std::string password, int score, int level, int ballX, int ballY, int leftPaddelY, int rightPaddelY) : 
                userID(userID),
                userName(userName),
                password(password),
                score(score),
                level(level),
                ballX(ballX),
                ballY(ballY),
                leftPaddelY(leftPaddelY),
                rightPaddelY(rightPaddelY) {}


                void print(){
       			std::cout << "userID =" << userID << std::endl
                        << "userName =" << userName << std::endl
                        << "password =" << password << std::endl
                        << "score =" << score << std::endl
                        << "level =" << level << std::endl
                        << "ballX =" << ballX << std::endl
                        << "ballY =" << ballY << std::endl
                        << "leftPaddelY =" << leftPaddelY << std::endl
                        << "rightPaddelY =" << rightPaddelY << std::endl;
                }
    };

} // namespace myPong

#endif /* USERINFO_H */
