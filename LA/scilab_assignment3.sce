disp("enter the matrix A")
A = [input("value"), input("value"); input("value"), input("value"); input("value"), input("value")];
disp("the matrix is:")
disp(A)
disp("enter the matrix b")
b = [input("value"); input("value"); input("value")];
disp("the matrix is:")
disp(b)

function least_squares(A,b)
    x = (A'*A)\(A'*b);
    disp(x, 'x=');
    C = x(1,1);
    D = x(2,1);
    disp(C, 'C=');
    disp(D, 'D=');
    disp('The line of best fit is b=C + Dt');
endfunction
