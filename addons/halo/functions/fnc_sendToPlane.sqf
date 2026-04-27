params ["_plane", "_unit"];

private _group = group _unit;
private _allPositions = [_plane] call ctb_halo_fnc_getPositions;

private _units = units _group select { alive _x };
private _dir = direction _plane;

{
    // Check if we still have available positions in the array
    if (_forEachIndex < count _allPositions) then {
        private _planePos = _allPositions # _forEachIndex;
        
        _x attachTo [_plane, _planePos]; 
        _x setDir _dir;

        [_x, _plane] call ctb_halo_fnc_addParachute; 
        detach _x; 

        diag_log format ["Teleported %1 to ViV position %2", name _x, _forEachIndex];
		_x switchMove "";
    } else {
        diag_log format ["Warning: No room in ViV grid for %1", name _x];
    };
} forEach _units;