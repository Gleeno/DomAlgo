/* 
 * File:   SynBase.hpp
 * Author: Matteo Di Carlo
 * Created on March 17, 2016, 9:01 AM
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

#ifndef SYNBASE_HPP
#define	SYNBASE_HPP
#include "Synapsis/Common/Status.hpp"
#include "SynFile.hpp"
#include "SynWS.hpp"
#include "SynDB.hpp"

class SynBase {
public:
    SynBase();
private:
    SynWS ws;
};

#endif	/* SYNBASE_HPP */

