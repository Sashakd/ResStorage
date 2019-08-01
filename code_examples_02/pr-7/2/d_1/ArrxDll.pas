unit ArrxDll;

interface

type
    TCharPtr = String;
	TIntPtr  = ^Integer;

function phi(n : integer) : integer; cdecl;

function is_simple(n : integer) : integer; cdecl;

procedure init_arr_simple(arr : array of Integer; n : Integer); cdecl;

function insert(str : TCharPtr; sub_str : TCharPtr; start : integer; str_res : TCharPtr; res_len : integer) : integer; cdecl;

implementation

const
    DLLName = 'arrx.dll';

function phi; external DLLName;
function is_simple; external DLLName;
procedure init_arr_simple; external DLLName;
function insert; external DLLName;

end.