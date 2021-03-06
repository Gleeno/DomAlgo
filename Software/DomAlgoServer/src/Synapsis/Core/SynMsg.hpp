/* 
 * File:   SynMsg.hpp
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

#ifndef SYNMSG_HPP
#define	SYNMSG_HPP
#include <iostream>
#include "Synapsis/Common/Status.hpp"
#include <json/json.h>

class SynMsg {
public:
    SynMsg();
    SynMsg(void *rawMsg);
    static int l(int code);
    bool isSynMsg();
    bool isCreate();
    bool isRead();
    bool isUpdate();
    bool isDelete();
    std::string getId();
    Json::Value * getMsg();
    int addMsg(void * rawMsg);
    unsigned char * getMsgForWs();private:

};

#endif	/* SYNMSG_HPP */

