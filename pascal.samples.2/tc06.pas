program tc06;
var i,j,k:integer;
procedure teste1(x:integer; var y:integer);
    begin
        i:=i+1;
        j:=j+1;
        k:=k+1
    end
procedure teste2;
    begin
        i:=i-1;
        j:=j-1;
        k:=k-1
    end
begin
    i:=1;j:=1;k:=1;
    if (i<11)
    then begin
        teste1(1+1*3, i);
    end;
    if not(j<=k)
    then begin
        if (i + j)>5 then teste2
    end
    else begin
        if j>0 then teste1(1+1*3, i)
            else teste2
    end;
end.