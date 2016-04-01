/* 
 * File:   SynapsisMessage.cpp
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

#include "SynapsisMessage.hpp"

SynapsisMessage::SynapsisMessage() : SynapsisBase()
{

}

SynapsisMessage::SynapsisMessage(void* in)
{
    SynapsisMessage();
    if (settingsRaw["MESSAGE_TYPE"].compare("json") == 0)
        this->message = getJson('s', (std::string*)in);
    else std::cout << "SynapsisMessage: undefined message type: " << 
        settingsRaw["MESSAGE_TYPE"].toStyledString() << std::endl;
}

bool SynapsisMessage::isSynapsisInstruction()
{
    if (this->message.isNull() ||
            this->message.empty() ||
            (!this->message.isMember("action")) ||
            (!this->message.isMember("data")) ||
            (!this->message.isMember("id")) ||
            (!this->message.isMember("type"))
            ) {
        l(L_WRONG_INSTRUCTION_FORMAT);
        return false;
    }
    l(L_RIGHT_INSTRUCTION_FORMAT);
    return true;
}