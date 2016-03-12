/* 
 * File:   SimpleSwitch.hpp
 * Author: Matteo Di Carlo
 * Created on February 23, 2016, 2:57 PM
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

#ifndef SIMPLESWITCH_HPP
#define	SIMPLESWITCH_HPP

#include "Sensor.hpp"

class SimpleSwitch : public Sensor {
public:
    SimpleSwitch(std::string id, sensType type, std::string name, std::string ip);
    Json::Value getDataSensor();
    bool getState();
    int getSwitchState();
    
private:
    bool switchState = false;
};

#endif	/* SIMPLESWITCH_HPP */

