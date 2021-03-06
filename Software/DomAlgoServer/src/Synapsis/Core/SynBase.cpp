/* 
 * File:   SynBase.cpp
 * Author: Matteo Di Carlo
 * Created on March 17, 2016, 9:01 AM
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

#include "SynBase.hpp"

int SynBase::l(int code) {
        switch (code) {
        case OK: std::cout << "LOG : Success!"<< std::endl; break;
        case CL_CONNECTED: std::cout << "LOG : Client connected!"<< std::endl; break;
        case RIGHT_MSG_FORMAT: std::cout << "LOG : Right instruction format"<< std::endl; break;
        case ERR_BAD_MSG_FORMAT: std::cout << "LOG : Bad instruction format"<< std::endl; break;
        case ERR_ACTION_NOT_EXIST: std::cout << "LOG : Action not exist"<< std::endl; break;
        default: std::cout << "LOG: Error : " << code << std::endl;
        }
        return code;
}