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
    .module('DomAlgo')
    .controller('DomAlgo', DomAlgoBlock);

DomAlgoBlock.$inject = ['$rootScope', '$scope'];

function DomAlgoBlock(rootScope, scope) {
    console.log(" DomAlgo block  ");
    scope.test = {
        addSensor: addTestSensor,
        getAllSensorsData: getTestAllSensorsData
    };

    function addTestSensor() {
        console.log(" Add random test sensor ");
        var instr = {
            action: "create",
            id: "st_" + randTxt(5),
            type: 5,
            data: {val: Math.random() * (1000 - 50) + 50}
        };
        rootScope.ws.send(JSON.stringify(instr));
        console.log("client message: " + instr);
    }

    function randTxt(x) {
        x = 5;
        var s = "";
        while (s.length < x && x > 0) {
            var r = Math.random();
            s += (r < 0.1 ? Math.floor(r * 100) : String.fromCharCode(Math.floor(r * 26) + (r > 0.5 ? 97 : 65)));
        }
        return s;
    }
    function getTestAllSensorsData() {
        console.log(" get all sensors data ");
        var instr = {
            action: "read",
            id: "all",
            type: 5,
            data: {}
        };
        rootScope.ws.send(JSON.stringify(instr));
    }
}