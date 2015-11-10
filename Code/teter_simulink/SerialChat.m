function [out] = SerialChat( s, opsetP, readP )
switch opsetP
    case 1
        fprintf(s,strcat(num2str(opsetP),',',num2str(readP)));
        out = '';
    case 2
        fprintf(s,strcat(num2str(opsetP),',',num2str(readP)));
        out = '';
    case 9
        fprintf(s,'9,1,1');
        out = zeros(6,1);
        for i=1:6
            str = fgetl(s);
            out(i) = sscanf(str, '%i')/100;
        end
        flushinput(s);
    case 10
        fprintf(s,strcat(num2str(opsetP),',',num2str(readP)));
        out = zeros(2,1);
        for i=1:2
            str = fgetl(s);
            out(i) = sscanf(str, '%i');
        end
        flushinput(s);
    otherwise
        out = '';
end
end

fprintf(s,strcat(num2str(1),',',num2str(u(1)),',',num2str(u(2))))