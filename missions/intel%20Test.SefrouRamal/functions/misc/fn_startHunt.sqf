params ["_detected"]; 
private _qrfSpawn = [getPos _detected, 1000, 1650, 1, 0, 0.7, 0, [], [[0,0,0],[0,0,0]]] call BIS_fnc_findSafePos; 
 
private _qrfWP2 = getPos _detected; 

_dir = _qrfSpawn getDir _qrfWP2;
_dirOffset = [20, 45] call BIS_fnc_randomInt;
_dis = _qrfSpawn distance _qrfWP2;
_qrfWP1 = _qrfSpawn getPos [(_dis / 1.5), (_dir + _dirOffset)];
 
if (BB_Debug) then { 
 _mrkrName = "QRF Spawn" + (str _qrfSpawn); 
 _mrkr = createMarker [_mrkrName, _qrfSpawn]; 
 _mrkr setMarkertype "hd_dot"; 
 _mrkr setMarkerText _mrkrName; 
 
 _mrkrName = "QRF WP" + (str _qrfWP1); 
 _mrkr = createMarker [_mrkrName, _qrfWP1]; 
 _mrkr setMarkertype "hd_dot"; 
 _mrkr setMarkerText _mrkrName; 
}; 

private _qrfVeh = createVehicle [selectRandom BB_Veh, _qrfSpawn];
private _qrfTeam = [_qrfSpawn, east, [selectRandom BB_Enemy, selectRandom BB_Enemy, selectRandom BB_Enemy, selectRandom BB_Enemy]] call BIS_fnc_spawnGroup;
_qrfTeam deleteGroupWhenEmpty true;
{_x moveInAny _qrfVeh} forEach units _qrfTeam; 

_qrfTeam setBehaviour "AWARE";
_wp1 = _qrfTeam addWaypoint [_qrfWP1, 50];
_wp1 setWaypointType "GETOUT";

//_wp2 = [_qrfTeam, 500] spawn lambs_wp_fnc_taskHunt;
_wp2 = _qrfTeam addWaypoint [_qrfWP2, 50];
_wp2 setWaypointType "SAD";