/**
 * @file main.cpp
 * @author Sandeep Thalapanane, Sandip Sharan Senthil Kumar, Sourang Sri Hari
 * @brief  The main is responsible for creating the object for diffreent classes and calling its member classes
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

#include "simulator/simulator.h"
#include "mouse/mouse.h"

int main(int argc, char *argv[])
{
    auto A = std::make_unique<rwa2group16::Algorithm>();
    if (std::string(argv[1]) == "-left")
    {
        A->run_left();
    }
    else if (std::string(argv[1]) == "-right")
    {
        A->run_right();
    }
}