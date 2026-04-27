params ["_vehicle"];
 
private _cfgPath = configFile >> "CfgVehicles" >> typeOf _vehicle >> "VehicleTransport" >> "Carrier" >> "cargoBayDimensions"; 
private _rawDims = getArray _cfgPath; 
 
if (count _rawDims == 0) exitWith { systemChat "Vehicle incompatible, try cargo variant."; [] }; 
 
//Get Model Space positions 
private _p1 = if (_rawDims # 0 isEqualType "") then { _vehicle selectionPosition (_rawDims # 0) } else { _rawDims # 0 }; 
private _p2 = if (_rawDims # 1 isEqualType "") then { _vehicle selectionPosition (_rawDims # 1) } else { _rawDims # 1 }; 
 
//Define the absolute limits and the 0.5m buffer 
private _buffer = 0.5; 
private _absMinX = (_p1 # 0) min (_p2 # 0); 
private _absMaxX = (_p1 # 0) max (_p2 # 0); 
private _absMinY = (_p1 # 1) min (_p2 # 1); 
private _absMaxY = (_p1 # 1) max (_p2 # 1); 
private _floorZ  = (_p1 # 2) min (_p2 # 2); 
 
//Calculate usable span after buffer 
private _usableWidth  = (_absMaxX - _absMinX) - (2 * _buffer); 
private _usableLength = (_absMaxY - _absMinY) - (2 * _buffer); 
 
private _step = 1.8; 
 
//Calculate how many points fit and the "best fit" offset 
private _countX = floor (_usableWidth / _step); 
private _countY = floor (_usableLength / _step); 
 
private _offsetX = (_usableWidth - (_countX * _step)) / 2; 
private _offsetY = (_usableLength - (_countY * _step)) / 2; 
 
private _startX = _absMinX + _buffer + _offsetX; 
private _startY = _absMinY + _buffer + _offsetY; 
 
private _allPositions = []; 
 
for "_ix" from 0 to _countX do { 
    for "_iy" from 0 to _countY do { 
         
        private _posX = _startX + (_ix * _step); 
        private _posY = _startY + (_iy * _step); 
        private _pointModel = [_posX, _posY, _floorZ]; 
         
        //private _pointWorld = _vehicle modelToWorld _pointModel; 
        //private _pointASL = AGLToASL _pointWorld; 
         
        _allPositions pushBack _pointModel; 
 
        // Debug Visualisation 
        /*private _sp = createVehicleLocal ["Sign_Sphere10cm_F", [0,0,0], [], 0, "CAN_COLLIDE"]; 
        _sp attachTo [_vehicle, _pointModel]; */
    }; 
}; 
 
_allPositions;