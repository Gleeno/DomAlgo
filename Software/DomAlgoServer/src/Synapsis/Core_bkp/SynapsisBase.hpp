/* 
 * File:   SynapsisBase.hpp
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

#ifndef SYNAPSISBASE_HPP
#define	SYNAPSISBASE_HPP
#include <json/json.h>
#include <string>
#include <fstream>
#include <cerrno>
#include "Synapsis/Log/Log.hpp"
#include <Synapsis/Message/en.hpp>
class SynapsisBase {
public:
    SynapsisBase();
    SynapsisBase(const SynapsisBase& orig);
    virtual ~SynapsisBase();
    std::string getContFromFile(std::string source);
    static Json::Value getJson(char type,std::string* sourceOrPath);
    Json::Value getSettingsRaw();
protected:
    static Json::Value settingsRaw;
};

#endif	/* SYNAPSISBASE_HPP */
