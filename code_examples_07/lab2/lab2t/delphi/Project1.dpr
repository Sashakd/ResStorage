program Project1;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System, SysUtils, Windows;
const
  MAX = 320;
  
type
  Privacy = record
    dd: Integer;
    mm: Integer;
    yy: Integer;
  end;

  Work = record
    org: Real;
    pos: Real;
  end;

  Group = record
    Name: string;
    Surname: string;
    Tel: string;
    Address: string;
    case Status: Integer of
      1: (P: Privacy);
      2: (W: Work);
  end;

  Key = record
    Surname: string;
    Num: Integer;
  end;

  TData = array[0..MAX - 1] of Group;
  TKeys = array[0..MAX - 1] of Key;
  TIntAr = array of Integer;

procedure CreateKeys(var Keys: TKeys; var Data: TData);
var
  K: Key;
  I: Integer;
begin
  for I := 0 to Length(Data) - 1 do
  begin
    K.Surname := Data[I].Surname;
    K.Num := I;
    Keys[I] := K;
  end;
end;

procedure ReadList(var Keys: TKeys; var Data: TData);
var
  F: TextFile;
  Count: Integer;
  I: Integer;
  Str: string;
begin
  AssignFile(F, '40.txt');
  if FileExists('40.txt') then
  begin
    Reset(F);
    ReadLn(F, Count);

    for I := 0 to 3 do
    begin
        ReadLn(F, Str);
      ReadLn(F, Str);
      Data[I].Name := Str;
      ReadLn(F, Str);
      Data[I].Surname := Str;
      ReadLn(F, Str);
      Data[I].Tel := Str;
      ReadLn(F, Str);
      Data[I].Address := Str;
      ReadLn(F, Str);
      Data[I].Status := StrToInt(Str);
      case Data[I].Status of
      1:begin
          ReadLn(F, Str);
          Data[I].P.dd := StrToInt(Str);
          ReadLn(F, Str);
          Data[I].P.mm := StrToInt(Str);
          ReadLn(F, Str);
          Data[I].P.yy := StrToInt(Str);
        end;
      2:begin
          ReadLn(F, Str);
          Data[I].W.org := StrToFloat(Str);
          ReadLn(F, Str);
          Data[I].W.pos := StrToFloat(Str);
        end;
      end;
  end;
    CloseFile(F);
    CreateKeys(Keys, Data);
end;

end;
procedure SwKeys(var A: Key; var B: Key);
var
  C: Key;
begin
    C := A;
    A := B;
    B := C;
end;

procedure SwGr(var A: Group; var B: Group);
var
  C: Group;
begin
    C := A;
    A := B;
    B := C;
end;

procedure KeySortSel(var A: TKeys);
var
  I, J: Integer;
begin
  I := 1;    
  while I < Length(A) do
  begin
    J := I;
    while (J > 0) and (A[j - 1].Surname > A[j].Surname) do
    begin
      SwKeys(A[J - 1], A[j]);
      Dec(J);
    end;
    Inc(I);
  end;
end;

procedure GrSortSel(var A: TData);
var
  I, J: Integer;
begin
  I := 1;
  while I < Length(A) do
  begin
    J := I;
    while (J > 0) and (A[j - 1].Surname > A[j].Surname) do
    begin
      SwGr(A[J - 1], A[j]);
      Dec(J);
    end;
    Inc(I);
  end;
end;

procedure KeySortIns(var A: TKeys);
var
  I, J, K: Integer;
begin
  I := 0;
  while I < Length(A) do
  begin
    K := I;
    J := I + 1;
    while J < Length(A) do
    begin
      if A[j].Surname < A[k].Surname then
        K := J;
      Inc(J);
    end;
    SwKeys(A[I], A[K]);
    Inc(I);
  end;
end;

procedure GrSortIns(var A: TData);
var
  I, J, K: Integer;
begin
  I := 0;
  while I < Length(A) do
  begin
    K := I;
    J := I + 1;
    while J < Length(A) do
    begin
      if A[j].Surname < A[k].Surname then
        K := J;
      Inc(J);
    end;
    SwGr(A[I], A[K]);
    Inc(I);
  end;
end;

function birthday(var i: Integer; var Data: TData; var Keys: TKeys): Integer;
var
    Sum: Integer;
begin
    if (Data[Keys[i].Num].status = 2)  then
        Result := 10;
    Sum := 30*Data[Keys[i].Num].p.mm + Data[Keys[i].Num].p.dd;

    if ((Sum-88>0) and (Sum-88<8)) then
        Result := 1
    else
        Result := 10;
end;

procedure FindSel(var Keys: TKeys; var Data: TData; var Bd: TIntAr);
var
  I, K: Integer;
begin
    SetLength(Bd, 0);
    for K := 0 to Length(Keys) - 1 do
        if (birthday(i, Data, Keys)<8) then
        begin
          SetLength(Bd, Length(Bd) + 1);
          Bd[Length(Bd) - 1] := K;
        end;
end;

var
  Data: TData;
  Keys: TKeys;
  Te, Tb, Res: Int64;
begin
  ReadList(Keys, Data);
  Tb := GetTickCount;
  GrSortSel(Data);
  Te := GetTickCount;
  Res := Te - Tb;
  WriteLn(Tb);
  WriteLn(Te);
  WriteLn(res);
  ReadLn;

end.
