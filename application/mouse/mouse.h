/**
 * @file mouse.cpp
 * @author Sandeep T, Sandeep sharan, Sourang Sri hari
 * 
 * @brief This file contains the functions responsible for movements of the robot and setting the walls of the maze.
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MOUSE_H__
#define __MOUSE_H__

#pragma once

#include <array>
#include <memory>

namespace rwa2group16
{
    /**
     * @brief This class makes the robot to move and store the current position
     */
    class Robot
    {
    public:
        // make the robot turn left and store the position & direction and also set color to the cell
        void turn_left();
        // make the robot turn right and store the position & direction and also set color to the cell
        void turn_right();
        // make the robot move forward and store the position & direction and also set color to the cell
        void move_forward();
        // make the robot turn around and store the position & direction and also color to the cell
        void turn_around();
        // accessing the private attribute m_position
        std::pair<int, int> get_position() { return m_position; }
        // accessing the private attribute m_direction
        char get_direction() { return m_direction; }

    private:
        // initiating the initial position as 0,0 - Origin
        std::pair<int, int> m_position{0, 0};
        // initiating the initial direction as n - north
        char m_direction{'n'};
    }; // Robot Class
} // namespace rwa2group16

namespace rwa2group16
{
    /**
     * @brief This class implements the search algorithm.
     */
    class Algorithm
    {
    public:
        // initialize outer walls, generate goal, execute right-hand rule approach
        void run_right();
        // initialize outer walls, generate goal, execute left-hand rule approach
        void run_left();
        // color outer walls
        void init_outer_walls();
        // algorithm for left-hand rule approach
        void follow_wall_left();
        // algorithm for right-hand rule approach
        void follow_wall_right();
        // generate random goal adjacent to an outer wall
        void generate_goal();
        // set current wall in m_maze and in simulator
        void set_current_wall();

    private:
        //!<@brief A maze is a 2D array of cells.
        std::unique_ptr<Robot> robot;
        // To store the value of the randomly generated goal
        std::pair<int, int> goal;
        int m_maze_height;
        int m_maze_width;
    }; // Algorithm class
} // namespace rwa2group16

#endif