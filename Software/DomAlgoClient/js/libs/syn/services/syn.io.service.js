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
    .module("syn")
    .factory("synIO", synIOBlock);

synIOBlock.$inject = ['$http'];

function synIOBlock(http) {
    return {
        open: openBlock
    };

    function openBlock(type, address) {
        if (type == 'ws') {
            console.log(" Type ws... ");
            return openWs(address);
        }
        else
            console.log(" Entity to open not defined. ");
    }

    function openWs(address) {
        var ws = new WebSocket(address, "mainProtocol");
        ws.onopen = wsOpen;
        ws.onclose = wsClose;
        return ws;
    }

    function wsOpen() {
        console.log(" Ws opened ");
    }
    function wsClose() {
        console.log(" Ws closed ");
    }
}