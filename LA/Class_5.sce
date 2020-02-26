clear;close;
clc;
n=3
disp("Enter matrix A")
for i=1:n
    for j=1:n
        A(i,j)=input("Enter")
    end
end
disp('matrix is ')
disp(A,'A is ');
[m,n]=size(A);
disp(m,'m is ');
disp(n,'n is ');
[v,pivot]=rref(A);
disp(rref(A));
disp(v);
r=length(pivot);
disp(r,'rank is ')
cs=A(:,pivot);
disp(cs,'Column Space is ');
ns=kernel(A);
disp(ns,'Null Space is ');
rs=v(1:r,:)';
disp(rs,'Row Space is ')
lns=kernel(A');
disp(lns,'Left Null Space is ');
