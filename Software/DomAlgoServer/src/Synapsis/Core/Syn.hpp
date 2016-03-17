/* 
 * File:   Syn.hpp
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

#ifndef SYN_HPP
#define	SYN_HPP
#include "SynBase.hpp"

class Syn {
public:
    Syn();
    int setupWsConnection(int port=9002);
    lws_context * getWS();
    static int mainCallback(struct lws *wsi,enum lws_callback_reasons reason, void *user,
        void *in, size_t len);
private:
    lws_context *ws;
};

#endif	/* SYN_HPP */

