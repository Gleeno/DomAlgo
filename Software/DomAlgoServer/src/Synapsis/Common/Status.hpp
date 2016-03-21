/* 
 * File:   Error.hpp
 * Author: Matteo Di Carlo
 * Created on March 17, 2016, 10:17 AM
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

#ifndef ERROR_HPP
#define	ERROR_HPP

#define L_OK "Success!",
#define L_UND "Undefined",
#define L_ERR_GEN  "Generic error",
#define L_ERR_RW_FILE "Read/write file error" ,
#define L_LWS_INIT_FAILED  "WebSocket init failed"

enum status_t {
    SNS_PAIRED_SUCC = 4,
    SNS_EXIST = 4,
    RIGHT_MSG_FORMAT = 3,
    CL_CONNECTED = 2,
    OK = 1,
    UND = 0,
    ERR_GEN = -1,
    ERR_RW_FILE = -2,
    ERR_LWS_INIT = -3,
    ERR_JSON_PARSE = -4,
    ERR_MSG_INVALID = -5,
    ERR_BAD_MSG_FORMAT = -6
    
};

#endif	/* ERROR_HPP */