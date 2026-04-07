params ["_target", "_unit"];

private _group = group _unit;
// 1. Get the list of available 1.5m spaced positions
private _allPositions = [_target] call ctb_halo_fnc_getPositions;

// 2. Filter the group to only include units that are alive
private _units = units _group select { alive _x };

// 3. Loop through units and match them to positions
{
    // Check if we still have available positions in the array
    if (_forEachIndex < count _allPositions) then {
        private _targetPos = _allPositions # _forEachIndex;
        
        // Move the unit to the specific grid position
        // Using setPosASL is recommended for aircraft/high-altitude placement
        _x setPosASL (AGLToASL _targetPos);
        
        // 4. Call your parachute function for this specific unit
        [_x] call ctb_halo_fnc_addParachute; 
        
        diag_log format ["Teleported %1 to ViV position %2", name _x, _forEachIndex];
		_x switchMove "";
    } else {
        // Fallback if the group is larger than the cargo bay grid
        systemChat format ["Warning: No room in ViV grid for %1", name _x];
    };
} forEach _units;

hint "Group loaded into ViV positions with parachutes.";