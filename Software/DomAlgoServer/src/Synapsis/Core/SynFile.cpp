/* 
 * File:   SynFile.cpp
 * Author: Matteo Di Carlo
 * Created on March 17, 2016, 9:59 AM
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

#include "SynFile.hpp"

status_t SynFile::getTextFromFile(std::string* source, std::string* result) {
    std::ifstream in(*source, std::ios::in | std::ios::binary);
    if (in) {
        in.seekg(0, std::ios::end);
        result->resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&result->at(0)  , result->size());
        in.close();
        return OK;
    }
    else 
        return ERR_RW_FILE;
    return UND;
}



