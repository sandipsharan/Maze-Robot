/**
 * @file mouse.cpp
 * @author Sandeep Thalapanane, Sandip Sharan Senthil Kumar, Sourang Sri Hari
 * 
 * @brief This file contains the functions responsible for movements of the robot and setting the walls of the maze.
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include "../simulator/simulator.h"
#include "mouse.h"

auto r = std::make_unique<rwa2group16::Robot>();
std::pair<int, int> position = r->get_position();
char direction = r->get_direction();

/**
 * @brief Guides the robot to turn left in the maze
 * 
 */
void rwa2group16::Robot::turn_left()
{
    Simulator::turnLeft();
    if (direction == 'n')
    {
        position.first--;
        direction = 'w';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 's')
    {
        position.first++;
        direction = 'e';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'e')
    {
        position.second++;
        direction = 'n';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'w')
    {
        position.second--;
        direction = 's';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
}


/**
 * @brief Guides the robot to move forward
 * 
 */
void rwa2group16::Robot::move_forward()
{
    Simulator::moveForward();
    if (direction == 'n')
    {
        position.second++;
        direction = 'n';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 's')
    {
        position.second--;
        direction = 's';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'e')
    {
        position.first++;
        direction = 'e';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'w')
    {
        position.first--;
        direction = 'w';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
}

/**
 * @brief guides the robot to turn right
 * 
 */
void rwa2group16::Robot::turn_right()
{
    Simulator::turnRight();
    if (direction == 'n')
    {
        position.first++;
        direction = 'e';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 's')
    {
        position.first--;
        direction = 'w';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'e')
    {
        position.second--;
        direction = 's';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'w')
    {
        position.second++;
        direction = 'n';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
}

/**
 * @brief commands the robot to turn around in case of dead ends
 * 
 */
void rwa2group16::Robot::turn_around()
{
    Simulator::turnLeft();
    Simulator::turnLeft();
    Simulator::moveForward();
    if (direction == 'n')
    {
        position.second--;
        direction = 's';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 's')
    {
        position.second++;
        direction = 'n';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'e')
    {
        position.first--;
        direction = 'w';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
    else if (direction == 'w')
    {
        position.first++;
        direction = 'e';
        Simulator::setColor(position.first, position.second, 'G');
        std::cerr << "X: " << position.first << " " << "Y: " << position.second << "\n";
        std::cerr << "Direction :" << direction << "\n";
    }
}

/**
 * @brief To generate the destination goal of the robot in the maze
 * 
 */
void rwa2group16::Algorithm::generate_goal()
{
    m_maze_height = Simulator::mazeWidth() ;
    m_maze_width = Simulator::mazeWidth() ;
    std::cerr << "The maze size is: " << m_maze_height << "x" << m_maze_width << '\n';
    time_t t;
    srand((unsigned)time(&t));
    int x = std::rand() % m_maze_width;
    if (x == 0 || x == (m_maze_width - 1))
    {
        int y = std::rand() % (m_maze_height-1) + 1;
        Simulator::setText(x, y, "G");
        Simulator::setColor(x, y, 'R');
        goal.first = x;
        goal.second = y;
    }
    else
    {
        std::array<int, 2> g{0, (m_maze_height-1)};
        int y = g.at(std::rand() % 2);
        Simulator::setText(x, y, "G");
        Simulator::setColor(x, y, 'R');
        goal.first = x;
        goal.second = y;
    }
}

/**
 * @brief Right hand rule algorithm function
 * 
 */
void rwa2group16::Algorithm::follow_wall_right()
{
    set_current_wall();
    bool a{true};
    std::cerr << "Generated goal position:" << "(" << goal.first << "," << goal.second << ")" << "\n";
    while (a == true)
    {
        Simulator::setColor(position.first, position.second, 'G');
        if (Simulator::wallRight() == 0)
        {
            std::cerr << "Moving Right" << "\n";
            robot->turn_right();
            Simulator::moveForward();
            set_current_wall();
        }
        else if (Simulator::wallFront() == 0)
        {
            std::cerr << "Moving Front" << "\n";
            robot->move_forward();
            set_current_wall();
        }
        else if (Simulator::wallLeft() == 0)
        {
            std::cerr << "Moving left" << "\n";
            robot->turn_left();
            Simulator::moveForward();
            set_current_wall();
        }
        else
        {
            std::cerr << "Turning Around" << "\n";
            robot->turn_around();
            set_current_wall();
        }
        if (position.first == goal.first && position.second == goal.second)
        {
            a = false;
            std::cerr << "Destination reached" << "\n";
        }
    }
}

/**
 * @brief Left hand rule algorithm function
 * 
 */
void rwa2group16::Algorithm::follow_wall_left()
{
    set_current_wall();
    bool a{true};
    std::cerr << "Generated goal position:" << "(" << goal.first << "," << goal.second << ")" << "\n";
    while (a == true)
    { 
        Simulator::setColor(position.first, position.second, 'G');
        if (Simulator::wallLeft() == 0)
        {
            std::cerr << "Moving left" << "\n";
            robot->turn_left();
            Simulator::moveForward();
            set_current_wall();
        }
        else if (Simulator::wallFront() == 0)
        {
            std::cerr << "Moving Front" << "\n";
            robot->move_forward();
            set_current_wall();
        }
        else if (Simulator::wallRight() == 0)
        {
            std::cerr << "Moving Right" << "\n";
            robot->turn_right();
            Simulator::moveForward();
            set_current_wall();
        }
        else
        {
            std::cerr << "Turning Around" << "\n";
            robot->turn_around();
            set_current_wall();
            std::cerr << "x :" << position.first << "y : " << position.second << "\n";
        }
        if (position.first == goal.first && position.second == goal.second)
        {
            a = false;
            std::cerr << "Destination reached" << "\n";
        }
    }
}
/**
 * @brief Colour the outer walls of the maze
 * 
 */

void rwa2group16::Algorithm::init_outer_walls()
{
    int x = 0;
    char direction = 'w';
    for (int y = 0; y <= 15; ++y)
    {
        Simulator::setWall(x, y, direction);
    }
    x = 15;
    direction = 'e';
    for (int y = 0; y <= 15; ++y)
    {
        Simulator::setWall(x, y, direction);
    }
    int y = 0;
    direction = 's';
    for (int x = 0; x <= 15; ++x)
    {
        Simulator::setWall(x, y, direction);
    }
    y = 15;
    direction = 'n';
    for (int x = 0; x <= 15; ++x)
    {
        Simulator::setWall(x, y, direction);
    }
}

/**
 * @brief Set the walls of the current cell of the robot
 * 
 */
void rwa2group16::Algorithm::set_current_wall()
{
    if (Simulator::wallFront())
    {
        if (direction == 'n')
            Simulator::setWall(position.first, position.second, direction);
        else if (direction == 's')
            Simulator::setWall(position.first, position.second, direction);
        else if (direction == 'e')
            Simulator::setWall(position.first, position.second, direction);
        else if (direction == 'w')
            Simulator::setWall(position.first, position.second, direction);
    }
    if (Simulator::wallLeft())
    {
        if (direction == 'n')
            Simulator::setWall(position.first, position.second, 'w');
        else if (direction == 's')
            Simulator::setWall(position.first, position.second, 'e');
        else if (direction == 'e')
            Simulator::setWall(position.first, position.second, 'n');
        else if (direction == 'w')
            Simulator::setWall(position.first, position.second, 's');
    }
    if (Simulator::wallRight())
    {
        if (direction == 'n')
            Simulator::setWall(position.first, position.second, 'e');
        else if (direction == 's')
            Simulator::setWall(position.first, position.second, 'w');
        else if (direction == 'e')
            Simulator::setWall(position.first, position.second, 's');
        else if (direction == 'w')
            Simulator::setWall(position.first, position.second, 'n');
    }
}
/**
 * @brief Calls the functions responsible for generating goal, set outer walls and left hand algorithm
 * 
 */
void rwa2group16::Algorithm::run_left(){
    init_outer_walls();
    generate_goal();
    follow_wall_left();
}

/**
 * @brief Calls the functions responsible for generating goal, set outer walls and right hand algorithm
 * 
 */
void rwa2group16::Algorithm::run_right(){
    init_outer_walls();
    generate_goal();
    follow_wall_right();
}