/* 
 * File:   Synapsis.cpp
 * Author: Matteo Di Carlo
 * Created on December 12, 2015, 2:01 PM
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
    
#include "Synapsis.hpp"

Synapsis::Synapsis(){}

int Synapsis::connect(std::string address, int port) {
    this->wsAddress = address;
    this->wsPort = port;
    l("Server connection: address: " + address + ". Port: " + std::to_string(port));

    /* libwebsocket start */
    struct lws_context_creation_info info;
    static struct lws_protocols protocols[] = {
        { "instruction_protocol", callback_instruction, 0},
        { NULL, NULL, 0}
    };
    memset(&info, 0, sizeof (info));
    info.port = this->wsPort;
    info.iface = NULL;
    info.protocols = protocols;
    info.extensions = lws_get_internal_extensions();
    info.ssl_cert_filepath = NULL;
    info.ssl_private_key_filepath = NULL;
    info.gid = -1;
    info.uid = -1;
    info.options = 0;
    this->context = lws_create_context(&info);
    if (this->context == NULL) {
        fprintf(stderr, "libwebsocket init failed\n");
        //return -1;
    }
    return 0;
}

//callbacks

int Synapsis::callback_instruction(
        struct lws *wsi,
        enum lws_callback_reasons reason, void *user,
        void *in, size_t len) {
    int dataW;
    lws_write_protocol writeProtocol;
    std::vector<unsigned char> buffer;
    std::string name = "name";
    std::string ip = "2344";
    
    switch (reason) {
    case LWS_CALLBACK_ESTABLISHED:
        l((std::string)L_CONNECTED);
        break;
    case LWS_CALLBACK_RECEIVE:
        writeProtocol = parseInstruction(in, &buffer, &name, &ip);
        if (writeProtocol == LWS_WRITE_TEXT || writeProtocol == LWS_WRITE_BINARY) {
            dataW = lws_write(wsi, buffer.data(),buffer.size(), writeProtocol);
            //l(std::to_string(dataW) + " DATA SENT: " + std::to_string(buffer.data));
        }
        else l((std::string)L_INVALID_INSTRUCTION);
    break;
    }
    return 0;
}

lws_write_protocol Synapsis::parseInstruction(void *in,
        std::vector<unsigned char> *buffer,
        std::string* clientName, std::string* clientIp) {
    SynapsisMessage message = SynapsisMessage(in);
    if (message.isSynapsisInstruction()){
        int actionStatus;        
        actionStatus = performAction();
            if( actionStatus == 1)
                return LWS_WRITE_TEXT;        
    }
    return (lws_write_protocol)settingsRaw["N_BAD_INSTRUCTION"].isInt();
}

int Synapsis::performAction() {
    
}

bool Synapsis::isPaired(std::string sensorId)
{
}

int Synapsis::notify(std::string message, Json::Value result) {
    makeInstruction(settingsRaw["A_NOTIFY"].asString(),&message,result);
    return settingsRaw["N_SUCCESS"].asInt();
}

bool Synapsis::pairing(Json::Value instruction, Json::Value result,
        std::string* clientName, std::string* clientIp) {
    std::string id= instruction["id"].asString();
    sensType type = (sensType) instruction["type"].asInt();
    if (!isPaired(id)) {
                if (type == sensType::TERMINAL) {
                    //sensors.push_back(new Sensor(id,type,*clientName, *clientIp));
                    notify(L_SENSOR_PAIRED_SUCCESS,&result);
                }
                else if (type == sensType::SIMPLE_SWITCH) {
                    //sensors.push_back(new SimpleSwitch(id,type,*clientName, *clientIp));
                    notify(L_SENSOR_PAIRED_SUCCESS,&result);
                }
                else
                    notify(L_SENSOR_TYPE_UNKNOWN,&result);
            }    
    else
        notify(L_SENSOR_JUST_PAIRED,&result);
    return true;
}


bool Synapsis::getDataSensor(Json::Value instruction, Json::Value result) {
    std::string action = instruction["action"].asString();
    std::string id= instruction["id"].asString();
    sensType type = (sensType)instruction["type"].asInt();
    std::string data;
    Json::Value tmp;
    
    return true;
}

int Synapsis::makeInstruction(std::string action, std::string* data, Json::Value result, sensType type, std::string id) {
    result["action"] = action;
    result["id"] = id;
    result["type"] = std::to_string((int)type);
    result["data"] = data;
    return settingsRaw["N_SUCCESS"].asInt();
}