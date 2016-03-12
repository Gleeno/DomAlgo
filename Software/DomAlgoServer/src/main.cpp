/* 
 * File:   main.cpp
 * Author: Matteo Di Carlo
 * Created on December 10, 2015, 4:26 PM
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

#include "Synapsis/Core/Synapsis.hpp"
#include "Synapsis/Log/Log.hpp"

int main(int argc, char** argv) {
    Synapsis *wsI = new Synapsis();
    wsI->connect("127.0.0.1",9002);
    while (1) {
      lws_service(wsI->context, 50);
    }
    return 0;
}

