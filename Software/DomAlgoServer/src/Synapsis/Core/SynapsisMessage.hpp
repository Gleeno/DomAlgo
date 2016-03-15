/* 
 * File:   SynapsisMessage.hpp
 * Author: Matteo Di Carlo
 * Created on March 13, 2016, 5:02 PM
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

#ifndef SYNAPSISMESSAGE_HPP
#define	SYNAPSISMESSAGE_HPP
#include <json/json.h>
#include <string>
#include <fstream>
#include <cerrno>
#include "Synapsis/Log/Log.hpp"
#include <Synapsis/Message/en.hpp>
class SynapsisMessage {
public:
    SynapsisMessage(void **message);
    SynapsisMessage(const SynapsisMessage& orig);
    virtual ~SynapsisMessage();
    bool isSynapsisInstruction();
    Json::Value getJson(char type, std::string* sourceOrPath);
private:
    std::string message;
};

#endif	/* SYNAPSISMESSAGE_HPP */

