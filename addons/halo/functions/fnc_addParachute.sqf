params ["_unit"];

// 1. Check if unit has a backpack
private _backpackType = backpack _unit;
if (_backpackType == "") exitWith { 
    _unit addBackpack "B_Parachute"; 
    diag_log "No backpack to save, added parachute.";
};

// 2. Store all items and their specific containers/states
// getBackpackCargo is okay, but combinations of items/magazines/weapons are best handled via:
private _backpackItems = backpackItems _unit;

// 3. Remove backpack and add parachute
removeBackpack _unit;
_unit addBackpack "B_Parachute";

// 4. Wait until the unit is on the ground
// Using a spawn to prevent halting the main script execution
[_unit, _backpackType, _backpackItems] spawn {
    params ["_unit", "_type", "_items"];
    
    // Wait until unit is lower than 1m or speed is 0 (landed)
    waitUntil { 
        isNull objectParent _unit && 
        { (isTouchingGround _unit) && ((getPos _unit # 2) < 5) } 
    };
    
    // Small delay to ensure landing animation finishes
    sleep 2;
    
    // 5. Restore the original backpack
    removeBackpack _unit;
    _unit addBackpack _type;
    
    // 6. Re-add the items
    {
        _unit addItemToBackpack _x;
    } forEach _items;
    
    hint "Backpack restored with items.";
};