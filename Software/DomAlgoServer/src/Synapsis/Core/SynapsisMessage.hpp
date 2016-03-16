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
#include "Synapsis/Core/SynapsisBase.hpp"
#include <Synapsis/Message/en.hpp>

class SynapsisMessage : public SynapsisBase 
{
public:
    SynapsisMessage();
    SynapsisMessage(void **in);
    bool isSynapsisInstruction();
private:
    Json::Value message;
};

#endif	/* SYNAPSISMESSAGE_HPP */

