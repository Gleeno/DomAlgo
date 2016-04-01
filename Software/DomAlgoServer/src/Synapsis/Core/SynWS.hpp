/* 
 * File:   SynWS.hpp
 * Author: Matteo Di Carlo
 * Created on March 17, 2016, 12:15 PM
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

#ifndef SYNWS_HPP
#define	SYNWS_HPP
#include <iostream>
#include <libwebsockets.h>
#include "SynBase.hpp"

class SynWS : public SynBase{
public:
    static struct lws* wsi;
    static char* preBuff;
    SynWS( int port=9002);
    SynWS(struct lws_protocols* protocols, int port);
    lws_context * getContext();
    void runWs(int delay);
    static int mainCallback(struct lws* wsi, lws_callback_reasons reason, void* user, void* in, size_t len);
    
    static int parseMessage(void *rawMessage);
    static int performAction(Json::Value *msg);
    static int checkFormat(Json::Value *msg);

    static int create(Json::Value *msg, Json::Value* result);
    static int read(Json::Value *msg, Json::Value* result);
    static int update(Json::Value *msg, Json::Value* result);
    static int del(Json::Value *msg, Json::Value* result);
    static int send (Json::Value * msg);
private:
    lws_context* context;
};
#endif	/* SYNWS_HPP */

