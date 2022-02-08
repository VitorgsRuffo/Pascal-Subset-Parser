program tc10;
var a,b,c,d,e:integer;

function f01(p01:integer):integer;
    function f02(p02:integer):integer;
        function f03(p03:integer):integer;
            function f04(p04:integer):integer;
                function f05(p05:integer):integer;
                    function f06(p06:integer):integer;
                        function f07(p07:integer):integer;
                            function f08(p08:integer):integer;
                                function f09(p09:integer):integer;
                                    function f10(p10:integer):integer;
                                    begin
                                        f10:=1
                                    end
                                begin
                                    f09:=f10(10)
                                end
                            begin
                                f08:=f09(09)
                            end
                        begin
                            f07:=f08(08)
                        end
                    begin
                        f06:=f07(07)
                    end
                begin
                    f05:=f06(06)
                end
            begin
                f04:=f05(05)
            end
        begin
            f03:=f04(04)
        end
    begin
        f02:=f03(03)
    end
begin
    f01:=f02(02)
end
begin
    write (f01(0))
end.
