/* 
 * Copyright (C) 2016 Matteo Di Carlo
 *
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

var DomAlgo = angular
    .module("DomAlgo",
        [
            "ngRoute",
            "syn"
        ])
    .config(configure)
    .run(runBlock);

configure.$inject = ['$routeProvider', '$locationProvider'];
runBlock.$inject = ['$http', '$rootScope', 'synIO'];

function configure(routeProvider, locationProvider) {
    routeProvider
        .when("/", {
            templateUrl: "pages/realTime.html",
            controller: "realTime"
        })
        .when("/realTime", {
            templateUrl: "pages/realTime.html",
            controller: "realTime"
        })
        .otherwise({redirectTo: ""});
}

function runBlock(http, rootScope, synIO) {
    rootScope.sensors = [];
    rootScope.ws = null;
    activate();

    function activate() {
        console.log(" Settings load... ");
        rootScope.ws = synIO.open("ws", "ws://127.0.0.1:9002");
        rootScope.ws.onmessage = onMessage;

    }
    function onMessage(msg) {
        console.log("msg: " + msg.data);
        processMessage(msg.data);
    }
    
    function processMessage(rawMessage) {
        var msg = JSON.parse(rawMessage);
        if(checkFormat(msg) === true) {
        switch (msg.action) {
            case 'update' :
                update(msg);
                break;
            default:
                    console.log("action not implemented: " + msg.action);
                    break;
        }
    }
    else console.log("Invalid message format. No action to perform");
    }
    
    function checkFormat(msg) {
        //TO BE IMPLEMENTED
        console.log("CheckFormat: to be implemented: always true");
        return true;
    }
        
    function update(msg) {
        realTime.realTimeUpdate(msg);
    }
    
    function isMember(id) {
        for(var i = 0; i< rootScope.sensors.length; i++) {
            if (id === rootScope.sensors.id) return i;
        }
        return -1;
    }
}
//______________________________________________________________________________