/* 
 * File:   Sensor.cpp
 * Author: Matteo Di Carlo
 * Created on January 28, 2016, 4:03 PM
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

#include "Sensor.hpp"

Sensor::Sensor(std::string id, sensType type, std::string name, std::string ip) {
    this->id = id;
    this->type = type;
    this->name = name;
    this->ip = ip;
}

Sensor::Sensor() {

}

Sensor::~Sensor() {
}

sensType Sensor::getType() {
    return this->type;
}

std::string Sensor::getId() {
    return this->id;
}

std::string Sensor::getIp() {
    return this->ip;
}

std::string Sensor::getName() {
    return this->name;
}

int Sensor::getWifiSignal() {
    return this->wifiSignal;
}

//get general values

Json::Value Sensor::getDataSensor() {
    Json::Value data;
    // get all sensor datas
    data["ip"] = getIp();
    data["name"] = getName();
    data["id"] = getId();
    data["type"] = std::to_string((int) getType());
    return data;
}

