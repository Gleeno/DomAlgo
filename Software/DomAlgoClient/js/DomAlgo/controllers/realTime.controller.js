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
angular
    .module("DomAlgo")
    .controller("realTime", realTimeBlock);

realTimeBlock.$inject= ["$rootScope"]

function realTimeBlock(rootScope) {
    return {
        realTimeUpdate: realTimeUpdateBlock
    }
    
    function realTImeUpdateBlock(msg) {
        console.log("perform update");
        if(msg.id === 'all'){
            var n = Object.keys(msg.data).length;
            console.log("update " + n + " sensors");
            for(var i=0; i<n;i++) {
                var index = isMember(msg.data[i].id);
                if(index === -1) { // sensor not registered
                    console.log("sensor not registered. pairing ( id: " + msg.data[i].id + " )");
                    s = new Sensor();
                    s.id = msg.data[i].id;
                    s.type = msg.data[i].type;
                    rootScope.sensors.push(s);
                }
                else console.log("sensor with id " + msg.data[i].id + "registered yet.");
            }
            console.log(rootScope.sensors.length);
        }
    }
}  


