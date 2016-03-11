/* 
 * File:   Log.hpp
 * Author: Matteo Di Carlo
 * Created on December 12, 2015, 2:24 PM
 * 
 * Copyright (C) 2016 Matteo Di Carlo - www.gleeno.com
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LOG_HPP
#define	LOG_HPP
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>



void l(std::string text);
void lf(std::string text, std::string fileName="log", std::string path="logs/");
void lall(std::string text, std::string fileName="log", std::string path="logs/");

//deprecated
void l(std::ostringstream* text);
void lf(std::ostringstream text, std::string fileName="log", std::string path="logs/");
void lall(std::ostringstream text, std::string fileName="log", std::string path="logs/");
#endif	/* LOG_HPP */


