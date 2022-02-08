cd src/
make clean
make
./pascal < ../pascal.samples.2/tc01.pas > ../pascal.samples.2/vitor01.txt
./pascal < ../pascal.samples.2/tc02.pas > ../pascal.samples.2/vitor02.txt
./pascal < ../pascal.samples.2/tc03.pas > ../pascal.samples.2/vitor03.txt
./pascal < ../pascal.samples.2/tc04.pas > ../pascal.samples.2/vitor04.txt
./pascal < ../pascal.samples.2/tc05.pas > ../pascal.samples.2/vitor05.txt
./pascal < ../pascal.samples.2/tc06.pas > ../pascal.samples.2/vitor06.txt
./pascal < ../pascal.samples.2/tc07.pas > ../pascal.samples.2/vitor07.txt
./pascal < ../pascal.samples.2/tc08.pas > ../pascal.samples.2/vitor08.txt
./pascal < ../pascal.samples.2/tc09.pas > ../pascal.samples.2/vitor09.txt
./pascal < ../pascal.samples.2/tc10.pas > ../pascal.samples.2/vitor10.txt
diff ../pascal.samples.2/saida_01.txt ../pascal.samples.2/vitor01.txt
diff ../pascal.samples.2/saida_02.txt ../pascal.samples.2/vitor02.txt
diff ../pascal.samples.2/saida_03.txt ../pascal.samples.2/vitor03.txt
diff ../pascal.samples.2/saida_04.txt ../pascal.samples.2/vitor04.txt
diff ../pascal.samples.2/saida_05.txt ../pascal.samples.2/vitor05.txt
diff ../pascal.samples.2/saida_06.txt ../pascal.samples.2/vitor06.txt
diff ../pascal.samples.2/saida_07.txt ../pascal.samples.2/vitor07.txt
diff ../pascal.samples.2/saida_08.txt ../pascal.samples.2/vitor08.txt
diff ../pascal.samples.2/saida_09.txt ../pascal.samples.2/vitor09.txt