/* 
 * File:   SynWS.cpp
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

#include "SynWS.hpp"

SynWS::SynWS(struct lws_protocols* protocols, int port) {
    struct lws_context_creation_info info;   
    memset(&info, 0, sizeof (info));
    info.port = port;
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
    }
}

lws_context * SynWS::getContext() {
    return this->context;
}