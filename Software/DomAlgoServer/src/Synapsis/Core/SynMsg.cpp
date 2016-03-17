/* 
 * File:   SynMsg.cpp
 * Author: Matteo Di Carlo
 * Created on March 17, 2016, 9:05 PM
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

#include "SynMsg.hpp"

SynMsg::SynMsg(void* rawMsg) {
    Json::Reader reader;
    int status = reader.parse((char*)rawMsg,this->msg);
    if (!status) l(ERR_JSON_PARSE);
}
int SynMsg::l(int code) {
        switch (code) {
        case OK: std::cout << "LOG : Success!"<< std::endl; break;
        case CL_CONNECTED: std::cout << "LOG : Client connected!"<< std::endl; break;
        case RIGHT_MSG_FORMAT: std::cout << "LOG : Right instruction format"<< std::endl; break;
        case ERR_BAD_MSG_FORMAT: std::cout << "LOG : Bad instruction format"<< std::endl; break;
        default: std::cout << "LOG: Error: " << code << std::endl;
        }
        return code;
}

bool SynMsg::isSynMsg() {
    if (this->msg.isNull() ||
            this->msg.empty() ||
            (!this->msg.isMember("action")) ||
            (!this->msg.isMember("data")) ||
            (!this->msg.isMember("id")) ||
            (!this->msg.isMember("type"))
            ) {
        return false;
    }
    return true;
}

bool SynMsg::isCreate() {
    if(this->msg["action"].asString().compare("create") == 0)
        return true;
    return false;
}

bool SynMsg::isRead() {
    if(this->msg["action"].asString().compare("read") == 0)
        return true;
    return false;
}

bool SynMsg::isUpdate() {
    if(this->msg["action"].asString().compare("update") == 0)
        return true;
    return false;
}

bool SynMsg::isDelete() {
    if(this->msg["action"].asString().compare("delete") == 0)
        return true;
    return false;
}
