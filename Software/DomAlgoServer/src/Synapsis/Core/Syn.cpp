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
    return UND;
}

void Syn::run(int delay) {
    runWs(delay);
}
//SYN WS FUNCIOTNS

int SynWS::checkFormat(Json::Value* msg) {
    if (msg->isNull() ||
        msg->empty() ||
        (!msg->isMember("action")) ||
        (!msg->isMember("data")) ||
        (!msg->isMember("id")) ||
        (!msg->isMember("type"))
        ) {
        return ERR;
    }
    return OK;
}

int SynWS::performAction(Json::Value *msg) {
    int status = UND;
    std::string action;
    Json::Value response = Json::Value();
    
    action = msg->get("action", "UTF-8").asString();
    //CRUD
    if (action.compare("create") == 0) //ACTION CREATE
        status = create(msg, &response);
    else if (action.compare("read") == 0)
        status = read(msg, &response);
    else if (action.compare("update") == 0)
       status = update(msg, &response);
    else if (action.compare("delete") == 0)
        status = del(msg, &response);
    else
        status =(ERR_ACTION_NOT_EXIST);    
    Syn::toWS(status, &response);    
    return l(status);
}

bool Syn::isPaired(std::string id) {
    for(auto s : sensors) {
        if(id.compare(s.getId()) == 0) return true;
    }
    return false;
}

int SynWS::create(Json::Value* msg, Json::Value *result) {
    std::cout << "Action: create" << std::endl;
    std::string message;
    if(!Syn::isPaired((*msg)["id"].asString())) {
        Syn::sensors.push_back(SimpleSwitch((*msg)["id"].asString(),(sensType)(*msg)["type"].asInt()));
        message = "Sensor with id: " + (*msg)["id"].asString() + " added";
    }
    else message = "Sensor with id: " + (*msg)["id"].asString() + " already paired";
    (*result)["action"] = "update";
    (*result)["id"] = (*msg)["id"];
    (*result)["type"] = (*msg)["type"];
    (*result)["data"] = message;    
    return OK;
}

int SynWS::read(Json::Value* msg, Json::Value* result) {
    std::string id = (*msg)["id"].asString();
    Json::Value tmp;
    if(id.compare("all") == 0) {
        for( auto s: Syn::sensors) {
            (*result)["data"].append(s.getDataSensor());
        }
    }
    else {
        //TO BE IMPLEMENTED: SENSOR WITH SPEIFIC ID
        (*result)["data"] = "to be implemented";
    }
    (*result)["id"] = id;
    (*result)["action"] = "read";  
    (*result)["type"] = "all";
    return OK;
}

int SynWS::update(Json::Value* msg, Json::Value* result) {
}

int SynWS::del(Json::Value* msg, Json::Value* result) {
}


int Syn::toWS(int status, Json::Value *result) {
    if(status == OK) {
        send(result);
    }
    
    return UND;
}