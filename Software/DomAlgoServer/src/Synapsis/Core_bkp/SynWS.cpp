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
SynWS::SynWS(int port = 9002) {
    static struct lws_protocols protocols[] = {
        { "mainProtocol", mainCallback, 0},
        { NULL, NULL, 0}
    };
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
        std::cout << "Error WebSocket init failed: -3"  << std::endl; //lws init failed        
    }
    
}
SynWS::SynWS(struct lws_protocols* protocols, int port) {
    
}

lws_context * SynWS::getContext() {
    return this->context;
}

int Syn::mainCallback(struct lws* wsi, lws_callback_reasons reason, void* user, void* in, size_t len) {
    switch (reason) {
    case LWS_CALLBACK_ESTABLISHED:
        SynMsg::l(CL_CONNECTED);
        break;
        case LWS_CALLBACK_RECEIVE:
            processMessage(in);
            break;
    }
    return 0;
}
