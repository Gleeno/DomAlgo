/* 
 * File:   Sensor.hpp
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

#ifndef SENSOR_HPP
#define	SENSOR_HPP
#include <iostream>
#include <json/value.h>
enum sensType {
  SIMPLE_KNOB = 0,
  SIMPLE_SWITCH,
  ADV_KNOB_TUNER,
  ADV_SWITCH,
  SIMPLE_CAMERA, //INPUT
  TERMINAL,  //OUTPUT
  GENERIC
};
class Sensor {
public:
    Sensor();
    Sensor(std::string id, sensType type, std::string name = "no-name", std::string ip = "no-ip");
    virtual ~Sensor();
    virtual Json::Value getDataSensor();
    sensType getType();
    std::string getId();
    std::string getIp();
    std::string getName();
    int getWifiSignal();
    
private:
    std::string id;
    sensType type;
    std::string name;
    std::string ip;
    int wifiSignal; // wifi signal strong
};

#endif	/* SENSOR_HPP */


