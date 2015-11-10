function [ output ] = read( s,input1,input2,input3 )
%READ Summary of this function goes here
%   Detailed explanation goes here
   fwrite(s,input1,'int');
   fwrite(s,input2,'int');
   fwrite(s,input3,'int');
   switch (input3)
       case 2
           output = fread(s,1,'int')
       case 1
           output = fread(s,1,'int')
       case 0
           output = fread(s,1,'int')
       case 3
           output = fread(s,3,'int')
   end
end

