/* 
 * File:   Syn.cpp
 * Author: Matteo Di Carlo
 * Created on March 17, 2016, 8:59 AM
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

#include "Syn.hpp"
std::vector<Sensor> Syn::sensors;
//SynMsg Syn::msg;

Syn::Syn() {
}


int Syn::setupWsConnection(int port) {
    this->ws = SynWS(port);
    /*
    static struct lws_protocols protocols[] = {
        { "mainProtocol", mainCallback, 0},
        { NULL, NULL, 0}
    };

    SynWS ws = SynWS(protocols, port);
    this->ws = ws.getContext();
     * */
    return UND;
}

int Syn::processMessage(void* in) {
    SynMsg msg = SynMsg(in);
    SynMsg response = SynMsg();
    int opStatus = UND;
    // check for right msg format
    if(!msg.isSynMsg()) 
        return SynMsg::l(ERR_MSG_INVALID);
    else {
        SynMsg::l(RIGHT_MSG_FORMAT);
        if(msg.isCreate()) {// pairing == CREATE
            std::cout << "Action: create" << std::endl;        
            opStatus = Syn::create(msg.getMsg(),&response);            
        }
        else if(msg.isRead())
            std::cout << "Action: read" << std::endl;
        else if(msg.isUpdate())
            std::cout << "Action: update" << std::endl;
        else if(msg.isDelete())
            std::cout << "Action: delete" << std::endl;
    }    
    send(&response);
    return UND;
}
int Syn::create(Json::Value* msg, SynMsg * response) {
    bool exist = false;
    std::string sensorId = msg->get("id", "UTF-8").asString();
    for(auto s : Syn::sensors) {
        if(s.getId().compare(sensorId) == 0) 
            exist=true;
    }
    if(!exist) {
        Syn::sensors.push_back(Sensor());
        response.setMsg("sensor pushed");
        send(response);
        return SNS_PAIRED_SUCC;
    }
    return SNS_EXIST;
}

int Syn::send(SynMsg * msg) {
    int dataW=0;
    //lws_write(wsi,msg->getMsgForWs(),msg->lenght(),msg->dataType);
    return UND;
}

int Syn::run( int delay) {
    //this->ws.run(delay);
    return UND;
}