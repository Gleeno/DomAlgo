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
            "daRealTime",
        ])
    .config(configure)
    .run(runBlock);

configure.$inject = [ '$routeProvider', '$locationProvider' ] ;
runBlock.$inject = [ '$http', '$rootScope' ];

function configure( routeProvider, locationProvider) {
    routeProvider
        .when("/", {
            templateUrl: "pages/realTime.html",
            controller : "realTime"        
        })
        .when ("/realTime.html", {
            templateUrl: "pages/realTime.html",
            controller : "realTimeCtrl"
        })
        .otherwise ({ redirectTo:"" });
    }

    function runBlock(http, rootScope) {
        rootScope.sensors = [];
        activate();
        
        function activate() {
            //realTime();
        }
    }
//______________________________________________________________________________

var Sensor = function () {
    this.id;
    this.type;
    }