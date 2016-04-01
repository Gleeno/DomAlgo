/* 
 * File:   SynapsisBase.cpp
 * Author: Matteo Di Carlo
 * Created on December 13, 2015, 4:16 PM
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

#include "SynapsisBase.hpp"

Json::Value SynapsisBase::settingsRaw;
SynapsisBase::SynapsisBase() {
    std::string configFile = "configs/default.json";
    this->settingsRaw = this->getJson( 'f', &configFile );
}

SynapsisBase::SynapsisBase(const SynapsisBase& orig) {
}

SynapsisBase::~SynapsisBase() {
}

std::string SynapsisBase::getContFromFile(std::string source) {
  std::ifstream in(source, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  throw(errno);
}

Json::Value SynapsisBase::getSettingsRaw() {
    return (this->settingsRaw);
}
Json::Value SynapsisBase::getJson(char type, std::string* sourceOrPath){
    Json::Value v;
    Json::Reader r;
    if(type == 'f') {
        std::ifstream in(*sourceOrPath, std::ios::in | std::ios::binary);
        if (in) {
            std::string contents;
            in.seekg(0, std::ios::end);
            contents.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&contents[0], contents.size());
            in.close();
            if(!r.parse(contents,v,false))
                throw(errno);
        }
        else std::cout << "GetJson: file error." << std::endl;
    }
    else {
         if(!r.parse(*sourceOrPath,v,false)) {
             lall("Instruction in bad format ( no json ). Exit");
             throw(errno);
         }
    }
    return v;
}