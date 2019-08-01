unit AXd1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ArrxDLL;

type
  TForm1 = class(TForm)
    Edit1: TEdit;
    Button1: TButton;
    Label1: TLabel;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Button2: TButton;
    Edit5: TEdit;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Edit6: TEdit;
    Label6: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

var
  Arr : array of Integer;
  N, P : Integer;

function StrIsIntNumb(Str : String) : Boolean;       // Испрввить это
var
  I : Integer;
  Fact : Boolean;
begin
  Fact := True;

  for I := 1 to Length(Str) do
  begin
    if ((Str[I] < '0') or (Str[I] > '9')) then
    begin
      result := False;
      exit;
    end;
  end;

  result := Fact;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  N := 0;
  P := 0;
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  I : Integer;
begin
  if (StrIsIntNumb(Edit1.Text) = True) then
  begin
    N := StrToInt(Edit1.Text);

    if (N > 0) then
    begin
      SetLength(Arr, N);
      Edit5.Text := '';
      init_arr_simple(Arr, N);

      for I := 0 to N-1 do
        Edit5.Text := Edit5.Text + IntToStr(Arr[I]) + ' ';
    end
    else
     Edit5.Text := 'ОШИБКА! Неверно задан размер массива';
  end
  else
    Edit5.Text := 'ОШИБКА! Введённое значение не является целым числом';
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  //Str1 : String;
  Str1 : String;
  Str2 : String;
  StrR : String;
  RLen : Integer;
begin
  if (StrIsIntNumb(Edit6.Text) = True) then
  begin
    P := StrToInt(Edit6.Text);

    if (P > 0) then
    begin
      Edit4.Text := '';
      Str1 := Edit2.Text;
      Str2 := Edit3.Text;
      RLen := insert(Str1, Str2, P, StrR, 40);

      if (RLen > 0) then
      begin
        Edit4.Text := StrR;
      end
      else
        Edit4.Text := 'ВНИМАНИЕ! Невозможно выполнить вставку';
    end
    else
      Edit4.Text := 'ОШИБКА! Неверно задана позиция вставки';
  end
  else
    Edit4.Text := 'ОШИБКА! Введённое значение не является целым числом';
end;

end.
