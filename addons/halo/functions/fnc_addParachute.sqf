params ["_unit", "_plane"];

private _backpackType = backpack _unit;
if (_backpackType == "") exitWith { 
    _unit addBackpack "B_Parachute"; 
};

private _backpackItems = backpackItems _unit;


removeBackpack _unit;
_unit addBackpack "B_Parachute";
[_unit, _plane] spawn {
    params ["_unit", "_plane"];
    waitUntil { !(isTouchingGround _unit) };
    _unit allowDamage false;

    private _velocityVector = _plane vectorModelToWorld [0, -35, 0];
    _unit setVelocity _velocityVector;
};

[_unit, _backpackType, _backpackItems] spawn {
    params ["_unit", "_type", "_items"];
    
    waitUntil { 
        isNull objectParent _unit && 
        { (((isTouchingGround _unit) && (getPosATL _unit # 2) < 2)) or ((getPosASL _unit # 2) <2) } 
    };
    
    // Small delay to ensure landing animation finishes
    sleep 2;
    _unit allowDamage true;
    
    // 5. Restore the original backpack
    removeBackpack _unit;
    _unit addBackpack _type;
    
    // 6. Re-add the items
    {
        _unit addItemToBackpack _x;
    } forEach _items;
    
};