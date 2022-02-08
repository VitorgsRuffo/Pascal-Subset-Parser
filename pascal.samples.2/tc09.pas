program tc09;
var N,c:integer;
    function Fat (N:integer; var c:integer): integer;
    begin
        c:=c+1;
        if N > 0
        then Fat:= Fat (N-1,c) * N
        else Fat:= 1
    end
begin
    N:=3; c:=0;
    write (Fat(N,c));
end.