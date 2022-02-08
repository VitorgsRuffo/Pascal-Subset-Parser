program tc07;
var i,j,k:integer;
procedure teste1;
    procedure teste1_1;
        begin
            i:=i*1;
            j:=j*1;
            k:=k*1
        end
    begin
        i:=1+1;
        teste1_1;
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
        teste1;
    end;
    if not(j<=k)
    then begin
        if (i + j)>5 then teste2
        end
        else begin
            if j>0 then teste1
                else teste2
    end;
end.