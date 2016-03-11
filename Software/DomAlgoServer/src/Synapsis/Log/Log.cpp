/* 
 * File:   Log.cpp
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

#include "Log.hpp"
void l(std::string text) {
    std::cout << "** " << text <<" **" << std::endl;
}

void lf(std::string text, std::string fileName, std::string path) {
    time_t t= time(0);
    struct tm * now = localtime( & t );
    std::ofstream f;
    //l(path+fileName);
    f.open(path+fileName, std::fstream::app);
    
    //if(f.is_open()) l("file opened");
    //else l("Log file not opened");
    f << "Log: [ " 
          << now->tm_year + 1900 
          << "-"
          << now->tm_mon + 1 
          << "-"
          << now->tm_mday 
          << " at " 
          << now->tm_hour  
          << ":"
          << now->tm_min 
          << ":"
          << now->tm_sec 
          << " ] " 
          << text << std::endl;
    f.close();
}
void lall(std::string text, std::string fileName, std::string path) {
    l(text);
    lf(text, fileName, path);
}

